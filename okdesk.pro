QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia network

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formtask.cpp \
    main.cpp \
    general.cpp \
	informdisplay.cpp \
	okdeskapi.cpp \
	setparameteraccount.cpp

HEADERS += \
    formtask.h \
    main.h \
    general.h \
	informdisplay.h \
	okdeskapi.h \
	setparameteraccount.h

FORMS += \
    formtask.ui \
    informdisplay.ui \
        setparameteraccount.ui
	

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
