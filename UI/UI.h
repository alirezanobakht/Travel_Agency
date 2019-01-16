//
// Created by Jarvis on 1/16/2019.
//

#ifndef TRAVEL_AGENCY_UI_H
#define TRAVEL_AGENCY_UI_H

#include "../myAll.h"

void gotoxy(int x,int y);

void disableCursor();

void enableCursor();

void fullScreen();

void fontColor(int x=0);

bool setTitle(char a[20]);

void clrscr();


COORD getWindowSize();

#endif //TRAVEL_AGENCY_UI_H
