#include <graphics.h>
#include <stdio.h>
#include <math.h>

void dcircle(int xc, int yc, int c, int r);
void draw(int x1,int y1,int x2,int y2, int c);
void mline(int x1,int y1,int x2,int y2);
void bline(int x1, int y1, int xn, int yn);

void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int main()
{

  int i,j,x,y,gd,gm;

  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"");

  //Hands facing up stick man
  dcircle(200,100,2,30);
  //line(200,130,200,170);
  draw(200,130,200,170,2);
  //draw(200,150,220,180,2);
  bline(200,150,250,130);
  //mline(200,150,150,130);
  bline(150,130,200,150);
  mline(200,170,150,200);
  mline(200,170,250,200);
  //bline(250,200,200,170);

  //Hands down stick man
  dcircle(400,100,2,30);
  draw(400,130,400,170,2);
  mline(400,150,425,175);
  mline(400,150,375,175);
  mline(400,170,425,200);
  mline(400,170,375,200);

  //Squatting stick man
  dcircle(500,100,2,30);
  draw(500,130,500,170,2);
  mline(500,150,550,130);
  mline(500,150,450,130);
  mline(500,170,520,190);
  mline(500,170,480,190);
  mline(520,190,520,210);
  mline(480,190,480,210);







  getch();
  closegraph();


}

void draw(int x1,int y1,int x2,int y2, int c)
{

    int dx,dy,pixel,i,x,y;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
    pixel=dx;
    else
    pixel=dy;

    dx=dx/pixel;
    dy=dy/pixel;

    x=x1;
    y=y1;

    i=1;
    while(i<=pixel)
    {
          putpixel(x,y,c);
          x=x+dx;
          y=y+dy;
          i=i+1;
          //delay(100);
    }


}

void dcircle(int xc, int yc, int c, int r)
{

  setcolor(c);

  int x,y,p;

  x=0;
  y=r;
putpixel(xc+x,yc-y,1);

p=3-(2*r);

for(x=0;x<=y;x++)
{
if (p<0)
{
y=y;
p=(p+(4*x)+6);
}
else
{
y=y-1;

p=p+((4*(x-y)+10));
}

putpixel(xc+x,yc-y,1);
putpixel(xc-x,yc-y,1);
putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,1);
putpixel(xc+y,yc-x,1);
putpixel(xc-y,yc-x,1);
putpixel(xc+y,yc+x,1);
putpixel(xc-y,yc+x,1);

}
}


void mline(int x1,int y1,int x2,int y2)
{
	int dx,dy,d,incry,incre,incrne,slopegt1=0;
	dx=abs(x1-x2);dy=abs(y1-y2);
	if(dy>dx)
	{
		swap(&x1,&y1);
		swap(&x2,&y2);
		swap(&dx,&dy);
		slopegt1=1;
	}
	if(x1>x2)
	{
		swap(&x1,&x2);
		swap(&y1,&y2);
	}
	if(y1>y2)
		incry=-1;
	else
		incry=1;
	d=2*dy-dx;
	incre=2*dy;
	incrne=2*(dy-dx);
	while(x1<x2)
	{
		if(d<=0)
			d+=incre;
		else
		{
			d+=incrne;
			y1+=incry;
		}
		x1++;
		if(slopegt1)
			putpixel(y1,x1,WHITE);
		else
			putpixel(x1,y1,WHITE);
	}
}

void bline(int x1, int y1, int xn, int yn)
{
int dx = xn - x1, dy = yn - y1;
int di = 2 * dy - dx;
int ds = 2 * dy, dt = 2 * (dy - dx);
putpixel(x1, y1, WHITE);
while (x1 < xn)
{
x1++;
if (di < 0)
di = di + ds;
else
{
y1++;
di = di + dt;
}
putpixel(x1, y1, WHITE);
}
}
