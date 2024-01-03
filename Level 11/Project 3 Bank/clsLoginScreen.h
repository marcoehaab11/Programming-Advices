#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

   

  static  bool _Login()
    {
        bool LoginFaild = false;
        short Counter=0;
        string Username, Password;
        do
        {
     
            if (LoginFaild)
            {
                
                cout << "\nInvlaid Username/Password! You Have "<<3-Counter<<" Tries"<<"\n\n";
                
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            Counter++;
            if(Counter==3)
            return false;
            
        } while (LoginFaild );
        CurrentUser.RegisterLogIn();  
        clsMainScreen::ShowMainMenue();

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

