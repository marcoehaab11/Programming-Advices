#pragma once
#include "clsString.h"
#include <vector>
#include <fstream>


class clsCurrency
{
    private:
    
    enum enMode {EmptyMode=0,UpdateMode=1};
    
    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;
    
    static clsCurrency _ConvertLineToCurrencyObject(string Line,string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData=clsString::Split(Line,Seperator);
        
        return clsCurrency(enMode::UpdateMode,vCurrencyData[0],vCurrencyData[1],vCurrencyData[2]
        , stof(vCurrencyData[3]) );
    }
    
    static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator = "#//#")
    {
        string stCurrencyRecord="";
        stCurrencyRecord+=Currency.GetCountry()+Seperator;
        stCurrencyRecord+=Currency.GetCurrencyCode()+Seperator;
        stCurrencyRecord+=Currency.GetCurrencyNamey()+Seperator;
        stCurrencyRecord+=to_string( Currency.GetRate() )+Seperator;
        
        return stCurrencyRecord;
    
    }
    
 static   vector<clsCurrency> _LoadDataFromFile()
    {
        vector<clsCurrency> vCurrencyData;
        fstream MyFile;
        MyFile.open("Currencies.txt",ios::in);
        if( MyFile.is_open() )
        {   string Line;
            while (getline(MyFile,Line))
            {   
                clsCurrency User;
                User =_ConvertLineToCurrencyObject(Line);
                
                vCurrencyData.push_back(User);
                
            }
            MyFile.close();
        }
        return vCurrencyData;
    }
    
    static void _SaveDataToFile(vector<clsCurrency> vCurrencyData)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt",ios::out); ///overwrite
        
        string DataLine;
        
        if(MyFile.is_open())
        {
            for(clsCurrency c :vCurrencyData)
            {
                DataLine=_ConvertCurrencyObjectToLine(c);
                MyFile<<DataLine<<endl;
            }
            MyFile.close();
            
        }
        
        
    }
    
    void _Update()
    {
        vector<clsCurrency> _vCurrencys;
        _vCurrencys=_LoadDataFromFile();
        
        for(clsCurrency &c:_vCurrencys)
        {
            if(c.GetCurrencyCode()==GetCurrencyCode())
            {
                c=*this;
                break;
            }
        }
        
        _SaveDataToFile(_vCurrencys);
        
    }
    static clsCurrency _GetEmptyCurrencyOblect()
    {
         return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }
    
    
    
    
    
    
    public:
    clsCurrency(){};
    clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate)
    {
        _Mode=Mode;
        _Country=Country;
        _CurrencyCode=CurrencyCode;
        _CurrencyName=CurrencyName;
        _Rate=Rate;
    }
  
	bool IsEmpty()
	{
	    return(_Mode==enMode::EmptyMode);
	}
	string GetCountry()
	{
	    return _Country;
	}
	
	string GetCurrencyCode()
	{
	    return _CurrencyCode;
	}
	
	string GetCurrencyNamey()
	{
	    return _CurrencyName;
	}
	
	float GetRate()
	{
	    return _Rate;
	    
	}
	void SetRate(float Rate)
    {
        _Rate=Rate;
    }
	
	static clsCurrency FindByCode(string CurrencyCode)
	{
	  CurrencyCode=clsString::UpperAllString(CurrencyCode);
	  fstream MyFile;
	  MyFile.open("Currencies.txt",ios::in); //Read _Mode
	  
	  if(MyFile.is_open())
	  {
	      string Line;
	      while(getline(MyFile,Line))
	      {
	          clsCurrency OneDate;
	          OneDate=_ConvertLineToCurrencyObject(Line);
	          
	          if(OneDate.GetCurrencyCode()==CurrencyCode)
	          { 
	              MyFile.close();
	              return OneDate;
	              
	          }
	      }
	      MyFile.close();
	  }
	    
	    return _GetEmptyCurrencyOblect();
	    
	}
	
	static clsCurrency FindByCountry(string Country)
	{
	    Country=clsString::UpperAllString(Country);
	    
	    fstream MyFile;
	    MyFile.open("Currencies.txt",ios::in);
	    
	    if(MyFile.is_open())
	    {
	        string Line;
	        while(getline(MyFile,Line))
	        {
	            clsCurrency Currency=_ConvertLineToCurrencyObject(Line);
	            
	            if(Country==Currency.GetCurrencyNamey())
	            {   
	                
	                MyFile.close();
	                return Currency;
	            }
	            
	            
	        }
	        MyFile.close();
	   
	 }
	    return _GetEmptyCurrencyOblect();
	 
	}
	
	static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1=clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }
	static  vector<clsCurrency> GetCurrencyList()
	{
	    return _LoadDataFromFile();
	}
	
	
	
};