//
// Created by Jarvis on 1/19/2019.
//

#include "TripsFunctions.h"
#include "../UI/UI.h"
#include "UI/ahmadUI.h"
#include "../Cities/city.h"
int NumberOfSoldTickets(Trip _trip, int capacity){
    int c = 0;
    for (int i = 0; i < capacity; i++) {
        if (_trip.seats[i] == true)
            c++;
    }
    return c;

}

void defineNewTrip(int username,Driver drvr){
    fontColor(103);
    cout << " ";
    clrscr();
    Trip newTrip = {};
    gotoxy(4,4);
    cout << "Enter Starting City : ";
    gotoxy(4,5);
    cout << "Enter Destination City :";
    gotoxy(4,6);
    cout << "Enter Year : ";
    gotoxy(4,7);
    cout << "Enter Month : ";
    gotoxy(4,8);
    cout << "Enter Day : ";
    gotoxy(4,9);
    cout << "Enter Dept. Hour : ";
    gotoxy(4,10);
    cout << "Enter Dept. Min : ";
    gotoxy(26,4);
    cin >> newTrip.src;
    gotoxy(28, 5);
    cin >> newTrip.dst;
    gotoxy(17,6);
    cin >> newTrip.date.year;
    gotoxy(18,7);
    cin >> newTrip.date.month;
    gotoxy(16,8);
    cin >> newTrip.date.day;
    gotoxy(23,9);
    cin >> newTrip.date.hour;
    gotoxy(22,10);
    cin >> newTrip.date.min;
    newTrip.cost = getPrice(newTrip.src,newTrip.dst);
    newTrip.drvr = drvr;
    newTrip.ID = getTripID();
    newTrip.estimate = getDistance(newTrip.src,newTrip.dst) / newTrip.drvr.v.velocity;
    addTrip(newTrip);
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-12,y);
    cout<<"Trip Added Successfully!";
    _sleep(1500);
    driversLoginPage(username,findDriver(username));
}
