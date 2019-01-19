//
// Created by Jarvis on 1/17/2019.
//

#include "trip.h"
#include "../myAll.h"

using namespace std;

int getTripID(){
    FILE *f=fopen("Trip/getTripId.dat","rb");
    if(f==NULL){
        fclose(f);
        FILE * fp = fopen("Trip/getTripId.dat","wb");
        int x;
        x=1000;
        fwrite(&x, sizeof(int),1,fp);
        fclose(fp);
        return x;
    }
    else{
        int x;
        fread(&x, sizeof(int),1,f);
        fclose(f);
        x++;
        FILE * fp = fopen("Trip/getTripId.dat","wb");
        fwrite(&x, sizeof(int),1,fp);
        fclose(fp);
        return x;
    }
}

void updateTrip(vector<Trip> trip){
    FILE * f= fopen("Trip/trips.dat","wb");
    for(int i=0;i<trip.size();i++){
        fwrite(&(trip[i]), sizeof(Trip),1,f);
    }
    fclose(f);
}

vector<Trip> getAllTrip(){
    vector<Trip> trips;
    Trip trip;
    FILE * f=fopen("Trip/trips.dat","wb");
    if(f==NULL){
        fclose(f);
        return trips;
    }
    else{
        while(1){
            fread(&trip, sizeof(Trip),1,f);
            if(feof(f)) break;
            trips.push_back(trip);
        }
    }
    fclose(f);
    return trips;
}

vector<Trip> getTrip(int src,int dst){
    vector<Trip> trips=getAllTrip();
    vector<Trip> wanted;
    for(int i=0;i<trips.size();i++){
        if(src==trips[i].src && dst==trips[i].dst){
            wanted.push_back(trips[i]);
        }
    }
    return wanted;
}

void addTrip(Trip trip){
    vector<Trip> trips=getAllTrip();
    trips.push_back(trip);
    updateTrip(trips);
}

void deleteTrip(int id){
    vector<Trip> trips=getAllTrip();
    for(int i=0;i<trips.size();i++){
        if(trips[i].ID==id){
            trips.erase(trips.begin() + i);
            break;
        }
    }
    updateTrip(trips);
}


