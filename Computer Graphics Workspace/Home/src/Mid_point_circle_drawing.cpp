#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>

using namespace std;

void drawCircle(int x, int y, int xc, int yc){
    putpixel(x+xc,y+yc,GREEN);
	putpixel(-x+xc,y+yc,GREEN);
	putpixel(x+xc, -y+yc,GREEN);
	putpixel(-x+xc, -y+yc, GREEN);
	putpixel(y+xc, x+yc, GREEN);
	putpixel(y+xc, -x+yc, GREEN);
	putpixel(-y+xc, x+yc, GREEN);
	putpixel(-y+xc, -x+yc, GREEN);
}

int main()
{
	int gd = DETECT, gm;
	int r, xc, yc, pk, x, y;
    char path[] = "C:\\MinGW\\lib\\libbgi.a";

	initgraph(&gd, &gm, path);
	cout<<"Enter the center co-ordinates\n";
	cin>>xc>>yc;
	cout<<"Enter the radius of circle\n";
	cin>>r;
	pk = 1 - r;
	x = 0;
	y = r;
	while(x < y)
	{
		drawCircle(x,y,xc,yc);
		++x;
		if(pk < 0)
		{
			pk = pk + (2*x) + 1;
		}
		else
		{
			--y;
			pk = pk + (2*x) + 1 - (2*y);
		}
        delay(50);
	}
    
	getch();
	closegraph();
}
