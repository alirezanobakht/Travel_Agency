//
// Created by Jarvis on 12/30/2018.
//

#ifndef TRAVEL_AGENCY_SOMETHINGNECESSARY_H
#define TRAVEL_AGENCY_SOMETHINGNECESSARY_H

//Date structure:
typedef struct myDate{
    int year = 2000;
    int month = 1;
    int day = 1;
    int hour = 0;
    int min = 0;
    int sec = 0;
}myDate;


//Return Now time:
myDate nowTime();


#endif //TRAVEL_AGENCY_SOMETHINGNECESSARY_H
