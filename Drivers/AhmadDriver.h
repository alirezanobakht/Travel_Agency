//
// Created by Jarvis on 1/18/2019.
//

#ifndef TRAVEL_AGENCY_AHMADDRIVER_H
#define TRAVEL_AGENCY_AHMADDRIVER_H

#include <vector>
using namespace std;


#define BUS 0
#define CAR 1
#define AIRPLANE 2
#define TRAIN 3

typedef struct vehicle{
    int model=0;
    int capacity=0;
    int velocity=0;
    //vector<bool> ifSeatsAreNotOccupied;
} Vehicle;

typedef struct driver{
    Vehicle v={};
    int username=-1;
    char password[50]="1";
    char fname[10]={};
    char lastname[10]={};
    char phonenumber[12]={};
    int bankaccount=0;
} Driver;



/* This function verifies your login information!
    returns -1 : if there is no fucking match for the username in the system or the password is wrong.
    returns  1 : if the login operation was successful.

*/
int  VerifyLoginInfo(int username, char password[50]);


/*
 * returns all vectors in one vector
*/
vector<Driver> GetDrivers();


/*
 * Returns the place of a special driver in vector.
 * Returns -1 if the username was not found in the vector;
 */
int findDriver(int username);


/*
 * This function adds a new driver to the system.
 * Returns the username for the given driver/
*/
int AddDriver(Driver _driver);


/*
 * This function deletes a selected driver.
 * returns -1 : if the fucking username is not available.
 * returns 1 : if the operation completes successfully.
 */
int DeleteDriver(int username);


/*
 * This function will save edited driver in the usrs folder.
 * returns 1 : if the operation was successful.
 * returns -1 : if there wasn't any match for the username entered.
*/
int EditDriversInfo(Driver driver);


/*
 * You fucking want comment for this shit?
 */
void saveUsernamesToDefaultFile(vector<Driver> AllDrivers);





#endif //TRAVEL_AGENCY_AHMADDRIVER_H
