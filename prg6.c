#include <graphics.h>
#include <stdio.h>
#include <math.h>

void draw(int x1,int y1,int x2,int y2, int c);
void dcircle(int xc,int yc, int r, int c);

int main()
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

  //dcircle(400,350,40,1);

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

    //Drawing the circle
    circle(400,350,40);



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

void Draw8Points(int xc,int yc, int a, int b)
{
        putpixel(xc+a, yc+b, 1);
        putpixel(xc-a, yc+b, 1);
        putpixel(xc-a, yc-b, 1);
        putpixel(xc+a, yc-b, 1);
        putpixel(xc+b, yc+a, 1);
        putpixel(xc-b, yc+a, 1);
        putpixel(xc-b, yc-a, 1);
        putpixel(xc+b, yc-a, 1);

}

void circle(int xc,int yc, int R)
{
int x=R,y=0;
double theta=0,dtheta=1.0/R;
// Draw8Points(xc,yc,x,y);
while(x>y)
{
theta+=dtheta;
x=round(R*cos(theta));
y=round(R*sin(theta));
Draw8Points(xc,yc,x,y);
}
}
