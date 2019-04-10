#include "galvininkas.h"

std::vector<Studentai> DuPadalijimasVektorius( std::vector<Studentai> & vektstud ,int k)
{

    std::vector<Studentai> nemoka;


    auto s = std::chrono::system_clock::now();


    std::copy_if(vektstud.begin(), vektstud.end(),std::inserter(nemoka, nemoka.end()), [](const Studentai & w){return w.getGalutinis()<=5;});

    vektstud.erase(std::remove_if(vektstud.begin(), vektstud.end(), IsMarkedToDelete),vektstud.end());

    vektstud.shrink_to_fit();

    auto e = std::chrono::system_clock::now();
    std::chrono::duration<double> u = e - s;
    std::cout<<"10 pakelta " << k<<" (vector) rusiuoja  :   "<<std::fixed<<std::setprecision(20)<<u.count()<< std::endl;
    DuIrasymasVektorius(nemoka,k);
    return vektstud;

}
void DuIrasymasVektorius(std::vector<Studentai>nemoka,int k)
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

        std::vector<int> pazymys;
        pazymys=nemoka[i].getBalai();
        for ( int j=0; j<50; j++)
        {
            ne<< std::setw(5) << std::left << pazymys[j];
        }

        ne<<std::setw(7)<<std::right<<nemoka[i].getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<nemoka[i].getGalutinismediana()<<std::endl;
    }

    ne.close();


}
void DuPadalijimasListas(std::list<Studentai> liststud,int k)
{
    std::list<Studentai>nemoka;

    std::list<Studentai>::iterator it;


    auto startrusislistas = std::chrono::system_clock::now();


    for (auto it = begin(liststud); it != end(liststud);) {
        if (it->getGalutinis() <= 5) {
            nemoka.push_back(*it);
            it = liststud.erase(it);
        }
        else
            ++it;
    }


    auto endrusislistas = std::chrono::system_clock::now();
    std::chrono::duration<double>uztrukolistas = endrusislistas - startrusislistas;
    std::cout <<"10 pakelta "<< k<<" (list) rusiuoja    :   "<<std::fixed<<std::setprecision(20)<<uztrukolistas.count()<< std::endl;
    DuIrasymasListas(nemoka,k);

}
void DuIrasymasListas(std::list<Studentai>nemoka,int k)
{

    std::list<Studentai>::iterator ite;
    std::ofstream ne;

    std::stringstream a1;
    std::string failovardas1;

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


    ne.close();

}
void DuPadalijimasDekas(std::deque<Studentai>dekasstud,int k)
{


    std::deque<Studentai> nemoka;


    auto startasdekas = std::chrono::system_clock::now();




    for (auto it = begin(dekasstud); it != end(dekasstud);) {
        if (it->getGalutinis() <= 5) {
            nemoka.push_back(*it);
            it = dekasstud.erase(it);
        }
        else
            ++it;
    }


    auto endasdekas = std::chrono::system_clock::now();
    std::chrono::duration<double> uztrukodekas = endasdekas - startasdekas;
    std::cout<<"10 pakelta " << k<<" (dekas) rusiuoja   :   "<<std::fixed<<std::setprecision(20)<<uztrukodekas.count()<< std::endl;
    DuIrasymasDekas(nemoka,k);
}
void DuIrasymasDekas(std::deque<Studentai>nemoka,int k)
{


    std::ofstream ne;

    std::stringstream a1;
    std::string failovardas1;

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


    ne.close();



}






