//
// Created by Jarvis on 12/28/2018.
//
//header:
#include "adminlogged.h"
//necessary libraries:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary project files:
#include "../main.h"
#include "../BankAccounts/account_func.h"
#include "../someThingNecessary.h"
//Panels:
#include "AdminPanels/setting.h"
#include "AdminPanels/users.h"
#include "AdminPanels/drivers.h"
#include "AdminPanels/tickets.h"
#include "AdminPanels/offers.h"
#include "AdminPanels/transaction.h"
#include "AdminPanels/trips.h"
using namespace std;

void adminLogged(){
    clrscr();
    fontColor();
    {
        //~~~~~~~~~~~~~~~Admin UI~~~~~~~~~~~~~~~~~~~~//
        cout << "*_*      Admin Page      :)" << endl;
        cout << "There is your accessories panel below. Enter the number of each one you want access:" << endl;
        cout<<endl;
        cout << "-1.  Exit" << endl;
        cout << "0.   Back to main menu" << endl;
        cout << endl;
        cout << "1.   Setting" << endl;
        cout << "2.   Users" << endl;
        cout << "3.   Drivers" << endl;
        cout << "4.   Tickets" << endl;
        cout << "5.   Offers" << endl;
        cout << "6.   Account transaction" << endl;
        cout << "7.   Trips" << endl;
        cout<<endl;
        cout << "--------------------------------------------" << endl;
        cout<<endl;
    }

    //----------------user Input-------------------//
    while(true){
        int entered;
        cin>>entered;
        if(entered==-1){
            exit(0);
        }
        else if(entered==0){
            cout<<"Returning to main menu ...";
            Sleep(1000);
            main();
            break;
        }
        else if(entered==1){
            cout<<"Going to Setting ...";
            Sleep(1000);
            setting();
            break;
        }
        else if(entered==2){
            cout<<"Going to User panel ...";
            Sleep(1000);
            users();
            break;
        }
        else if(entered==3){
            cout<<"Going to Drivers panel ...";
            Sleep(1000);
            drivers();
            break;
        }
        else if(entered==4){
            cout<<"Going to the Ticket panel ...";
            Sleep(1000);
            tickets();
            break;
        }
        else if(entered==5){
            cout<<"Going to the Offer panel ...";
            Sleep(1000);
            offers();
            break;
        }
        else if(entered==6){
            cout<<"Going to the Account transaction ...";
            Sleep(1000);
            transaction();
            break;
        }
        else if(entered==7){
            cout<<"Going to the Trips panel ...";
            Sleep(1000);
            trips();
            break;
        }
        else{
            cout<<"\aInput not valid. Try again:"<<endl;
        }


    }

}