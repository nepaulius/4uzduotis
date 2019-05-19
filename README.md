# 4uzduotis

**1 dalis**

5 funkcijos MyVector klasėje:

1)**.pop_back()**-ištrina paskutinį elementą vektoriuje.
```cpp
template<class T>
void MyVector<T>::pop_back() {
    if (vektsize > 0)
        vektsize--;
}
```
2)**.swap()**- apkeičia vektorių elementus vietomis.
```cpp
template<class T>
void MyVector<T>::swap(MyVector &other) {
    int tempVektsize, tempVektcapa;
    T *tempPoint;

    tempPoint = other.point;
    tempVektsize = other.vektsize;
    tempVektcapa = other.vektcapa;

    other.point = point;
    other.vektsize = vektsize;
    other.vektcapa = vektcapa;

    vektsize = tempVektsize;
    vektcapa = tempVektcapa;
    point = tempPoint;
}
```
3)**.front()** - iškviečia vektoriaus pirmąjį elementą.
```cpp
template<class T>
T &MyVector<T>::front() {
    if (vektsize > 0)
        return point[0];
    else
        throw std::logic_error("Empty container");
}
```
4)**.clear()** - ištrina elementus esančius vektoriuje.
```cpp
template<class T>
void  MyVector<T>::clear()
{
    if(point!=NULL)
       {
          delete[] point;
          vektsize=0;
          vektcapa=0;

       }

}
```
5)**.back()** - iškviečia elementą, esantį vektoriaus pabaigoje.
```cpp
template<class T>
T &MyVector<T>::back() {
    if (vektsize > 0)
        return point[vektsize-1];
    else
        throw std::logic_error("Empty container");
}
```
___
**2 dalis**

Pushback funkcijos testavimas laiko atžvilgiu su paprastu ir sukurto vektoriumi:

![](https://user-images.githubusercontent.com/45967745/57319486-5963d200-7105-11e9-91cb-38efc0045c39.JPG)
![](https://user-images.githubusercontent.com/45967745/57319487-5963d200-7105-11e9-8fee-44f6a1fc2f4f.JPG)
![](https://user-images.githubusercontent.com/45967745/57319482-58cb3b80-7105-11e9-976a-38a57aae6453.JPG)
![](https://user-images.githubusercontent.com/45967745/57319483-5963d200-7105-11e9-83ef-afc2a0095e80.JPG)
![](https://user-images.githubusercontent.com/45967745/57319485-5963d200-7105-11e9-8853-416ad5959abd.JPG)

|  Vektoriaus tipas \ Dydis  | 10 000  |100 000   |1 000 000   |10 000 000  |100 000 000|
|---|---|---|---|---|---|
|**Paprastas vektorius** - (laikas s) |0,00099   |0,002   | 0,025   | 0,27  |2,45  |
|**Sukurtas vektorius** - (laikas s)|0 |  0,001  |0,12 | 0,16  |1,43|
___
**3 dalis**

Sukurto ir paprasto vektoriaus perskirstymo dažnis 100 000 000
```cpp
for(int i=0;i<sz;i++)
{
    v1.push_back(i);
    if(v1.capacity()==v1.size())
         perskirstymasPap++;
}
```
```cpp
for (int i =0; i <sz; ++i){
v2.push_back(i);
if(v2.capacity()==v2.size())
    perskirstymasSuk++;
}
```
```cpp
std::cout<<"Paprastas vektorius "<<sz<<" perskirsto : "<<perskirstymasPap <<" kartus"<<std::endl;
std::cout<<"Sukurtas vektorius "<<sz<< " perskirsto : "<<perskirstymasSuk <<" kartus"<<std::endl;
```
![](https://user-images.githubusercontent.com/45967745/57320818-78179800-7108-11e9-9883-f062f89d7fef.png)

___
std::vector ir MyVector palyginimas : 

|*Studentų skaičius*|100 000|
|---|:---:|
**Rūšiavimo laikas (sekundėmis)** tipas - __*MyVector*__|0,18    
**Rūšiavimo laikas (sekundėmis)** tipas - __*std::vector*__|0,12
