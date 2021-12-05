QT       += core gui
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addemprunte.cpp \
    addenseignant.cpp \
    addetudiant.cpp \
    addlivre.cpp \
    creationwindow.cpp \
    displayemp.cpp \
    displaysearch.cpp \
    displaytab.cpp \
    main.cpp \
    mainwindow.cpp\
    Bibliotheque.cpp\
    Etudiant.cpp\
    Livre.cpp\
    Enseignant.cpp\
    Personne.cpp\
    Date.cpp\
    Statistique.cpp \
    modifybook.cpp \
    modifyprof.cpp \
    modifystudent.cpp \
    searchbook.cpp \
    searchprof.cpp \
    searchstudent.cpp \
    suppression.cpp


HEADERS += \
    addemprunte.h \
    addenseignant.h \
    addetudiant.h \
    addlivre.h \
    creationwindow.h \
    displayemp.h \
    displaysearch.h \
    displaytab.h \
    mainwindow.h\
    Bibliotheque.h\
    Etudiant.h\
    Livre.h\
    Enseignant.h\
    Personne.h\
    Date.h\
    Statistique.h \
    modifybook.h \
    modifyprof.h \
    modifystudent.h \
    searchbook.h \
    searchprof.h \
    searchstudent.h \
    suppression.h

FORMS += \
    addemprunte.ui \
    addenseignant.ui \
    addetudiant.ui \
    addlivre.ui \
    creationwindow.ui \
    displayemp.ui \
    displaysearch.ui \
    displaytab.ui \
    mainwindow.ui \
    modifybook.ui \
    modifyprof.ui \
    modifystudent.ui \
    searchbook.ui \
    searchprof.ui \
    searchstudent.ui \
    suppression.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CSV.qrc \
    Icons.qrc

DISTFILES +=
