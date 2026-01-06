#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen {
private:

    static  bool _Login() {
        bool LoginFaild = false;
        short Tries = 3;

        string Username, Password;
        do {

            if (LoginFaild) {
                cout << "\nInvlaid Username/Password!\n\n";
                Tries--;
                cout << "You have " << Tries << " Trial(s) to login.\n\n";
            }

            if (Tries == 0) {
                cout << "\n\nYou are locked after 3 failed trails.\n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();


        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        
        return true;
    }

public:

     static bool ShowLoginScreen(){
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};

