#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gDriver=DETECT,gmode;
    char path[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gDriver,&gmode, path);
    initwindow(1100, 600, "Hello World");


    int s;
    cout<<"1.Translation\n2.Rotation\n3.Scaling"<<endl;
    cout<<"choice:";
    cin>>s;
            if(s == 1)
            {   int x1=200,y1=150,x2=300,y2=250;
                int tx,ty;

                cout<<"Enter the unit of x-axis translation: ";
                cin>>tx;

                cout<<"Enter the unit of y-axis translation: ";
                cin>>ty;

                cout<<"Rectangle before translation"<<endl;
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                setcolor(4);
                cout<<"Rectangle after translation"<<endl;
                rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
                getch();
            }

            else if(s==2){
               long x1=200,y1=200,x2=400,y2=300;
                double a;
                cout<<"Rectangle with rotation"<<endl;
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                cout<<"Angle of rotation:";
                cin>>a;
                a=(a*3.14)/180;
                long xr=x1+((x2-x1)*cos(a)-(y2-y1)*sin(a));
                long yr=y1+((x2-x1)*sin(a)+(y2-y1)*cos(a));
                setcolor(2);
                rectangle(x1,y1,xr,yr);
                getch();
            }
            else if(s == 3){
                int x1=30,y1=30,x2=70,y2=70;
                int x,y;
                cout<<"Enter the x-axis scaling: ";
                cin>>x;
                cout<<"Enter the y-axis scaling";
                cin>>y;
                cout<<"Before scaling"<<endl;
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                cout<<"After scaling"<<endl;
                setcolor(10);
                rectangle(x1*x,y1*y,x2*x,y2*y);
                getch();
            }
            else{
            cout<<"Invalid Selection"<<endl;
          }
    closegraph();
    return 0;
}