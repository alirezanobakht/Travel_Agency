//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_TRIP_H
#define TRAVEL_AGENCY_TRIP_H

#include "../someThingNecessary.h"

//#include "../myAll.h"
#include "../Drivers/AhmadDriver.h"

typedef struct Trip{
    int ID;
    int src;
    int dst;
    Driver drvr;
    myDate date;
    int estimate;
    int cost;
    bool seats[1000] = {};
}Trip;

vector<Trip> getTripDriver(int user);

int getTripID();

vector<Trip> getAllTrip();

vector<Trip> getTripUser(int src, int dst);

void addTrip(Trip trip);

void deleteTrip(int id);

void updateTrip(vector<Trip> trip);

//TODO YE gohi benevisin ke list mosaferaye hameye ye trip khas ba ID khas ro bar gardoone

#endif //TRAVEL_AGENCY_TRIP_H
