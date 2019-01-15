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

void profileEdit(){
    clrscr();
    setTitle("Editing Profile");
    cout<<"0.   Back to Setting page"<<endl;
    cout<<endl;
    admin a=adminInfo();
    cout<<"Your Username is:    "<<a.userName<<endl;
    cout<<"For edit enter 1"<<endl;
    cout<<"Your password is:    ****"<<endl;
    cout<<"For edit enter 2"<<endl;
    cout<<"Your account ID is:      "<<a.accID<<endl;
    cout<<"For edit enter 3"<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
    int x;
    cin>>x;
    if(x==0){
        setting();
    }
    else if(x==1){
        editUsername(a);
    }
    else if(x==2){
        editPassword(a);
    }
    else if(x==3){
        editAccID(a);
    }


}