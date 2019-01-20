//
// Created by Jarvis on 12/29/2018.
//
//HEADER:
#include "account_func.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
//Necessary:
#include "../someThingNecessary.h"
using namespace std;

//------------------------ Get tracking number ------------------_/
int getTrack(bool b=true){
    FILE * f = fopen("BankAccounts/trackNumber.dat","rb");
    if(f==NULL){
        fclose(f);
        FILE * fp = fopen("BankAccounts/trackNumber.dat","wb");
        int x=1000;
        fwrite(&x, sizeof(int),1,fp);
        fclose(fp);
        return 1000;
    }
    else{
        int x;
        fread(&x, sizeof(int),1,f);
        x++;
        fclose(f);
        if(b){
            FILE * fp = fopen("BankAccounts/trackNumber.dat","wb");
            fwrite(&x,sizeof(int),1,fp);
            fclose(fp);
        }
        return x;
    }
}

//-------------------------Return all accounts :-----------------_/
vector<account> allAccounts() {
    FILE *f = fopen("BankAccounts/accounts.dat", "rb");
    vector<account> acc;
    account temp;
    while (true) {
        fread(&(temp), sizeof(account), 1, f);
        if(feof(f)) break;
        acc.push_back(temp);
    }
    return acc;
}

//-------------------------Update Accounts.dat file :-------------_/
void updateAccounts(vector<account> acc) {
    FILE *f = fopen("BankAccounts/accounts.dat", "wb");
    for (int i = 0; i < acc.size(); i++) {
        fwrite(&(acc[i]), sizeof(account), 1, f);
    }
}


//-------------------------Return remainder----------------_/
int remainder(int accounts,int password){
    vector<account> acc=allAccounts();
    for(int i=0;i<acc.size();i++){
        if(accounts==acc[i].ID){
            if(password==acc[i].password){
                return acc[i].remaind;
            }
            return -1;
        }
    }
    return -2;
}


//--------------------Add money----------------------_/
int addMoney(int accID,int cost){
    vector<account> acc=allAccounts();
    for(int i=0;i<acc.size();i++){
        if(acc[i].ID==accID){
            acc[i].remaind+=cost;
            updateAccounts(acc);
            return 1;
        }
    }
    return -1;
}


//-------------------Reduce Money--------------------------_/
/*
 * return:
 *  1 : succeed.
 * -3 : not enough money.
 * -2 :no such account.
 * -1 :wrong password.
 */
int reduceMoney(int accID,int password,int cost){
    vector<account> acc=allAccounts();
    for(int i=0;i<acc.size();i++){
        if(accID==acc[i].ID){
            if(password==acc[i].password){
                if(acc[i].remaind-cost>=0){
                    acc[i].remaind-=cost;
                    updateAccounts(acc);
                    return 1;
                }
                return -3;
            }
            return -1;
        }
    }
    return -2;
}

//--------------------Return All Trans----------------_/
vector<trans> getAllTrans(int accID){
    string address=to_string(accID);
    vector<trans> transes;
    trans temp;
    address="BankAccounts/Transaction/"+address+".dat";
    FILE * f = fopen(address.c_str(),"rb");
    if(f==NULL){
        return transes;
    }
        while(true){
            fread(&(temp), sizeof(trans),1,f);
            if(feof(f)) break;
            transes.push_back(temp);

        }
    fclose(f);
    return transes;
}

//---------------------Update trans------------------------_/
void updateTrans(vector<trans> v){
    string s;
    s=to_string(v[0].acc.ID);
    s="BankAccounts/Transaction/"+s+".dat";
    FILE * f = fopen(s.c_str(),"wb");
    for(int i=0;i<v.size();i++){
        fwrite(&(v[i]), sizeof(trans),1,f);
    }
    fclose(f);
}

//--------------------Add Trans------------------------------_/
/*
 * 1 when succeed
 * -1 when no such account
 */
int addTrans(int accID,int cost,int dest,int tracking,char exp[50]){
    vector<account> acc=allAccounts();
    for(int i=0;i<acc.size();i++){
        if(acc[i].ID==accID){
            vector<trans> vtran= getAllTrans(accID);
            trans tran;
            tran.d=nowTime();
            tran.acc.ID=accID;
            tran.acc.password=acc[i].password;
            tran.acc.remaind=0;
            tran.cost=cost;
            memcpy(tran.exp,exp,50);
            tran.dest=dest;
            tran.trackingNumber=tracking;
            vtran.push_back(tran);
            updateTrans(vtran);
            return 1;
        }
    }
    return -2;
}

//--------------------move money---------------------------------_/
int moveMoney(int originID,int originPass,int destID,int cost,char exp[50]){
    int x=reduceMoney(originID,originPass,cost);
    if(x>0){
        addMoney(destID,cost);
        int track=getTrack();
        addTrans(originID,-cost,destID,track,exp);
        addTrans(destID,cost,originID,track,exp);
        return 1;
    }
    else if(x==-3){
        return -3;
    }
}