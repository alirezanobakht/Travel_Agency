//
// Created by Jarvis on 12/30/2018.
//

#ifndef TRAVEL_AGENCY_SOMETHINGNECESSARY_H
#define TRAVEL_AGENCY_SOMETHINGNECESSARY_H
//Clear Screen;
void clrscr();

//Date structure:
typedef struct myDate{
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
}myDate;


//Return Now time:
myDate nowTime();

/*
The different color codes are

0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/
void fontColor(int x=15);


bool setTitle(char a[20]);
#endif //TRAVEL_AGENCY_SOMETHINGNECESSARY_H
