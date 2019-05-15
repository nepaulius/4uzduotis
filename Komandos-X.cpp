#include "galvininkas.h"

void DuomenuPateikimas()
{
    MyVector<Studentai> vektstud;
    Studentai stud;

    int a=PatikraSkaiciams();
    while (a<=0 || a>100)
    {
        std::cout<<"Per didelis arba per mazas studentu skaicius.Bandykite dar kart : "<<std::endl;
        a=PatikraSkaiciams();
    }



    MyVector<std::string> vardai2;
    MyVector<std::string> pavardes2;


    for(int i=0;i<a; i++)
    {
        std::string vardas;
        std::cout << "Iveskite varda: "<<std::endl;
        std::cin.sync();
        vardas=PatikraRaidems();
        stud.setVardas(vardas);
        std::string tempVard=stud.getVardas();
        vardai2.push_back(tempVard);


        std::string pavarde;
        std::cout << "Iveskite pavarde: "<<std::endl;
        std::cin.sync();
        pavarde=PatikraRaidems();
        stud.setPavarde(pavarde);
        pavardes2.push_back(pavarde);

        std::string f;
        std::cout<<"Ar norite automatiskai parinkti namu darbu ir egzamino rezultatus? (Jei norite, spauskite M jei ne V)"<<std::endl;
        std::cin>>f;
        std::string p=ValidacijaVidurkiuIrMedianai(f);

        double laikinvid=0;
        MyVector<int>balai;

        if(p[0]=='M')
        {
            int n=3;

            std::mt19937 generator;
            generator.seed(std::time(0));
            std::uniform_int_distribution<uint64_t> dice(1,10);
            int intime;

            for(int i=0;i<n;i++)
            {
                intime=dice(generator);
                balai.push_back(intime);
                stud.setBalai(balai);
                laikinvid=balai[i]+laikinvid;
            }
            int egz=dice(generator);

            double galutinis = 0.4 * Vidurkis(laikinvid,n) + 0.6 * egz;
            stud.setGalutinis(galutinis);
            double galutinismediana= 0.4 * Mediana(balai,n) + 0.6 * egz ;
            stud.setGalutinismediana(galutinismediana);

            vektstud.push_back(stud);
            balai.clear();
        }
else if(p[0]=='V') {
            int b = 1;
            int e = 0;

            do {
                if (b > 0 && b <= 10) {
                    b = PatikraND();
                    while (b > 10) {
                        std::cout << "Per didelis arba per mazas balas.Bandykite dar kart : " << std::endl;
                        b = PatikraND();
                    }
                    balai.push_back(b);
                    stud.setBalai(balai);
                    laikinvid = balai[e] + laikinvid;
                    e++;

                }
            } while (b != 0);

            int egzaminas = PatikraEgzaminui();
            while (egzaminas < 1 || egzaminas > 10) {
                std::cout << "Per didelis arba per mazas balas.Bandykite dar kart : " << std::endl;
                egzaminas = PatikraEgzaminui();
            }
            stud.setTestas(egzaminas);

            double galutinis = 0.4 * Vidurkis(laikinvid, e - 1) + 0.6 * egzaminas;
            stud.setGalutinis(galutinis);

            double galutinismediana = 0.4 * Mediana(balai, e - 1) + 0.6 * egzaminas;
            stud.setGalutinismediana(galutinismediana);

            vektstud.push_back(stud);

            balai.clear();
        }
    }


    Palyginimas(a,vektstud);
    StudentoIvedimas(a,vektstud);
    VidurkioPalyginimas(a,vektstud);
    IsvedimasEkranan(vardai2,pavardes2,vektstud);

}
void VidurkioPalyginimas(int a,MyVector<Studentai>vektstud)
{
    Studentai stud;
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++)

            if (vektstud[i].getGalutinis() != vektstud[j].getGalutinis()) {
                 std::cout <<"Studentas pavarde : " << vektstud[i].getPavarde()<<" turi skirtinga galutini bala nei pavarde: " <<vektstud[j].getPavarde()<< std::endl;
            }

    }
}

void StudentoIvedimas(int a,MyVector<Studentai>vektstud)
{
    Studentai stud;



    bool valid;
    do {
        std::cin >> stud;
        for (int i = 0; i < a; i++) {
            if (vektstud[i].getPavarde() == stud.getPavarde() && vektstud[i].getVardas() == stud.getVardas()) {

                stud = vektstud[i];
                valid = true;

            }

        }

    }while(!valid);

    for(int j=0;j<a;j++)
    {
        if(vektstud[j]>stud)
        {
            std::cout<<vektstud[j];
        }
    }

}

void Palyginimas(int a,MyVector<Studentai>vektstud) {
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++)

            if (vektstud[i] == vektstud[j]) {
                std::cout <<"Studentas vardu : "<< vektstud[i].getVardas() << " ir pavarde : " << vektstud[j].getPavarde()<<" pasikartoja sarase" << std::endl;
            }
    }
}

void IsvedimasEkranan(MyVector<std::string> vardai2,MyVector<std::string> pavardes2,MyVector<Studentai>vektstud)
{

    std::string klausimas=VidurkisArMediana();

    std::cout<<std::left<<std::setw(Ilgiausia(pavardes2)+10)<<"Pavarde ";
    std::cout<<std::left<<std::setw(Ilgiausia(vardai2)+10)<<"Vardas";
    std::cout<<"Galutinis (vid.)/Galutinis (med.) "<<std::endl;

    for(int i=0;i<vektstud.size();i++){

        std::cout<<std::left<<std::setw(Ilgiausia(pavardes2)+10)<<vektstud[i].getPavarde();
        std::cout<<std::left<<std::setw(Ilgiausia(vardai2)+10)<<vektstud[i].getVardas();

        if(klausimas[0]=='V') std::cout<<std::fixed<<std::setprecision(2)<<vektstud[i].getGalutinis()<<std::setw(16)<<std::endl;
        else if(klausimas[0]=='M') std::cout<<std::right<<std::setw(24)<<std::fixed<<std::setprecision(2)<<vektstud[i].getGalutinismediana()<<std::endl;
    }
}
std::string VidurkisArMediana() {

    std::cout << std::endl;
    std::string s;
    std::cout << "Jei norite matyti vidurki, spauskite V, jei mediana spauskite M" << std::endl;
    std::cin >> s;
    std::string h = ValidacijaVidurkiuIrMedianai(s);
    return  h;
}
double Vidurkis(double laikinvid,int e)
{
    double vidurkis = laikinvid/e;
    return vidurkis;
}
double Mediana(MyVector<int> balai,int namsk)
{
    double median;
    std::sort(balai.begin(), balai.end());

    if( namsk%2==0 || namsk==2  )  median=(double)(balai[balai.size()/2+1]+balai[balai.size()/2])/2;
    else median=balai[balai.size()/2];


    return median;
}


