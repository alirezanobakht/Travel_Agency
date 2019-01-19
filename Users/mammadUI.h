//
// Created by Jarvis on 1/17/2019.
//

#ifndef TRAVEL_AGENCY_MAMMADUI_H
#define TRAVEL_AGENCY_MAMMADUI_H

#include <string>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
void clearIt();
void full_screen();
COORD get_window_size();
void font_color(int x);
void gotoXY(int x ,int y);
int move_between_items(int items[][2],int l);
int move_between_items(int **items,int l);
void create_raw_menu(int height,int width,int startX,int startY,bool clear_screen);
void create_raw_menu(int height,int width,int startX,int startY,bool clear_screen,long speed);
void add_text_to_raw_menu(string text,int startX,int startY);
void clear_panel(int height,int width,int startX,int startY);
string input(int min_char,int max_char,char output_char,bool can_num,bool can_word,bool can_char);

#endif //TRAVEL_AGENCY_MAMMADUI_H
