#include <QCoreApplication>
#include "circularlist.h"
#include <QDebug>

class Node
{
public:
    Node()
    {
        a = 0;
        b = -1;
        c = -2;
    }
    Node(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c  = c;
    }
    int a;
    int b;
    int c;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CircularList<Node*> list;
    list.setCapacity(50);
    for(int i = 0; i < list.capacity(); i++)
    {
        list.append(new Node(i, i+1, i+2));
    }
    qDebug() << list.before(list.at(0))->a;
    qDebug() << list.after(list.at(list.count() - 1))->a;

    return a.exec();
}
