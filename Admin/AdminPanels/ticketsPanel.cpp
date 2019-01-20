//
// Created by Jarvis on 12/30/2018.
//
//HEADER:
#include "../../Users/tickets.h"
#include "ticketsPanel.h"
//Necessary Includes:
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>

//necessary:
#include "../../main.h"
#include "../../someThingNecessary.h"
#include "../../UI/UI.h"
#include "../../myAll.h"


using namespace std;

void ticketsPanel(){
    fontColor(192);
    cout<<" ";
    clrscr();
    vector<Ticket> tickets = return_tickets();
    cout<<"  Enter [esc] to back to admin panels."<<endl;
    cout<<"  Ticket ID  |  Phone number  |  From  |  To  |  cost  |  Seat number  |  MM/DD/YY  |  HH:MM"<<endl;
    cout<<endl;
    if(tickets.size()<=0){
        cout<<endl;
        fontColor(207);
        cout<<"NO Ticket yet.";
    }
    for(int i=0;i<tickets.size();i++){
        if(i%2==0){
            fontColor(203);
        }
        else{
            fontColor(199);
        }
        cout<<"  "<<tickets[i].id<<"  |  "<<tickets[i].phone_number<<"  |  "<<tickets[i].ticket_trip.src<<"  |  "<<tickets[i].ticket_trip.cost<<
        "  |  "<<tickets[i].seat_number<<"  |  "<<tickets[i].ticket_trip.date.month<<"/"<<tickets[i].ticket_trip.date.day<<"/"<<tickets[i].ticket_trip.date.year<<
        "  |  "<<tickets[i].ticket_trip.date.hour<<":"<<tickets[i].ticket_trip.date.min<<endl;
    }
    char c;
    while(true){
        c=getch();
        if(c==27){
            adminLogged();
            break;
        }
        else if(c==0){
            c=getch();
            if(c==107)
                exit(0);
        }
    }
}