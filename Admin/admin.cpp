//
// Created by mgh on 12/24/18.
//
#include "admin.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "../main.h"
#include "adminlogged.h"
#include "../BankAccounts/account_func.h"
#include "../someThingNecessary.h"
#include "../myAll.h"


using namespace std;

void SignUp(){
    fontColor(112);
    int x=getWindowSize().X;
    gotoxy(x/2-25,0);
    cout<<"Admin is not registered. You should register one time."<<endl;
    FILE *f=fopen("Admin/admin.encrypted","wb");
    string username;
    string password;
    int accID;
    int accpw;
    //-----------------------------assigning username--------------------//
    fontColor(120);
    cout<<endl<<"     Username :   ";
    fontColor(118);
    cin>>username;
    //-----------------------------assigning password---------------------//
    fontColor(120);
    cout<<"     Password :   ";
    fontColor(118);
    cin>>password;
    //----------------------------assigning Account ID--------------------//
    while(true){
        fontColor(120);
        cout<<"     Account ID :    ";
        fontColor(118);
        cin>>accID;
        if(remainder(accID,0) == -1){
            while(true){
                fontColor(120);
                cout<<"     Account password :   ";
                fontColor(118);
                cin>>accpw;
                if(remainder(accID,accpw)>=0){
                    break;
                }
                else{
                    fontColor(116);
                    cout<<"\a     Sorry, your account password is wrong. try again:"<<endl;
                }
            }
            break;
        }
        else{
            fontColor(116);
            cout<<"\a     Sorry, No such account ID exist. try again:"<<endl;
        }
    }
    admin ad;
    ad.accID=accID;
    memcpy(ad.userName,username.c_str(),20);
    memcpy(ad.password,password.c_str(),20);
    fwrite(&ad, sizeof(admin),1,f);
    fontColor(114);
    cout<<endl<<"     You have registered successfully."<<endl;
    cout<<"          Backing to the main page ...";
    fclose(f);
    Sleep(2000);
    clrscr();
    main();

}

int editAdminProfile(admin a){
    FILE *f=fopen("Admin/admin.encrypted","wb");
    fwrite(&a, sizeof(admin),1,f);
    fclose(f);
}

admin adminInfo(){
    FILE * f=fopen("Admin/admin.encrypted","rb");
    admin ad;
    fread(&ad, sizeof(admin),1,f);
    fclose(f);
    return ad;
}


int Admin(){
    clrscr();
    enableCursor();
    FILE * f=fopen("Admin/admin.encrypted","rb");
    if(f==NULL){
        fclose(f);
        SignUp();
    }
    else{
        admin ad;
        fread(&ad, sizeof(admin),1,f);
        string username(ad.userName),password(ad.password);
        while(true){
            fontColor(112);
            cout<<".:::";
            int x=getWindowSize().X;
            int y=getWindowSize().Y;
            gotoxy(x/2-2,0);
            cout<<"Login";
            gotoxy(x-4,0);
            cout<<":::.";

            fontColor(117);
            gotoxy(5,y-2);
            cout<<"[esc]: Back";
            gotoxy(x-23,y-2);
            cout<<"[alt] + [f4]: Exit";

            gotoxy(0,1);
            fontColor(120);

            string u_username;
            cout<<endl<<"     Username:    ";
            fontColor(118);
            cin>>u_username;
            fontColor(120);
            cout<<"     Password:    ";
            fontColor(118);
            char p[20]={};
            int i=0;
            for(i=0;i<19;i++){
                char c=getch();
                if(c==13){
                    break;
                }
                else if(c==8){
                    if(i>0){
                        cout<<"\b \b";
                        i--;
                        p[i]='\0';
                    }
                    i--;
                }
                else if(c==27){
                    main();
                    break;
                }
                else{
                    p[i]=c;
                    cout<<"*";
                }
            }
            cout<<endl;
            string u_password(p);
            if(u_username==username && u_password==password){
                fontColor(122);
                cout<<"     logging in ...";
                Sleep(1000);
                adminLogged();
                break;
            }
            else{
                fontColor(116);
                cout<<"\a     Username or password is wrong. try again:"<<endl;
                Sleep(1000);
                clrscr();
            }
        }
    }
    }



