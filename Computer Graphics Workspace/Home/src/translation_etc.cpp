#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>

using namespace std;
int main()
{
int gDriver=DETECT,gmode;
char path[] = "C:\\MinGW\\lib\\libbgi.a";
initgraph(&gDriver,&gmode, path);

int xt,yt;
cout<<"Enter the unit of x-axis translation: ";
cin>>xt;

cout<<"Enter the unit of y-axis translation: ";
cin>>yt;

int l[2][2],v[2]={xt,yt},i=0,j;

while(i<2)
{
printf("x%d and y%d = ",i,i);
j=0;
scanf("%d",&l[i][j]);
scanf("%d",&l[i][j+1]);
i++;
}

line(l[0][0],l[0][1],l[1][0],l[1][1]);
setcolor(RED);
line(l[0][0]+v[0],l[0][1]+v[1],l[1][0]+v[0],l[1][1]+v[1]); 
getch();
closegraph();
}