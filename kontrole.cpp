#include "galvininkas.h"

int PatikraSkaiciams()
{

    bool valid;
    std::string n;
    std::string tikrinimas;
    do
    {
        std::cout<<"Iveskite studentu skaiciu : "<<std::endl;
        std::cin.sync();
        std::getline(std::cin,tikrinimas);
        std::stringstream s(tikrinimas);
        if(s >> n){
            valid = true;
            for(auto& i : tikrinimas)
            {
                if(!std::isdigit(i))
                {
                    valid = false;
                    std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
                    break;
                }
            }
        }
        else{
            valid = false;
            std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
        }
    }while(!valid);

    return std::stoi(tikrinimas);

}
int PatikraEgzaminui()
{

    bool valid;
    std::string n;
    std::string tikrinimas;
    do
    {
        std::cout<<"Iveskite egzamino bala: "<<std::endl;
        std::cin.sync();
        std::getline(std::cin,tikrinimas);
        std::stringstream s(tikrinimas);
        if(s >> n ){
            valid = true;
            for(auto& i : tikrinimas)
            {
                if(!std::isdigit(i))
                {
                    valid = false;
                    std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
                    break;
                }
            }
        }
        else{
            valid = false;
            std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
        }
    }while(!valid);

    return std::stoi(tikrinimas);

}
int PatikraND()
{

    bool valid;
    std::string n;
    std::string tikrinimas;
    do
    {
        std::cout<<"Iveskite namu darbu bala (spauskit 0, kai noresite baigti) : "<<std::endl;
        std::cin.sync();
        std::getline(std::cin,tikrinimas);
        std::stringstream s(tikrinimas);
        if(s >> n){
            valid = true;
            for(auto& i : tikrinimas)
            {
                if(!std::isdigit(i))
                {
                    valid = false;
                    std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
                    break;
                }
            }
        }
        else{
            valid = false;
            std::cout << "Ivedete ne taip bandykite dar karta" << std::endl;
        }
    }while(!valid);

    return std::stoi(tikrinimas);

}
std::string PatikraRaidems()
{
    std::string tikrinimas;
    bool valid;
    std::string n;
    do
    {
        std::getline(std::cin,tikrinimas);
        std::stringstream s(tikrinimas);
        if(s >> n){
            valid = true;
            for(auto& i : tikrinimas)
            {
                if(!std::isalpha(i))
                {
                    valid = false;
                    std::cout << "Ivedete ne taip bandykite dar kart" << std::endl;
                    break;
                }
            }
        }
        else{
            valid = false;
            std::cout << "Ivedete ne taip bandykite dar kart" << std::endl;
        }
    }while(!valid);

    return  tikrinimas;

}

int Ilgiausia(MyVector<std::string>pavardes)
{
    std::string longest=pavardes[0];
    for(int i=0;i<pavardes.size();i++)
    {
        if(longest.size()<pavardes[i].size())
        {
            longest=pavardes[i];
        }
    }

    return longest.size();
}
std::string ValidacijaVidurkiuIrMedianai(std::string b)
{
    while(b.length()!=1 || !isalpha(b[0]) || b[0]!='V' && b[0]!='M' )
    {
        std::cout<<"Iveskite dar kart"<<std::endl;
        std::cout<<"Iveskite [V/M]: ";
        std::cin >> b;
    }

    return b;
}
int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>())-3;
}

bool IsMarkedToDelete(const Studentai & o)
{
    return o.getGalutinis()<=5;


}