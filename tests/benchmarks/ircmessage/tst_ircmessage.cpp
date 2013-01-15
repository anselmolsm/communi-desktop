/*
 * Copyright (C) 2008-2013 J-P Nurmi <jpnurmi@gmail.com>
 *
 * This test is free, and not covered by LGPL license. There is no
 * restriction applied to their modification, redistribution, using and so on.
 * You can study them, modify them, use them in your own program - either
 * completely or partially. By using it you may give me some credits in your
 * program, but you don't have to.
 */

#include "ircmessage.h"
#include <QtTest/QtTest>
#include <QtCore/QTextCodec>

static const QByteArray MSG_32_5("Vestibulum eu libero eget metus.");
static const QByteArray MSG_64_9("Phasellus enim dui, sodales sed tincidunt quis, ultricies metus.");
static const QByteArray MSG_128_19("Ut porttitor volutpat tristique. Aenean semper ligula eget nulla condimentum tempor in quis felis. Sed sem diam, tincidunt amet.");
static const QByteArray MSG_256_37("Vestibulum quis lorem velit, a varius augue. Suspendisse risus augue, ultricies at convallis in, elementum in velit. Fusce fermentum congue augue sit amet dapibus. Fusce ultrices urna ut tortor laoreet a aliquet elit lobortis. Suspendisse volutpat posuere.");
static const QByteArray MSG_512_75("Nam leo risus, accumsan a sagittis eget, posuere eu velit. Morbi mattis auctor risus, vel consequat massa pulvinar nec. Proin aliquam convallis elit nec egestas. Pellentesque accumsan placerat augue, id volutpat nibh dictum vel. Aenean venenatis varius feugiat. Nullam molestie, ipsum id dignissim vulputate, eros urna vestibulum massa, in vehicula lacus nisi vitae risus. Ut nunc nunc, venenatis a mattis auctor, dictum et sem. Nulla posuere libero ut tortor elementum egestas. Aliquam egestas suscipit posuere.");

class tst_IrcMessage : public QObject
{
    Q_OBJECT

private slots:
    void testFromData_data();
    void testFromData();

    void testEncoding();
};

void tst_IrcMessage::testFromData_data()
{
    QTest::addColumn<QByteArray>("data");

    QTest::newRow("null") << QByteArray();
    QTest::newRow("empty") << QByteArray("");

    QTest::newRow("32 chars / 5 words") << MSG_32_5;
    QTest::newRow("64 chars / 9 words")  << MSG_64_9;
    QTest::newRow("128 chars / 19 words")  << MSG_128_19;
    QTest::newRow("256 chars / 37 words")  << MSG_256_37;
    QTest::newRow("512 chars / 75 words")  << MSG_512_75;

    QTest::newRow("32 chars / 5 words") << MSG_32_5;
    QTest::newRow("64 chars / 9 words")  << MSG_64_9;
    QTest::newRow("128 chars / 19 words")  << MSG_128_19;
    QTest::newRow("256 chars / 37 words")  << MSG_256_37;
    QTest::newRow("512 chars / 75 words")  << MSG_512_75;
}

void tst_IrcMessage::testFromData()
{
    QFETCH(QByteArray, data);

    QBENCHMARK {
        IrcMessage::fromData(data, "ISO-8859-1", this);
    }
}

void tst_IrcMessage::testEncoding()
{
    IrcMessage message;
    foreach (const QByteArray& codec, QTextCodec::availableCodecs()) {
        QBENCHMARK {
            message.setEncoding(codec);
        }
    }
}

QTEST_MAIN(tst_IrcMessage)

#include "tst_ircmessage.moc"