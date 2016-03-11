#include<graphics.h>
#include<stdlib.h>

float scale = 0.5;
int translatex = 100;
int translatey = 100;
float rotate = 120;

//secret: I actually use the inbuilt.
void drawLine(float,float,float,float,int);
void drawLine2(float,float,float,float,int);
void makeLine(float,float,float,float,int);


int main(int argc, char *argv)
{
	int gd = DETECT, gm = DETECT,i, x, y, x1, y1;
	scale=scale*2;
	initgraph(&gd, &gm, "");

	int point[5][2]={{100, 100}, {150, 50}, {200, 100}, {200, 200}, {100, 200}};

	for(i=0;i<5;i++)
	{
	    point[i][0]+=translatex;
	    point[i][1]+=translatey;
	}

	for(i=0;i<5;i++)
	{
	    point[i][0]*=scale;
	    point[i][1]*=scale;
	}

	for(i=0;i<5;i++)
	{
	    x = point[i][0];
	    y = point[i][1];
	    x1 = x*cos(rotate) - y*sin(rotate);
	    y1 = x*sin(rotate) + y*cos(rotate);
	    point[i][0] = x1;
	    point[i][1] = y1;
	}



    line(point[0][0], point[0][1], point[1][0], point[1][1]);
    line(point[1][0], point[1][1], point[2][0], point[2][1]);
    line(point[2][0], point[2][1], point[3][0], point[3][1]);
    line(point[0][0], point[0][1], point[4][0], point[4][1]);
    line(point[4][0], point[4][1], point[3][0], point[3][1]);



	delay(10000);

	return 0;

}

void drawLine(float x0,float y0,float x1,float y1, int color)
{
	int p0, i, dx, dy;
	dx = x1 - x0;
	dy = y1 - y0;

	p0 = 2*dy - dx;
	putpixel(x0, y0, color);
	for (i=0;i<abs(dx-1);i++)
	{
		if(p0 < 0)
		{
			p0 = p0 + 2*dy;
			x0 = x0 + 1;
			putpixel(x0, y0, color);
		}
		else
		{
			p0 = p0 + 2*dy - 2*dx;
			x0 = x0 + 1;
			if(y1<y0)
				y0--;
			else
				y0 = y0 + 1;
			putpixel(x0, y0, color);
		}
	}
}

void drawLine2(float x0,float y0,float x1,float y1, int color)
{
	int p0, i, dx, dy;
	dx = x1 - x0;
	dy = y1 - y0;
	p0 = 2*dx - dy;
	putpixel(x0, y0, color);
	for (i=0;i<abs(dy-1);i++)
	{
		if(p0 < 0)
		{
			p0 = p0 + 2*dx;
			if(y1<y0)
				y0--;
			else
				y0 = y0 + 1;
			putpixel(x0, y0, color);
		}
		else
		{
			p0 = p0 + 2*dx - 2*dy;
			x0 = x0 + 1;
			if(y1<y0)
				y0--;
			else
				y0 = y0 + 1;
			putpixel(x0, y0, color);
		}
	}
}

void makeLine(float x0,float y0,float x1,float y1, int color)
{
	float m;
	m = (y1-y0)/(x1-x0);
	if(fabs(m)>=1)
		drawLine2(x0,y0,x1,y1,color);
	else
		drawLine(x0,y0,x1,y1,color);
}
