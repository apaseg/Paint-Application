#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
int colr = 15;
int radii = 2;
void drawingpad();
void setup();
void boundaryfill(int x, int y, int fill, int boundary);
void eraser(int x, int y, int size);
void eraser_box();
void car_moving();
void clear();
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char *)"");
	initwindow(1500, 1200, "Paint Application by Anmol"); // windows coordinate
	setbkcolor(BLACK);
	cleardevice();
	drawingpad(); // main drawing canvas
	getch();
	closegraph();
}

void drawingpad()
{
	POINT cur_pos;
	setup();
	int choice = 0;
	while (1)
	{
		setcolor(colr);
		// Get Screen Co-ordinate
		GetCursorPos(&cur_pos);
		
		// Convert Screen Co-ordinate To Window Co-ordinate
		ScreenToClient(GetForegroundWindow(), &cur_pos);
		int x1, y1, x2, y2;

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			x1 = cur_pos.x;
			y1 = cur_pos.y;
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (ismouseclick(WM_LBUTTONUP))
		{
			x2 = cur_pos.x;
			y2 = cur_pos.y;
			clearmouseclick(WM_LBUTTONUP);
			if (x2 >= 80)
			{
				int cc=getcolor();
				setcolor(WHITE);
				if (choice == 1)
				{
					double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
					int xc = (x1 + x2) / 2;
					int yc = (y1 + y2) / 2;
					circle(xc, yc, dis / 2);
					circle(xc, yc, dis / 2 - 1);
				}
				else if (choice == 2)
				{
					line(x1, y1, x2, y2);
				}
				else if (choice == 3)
				{
					rectangle(x1, y1, x2, y2);
					rectangle(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
				}
				setcolor(cc);
			}
		}
		if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x >= 100)
		{
			// Getcur_pos(&cur_pos);
			switch (choice)
			{
			case 4:
				circle(cur_pos.x, cur_pos.y, radii);
				boundaryfill(cur_pos.x, cur_pos.y, colr, colr);
				break;
			case 5:
			setfillstyle(1,colr);
			floodfill(cur_pos.x,cur_pos.y,WHITE);
				// boundaryfill(cur_pos.x, cur_pos.y, colr, colr);
				// delay(500);
				break;
			case 6:
				eraser(cur_pos.x, cur_pos.y, radii);
				break;

			case 7:
				car_moving();
				break;
			}
			
			clearmouseclick(VK_LBUTTON);
		}
		// first button
		if (((GetAsyncKeyState(VK_LBUTTON)) != 0) && cur_pos.x >= 18 && cur_pos.x <= 40 && cur_pos.y >= 50 && cur_pos.y <= 70)
		{
			choice = 3; // circle
		}
		else if (((GetAsyncKeyState(VK_LBUTTON)) != 0) && cur_pos.x >= 44 && cur_pos.x <= 66 && cur_pos.y >= 50 && cur_pos.y <= 70)
		{
			choice = 2; // line
		}
		else if (((GetAsyncKeyState(VK_LBUTTON)) != 0) && cur_pos.x >= 18 && cur_pos.x <= 40 && cur_pos.y >= 74 && cur_pos.y <= 94)
		{
			choice = 1; // rectangle
		}
		else if (((GetAsyncKeyState(VK_LBUTTON)) != 0) && cur_pos.x >= 44 && cur_pos.x <= 66 && cur_pos.y >= 74 && cur_pos.y <= 94)
		{
			choice = 4; // rectangle
			outtextxy(13, 598, (char *)"Choice:     ");
			outtextxy(13, 615, (char *)"4    ");
		}

		// Color black
		if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 180 && cur_pos.y < 200)
		{
			colr = 15;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color magenta
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 180 && cur_pos.y < 200)
		{
			colr = 5;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color blue
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 204 && cur_pos.y < 224)
		{
			colr = 1;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color green
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 204 && cur_pos.y < 224)
		{
			colr = 2;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color red
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 228 && cur_pos.y < 240)
		{
			colr = 4;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color yellow
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 228 && cur_pos.y < 240)
		{
			colr = 14;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color cyan
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 252 && cur_pos.y < 272)
		{
			colr = 3;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color Brown
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 252 && cur_pos.y < 272)
		{
			colr = 6;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color light red
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 276 && cur_pos.y < 296)
		{
			colr = 12;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Color light red
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 276 && cur_pos.y < 296)
		{
			colr = 9;
			setcolor(8);
			outtextxy(13, 598, (char *)"Marker     ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		// Eraser
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 66 && cur_pos.y > 300 && cur_pos.y < 350)
		{
			choice=6; //eraser
			// colr = 0;
			setcolor(8);
			outtextxy(13, 598, (char *)"Eraser      ");
			outtextxy(13, 615, (char *)"In Use    ");
		}

		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 70 && cur_pos.y > 98 && cur_pos.y < 138)
		{
			choice=7; //car moving
			// colr = 0;
			setcolor(8);
			outtextxy(13, 598, (char *)"Moving      ");
			outtextxy(13, 615, (char *)"Car    ");
		}
		// Clear all
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 66 && cur_pos.y > 408 && cur_pos.y < 454)
		{
			cleardevice();
			setup();
			setcolor(8);
			outtextxy(13, 598, (char *)"Cleared    ");
			outtextxy(13, 615, (char *)"All      ");
		}

		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 66 && cur_pos.y > 354 && cur_pos.y < 404)
		{
			choice = 5;
			outtextxy(13, 598, (char *)"Flood    ");
			outtextxy(13, 615, (char *)"Fill      ");
		}
		// Brushsize
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 484 && cur_pos.y < 508)
		{
			radii = 2;
			setcolor(8);
			outtextxy(13, 598, (char *)"Brush      ");
			outtextxy(13, 615, (char *)"2px      ");
		}
		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 484 && cur_pos.y < 508)
		{
			radii = 6;
			setcolor(8);
			outtextxy(13, 598, (char *)"Brush     ");
			outtextxy(13, 615, (char *)"6px      ");
		}

		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 18 && cur_pos.x < 40 && cur_pos.y > 512 && cur_pos.y < 536)
		{
			radii = 10;
			setcolor(8);
			outtextxy(13, 598, (char *)"Brush      ");
			outtextxy(13, 615, (char *)"10px      ");
		}

		else if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cur_pos.x > 44 && cur_pos.x < 66 && cur_pos.y > 512 && cur_pos.y < 536)
		{
			radii = 14;
			setcolor(8);
			outtextxy(13, 598, (char *)"Brush      ");
			outtextxy(13, 615, (char *)"14px      ");
		}
	}
}

void setup()
{
	readimagefile("Logos.jpg", 6, 50, 76, 120);
	setcolor(8);
	outtextxy(25,365,(char *)"Flood");
	outtextxy(25,385,(char *)"Fill");
	setcolor(1);
	// status:
	outtextxy(13, 580, (char *)"Status: ");
	setcolor(8);
	// canvas vv
	rectangle(80, 0, 1400, 700);
	rectangle(81, 1, 1399, 699);
	// setbkcolor(WHITE);
	// floodFill(82,2,0,15);

	// tool box vv
	rectangle(10, 40, 74, 468);
	rectangle(11, 41, 73, 467);

	// size outline
	rectangle(10, 474, 74, 560);
	rectangle(11, 475, 73, 559);
	outtextxy(28, 540, (char *)"SIZE");
	outtextxy(26, 489, (char *)"1");
	outtextxy(52, 489, (char *)"2");
	outtextxy(26, 516, (char *)"3");
	outtextxy(52, 516, (char *)"4");

	// brush size vv
	rectangle(18, 484, 40, 508);
	rectangle(44, 484, 66, 508);

	rectangle(18, 512, 40, 536);
	rectangle(44, 512, 66, 536);

	// top buttons
	rectangle(18, 50, 40, 70);
	rectangle(22, 56, 36, 64);
	rectangle(44, 50, 66, 70);
	line(49, 55, 61, 65);

	rectangle(18, 74, 40, 94);
	circle(29, 84, 7);
	rectangle(44, 74, 66, 94);

	// moving car
	rectangle(18,98,70,138);
	// colors vv
	rectangle(18, 180, 40, 200);
	rectangle(44, 180, 66, 200);

	rectangle(18, 204, 40, 224);
	rectangle(44, 204, 66, 224);

	rectangle(18, 228, 40, 248);
	rectangle(44, 228, 66, 248);

	rectangle(18, 252, 40, 272);
	rectangle(44, 252, 66, 272);

	rectangle(18, 276, 40, 296);
	rectangle(44, 276, 66, 296);

	// eraser vv
	eraser_box();
	rectangle(18, 300, 66, 350);

	// clear vv
	clear();
	rectangle(18, 408, 66, 458);

	clear();
	rectangle(18, 354, 66, 404);



	boundaryfill(12, 174, 7, 8);

	boundaryfill(12, 476, 7, 8);

	boundaryfill(19, 181, 15, 8);
	boundaryfill(45, 181, 5, 8);

	boundaryfill(19, 205, 1, 8);
	boundaryfill(45, 205, 2, 8);

	boundaryfill(19, 229, 4, 8);
	boundaryfill(45, 229, 14, 8);

	boundaryfill(19, 253, 3, 8);
	boundaryfill(45, 253, 6, 8);

	boundaryfill(19, 277, 12, 8);
	boundaryfill(45, 277, 9, 8);

	
}
void boundaryfill(int x, int y, int fill, int boundary)
{
	// setfillstyle(1,fill);
	// floodfill(x,y,boundary);
	int current = getpixel(x, y);
	if ((current != boundary) && (current != fill))
	{
		// setcolor(fill);
		putpixel(x, y, fill);
		boundaryfill(x + 1, y, fill, boundary);
		boundaryfill(x, y - 1, fill, boundary);
		boundaryfill(x - 1, y, fill, boundary);
		boundaryfill(x, y + 1, fill, boundary);
	}
}

void clear()
{
	outtextxy(26, 440, (char *)"clear");

	circle(42, 428, 10);
	circle(42, 428, 9);
	outtextxy(39, 411, (char *)"<");
}
void eraser(int x, int y, int size)
{
	setfillstyle(1,BLACK);
	bar(x-2*size,y-2*size,x+2*size,y+2*size);
}
void eraser_box()
{
	outtextxy(25, 332, (char *)"Erase");
	line(26, 330, 58, 330);
	rectangle(35, 306, 50, 330);
	rectangle(36, 307, 49, 329);
	line(35, 318, 50, 318);
	
}

void car_moving(){
	int x1,x2,j=0;

	printf("Enter the x co-ordinates of the car from where you want to move: ");
	scanf("%d",&x1);

	printf("Enter the x co-ordinates of the car till where you want to move: ");
	scanf("%d",&x2);

	int i;
	for (i = x1; i <= x2; i = i + 10) {
 
        setcolor(RED);

        line(0 + i, 300, 210 + i, 300);
        line(0 + i, 330, 50 + i, 330);
        line(80 + i, 330, 130 + i, 330);
        line(210 + i, 330, 160 + i, 330);

        line(50 + i, 300, 75 + i, 270);
        line(150 + i, 270, 165 + i, 300);
        line(75 + i, 270, 150 + i, 270);

        line(0 + i, 300, 0 + i, 330);
        line(210 + i, 300, 210 + i, 330);

        circle(65 + i, 330, 15);
        circle(65 + i, 330, 2);
 
        circle(145 + i, 330, 15);
        circle(145 + i, 330, 2);

 
        delay(100);
 
        setcolor(BLACK);

        line(0 + i, 300, 210 + i, 300);
        line(50 + i, 300, 75 + i, 270);
        line(75 + i, 270, 150 + i, 270);
        line(150 + i, 270, 165 + i, 300);
        line(0 + i, 300, 0 + i, 330);
        line(210 + i, 300, 210 + i, 330);
 
        circle(65 + i, 330, 15);
        circle(65 + i, 330, 2);

        circle(145 + i, 330, 15);
        circle(145 + i, 330, 2);

        line(0 + i, 330, 50 + i, 330);

        line(80 + i, 330, 130 + i, 330);
 
        line(210 + i, 330, 160 + i, 330);
    }
 
    getch();
}