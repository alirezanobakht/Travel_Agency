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

using namespace std;

void setting(){
    clrscr();
    setTitle("Setting Panel");
    system("Color 5F");
    cout<<"************* Setting Panel ********************"<<endl;
    cout<<endl;
    cout<<"0.   Back to Admin page"<<endl;
    cout<<endl;
    cout<<"1.   Edit Profile"<<endl;
    cout<<"2.   Edit Pricing Policy"<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
    int x;
    cin>>x;
    if(x==0){
        adminLogged();
    }
    else if(x==1){
        profileEdit();
    }
    else if(x==2){
        editPrice();
    }
}