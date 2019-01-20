//
// Created by Jarvis on 1/18/2019.
//

#include "AhmadDriver.h"


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include "../someThingNecessary.h"
using namespace std;


int  VerifyLoginInfo(int username, char password[50]){
    string fileaddress  = "Drivers/usrs/" + to_string(username) +".drvr";
    FILE* fp = fopen(fileaddress.c_str(),"rb");
    if (fp == NULL) {
        return -1;
    }
    Driver temp = {1,2,3,4,"abc","abc","abc","abc",0};
    fread(&temp, sizeof(Driver),1,fp);
    fclose(fp);
    if (temp.username == username){
        if (strcmp(password,temp.password) == 0){
            return 1;
        }
        return -1;
    }
}


vector<Driver> GetDrivers(){
    vector<Driver> drivers;
    FILE* fp = fopen("Drivers/usrs/Default.dat","rb");
    if (fp == NULL){
        return drivers;
    }
    while(true){
        int temp_usr;
        fread(&temp_usr, sizeof(int), 1, fp);
        if (feof(fp))
            break;
        string fileAddress  = "Drivers/usrs/" + to_string(temp_usr) + ".drvr";
        FILE* fp_d = fopen(fileAddress.c_str(),"rb");
        Driver temp_d;
        fread(&temp_d,sizeof(Driver),1,fp_d);
        drivers.push_back(temp_d);
        fclose(fp_d);
    }
    fclose(fp);
    return drivers;
}



void saveUsernamesToDefaultFile(vector<Driver> AllDrivers){
    FILE * fp = fopen("Drivers/usrs/Default.dat","wb");
    for (int i=0; i < AllDrivers.size(); i++){
        fwrite(&AllDrivers[i].username, sizeof(int),1,fp);
    }
    fclose(fp);
}


int AddDriver(Driver _driver){
    FILE* fp = fopen ("Drivers/usrs/Default.dat","ab");
    vector<Driver> drivers = GetDrivers();
    int newUsername;
    if (drivers.size() == 0){
        _driver.username = 10000;
        newUsername = _driver.username;
        fwrite(&_driver.username, sizeof(int),1,fp);
        string fileaddress = "Drivers/usrs/" + to_string(_driver.username) + ".drvr";
        FILE* fp_d = fopen(fileaddress.c_str(), "wb");
        fwrite(&_driver, sizeof(Driver), 1, fp_d);
        fclose(fp_d);
    }else{
        newUsername = drivers[drivers.size()-1].username + 1;
        _driver.username = newUsername;
        fwrite(&_driver.username, sizeof(int) , 1, fp);
        string fileaddress = "Drivers/usrs/" + to_string(_driver.username) + ".drvr";
        FILE* fp_d = fopen(fileaddress.c_str(), "wb");
        fwrite(&_driver, sizeof(Driver), 1, fp_d);
        fclose(fp_d);
    }
    fclose(fp);
    return newUsername;

}


int DeleteDriver(int username){
    vector<Driver> AllDrivers = GetDrivers();
    bool correct = false;
    for (int i=0; i<AllDrivers.size(); i++){
        if (AllDrivers[i].username == username){
            AllDrivers.erase(AllDrivers.begin() + i);
            string fileAddress = "Drivers/usrs/" + to_string(username) + ".drvr";
            remove(fileAddress.c_str());
            correct = true;
            break;
        }
    }
    if (correct) {
        saveUsernamesToDefaultFile(AllDrivers);
        return 1;
    }else
        return -1;
}

int EditDriversInfo(Driver driver){
    vector<Driver> allDrivers = GetDrivers();
    for (int i=0; i < allDrivers.size(); i++){
        if (allDrivers[i].username == driver.username){
            allDrivers[i] = driver;
            saveUsernamesToDefaultFile(allDrivers);
            return 1;
        }
    }
    return -1;
}


Driver findDriver(int username){
    vector<Driver> drivers = GetDrivers();
    for (int i=0; i < drivers.size(); i++){
        if (drivers[i].username == username)
            return drivers[i];
    }

}
