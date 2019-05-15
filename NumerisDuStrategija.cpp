#include "galvininkas.h"


MyVector<Studentai> DuPadalijimasVektorius( MyVector<Studentai> & vektstud ,int k)
{

    MyVector<Studentai> nemoka;


    auto s = std::chrono::system_clock::now();


    for(int i = 0; i <pow(10,k) ;i++){
        if(vektstud[i].getGalutinis() < 5) nemoka.push_back(vektstud[i]);
    }
    vektstud.erase(std::remove_if(vektstud.begin(), vektstud.end(), IsMarkedToDelete), vektstud.end());
    vektstud.shrink_to_fit();
    nemoka.shrink_to_fit();

    auto e = std::chrono::system_clock::now();
    std::chrono::duration<double> u = e - s;
    std::cout<<"10 pakelta " << k<<" (vector) rusiuoja  :   "<<std::fixed<<std::setprecision(20)<<u.count()<< std::endl;
    DuIrasymasVektorius(nemoka,k);
    return vektstud;

}
void DuIrasymasVektorius(MyVector<Studentai>nemoka,int k)
{
    std::ofstream ne;

    std::stringstream a1;
    std::string failovardas1;

    a1<<k;
    failovardas1= "Nemoka_" + a1.str();

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

    ne.close();


}






