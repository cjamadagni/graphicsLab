#include<graphics.h>

int x[10] = {100,200,200,100,150,250,250,150,150,200};
int y[10] = {100,100,200,200,70,70,170,170,50,20};
float shearx = 0.5;
int reflectx = 260;
int shearshift = 150;

void reflection();
void shear();


void main()
{
    int gd=DETECT,gm;
    int ch;
    printf("\n\n1.Reflection\n2.Shear\nEnter choice: ");
    scanf("%d", &ch);
    initgraph(&gd,&gm,NULL);

    int i;


    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    line(x[3],y[3],x[0],y[0]);
    line(x[0],y[0],x[8],y[8]);
    line(x[8],y[8],x[1],y[1]);


    //making the house 3D:
    line(x[1],y[1],x[5],y[5]);
    line(x[5],y[5],x[6],y[6]);
    line(x[6],y[6],x[2],y[2]);
    line(x[8],y[8],x[9],y[9]);
    line(x[9],y[9],x[5],y[5]);

    //dotted lines:
    setlinestyle(1,1,1);
    line(x[3],y[3],x[7],y[7]);
    line(x[7],y[7],x[6],y[6]);
    line(x[7],y[7],x[4],y[4]);
    line(x[4],y[4],x[5],y[5]);
    line(x[0],y[0],x[4],y[4]);
    line(x[4],y[4],x[9],y[9]);

    //reflection();
    if(ch==1)
      reflection();
    else
      shear();

    delay(5000);

}

void reflection()
{
    int i;

    for(i=0;i<10;i++)
        x[i] = reflectx + (reflectx - x[i]);

    setlinestyle(0,0,0);

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    line(x[3],y[3],x[0],y[0]);
    line(x[0],y[0],x[8],y[8]);
    line(x[8],y[8],x[1],y[1]);


    //making the house 3D:
    line(x[1],y[1],x[5],y[5]);
    line(x[5],y[5],x[6],y[6]);
    line(x[6],y[6],x[2],y[2]);
    line(x[8],y[8],x[9],y[9]);
    line(x[9],y[9],x[5],y[5]);

    //dotted lines:
    setlinestyle(1,1,1);
    line(x[3],y[3],x[7],y[7]);
    line(x[7],y[7],x[6],y[6]);
    line(x[7],y[7],x[4],y[4]);
    line(x[4],y[4],x[5],y[5]);
    line(x[0],y[0],x[4],y[4]);
    line(x[4],y[4],x[9],y[9]);

}


void shear()
{
    int i;


    for(i=0;i<10;i++)
        x[i] = x[i] + shearshift + shearx * y[i];

    setlinestyle(0,0,0);

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    line(x[3],y[3],x[0],y[0]);
    line(x[0],y[0],x[8],y[8]);
    line(x[8],y[8],x[1],y[1]);

    //making the house 3D:
    line(x[1],y[1],x[5],y[5]);
    line(x[5],y[5],x[6],y[6]);
    line(x[6],y[6],x[2],y[2]);
    line(x[8],y[8],x[9],y[9]);
    line(x[9],y[9],x[5],y[5]);

    //dotted lines:
    setlinestyle(1,1,1);
    line(x[3],y[3],x[7],y[7]);
    line(x[7],y[7],x[6],y[6]);
    line(x[7],y[7],x[4],y[4]);
    line(x[4],y[4],x[5],y[5]);
    line(x[0],y[0],x[4],y[4]);
    line(x[4],y[4],x[9],y[9]);


}
