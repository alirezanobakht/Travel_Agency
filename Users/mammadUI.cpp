//
// Created by Jarvis on 1/17/2019.
//

#include "mammadUI.h"

void clearIt(){
    system("@cls");
}
void full_screen(){
    HWND hwin=GetConsoleWindow();
    AnimateWindow(hwin,1000,AW_SLIDE);

    HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font;
    font.cbSize= sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(con,false,&font);
    font.dwFontSize.X=22;
    font.dwFontSize.Y=22;
    font.FontWeight=500;
    SetCurrentConsoleFontEx(con,false,&font);

    ShowWindow(hwin,SW_MAXIMIZE);

}
void font_color(int x){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
COORD get_window_size() {
    COORD c;
    CONSOLE_SCREEN_BUFFER_INFO x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
    c.X=x.srWindow.Right-x.srWindow.Left+1;
    c.Y=x.srWindow.Bottom-x.srWindow.Top+1;
    return c;
}
void gotoXY(int x ,int y){
    COORD pos = {(short)x, (short)y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
int move_between_items(int items[][2],int l){
    gotoXY(items[0][0], items[0][1]);
    int n=0;
    int i = 0;
    while (n!=13) {
        n =_getch();
        if(n==-32)n=_getch();
        if (n == 80) {
            i += 1;
            if (i == l) i = 0;
        }
        if (n == 72) {
            i -= 1;
            if (i == -1) i = l - 1;
        }
        gotoXY(items[i][0], items[i][1]);
    }
    return i;
}
int move_between_items(int **items,int l){
    gotoXY(items[0][0], items[0][1]);
    int n=0;
    int i = 0;
    while (n!=13) {
        n =_getch();
        if(n==-32)n=_getch();
        if (n == 80) {
            i += 1;
            if (i == l) i = 0;
        }
        if (n == 72) {
            i -= 1;
            if (i == -1) i = l - 1;
        }
        gotoXY(items[i][0], items[i][1]);
    }
    return i;
}
void create_raw_menu(int height,int width,int startX ,int startY,bool clear_screen){
    if(clear_screen)clearIt();
    for(int i=1;i<=height;i++){
        gotoXY(startX,i+startY-1);
        printf("*");
        gotoXY(width+startX-1,i+startY-1);
        printf("*");
        Sleep(10);

    }
    for(int i=1;i<=width;i++){
        gotoXY(i+startX-1,startY);
        printf("*");
        gotoXY(i+startX-1,height+startY-1);
        printf("*");
        Sleep(10);
    }
    gotoXY(1,height+1);
}
void create_raw_menu(int height,int width,int startX ,int startY,bool clear_screen,long speed){
    if(clear_screen)clearIt();
    for(int i=1;i<=height;i++){
        gotoXY(startX,i+startY-1);
        printf("*");
        gotoXY(width+startX-1,i+startY-1);
        printf("*");
        Sleep(speed);

    }
    for(int i=1;i<=width;i++){
        gotoXY(i+startX-1,startY);
        printf("*");
        gotoXY(i+startX-1,height+startY-1);
        printf("*");
        Sleep(speed);
    }
    gotoXY(1,height+1);

}
void add_text_to_raw_menu(string text,int startX,int startY){
    gotoXY(startX,startY);
    printf("%s",text.c_str());
}
void clear_panel(int height,int width,int startX,int startY){
    for(int i=1;i<=height;i++){
        for(int j=1;j<=width;j++){
            Sleep(1);
            gotoXY(j+startX-1,i+startY-1);
            printf(" ");
        }
    }
    clearIt();
}
string input(int min_char,int max_char,char output_char,bool can_num,bool can_word,bool can_char){
    int i=0;
    string output;
    while(true){
        char n=(char)_getch();
        bool is_num=(n>='0' && n<='9') && can_num;
        bool is_word=((n>='a' && n<='z') || (n>='A' && n<='Z'))&&can_word;
        bool is_char=n>32 && n!=127 && can_char;
        if(n==13 && (output.length()>=min_char)) break;
        if(i<max_char){
            if(is_char || is_num || is_word) {
                i++;
                output += n;
                if(output_char=='\0') printf("%c", n);
                else printf("%c", output_char);
            }
        }
        if(n=='\b' && i>0){
            i--;
            output.erase(output.end()-1);
            printf("%c %c",n,n);
        }
    }
    return output;
}
