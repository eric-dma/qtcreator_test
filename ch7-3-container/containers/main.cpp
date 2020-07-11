#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QMap>
#include <QMultiMap>
#include <QMapIterator>
#include <QMutableMapIterator>
#include <QVector>
#include <QStringList>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    //1
//    QList <QString> list;
//    list << "aa" << "bb" << "cc";
//    if(list[1] == "bb") list[1] = "ab";
//    list.replace(2,"bc");
//    qDebug() << "the list is:";
//    for(int i=0; i<list.size(); ++i) {
//        qDebug() << list.at(i);
//    }
//    list.append("dd");
//    list.prepend("mm");
//    QString str = list.takeAt(2);
//    qDebug() << "at(2) item is:";
//    qDebug() << "the list is:";
//    for(int i=0; i<list.size();++i) {
//        qDebug() << list.at(i);
//    }
//    list.insert(2,"mm");
//    list.swap(1,3);
//    qDebug() << "the list is:";
//    for(int i=0; i<list.size();++i) {
//        qDebug() << list.at(i);
//    }
//    qDebug() << "contains 'mm' ? " << list.contains("mm");
//    qDebug() << "the 'mm' count: " << list.count("mm");
//    qDebug() << "the first 'mm' index: " << list.indexOf("mm");
//    qDebug() << "the second 'mm' index: " << list.indexOf("mm", 1);
//    //2
//    QMap <QString,int>map;
//    map["one"] = 1;
//    map["three"] = 3;
//    map.insert("seven", 7);
//    int value1 = map["six"];
//    qDebug() << "value1:" << value1;
//    qDebug() << "contains 'six' ? " << map.contains("six");
//    int value2 = map.value("five");
//    qDebug() << "value2:" << value2;
//    qDebug() << "contains 'five' ?" << map.contains("five");
//    int value3 = map.value("nine", 9);
//    qDebug() << "value3:" << value3;
//    map.insert("ten", 10);
//    map.insert("ten", 100);
//    qDebug() << "ten: " << map.value("ten");
//    map.insertMulti("two", 2);
//    map.insertMulti("two", 4);
//    QList <int> values = map.values("two");
//    qDebug() << "two: " << values;
//    QMultiMap<QString,int> map1,map2,map3;
//    map1.insert("values",1);
//    map1.insert("values",2);
//    map2.insert("values",3);
//    map3 = map1 + map2;
//    QList<int> myValues = map3.values("values");
//    qDebug() << "the values are: ";
//    for(int i=0; i<myValues.size(); ++i) {
//        qDebug() << myValues.at(i);
//    }
//    //3
//    QMap<QString, QString> map;
//    map.insert("Paris", "France");
//    map.insert("Guatemala City", "Guatemala");
//    map.insert("Moscow", "Russia");
//    QMapIterator<QString, QString> i(map);
//    while(i.hasNext()) {
//        i.next();
//        qDebug() << i.key() << ":" <<i.value();
//    }
//    if(i.findPrevious("Mexico")) qDebug() << "find 'Mexico'";
//    QMutableMapIterator<QString, QString> j(map);
//    while(j.hasNext()) {
//        if(j.next().key().endsWith("City"))
//            j.remove();
//    }
//    while(j.hasPrevious()) {
//        j.previous();
//        qDebug() << j.key() << ":" << j.value();
//    }
    //4
//    QMap<QString, int> map;
//    map.insert("one",1);
//    map.insert("two",2);
//    map.insert("three",3);
//    QMap<QString, int>::const_iterator p;
//    qDebug() << "the forward is:";
//    for(p = map.constBegin(); p != map.constEnd(); ++p) {
//        qDebug() << p.key() << ":" << p.value();
//    }
    //5
    QStringList list;
    list << "one" << "two" << "three";
    qDebug() << QObject::tr("copy");
    QVector<QString> vect(3);
    std::copy(list.begin(), list.end(), vect.begin());
    qDebug() << vect;
    qDebug() << endl << QObject::tr("equal");
    bool ret1 = std::equal(list.begin(),list.end(),vect.begin());
    qDebug() << "equal: " << ret1;
    qDebug() << endl << QObject::tr("find");
    QList<QString>::iterator i = std::find(list.begin(),list.end(),"two");
    qDebug() << *i;
    qDebug() << endl << QObject::tr("fill");
    std::fill(list.begin(),list.end(),"eleven");
    qDebug() << list;
    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;
    qDebug() << endl << QObject::tr("count");
    int countOf6 = std::count(list1.begin(),list1.end(),6);
    qDebug() << "countOf6" << countOf6;
    qDebug() << endl << QObject::tr("lower_bound:");
    QList<int>::iterator j = std::lower_bound(list1.begin(),list1.end(),5);
    list1.insert(j,5);
    qDebug() << list1;
    QList<int> list2;
    list2 << 33 << 23 << 45 << 12;
    qDebug() << endl << QObject::tr("sort:");
    std::sort(list2.begin(),list2.end());
    qDebug() << list2;
    qDebug() << endl << QObject::tr("stable_sort:");
    std::stable_sort(list2.begin(),list2.end());
    qDebug() << list2;
    qDebug() << endl << QObject::tr("greater:");
    qSort(list2.begin(),list2.end(),std::greater<int>());
    qDebug() << list2;
    qDebug() << endl << QObject::tr("swap:");
    double pi = 3.14;
    double e = 2.7;
    std::swap(pi, e);
    qDebug() << "pi:" << pi << ", e:" << e;

    return a.exec();
}
