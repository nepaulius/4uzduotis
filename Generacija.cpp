#include "galvininkas.h"


void Strategas(){
        std::string d;
        std::cout<<"Kokia strategija pasirinksite? Spauskite V , jei 1 strategija, spauskite M, jei 2 strategija"<<std::endl;
        std::cin>>d;
        std::string r=ValidacijaVidurkiuIrMedianai(d);
        for (int k=4;k<6;k++)
        {

            MakeData(k, r);

        }
}
void MakeData(int k,std::string r)
{

    Studentai gimt;

    std::vector<Studentai> vektstud;
    std::list<Studentai> liststud;
    std::list<Studentai>::iterator it;
    std::deque<Studentai> dekasstud;

    double laikinvid=0;
    std::string failovardas;
    std::ofstream fr;

    std::stringstream a;
    a<<k;
    failovardas= "Rez_" + a.str();

    failovardas += ".txt";
    fr.open(failovardas.c_str(), std::ios::out);

    fr<<std::left<<std::setw(15)<<"Vardas"<<std::setw(30)<<std::left<<"Pavarde";
    for(int i=1;i<51;i++)
    {
        fr<<std::setw(5)<<std::left<<"ND"+std::to_string(i);
    }
    fr<<std::setw(12)<<std::right<<"Egzaminas"<<std::setw(35)<<std::right<<"Galutinis vid./ Galutinis med"<<std::endl;
    fr<<std::endl;




    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint64_t> dice(1,10);

    std::vector<int> balai;

    for(int i=0;i<std::round(pow(10,k));i++)
    {

        std::string vardas="Vardas"+std::to_string(i);
        gimt.setVardas(vardas);


        std::string pavarde="Pavarde"+std::to_string(i);
        gimt.setPavarde(pavarde);



        for(int j=0;j<50;j++)
        {
            int bet=dice(generator);

            laikinvid=bet+laikinvid;
            balai.push_back(bet);
            gimt.setBalai(balai);


        }
        int testas=dice(generator);
        gimt.setTestas(testas);



        double galutinis = 0.4 * Vidurkis(laikinvid,50) + 0.6 *testas;
        gimt.setGalutinis(galutinis);

        double galutinismediana =0.4 * Mediana(balai,50) + 0.6 *testas;
        gimt.setGalutinismediana(galutinismediana);


        vektstud.push_back(gimt);
        liststud.push_back(gimt);
        dekasstud.push_back(gimt);


        balai.clear();

        laikinvid=0;
    }


    if(r[0]=='V') {
      PadalijimasVektorius(vektstud, k);
      PadalijimasListas(liststud, k);
      PadalijimasDekas(dekasstud, k);
    }
    else if(r[0]=='M') {
    // DuPadalijimasVektorius(vektstud, k);
    // DuPadalijimasListas(liststud, k);
      DuPadalijimasDekas(dekasstud, k);


    }


    for(int i=0;i<vektstud.size();i++)
    {
        fr<<std::left<<std::setw(15)<<vektstud[i].getPavarde()<<std::setw(30)<<std::left<<vektstud[i].getVardas();

        std::vector<int> pazymys;
        pazymys=vektstud[i].getBalai();
            for ( int j=0; j<50; j++)
            {
                fr << std::setw(5) << std::left << pazymys[j];
            }



        fr<<std::setw(7)<<std::right<<vektstud[i].getTestas()<<std::setw(20)<< std::setprecision (2) << std::fixed<<vektstud[i].getGalutinis()<<std::right<<std::setw(15)<< std::setprecision (2) << std::fixed<<vektstud[i].getGalutinismediana()<<std::endl;

    }


    fr.close();

}
