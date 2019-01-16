//
// Created by Jarvis on 1/13/2019.
//

#include "profileEdit.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary:
#include "../../../main.h"
#include "../../../BankAccounts/account_func.h"
#include "../../../someThingNecessary.h"
#include "../../adminlogged.h"
#include "../../admin.h"
#include "../setting.h"
#include "../../../myAll.h"
void editUsername(admin a){
    clrscr();
    cout<<"Enter new username:"<<endl;
    string x;
    cin>>x;
    if(x==""){
        while(true) {
            cout << "You entered nothing. try again:" << endl;
            cin>>x;
            if(x!="") break;
        }
    }
    memcpy((a.userName),x.c_str(),20);
    editAdminProfile(a);
    cout<<"Editing was successfully Done!";
    Sleep(500);
    profileEdit();
}

void editPassword(admin a){
    clrscr();
    string p1,p2;
    cout<<"Enter your current password:    ";
    cin>>p1;
    string lpass(a.password);
    if(lpass!=p1){
        while(1) {
            cout << "Wrong password. Try again :    ";
            cin >> p1;
            if(p1==lpass) break;
        }
    }
    cout<<"Enter New Password:    ";
    cin>>p2;
    if(p2==""){
        while(1){
            cout<<"You Entered Nothing. Enter again:    ";
            cin>>p2;
            if(p2!="") break;
        }
    }
    memcpy(a.password,p2.c_str(),20);
    editAdminProfile(a);
    cout<<endl;
    cout<<"Password Changed successfully!";
    Sleep(800);
    profileEdit();
}

void editAccID(admin a){
    int x;
    while(1){
        clrscr();
        cout<<"Enter Acccount ID:   ";
        cin>>x;
        if(remainder(x,0)==-2){
            cout<<"No Such account exist. Try again.";
            Sleep(800);
        }
        else{
            cout<<"Enter Account Password:    ";
            int pass;
            cin>>pass;
            if(remainder(x,pass)==-1){
                while(1){
                    cout<<"Wrong password. Enter Again:    ";
                    cin>>pass;
                    if(remainder(x,pass)!=-1) break;
                }
            }
            break;
        }
    }
    a.accID=x;
    editAdminProfile(a);
    cout<<"Account changed successfully!";
    Sleep(800);
    profileEdit();
}

void  profileEdit(){
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

    admin a=adminInfo();
    int color=0;

    gotoxy(0,2);
    fontColor(95);
    cout<<"   Username:    ";
    fontColor(94);
    cout<<a.userName<<endl;
    fontColor(95);
    cout<<"   Password:    ";
    fontColor(94);
    cout<<"********"<<endl;
    fontColor(95);
    cout<<"   Account ID:  ";
    fontColor(94);
    cout<<a.accID;
    gotoxy(36,2);
    fontColor(90);
    cout<<"Edit";

    while (1) {
        color = abs(color % 3);

        if (color == 0) {
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            gotoxy(35, 2);
            cout << "Edit";
        } else if (color == 1) {
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            gotoxy(35, 3);
            cout << "Edit";
        } else if (color == 2) {
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            cout << "\b \b";
            gotoxy(35, 4);
            cout << "Edit";
        }

        char c=getch();

        if(c==27){
            setting();
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
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }
        else if(c==13){
            if(color==0){
                editUsername(a);
                break;
            }
            else if(color==1){
                editPassword(a);
                break;
            }
            else if(color==2){
                editAccID(a);
                break;
            }
        }

    }
}