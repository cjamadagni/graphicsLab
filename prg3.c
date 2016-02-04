#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
void draw(int x1,int y1,int x2,int y2);

void main()
{
    int x1,x2,y1,y2;
    int gd=DETECT,gm;//DETECT is macro defined in graphics.h
    initgraph(&gd,&gm,"d:\\tc\\bgi");//initialize graphic mode
    // printf("Enter values of x1 and y1: ");
    // scanf("%d %d",&x1,&y1);
    // printf("Enter values of x2 and y2 : ");
    // scanf("%d %d",&x2,&y2);
    draw(100,100,500,100);//call to function that draws the line
    draw(100,100,125,300);
    getch();
}
void draw(int x1,int y1,int x2,int y2)
{
    float dx,dy,p;
    int i,x,y,xend;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;
    if(x1>x2)
    {
        x-x2;
        y=y2;
        xend=x1;
    }
    else
    {
        x=x1;
        y=y1;
        xend=x2;
    }
    putpixel(x,y,10);

    while(x<xend)
    {
        if(p<0)
        {
            x=x+1;
            putpixel(x,y,10);
            p=p+(2*dy);
        }
        else
        {
            x=x+1;
            y=y+1;
            putpixel(x,y,10);
            p=p+(2*dy)-(2*dx);
        }
    }
}
