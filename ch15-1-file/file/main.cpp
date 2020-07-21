#include <QCoreApplication>
#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("myfile.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << file.errorString();
    file.write("hello Qt!");
    file.close();
    QFileInfo info(file);
    qDebug() << QObject::tr("path: ") << info.absoluteFilePath() << endl
             << QObject::tr("filename: ") << info.fileName() << endl
             << QObject::tr("basename: ") << info.baseName() << endl
             << QObject::tr("suffix: ") << info.suffix() << endl
             << QObject::tr("create time: ") << info.created() << endl
             << QObject::tr("size: ") << info.size();
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << file.errorString();
    qDebug() << QObject::tr("file context:") << endl << file.readAll();
    qDebug() << QObject::tr("current position: ") << file.pos();
    file.seek(0);
    QByteArray array;
    array = file.read(5);
    qDebug() << QObject::tr("first 5 words: ") << array << QObject::tr("current position: ") << file.pos();
    file.seek(15);
    array = file.read(5);
    qDebug() << QObject::tr("16-20 words: ") << array;
    file.close();
    return a.exec();

    return a.exec();
}
