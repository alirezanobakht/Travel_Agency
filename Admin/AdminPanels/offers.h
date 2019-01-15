//
// Created by Jarvis on 12/30/2018.
//

#ifndef TRAVEL_AGENCY_OFFERS_H
#define TRAVEL_AGENCY_OFFERS_H

#include "../../myAll.h"

typedef struct off{
    char id[16];
    int percentage;
}off;

vector<off> getAllOffers();

void updateOffers(vector<off> offers);

int offerpercent(char id[16]);

void showAllOffers();

void createOffer();

void deleteOffer();

void offers();




#endif //TRAVEL_AGENCY_OFFERS_H
