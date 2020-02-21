QT += widgets
requires(qtConfig(filedialog))

HEADERS       = mainwindow.h \
    qt_gui.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                qt_gui.cpp
#! [0]
RESOURCES     = application.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target
