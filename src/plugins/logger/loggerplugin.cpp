/*
  Copyright (C) 2008-2016 The Communi Project

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "loggerplugin.h"
#include <IrcConnection>
#include <IrcNetwork>
#include <IrcMessage>
#include <IrcCommand>
#include <IrcChannel>
#include <Irc>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QString>

LoggerPlugin::LoggerPlugin(QObject* parent) : QObject(parent)
    , m_logDirPath(QDir::homePath()+"/communilogs/")
{
    QDir logDir;
    if (!logDir.exists(m_logDirPath))
        logDir.mkpath(m_logDirPath);
}

LoggerPlugin::~LoggerPlugin()
{
    QStringList values = m_logs.keys();
    foreach(QString v, values) {
        QFile *f = m_logs.take(v);
        f->close();
    }
}

void LoggerPlugin::bufferAdded(IrcBuffer* buffer)
{
    connect(buffer, SIGNAL(messageReceived(IrcMessage*)), this, SLOT(logMessage(IrcMessage*)));
}

void LoggerPlugin::bufferRemoved(IrcBuffer* buffer)
{
    disconnect(buffer, SIGNAL(messageReceived(IrcMessage*)), this, SLOT(logMessage(IrcMessage*)));
    QString file(buffer->network()->name() + "_" + buffer->title());
    QFile *f = m_logs.take(file);
    if (f)
        f->close();
}

void LoggerPlugin::logMessage(IrcMessage *message)
{
    if (message->type() != IrcMessage::Private)
        return;

    IrcPrivateMessage *m = static_cast<IrcPrivateMessage*>(message);
    QFile *f = m_logs.value(logFileName(m), new QFile(this));

    if (f->fileName().isEmpty()) {
        f->setFileName(m_logDirPath+logFileName(m));
        f->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

        m_logs.insert(logFileName(m), f);
        QTextStream ts(f);
        ts << "============== " + formatTimestamp(m) + " ==============" << endl;
    }

    QTextStream ts(f);
    ts << formatTimestamp(m) + " " + m->nick() + ": " + m->content() << endl;
}

QString LoggerPlugin::logFileName(IrcPrivateMessage *message) const
{
    return message->isPrivate() ? message->network()->name() + "_" + message->nick()
                                : message->network()->name() + "_" + message->target();
}

QString LoggerPlugin::formatTimestamp(IrcPrivateMessage *message) const
{
    return message->timeStamp().toString("[yyyy-MM-dd] hh:mm:ss");
}
