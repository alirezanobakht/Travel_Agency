//
// Created by Jarvis on 1/17/2019.
//

#include "tickets.h"
#include "../someThingNecessary.h"

int getTicketID(){
    FILE * f= fopen("Users/tics/ticketId.dat","rb");
    if(f==NULL){
        fclose(f);
        FILE * fp= fopen("Users/tics/ticketId.dat","wb");
        int x=1000;
        fwrite(&x, sizeof(int),1,fp);
        fclose(fp);
        return x;
    }
    else{
        int x;
        fread(&x, sizeof(int),1,f);
        fclose(f);
        x++;
        FILE * fp=fopen("Users/tics/ticketId.dat","wb");
        fwrite(&x, sizeof(int),1,fp);
        fclose(fp);
        return x;
    }
}

vector<Ticket> getTicketByTrip(int tripId){
    vector<Ticket> rt;
    vector<Ticket> tickets=return_tickets();
    for(int i=0;i<tickets.size();i++){
        if(tickets[i].ticket_trip.ID==tripId){
            rt.push_back(tickets[i]);
        }
    }
    return rt;
}

void save_def_file(Ticket _ticket){
    FILE* fp_d=fopen("Users/tics/default.def","ab");
    fwrite(&(_ticket.id),sizeof(int),1,fp_d);
    fclose(fp_d);
}
void save_ticket_file(Ticket _ticket){
    string file_addr="Users/tics/"+to_string(_ticket.id)+".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"wb");
    fwrite(&_ticket,sizeof(Ticket),1,fp_t);
    fclose(fp_t);
}
void save_ticks_def_file(User _user, Ticket _ticket){
    string file_addr="Users/usrs/"+(string)_user.user_name+"/ticks.def";
    FILE* fp_d=fopen(file_addr.c_str(),"ab");
    fwrite(&(_ticket.id),sizeof(int),1,fp_d);
    fclose(fp_d);
}


vector<Ticket> return_tickets(){
    vector<Ticket> tickets;
    FILE* fp_d=fopen("Users/tics/default.def","rb");
    if(fp_d!=NULL){
        while (true){
            int id;
            fread(&id,sizeof(int),1,fp_d);
            if(feof(fp_d))
                break;
            string file_addr="Users/tics/"+to_string(id)+".tic";
            Ticket temp={};
            FILE* fp_t=fopen(file_addr.c_str(),"rb");
            fread(&temp, sizeof(Ticket),1,fp_t);
            fclose(fp_t);
            tickets.push_back(temp);
        }
        fclose(fp_d);
    }
    return tickets;
}
Ticket return_ticket(int id){
    string file_addr="Users/tics/"+to_string(id) +".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"rb");
    Ticket temp={};
    if(fp_t!=NULL) {
        fread(&temp, sizeof(Ticket),1,fp_t);
        fclose(fp_t);
    }
    return temp;
}
vector<Ticket> return_user_tickets(char user_name[9]){
    vector<Ticket> tickets;
    string file_addr="Users/usrs/"+(string)user_name+"/ticks.def";
    FILE* fp_d=fopen(file_addr.c_str(),"rb");
    if(fp_d!=NULL){
        while (true){
            int id;
            fread(&id,sizeof(int),1,fp_d);
            if(feof(fp_d))
                break;
            file_addr="Users/tics/"+to_string(id)+".tic";
            Ticket temp={};
            FILE* fp_t=fopen(file_addr.c_str(),"rb");
            fread(&temp, sizeof(Ticket),1,fp_t);
            fclose(fp_t);
            tickets.push_back(temp);
        }
        fclose(fp_d);
    }
    return tickets;
}

/*
 * finds ticket in tics directory
 * returns the place of the ticket in the vector.
 */
long int find_ticket_in_tickets(Ticket _ticket){
    vector<Ticket> tickets= return_tickets();
    for(long int i=0;i<tickets.size();i++){
        if (_ticket.id == tickets[i].id)
            return i;
    }
    return -1;
}
/*
 * returns place of the ticket in the user directory tickets.
 */
long int find_ticket_in_tickets(int id,char user_name[9]){
    vector<Ticket> tickets= return_user_tickets(user_name);
    for(long int i=0;i<tickets.size();i++){
        if (id == tickets[i].id)
            return i;
    }
    return -1;
}
/*
 * you can find if a ticket exists or not
 * returns 1 : if the ticket was found.
 * returns -1 : if there are no tickets match for the given ticket.
 */
long int find_ticket_in_file(int id){
    string file_addr="Users/tics/"+to_string(id)+".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"rb");
    if(fp_t==NULL)
        return -1;
    fclose(fp_t);
    return 1;
}
/*
 * Adds a new ticket
 * used for buying tickets.
 * FOR GUESTS!!!!!!!!!!
 */
int add_ticket(Ticket _ticket, int cost,int bank_account){
    if(find_ticket_in_file(_ticket.id)==-1) {
        save_ticket_file(_ticket);
        save_def_file(_ticket);
        vector<account> acc = allAccounts();
        for (int i = 0; i < acc.size(); i++) {
            if (bank_account == acc[i].ID) {
                if (acc[i].remaind - cost >= 0) {
                    string Exp = "Buying Ticket with ID :" + to_string(_ticket.id);
                    char a[80];
                    memcpy(a,Exp.c_str(),80);
                    moveMoney(acc[i].ID,acc[i].password,acc[0].ID, cost/10, a);
                    string exp = "Having a Trip with ID :" + to_string(_ticket.id);
                    char b[80];
                    memcpy(b,exp.c_str(),80);
                    moveMoney(acc[i].ID,acc[i].password,_ticket.ticket_trip.drvr.bankaccount, (9*cost)/10, b);
                    return 1;
                }
                return -1;
            }
        }
    }
    return -2;
}
/*
 * Adds a new ticket
 * used for buying tickets.
 * FOR USERS!!!!!!!!!!
 */
int add_ticket(Ticket _ticket,User _user, int cost){
    if(find_ticket_in_file(_ticket.id)==-1) {
        save_ticket_file(_ticket);
        save_def_file(_ticket);
        save_ticks_def_file(_user, _ticket);
        vector<account> acc = allAccounts();
        for (int i = 0; i < acc.size(); i++) {
            if (atoi(_user.bank_account) == acc[i].ID) {
                if (acc[i].remaind - cost >= 0) {
                    string Exp = "Buying Ticket with ID :" + to_string(_ticket.id);
                    char a[80];
                    memcpy(a,Exp.c_str(),80);
                    moveMoney(acc[i].ID,acc[i].password,acc[0].ID, cost/10, a);
                    string exp = "Having a Trip with ID :" + to_string(_ticket.id);
                    char b[80];
                    memcpy(b,exp.c_str(),80);
                    moveMoney(acc[i].ID,acc[i].password,_ticket.ticket_trip.drvr.bankaccount, (9*cost)/10, b);
                    return 1;
                }
                return -1;
            }
        }
    }
    return -2;
}
int remove_ticket(int id,int bank_account){
    if(find_ticket_in_file(id)!=-1) {
        vector<Ticket> tickets= return_tickets();
        string file_addr="Users/tics/"+to_string(id)+".tic";
        ticket _ticket={};
        _ticket.id=id;
        long int point=find_ticket_in_tickets(_ticket);
        tickets.erase(tickets.begin()+point);
        remove("Users/tics/default.def");
        remove(file_addr.c_str());
        for(int i=0;i<tickets.size();i++){
            save_def_file(tickets[i]);
        }
        int pwd;
        vector<account> accs=allAccounts();
        for(int i=0;i<accs.size();i++){
            if(accs[i].ID==bank_account){
                pwd=accs[i].password;
            }
        }

        vector<Ticket> tks=return_tickets();
        Ticket tk={};
        tk.id=id;
        int p=find_ticket_in_tickets(tk);

        string  str="You have Cancelled a ticket with ID : "+to_string(id);
        char cr[50];
        memcpy(cr,str.c_str(),50);
        int pr=int(tks[p].ticket_trip.cost*penaltyPrice(tks[p]));

        moveMoney(bank_account,pwd,accs[0].ID,pr*9/10,cr);
        moveMoney(bank_account,pwd,tks[p].ticket_trip.drvr.bankaccount,pr/10,cr);
        return 1;
    }
    return -1;
}
int remove_ticket(int id,User _user){
    if(find_ticket_in_file(id)!=-1) {
        string file_addr="Users/usrs/"+(string)_user.user_name+"/ticks.def";
        vector<Ticket> tickets= return_user_tickets(_user.user_name);
        long int point=find_ticket_in_tickets(id,_user.user_name);
        if(point!=-1){
            tickets.erase(tickets.begin()+point);
            remove(file_addr.c_str());
        }
        for(int i=0;i<tickets.size();i++){
            save_ticks_def_file(_user,tickets[i]);
        }
        vector<Ticket> tickets2= return_tickets();
        string file_addr2="Users/tics/"+to_string(id)+".tic";
        ticket _ticket={};
        _ticket.id=id;
        long int point2=find_ticket_in_tickets(_ticket);
        tickets2.erase(tickets2.begin()+point2);
        remove("Users/tics/default.def");
        remove(file_addr2.c_str());
        for(int i=0;i<tickets2.size();i++){
            save_def_file(tickets2[i]);
        }
        int pwd;
        vector<account> accs=allAccounts();
        for(int i=0;i<accs.size();i++){
            if(accs[i].ID==atoi(_user.bank_account)){
                pwd=accs[i].password;
            }
        }

        vector<Ticket> tks=return_tickets();
        Ticket tk={};
        tk.id=id;
        int p=find_ticket_in_tickets(tk);

        string  str="You have Cancelled a ticket with ID : "+to_string(id);
        char cr[50];
        memcpy(cr,str.c_str(),50);
        int pr=int(tks[p].ticket_trip.cost*penaltyPrice(tks[p]));

        moveMoney(atoi(_user.bank_account),pwd,accs[0].ID,pr*9/10,cr);
        moveMoney(atoi(_user.bank_account),pwd,tks[p].ticket_trip.drvr.bankaccount,pr/10,cr);
        return 1;
    }
    return -1;
}

double penaltyPrice(Ticket _ticket){
    myDate Now = nowTime();
    if (_ticket.ticket_trip.date.year - Now.year >= 0 && _ticket.ticket_trip.date.month - Now.month >= 0 && _ticket.ticket_trip.date.day - Now.day > 0 ){
        return 0.9;
    } else if (_ticket.ticket_trip.date.year - Now.year == 0 && _ticket.ticket_trip.date.month - Now.month == 0 && _ticket.ticket_trip.date.day - Now.day == 0 ){
        if (_ticket.ticket_trip.date.hour - Now.hour > 1)
            return 0.9;
    } else {
        return 0.5;
    }
}
//-------------------------------------------------------------------------------------------