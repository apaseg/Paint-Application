#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int gm,gd = DETECT;
    char path[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gm,&gd,path);
    initwindow(500, 500);

    float x1,x2,y1,y2,dx,dy,steps,xinc,yinc,x,y;

    cout<<"Enter the value of x1 and y1"<<endl;
    cin>>x1>>y1;

    cout<<"Enter the value of x2 and y2"<<endl;
    cin>>x2>>y2;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }

    xinc = dx/steps;
    yinc = dy/steps;

    for(int i=0;i<steps;i++){
        putpixel(x1,y1,WHITE);
        x1 = x1+xinc;
        y1 = y1+yinc;
        delay(50);
    }

    getch();
    closegraph();

return 0;
}
