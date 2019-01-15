//
// Created by Jarvis on 12/30/2018.
//
//Header:
#include "drivers.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary:
#include "../../main.h"
#include "../../someThingNecessary.h"
using namespace std;

void drivers(){
    clrscr();
    fontColor();
    cout<<"************* Drivers Panel ********************"<<endl;
    cout<<endl;
    cout<<"0.    Back to Admin page"<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------";
    cout<<endl;
    cout<<"1.   Show all Drivers."<<endl;
    cout<<"2.   Add Driver."<<endl;
    cout<<"3.   Delete Driver."<<endl;

    int x;
    cin>>x;
}