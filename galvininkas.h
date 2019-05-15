
#ifndef KLASES_GALVININKAS_H
#define KLASES_GALVININKAS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iterator>
#include <exception>
#include <limits>
#include <sstream>
#include <cmath>
#include <chrono>
#include <list>
#include <deque>
#include <random>

#include "Viktor.h"

class Zmogas{
public:
    void setVardas(std::string vardas2) {
        vardas = vardas2;
    }
    void setPavarde(std::string pavarde2) {
        pavarde = pavarde2;
    }
    const std::string &getVardas() const {
        return vardas;
    }
    const std::string &getPavarde() const {
        return pavarde;
    }

    virtual void setTestas(int testas) = 0;
    virtual ~Zmogas(){};

    protected:
    std::string vardas;
    std::string pavarde;

};

class Studentai:public Zmogas{
private:

    MyVector<int> balai;
    int testas;
    double galutinis;
    double galutinismediana;
public:
	/**
	*Konstruktorius
	**/
    Studentai()
    {
        testas=0;
        galutinis=0;
        galutinismediana=0;
    }
	/**
	*Dekonstruktorius
	**/
~Studentai()
{

};
/**
	*Copy konstruktorius
	**/
    Studentai(const  Studentai& y) {
        vardas = y.vardas;
        pavarde = y.pavarde;
        testas = y.testas;
        for (int i = 0; i < balai.size(); i++) {
            balai[i] = y.balai[i];
        }
        galutinis = y.galutinis;
        galutinismediana = y.galutinismediana;

    }

	/**
	*Copy assign
	**/
    Studentai& operator=(const Studentai& y){
            if(&y == this) return *this;
            vardas = y.vardas;
            pavarde = y.pavarde;
            testas = y.testas;
            galutinis=y.galutinis;
            galutinismediana = y.galutinismediana;
            balai=y.balai;

            return *this;

        }


        const MyVector<int> &getBalai() const {
        return balai;
    }

    void setBalai(const MyVector <int> &balai) {
        Studentai::balai = balai;
    }

    int getTestas() const {
        return testas;
    }

    void setTestas(int testas) {
        Studentai::testas = testas;
    }

    double getGalutinis() const {
        return galutinis;
    }

    void setGalutinis(double galutinis) {
        Studentai::galutinis = galutinis;
    }

    double getGalutinismediana() const {
        return galutinismediana;
    }

    void setGalutinismediana(double galutinismediana) {
        Studentai::galutinismediana = galutinismediana;
    }
    bool operator() (Studentai i,Studentai j) { return (i.pavarde<j.pavarde);}

   friend bool operator==(Studentai const a, Studentai const b){
        return  (a.galutinismediana==b.galutinismediana&&a.vardas==b.vardas&&a.pavarde==b.pavarde);
    }
    friend bool operator !=(Studentai const a, Studentai const b)
    {
        if(a.galutinis  != b.galutinis)
        {
            return a.galutinis!=b.galutinis;
        }
    }
    friend  std::istream& operator>> (std::istream& in, Studentai& a)
    {
            std::cout<<"Iveskite pavarde ir varda studento, pagal kurio vidurki bus parodyti studentai turintys aukstesni vidurki :"<<std::endl;
            std::cout<<"Iveskite pavarde : "<<std::endl;
            in>>a.pavarde;
            std::cout<<"Iveskite varda : "<<std::endl;
            in>>a.vardas;
            return in;
    }
    friend std::ostream & operator << (std::ostream &out, const Studentai &a)
    {
        out <<"Studento pavarde : "<< a.pavarde<<std::endl;
        out <<"Studento vardas : "  << a.vardas << std::endl;
        out <<"Studento galutinis vidurkio balas : "<<a.galutinis<<std::endl;
        out<<std::endl;
        return out;
    }

    friend bool operator > (Studentai const a, Studentai const b)
    {
        return a.galutinis>b.galutinis;
    }

};

int PatikraSkaiciams();
int PatikraEgzaminui();
int PatikraND();
std::string PatikraRaidems();
std::string ValidacijaVidurkiuIrMedianai(std::string b);
void Strategas();
void MakeData(int k,std::string r);
void PadalijimasVektorius(MyVector<Studentai> vektstud,int k);
MyVector<Studentai> DuPadalijimasVektorius( MyVector<Studentai> & vektstud ,int k);
void IrasymasVector(MyVector<Studentai>nemoka,MyVector<Studentai>moka,int k);
void SkaitymasIsFailo();
void DuomenuPateikimas();
void DuIrasymasVektorius(MyVector<Studentai>nemoka,int k);
void IsvedimasEkranan(MyVector<std::string>vardai2,MyVector<std::string>pavardes2,MyVector<Studentai>vektstud);
int countWordsInString(std::string const& str);
bool IsMarkedToDelete(const Studentai & o);
int Ilgiausia(MyVector<std::string>pavardes);
std::string VidurkisArMediana();
double Vidurkis(double laikinvid,int e);
double Mediana(MyVector<int> balai,int namsk);
std::string ValidacijaVidurkiuIrMedianai(std::string b);

void Palyginimas(int a,MyVector<Studentai>vektstud);
void StudentoIvedimas(int a,MyVector<Studentai>vektstud);
void VidurkioPalyginimas(int a,MyVector<Studentai>vektstud);





#endif //KLASES_GALVININKAS_H
