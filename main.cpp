#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <winuser.h>
#include <fstream>

#include "headers/latex.h"
#include "headers/drawLatex.h"

using namespace std;

#define MAX1 20
#define MAX2 17
/*struct buton//Amalia
{
    int x,y;
    int ales=-1;
    char operatie[MAX1];
};
struct program//Amalia
{
    buton Butoane[MAX2];
    int marginLeft=50;
    int marginTop=25;
    int nrOfBoxes=13;
    int unit=5;
    int rez=2;
    int nrPoza=0;
    char img[MAX2]= {"img"};
};*/

// defined in latex.h

int window1;
void drawBox(int marginLeft,int marginTop,string content,program &latexCalculator)//Amalia
{
    rectangle(marginLeft,marginTop,marginLeft+8*latexCalculator.unit,marginTop+8*latexCalculator.unit);
}
void drawRoot(program &latexCalculator,int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit);
}
void drawAddition(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+7*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit);
}
void drawSubstraction(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
}
void drawMultiplication(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
}
void drawPower(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit);
    line(latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
}
void drawDivision(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
}
void drawLogarithm(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    outtextxy(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+2.5*latexCalculator.unit,"log");
    rectangle(latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+7*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);//box baza

}
void drawLn(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    outtextxy(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+2.5*latexCalculator.unit,"ln");
}
void drawLg(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    outtextxy(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+2.5*latexCalculator.unit,"lg");
}
void drawExponentiala(program &latexCalculator, int color)//x^a//Amalia
{
    outtextxy(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,"x");//55,40
    outtextxy(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,"^");
    rectangle(latexCalculator.marginLeft+4.5*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6.5*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
}
void drawScreenshot(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    rectangle(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+6.5*latexCalculator.unit,latexCalculator.marginTop+6.5*latexCalculator.unit);
    rectangle(latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6.5*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit);
    circle(latexCalculator.marginLeft+4.5*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,3);
}
void drawUpload(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit);
    line(latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit);
    line(latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit);
}
void drawDownload(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
    line(latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
    line(latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+4*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+7*latexCalculator.unit);
}


void drawUndo(program &latexCalculator, int color)//Amalia
{
    //outtextxy(latexCalculator.marginLeft+0.7*latexCalculator.unit,latexCalculator.marginTop+2.7*latexCalculator.unit,"Undo"); il face bold
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
}
void drawFraction(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    rectangle(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+4.5*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+6.5*latexCalculator.unit);
    line(latexCalculator.marginLeft+2.5*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+5.8*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    rectangle(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+1.5*latexCalculator.unit,latexCalculator.marginLeft+5*latexCalculator.unit,latexCalculator.marginTop+3.5*latexCalculator.unit);
}
void drawEqual(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2.5*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+5.8*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2.5*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+5.8*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit);
}
void drawNotEqual(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2.5*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+5.8*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2.5*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit,latexCalculator.marginLeft+5.8*latexCalculator.unit,latexCalculator.marginTop+5*latexCalculator.unit);
    line(latexCalculator.marginLeft+3*latexCalculator.unit,latexCalculator.marginTop+3*latexCalculator.unit,latexCalculator.marginLeft+5.5*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);
}
void drawBigger(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+5.2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
}
void drawSmaller(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+5.5*latexCalculator.unit);

}
void drawBiggerEqual(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+5.2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+6*latexCalculator.unit);

}
void drawSmallerEqual(program &latexCalculator, int color)//Amalia
{
    setcolor(color);
    line(latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+2*latexCalculator.unit,latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+4*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+5.5*latexCalculator.unit);
    line(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+6.2*latexCalculator.unit,latexCalculator.marginLeft+6*latexCalculator.unit,latexCalculator.marginTop+6.2*latexCalculator.unit);
}
void drawSin(program &latexCalculator,int color)//Amalia
{
    setcolor(color);
    outtextxy(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2.5*latexCalculator.unit,"sin");//Amalia
}
void drawCos(program &latexCalculator,int color)//Amalia
{
    setcolor(color);
    outtextxy(latexCalculator.marginLeft+2*latexCalculator.unit,latexCalculator.marginTop+2.5*latexCalculator.unit,"cos");
}
void desenareButoane1(program &latexCalculator,int &k)//Amalia
{
    drawRoot(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//2
    latexCalculator.marginLeft+=50;
    drawAddition(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//3
    latexCalculator.marginLeft+=50;
    drawSubstraction(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//4
    latexCalculator.marginLeft+=50;
    drawMultiplication(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//5
    latexCalculator.marginLeft+=50;
    drawLogarithm(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//6
    latexCalculator.marginLeft+=50;
    drawExponentiala(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//7
    latexCalculator.marginLeft+=50;
    drawFraction(latexCalculator,15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//10
    latexCalculator.marginLeft+=50;
    drawSin(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;//11
    latexCalculator.marginLeft+=50;
    drawCos(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;

}
void desenareButoane2(program &latexCalculator,int &k)//Amalia
{
    k++;
    drawUndo(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;
    latexCalculator.marginLeft+=50;
    drawScreenshot(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;
    latexCalculator.marginLeft+=50;
    drawUpload(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    k++;
    latexCalculator.marginLeft+=50;
    drawDownload(latexCalculator, 15);
    latexCalculator.Butoane[k].x=latexCalculator.marginLeft+20;
    latexCalculator.Butoane[k].y=latexCalculator.marginTop+20;
    latexCalculator.marginLeft=50;

}
void coordonate(int &x,int &y)
{
    bool click=false;
    int xMouse,yMouse;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex();
            yMouse=mousey();
            click=true;
        }
    while (!click);
    x=xMouse;
    y=yMouse;
}
void desenareChenare(program &latexCalculator,int a,int b,int c, int *topLeftX, int *topLeftY, int *bottomRightX, int *bottomRightY)//Amalia
{
    setfillstyle(SOLID_FILL,BLACK);

    *topLeftX=latexCalculator.marginLeft+latexCalculator.unit;
    *topLeftY=latexCalculator.marginTop+a*latexCalculator.unit;

    *bottomRightX=latexCalculator.marginLeft+b*latexCalculator.unit;
    *bottomRightY=latexCalculator.marginTop+c*latexCalculator.unit;

    bar(*topLeftX,*topLeftY,*bottomRightX,*bottomRightY);
    setcolor(MAGENTA);
    rectangle(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+a*latexCalculator.unit,latexCalculator.marginLeft+b*latexCalculator.unit,latexCalculator.marginTop+c*latexCalculator.unit);
    setcolor(WHITE);
}

void desenareChenare2(program &latexCalculator,int a,int b,int c, int *topLeftX, int *topLeftY, int *bottomRightX, int *bottomRightY)//Amalia
{
    setfillstyle(SOLID_FILL,BLACK);

    *topLeftX=latexCalculator.marginLeft+latexCalculator.unit;
    *topLeftY=latexCalculator.marginTop+a*latexCalculator.unit;

    *bottomRightX=latexCalculator.marginLeft+b*latexCalculator.unit;
    *bottomRightY=latexCalculator.marginTop+c*latexCalculator.unit;

    bar(*topLeftX,*topLeftY,*bottomRightX,*bottomRightY);

    setcolor(MAGENTA);
    rectangle(latexCalculator.marginLeft+latexCalculator.unit,latexCalculator.marginTop+a*latexCalculator.unit,latexCalculator.marginLeft+b*latexCalculator.unit,latexCalculator.marginTop+c*latexCalculator.unit);
    setcolor(WHITE);
}
void rezolutie(program &latexCalculator,int &x,int &y);
//void Latex(string s,int &ales,program &latexCalculator);

/*signed alegeButonMeniu(program &latexCalculator,int &x,int &y)//Amalia
{
    bool click=false;
    unsigned i,butonAles=0;
    int xMouse,yMouse;

        if (x!=-1 && y!=-1)
            xMouse=x; yMouse=y;
        {
            for (i=1; i<=MAX2; i++)
                if (abs(latexCalculator.Butoane[i].x - xMouse)<=20 && abs(latexCalculator.Butoane[i].y - yMouse)<=20 &&(xMouse<=(latexCalculator.Butoane[i].x+70)) && (yMouse<=(latexCalculator.Butoane[i].y+70)))
                {
                    butonAles=i;
                    click=true;
                }
            if(latexCalculator.rez==3)
            {
                if(xMouse > 5 && xMouse < 65 && yMouse > 5 && yMouse < 35)
                {
                    butonAles=0;
                    click=true;
                }
            }
            else if(latexCalculator.rez==2)
            {
                if(xMouse > 5 && xMouse < 75 && yMouse > 5 && yMouse < 35)
                {
                    butonAles=0;
                    click=true;
                }
            }
            else if(latexCalculator.rez==1)
            {
                if(xMouse > 5 && xMouse < 75 && yMouse > 5 && yMouse < 35)
                {
                    butonAles=0;
                    click=true;
                }
            }
        };
    return butonAles;
}*/

//defined in latex.h
void rezolutie(program &latexCalculator,int &x,int &y) //schimba rezolutia prin var x & y
{
    if(latexCalculator.rez==1)
    {
        x=1920;
        y=1080;
    }
    else if(latexCalculator.rez==2)
    {
        x=1280;
        y=720;
    }
    else if(latexCalculator.rez==3)
    {
        x=800;
        y=600;
    }
}

void screenshot(program &latexCalculator)//Amalia
{
    int x,y;
    char imagine[MAX2];
    if(latexCalculator.rez==1)
    {
        latexCalculator.nrPoza+=1;
        if(strlen(latexCalculator.img)==3)
            latexCalculator.img[strlen(latexCalculator.img)]=latexCalculator.nrPoza+'0';
        else if(strlen(latexCalculator.img)==4)
            latexCalculator.img[strlen(latexCalculator.img)-1]=latexCalculator.nrPoza+'0';
        strcpy(imagine,latexCalculator.img);
        strcat(imagine,".jpg");
        writeimagefile(imagine,5,500,1919,1079);
        setcolor(GREEN);
        rectangle(5,500,1919,1079);
    }
    else if(latexCalculator.rez==2)
    {
        latexCalculator.nrPoza+=1;
        if(strlen(latexCalculator.img)==3)
            latexCalculator.img[strlen(latexCalculator.img)]=latexCalculator.nrPoza+'0';
        else if(strlen(latexCalculator.img)==4)
            latexCalculator.img[strlen(latexCalculator.img)-1]=latexCalculator.nrPoza+'0';
        strcpy(imagine,latexCalculator.img);
        strcat(imagine,".jpg");
        writeimagefile(imagine,1,290,1279,719);
    }
    else if(latexCalculator.rez==3)
    {
        latexCalculator.nrPoza+=1;
        if(strlen(latexCalculator.img)==3)
            latexCalculator.img[strlen(latexCalculator.img)]=latexCalculator.nrPoza+'0';
        else if(strlen(latexCalculator.img)==4)
            latexCalculator.img[strlen(latexCalculator.img)-1]=latexCalculator.nrPoza+'0';
        strcpy(imagine,latexCalculator.img);
        strcat(imagine,".jpg");
        writeimagefile(imagine,5,290,799,599);
    }
}
int ButonMeniu(int &ales,program &latexCalculator,int &ok1, int inputX=-1, int inputY=-1)//Amalia
{
    string s;


    unsigned butonAles,nrPiesaAleasa;
    bool ok=1;
    if (ok1==1)
    {
        int xMouse=inputX,yMouse=inputY;
        butonAles=alegeButonMeniu(latexCalculator,xMouse,yMouse);

        if(butonAles==0)
        {
            if(latexCalculator.rez==3)
            {
                if(xMouse > 5 && xMouse < 65 && yMouse > 5 && yMouse < 35)
                {
                    //ok=0;
                    //ok1=0;
                    butonAles=-1;
                }
            }
            else if(latexCalculator.rez==2)
            {
                if(xMouse > 5 && xMouse < 75 && yMouse > 5 && yMouse < 35)
                {
                    //ok=0;
                    //ok1=0;
                    butonAles=-1;
                }
            }
            else if(latexCalculator.rez==1)
            {
                if(xMouse > 5 && xMouse < 75 && yMouse > 5 && yMouse < 35)
                {
                    //ok=0;
                    //ok1=0;
                    butonAles=-1;
                }
            }
        }
        else if(butonAles==ales)
        {
            setcolor(MAGENTA);
            drawBox(latexCalculator.Butoane[butonAles].x-20,latexCalculator.Butoane[butonAles].y-20,s,latexCalculator);
            ales=-1;
            setcolor(WHITE);

        }
        else
        {
            setcolor(MAGENTA);
            drawBox(latexCalculator.Butoane[ales].x-20,latexCalculator.Butoane[ales].y-20,s,latexCalculator);
            setcolor(GREEN);
            drawBox(latexCalculator.Butoane[butonAles].x-20,latexCalculator.Butoane[butonAles].y-20,s,latexCalculator);
            if(butonAles==11)
                screenshot(latexCalculator);
            ales=butonAles;
            setcolor(WHITE);
        }

    }
    return butonAles;
}


void desenareLatex(program &latexCalculator,int &ales)//Amalia && Habasescu
{
    string s;
    int xRes,yRes;
    int topLeftX=0, topLeftY=0, bottomRightX=0, bottomRightY=0;
    int upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY;

    rezolutie(latexCalculator,xRes,yRes);
    readimagefile("Resources/calculatorBackground.jpg",0,0,xRes,yRes);
    int k=1;

    if(latexCalculator.rez==1)
    {

        int a=40,b=140,c=120;
        latexCalculator.marginLeft=50;
        latexCalculator.marginTop=25;
        int cmarginLeft=latexCalculator.marginLeft+250;
        int cmarginTop=latexCalculator.marginTop+170;

        for(int i=1; i<=9; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,cmarginTop,s,latexCalculator);
            cmarginLeft+=50;
        }
        cmarginLeft=latexCalculator.marginLeft+250;
        cmarginTop+=50;
        for(int i=1; i<=4; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,cmarginTop,s,latexCalculator);
            cmarginLeft+=50;
        }
        cmarginTop-=50;
        latexCalculator.marginLeft+=250;
        latexCalculator.marginTop+=170;

        desenareButoane1(latexCalculator,k);

        latexCalculator.marginTop+=50;
        latexCalculator.marginLeft=300;

        desenareButoane2(latexCalculator,k);

        //latexCalculator.marginTop-=50;
        latexCalculator.marginLeft+=850;
        latexCalculator.marginTop-=350;

        desenareChenare(latexCalculator,a,b+30,c-10,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);

        upperTopLeftX=topLeftX;
        upperTopLeftY=topLeftY;
        upperBottomRightX=bottomRightX;
        upperBottomRightY=bottomRightY;

        latexCalculator.marginTop=300;
        latexCalculator.marginLeft=1;

        desenareChenare2(latexCalculator,a,b+400,c+50,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);

        latexCalculator.marginLeft=50;
        latexCalculator.marginTop=25;

        //Latex(s,ales,latexCalculator);
    }
    else if(latexCalculator.rez==2) {

        latexCalculator.marginLeft=50;
        latexCalculator.marginTop=25;
        int a=25,b=105,c=100;
        int cmarginLeft=latexCalculator.marginLeft;
        for(int i=1; i<=9; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,latexCalculator.marginTop+70,s,latexCalculator);
            cmarginLeft+=50;
        }
        cmarginLeft=latexCalculator.marginLeft;
        for(int i=1; i<=4; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,latexCalculator.marginTop+120,s,latexCalculator);
            cmarginLeft+=50;
        }
        cmarginLeft=latexCalculator.marginLeft;
        latexCalculator.marginTop+=70;

        desenareButoane1(latexCalculator,k);

        latexCalculator.marginTop-=70;
        latexCalculator.marginTop-=145;
        latexCalculator.marginTop+=265;
        latexCalculator.marginLeft=cmarginLeft;

        desenareButoane2(latexCalculator,k);

        latexCalculator.marginTop-=265;
        latexCalculator.marginLeft+=640;

        desenareChenare(latexCalculator,a,b+10,c-30,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);
        upperTopLeftX=topLeftX;
        upperTopLeftY=topLeftY;
        upperBottomRightX=bottomRightX;
        upperBottomRightY=bottomRightY;

        latexCalculator.marginLeft-=695;
        latexCalculator.marginTop+=235;

        desenareChenare2(latexCalculator,a+10,b+205,c+23,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);

        latexCalculator.marginLeft=50;
        latexCalculator.marginLeft=25;

        //Latex(s,ales,latexCalculator);

    }
    else if(latexCalculator.rez==3)
    {

        latexCalculator.marginLeft=50;
        latexCalculator.marginTop=25;
        int a=25,b=70,c=70;
        int cmarginLeft=latexCalculator.marginLeft+30;
        for(int i=1; i<=9; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,latexCalculator.marginTop,s,latexCalculator);
            cmarginLeft+=50;
        }
        cmarginLeft=latexCalculator.marginLeft+30;
        for(int i=1; i<=4; i++)
        {
            setcolor(MAGENTA);
            drawBox(cmarginLeft,latexCalculator.marginTop+50,s,latexCalculator);
            cmarginLeft+=50;
        }
        latexCalculator.marginLeft+=30;

        desenareButoane1(latexCalculator,k);
        latexCalculator.marginTop-=60;
        cmarginLeft=latexCalculator.marginLeft;
        latexCalculator.marginTop+=110;
        latexCalculator.marginLeft=80;
        desenareButoane2(latexCalculator,k);
        latexCalculator.marginTop-=60;
        desenareChenare(latexCalculator,a,b+70,c-18,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);

        upperTopLeftX=topLeftX;
        upperTopLeftY=topLeftY;
        upperBottomRightX=bottomRightX;
        upperBottomRightY=bottomRightY;

        //latexCalculator.marginLeft+=350;
        latexCalculator.marginLeft=1;
        latexCalculator.marginTop+=150;
        desenareChenare2(latexCalculator,a,b+90,c+20,&topLeftX,&topLeftY,&bottomRightX,&bottomRightY);
        latexCalculator.marginLeft=50;
        latexCalculator.marginLeft=25;
        //Latex(s,ales,latexCalculator);
    }

    int x,y,i,m,ok,button=0;

    char auxString[8][1024];

    string str,latexExpression;

    string formulaHistory[1024]; formulaHistory[0]=""; int stepCounter = 0;

    int keyboardKey;

    int editingPosition;

    int arrowClicked=0;

    string postfix;
    int errorCode=0;
    int exitCode=0;

    cout<<"running "<<topLeftX<<" "<<topLeftY<<endl;
    setcolor(WHITE);
while (keyboardKey!=27) {
    while (keyboardKey!=27) {

    if (exitCode==0) {
        x=0; y=0;
        keyboardKey=-1;
        if (kbhit()) {keyboardKey=getch(); cout<<"kbhit "<<keyboardKey<<endl;}
        getmouseclick(WM_LBUTTONDOWN,x,y);
        //cout<<ok<<endl;
        if (x!=-1 && y!=-1) {cout<<x<<" - "<<y<<endl; ok=1;} else ok=0;

        button = ButonMeniu(ales,latexCalculator,ok,x,y);

        if (button==12 || button==13) {
                drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
                cout<<"filename"<<endl;
                if (button%2==1) {
                        string fileName="";
                        string fileContent="";
                        char c;
                        char auxCharString[256];
                        int key=-1;
                        while(key!=13) {
                            outtextxy(upperTopLeftX+15,upperTopLeftY+25,"TYPE IN THE NAME OF THE .TXT FILE : ");
                            key=getch();
                            if (key!=8) {
                                drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
                                outtextxy(upperTopLeftX+15,upperTopLeftY+25,"TYPE IN THE NAME OF THE .TXT FILE : ");
                                c=key;
                                fileName=fileName+c;
                                strcpy(auxCharString,fileName.c_str());
                                outtextxy(upperTopLeftX+15,upperTopLeftY+50,auxCharString);
                            } else {
                                    drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
                                    outtextxy(upperTopLeftX+15,upperTopLeftY+25,"TYPE IN THE NAME OF THE .TXT FILE : ");
                                    if (fileName!="") {
                                            fileName.pop_back();
                                            strcpy(auxCharString,fileName.c_str());
                                    }
                                    outtextxy(upperTopLeftX+15,upperTopLeftY+50,auxCharString);
                                    }
                        cout<<"auxch = "<<auxCharString<<endl;

                        string name = auxCharString;
                        string line;
                        ifstream myfile (name);
                        if (myfile.is_open())
                        {
                            getline(myfile,line);
                            latexExpression=line;
                            myfile.close();
                        }

                    }
            } else {
                ofstream outputFile;
                outputFile.open ("export.txt");
                outputFile << latexExpression;
                outputFile.close();
                cout<<"successful outputted "<<latexExpression<<endl;
                outtextxy(upperTopLeftX+15,upperBottomRightY-25,"Successful Export, Press Enter to Proceed. . .");
                getch();
            }

        }

        buttonFunction(button,&latexExpression,formulaHistory,&stepCounter);

        if (x!=-1 && y!=-1) {
            drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
            parseLatexString(latexExpression,auxString);
            drawLatexExpression(auxString,upperTopLeftX,upperTopLeftY);
        }

            if (keyboardKey!=-1) {
                if (keyboardKey==0) {

                    latexExpression=editingMode(keyboardKey,upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY,&latexExpression,latexCalculator.marginLeft, latexCalculator.marginTop,
                                                latexCalculator.unit, 20 /*spacing*/, upperTopLeftX, upperTopLeftY, formulaHistory, &stepCounter, latexCalculator, button);
                } else {latexExpression=takeInput(latexExpression,keyboardKey);}
                stepCounter++; formulaHistory[stepCounter]=latexExpression;

                drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
                parseLatexString(latexExpression,auxString);
                drawLatexExpression(auxString,upperTopLeftX,upperTopLeftY);

            }
        if (keyboardKey==13) {
            int height = getwindowheight();
            drawTextBox(topLeftX,topLeftY,bottomRightX,bottomRightY);

            stackElement *top = new stackElement;
            top=NULL;


            postfix = infixToPostfix(latexExpression,&top,&errorCode,&exitCode); cout<<"postfix "<<postfix<<endl;

            if (postfix!="") {
                    if (postfix!="") {



                        node *tree = new node;
                        tree=NULL;
                        createExpressionTree(postfix,&tree, &exitCode);

                        int offset=0, paranths=0;
                        draw::assessExpression(tree,topLeftX+15,topLeftY+150,&offset,"",&paranths,&errorCode, &exitCode);


                    }


            }   else {

                cout<<"CLEAR"<<endl;
                drawTextBox(topLeftX,topLeftY,bottomRightX,bottomRightY);


            }
            throwError(topLeftX+15,bottomRightY-25,&errorCode);
            cout<<"errorCode "<<errorCode<<endl;
        }
        if (keyboardKey==127) {
        }
    } else {
        if (exitCode!=0) {
            cout<<"Exit Error"<<endl;
            string exitInfo = exitCodeHandler(exitCode);
            char exitInfoChar[256];
            strcpy(exitInfoChar,exitInfo.c_str());

            drawTextBox(upperTopLeftX,upperTopLeftY,upperBottomRightX,upperBottomRightY);
            outtextxy(upperTopLeftX+15,upperBottomRightY-25,exitInfoChar);

            exitCode=0;
        }
    }
    }
    }
}
//void Meniu(string s,int &ales,program &latexCalculator);
void Latex(int &ales,program &latexCalculator)
{
    int ok=1,ok1;
    while(1 && ok==1)
    {
        ButonMeniu(ales,latexCalculator,ok1);
        if(ok1==0)
            ok=0;
    }
    //cleardevice();
    int x,y;
    rezolutie(latexCalculator,x,y);
    readimagefile("Resources/loadingScreen.bmp",0,0,x,y);
    //Meniu(s,ales,latexCalculator);
}
void calculatorRezolutie(program &latexCalculator,int &ok,int x,int y)//Amalia
{
    if(latexCalculator.rez==1)
    {
        if(x>160 && x<380 && y>150 && y<250)
        {
            Beep(550, 1000);
            ok=0;
        }
        else if(x>400 && x<1550 && y>200 && y<400)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1920,1080);
            readimagefile("Resources/settings.bmp",0,0,1920,1080);
            latexCalculator.rez=1;

        }
        else if(x>400 && x<1550 && y>450 && y<600)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1280,720);
            readimagefile("Resources/settings.bmp",0,0,1280,720);
            latexCalculator.rez=2;
        }
        if(x>400 && x<1550 && y>630 && y<800)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(800,600);
            readimagefile("Resources/settings.bmp",0,0,800,600);
            latexCalculator.rez=3;
        }
    }
    else if(latexCalculator.rez==2)
    {
        if(x>100 && x<300 && y>100 && y<150)
        {
            Beep(550, 1000);
            ok=0;
        }
        else if(x>220 && x<1050 && y>150 && y<260)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1920,1080);
            readimagefile("Resources/settings.bmp",0,0,1920,1080);
            latexCalculator.rez=1;
        }
        else if(x>220 && x<1050 && y>280 && y<390)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1280,720);
            readimagefile("Resources/settings.bmp",0,0,1280,720);
            latexCalculator.rez=2;
        }
        if(x>220 && x<1050 && y>410 && y<520)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(800,600);
            readimagefile("Resources/settings.bmp",0,0,800,600);
            latexCalculator.rez=3;
        }
    }
    else if(latexCalculator.rez==3)
    {
        if(x>70 && x<160 && y>90 && y<140)
        {
            Beep(550, 1000);
            ok=0;
        }
        else if(x>170 && x<650 && y>130 && y<230)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1920,1080);
            readimagefile("Resources/settings.bmp",0,0,1920,1080);
            latexCalculator.rez=1;
        }
        else if(x>170 && x<650 && y>240 && y<340)
        {
            Beep(550, 1000);
            closegraph(window1);
            window1=initwindow(1280,720);
            readimagefile("Resources/settings.bmp",0,0,1280,720);
            latexCalculator.rez=2;
        }
        if(x>170 && x<650 && y>350 && y<450)
        {
            Beep(440, 100);
            closegraph(window1);
            window1=initwindow(800,600);
            readimagefile("Resources/settings.bmp",0,0,800,600);
            latexCalculator.rez=3;
        }
    }
}

void mouseHover(program &latexCalculator,int x,int y)//Amalia
{
    bool click=false;
    int ok=1;
    int xMouse,yMouse;
    while (ok==1)
    {
        getmouseclick(WM_MOUSEMOVE,xMouse,yMouse);
        if(latexCalculator.rez==1)
        {
            if(xMouse>740 && xMouse<1150 && yMouse>370 && yMouse<470)
            {
                readimagefile("Resources/Main/mainMenuStart.bmp",0,0,1920,1080);
                ok=0;
            }
            else if(xMouse>700 && xMouse<1170 && yMouse>480 && yMouse<580)
            {
                readimagefile("Resources/Main/mainMenuSettings.bmp",0,0,1920,1080);
                ok=0;
            }
            else if(xMouse>620 && xMouse<1260 && yMouse>590 && yMouse<690)
            {
                readimagefile("Resources/Main/mainMenuInfo",0,0,1920,1080);
                ok=0;
            }
            else if(xMouse>780 && xMouse<1120 && yMouse>700 && yMouse<790)
            {
                readimagefile("Resources/Main/mainMenuExit",0,0,1920,1080);
                ok=0;
            }
        }
        else if(latexCalculator.rez==2)
        {
            if(xMouse>500 && xMouse<760 && yMouse>250 && yMouse<320)
            {
                readimagefile("Resources/Main/mainMenuStart.bmp",0,0,1280,720);
                ok=0;
            }
            else if(xMouse>450 && xMouse<800 && yMouse>320 && yMouse<390)
            {
                readimagefile("Resources/Main/mainMenuSettings.bmp",0,0,1280,720);
                ok=0;
            }
            else if(xMouse>400 && xMouse<860 && yMouse>400 && yMouse<460)
            {
                readimagefile("Resources/Main/mainMenuInfo.bmp",0,0,1280,720);
                ok=0;
            }
            else if(xMouse>520 && xMouse<760 && yMouse>470 && yMouse<530)
            {
                readimagefile("Resources/Main/mainMenuExit.bmp",0,0,1280,720);
                ok=0;
            }
        }
        else if(latexCalculator.rez==3)
        {
            if(xMouse>170 && xMouse<650 && yMouse>210 && yMouse<260)
            {
                readimagefile("Resources/Main/mainMenuStart.bmp",0,0,800,600);
                ok=0;
            }
            else if(xMouse>170 && xMouse<650 && yMouse>270 && yMouse<320)
            {
                readimagefile("Resources/Main/mainMenuSettings.bmp",0,0,800,600);
                ok=0;
            }
            else if(xMouse>240 && xMouse<570 && yMouse>330 && yMouse<380)
            {
                readimagefile("Resources/Main/mainMenuInfo.bmp",0,0,800,600);
                ok=0;
            }
            else if(xMouse>170 && xMouse<650 && yMouse>390 && yMouse<440)
            {
                readimagefile("Resources/Main/mainMenuExit.bmp",0,0,800,600);
                ok=0;
            }
        }
    }
    x=xMouse;
    y=yMouse;

}

class ui {
    public:
static void Meniu(int &ales,program &latexCalculator)//Amalia
{
    int x,y,xRez,yRez;

    rezolutie(latexCalculator,x,y);
    readimagefile("Resources/mainMenu.bmp",0,0,x,y);
    int ok=1;
    while(1)
    {
        Beep(440, 100);

        coordonate(x,y);
        if(latexCalculator.rez==1)
        {
            mouseHover(latexCalculator,x,y);
            if(x>740 && x<1150 && y>370 && y<470)
            {
                /*setcolor(GREEN);
                rectangle(740,370,1150,470);*/
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",0,0,1920,1080);

                desenareLatex(latexCalculator,ales);
                readimagefile("Resources/mainMenu.bmp",0,0,1920,1080);
            }
            else if(x>700 && x<1170 && y>480 && y<580)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",1920,1080,x,y);

                readimagefile("Resources/settings.bmp",0,0,1920,1080);
//                coordonate(x,y);
                Ecran(ales,latexCalculator);
            }
            else if(x>620 && x<1260 && y>590 && y<690)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",1920,1080,x,y);

                readimagefile("Resources/information.bmp",0,0,1920,1080);
                ok=1;
                while(ok==1)
                {
                    if(GetAsyncKeyState(VK_ESCAPE))
                    {
                        Beep(550, 1000);
                        ok=0;
                    }
                }
                rezolutie(latexCalculator,x,y);
                readimagefile("Resources/mainMenu.bmp",0,0,x,y);
            }
            if(x>780 && x<1120 && y>700 && y<790)
            {
                exit(1);
            }
        }
        else if(latexCalculator.rez==2)
        {
            mouseHover(latexCalculator,x,y);
            if(x>500 && x<760 && y>250 && y<320)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",0,0,1280,720);

                desenareLatex(latexCalculator,ales);
                readimagefile("Resources/mainMenu.bmp",0,0,1280,720);
            }
            else if(x>450 && x<800 && y>320 && y<390)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",0,0,1280,720);

                readimagefile("Resources/settings.bmp",0,0,1280,720);
                coordonate(x,y);
                Ecran(ales,latexCalculator);
            }
            else if(x>400 && x<860 && y>400 && y<460)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",0,0,1280,720);

                readimagefile("Resources/information.bmp",0,0,1280,720);
                ok=1;
                while(ok==1)
                {
                    if(GetAsyncKeyState(VK_ESCAPE))
                    {
                        Beep(550, 1000);
                        ok=0;
                    }
                }
                rezolutie(latexCalculator,x,y);
                readimagefile("Resources/mainMenu.bmp",0,0,x,y);

            }
            else if(x>520 && x<760 && y>470 && y<530)
            {
                exit(1);
            }
        }
        else if(latexCalculator.rez==3)
        {
            mouseHover(latexCalculator,x,y);
            if(x>170 && x<650 && y>210 && y<260)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",800,600,x,y);

                desenareLatex(latexCalculator,ales);
                readimagefile("Resources/mainMenu.bmp",0,0,800,600);

            }
            else if(x>170 && x<650 && y>270 && y<320)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",800,600,x,y);

                readimagefile("Resources/settings.bmp",0,0,800,600);
                coordonate(x,y);
                Ecran(ales,latexCalculator);
            }
            else if(x>240 && x<570 && y>330 && y<380)
            {
                Beep(440, 100);
                readimagefile("Resources/loadingScreen.bmp",0,0,800,600);

                readimagefile("Resources/information.bmp",0,0,800,600);
                ok=1;
                while(ok==1)
                {
                    if(GetAsyncKeyState(VK_ESCAPE))
                    {
                        Beep(550, 1000);
                        ok=0;
                    }
                }
                rezolutie(latexCalculator,x,y);
                readimagefile("Resources/mainMenu.bmp",0,0,x,y);
            }
            if(x>170 && x<650 && y>390 && y<440)
            {
                exit(1);
            }
        }

    }
}

static void Ecran(int &ales,program &latexCalculator)//Amalia
{
    int ok=1,x,y;
    coordonate(x,y);
    while(1&&ok==1)
    {
        calculatorRezolutie(latexCalculator,ok,x,y);
        if(ok==1)
            coordonate(x,y);
    }
    Meniu(ales,latexCalculator);

}
};

int main()
{
    program latexCalculator;
    int x,y;
        rezolutie(latexCalculator,x,y);
        window1=initwindow(x,y,"UI Test");
        readimagefile("Resources/loadingScreen.bmp",0,0,1280,720);

    int k=1, spacing = 15, numarButoane=11, ales=-1;
    buton Butoane[MAX2];
    string s;
    int spaces, boxes;

        readimagefile("Resources/mainMenu.bmp",0,0,1280,720);
        ui::Meniu(ales,latexCalculator);
        Latex(ales,latexCalculator);
        char baza[3], exponent[3], numitor[3];

    getch();
    closegraph();
    return 0;
}
