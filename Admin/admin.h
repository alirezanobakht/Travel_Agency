//
// Created by mgh on 12/24/18.
//

#ifndef TRAVEL_AGENCY_ADMIN_H
#define TRAVEL_AGENCY_ADMIN_H


//Admin Structure:
typedef struct admin{
    char userName[20];
    char password[20];
    int accID;
}admin;

//Return admin struct:
admin adminInfo();

//Admin Editing profile:
int editAdminProfile(admin a);

//Main function::::
int Admin();

#endif //TRAVEL_AGENCY_ADMIN_H
