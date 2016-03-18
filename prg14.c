#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
int gd=DETECT,gm;
int i,n,ch;
float x[8],y[8],m;


initgraph(&gd,&gm,"");
cleardevice();
printf("\nBefore clipping A:\n");
line(100,300,200,100);
line(200,100,300,300);
line(150,200,250,200);
delay(1000);
cleardevice();
printf("\nAfter clipping A:\n");
line(200,100,300,300);
line(200,200,250,200);
delay(1000);
cleardevice();

getch();
}
