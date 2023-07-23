#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>

using namespace std;

void floodFill(int x, int y, int old, int fill)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill);
		// delay(5);
		floodFill(x+1,y,old,fill);
		floodFill(x-1,y,old,fill);
		floodFill(x, y+1,old,fill);
		floodFill(x,y-1,old,fill);
	}
}

int main(){
		int x,y,o=0;
		int gDriver=DETECT,gmode;
        char path[] = "C:\\MinGW\\lib\\libbgi.a";
		initgraph(&gDriver,&gmode, path);

		rectangle(100,100,300,300);
		x=(100+300)/2;
		y=(100+300)/2;
		floodFill(x,y,o,2);
		getch();
		closegraph();
}