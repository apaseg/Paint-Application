#include<graphics.h>
#include<conio.h>

int main(){
    int gd = DETECT,gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a";


    initgraph(&gd,&gm,data);
    outtext("Hello");
    outtextxy(100,100,"World");

    getch();
    closegraph();
    return 0;
}