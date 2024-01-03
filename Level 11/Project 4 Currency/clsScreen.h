#pragma once
#include <iostream>

using namespace std;

class clsScreen
{
protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {   
        time_t t = time(0);
		tm* now = localtime(&t);
		short D,M,Y;
		D = now->tm_mday;
		M = now->tm_mon + 1;
		Y = now->tm_year + 1900;    
        
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
       cout<<"\t\t\t\t\tDate :"<<D<<"/"<<M<<"/"<<Y<<"\n";
    }


};

