//
// Created by Jarvis on 12/30/2018.
//
//HEADER:
#include "setting.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary:
#include "../../main.h"
#include "../../BankAccounts/account_func.h"
#include "../../someThingNecessary.h"
#include "../adminlogged.h"
#include "Profile/profileEdit.h"
#include "../../Cities/city.h"
#include "../../myAll.h"

using namespace std;

void setting(){
    fontColor(95);
    cout<<" ";
    clrscr();
    disableCursor();
    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    fontColor(83);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    int color=0;

    while(1){
        color=abs(color%2);

        if(color==0){
            fontColor(80);
        }
        else{
            fontColor(95);
        }
        gotoxy(x/2-6,y/2-1);
        cout << "Edit Profile" << endl;

        if(color==1){
            fontColor(80);
        }
        else{
            fontColor(95);
        }
        gotoxy(x/2-10,y/2);
        cout << "Edit Pricing Policy" << endl;

        char c=getch();

        if(c==27){
            adminLogged();
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
        else if(c==13) {
            if (color == 0) {
                profileEdit();
                break;
            } else if (color == 1) {
                editPrice();
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