#include <QCoreApplication>
#include <QDebug>
#include "dbug.h"
#include "hitobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dbug::full_debug();

    NormalNote normal_note = NormalNote(4, 100);
    normal_note.debugInfo();

    normal_note.setColumn(3);

    qDebug() << normal_note.toString(4);

    return a.exec();
}

