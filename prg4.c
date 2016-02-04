#include <graphics.h>
#include <stdio.h>
#include <math.h>

void draw(int x1,int y1,int x2,int y2, int c);
void dcircle(int xc, int yc, int c, int r);

int main( )
{
    int x,y,x1,y1,x2,y2,xcor,ycor;
    int i,gd,gm;
    int x10[25], y10[25];
    int r=40;

    double theta, angle=0;

    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    for(i=0;i<=100;i++)
    {
      draw(200,200+i,600,200+i,12);
      draw(200,300+i,600,300+i,15);
      draw(200,400+i,600,400+i,2);
    }

    dcircle(400,350,1,40);

    for(i=0;i<24;i++)
			{
				theta=M_PI*angle/180;
				x10[i]=400+r*cos(theta);
				y10[i]=350+r*sin(theta);
				angle+=15;
        // setcolor(1);
				// draw(400,350,x10[i],y10[i],1);
        setcolor(1);
        line(400,350,x10[i],y10[i]);
			}




    getch();
    //closegraph();
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
