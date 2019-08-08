#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <QList>
//#include "boost/circular_buffer.hpp"

template <class T>
class CircularList : public QList<T>
{
public:
    inline CircularList(){}
    inline CircularList(int capacity) {m_Capacity = capacity;}
    inline ~CircularList() {}

    void setCapacity(int capacity){m_Capacity = capacity;}
    int capacity() const {return m_Capacity;}

    const T& before(const T& t) const
    {
        Q_ASSERT(!QList<T>::isEmpty());
        int idx = QList<T>::indexOf(t);
        return idx == 0 ? QList<T>::last() : QList<T>::at(idx - 1);
    }
    T& before(const T& t)
    {
        Q_ASSERT(!QList<T>::isEmpty());
        int idx = QList<T>::indexOf(t);
        return idx == 0 ? QList<T>::last() : QList<T>::operator[](idx - 1);
    }
    const T& after(const T& t) const
    {
        Q_ASSERT(!QList<T>::isEmpty());
        int idx = QList<T>::indexOf(t);
        return idx == QList<T>::count() - 1 ? QList<T>::front() : QList<T>::at(idx - 1);
    }
    T& after(const T& t)
    {
        Q_ASSERT(!QList<T>::isEmpty());
        int idx = QList<T>::indexOf(t);
        return idx == QList<T>::count() - 1 ? QList<T>::front() : QList<T>::operator[](idx - 1);
    }

private:
    int m_Capacity;
};

#endif // CIRCULARLIST_H
