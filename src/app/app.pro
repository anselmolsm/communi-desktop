######################################################################
# Communi
######################################################################

TEMPLATE = app
win32|mac:TARGET = Communi
else:TARGET = communi
DESTDIR = ../../bin

win32:target.path = $$[QT_INSTALL_BINS]
else:mac:target.path = /Applications
else:target.path = /usr/bin
INSTALLS += target

include(src.pri)
include(../config.pri)
include(../libs/backend/backend.pri)
include(../libs/util/util.pri)
include(../libs/input/input.pri)
include(../libs/tree/tree.pri)
include(../libs/view/view.pri)
include(../libs/3rdparty/3rdparty.pri)
include(../../resources/resources.pri)

STATIC_PLUGINS = completer finder highlighter history menu navigator
for(PLUGIN, STATIC_PLUGINS) {
    LIBS *= -L$$PWD/../../plugins
    LIBS += -l$${PLUGIN}plugin
}
