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
#include "AdminPanels/userPanel.h"
#include "AdminPanels/drivers.h"
#include "AdminPanels/ticketsPanel.h"
#include "AdminPanels/offers.h"
#include "AdminPanels/transaction.h"
#include "AdminPanels/tripsPanel.h"
using namespace std;

void adminLogged(){
    fontColor(63);
    cout<<" ";
    clrscr();
    disableCursor();
    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    fontColor(61);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    int color=0;

    while(true) {
        color=abs(color%7);

        if(color==0){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-4,y/2-3);
        cout << "Setting" << endl;

        if(color==1){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-3,y/2-2);
        cout << "Users" << endl;

        if(color==2){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-4,y/2-1);
        cout << "Drivers" << endl;

        if(color==3){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-4,y/2);
        cout << "Tickets" << endl;

        if(color==4){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-3,y/2+1);
        cout << "Offers" << endl;

        if(color==5){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-10,y/2+2);
        cout << "Account transaction" << endl;

        if(color==6){
            fontColor(48);
        }
        else{
            fontColor(63);
        }
        gotoxy(x/2-3,y/2+3);
        cout << "Trips" << endl;

        char c=getch();

        if(c==27){
            main();
            break;
        }
        else if(c==-32){
            c=getch();
            if(c==80){
                color++;
            }
            else if(c==72){
                color--;
            }
        }
        else if(c==13){
            if(color==0){
                setting();
                break;
            }
            else if(color==1){
                usersPanel();
                break;
            }
            else if(color==2){
                drivers();
                break;
            }
            else if(color==3){
                ticketsPanel();
                break;
            }
            else if(color==4){
                offers();
                break;
            }
            else if(color==5){
                transaction();
                break;
            }
            else if(color==6){
                trips();
                break;
            }
        }
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }

    }

}