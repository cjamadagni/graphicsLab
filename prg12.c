//House to viewport - Scaling down example


#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void drawHouseWorld(int x, int y)
{
	int house[] = {x,y,x+100,y,x+100,y+100,x,y+100,x,y};
	int door[] = {x+25,y+100,x+75,y+100,x+75,y+50,x+25,y+50,x+25,y+100};
	int roof[] = {x,y,x+100,y,x+50,y-50,x,y};
	int window[] = {x+10,y+10,x+30,y+10,x+30,y+30,x+10,y+30,x+10,y+10};



	drawpoly(5,house);
	drawpoly(5,door);
	drawpoly(4,roof);
	drawpoly(5,window);
}

void drawHouseView(int x, int y, int x1w, int y1w, int x2w, int y2w, int x1v, int y1v, int x2v, int y2v)
{
	float sx = (float)(x2v-x1v)/(x2w-x1w);
	float sy = (float)(y2v-y1v)/(y2w-y1w);
	int house[] = {x1v+sx*x,y1v+sy*y,x1v+sx*(x+100),y1v+sy*y,x1v+sx*(x+100),y1v+sy*(y+100),x1v+sx*x,y1v+sy*(y+100),x1v+sx*x,y1v+sy*y};
	int roof[] = {x1v+sx*x,y1v+sy*y,x1v+sx*(x+100),y1v+sy*y,x1v+sx*(x+50),y1v+sy*(y-50),x1v+sx*x,y1v+sy*y};
	int door[] = {x1v+sx*(x+25),y1v+sy*(y+100),x1v+sx*(x+75),y1v+sy*(y+100),x1v+sx*(x+75),y1v+sy*(y+50),x1v+sx*(x+25),y1v+sy*(y+50),x1v+sx*(x+25),y1v+sy*(y+100)};
	int window[] = {x1v+sx*(x+10),y1v+sy*(y+10),x1v+sx*(x+30),y1v+sy*(y+10),x1v+sx*(x+30),y1v+sy*(y+30),x1v+sx*(x+10),y1v+sy*(y+30),x1v+sx*(x+10),y1v+sy*(y+10)};

	drawpoly(5,house);
	drawpoly(5,door);
	drawpoly(4,roof);
	drawpoly(5,window);
}

int main()
{
	int gd=DETECT,gm,x=200,y=200;

	int x1w,y1w,x2w,y2w;
	int x1v,y1v,x2v,y2v;
	printf("Enter top-left and bottom-right of world co-ordinate system\n");
	scanf("%d%d%d%d",&x1w,&y1w,&x2w,&y2w);	//100,100,400,400

	printf("Enter top-left and bottom-right of view co-ordinate system\n");
	scanf("%d%d%d%d",&x1v,&y1v,&x2v,&y2v);	//100,100,300,300

	initgraph(&gd, &gm, NULL);

  // World coordinate system
	setcolor(BLUE);
	rectangle(x1w,y1w,x2w,y2w);
	drawHouseWorld(x,y);

	delay(3000);
	cleardevice();

  // View coordinate system
  setcolor(GREEN);
	rectangle(x1v,y1v,x2v,y2v);
	drawHouseView(x-x1w,y-y1w,x1w,y1w,x2w,y2w,x1v,y1v,x2v,y2v);

	delay(3000);
	cleardevice();

	closegraph();
	return 0;
}
