//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_TICKETS_H
#define TRAVEL_AGENCY_TICKETS_H

#include "define.h"
vector<Ticket> get_tickets();
vector<Ticket> get_user_tickets(User);
Ticket get_ticket(char[9]);
long int find_ticket_in_tickets(Ticket,User);//point or -1
long int find_ticket_in_tickets(Ticket);//point or -1
long int find_ticket_in_file(char[9]);//1 or -1
int add_ticket(Ticket);//1 or -1
int add_ticket(Ticket,User);//1 or -1
int remove_ticket(Ticket,User);//1 or -1
int remove_ticket(Ticket);//1 or -1



#endif //TRAVEL_AGENCY_TICKETS_H
