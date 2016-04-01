#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{

    //Setting the coordinates
    int x=400, y=400, r=100;
    int circle[400][400] = {0}, circle2[400][400]={0};
    int alias_flag=1;
    int i, j;


    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            circle[i][j]=255, circle2[i][j]=255;


    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            if((int)sqrt(pow(i-x/2,2) + pow(j-y/2,2)) == r)
                circle[i][j]=0, circle2[i][j]=0;

   //Applying antialiasing techniques
    if(alias_flag)
    {
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            if(circle2[i][j]!=255)
                circle2[i][j] = circle[i][j] / 2 + circle[i+1][j]/16 + circle[i-1][j]/16 + circle[i][j-1]/16 + circle[i][j+1]/16 + circle[i-1][j-1]/16 + circle[i-1][j+1]/16 + circle[i+1][j-1]/16 + circle[i+1][j+1]/16  ;
    }


    int gd = DETECT, gm = DETECT;
	initgraph(&gd, &gm, "");


  //Drawing the initial cirlce
	for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(circle[i][j]==0)
                putpixel(i,j,BLUE);
            else
                putpixel(i,j,BLACK);
        }
        printf("\n");
    }


    //Drawing the smoothened circle
    int flag=0;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(circle2[i][j]==255)
                putpixel(i,j,BLACK);
            else if(circle2[i][j]==0)
                putpixel(i,j,WHITE);
            else if (circle2[i][j]<80)
                putpixel(i,j,8);
            else if (circle2[i][j]<255)
                {putpixel(i,j,7);flag=1;}
        }
    }


    delay(5000);
    closegraph();
    if(flag)
        printf("flag enabled");
    return 0;

}
