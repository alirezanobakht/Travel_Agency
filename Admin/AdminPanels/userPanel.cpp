//
// Created by Jarvis on 12/30/2018.
//

#include "../../Users/users.h"
//Header
#include "userPanel.h"
//Necessary Includes:
#include "../../UI/UI.h"
#include "../adminlogged.h"


//necessary:




void usersPanel(){
    vector<User> us=get_users();
    fontColor(128);
    cout<<"asd";
    clrscr();


    int x=getWindowSize().X;
    int y=getWindowSize().Y;
    fontColor(141);
    gotoxy(5,y-2);
    cout<<"[esc]: Back";
    gotoxy(x-23,y-2);
    cout<<"[alt] + [f4]: Exit";

    gotoxy(0,0);
    fontColor(128);
    cout<<endl;
    cout<<"   The Users are shown as below form:"<<endl;
    cout<<"   Username  |  First Name  |  Last Name  |  Phone Number  |  Bank Account"<<endl;
    cout<<endl;
    for(int i=0;i<us.size();i++){
        if(i%2==0){
            fontColor(143);
        }
        else{
            fontColor(135);
        }
        cout<<"   "<<us[i].user_name<<"  |  "<<us[i].fname<<"  |  "<<us[i].lname<<"  |  "<<us[i].phone_number<<"  |  "<<us[i].bank_account<<endl;
    }

    while(1){
        char c=getch();
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