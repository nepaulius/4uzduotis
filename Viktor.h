//
// Created by Šefas on 2019.05.08.
//

#ifndef KLASES_VIKTOR_H
#define KLASES_VIKTOR_H
#include "Viktoro_iteratorius.h"
#include <iostream>
#include<vector>
#include <chrono>

template<class T>
class MyVector {
private:
    T *pointas;
    int vektsize;
    int vektcapa;
public:
    MyVector() : pointas(nullptr), vektsize(), vektcapa() {}
    explicit MyVector(int size);
    MyVector(int size, int value);
    MyVector(const std::initializer_list<T> & v);
    MyVector(const MyVector<T> & v);
    MyVector(MyVector<T> && v);

    ~MyVector();

    MyVector & operator=(const MyVector<T> &v);
    MyVector & operator=(MyVector<T> &&v);
    bool operator==(const MyVector<T> & v);
    bool operator!=(const MyVector<T> & v);
    T &operator[](int size);
    const T &operator[](int size) const;

    int capacity();
    int size();


    T & front();
    const T & front() const;
    const T & back() const;
    T & back();
    T & at(int size);



    void push_back(T & v);
    void pop_back();
    void swap(MyVector & other);
    void assign(int count, const T &value);
    void resize(int count);
    void shrink_to_fit();
    void reserve(int new_vektcapa);
    bool empty();
    void clear();

    friend class Iterator<T>;
    typedef class Iterator<T> iterator;

     Iterator<T> erase(Iterator<T> pos);
     Iterator<T> erase(Iterator<T> first, Iterator<T> last);
     Iterator<T> insert(Iterator<T> pos, const T & value);
     void insert(iterator pos, int count, const T & value);

     Iterator<T> end();
     Iterator<T> begin();
};

template<class T>
MyVector<T>::MyVector(int size) : vektsize(size), vektcapa(size) {
    pointas = new T[vektsize];
}

template<class T>
MyVector<T>::MyVector(int size, int value) : vektsize(size), vektcapa(size){
    pointas = new T[vektsize];

    for (int i = 0; i < vektsize; i++)
        pointas[i] = value;
}

template<class T>
MyVector<T>::MyVector(const std::initializer_list<T> &v) : vektsize(v.size()), vektcapa(v.size()) {
    pointas = new T[v.size()];

    for (int i = 0; i < v.size(); i++)
        pointas[i] = *(v.begin() + i);
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> &v) : vektsize(v.vektsize), vektcapa(v.vektcapa) {
    pointas = new T[vektcapa];

    for (int i = 0; i < vektsize; i++)
        pointas[i] = v.pointas[i];
}

template<class T>
MyVector<T>::MyVector(MyVector<T> &&v) : vektsize(v.vektsize), vektcapa(v.vektcapa) {
    pointas = v.pointas;
    v.pointas = nullptr;
    v.vektsize = 0;
    v.vektcapa = 0;
}

template<class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v) {

        MyVector<T> copy(v);
        copy.swap(*this);
        return *this;

}

template<class T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&v) {
    if (this == &v)
        return *this;

    delete[] pointas;
    vektsize = v.vektsize;
    vektcapa = v.vektcapa;
    pointas = v.pointas;
    v.vektsize = 0;
    v.capacity = 0;
    v.pointas = nullptr;
     return *this;
}

template<class T>
MyVector<T>::~MyVector() {
    delete[] pointas;
}

template<class T>
bool MyVector<T>::operator==(const MyVector<T> &v) {
    if (vektsize == v.vektsize && vektcapa == v.vektcapa) {
        for (int i = 0; i < vektsize; i++)
            if (pointas[i] != v.pointas[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool MyVector<T>::operator!=(const MyVector<T> &v) {
    return !operator==(v);
}

template<class T>
int MyVector<T>::capacity() {
    return vektcapa;
}

template<class T>
int MyVector<T>::size() {
    return vektsize;
}

template<class T>
void MyVector<T>::push_back(T &v) {

    if (vektsize==vektcapa) {
        vektcapa=(1+vektcapa)*2;
        T *temp = new T[vektcapa];
        for (int i = 0; i < vektsize; i++)
            temp[i] = pointas[i];

        temp[vektsize] = v;
        delete[] pointas;
        pointas = temp;
        vektsize++;
    } else {
        pointas[vektsize] = v;
        vektsize++;
    }
}

template<class T>
void MyVector<T>::pop_back() {
    if (vektsize > 0)
        vektsize--;
}
template<class T>
bool MyVector<T>::empty()
{
    if(vektsize==0)
        return true;
    else return false;
}

template<class T>
void MyVector<T>::swap(MyVector &other) {

        using std::swap;
        swap(pointas, other.pointas);
        swap(vektsize, other.vektsize);
        swap(vektcapa,other.vektcapa);


}
template<class T>
T &MyVector<T>::at(int size ){
    if(size<vektsize)
return pointas[size];
    else throw std::out_of_range(" ");
}
template<class T>
T &MyVector<T>::front() {
    if (vektsize > 0)
        return pointas[0];
    else
        throw std::logic_error("Empty container");
}

template<class T>
const T &MyVector<T>::front() const {
    if (vektsize > 0)
        return pointas[0];
    else
        throw std::logic_error("Empty container");
        }

template<class T>
void MyVector<T>::resize(int count) {
    if (count < 0)
        throw std::length_error("too short");
    else if (count < vektsize)
        vektsize = count;
    else if (count > vektcapa) {
        T *temppointas = new T[count];
        for (int i = 0; i < vektsize; i++)
            temppointas[i] = pointas[i];
        delete[] pointas;
        pointas = temppointas;
    }
}

template<class T>
const T &MyVector<T>::back() const {
    if (vektsize == 0)
        throw std::logic_error("Empty");

    return pointas[vektsize - 1];
}

template<class T>
T &MyVector<T>::back() {
    if (vektsize == 0)
        throw std::logic_error("Empty");

    return pointas[vektsize - 1];
    }

template<class T>
T &MyVector<T>::operator[](int size) {
    if (size > vektsize - 1 || size < 0)
        throw std::out_of_range("Out of scope");
    else
        return pointas[size];
}

template<class T>
const T &MyVector<T>::operator[](int size) const {
    if (size > vektsize - 1 || size < 0)
        throw std::out_of_range("Out of scope");
    else
        return pointas[size];
}

template<class T>
void MyVector<T>::assign(int count, const T &value) {
    if (count < 0)
        throw std::out_of_range("Out of scope");

    if (count < vektcapa)
        for (int i = 0; i < count; i++)
            pointas[i] = value;
    else if (count >= vektcapa) {
        delete[] pointas;
        pointas = new T[count + 5];
        vektcapa = count + 5;
        vektsize = count;
         for (int i = 0; i < count; i++)
            pointas[i] = value;
    }
}

template<class T>
Iterator<T> MyVector<T>::end(){
     Iterator<T> temp(pointas + vektsize);
    return temp;
}

template<class T>
Iterator<T> MyVector<T>::begin(){
    Iterator<T> temp(pointas);
    return temp;
}

template<class T>
Iterator<T> MyVector<T>::erase(Iterator<T> pos) {
    int i = 0;
    auto it = (*this).begin();

    for (it; it != pos; it++, i++);

    for (auto it = pos + 1; it != (*this).end(); it++, i++)
        pointas[i] = pointas[i + 1];

    vektsize--;
    return pos;
    }

template<class T>
Iterator<T> MyVector<T>::erase(Iterator<T> first, Iterator<T> last){
    int i = 0;
    int temp = 0;
    auto it = (*this).begin();

    for (it; it != first; it++, i++);
    for (it = first; it != last; it++, temp++, i++);

    for (auto it = last; it != (*this).end(); it++, i++)
        pointas[i - temp] = pointas[i];

    vektsize -=  temp;
    return last;
}

template<class T>
Iterator<T> MyVector<T>::insert(Iterator<T> pos, const T & value){
    int i = 0;

    if (vektcapa > vektsize){
        for(Iterator<T> it = pointas + vektsize; it != pos; it--, i++)
            pointas[vektsize - i] = pointas[vektsize - i - 1];
        *pos = value;
        vektsize++;
    } else{
        T * temp = new T[vektsize + 1];
            for (Iterator<T> it = pointas; it != pos; it++, i++)
             temp[i] = pointas[i];
              temp[i] = value;
        i++;
            for (Iterator<T> it = pointas + i + 1; it != pointas + vektsize + 2; it++, i++)
            temp[i] = pointas[i-1];
        delete [] pointas;
        pointas = temp;
        vektsize++;
        vektcapa = vektsize;
    }
}

template<class T>
void MyVector<T>::insert(Iterator<T> pos, int count, const T & value){
    T * temp = new T[vektsize + count];
    int i = 0, j = 0;

    for (Iterator<T> it = pointas; it != pos; it++, i++)
        temp[i] = pointas[i];

    for (j; j < count; j++)
        temp[i+j] = value;

    for (Iterator<T> it = pointas + i; it != pointas + vektsize; it++, i++)
        temp[i+j] = pointas[i];

    vektsize += count;
    vektcapa = vektsize;
    delete [] pointas;
    pointas = temp;
}
template<class T>
void MyVector<T>:: reserve(int new_vektcapa)
    {

        if(new_vektcapa>vektcapa)
        {
            T* temp=new T[new_vektcapa];
            std::copy(pointas,pointas+vektcapa,temp);
            delete[] pointas;
            pointas=temp;
            vektcapa=new_vektcapa;
        }
    }
template<class T>
void MyVector<T>::shrink_to_fit()
{
    vektcapa=vektsize;
}
template<class T>
void MyVector<T>::clear()
{
    vektsize=0;
    vektcapa=0;
}





#endif //KLASES_VIKTOR_H
