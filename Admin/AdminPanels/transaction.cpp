//
// Created by Jarvis on 12/30/2018.
//
//HEADER
#include "transaction.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <vector>
//necessary:
#include "../../main.h"
#include "../../someThingNecessary.h"
#include "../../BankAccounts/account_func.h"
#include "../admin.h"
#include "../adminlogged.h"
#include "../../myAll.h"

using namespace std;

void transaction(){
    fontColor(240);
    cout<<" ";
    clrscr();
    disableCursor();

    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    admin ad=adminInfo();
    int password;

    gotoxy(x/2-15,1);
    cout<<"Your account ID is :   ";
    fontColor(246);
    cout<<ad.accID;
    gotoxy(x/2-30,2);
    fontColor(240);
    cout<<"Please Enter the account password to access detail :   ";
    fontColor(246);
    cin>>password;
    if(remainder(ad.accID,password)==-1){
        for(int i=3;true;i++){
            gotoxy(x/2-17,i);
            fontColor(244);
            cout<<"Wrong password. Try again :  ";
            fontColor(246);
            cin>>password;
            if(remainder(ad.accID,password)>=0) break;
        }
    }
    clrscr();
    gotoxy(x/2-15,1);
    fontColor(240);
    cout<<"Your account ID is :   ";
    fontColor(246);
    cout<<ad.accID;
    fontColor(240);
    cout<<endl;
    cout<<endl;
    cout<<"  The Transaction are shown as below format:"<<endl;
    cout<<"  Tracking Number | dest accID | Cost | Year | Month | Day | Hour | Minute | Second | Explanation"<<endl;
    Sleep(2000);
    cout<<endl;
    vector<trans> vtr = getAllTrans(ad.accID);
    int i = 0;
    if(vtr.size()==0){
        fontColor(244);
        cout<<"  No Transaction done yet."<<endl;
    }
    else {
        for (i = 0; i < vtr.size(); i++) {
            fontColor(242+i%2);
            cout <<"  "<< vtr[i].trackingNumber << " | ";
            cout << vtr[i].dest << " | ";
            cout << vtr[i].cost << " | ";
            cout << vtr[i].d.year << " | ";
            cout << vtr[i].d.month << " | ";
            cout << vtr[i].d.day << " | ";
            cout << vtr[i].d.hour << " | ";
            cout << vtr[i].d.min << " | ";
            cout << vtr[i].d.sec << " | ";
            cout << vtr[i].exp;
            cout << endl;
        }
    }
    cout<<endl;
    gotoxy(x/2-15,8+i);
    fontColor(245);
    cout<<"-----------------------------"<<endl;
    cout<<endl;
    cout<<"  The Account charge is :  "<<remainder(ad.accID,password);

    fontColor(253);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    while(1){
        char c=getch();
        if(c==27){
            setting();
            break;
        }
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }
    }
}