#include "galvininkas.h"

void PadalijimasVektorius(std::vector<Studentai> vektstud,int k)
{

        std::vector<Studentai> nemoka;
        std::vector<Studentai> moka;

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
void IrasymasVector(std::vector<Studentai>nemoka,std::vector<Studentai>moka,int k)
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

        std::vector<int> pazymys;
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

        std::vector<int> pazymys2;
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
void PadalijimasListas(std::list<Studentai> liststud,int k)
{
    std::list<Studentai>nemoka;
    std::list<Studentai>moka;
    std::list<Studentai>::iterator it;


    auto startrusislistas = std::chrono::system_clock::now();

    it = liststud.begin();
    while (it != liststud.end()){
        if(it->getGalutinis() <5)
        {
            nemoka.push_back(*it);
        }
        else if(it->getGalutinis()>=5)
        {
            moka.push_back(*it);
        }

        it++;
    }

    auto endrusislistas = std::chrono::system_clock::now();
    std::chrono::duration<double>uztrukolistas = endrusislistas - startrusislistas;
    std::cout <<"10 pakelta "<< k<<" (list) rusiuoja    :   "<<std::fixed<<std::setprecision(20)<<uztrukolistas.count()<< std::endl;
    IrasymasListas(nemoka,moka,k);

}
void IrasymasListas(std::list<Studentai>nemoka,std::list<Studentai>moka,int k)
{

    std::list<Studentai>::iterator ite;
    std::ofstream ne;
    std::ofstream taip;
    std::stringstream a;
    std::string failovardas;
    std::stringstream a1;
    std::string failovardas1;

    a<<k;
    failovardas= "ListMoka_" + a.str();

    failovardas += ".txt";
    taip.open(failovardas.c_str(), std::ios::out);
    a1<<k;
    failovardas1= "ListNemoka_" + a1.str();

    failovardas1 += ".txt";
    ne.open(failovardas1.c_str(), std::ios::out);


    for(ite=nemoka.begin(); ite!=nemoka.end();ite++)
    {
        ne<<std::left<<std::setw(15)<<ite->getVardas()<<std::setw(20)<<std::left<<ite->getPavarde();


        std::vector<int> pazymys;
        pazymys=ite->getBalai();
        for ( int j=0; j<50; j++)
        {
            ne<< std::setw(5) << std::left << pazymys[j];
        }

        ne<<std::setw(7)<<std::right<<ite->getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<ite->getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<ite->getGalutinismediana()<<std::endl;
    }
    for(ite=moka.begin();ite!=moka.end();ite++)
    {
        taip<<std::left<<std::setw(15)<<ite->getPavarde()<<std::setw(20)<<std::left<<ite->getVardas();

        std::vector<int> pazymys2;
        pazymys2=ite->getBalai();
        for ( int j=0; j<50; j++)
        {
            taip<< std::setw(5) << std::left << pazymys2[j];
        }

        taip<<std::setw(7)<<std::right<<ite->getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<ite->getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<ite->getGalutinismediana()<<std::endl;
    }

    ne.close();
    taip.close();


}
void PadalijimasDekas(std::deque<Studentai>dekasstud,int k)
{


    std::deque<Studentai> nemoka;
    std::deque<Studentai> moka;

    auto s = std::chrono::system_clock::now();

    for(int i=0;i<dekasstud.size();i++)
    {
        if(dekasstud[i].getGalutinis()<5)
        {
            nemoka.push_back(dekasstud[i]);
        }
        else
        {

            moka.push_back(dekasstud[i]);
        }

    }
    auto e = std::chrono::system_clock::now();
    std::chrono::duration<double> u = e - s;
    std::cout<<"10 pakelta " << k<<" (dekas) rusiuoja   :   "<<std::fixed<<std::setprecision(20)<<u.count()<< std::endl;
    IrasymasDekas(nemoka,moka,k);
}
void IrasymasDekas(std::deque<Studentai>nemoka,std::deque<Studentai>moka,int k)
{


    std::ofstream ne;
    std::ofstream taip;
    std::stringstream a;
    std::string failovardas;
    std::stringstream a1;
    std::string failovardas1;

    a<<k;
    failovardas= "DekasMoka_" + a.str();

    failovardas += ".txt";
    taip.open(failovardas.c_str(), std::ios::out);
    a1<<k;
    failovardas1= "DekasNemoka_" + a1.str();

    failovardas1 += ".txt";
    ne.open(failovardas1.c_str(), std::ios::out);
    for(int i=0;i<nemoka.size();i++)
    {
        ne<<std::left<<std::setw(15)<<nemoka[i].getVardas()<<std::setw(20)<<std::left<<nemoka[i].getPavarde();

        std::vector<int> pazymys;
        pazymys=nemoka[i].getBalai();
        for ( int j=0; j<50; j++)
        {
            ne<< std::setw(5) << std::left << pazymys[j];
        }

        ne<<std::setw(7)<<std::right<<nemoka[i].getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinismediana()<<std::endl;
    }
    for(int i=0;i<moka.size();i++)
    {
        taip<<std::left<<std::setw(15)<<moka[i].getPavarde()<<std::setw(20)<<std::left<<moka[i].getVardas();

        std::vector<int> pazymys2;
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