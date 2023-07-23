#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;

int main(){
    int gm,gd = DETECT;
    char path[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gm,&gd,path);
    initwindow(600,600);
    int x1,x2,y1,y2,dx,dy,p,xinc,yinc;

    cout<<"Enter the value of x1 and y1";
    cin>>x1>>y1;

    cout<<"Enter the value of x2 and y2";
    cin>>x2>>y2;

    dx = x2-x1;
    dy = y2-y1;

    p  = 2*dy - dx;

    putpixel(x1,y1,WHITE);

    for(int i=0;i<dx;i++){
       if(p<0){
        x1++;
        p = p+2*dy;
       }
       else{
        x1++;
        y1++;
        p = p+ 2*dy - 2*dx;
       }

       putpixel(x1,y1,RED);
       delay(50);
    }

    getch();
    closegraph();

}