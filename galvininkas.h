
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

    virtual ~Zmogas(){

    };

    protected:
    std::string vardas;
    std::string pavarde;

};

class Studentai:public Zmogas{
private:

    std::vector <int> balai;
    int testas;
    double galutinis;
    double galutinismediana;
public:
    Studentai()
    {
        testas=0;
        galutinis=0;
        galutinismediana=0;
    }
~Studentai()
{

};
    Studentai(const  Studentai& y) {
        vardas = y.vardas;
        pavarde = y.pavarde;
        testas = y.testas;
        balai.reserve(y.balai.size());
        for (int i = 0; i < balai.size(); i++) {
            balai[i] = y.balai[i];
        }
        galutinis = y.galutinis;
        galutinismediana = y.galutinismediana;

    }


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



        const std::vector<int> &getBalai() const {
        return balai;
    }

    void setBalai(const std::vector<int> &balai) {
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
void PadalijimasVektorius(std::vector<Studentai> vektstud,int k);
void PadalijimasListas(std::list<Studentai> liststud,int k);
void IrasymasListas(std::list<Studentai>nemoka,std::list<Studentai>moka,int k);
void PadalijimasDekas(std::deque<Studentai>dekasstud,int k);
void IrasymasDekas(std::deque<Studentai>nemoka,std::deque<Studentai>moka,int k);
std::vector<Studentai> DuPadalijimasVektorius( std::vector<Studentai> & vektstud ,int k);
void IrasymasVector(std::vector<Studentai>nemoka,std::vector<Studentai>moka,int k);
void SkaitymasIsFailo();
void DuomenuPateikimas();
void DuIrasymasVektorius(std::vector<Studentai>nemoka,int k);
void DuPadalijimasListas(std::list<Studentai> liststud,int k);
void DuIrasymasListas(std::list<Studentai>nemoka,int k);
void DuPadalijimasDekas(std::deque<Studentai>dekasstud,int k);
void DuIrasymasDekas(std::deque<Studentai>nemoka,int k);
void IsvedimasEkranan(std::vector<std::string>vardai2,std::vector<std::string>pavardes2,std::vector<Studentai>vektstud);
int countWordsInString(std::string const& str);
bool IsMarkedToDelete(const Studentai & o);
int Ilgiausia(std::vector<std::string>pavardes);
std::string VidurkisArMediana();
double Vidurkis(double laikinvid,int e);
double Mediana(std::vector<int> balai,int namsk);
std::string ValidacijaVidurkiuIrMedianai(std::string b);

void Palyginimas(int a,std::vector<Studentai>vektstud);
void StudentoIvedimas(int a,std::vector<Studentai>vektstud);
void VidurkioPalyginimas(int a,std::vector<Studentai>vektstud);





#endif //KLASES_GALVININKAS_H
