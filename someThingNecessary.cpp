//
// Created by Jarvis on 12/30/2018.
//

#include "someThingNecessary.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
using namespace std;



myDate nowTime(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    myDate md;
    md.year=(ltm->tm_year)%100+2000;
    md.month=ltm->tm_mon+1;
    md.day=ltm->tm_mday;
    md.hour=ltm->tm_hour;
    md.min=ltm->tm_min;
    md.sec=ltm->tm_sec;
    return md;
}



