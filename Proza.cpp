#include "galvininkas.h"


void SkaitymasIsFailo() {
    int kartai = 0;

    std::vector<Studentai> vektstud;
    std::vector<std::string> Pavardes1;
    std::vector<std::string> Vardai1;


    Studentai stud;
    std::string sLine;
    std::ifstream fd;
    try {
        fd.open("kursiokai.txt");
        if (!fd.good()) {
            throw "Tekstinio failo atidaryti neimanoma";

        }
    } catch (const char *msg) {
        std::cout << msg;
    }


    getline(fd, sLine);

    std::string vardas;
    std::string pavarde;
    std::vector<int> balai;
    int egzaminas;
    double galutinis;
    double galutinismediana;


    while (!fd.eof()) {
        fd >>pavarde>>vardas;


         stud.setVardas(vardas);
         stud.setPavarde(pavarde);

        Pavardes1.push_back(pavarde);
        Vardai1.push_back(vardas);


        int q;
        double laikinvid = 0;
        for (int i = 0; i < countWordsInString(sLine); i++) {
            fd >> q;
            balai.push_back(q);
             stud.setBalai(balai);
            laikinvid = balai[i] + laikinvid;
        }

         fd >> egzaminas;
         stud.setTestas(egzaminas);

         galutinis = 0.4 * Vidurkis(laikinvid, countWordsInString(sLine)) + 0.6 * egzaminas;
         stud.setGalutinis(galutinis);
         galutinismediana = 0.4 * Mediana(balai, countWordsInString(sLine)) + 0.6 * egzaminas;
         stud.setGalutinismediana(galutinismediana);


         vektstud.push_back(stud);
        kartai++;
        balai.clear();
    }
    fd.close();


    std::sort(vektstud.begin(), vektstud.end(), stud);


    std::cout<<std::left<<std::setw(Ilgiausia(Pavardes1)+10)<<"Pavarde ";
    std::cout<<std::left<<std::setw(Ilgiausia(Vardai1)+10)<<"Vardas";
    std::cout<<"Galutinis (vid.)/Galutinis (med.) "<<std::endl;
    std::cout<<std::endl;


    for(int i=0;i<vektstud.size();i++){

        std::cout<<std::left<<std::setw(Ilgiausia(Pavardes1)+10)<<vektstud[i].getPavarde();
        std::cout<<std::left<<std::setw(Ilgiausia(Vardai1)+10)<<vektstud[i].getVardas();
        std::cout<<std::left<<std::setw(20)<<std::fixed<<std::setprecision(2)<<vektstud[i].getGalutinis();
        std::cout<<std::left<<std::setw(20)<<vektstud[i].getGalutinismediana()<<std::endl;

    }
}
