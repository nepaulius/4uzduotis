#include "galvininkas.h"




int main()
{

   // Strategas();

    std::string q;
    std::cout<<"Iveskite V, jei norite skaityti is failo, M jei norite rasyti ranka : "<<std::endl;
    std::cin>>q;
    std::string c=ValidacijaVidurkiuIrMedianai(q);


    if(c[0]=='V')
    {
        SkaitymasIsFailo();
    }
    else if(c[0]=='M') {
        DuomenuPateikimas();

    }


}