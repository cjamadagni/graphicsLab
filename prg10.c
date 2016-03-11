#include <stdio.h>
#include <graphics.h>

float basex,basey,theta, basex1, basey1;

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

float get_x1(float x, float y)
{
	x-=basex1;
	y-=basey1;

	return (x*cos(theta)) - (y*sin(theta))+basex;
}

float get_y1(float x, float y)
{
	x-=basex1;
	y-=basey1;
	return (x*sin(theta)) + (y*cos(theta))+basey;
}

int main()
{
 int gd=DETECT,gm;
  int ch,angle;
  printf("Enter choice\n1.Front facing\n2.Back facing\n3.Rotation");
  scanf("%d",&ch);
  initgraph(&gd,&gm,NULL);
  int flx1,flx2,flx3,flx4,fly1,fly2,fly3,fly4;
  int f2x1,f2x2,f2x3,f2x4,f2y1,f2y2,f2y3,f2y4;
  int p1[50], p2[50];
  int poly1[]={100,100,150,150,150,250,100,200,100,100};
  int poly2[]={200,100,250,150,250,250,200,200,200,100};
  int face1[]={100,100,150,150,150,250,100,200,100,100};
  int face2[]={100,100,200,100,250,150,150,150,100,100};
  int face3[]={150,150,250,150,250,250,150,250,150,150};
  int face4[]={100,100,200,100,200,200,100,200,100,100};
  int face5[]={100,200,200,200,250,250,150,250,100,200};
  int face6[]={200,100,250,150,250,250,200,200,200,100};
  rectangle(100,100,200,200);
  rectangle(150,150,250,250);
  drawpoly(5,poly1);
  drawpoly(5,poly2);

  if(ch==1)
  {
    setcolor(RED);
    fillpoly(5,face1);

    setcolor(GREEN);
    fillpoly(5,face2);

    setcolor(YELLOW);
    fillpoly(5,face3);

    setcolor(BLACK);
    setlinestyle(1,0,1);
    line(100,200,200,200);
    line(200,100,200,200);
    line(200,200,250,250);
  }

  if(ch==2)
  {
    setcolor(BLUE);
    fillpoly(5,face4);

    setcolor(WHITE);
    fillpoly(5,face5);

    setcolor(BROWN);
    fillpoly(5,face6);

    setcolor(BLACK);
    setlinestyle(1,0,1);
    line(100,100,150,150);
    line(150,150,250,150);
    line(150,150,150,250);
  }

  else if(ch==3)
  {
    //cleardevice();
    printf("\n\nEnter angle of rotation ");
    scanf("%d",&theta);

    cleardevice();

    basex = 150;
    basey = 150;
    basex1 = 150;
    basey1 = 250;

    flx1 = get_x(100,100);
    fly1 = get_y(100,100);
    flx2 = get_x(200,100);
    fly2 = get_y(200,100);
    flx3 = get_x(250,150);
    fly3 = get_y(250,150);

    p1[0] = flx1;
    p1[1] = fly1;
    p1[2] = flx2;
    p1[3] = fly2;
    p1[4] = flx3;
    p1[5] = fly3;
    p1[6] = 150;
    p1[7] = 150;
    p1[8] = flx1;
    p1[9] = fly1;

    f2x1 = get_x1(100,200);
    f2y1 = get_y1(100,200);
    f2x2 = get_x1(200,200);
    f2y2 = get_y1(200,200);
    f2x3 = get_x1(250,250);
    f2y3 = get_y1(250,250);

    p2[0] = f2x1;
    p2[1] = f2y1;
    p2[2] = f2x2;
    p2[3] = f2y2;
    p2[4] = f2x3;
    p2[5] = f2y3;
    p2[6] = 150;
    p2[7] = 250;
    p2[8] = f2x1;
    p2[9] = f2y1;

    setcolor(WHITE);
    setlinestyle(0,0,0);
    drawpoly(5,p1);
    drawpoly(5,p2);
    line(150,150,150,250);
    line(f2x1,f2y1,flx1,fly1);
    line(f2x2,f2y2,flx2,fly2);
    line(f2x3,f2y3,flx3,fly3);






  }



delay(10000);
return 0;
	}
