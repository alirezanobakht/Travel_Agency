//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_TRIP_H
#define TRAVEL_AGENCY_TRIP_H


#include "../myAll.h"
#include "../Drivers/AhmadDriver.h"

typedef struct Trip{
    int ID;
    int src;
    int dst;
    Driver drvr;
    myDate date;
    //vehicle v;
    float estimate;
    int cost;

}Trip;

int getTripID();

vector<Trip> getAllTrip();

vector<Trip> getTrip(int src,int dst);

void addTrip(Trip trip);

void deleteTrip(int id);



#endif //TRAVEL_AGENCY_TRIP_H
