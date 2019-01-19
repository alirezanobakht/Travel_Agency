//
// Created by Jarvis on 1/18/2019.
//

#include "ahmadUI.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include "../AhmadDriver.h"
#include "../../someThingNecessary.h"

//-----------------------------------------------Necessary Functions----------------------------------------------
/*
void fullScreen(){
    HWND hwin=GetConsoleWindow();
    AnimateWindow(hwin,1000,AW_SLIDE);
    ShowWindow(hwin,SW_MAXIMIZE);

}



void fontColor(int x){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void setTitle(char a[20]){
    SetConsoleTitle(a);
}

COORD getWindowSize() {
    COORD c;
    CONSOLE_SCREEN_BUFFER_INFO x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
    c.X=x.srWindow.Right-x.srWindow.Left + 1;
    c.Y=x.srWindow.Bottom-x.srWindow.Top + 1;
    return c;
}

void clrscr(){
    system("@cls||clear");
}

void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
*/
//-----------------------------------------------------------------------------------

void loginPage(){
    setTitle("Travel Agency");
    string stringUsername="";
    string stringPassword="";
    fontColor(128);
    COORD c = getWindowSize();
    c.X /=2;
    c.Y /=2;
    cout<<" ";
    clrscr();
    int x = c.X;
    int y = c.Y;
    gotoxy(x-3,y);
    cout<<"Username : \n";
    gotoxy (x-3,y+1);
    cout<<"Password :";
    gotoxy(x-10,y+4);
    cout<<"Default password = 1";
    gotoxy(x-3+11,y);
    while(true){
        char curr = getch();
        if(curr == 13){
            break;
        }else if(curr == '\b'){
            if (stringUsername.length() == 0)
                continue;
            stringUsername.pop_back();
            clrscr();
            gotoxy(x-3,y);
            cout<<"Username : ";
            for (int i=0; i < stringUsername.length(); i++)
                cout<<stringUsername[i];
            gotoxy(x-3,y+1);
            cout<<"Password : ";
            gotoxy(x-3+11+stringUsername.length(),y);
        }else{
            stringUsername += curr;
            cout<<curr;
        }
    }
    gotoxy(x+8,y+1);
    while (true){
        char curr = getch();
        if(curr == 13){
            break;
        } else if (curr == '\b'){
            if (stringPassword.length() == 0)
                continue;
            stringPassword.pop_back();
            clrscr();
            gotoxy(x-3,y);
            cout<<"Username : " + stringUsername;
            gotoxy(x-3,y+1);
            cout<<"Password : ";
            for (int i=0; i < stringPassword.length(); i++)
                cout<<"*";
        }else{
            stringPassword += curr;
            cout<<"*";
        }
    }
    int username = stringToInt(stringUsername);
    char password[50]={};
    for (int i=0; i < stringPassword.length(); i++){
        password[i] = stringPassword[i];
    }
    string fileAddress = "Drivers/usrs/" + stringUsername + ".drvr";
    FILE* fp_1 = fopen(fileAddress.c_str(),"rb");
    if (fp_1 == NULL){
        clrscr();
        gotoxy(x-7,y);
        cout<<"User not found try again.";
        Sleep(2000);
        loginPage();
    }
    Driver temp_driver = {};
    fread(&temp_driver, sizeof(Driver),1,fp_1);
    fclose(fp_1);
    if (VerifyLoginInfo(username, password) == 1 && strcmp("1", password) == 0 ){
        clrscr();
        bool check = false;
        while (!check) {
            clrscr();
            char newPassword[50] = {};
            char newPassword2[50] = {};
            gotoxy(x-11,y-1);
            cout << "Enter your password : ";
            gotoxy(x-11,y+1);
            cout << "Verify your Password :";
            gotoxy(x+11,y-1);
            cin >> newPassword;
            gotoxy(x+11,y+1);
            cin >> newPassword2;
            if (strcmp(newPassword, newPassword2) == 0) {
                check = true;
                clrscr();
                for (int i=0; newPassword[i] != '\0'; i++){
                    temp_driver.password[i] = newPassword[i];
                }
                FILE* fp_d = fopen(fileAddress.c_str(),"wb");
                fwrite(&temp_driver, sizeof(Driver), 1, fp_d);
                fclose(fp_d);
                clrscr();
                gotoxy(x-15,y);
                cout << "Password changed successfully";
                gotoxy(x-5,y+1);
                cout << "Loading";
                Sleep(2000);
                driversLoginPage(username);
            } else {
                clrscr();
                gotoxy(x-36,y);
                cout << "\aThe Passwords you entered does not match please try again!";
                loginPage();
            }
        }
    }else if(VerifyLoginInfo(username,password) == 1){
        clrscr();
        gotoxy(x-10,y);
        Driver temp = {};
        string fileAddress = "Drivers/usrs/" + to_string(username) +".drvr";
        FILE* fp = fopen(fileAddress.c_str(),"rb");
        fread(&temp, sizeof(Driver), 1, fp);
        fclose(fp);
        fontColor(128);
        printf("Welcome %s %s",temp.fname,temp.lastname);
        fontColor(112);
        Sleep(2000);
        driversLoginPage(username);
    } else if (VerifyLoginInfo(username,password) == -1){
        clrscr();
        gotoxy(x-21,y);
        cout<<"\aThe username or password entered is wrong.\n";
        Sleep(1000);
        loginPage();
    }

}

void driversLoginPage(int username){
    fontColor(112);
    cout<<" ";
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-4,y-14);
    cout<<"Welcome";
    gotoxy(x-8,y-2);
    cout<<"List of all trips";
    gotoxy(x-6,y-1);
    cout<<"Define a trip";
    gotoxy(x-6,y);
    cout<<"Edit profile";
    int color = 0;

    // UpArrow  = 72;
    // DownArrow = 80;
    while (true){
        gotoxy(3,y+13);
        fontColor(125);
        cout<<"[Ctrl] + F4 : Logout";
        gotoxy(x-8,y-2);
        if (color == 0){
            fontColor(124);
        } else{
            fontColor(112);
        }
        cout<<"List of all trips";
        if (color == 1){
            fontColor(124);
        }else{
            fontColor(112);
        }
        gotoxy(x-6,y-1);
        cout<<"Define a trip";
        if (color == 2){
            fontColor(124);
        }else {
            fontColor(112);
        }
        gotoxy(x-6,y);
        cout<<"Edit profile";
        char dokme = _getch();
        if (dokme == -32) {
            dokme = _getch();
            if (dokme == 72) {
                color--;
                if (color == -1)
                    color = 2;
            } else if (dokme == 80) {
                color++;
                if (color == 3)
                    color =0;
            }

        }else if (dokme == 13){
            if (color == 0){
                listOfTripsDriver(username);
            }
            if (color == 1){
                defineATrip(username);
            }
            if (color == 2){
                editProfilePage(username);
            }
        }
        else if (dokme == 0){
            dokme = _getch();
            if (dokme == 97)
                break;
        }
    }
    loginPage();
}

void listOfTripsDriver(int username){
    clrscr();
    while (true){

    }
}

void defineATrip(int username){
    clrscr();
    /*while (){

    }
     */
}

void editProfilePage(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(3,y+13);
    fontColor(125);
    cout<<"[Ctrl] + F4 : Home";
    gotoxy(x-6,y-10);
    fontColor(124);
    cout<<"Edit Profile";
    fontColor(112);
    gotoxy(x-4,y);
    cout<<"Password";
    gotoxy(x-4,y+1);
    cout<<"Firstname";
    gotoxy(x-4,y+2);
    cout<<"Lastname";
    gotoxy(x-4,y+3);
    cout<<"Phonenumber";
    gotoxy(x-7,y+4);
    cout<<"Bank Account";
    gotoxy(x-7,y+5);
    cout<<"Delete Profile";

    int color = 0;
    while (true){
        char temp = _getch();
        if (temp == -32){
            temp = _getch();
            if (temp == 72){
                if (color == 0){
                    color = 5;

                }else {
                    color--;
                }
            }else if (temp == 80){
                if (color == 5){
                    color = 0;
                }else {
                    color++;
                }
            }
        }else if (temp == 13){
            if (color == 0){
                EditPassword(username);
            } else if (color == 1){
                EditFname(username);
            } else if (color == 2){
                EditLname(username);
            } else if (color == 3){
                EditPhonenumber(username);
            } else if (color == 4){
                EditBankAccount(username);
            } else if (color == 5){
                DeleteDriverAccount(username);
            }
        }else if (temp == 0){
            temp = _getch();
            if (temp == 97){
                break;
            }
        }
        if (color == 0){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(124);
            gotoxy(x-4,y);
            cout<<"Password";
            fontColor(112);
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
        } else if (color == 1){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(112);
            gotoxy(x-4,y);
            cout<<"Password";
            fontColor(124);
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            fontColor(112);
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
        }else if (color ==2){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(112);
            gotoxy(x-4,y);
            cout<<"Password";
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            fontColor(124);
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            fontColor(112);
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
        }else if (color == 3){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(112);
            gotoxy(x-4,y);
            cout<<"Password";
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            fontColor(124);
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            fontColor(112);
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
        }else if (color == 4){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(112);
            gotoxy(x-4,y);
            cout<<"Password";
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            fontColor(124);
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            fontColor(112);
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
        }else if (color == 5){
            gotoxy(3,y+13);
            fontColor(125);
            cout<<"[Ctrl] + F4 : Home";
            gotoxy(x-6,y-10);
            fontColor(125);
            cout<<"Edit Profile";
            fontColor(112);
            gotoxy(x-4,y);
            cout<<"Password";
            gotoxy(x-4,y+1);
            cout<<"Firstname";
            gotoxy(x-4,y+2);
            cout<<"Lastname";
            gotoxy(x-4,y+3);
            cout<<"Phonenumber";
            gotoxy(x-7,y+4);
            cout<<"Bank Account";
            fontColor(124);
            gotoxy(x-7,y+5);
            cout<<"Delete Profile";
            fontColor(112);
        }
    }
    driversLoginPage(username);
}

int stringToInt(string input){
    int x = 0;
    for (int i=0; i < input.length(); i++){
        int temp = (int)input[i] - (int)'0';
        x = (x*10) + temp;
    }
    return x;
}

void EditPassword(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    fontColor(112);
    gotoxy(x-13,y);
    cout<<"Enter your new password : ";
    gotoxy(x-12,y+1);
    cout<<"Verify your password : ";
    gotoxy(x + 13 , y);
    char password[50]={};
    char password2[50] = {};
    cin>>password;
    gotoxy(x + 11 , y+1);
    cin>>password2;
    if (strcmp(password,password2) == 0){
        Driver temp = {};
        string fileAddress = "Drivers/usrs/"+ to_string(username) +".drvr";
        FILE* fp = fopen(fileAddress.c_str(),"rb");
        fread(&temp, sizeof(Driver), 1, fp);
        fclose(fp);
        FILE* fp_d = fopen(fileAddress.c_str(),"wb");
        strcpy(temp.password,password);
        fwrite(&temp, sizeof(Driver), 1, fp_d);
        fclose(fp_d);
        clrscr();
        gotoxy(x-14,y);
        fontColor(124);
        cout<<"Password changed successfully";
        fontColor(112);
        Sleep(1000);
        editProfilePage(username);
    }else{
        gotoxy(x-20,y);
        fontColor(124);
        cout<<"Passwords do not match please try again!";
        Sleep(700);
        fontColor(112);
        EditPassword(username);
    }
}
void EditFname(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-9,y);
    cout<<"Enter firstname : ";
    gotoxy(x+9,y);
    char newName[50]={};
    cin>>newName;
    Driver temp={};
    string fileAddress = "Drivers/usrs/" + to_string(username) + ".drvr";
    FILE* fp = fopen(fileAddress.c_str(),"rb");
    fread(&temp, sizeof(Driver), 1, fp);
    fclose(fp);
    strcpy(temp.fname, newName);
    FILE* fp_d = fopen(fileAddress.c_str(),"wb");
    fwrite(&temp, sizeof(Driver), 1, fp_d);
    fclose(fp_d);
    editProfilePage(username);

}
void EditLname(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-9,y);
    cout<<"Enter Lastname : ";
    gotoxy(x+9,y);
    char newName[50]={};
    cin>>newName;
    Driver temp={};
    string fileAddress = "Drivers/usrs/" + to_string(username) + ".drvr";
    FILE* fp = fopen(fileAddress.c_str(),"rb");
    fread(&temp, sizeof(Driver), 1, fp);
    fclose(fp);
    strcpy(temp.lastname, newName);
    FILE* fp_d = fopen(fileAddress.c_str(),"wb");
    fwrite(&temp, sizeof(Driver), 1, fp_d);
    fclose(fp_d);
    editProfilePage(username);

}
void EditPhonenumber(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-9,y);
    cout<<"Enter new number : ";
    gotoxy(x+9,y);
    char newPhonenumber[12] = {};
    cin>>newPhonenumber;
    Driver temp={};
    string fileAddress = "Drivers/usrs/" + to_string(username) + ".drvr";
    FILE* fp = fopen(fileAddress.c_str(),"rb");
    fread(&temp, sizeof(Driver), 1, fp);
    fclose(fp);
    strcpy(temp.phonenumber,newPhonenumber);
    FILE* fp_d = fopen(fileAddress.c_str(),"wb");
    fwrite(&temp, sizeof(Driver), 1, fp_d);
    fclose(fp_d);
}
void DeleteDriverAccount(int username){
    clrscr();
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    fontColor(112);
    gotoxy(x-25,y-13);
    cout<<"Are you sure that you want to delete your account?";
    fontColor(124);
    gotoxy(x-2,y);
    cout<<"Yes";
    fontColor(112);
    gotoxy(x-1,y+1);
    cout<<"No";
    int color = 0;
    while (true){
        char temp = _getch();
        if (temp == -32) {
            temp = _getch();
            if (temp == 72) {
                if (color == 0)
                    color = 1;
                else
                    color = 0;
            }else if (temp == 80){
                if (color == 0)
                    color = 1;
                else
                    color = 0;
            }
        }else if (temp == 13) {
            if (color == 1)
                break;
            else {
                DeleteDriver(username);
                loginPage();
            }
        }
        if (color == 1){
            fontColor(112);
            gotoxy(x-2,y);
            cout<<"Yes";
            fontColor(124);
            gotoxy(x-1,y+1);
            cout<<"No";
            fontColor(112);
        }else if (color == 0){
            fontColor(124);
            gotoxy(x-2,y);
            cout<<"Yes";
            fontColor(112);
            gotoxy(x-1,y+1);
            cout<<"No";
        }

    }
    editProfilePage(username);
}
void EditBankAccount(int username){
    clrscr();
    fontColor(112);
    COORD c = getWindowSize();
    int x = c.X/2;
    int y = c.Y/2;
    gotoxy(x-16,y);
    cout<<"Enter new bank account number : ";
    int newBankAccountNumber;
    cin>>newBankAccountNumber;
    string fileAddress = "Drivers/usrs/"+ to_string(username) +".drvr";
    FILE* fp = fopen(fileAddress.c_str(),"rb");
    Driver temp = {};
    fread(&temp, sizeof(Driver), 1, fp);
    fclose(fp);
    FILE* fp_d = fopen(fileAddress.c_str(),"wb");
    temp.bankaccount = newBankAccountNumber;
    fwrite(&temp, sizeof(Driver), 1, fp_d);
    fclose(fp_d);
    clrscr();
    gotoxy(x-21,y);
    fontColor(124);
    cout<<"Bank account number changed successfully!";
    Sleep(1500);
    editProfilePage(username);
}