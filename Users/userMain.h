//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_USERMAIN_H
#define TRAVEL_AGENCY_USERMAIN_H

#include "mammadUI.h"
#include "users.h"
#include "tickets.h"
void create_user_intro_panel();
void create_user_login_panel();
void create_user_panel(User);
void create_user_register_panel();
void create_setting_panel(User);
void create_delete_panel(User);
void create_edit_panel(User);
void create_guest_register_panel();
void create_show_ticket_panel(User);
int create_pay_panel(User);
int create_pay_panel();
void create_show_transaction_panel(User);
void create_buy_ticket_panel(User);
void create_buy_ticket_panel();
int create_choose_seat_panel();
void create_show_trip_panel(int,int);
void create_show_trip_panel(int,int,User);
#endif //TRAVEL_AGENCY_USERMAIN_H
