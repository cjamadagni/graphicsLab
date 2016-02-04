#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


void circle(int xc, int yc, int r)
{
	int x, y, p;

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

void line( int x1, int y1, int x2, int y2 )
{
	float x, y, xinc, yinc, dx, dy;
	int k, step;
	dx = x2 - x1;
	dy = y2 - y1;
	if( abs(dx) > abs(dy) )
		step = abs(dx);
	else
		step = abs(dy);
	xinc = dx / (float) step;
	yinc = dy / (float) step;
	x = x1;
	y = y1;
	putpixel( x, y, 1 );
	for( k = 1; k <= step; k++ )
	{
		x = x + xinc;
		y = y + yinc;
		putpixel( x, y, 2 );
	}
}

float basex,basey,theta;

float get_x(float x, float y)
{
	x-=basex;
	y-=basey;

	return (x*cos(theta)) - (y*sin(theta))+basex;
}

float get_y(float x, float y)
{
	x-=basex;
	y-=basey;
	return (x*sin(theta)) + (y*cos(theta))+basey;
}

int main(int argc, void* argv[])
{
	int gd=DETECT, gm;
	int i=0, x=0, y=20;
	initgraph(&gd, &gm, "f:\\tc\\bgi");


	int c,len,angle,scale;
	do{
		cleardevice();
		circle (150, 200,30);// left tyre
		circle (250, 200,30);// right tyre
		line(180,200,220,200);// cycle body
		circle (200, 140,15);// stick head
		line (200, 155,200, 180);// stick body
		line (200, 180,190,210);// stick left leg
		line (200, 180,210,210);// stick right leg
		line (200, 165,250,165);// stick hand
		line (250, 170,250, 160);// handle
		printf("MENU:\n");
		printf("1. Translate\n");
		printf("2. Rotate\n");
		printf("3. Scale\n");
		printf("4. Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:

				printf("Enter length\n");
				scanf("%d",&len);
				for(i=0;i<=len;i++)
				{
					theta=i/2;
					cleardevice();
					circle (150+i, 200,30);// left tyre
					circle (250+i, 200,30);// right tyre
					line(180+i,200,220+i,200);// cycle body
					circle (200+i, 140,15);// stick head
					line (200+i, 155,200+i, 180);// stick body
					line (200+i, 180,190+i,210);// stick left leg
					line (200+i, 180,210+i,210);// stick right leg
					line (200+i, 165,250+i,165);// stick hand
					line (250+i, 170,250+i, 160);// handle
					delay(10);
				}
				break;
			case 2:
				cleardevice();
				printf("Enter angle\n");
				scanf("%d",&angle);

					theta=((float)(angle)*3.14)/180;
					cleardevice();
					basex=150;
					basey=200;
					circle (150, 200,30);// left tyre
					circle (get_x(250, 200),get_y(250, 200),30);// right tyre
					line(get_x(180, 200),get_y(180, 200),get_x(220, 200),get_y(220, 200));// cycle body
					circle (get_x(200, 140),get_y(200, 140),15);//  stick head

					line(get_x(200, 155),get_y(200, 155),get_x(200, 180),get_y(200, 180));// stick body
					line(get_x(200, 180),get_y(200, 180),get_x(190, 210),get_y(190, 210));// stick left leg
					line(get_x(200, 180),get_y(200, 180),get_x(210, 210),get_y(210, 210));// stick right leg
					line(get_x(200, 165),get_y(200, 165),get_x(250, 165),get_y(250, 165));// stick hand
					line(get_x(250, 170),get_y(250, 170),get_x(250, 160),get_y(250, 160));// handle

					delay(100);

				getch();
				break;
			case 3:
				cleardevice();
				printf("Enter scaling factor\n");
				scanf("%d",&scale);
				circle (150*scale, 200*scale,30*scale);// left tyre
				circle (250*scale, 200*scale,30*scale);// right tyre
				line(180*scale,200*scale,220*scale,200*scale);// cycle body
				circle (200*scale, 140*scale,15*scale);// stick head
				line (200*scale, 155*scale,200*scale, 180*scale);// stick body
				line (200*scale, 180*scale,190*scale,210*scale);// stick left leg
				line (200*scale, 180*scale,210*scale,210*scale);// stick right leg
				line (200*scale, 165*scale,250*scale,165*scale);// stick hand
				line (250*scale, 170*scale,250*scale, 160*scale);// handle
				getch();
				break;
		}
	}while(c!=4);


	closegraph();

}
