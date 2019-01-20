//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_TICKETS_H
#define TRAVEL_AGENCY_TICKETS_H

#include "define.h"



double penaltyPrice(Ticket _ticket);
int getTicketID();
vector<Ticket> return_tickets();
vector<Ticket> return_user_tickets(char user_name[9]);
Ticket return_ticket(int);
long int find_ticket_in_tickets(int,char[9]);//point or -1
long int find_ticket_in_tickets(Ticket);//point or -1
long int find_ticket_in_file(int);//1 or -1
int add_ticket(Ticket, int, int);//1 or -1
int add_ticket(Ticket,User, int);//1 or -1
int remove_ticket(int,User);//1 or -1
int remove_ticket(int,int);//1 or -1



#endif //TRAVEL_AGENCY_TICKETS_H
