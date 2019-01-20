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
#include "../../myAll.h"
using namespace std;


void showDriverPanel(){
    fontColor(6);
    cout<<" ";
    clrscr();

    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    fontColor(13);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";
    gotoxy(0,0);

    fontColor(6);
    vector<Driver> dvr=GetDrivers();
    if(dvr.size()<=0){
        cout<<endl;
        cout<<"  No Drivers found.";
    }
    else{
        cout<<endl;
        cout<<"  Username  |  First name  |  Last name  |  phone number  |  Account ID  |  Vehicle capacity  |  Vehicle velocity"<<endl;
        for(int i=0;i<dvr.size();i++){
            if(i%2==0){
                fontColor(15);
            }
            else{
                fontColor(14);
            }
            cout<<"  "<<dvr[i].username<<"  |  "<<dvr[i].fname<<"  |  "<<dvr[i].lastname<<"  |  "<<dvr[i].phonenumber<<"  |  "<<dvr[i].bankaccount<<"  |  "<<dvr[i].v.capacity<<"  |  "<<dvr[i].v.velocity<<endl;
        }
    }
    char c;
    while(1){
        c=getch();
        if(c==27){
            drivers();
            break;
        }
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }
    }
}

void deleteDriverPanel(){

    clrscr();

    int username;
    cout<<endl;
    cout<<"  enter username of driver you want to delete:   ";
    cin>>username;
    int y=DeleteDriver(username);
    if(y==1){
        cout<<"  Driver deleted successfully.";
        Sleep(1500);
    }
    else{
        fontColor(172);
        cout<<"\a  Error deleting the Driver please check username and then try again!";
        Sleep(1500);
    }
    drivers();
}

void addDriverPanel(){
    Driver d;
    Vehicle v;
    char password[50]="1";
    char fname[10]={};
    char lastname[10]={};
    char phonenumber[12]={};
    int bankaccount=0;
    clrscr();

    cout<<endl;
    cout<<"  Enter drivers info:           "<<endl;
    cout<<"  First name:                         ";
    cin>>fname;
    cout<<"  Last name:                          ";
    cin>>lastname;
    cout<<"  Phone number:                       ";
    cin>>phonenumber;
    cout<<"  Vehicle Type(between 0 & 2):        ";
    cin>>v.model;
    cout<<"  Vehicle velocity:                   ";
    cin>>v.velocity;
    cout<<"  Vehicle capacity:                   ";
    cin>>v.capacity;
    cout<<"  Account ID(between 200000 & 299999: ";
    cin>>bankaccount;

    d.v=v;
    d.bankaccount=bankaccount;
    memcpy(d.fname,fname,10);
    memcpy(d.lastname,lastname,10);
    memcpy(d.phonenumber,phonenumber,12);

    int user=AddDriver(d);

    cout<<endl;
    cout<<endl;
    cout<<"  Driver username is :  "<<user<<endl;
    cout<<"  press any key to continue.";
    drivers();



}

void editDriverPanel(){
    clrscr();
    cout<<endl<<"  Enter driver username:   ";
    int user;
    cin>>user;
    Driver d=findDriver(user);
    clrscr();
    vector<Driver> dvrs=GetDrivers();
    cout<<"  Enter Driver Id:   ";
    int id;
    cin>>id;
    Driver dvr;
    for(int i=0;i<dvrs.size();i++){
        if(dvrs[i].username==id){
            dvr=dvrs[i];
        }
    }
    clrscr();
    cout<<endl;
    cout<<"1.  Edit first name"<<endl;
    cout<<"2.  Edit last name"<<endl;
    cout<<"3.  Edit phone number"<<endl;
    cout<<"4.  Edit vehicle velocity"<<endl;
    cout<<"5.  Edit vehicle capacity"<<endl;
    cout<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<endl;
    int x;
    cin>>x;

    if(x==1){
        cout<<"Enter new first name:  "<<endl;
        char c[10];
        cin>>c;
        memcpy(dvr.fname,c,10);
    }
    else if(x==2){
        cout<<"Enter new last name:  "<<endl;
        char c[10];
        cin>>c;
        memcpy(dvr.lastname,c,10);
    }
    else if(x==3){
        cout<<"Enter new Phone number:  "<<endl;
        char c[12];
        cin>>c;
        memcpy(dvr.lastname,c,12);
    }
    else if(x==4){
        cout<<"Enter new velciyt:  "<<endl;
        int y;
        dvr.v.velocity=y;
    }
    else if(x==5){
        cout<<"Enter new capacity:  "<<endl;
        int y;
        cin>>y;
        dvr.v.capacity=y;
    }
    EditDriversInfo(dvr);
    drivers();
}


void drivers(){
    fontColor(160);
    cout<<" ";
    clrscr();

    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    fontColor(173);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    fontColor(160);

    int color =0;

    while(true){
        color=abs(color%4);

        if(color==0){
            fontColor(160);
        }
        else{
            fontColor(175);
        }
        gotoxy(x/2-8,y/2-2);
        cout<<"Show All Drivers";

        if(color==1){
            fontColor(160);
        }
        else{
            fontColor(175);
        }
        gotoxy(x/2-7,y/2-1);
        cout<<"Add new driver";

        if(color==2){
            fontColor(160);
        }
        else{
            fontColor(175);
        }
        gotoxy(x/2-6,y/2);
        cout<<"Edit Driver";

        if(color==3){
            fontColor(160);
        }
        else{
            fontColor(175);
        }
        gotoxy(x/2-7,y/2+1);
        cout<<"Delete Driver";

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
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }
        else if(c==13){
            if(color==0){
                showDriverPanel();
                break;
            }
            else if(color==1){
                addDriverPanel();
                break;
            }
            else if(color==2){

                break;
            }
            else{
                deleteDriverPanel();
                break;
            }
        }
    }

}