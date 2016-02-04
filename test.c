/*  demo.c*/
#include<graphics.h>
int main()
{
   int gd = DETECT,gm;
   int i=0;
   int j=0;
   initgraph(&gd,&gm,NULL);

   for(i=0;i<=200;i++,j++)
   {
     rectangle(310, 10+i, 315, 100+i);
     arc(310, 35+i, 90, 270, 25);
     arc(315, 35+i, 270, 90, 25);
     rectangle(280,85+i, 310, 60+i);
     rectangle(315,85+i, 345, 60+i);
     setcolor(j);
     delay(100);
     cleardevice();

     if(j==15)
      j=2;

   }

   //circle(x, y, radius);
   //bar(left + 300, top, right + 300, bottom);
   //line(left - 10, top + 150, left + 410, top + 150);
   //ellipse(x, y + 200, 0, 360, 100, 50);
   //outtextxy(left + 100, top + 325, "C Graphics Program");

   delay(1000);
   //getch();
   closegraph();
   return 0;
}
