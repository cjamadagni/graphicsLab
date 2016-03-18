#include<stdio.h>
#include<graphics.h>
#include<math.h>

void clip(float,float,float);

int i,j=0,n;
int rx1,rx2,ry1,ry2;
float x1[8], newy[8];

void main()
{

int gd=DETECT,gm;
int i,n,ch;
float x[8],y[8],m;

printf("coordinates for rectangle : ");
scanf("%d%d%d%d",&rx1,&ry1,&rx2,&ry2);
printf("no. of sides for polygon : ");
scanf("%d",&n);
printf("coordinates : ");
for(i=0;i<n;i++)
{
scanf("%f%f",&x[i],&y[i]);
}
printf("Clip? ");
scanf("%d",&ch);

initgraph(&gd,&gm,"");

cleardevice();

if(ch==0)
{
rectangle(rx1,ry1,rx2,ry2);

for(i=0;i<n-1;i++)
	line(x[i],y[i],x[i+1],y[i+1]);
line(x[i],y[i],x[0],y[0]); //For the 0th coordinates

getch();
}

if(ch==1)
{
for(i=0;i<n-1;i++)
{
m=(y[i+1]-y[i])/(x[i+1]-x[i]);
clip(x[i],y[i],m);
clip(x[i+1],y[i+1],m);
}
//For the 0th coordinates
m=(y[i]-y[0])/(x[i]-x[0]);
clip(x[i],y[i],m);
clip(x[0],y[0],m);



cleardevice();
rectangle(rx1,ry1,rx2,ry2);

for(i=0;i<j-1;i++)
line(x1[i],newy[i],x1[i+1],newy[i+1]);
getch();
}

delay(3000);
   closegraph();
}

void clip(float e,float f,float m)
{
while(e<rx1||e>rx2||f<ry1||f>ry2)
{
	if(e<rx1)
	{
	f+=m*(rx1-e);
	e=rx1;
	}
	else if(e>rx2)
	{
	f+=m*(rx2-e);
	e=rx2;
	}
	if(f<ry1)
	{
	e+=(ry1-f)/m;
	f=ry1;
	}
	else if(f>ry2)
	{
	e+=(ry2-f)/m;
	f=ry2;
	}
}
	x1[j]=e;
	newy[j]=f;
	j++;

}
