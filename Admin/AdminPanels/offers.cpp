//
// Created by Jarvis on 12/30/2018.
//
//HEADER:
#include "offers.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary:
#include "../../myAll.h"
#include "../../main.h"
#include "../../someThingNecessary.h"

using namespace std;


//----------------IT'S FOR YOU---------------------
int offPercent(string id){
    vector<off> ofrs=getAllOffers();
    for(int i=0;i<ofrs.size();i++){
        string a(ofrs[i].id);
        if(a==id){
            return ofrs[i].percentage;
        }
    }
    return -1;
}


//------------------NOT FOR YOU--------------------
void offers(){
    fontColor(232);
    cout<<" ";
    clrscr();
    disableCursor();
    int x=getWindowSize().X;
    int y=getWindowSize().Y;

    fontColor(237);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    int color=0;

    while(1){
        color=abs(color%3);

        if(color==0){
            fontColor(224);
        }
        else{
            fontColor(230);
        }
        gotoxy(x/2-8,y/2-1);
        cout << "Show All Offers" << endl;

        if(color==1){
            fontColor(224);
        }
        else{
            fontColor(230);
        }
        gotoxy(x/2-8,y/2);
        cout << "Create new offer" << endl;
        if(color==2){
            fontColor(224);
        }
        else{
            fontColor(230);
        }
        gotoxy(x/2-6,y/2+1);
        cout << "Delete offer" << endl;



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
                showAllOffers();
                break;
            }
            else if(color==1){
                createOffer();
                break;
            }
            else if(color==2){
                deleteOffer();
                break;
            }
        }
    }

    /*
    setTitle("Offer Panel");
    cout<<"************* Offers Panel ********************"<<endl;
    cout<<endl;
    cout<<"0.    Return to Setting panel"<<endl;
    cout<<endl;
    cout<<"1.    Show All offers"<<endl;
    cout<<"2.    Create new offer"<<endl;
    cout<<"3.    Delete offer"<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<endl;
    int x;
    cin>>x;
    if(x==0){
        setting();
    }
    else if(x==1){
        showAllOffers();
    }
    else if(x==2){
        createOffer();
    }
    else if(x==3){
        deleteOffer();
    }*/
}

void showAllOffers(){
    clrscr();
    cout<<endl;
    cout<<"List of Offers:"<<endl;
    cout<<"OfferID   |   Percentage"<<endl;
    cout<<endl;
    vector<off> offer=getAllOffers();
    if(offer.size()==0){
        cout<<"No offer Exist."<<endl;
    }
    for(int i=0;i<offer.size();i++){
        cout<<offer[i].id<<"   |   "<<offer[i].percentage<<"%"<<endl;
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<endl;
    cout<<"0.    Return to offer page"<<endl;
    cout<<endl;
    int x;
    cin>>x;
    if(x==0){
        offers();
    }
}

void createOffer(){
    clrscr();
    setTitle("Create Offer");
    cout<<"Add New Offer:"<<endl;
    cout<<"Enter offer ID:    ";
    string x;
    cin>>x;
    cout<<"Enter offer percentage (between 1 and 99):    ";
    int y;
    cin>>y;
    y=y%99;
    off o;
    o.percentage=y;
    memcpy(&o.id,x.c_str(),15);
    vector<off> ofrs=getAllOffers();
    ofrs.push_back(o);
    updateOffers(ofrs);
    cout<<"New offer is now available!";
    Sleep(800);
    offers();
}

void deleteOffer(){
    clrscr();
    setTitle("Delete Offer");
    cout<<"Enter the  ID of offer you want to Delete:    "<<endl;
    string a;
    cin>>a;
    vector<off> ofrs=getAllOffers();
    for(int i=0;i<ofrs.size();i++){
        string b(ofrs[i].id);
        if(b==a){
            ofrs.erase(ofrs.begin()+i);
            cout<<endl<<"Offer deleted successfully!";
            updateOffers(ofrs);
            Sleep(800);
            offers();
            break;
        }
    }
    cout<<"There is no such a offer."<<endl;
    Sleep(800);
    offers();
}


vector<off> getAllOffers(){
    vector<off> offers;
    off offer;
    FILE * f= fopen("BankAccounts/Offers.dat","rb");
    if(f==NULL){
        fclose(f);
        return offers;
    }
    else{
        while(1){
            fread(&offer, sizeof(off),1,f);
            if(feof(f)) break;
            offers.push_back(offer);
        }
        fclose(f);
        return offers;
    }
}


void updateOffers(vector<off> offers){
    FILE * f= fopen("BankAccounts/Offers.dat","wb");
    for(int i=0;i<offers.size();i++){
        fwrite(&(offers[i]), sizeof(off),1,f);
    }
    fclose(f);
}