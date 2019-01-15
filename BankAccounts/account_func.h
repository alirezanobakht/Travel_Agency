//
// Created by Jarvis on 12/29/2018.
//

#ifndef TRAVEL_AGENCY_ACCOUNT_FUNC_H
#define TRAVEL_AGENCY_ACCOUNT_FUNC_H

#include "../someThingNecessary.h"
#include <istream>
#include <string>
#include <vector>
using namespace std;
/*
 * Account structure :
 */
typedef struct account{
    int ID;
    int password;
    int remaind;
}account;

vector<account> allAccounts();

int getTrack(bool b);

int addMoney(int accID,int cost);

int reduceMoney(int accID,int password,int cost);
/*
 * Transaction structure :
 */
typedef struct trans{
    int trackingNumber;
    account acc;
    myDate d;
    int cost;
    int dest;
    char exp[50]={};
}trans;

/*this function return 3 value:
 * the positive number that is the money in the account
 * -1 : when account exist but password is wrong
 * -2 : when no such account found
 */
int remainder(int account,int password);

int moveMoney(int originID,int originPass,int destID,int cost,char exp[50]);

vector<trans> getAllTrans(int accID);

void updateTrans(vector<trans> v);

/*
 * returns:
 * 0 : if not succeed.
 * -1 : when account exist but password is wrong
 * -2 : when no such account found
 * Else return Tracking number.
 */
int addTrans(int accID,int cost,int destID,int tracking,char exp[50]);

#endif //TRAVEL_AGENCY_ACCOUNT_FUNC_H
