#include<graphics.h>
#include<stdlib.h>
#include<math.h>


void drawLine(float,float,float,float,int);
void drawLine2(float,float,float,float,int);
void makeLine(float,float,float,float,int);
void draw();

void scanline(int x1, int y1, int x2, int y2, int color);


double face1[4][2]={{100,150},{200,150},{200,250},{100,250}};
double face2[4][2]={{150,100},{250,100},{250,200},{150,200}};
int xend=0, yend=0;

float rotate = 120;


int main(int argc, char *argv)
{
	int gd = DETECT, gm = DETECT,i, j, x, y, x1, y1;
	initgraph(&gd, &gm, "");
        
    /*
    for(i=0;i<4;i++)
	{
	    x = face2[i][0];
	    y = face2[i][1];
	    x1 = x*cos(rotate) - y*sin(rotate);
	    y1 = x*sin(rotate) + y*cos(rotate);
	    face2[i][0] = x1;
	    face2[i][1] = y1;
	}
      
    */

    setcolor(2);
    
    for(i=0;i<4;i++)
    {
        face1[i][0]+=50;
        face2[i][0]+=50;
        face1[i][1]-=50;
        face2[i][1]-=50;
    }
    
    draw();   
    
    setcolor(2);
     
    for(i=0;i<4;i++)
    {
        face1[i][0]-=100;
        face2[i][0]-=100;
        face1[i][1]+=100;
        face2[i][1]+=100;
    }
      
    draw();
    
    delay(1000);
    
    
    scanline(0,0,400,400,10);
    scanline(101,151,151,199,2);
    scanline(151,200,199,249,2);
    
   /*
    draw();   
    
    delay(1000);
    setcolor(2);
     
    for(i=0;i<4;i++)
    {
        face1[i][0]+=100;
        face2[i][0]+=100;
        face1[i][1]-=100;
        face2[i][1]-=100;
    }
      
    draw();
    */
    delay(10000);
    
    return 0;  

}
    
void draw()
{
    int i, tempx1, tempy1, tempx2, tempy2;
    
   
   // setcolor(2);
    line(face1[0][0],face1[0][1],face1[1][0],face1[1][1]);
    line(face1[1][0],face1[1][1],face1[2][0],face1[2][1]);
    line(face1[0][0],face1[0][1],face1[3][0],face1[3][1]);
    line(face1[3][0],face1[3][1],face1[2][0],face1[2][1]);
   
    tempx1 = face1[0][0];
    tempy1 = face1[0][1];
    tempx2 = face1[1][0];
    tempy2 = face1[1][1];
    
    //setlinestyle(1,1,1);
   
    //for(i=0;i<100;i++)
    //    line(tempx1, tempy1+i, tempx2, tempy2+i);
      
   // setcolor(3);
    line(face2[0][0],face2[0][1],face2[1][0],face2[1][1]);
    line(face2[1][0],face2[1][1],face2[2][0],face2[2][1]);
    setcolor(10);
    line(face2[0][0],face2[0][1],face2[3][0],face2[3][1]);
    line(face2[3][0],face2[3][1],face2[2][0],face2[2][1]);
    
    tempx1 = face2[0][0];
    tempy1 = face2[0][1];
    tempx2 = face2[1][0];
    tempy2 = face2[1][1];
    
    //setlinestyle(1,2,1);
   
   // for(i=0;i<100;i++)
     //   line(tempx1, tempy1+i, tempx2, tempy2+i);
    
       setcolor(2);
    line(face1[0][0], face1[0][1], face2[0][0], face2[0][1]);
    line(face1[1][0], face1[1][1], face2[1][0], face2[1][1]);
    line(face1[2][0], face1[2][1], face2[2][0], face2[2][1]);
      setcolor(10);
    line(face1[3][0], face1[3][1], face2[3][0], face2[3][1]);
    
    tempx1 = face1[0][0];
    tempy1 = face1[0][1];
    tempx2 = face2[0][0];
    tempy2 = face2[0][1];
    
    //setlinestyle(1,3,1);
   
    //for(i=0;i<100;i++)
     //   line(tempx1+i, tempy1, tempx2+i, tempy2);
    
  //  setcolor(5);
    tempx1 = face1[1][0];
    tempy1 = face1[1][1];
    tempx2 = face2[1][0];
    tempy2 = face2[1][1];
   
    //setlinestyle(1,4,1);
    
   // for(i=0;i<100;i++)
    //    line(tempx1, tempy1+i, tempx2, tempy2+i);
    
  //  setcolor(15);
    tempx1 = face1[3][0];
    tempy1 = face1[3][1];
    tempx2 = face2[3][0];
    tempy2 = face2[3][1];
    
    //setlinestyle(1,5,1);
    
   // for(i=0;i<100;i++)
    //    line(tempx1+i, tempy1, tempx2+i, tempy2);

}
    
void scanline(int x1, int y1, int x2, int y2, int color)
{
    int i, j;
    
    for(i=x1; i<=x2; i++)
    {
        for(j=y1; j<=y2; j++)
        {
            if(getpixel(i,j)==color)
                putpixel(i,j,BLACK);
        }
    }
    
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

