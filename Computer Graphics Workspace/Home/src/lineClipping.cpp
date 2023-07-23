#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;

const int l = 1, r = 2, bottom = 4,top = 8;
static int xmin,xmax,ymin,ymax;

int getCode(int x,int y){
    int code = 0;
    if(y>ymax) code |= top;
    if(y<ymin) code |= bottom;
    if(x<xmin) code |= l;
    if(x>xmax) code |= r;
    return code;
}

int main()
{
    int gm,gd = DETECT;
    char path[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gm,&gd,path);
    initwindow(600,600);

    setcolor(WHITE);
    cout<<"Enter windows minimum and maximum values: ";
    cin>>xmin>>ymin>>xmax>>ymax;
    rectangle(xmin,ymin,xmax,ymax);
    int x1,y1,x2,y2;

    cout<<"Enter the endpoints of the line: ";
    cin>>x1>>y1>>x2>>y2;
    line(x1,y1,x2,y2);
    getch();

    int outcode1 = getCode(x1,y1),outcode2 = getCode(x2,y2);
    int accept = 0;
    
    while(1){
        float m = (float)(y2-y1)/(x2-x1);

        if(outcode1 == 0 && outcode2 == 0){
            accept  = 1;
            break;
        }

        else if((outcode1 & outcode2) != 0){
            break;
        }
        else{
            int x,y;
            int temp;
            if(outcode1 == 0) temp = outcode2;
            else temp = outcode1;

            if(temp & top){
                x = x1 + (ymax-ymin)/m;
                y = ymax;
            }
            else if (temp & bottom) {
                x = x1 + (ymin - y1)/ m;
                y = ymin;
            }
            else if (temp & l) {
                y = y1 + m*(xmin-x1);
                x = xmin;
            }
            else if (temp & r) {
                y = y1 + m*(xmax -x1);
                x = xmax;
            }

            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getCode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                outcode2 = getCode(x2, y2);
            }

        }
    }
    
    cout << "After Clipping";
    if (accept) {
        cleardevice();
        rectangle(xmin,ymin,xmax,ymax);
        setcolor(RED);
        line(x1,y1,x2,y2);
    }
    else cout << "Line rejected" << endl;

    getch();
    closegraph();
    return 0;
}