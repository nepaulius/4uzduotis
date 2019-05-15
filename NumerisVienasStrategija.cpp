#include "galvininkas.h"

void PadalijimasVektorius(MyVector<Studentai> vektstud,int k)
{

        MyVector<Studentai> nemoka;
        MyVector<Studentai> moka;

        auto s = std::chrono::system_clock::now();

        for(int i=0;i<vektstud.size();i++)
        {
                if(vektstud[i].getGalutinis()<5)
                {
                        nemoka.push_back(vektstud[i]);
                }
                else
                {

                        moka.push_back(vektstud[i]);
                }

        }
        auto e = std::chrono::system_clock::now();
        std::chrono::duration<double> u = e - s;
        std::cout<<"10 pakelta " << k<<" (vector) rusiuoja  :   "<<std::fixed<<std::setprecision(20)<<u.count()<< std::endl;
        IrasymasVector(nemoka,moka,k);

}
void IrasymasVector(MyVector<Studentai>nemoka,MyVector<Studentai>moka,int k)
{
    std::ofstream ne;
    std::ofstream taip;
    std::stringstream a;
    std::string failovardas;
    std::stringstream a1;
    std::string failovardas1;
    a<<k;
    failovardas= "VectorMoka_" + a.str();

    failovardas += ".txt";
    taip.open(failovardas.c_str(), std::ios::out);
    a1<<k;
    failovardas1= "VectorNemoka_" + a1.str();

    failovardas1 += ".txt";
    ne.open(failovardas1.c_str(), std::ios::out);
    for(int i=0;i<nemoka.size();i++)
    {
        ne<<std::left<<std::setw(15)<<nemoka[i].getVardas()<<std::setw(20)<<std::left<<nemoka[i].getPavarde();

        MyVector<int> pazymys;
        pazymys=nemoka[i].getBalai();
        for ( int j=0; j<50; j++)
        {
            ne<< std::setw(5) << std::left << pazymys[j];
        }


        ne<<std::setw(7)<<std::right<<nemoka[i].getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinismediana()<<std::endl;
    }
    for(int i=0;i<moka.size();i++)
    {
        taip<<std::left<<std::setw(15)<<moka[i].getVardas()<<std::setw(20)<<std::left<<moka[i].getPavarde();

        MyVector<int> pazymys2;
        pazymys2=moka[i].getBalai();
        for ( int j=0; j<50; j++)
        {
            taip<< std::setw(5) << std::left << pazymys2[j];
        }

        taip<<std::setw(7)<<std::right<<moka[i].getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<moka[i].getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<moka[i].getGalutinismediana()<<std::endl;
    }

    ne.close();
    taip.close();

}
