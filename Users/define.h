//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_DEFINE_H
#define TRAVEL_AGENCY_DEFINE_H

#include <vector>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <windows.h>
#include <conio.h>
#include "../BankAccounts/account_func.h"
#include "../Trip/trip.h"
using namespace std;
typedef struct user{
    char user_name[9]={};
    char user_pass[9]={};
    char fname[21]={};
    char lname[21]={};
    char bank_account[11]={};
    char phone_number[12]={};
    char reference[9]={};
}User;
typedef struct ticket{
    int id = 0;
    Trip ticket_trip={};
    int seat_number=-1;
    char phone_number[12]={};
}Ticket;



#endif //TRAVEL_AGENCY_DEFINE_H
