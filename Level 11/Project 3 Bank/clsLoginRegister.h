


#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
using namespace std;


class clsLoginRegister  
{
    private:
    
  static vector<string> _LoadDataFromFile()
    {   vector<string> Data;
        
        fstream MyFile;
        MyFile.open("LoginRegister.txt",ios::in); //Read Mode
        
        if(MyFile.is_open())
        {
            string line;
            while( getline(MyFile,line) )
            {
                Data.push_back(line);
            }
            
            
        MyFile.close();
        
            
        }
        return Data;
        
    }
    
    static vector<string> _GetDateFromObject(string c)
    {   
        vector<string> vUserDate;
        vUserDate=clsString::Split(c,"#//#");
        

        return vUserDate;
    }
    
    static   void _PrintData(vector<string> vUser)
    {   
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(20) << "User";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Prmetion";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        vector<string> User;
        for(string& c: vUser)
        {   
            User= _GetDateFromObject(c);
        cout << setw(8) << left << "" << "| " << left << setw(25) << User[0];    
        cout << "| " << left << setw(20) <<User[1];
        cout << "| " << left << setw(12) <<User[2];
        cout << "| " << left << setw(20) <<User[3]<<endl;
        }
    }
    
    public:
    
  static  void ShowLoginScreen()
    {
        vector<string>  vUser=_LoadDataFromFile();
        _PrintData(vUser);
    }
    
};























