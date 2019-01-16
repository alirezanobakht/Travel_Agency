#include <iostream>
#include "Admin/admin.h"
#include <conio.h>
#include <vector>
#include <ctime>
#include <windows.h>
#include "BankAccounts/account_func.h"
#include "someThingNecessary.h"
#include <stdlib.h>
#include "myAll.h"
using namespace std;


void toBinaryAcc(){
    FILE * f = fopen("BankAccounts/accounts.txt","r");
    if(f!=NULL){
        vector<account> acc;
        account temp;
        char a_temp[20];
        char p_temp[20];
        char r_temp[20];
        while(true){
            fscanf(f,"%s\t%s\t%s",a_temp,p_temp,r_temp);
            if(feof(f)) break;
            temp.ID=atoi(a_temp);
            temp.password=atoi(p_temp);
            temp.remaind=atoi(r_temp);
            acc.push_back(temp);
        }
        fclose(f);
        remove("BankAccounts/accounts.txt");
        FILE * newFile = fopen("BankAccounts/accounts.dat","wb");
        for(int i=0;i<acc.size();i++){
            fwrite(&(acc[i]), sizeof(account), 1, newFile);
        }
        fclose(newFile);
    }
}

int main(){
    toBinaryAcc();
    fullScreen();
    fontColor(120);
    cout<<" ";
    clrscr();
    disableCursor();
    setTitle("Travel Agency");
    int x,y;
    y=getWindowSize().Y/2;
    x=getWindowSize().X/2;
    int color=0;
    char dokme;
    gotoxy(x-4,y-2);
    fontColor(112);
    cout<<"Enter As:";
    while(1){
        color=abs(color)%3;
        gotoxy(x-3,y-1);
        if(color==0){
            fontColor(116);
        }
        else{
            fontColor(120);
        }
        cout<<"Admin";
        gotoxy(x-2,y);
        if(color==1){
            fontColor(116);
        }
        else{
            fontColor(120);
        }
        cout<<"User";
        gotoxy(x-3,y+1);
        if(color==2){
            fontColor(116);
        }
        else{
            fontColor(120);
        }
        cout<<"Driver";


        dokme=getch();
        if(dokme==13){
            if(color==0){
                Admin();
                break;
            }
            else if(color==1){

                break;
            }
            else{

                break;
            }
        }
        else if(dokme==-32){
            dokme=getch();
            if(dokme==80){
                color++;
            }
            else if(dokme==72){
                color--;
            }
        }

    }
    if(x==1){
        Admin();
    }
    else if(x==2){

    }
    else{
    }

    return 0;
}