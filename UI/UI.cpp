//
// Created by Jarvis on 1/16/2019.
//

#include "UI.h"
#include "../myAll.h"
void fullScreen(){
    HWND hwin=GetConsoleWindow();
    AnimateWindow(hwin,1000,AW_SLIDE);

    HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font;
    font.cbSize= sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(con,false,&font);
    font.dwFontSize.X=22;
    font.dwFontSize.Y=22;
    font.FontWeight=700;
    SetCurrentConsoleFontEx(con,false,&font);

    ShowWindow(hwin,SW_MAXIMIZE);

}

/*void colour(int front,int back){
    string a,b,c;
    if(front<=9){
        a=to_string(front);
    }
    else{
        switch (front){
            case 10:
                a="A";
                break;
            case 11:
                a="B";
                break;
            case 12:
                a="C";
                break;
            case 13:

        }
    }
}*/


void fontColor(int x){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

bool setTitle(char a[20]){
    SetConsoleTitle(a);
}

COORD getWindowSize() {
    COORD c;
    CONSOLE_SCREEN_BUFFER_INFO x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
    c.X=x.srWindow.Right-x.srWindow.Left+1;
    c.Y=x.srWindow.Bottom-x.srWindow.Top+1;
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

void disableCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=100;
    cursor.bVisible=false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}

void enableCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=20;
    cursor.bVisible=true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor);
}