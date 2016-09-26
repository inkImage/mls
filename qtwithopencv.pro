#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T17:59:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtwithopencv
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/imagewidget.cpp \
    src/mlsdeformation.cpp \
    src/mlsdaffine.cpp \
    src/mlsdsimilarity.cpp \
    src/mlsdrigid.cpp

HEADERS  += include/mainwindow.h \
    include/imagewidget.h \
    include/mlsdeformation.h \
    include/mlsdaffine.h \
    include/mlsdsimilarity.h \
    include/mlsdrigid.h

INCLUDEPATH += .
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv2/core
INCLUDEPATH += /usr/local/include/opencv2/highgui
INCLUDEPATH += /usr/local/include/opencv2/imgproc
INCLUDEPATH += /usr/local/include/opencv2/flann
INCLUDEPATH += /usr/local/include/opencv2/photo
INCLUDEPATH += /usr/local/include/opencv2/video
INCLUDEPATH += /usr/local/include/opencv2/features2d
INCLUDEPATH += /usr/local/include/opencv2/objdetect
INCLUDEPATH += /usr/local/include/opencv2/calib3d
INCLUDEPATH += /usr/local/include/opencv2/ml
INCLUDEPATH += /usr/local/include/opencv2/contrib

LIBS += `pkg-config opencv --cflags --libs`

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
