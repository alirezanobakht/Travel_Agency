//
// Created by Jarvis on 1/17/2019.
//

#include "userMain.h"
#include "../main.h"
#include "../Trip/trip.h"
void cursor_disable(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=100;
    cursor.bVisible=false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}

void cursor_enable(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=20;
    cursor.bVisible=true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}

bool goto_intro_panel=false;
bool is_guset=false;
bool is_ticket_cancel=false;
//----------------------------------------------------------------------------------------
char*str_to_char(string str,int length){
    char *ch=(char*)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++){
        ch[i]='\0';
    }
    for(int i=0;i<str.length();i++){
        ch[i]=str[i];
    }
    return ch;
}
User create_new_user(string user_name,string user_pass,string fname,string lname ,string bank_account,string phone_number,string reference){
    User new_user={};
    for(int i=0;i<9;i++){
        new_user.user_name[i]=str_to_char(user_name,9)[i];
        new_user.user_pass[i]=str_to_char(user_pass,9)[i];
        new_user.reference[i]=str_to_char(reference,9)[i];
    }
    for(int i=0;i<21;i++){
        new_user.fname[i]=str_to_char(fname,21)[i];
        new_user.lname[i]=str_to_char(lname,21)[i];
    }
    for(int i=0;i<11;i++){
        new_user.bank_account[i]=str_to_char(bank_account,11)[i];
    }
    for(int i=0;i<12;i++){
        new_user.phone_number[i]=str_to_char(phone_number,12)[i];
    }
    return new_user;
}
//----------------------------------------------------------------------------------------
void create_user_intro_panel(){
    font_color(243);
    printf("");
    clearIt();
    cursor_enable();
    while(true) {
        goto_intro_panel = false;
        int items[4][2] = {{4, 3},{4, 4},{4, 5},{4, 9}};
        int h = 11;
        int w = 32;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("[1] Login Into Your Account.", 3, 3);
        add_text_to_raw_menu("[2] Create New Account.", 3, 4);
        add_text_to_raw_menu("[3] Join As A Guest.", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 3, 9);
        int i = move_between_items(items, 4);
        switch (i) {
            case 0:
                create_user_login_panel();
                break;
            case 1:
                create_user_register_panel();
                break;
            case 2:
                create_buy_ticket_panel();
                break;
            case 3:
                main();
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
void create_user_login_panel(){
    User loggedin_user={};
    while (true) {
        if(goto_intro_panel) return;
        int items[2][2] = {{14, 4,},{5,  10}};
        int h = 12;
        int w = 56;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("If You Want To Add Your Username Press Enter.  ", 4, 2);
        add_text_to_raw_menu("Username : ", 3, 4);
        add_text_to_raw_menu("Password : ", 3, 6);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 8);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 10);
        int i = move_between_items(items, 2);
        if (i == 0) {
            string name = input(1,8,'\0',true,true,true);
            gotoXY(14, 6);
            string  pass = input(1,8,'*',true,true,true);
            loggedin_user = user_login(str_to_char(name,9),str_to_char(pass,9) );
        } else if (i == 1) {
            return;
        }
        if(loggedin_user.user_name[0]!='\0') break;
        create_raw_menu(3,56,1,13,false);
        add_text_to_raw_menu("Your Username Or Password Is Wrong Please Try Again.",3,14);
        gotoXY(1,15);
        Sleep(1500);
    }
    create_user_panel(loggedin_user);
}
void create_user_register_panel(){
    while(true) {
        int items[2][2]={{14,4},{5,21}};
        int h = 23;
        int w = 58;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("If You Want To Add Your Username Press Enter.  ",3, 2);
        add_text_to_raw_menu("Username : ", 3, 4);
        add_text_to_raw_menu("Password : ", 3, 6);
        add_text_to_raw_menu("First Name : ", 3, 8);
        add_text_to_raw_menu("Last Name : ", 3, 10);
        add_text_to_raw_menu("Bank Account : ", 3, 12);
        add_text_to_raw_menu("Phone Number : ", 3, 14);
        add_text_to_raw_menu("If You Have Reference", 3, 16);
        add_text_to_raw_menu("Please Enter His/Her Username : ", 3, 17);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 19);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 21);
        int n=move_between_items(items,2);
        if(n==1) break;
        gotoXY(14, 4);
        string user_name=input(1,8,'\0',true,true,true);
        if (find_user_in_file(str_to_char(user_name,9)) == -1) {
            gotoXY(14, 6);
            string user_pass=input(1,8,'*',true,true,true);
            gotoXY(16, 8);
            string fname=input(1,20,'\0',false,true,false);
            gotoXY(15, 10);
            string lname=input(1,20,'\0',false,true,false);
            gotoXY(18, 12);
            string bank_account=input(1,10,'\0',true,false,false);
            gotoXY(18, 14);
            string phone_number=input(11,11,'\0',true,false,false);
            gotoXY(35, 17);
            string reference=input(0,8,'\0',true,true,true);
            User new_user=create_new_user(user_name,user_pass,fname,lname,bank_account,phone_number,reference);
            int n=add_user(new_user);
            if(n==1) break;
            else{
                create_raw_menu(3, 58, 1, 24, false);
                add_text_to_raw_menu("Something Went Wrong Please Try Again.", 3, 20);
                gotoXY(1, 25);
            }
        }
        create_raw_menu(3, 58, 1, 24, false);
        add_text_to_raw_menu("User " + user_name + " is Exists Please Enter Another Username.", 3, 25);
        gotoXY(1, 26);
        Sleep(1500);
    }
}
//----------------------------------------------------------------------------------------
void create_user_panel(User _user){
    while(true) {
        if(goto_intro_panel) return;
        create_raw_menu(3,46,1,1,true);
        add_text_to_raw_menu("Hello "+(string)_user.fname+" "+(string)_user.lname+".",3,2);
        gotoXY(1,4);
        Sleep(1000);
        int items[5][2] = {{4, 6},{4, 7},{4, 8},{4,9},{4, 13}};
        int h = 12;
        int w = 46;
        create_raw_menu(h, w,1,4, false);
        add_text_to_raw_menu("[1] Show My Tickets.", 3, 6);
        add_text_to_raw_menu("[2] Show My Transactions.", 3, 7);
        add_text_to_raw_menu("[3] Buy New Ticket.", 3, 8);
        add_text_to_raw_menu("[4] Setting.", 3, 9);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 11);
        }
        add_text_to_raw_menu("[#] Log out.", 3, 13);
        int i = move_between_items(items, 5);
        switch (i) {
            case 0:
                create_show_ticket_panel(_user);
                break;
            case 1:
                create_show_transaction_panel(_user);
                break;
            case 2:
                create_buy_ticket_panel(_user);
                break;
            case 3:
                create_setting_panel(_user);
                break;
            case 4:
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
void create_setting_panel(User _user){
    while(true) {
        if(goto_intro_panel) return;
        int items[3][2] = {{4, 3},{4, 4},{4, 9}};
        int h = 11;
        int w = 32;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("[1] Edit My Account.", 3, 3);
        add_text_to_raw_menu("[2] Delete My Account.", 3, 4);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 3, 9);
        int i = move_between_items(items, 3);
        switch (i) {
            case 0:
                create_edit_panel(_user);
                break;
            case 1:
                create_delete_panel(_user);
                break;
            case 2:
                clearIt();
                return;
        }
    }
}
void create_show_ticket_panel(User _user){
    clearIt();
    vector<ticket> tickets=get_user_tickets(_user);
    if(tickets.size()>0) {
        int **items = (int **) malloc(sizeof(int *) * tickets.size());
        for (int i = 0; i < tickets.size(); i++)
            items[i] = (int *) malloc(sizeof(int) * 2);
        int h = 9;
        int w = 64;
        for (int i = 0; i < tickets.size(); i++) {
            int Y = (h + 3) * i + 1;
            items[i][0] = 3;
            items[i][1] = Y + 1;
            create_raw_menu(3, 5, 1, Y, false, 0);
            create_raw_menu(3, w, 1, Y, false, 0);
            add_text_to_raw_menu(tickets[i].id, w / 2 - 3, Y + 1);
            add_text_to_raw_menu("[ ]", 2, Y + 1);
            create_raw_menu(h, w, 1, Y + 2, false, 0);
            add_text_to_raw_menu("From : ", 9, Y + 4);
            add_text_to_raw_menu("To : ", 35, Y + 4);
            add_text_to_raw_menu("Start Date : ", 3, Y + 6);
            for (int i = 2; i < w; i++) {
                add_text_to_raw_menu("-", i, Y + 8);
            }
            add_text_to_raw_menu("Cost : " + to_string(tickets[i].cost), 3, Y + 9);
        }
        int n = move_between_items(items, (int) tickets.size());
    }else{
        add_text_to_raw_menu("No Tickets Found.", 1, 1);
        input(0, 0, '\0', false, false, false);
    }
}
void create_show_transaction_panel(User _user){
    int n=create_pay_panel(_user);
    if(n==-1) return;
    vector<trans> transactions=getAllTrans(atoi(_user.bank_account));
    int h=4+transactions.size();
    int w=120;
    if(transactions.size()>0){
        create_raw_menu(3,120,1,1,true);
        create_raw_menu(h,w,1,3,false);
        add_text_to_raw_menu("   ID   |   From   |   To   |   Cost   |   MM/DD/YY   |   HH:MM   |                   Explanation                    ",2,2);

    for(int i=0;i<transactions.size();i++){
        add_text_to_raw_menu(to_string(transactions[i].trackingNumber)
        +"|"+((atoi(_user.bank_account)==transactions[i].dest)?"   You.   ":to_string(transactions[i].dest))
        +"|"+((atoi(_user.bank_account)==transactions[i].dest)?to_string(transactions[i].dest):"   You.   ")
        +"|"+to_string(transactions[i].cost)
        +"|   "+to_string(transactions[i].d.month)+"/"+to_string(transactions[i].d.day)+"/"+to_string(transactions[i].d.year)
        +"   |   "+to_string(transactions[i].d.hour)+":"+to_string(transactions[i].d.min)
        +"   |"+(string)transactions[i].exp,3,i+5);
    }
    gotoXY(1,transactions.size()+6);
    }else{
        clearIt();
        add_text_to_raw_menu("No Transaction Found.",1,1);
    }
    input(0,0,'\0',false, false, false);
}
void create_buy_ticket_panel(User _user) {
    while (true) {
        int items[2][2] = {{4, 2},{5, 9}};
        int h = 11;
        int w = 58;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("[#] Enter Origin City And Destination City.", 3, 2);
        add_text_to_raw_menu("Origin City : ", 3, 4);
        add_text_to_raw_menu("Destination City : ", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 9);
        int n = move_between_items(items, 2);
        if (n == 1) break;
        gotoXY(17, 4);
        string src = input(1, 8, '\0', true, false, false);
        gotoXY(22, 5);
        string dst = input(1, 8, '\0', true, false, false);
        create_show_trip_panel(atoi(src.c_str()), atoi(dst.c_str()),_user);
    }
}
void create_buy_ticket_panel() {
    while (true) {
        int items[2][2] = {{4, 2},
                           {5, 9}};
        int h = 11;
        int w = 58;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("[#] Enter Origin City And Destination City.", 3, 2);
        add_text_to_raw_menu("Origin City : ", 3, 4);
        add_text_to_raw_menu("Destination City : ", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 9);
        int n = move_between_items(items, 2);
        if (n == 1) break;
        gotoXY(17, 4);
        string src = input(1, 8, '\0', true, false, false);
        gotoXY(22, 5);
        string dst = input(1, 8, '\0', true, false, false);
        create_show_trip_panel(atoi(src.c_str()), atoi(dst.c_str()));
    }
}
//----------------------------------------------------------------------------------------
void create_delete_panel(User _user){
    int items[2][2] = {{4, 4},{4, 5}};
    int h = 8;
    int w = 39;
    create_raw_menu(h, w,1,1, true);
    add_text_to_raw_menu("Do You Want To Delete Your Account?", 3, 2);
    add_text_to_raw_menu("[#] Yes.", 3, 4);
    add_text_to_raw_menu("[#] No.", 3, 5);
    int i = move_between_items(items, 2);
    switch (i) {
        case 0:
            remove_user(_user);
            goto_intro_panel=true;
            break;
        case 1:
            break;
    }
}
void create_edit_panel(User _user){
    int items[2][2]={{4,2},{5,20}};
    int h = 22;
    int w = 58;
    create_raw_menu(h, w, 1, 1, true);
    while(true) {
        add_text_to_raw_menu("[#] Edit My Profile. ",3, 2);
        add_text_to_raw_menu("Username : "+(string)_user.user_name, 3, 4);
        add_text_to_raw_menu("Password : "+(string)_user.user_pass, 3, 6);
        add_text_to_raw_menu("First Name : "+(string)_user.fname, 3, 8);
        add_text_to_raw_menu("Last Name : "+(string)_user.lname, 3, 10);
        add_text_to_raw_menu("Bank Account : "+(string)_user.bank_account, 3, 12);
        add_text_to_raw_menu("Phone Number : "+(string)_user.phone_number, 3, 14);
        add_text_to_raw_menu("Reference Username : "+(string)_user.reference, 3, 16);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 18);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 20);
        int n=move_between_items(items,2);
        if(n==1) break;
        goto_intro_panel=true;
        User new_user={};
        int items2[6][2]={{14,6},{16,8},{15,10},{18,12},{18,14},{24,16}};
        int n2=move_between_items(items2,6);
        if(n2==0){
            for(int i=0;i<9;i++){
                printf(" ");
            }
            gotoXY(14,6);
            string user_pass=input(1,8,'*',true,true,true);
            new_user=create_new_user(_user.user_name,user_pass,_user.fname,_user.lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==1){
            for(int i=0;i<21;i++){
                printf(" ");
            }
            gotoXY(16,8);
            string fname=input(1,20,'\0',false,true,false);
            new_user=create_new_user(_user.user_name,_user.user_pass,fname,_user.lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==2){
            for(int i=0;i<21;i++){
                printf(" ");
            }
            gotoXY(15,10);
            string lname=input(1,20,'\0',false,true,false);
            new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==3){
            for(int i=0;i<11;i++){
                printf(" ");
            }
            gotoXY(18,12);
            string bank_account=input(1,10,'\0',true,false,false);
            new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==4){
            for(int i=0;i<12;i++){
                printf(" ");
            }
            gotoXY(18,14);
            string phone_number=input(11,11,'\0',true,false,false);
            new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,_user.bank_account,phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==5){
            for(int i=0;i<9;i++){
                printf(" ");
            }
            gotoXY(24,16);
            string reference=input(0,8,'\0',true,true,true);
            new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,_user.bank_account,_user.phone_number,reference);
            edit_user_profile(new_user);
        }
        _user=new_user;
    }
}
//----------------------------------------------------------------------------------------
void create_guest_register_panel(){
    int items[2][2]={{16,4},{5,12}};
    is_guset=true;
    int h = 14;
    int w = 58;
    create_raw_menu(h, w, 1, 1, true);
    add_text_to_raw_menu("Please Enter Your Information.", 3, 2);
    add_text_to_raw_menu("First Name : ", 3, 4);
    add_text_to_raw_menu("Last Name : ", 3, 6);
    add_text_to_raw_menu("Phone Number : ", 3, 8);
    for (int i = 2; i < w; i++) {
        add_text_to_raw_menu("-", i, 10);
    }
    add_text_to_raw_menu("[#] Cancel", 4, 12);
    int n=move_between_items(items,2);
    if(n==1){
        is_ticket_cancel=true;
        return;
    }
    gotoXY(16, 4);
    string fname=input(1,20,'\0',false,true,false);
    gotoXY(15, 6);
    string lname=input(1,20,'\0',false,true,false);
    gotoXY(18, 8);
    string phone_number=input(11,11,'\0',true,false,false);
    create_pay_panel();
    //TODO dorso kon injaro
}
//----------------------------------------------------------------------------------------
int create_pay_panel(User _user){
    while(true) {
        int items[2][2] = {{14, 5},
                           {5,  9}};
        is_guset = true;
        int h = 11;
        int w = 44;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("Bank Account : " + (string) _user.bank_account, 3, 3);
        add_text_to_raw_menu("Password : ", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Cancel", 4, 9);
        int n = move_between_items(items, 2);
        if (n == 1) {
            is_ticket_cancel = true;
            return -1;
        }
        gotoXY(14, 5);
        string bank_account_pass = input(1, 8, '*', true, true, true);
        int rem=remainder(atoi(_user.bank_account),atoi(bank_account_pass.c_str()));
        if(rem>=0) break;
        if(rem==-1) {
            create_raw_menu(3, 44, 1, 12, false);
            add_text_to_raw_menu("Your Password Is Wrong Please Try Again.",3,13);
            Sleep(1500);
        } else{
            create_raw_menu(4, 44, 1, 12, false);
            add_text_to_raw_menu("Your Bank Account Is Wrong Please",3,13);
            add_text_to_raw_menu("Edit Your Profile And Change It.",3,14);
            Sleep(3000);
        }


    }
    return 1;

}
int create_pay_panel() {
    while (true) {
        int items[2][2] = {{18, 3},{5,  9}};
        is_guset = true;
        int h = 11;
        int w = 49;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("Bank Account : ", 3, 3);
        add_text_to_raw_menu("Password : ", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Cancel", 4, 9);
        int n = move_between_items(items, 2);
        if (n == 1) {
            is_ticket_cancel = true;
            return -1;
        }
        gotoXY(18, 3);
        string bank_account = input(1, 10, '\0', true, false, false);
        gotoXY(14, 5);
        string bank_account_pass = input(1, 8, '*', true, true, true);
        int rem = remainder(atoi(bank_account.c_str()), atoi(bank_account_pass.c_str()));
        if (rem >= 0) break;
        if (rem == -1) {
            create_raw_menu(3, 49, 1, 12, false);
            add_text_to_raw_menu("Your Password Is Wrong Please Try Again.", 3, 13);
            Sleep(1500);
        } else {
            create_raw_menu(3, 49, 1, 12, false);
            add_text_to_raw_menu("Your Bank Account Is Wrong Please Try Again.", 3, 13);
            Sleep(1500);
        }
    }
    //TODO kam kardan pool az hesab
    return 1;
}
//----------------------------------------------------------------------------------------
int create_choose_seat_panel(){
    return 0;
}
void create_show_trip_panel(int src,int dst,User _user){
    vector<Trip> trips=getTrip(src,dst);
    int h = 4+trips.size();
    int w = 58;
    if(trips.size()>0) {
        create_raw_menu(h, w, 1, 2, true);
        int **items = (int **) malloc(sizeof(int *) * trips.size());
        for (int i = 0; i < trips.size(); i++)
            items[i] = (int *) malloc(sizeof(int) * 2);
        add_text_to_raw_menu("From : " + to_string(src) + "     To : " + to_string(dst), 1, 1);
        for (int i = 0; i < trips.size(); i++) {
            add_text_to_raw_menu(
                    "[#] Date : " + to_string(trips[i].date.month) + "/" + to_string(trips[i].date.day) + "/" +
                    to_string(trips[i].date.year)
                    + "|Driver : " + trips[i].drvr.fname + " " + trips[i].drvr.lastname
                    + "|Estimate Time : " + to_string(trips[i].estimate) + " Min"
                    + "|Cost : " + to_string(trips[i].cost), 3, i + 3);
            items[i][0]=5;
            items[i][1]=i+3;
        }
        int n=move_between_items(items,trips.size());
    }else{
        add_text_to_raw_menu("No Trips Found By Your Filter.",1,1);
        input(0,0,'\0',false,false,false);
    }
    //TODO buy ticket from trips[i] and _user and call create_pay_panel(User)

}
void create_show_trip_panel(int src,int dst){
    vector<Trip> trips=getTrip(src,dst);
    int h = 4+trips.size();
    int w = 58;
    if(trips.size()>0) {
        create_raw_menu(h, w, 1, 2, true);
        int **items = (int **) malloc(sizeof(int *) * trips.size());
        for (int i = 0; i < trips.size(); i++)
            items[i] = (int *) malloc(sizeof(int) * 2);
        add_text_to_raw_menu("From : " + to_string(src) + "     To : " + to_string(dst), 1, 1);
        for (int i = 0; i < trips.size(); i++) {
            add_text_to_raw_menu(
                    "[#] Date : " + to_string(trips[i].date.month) + "/" + to_string(trips[i].date.day) + "/" +
                    to_string(trips[i].date.year)
                    + "|Driver : " + trips[i].drvr.fname + " " + trips[i].drvr.lastname
                    + "|Estimate Time : " + to_string(trips[i].estimate) + " Min"
                    + "|Cost : " + to_string(trips[i].cost), 3, i + 3);
            items[i][0]=5;
            items[i][1]=i+3;
        }
        int n=move_between_items(items,trips.size());
    }else{
        add_text_to_raw_menu("No Trips Found By Your Filter.",1,1);
        input(0,0,'\0',false,false,false);
    }
    //TODO buy ticket from trips[i] AND call create_guest_register_panel()
    //TODO age pool kam shod seda zandan add_ticket();
}