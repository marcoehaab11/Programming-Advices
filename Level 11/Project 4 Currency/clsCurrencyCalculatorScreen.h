#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrencyCalculatorScreen : protected clsScreen
{
    
  private:
  
    static void _PrintCurrency(string Code)
    {   clsCurrency Currency=clsCurrency::FindByCode(Code);
        
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.GetCountry();
        cout << "\nCode       : " << Currency.GetCurrencyCode();
        cout << "\nName       : " << Currency.GetCurrencyNamey();
        cout << "\nRate(1$) = : " << Currency.GetRate();

        cout << "\n_____________________________\n";

    }

 static float _ChangeCountryToUsd(string Code,float Amount)
   {    
       float Res=0;
       clsCurrency Usd=clsCurrency::FindByCode("usd");
       clsCurrency CodeofCounrty=clsCurrency::FindByCode(Code);
   
       Res=Amount/CodeofCounrty.GetRate();
       return Res;
   }
  
 static float _ChangefromUsdToCountry(string Code , float UsdAmount)
  {
        float Res=0;
        clsCurrency CodeofCounrty=clsCurrency::FindByCode(Code);
        
        Res=CodeofCounrty.GetRate()*UsdAmount;
        return Res;

  }
  
  public:
  
   static void ShowFindCurrencyScreen ()
  {


    _DrawScreenHeader ("\t  Currency Calculator Screen");

    string Code1,Code2;
    cout << "\nEnter Fisrt Code to Change ?\n";
    cin>>Code1;
    while( !clsCurrency::IsCurrencyExist(Code1))
    {
        cout<<"Wrong Code Enter Another one ?\n";
        cin>>Code1;
    }
    Code1=clsString::UpperAllString(Code1);
    cout << "\nEnter Sec Code to Change ?\n";
    cin>>Code2;
    while( !clsCurrency::IsCurrencyExist(Code2))
    {
        cout<<"Wrong Code Enter Another one ?\n";
        cin>>Code2;
    }
    Code2=clsString::UpperAllString(Code2);
    float Amount=0;
    cout<<"Enter The Amount =\n";
    cin>>Amount;
    if(Code2=="USD")
    {
        
         _PrintCurrency(Code1);
        float Result =_ChangeCountryToUsd(Code1,Amount);
        cout<<"The Change from "<<Code1<<" to "<<Code2<<" = "<<Result<<endl;
    }
    else if (Code1=="USD")
    {
        float Result = _ChangefromUsdToCountry(Code2,Amount);
         cout<<"The Change from "<<Code1<<" to "<<Code2<<" = "<<Result<<endl;
    }
    else 
    {
        _PrintCurrency(Code1);
        float Result =_ChangeCountryToUsd(Code1,Amount);
        cout<<"The Change from "<<Code1<<" to USD = "<<Result<<endl;
        
        _PrintCurrency(Code2);
         float Result2 = _ChangefromUsdToCountry(Code2,Result);
         cout<<"The Change from "<<Code1<<" to "<<Code2<<" = "<<Result2<<endl;
    }
    

  }
  
  
  
  
  
};