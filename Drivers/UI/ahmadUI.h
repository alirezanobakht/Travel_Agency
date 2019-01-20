//
// Created by Jarvis on 1/18/2019.
//

#ifndef TRAVEL_AGENCY_AHMADUI_H
#define TRAVEL_AGENCY_AHMADUI_H

#include <conio.h>
#include <string>
#include <string.h>
#include <Windows.h>
#include "../../UI/UI.h"
#include "../../BankAccounts/account_func.h"
#include "../AhmadDriver.h"
using namespace std;





void editProfilePage(int username);


void driversLoginPage(int username,Driver drvr);



void loginPage();

void listOfAllTripsDriver(int username);

void listOfAllTransactions(int username);




void EditPhonenumber (int username);
void EditPassword (int username);
void EditFname (int username);
void EditLname (int username);
void DeleteDriverAccount (int username);
void EditBankAccount (int username);
int stringToInt(string input);


//-------------------------------Nobakht-------------------------------
/*
void gotoxy(int x,int y);

void fullScreen();



void fontColor(int x);

void setTitle(char a[20]);

void clrscr();

COORD getWindowSize();



*/


#endif //TRAVEL_AGENCY_AHMADUI_H
