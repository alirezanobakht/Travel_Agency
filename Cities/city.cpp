//
// Created by Jarvis on 1/15/2019.
//
//Header:
#include "city.h"
#include "../myAll.h"
#include <math.h>
using namespace std;

typedef struct shahr{
    int id;
    int x;
    int y;
}shahr;

void editPrice(){
    clrscr();
    enableCursor();
    FILE * f=fopen("Cities/pricePolicy.dat","rb");
    if(f==NULL){
        fclose(f);
        cout<<endl;
        cout<<"  No price multiple is declared yet."<<endl;
        cout<<"  Price = Multiple * Distance"<<endl;
        float mul;
        cout<<"  Multiple:    ";
        cin>>mul;
        FILE * f1=fopen("Cities/pricePolicy.dat","wb");
        fwrite(&mul, sizeof(float),1,f1);
        fclose(f1);
    }
    else{
        float curmul;
        fread(&curmul, sizeof(float),1,f);
        fclose(f);
        cout<<endl;
        cout<<"  Multiple = "<<curmul<<endl;
        cout<<"  Price = Multiple * Distance"<<endl;
        float mul;
        cout<<"  New Multiple value:   ";
        cin>>mul;
        FILE * f1=fopen("Cities/pricePolicy.dat","wb");
        fwrite(&mul, sizeof(float),1,f1);
        fclose(f1);
    }
    cout<<"  Pricing Policy changed successfully!";
    Sleep(1000);
    setting();
}

int getPrice(int src,int dst){
    vector<shahr> vs;
    shahr s;
    int id,x,y;
    FILE * f=fopen("Cities/cities.txt","r");
    while(1){
        fscanf(f,"%d\t%d\t%d",&id,&x,&y);
        if(feof(f)) break;
        s.id=id;
        s.x=x;
        s.y=y;
        vs.push_back(s);
    }
    fclose(f);
    int x1,y1,x2,y2;
    x1=vs[src-1].x;
    y1=vs[src-1].y;
    x2=vs[dst-1].x;
    y2=vs[dst-1].y;
    float distant =sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    FILE * f1=fopen("Cities/pricePolicy.dat","rb");
    float mul;
    fread(&mul, sizeof(float),1,f1);
    fclose(f1);
    int price=mul*distant;
    return price;

}