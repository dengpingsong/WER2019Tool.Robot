#include "ASEIO.h"
#include "wpc.h"

#define true 1
#define false 0

#define POS1 0
#define POS2 1
#define POS3 2

#define HIGH1 3
#define HIGH2 4
#define HIGH3 5

int pos=1;
int nowPos=1;
int nowX=2;
int nowY=1;
int targetX;
int targetY;
int path;//false:left  true:right
int height;//false:down  true:up
int moveX,moveY;

void calcMove(int target)
{
    switch(target%3)
    {
        case 0:targetX=1;break;
        case 1:targetX=2;break;
        case 2:targetX=3;break;
    }
    targetY=target/3+1;
    //=======X==========
    if(targetX>=nowX)
    {
        path=true;
        moveX=targetX-nowX;
    }
    else
    {
        path=false;
        moveX=nowX-targetX;
    }
    //========End of X==========
    if(targetY>=nowY)
    {
        height=true;
        moveY=targetY-nowY;
        printf("input:%d\ntargetX:%d,Y:%d\nI'm in height true",target,targetX,targetY);
    }
    else
    {
        height=false;
        moveY=nowY-targetY;
        printf("intput:%d\ntargetX:%d,Y:%d\nI'm in height false",target,targetX,targetY);
    }

}

void operating(int sender,int target)
{
    //==========move to sender
    calcMove(sender);
    if(path)//right
    {
        if(height)
        {
            //righthigh
            printf("Right High send");
        }
        else
        {
            //rightlow
            printf("Right Low send");
        }
    }
    else//left
    {
        if(height)
        {
            //lefthigh
            printf("Left High send");
        }
        else
        {
            //leftdown
            printf("Left Down send");
        }
    }
    //==========move to target
    calcMove(target);
    if(path)//right
    {
        if(height)
        {
            //righthigh
            printf("tar Right High");
        }
        else
        {
            //rightlow
            printf("tar Right Low");
        }
    }
    else//left
    {
        if(height)
        {
            //lefthigh
            
            printf("tar Left High");
        }
        else
        {
            //leftdown
            printf("tar Left Down");
        }
    }
}

void main()
{
	operating(6,4);
}

//2013DUODUOProgramAA0905