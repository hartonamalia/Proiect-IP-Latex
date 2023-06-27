#include <iostream>
using namespace std;


#define MAX1 20
#define MAX2 17

struct buton//Amalia
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
};

class latex {//Habasescu
public:

};
    int eventListener(int x, int y, int x1, int y1, int inputX, int inputY) { //2 opposing corners coordinates + mouse click input
    int returnValue=0;
    int modulX = abs(x-x1);
    int modulY = abs(y-y1);


    int valueX, valueY;
    if (x>x1) {valueX=inputX-x1;} else {valueX=inputX-x;};
    if (y>y1) {valueY=inputY-y1;} else {valueY=inputY-y;};

    if ((valueX>=0 && valueX<modulX) && (valueY>=0 && valueY<modulY)) {returnValue=1;}
    return returnValue;
}


////////////////////////////////// U I    E L E M E N T S //////////////////////////////////

void drawLatexBox(int x,int y) {//Habasescu
    rectangle(x-300,y-100,x+300,y+100);
}

void drawLatexExpression(char stringArray[8][1024],int x, int y) {//Habasescu
    for (int i=0; i<8; i++) {
        outtextxy(x+15,y+15+i*20,stringArray[i]);
    }
}

//////////////////////////////////// F U N C T I O N S ////////////////////////////////////

string keyboardInput(string input, int tasta) {//Habasescu
    char c;
    if ((tasta>=32 && tasta<=66) || (tasta>=91 && tasta<=125)) {
            c=tasta; input=input+c;
    } else if (tasta==8 && input.length()>0) {input.pop_back();input[input.length()]='\0';}
    cout<<tasta<<endl;
    cout<<"kbinput "<<input<<endl;
    return input;
}

string takeInput(string input, int tasta) {//Habasescu
    char str[1024];
    //if (tasta!=27 && tasta!=13) {
        input = keyboardInput(input,tasta); cout<<input<<endl;
        for (int i=0; i<input.length();i++) {str[i]=input[i]; str[i+1]='\0';}
    //};
    return input;
}

int positionOffset(int order, int unit, int spacing) {//Habasescu
    return spacing*order+8*unit*order;
}



//////////////////// E D I T I N G ////////////////////

void clearStringArray(char stringArray[8][1024]) {//Habasescu
    for (int i=0; i<8;i++) {
        for (int j=0;j<1024;j++) {
            stringArray[i][j]=' ';
        }
    }
}

void parseLatexString(string latexExpression,char stringArray[8][1024]) {//Habasescu
    int i, lengthTotal=0;
    int offset=0;
    char auxStr[1024];
    string auxLatex="";
    int lineCounter=0; for (int i=0; i<8; i++) {stringArray[i][0]='\0';}
            for (i=0; i<latexExpression.length(); i++) {
                //lengthTotal=textwidth(latexExpression); cout<<"len = "<<lengthTotal<<endl;

                strcpy(auxStr,auxLatex.c_str());
                if (textwidth(auxStr)/450>=1) {lineCounter++;offset=i; auxLatex="";};

                stringArray[lineCounter][i-offset]=latexExpression[i];
                auxLatex+=latexExpression[i];
            }; stringArray[lineCounter][i-offset]='\0';
}

int arrowClick(int click) {//Habasescu
    int aux;
    int boolean=0;
    if (!click) {
        switch(aux=getch()){
            case KEY_LEFT : boolean=1;  break;
            case KEY_RIGHT : boolean=2;  break;
            default : boolean=aux; break;
        } //cout<<"aux "<<aux<<endl;
    }
    return boolean;
}

//////////////////// E V E N T S //////////////////////



void drawTextBox(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {//Habasescu
    int aux=getcolor();
    setfillstyle(SOLID_FILL,BLACK);
    bar(topLeftX,topLeftY,bottomRightX,bottomRightY);
    setcolor(MAGENTA);
    rectangle(topLeftX,topLeftY,bottomRightX,bottomRightY);
    setcolor(aux);
    cout<<"drewBox "<<topLeftX<<" "<<bottomRightX<<endl;;

}

void buttonFunction(int button, string *latexExpression, string formulaHistory[1024], int *stepCounter) {//Habasescu
    switch(button) {
        case 1 : *latexExpression+="sqrt[]{}"; break;
        case 2 : *latexExpression+="+"; break;
        case 3 : *latexExpression+="-"; break;
        case 4 : *latexExpression+="*"; break;
        case 5 : *latexExpression+="log[]{}"; break;
        case 6 : *latexExpression+="^{}"; break;
        case 7 : *latexExpression+="frac{}{}"; break;
        case 8 : *latexExpression+="sin[]"; break;
        case 9 : *latexExpression+="cos[]"; break;
        case 10 : if ((*stepCounter)-1>-1) {
                        (*latexExpression)=formulaHistory[(*stepCounter)-1];
                        formulaHistory[*stepCounter]="";
                        (*stepCounter)--;
                    } else if ((*stepCounter)-1==-1) {(*latexExpression)=formulaHistory[0];
                } break;
    }
}

unsigned alegeButonMeniu(program &latexCalculator,int &x,int &y)//Amalia
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
}

string editingMode(int charID, int topX, int topY, int bottomX, int bottomY,string *input, int marginLeft, int marginTop, int unit, int spacing, int latexBoxX, int latexBoxY,
                   string formulaHistory[1024], int *stepCounter, program latexCalculator, int button=0) {//Habasescu
    int x1, y1;
    int arrowClicked=0;
    textsettingstype textSettings;
    char stringArray[8][1024];
    string auxString; //char k[1024];
    int position=(*input).length();
    int arrow;
    int interact=0, click=0, kb=0;
    int lengthOffset=0;

    cout<<"coords "<<topX<<" "<<topY<<" "<<bottomX<<" "<<bottomY<<endl;

    while (charID!=13 && charID!=27) {
        if (charID==0) {
                arrow=arrowClick(charID);
                if (arrow==1) {if (position>0) {position--;}} else
                    if (arrow==2) { if (position<(*input).length()) {position++;}} else {
                        }

                auxString=(*input).substr(0,position); int lengthOffset=auxString.length();
                //getmouseclick(WM_LBUTTONDOWN,x1,y1);
                //operationListeners(x1,y1,&auxString, marginLeft, marginTop, unit, spacing, latexBoxX, latexBoxY, formulaHistory, stepCounter);

                lengthOffset=auxString.length()-lengthOffset;
                auxString=auxString+"_"+(*input).substr(position+lengthOffset,(*input).length());
                position=position+lengthOffset;

                //cleardevice();
                drawTextBox(topX,topY,bottomX,bottomY);
                outtextxy(topX+15,bottomY-25,"EDITING MODE");
                clearStringArray(stringArray);

                parseLatexString(auxString,stringArray);

                drawLatexExpression(stringArray,topX,topY);
                //drawFunctionMenu(marginLeft,marginTop,unit,spacing);
                if (click) {charID=getch();};
                interact=0; click=0; kb=0;
                while (interact==0) {
                    Sleep(100);
                    if (kbhit()) {
                        kb=1;
                    } else if (ismouseclick(WM_LBUTTONDOWN)) {
                        click=1;
                        getmouseclick(WM_LBUTTONDOWN,x1,y1);
                    }

                    interact=kb+click;
                }

                if (kb) {charID=getch();
                } else
                if (click) {
                    auxString=(*input).substr(0,position);
                    lengthOffset=auxString.length();
                    button=alegeButonMeniu(latexCalculator,x1,y1); cout<<"button "<<button<<endl;
                    buttonFunction(button,&auxString,formulaHistory,stepCounter);

                    lengthOffset=auxString.length()-lengthOffset;

                    (*input)=(*input).substr(position,(*input).length());

                    position=position+lengthOffset;
                    string valueHolder=(*input);
                    (*input)=auxString+(*input);
                    auxString=auxString+"_"+valueHolder;

                    drawTextBox(topX,topY,bottomX,bottomY);
                    outtextxy(topX+15,bottomY-25,"EDITING MODE");
                    clearStringArray(stringArray);
                    parseLatexString(auxString,stringArray);
                    drawLatexExpression(stringArray,topX,topY);
                }

        } else {
            auxString=(*input).substr(0,position); int lengthOffset=auxString.length();
            int ogPosition=position;

            lengthOffset=auxString.length()-lengthOffset;
            (*input)=auxString+(*input).substr(position,(*input).length());

            auxString=takeInput(auxString,charID);

            position=position+lengthOffset;
            if (charID==8) {if (position!=0) {position--;}} else {position++;}

            *input=auxString+(*input).substr(ogPosition,(*input).length());
            auxString=auxString+"_"+(*input).substr(position,(*input).length());

            drawTextBox(topX,topY,bottomX,bottomY);
            outtextxy(topX+15,bottomY-25,"EDITING MODE");

            parseLatexString(auxString,stringArray);

            drawLatexExpression(stringArray,topX,topY);

            charID=getch();

            clearStringArray(stringArray);
        }
    }
    return (*input);
}



