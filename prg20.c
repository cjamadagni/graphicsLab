#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bspline(int, int, int, int, int, int, int, int);
void init(int *, int *, int *, int *, int *, int *, int *, int *);
void approximateLineSegments();


void bspline(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
        //putpixel(x[i],y[i],GREEN);
    int px,py,x;

   // init(&x0,&y0,&x1,&y1,&x2,&y2,&x3,&y3);

    double t;

    for(t=0.0,x=0;t<=1.0;t+=0.001,x++)
    {
        px=(1-t)*(1-t)*(1-t)*x0+3*t*(1-t)*(1-t)*x1+3*t*t*(1-t)*x2+t*t*t*x3;
        py=(1-t)*(1-t)*(1-t)*y0+3*t*(1-t)*(1-t)*y1+3*t*t*(1-t)*y2+t*t*t*y3;
        py = 250-(50*sin(x*3.141/180));
        if(x<380)
        putpixel(x,py,WHITE);
    }

}



void approximateLineSegments()
{

    float origin[2]={-3.14,0};
    float amplitude = 1; // wave amplitude
    float rarity = 0.5; // point spacing
    float freq = 0.5; // angular frequency
    float phase = 3.14 * 2; // phase angle
    float x1, y1, x2, y2;
    int i;

    for ( i = 5; i < 40; i++) {

    x1 = (i - 1) * rarity + origin[0];
    y1 = sin(freq * (i - 1 + phase)) * amplitude + origin[1];
    x2 = i * rarity + origin[0];
    y2 = sin(freq * (i + phase)) * amplitude + origin[1];
    line(x1,y1,x2,y2);
    }

}

void init(int *x0, int *y0, int *x1, int *y1, int *x2, int *y2, int *x3, int *y3)
{
    *x0=0, *y0=0, *x1=0.512*125, *y1=0.512*125, *x2=1.002*125, *y2=1*125, *x3=1.570*125, *y3=1*125;
}



void main()
{

    int gd=DETECT,gm;
    int x1, y1, x2, y2, cx1, cy1, cx2, cy2;
    float angle=0;

    initgraph(&gd,&gm,"D:\\TC\\BGI");

    int   scale=125;

    //bspline(306,356,262,138,100,287,62,30);

    x1 = 306+200*cos(angle);
    y1 = 356 + 200*sin(angle);
    x2 = 62+200*sin(angle);
    y2 = 30+200*cos(angle);
    cx1 = 262+-300*cos(angle);
    cy1 = 138+-300*cos(angle);
    cx2 = 100+-300*sin(angle);
    cy2 = 287+-300*sin(angle);

    delay(100);

   bspline(x1,y1,cx1,cy1,cx2,cy2,x2,y2);

  //  bspline(x1,y1,cx1,cy1,cx2,cy2,x2,y2);
   //bspline(0,0,128,128,250.5,250,392.5,250);
   //approximateLineSegments();
   //bspline(0,0,128,128,250.5,250,392.5,250);
   // bspline(scale*x1,scale*y1,scale*cx1,scale*cy1,scale*cx2,scale*cy2,scale*x2,scale*y2);

//    bspline(392.5,250,250.5,250,128,128,0,0);

    delay(5000);
    closegraph();

}
