#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <QList>
//#include "boost/circular_buffer.hpp"

template <class T>
class CircularList : private QList<T>
{
public:
    inline CircularList(int capacity) {m_Capacity = capacity;}
    void setCapacity(int capacity){m_Capacity = capacity;}
    int capacity() const {return m_Capacity;}
    inline ~CircularList() {}
    inline void swap(CircularList<T> &other) { QList<T>::swap(other); }
    inline bool isEmpty() const { return QList<T>::isEmpty(); }
    void clear() { QList<T>::clear(); }
    const T &at(int i) const { return QList<T>::at(i); }
    const T &operator[](int i) const { return QList<T>::operator[](i); }
    T &operator[](int i) { return QList<T>::operator[](i); }
    void append(const T &t) { QList<T>::append(t); }
    void append(const QList<T> &t) { QList<T>::append(t); }

private:
    int m_Capacity;
};

#endif // CIRCULARLIST_H
