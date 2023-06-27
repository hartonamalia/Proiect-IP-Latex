#include <iostream>
using namespace std;

class drawLatex { //Habasescu
public:
    string curlyBrackets();

};
    string curlyBrackets(string input, int *exitCode) { //returns string within curly brackets
    string output;
    int open=0,close=0,i=0;
    int positionOpen=0, positionClose=0;
    input="bugFix"+input;

    while (!open && i!=input.length()+1) {
        if (input[i]=='{') {
            positionOpen=i;
            open=1;
        }
        i++;
    }

    i=positionOpen;
    while (open!=close && i!=input.length()) {
        i++;
        if (input[i]=='{') {open++;};
        if (input[i]=='}') {close++;};
    }

    if (i<(input.length())) {positionClose=i;}

    if (positionOpen && positionClose) {output=input.substr(positionOpen+1,positionClose-positionOpen-1);}
    if (positionClose==0) {output="ERROR : NO CLOSING CURLY BRACKETS DETECTED IN : "+input; *exitCode=6;};
    if (positionOpen==0) {output="ERROR : NO OPENING CURLY BRACKETS DETECTED IN : "+input; *exitCode=6;};

    return output;
}

string brackets(string input, int *exitCode) { //returns string within curly brackets //Habasescu
    string output;
    int open=0,close=0,i=0;
    int positionOpen=0, positionClose=0;
    input="bugFix"+input; //important, don't delete

    while (!open && i!=input.length()+1) {
        if (input[i]=='[') {
            positionOpen=i;
            open=1;
        }
        i++;
    }

    i=positionOpen;
    while (open!=close && i!=input.length()) {
        i++;
        if (input[i]=='[') {open++;};
        if (input[i]==']') {close++;};
    }

    if (i<(input.length())) {positionClose=i;}

    if (positionOpen && positionClose) {output=input.substr(positionOpen+1,positionClose-positionOpen-1);}
    if (positionClose==0) {output="ERROR : NO CLOSING BRACKETS DETECTED IN : "+input; *exitCode=6;};
    if (positionOpen==0) {output="ERROR : NO OPENING BRACKETS DETECTED IN : "+input; *exitCode=6;};

    return output;
}

struct stackElement {//Habasescu
    string inf;
    stackElement* previous;
};


void pop(stackElement **top) {//Habasescu
    if (top!=NULL) {
        stackElement *aux = new stackElement;
        aux=*top;
        *top=(*top)->previous;
        delete aux;
    }
}

void push(stackElement **top, string info) {//Habasescu
    stackElement *elem = new stackElement;
    elem->inf=info;
    elem->previous=*top;
    *top=elem;
}

string topElement(stackElement *top) {//Habasescu
    return (*top).inf;
}

int isOperator(char c) {
    int output=0;

    if (c=='+' || c=='-' || c=='*'|| c=='/'|| c=='^') {
        output=1;
    }
    return output;
}

int precedence(string s) {//Habasescu
    int output;
    if (s=="+") {output=1;} else
        if (s=="-") {output=1;} else
            if (s=="*") {output=2;} else
                if (s=="/") {output=2;} else
                    if (s=="^") {output=3;} else {
                    output=-1;
                }

    return output;
}

int isEmpty(stackElement *top) {//Habasescu
    int output=0;
    if (top==NULL) {
        output=1;
    }
    return output;
}
struct node{//Habasescu
    string inf;
    node* leftNode;
    node*  rightNode;
};

void createNode(string input, node **n) {//Habasescu
    (*n)->inf=input;
    (*n)->leftNode=NULL;
    (*n)->rightNode=NULL;
}

struct nodeStackElement{//Habasescu
    node *element;
    nodeStackElement *previous;
};

void nodeStackPush(node *element,nodeStackElement **top) {//Habasescu
    nodeStackElement *last = new nodeStackElement;
    last->previous=(*top);
    last->element=element;
    (*top)=last;
}

void nodeStackPop(nodeStackElement **top) {//Habasescu
    if(top!=NULL) {
        nodeStackElement *aux = new nodeStackElement;
        aux=(*top);
        *top=(*top)->previous;
        delete aux;
    }
}

int isNumber(string input) {//Habasescu
    int output=1;
    for (int i=0; i<input.length(); i++) {
        if ((input[i]<'0' || input[i]>'9') && input[i]!='-' && input[i]!='*' && input[i]!='+' && input[i]!='/' && input[i]!='(' && input[i]!=')') {
            output=0;
            break;
        }
    }

    return output;
}

int logErrorHandler(string order, string value) {//Habasescu
    int output=0;

    if (isNumber(order)) {
        if (stoi(order)<=0 || stoi(order)==1) {
            output=1;
        }
    }

    if (isNumber(value)) {
        if (stoi(value)<=0) {
            output=1;
        }
    }

    return output;
}

int fracErrorHandler(string sub) {//Habasescu
    int output=0;

    if (sub=="0") {
        output=1;
    }

    return output;
}

int sqrtErrorHandler(string order, string value)  {//Habasescu
    int output=0;
    int odd=0;
    cout<<"order "<<order<<endl;

    if (isNumber(order)) {
        if (stoi(order)==1 || stoi(order)<=0) {
            output=1;
        }
    }

    if (isNumber(value)) {
        if (stoi(value)<=0) {
            output=1;
        }
    }
    return output;
}

void throwError(int x, int y, int *errorCode) {//Habasescu
    //log=2 sqrt=3 frac=4
    if (*errorCode==1) {
        outtextxy(x,y-50,"Error Code 1 : Missing Paranths");
        *errorCode=0;
    } else if (*errorCode==2) {
        outtextxy(x,y-50,"Error Code 2 : Invalid Logarithm Input Values");
        *errorCode=0;
    } else if (*errorCode==3) {
        outtextxy(x,y-50,"Error Code 3 : Invalid SQRT Input Values");
        *errorCode=0;
    } if (*errorCode==4) {
        outtextxy(x,y-50,"Error Code 4 : Invalid Fraction Denominator (=0?)");
        *errorCode=0;
    }
}

string exitCodeHandler(int code) {//Habasescu
    string error="";

    if (code==1) {
        error="EXIT ERROR CODE 1 : LOG Has No Value Or Order";
    } else if (code==2) {
        error="EXIT ERROR CODE 2 : SQRT Has No Value Or Order";
    } else if (code==3) {
        error="EXIT ERROR CODE 3 : FRAC Has A Missing Value";
    } else if (code==4) {
        error="EXIT ERROR CODE 4 : SIN Has No Value";
    } else if (code==5) {
        error="EXIT ERROR CODE 5 : COS Has No Value";
    } else if (code==6) {
        error="EXIT ERROR CODE 6 : Missing Parantheses";
    }

    return error;
}

string infixToPostfix(string input, stackElement **top, int *errorCode, int *exitCode) {//Habasescu
    string output,aux;
    for(int i=0;i<input.length();i++) {
        if ((input[i]>='a' && input[i]<='z')||((input[i])>='A' && input[i]<='Z') || ((input[i]>='0' && input[i]<='9') || input[i]=='.')) {
            cout<<"draw running"<<endl;
                if (i<input.length()-3 && (input.substr(i,3)=="log")) {
                    input.erase(i,3);
                    string order = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-order.length()-2)) {input.erase(i,order.length()+2);};
                    string value = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-value.length())) {input.erase(i,value.length()+1);};

                if (order!="" && value != "") {
                    if (logErrorHandler(order,value)) {
                        if (*errorCode==0){*errorCode=2;};
                        output=output+"log["+order+"]{"+value+"}"; //cout<<input<<endl;
                    } else output=output+"log["+order+"]{"+value+"}"; //cout<<input<<endl;
                } else {*exitCode=1;}

                } else if (i<input.length()-4 && (input.substr(i,4)=="sqrt")) {
                    input.erase(i,4);
                    string order = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-order.length()-2)) {input.erase(i,order.length()+2);};
                    string value = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-value.length())) {input.erase(i,value.length()+1);};

                    if (order!="" && value != "") {
                        if (sqrtErrorHandler(order,value)) {
                            if (*errorCode==0){*errorCode=3;};
                            output=output+"sqrt["+order+"]{"+value+"}";
                        } else output=output+"sqrt["+order+"]{"+value+"}";
                    } else {*exitCode=2;}

                } else if (i<input.length()-4 && (input.substr(i,4)=="frac")) {
                    input.erase(i,4);
                    string topFrac = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-topFrac.length()-2)) {input.erase(i,topFrac.length()+2);};
                    string bottomFrac = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-bottomFrac.length())) {input.erase(i,bottomFrac.length()+1);};

                if (topFrac!="" && bottomFrac!= "") {
                    if (fracErrorHandler(bottomFrac)) {
                        if (*errorCode==0){*errorCode=4;};
                        output=output+"frac{"+topFrac+"}{"+bottomFrac+"}";
                    } else output=output+"frac{"+topFrac+"}{"+bottomFrac+"}";
                } else {*exitCode=3;}

                }else if (i<input.length()-3 && (input.substr(i,3)=="sin")) {
                    input.erase(i,3);
                    string value = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-value.length())) {input.erase(i,value.length()+1);};
                if (value!="") {
                    output=output+"sin["+value+"]"; //cout<<input<<endl;
                } else {*exitCode=4;}
                } else if (i<input.length()-3 && (input.substr(i,3)=="cos")) {
                    input.erase(i,3);
                    string value = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-value.length())) {input.erase(i,value.length()+1);};
                if (value!="") {
                    output=output+"cos["+value+"]"; //cout<<input<<endl;
                } else {*exitCode=5;}

                } else {
                    output=output+input[i];
                    if (i<input.length() && ((input[i]>='0' && input[i]<='9')|| input[i]=='.')) {
                        if((input[i+1]<'0' || input[i+1]>'9') && input[i+1]!='.') {
                            if (input[i]=='.') {
                                    output=output+'.';
                            }
                            output=output+'$';
                        }
                    }
                }

                }
            else if(input[i]=='(') {push(top,input.substr(i,1));}
                else if(input[i]==')') {
                    while(!isEmpty(*top) && (*top)->inf!="(") {
                        output=output+(*top)->inf;
                        if(top!=NULL) {pop(top);}
                    }
                    if ((*top)->inf=="(") {
                        pop(top);
                    }
                 }
                else if (isOperator(input[i])) {
                            if(top==NULL) {push(top,input.substr(i,1));}
                                else {

                                    if(!isEmpty(*top) && (precedence(input.substr(i,1))>precedence((*top)->inf))) {

                                        push(top,input.substr(i,1));
                                    }
                                    else if(!isEmpty(*top) && (precedence(input.substr(i,1))==precedence((*top)->inf))&&input[i]=='^') {
                                        push(top,input.substr(i,1));
                                    } else {
                                    while(!isEmpty(*top) &&(precedence(input.substr(i,1))<=precedence((*top)->inf))) {
                                        output=output+(*top)->inf;
                                        pop(top);
                                    };
                                    push(top,input.substr(i,1));
                                }

                }}
    }

    if (*exitCode==0) {
    while(!isEmpty(*top)){
        output=output+(*top)->inf;
        pop(top);
    }
}

    /*for(int i=0;i<output.length();i++) {
        if(output[i]!='(') {
            aux=aux+output[i];
           }
    }*/
    //output=aux;

    return output;
}

void createExpressionTree(string input, node** top,int *exitCode) {//Habasescu
    nodeStackElement *topStack = NULL;
if (*exitCode==0) {
    for (int i=0; i<input.length();i++) {
        if ((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9')) {
            if ((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')) {
                if (i<input.length()-3 && (input.substr(i,3)=="log")) {
                    input.erase(i,3);
                    string order = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-order.length()-2)) {input.erase(i,order.length()+2);};
                    string value = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<=(input.length()-value.length()-2)) {input.erase(i,value.length()+1);};

                    string aux="log["+order+"]{"+value+"}";

                    node *auxNode = new node;
                    createNode(aux,&auxNode);
                    nodeStackPush(auxNode,&topStack); //cout<<"topstack"<<topStack->element->inf<<endl;
                } else if (i<input.length()-3 && (input.substr(i,4)=="sqrt")) {
                    input.erase(i,3);
                    string order = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-order.length()-2)) {input.erase(i,order.length()+2);};
                    string value = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<=(input.length()-value.length()-2)) {input.erase(i,value.length()+1);};

                    string aux="sqrt["+order+"]{"+value+"}";

                    node *auxNode = new node;
                    createNode(aux,&auxNode);
                    nodeStackPush(auxNode,&topStack); //cout<<topStack->element->inf<<endl;
                } else if (i<input.length()-3 && (input.substr(i,4)=="frac")) {
                    input.erase(i,3);
                    string topFrac = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<(input.length()-topFrac.length()-2)) {input.erase(i,topFrac.length()+2);};
                    string bottomFrac = curlyBrackets(input.substr(i,input.length()-i),exitCode);
                        if(i<=(input.length()-bottomFrac.length()-2)) {input.erase(i,bottomFrac.length()+1);};

                    string aux="frac{"+topFrac+"}{"+bottomFrac+"}";

                    node *auxNode = new node;
                    createNode(aux,&auxNode);
                    nodeStackPush(auxNode,&topStack); //cout<<topStack->element->inf<<endl;
                } else if (i<input.length()-3 && (input.substr(i,3)=="sin")) {
                    input.erase(i,3);
                    string value = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<=(input.length()-value.length()-2)) {input.erase(i,value.length()+1);};

                    string aux="sin["+value+"]";

                    node *auxNode = new node;
                    createNode(aux,&auxNode);
                    nodeStackPush(auxNode,&topStack); //cout<<topStack->element->inf<<endl;
                } else if (i<input.length()-3 && (input.substr(i,3)=="cos")) {
                    input.erase(i,3);
                    string value = brackets(input.substr(i,input.length()-i),exitCode);
                        if(i<=(input.length()-value.length()-2)) {input.erase(i,value.length()+1);};

                    string aux="cos["+value+"]";

                    node *auxNode = new node;
                    createNode(aux,&auxNode);
                    nodeStackPush(auxNode,&topStack); //cout<<topStack->element->inf<<endl;
                } else {
                    node *auxNode = new node;
                    createNode(input.substr(i,1),&auxNode); //plain letters
                    nodeStackPush(auxNode,&topStack);
                }
            } else {
                int j=i;
                while((input[j]>='0' && input[j]<='9') || input[j]=='.') {
                    j++;
                }
                node *auxNode = new node;
                createNode(input.substr(i,j-i),&auxNode);
                i=j-1;
                nodeStackPush(auxNode,&topStack);
            }
        } else if (isOperator(input[i])) {
            node *auxNode = new node;
            auxNode->inf=input.substr(i,1);

            auxNode->rightNode=topStack->element;
            nodeStackPop(&topStack);

            auxNode->leftNode=topStack->element;
            nodeStackPop(&topStack);

            nodeStackPush(auxNode,&topStack);
        }
    }
    (*top)=topStack->element;
    }
}

void inorder(node *top) {
    if (top->leftNode!=NULL) {inorder(top->leftNode);};
    cout<<top->inf<<endl;
    if (top->rightNode!=NULL) {inorder(top->rightNode);};
}

void inorderMaxHeight(node *top, int value, int *maxValue) {//Habasescu
        if (top->inf=="^") {value+=10;} else
            if ((top->inf.length()>4) && (top->inf.substr(0,4)=="frac")) {
                //int aux = calcHeightBottom(top->inf);
                value+=15;
            } else if (top->inf.length()>3 && top->inf.substr(0,3)=="log") {
                value+=5;
            }

        if (top->leftNode!=NULL) {inorderMaxHeight(top->leftNode,value,maxValue);};
        cout<<top->inf<<endl;
        if (top->rightNode!=NULL) {inorderMaxHeight(top->rightNode,value,maxValue);};
        if (top->leftNode==NULL && top->leftNode==NULL) {
            if ((*maxValue)<value) {
                *maxValue=value;
            }
        }
    }

int calcHeightBottom(string input, int *exitCode) {//Habasescu
        int output=0;
        node *tree = new node;
        tree=NULL;

        stackElement *top = new stackElement;
        top=NULL;

        int errorCode=0;
        string postfix = infixToPostfix(input,&top, &errorCode, exitCode);

    if (*exitCode==0) {
        createExpressionTree(postfix,&tree,exitCode);

        int maxHeight=0;
        inorderMaxHeight(tree,10,&maxHeight);

        //cout<<"CALC "<<maxHeight<<endl;

        output=maxHeight;

        return output;
        }
    }

int calcHeight(string input) {//Habasescu
    int output=0;
    for (int i=0;i<input.length();i++) {
        if (i<input.length()-4 && input.substr(i,4)=="frac") {
            output+=15;
        }
        if (input[i]=='^') {output+=10;};
    }

    return output;
}

class draw {//Habasescu
    public :
    static void drawExpression(string input, int posX, int posY, int* offset, int *errorCode, int *exitCode, int mode = 0){
        //cout<<"MODE = "<<mode<<endl;
        cout<< "draw "<<input<<endl;
    if (*exitCode==0) {
        int *heightoffset=0;
        if (input=="*") {
            circle(posX+(*offset)+3,posY+7,2);
            (*offset)+=5;
        } else if (input=="+") {
            outtextxy(posX+(*offset)+2,posY,"+");
            (*offset)+=5;
        } else if (input=="-") {
            outtextxy(posX+(*offset)+2,posY,"-");
            (*offset)+=5;
        } else if (input=="^") {
            posY=posY+5;
        } else if (input.length()>3) {
            if (input.substr(0,3)=="sin" || input.substr(0,3)=="cos") {
                string auxString=input.substr(0,3)+"(";
                char auxChrString[256];
                strcpy(auxChrString,auxString.c_str());
                outtextxy(posX+(*offset),posY,auxChrString);


                stackElement *top = new stackElement;
                top=NULL;
                auxString=brackets(input,exitCode); //cout<<"auxxxx "<<auxString<<endl;
                auxString=infixToPostfix(auxString,&top, errorCode, exitCode);

                node *subTree;
                createExpressionTree(auxString,&subTree, exitCode);
                *offset+=30;

                int paranths=0;
                assessExpression(subTree,posX,posY,offset,"",&paranths,errorCode,exitCode);
                *offset+=10;
                outtextxy(posX+(*offset),posY,")");
            } else if (input.substr(0,3)=="log") {
                int heightOffset=0, paranths=0;



                string auxString=input;
                    auxString.erase(0,3);
                string order=brackets(auxString,exitCode);
                    auxString.erase(0,order.length()+2);
                string value=curlyBrackets(auxString,exitCode);

                char logType[4];
                if (order=="10") {strcpy(logType,"lg");} else
                    if (order=="e") {strcpy(logType,"ln");} else strcpy(logType,"log");

                if (mode==1 && (!strcmp(logType,"log"))) {
                    string auxString=input;
                        auxString.erase(0,3);
                    string order=brackets(auxString,exitCode);

                    heightOffset = calcHeightBottom(order,exitCode);
                }

                outtextxy(posX+(*offset),posY-heightOffset,logType);
                (*offset)+=textwidth(logType);

                if (!strcmp(logType,"log")) {
                    stackElement *orderTop = new stackElement;
                    orderTop=NULL;
                    order=infixToPostfix(order,&orderTop,errorCode,exitCode);
                    node *subTreeOrder;
                    createExpressionTree(order,&subTreeOrder,exitCode);

                    paranths=0;
                    assessExpression(subTreeOrder,posX,posY-heightOffset+8,offset,"",&paranths, errorCode, exitCode);
                }

                stackElement *valueTop = new stackElement;
                valueTop=NULL;
                value=infixToPostfix(value,&valueTop,errorCode, exitCode);
                node *subTreeValue;
                createExpressionTree(value,&subTreeValue,exitCode);

                paranths=0;
                int auxPosY=posY-heightOffset;
                assessExpression(subTreeValue,posX,auxPosY,offset,"",&paranths,errorCode, exitCode,mode);

            }

            if (input.length()>4 && input.substr(0,4)=="frac") {
                    *offset+=5;
                    int ogOffset1=*offset, ogOffset2=*offset, centerOffsetTop=0, centerOffsetBottom=0;
                    int topWidth=0, bottomWidth=0, heightOffsetBottom=0;

                    if (mode==1) {
                        string auxString=input;
                            auxString.erase(0,4);
                        string topValue=curlyBrackets(auxString,exitCode);
                            auxString.erase(0,topValue.length()+2);
                        string bottomValue=curlyBrackets(auxString,exitCode);

                        heightOffsetBottom = calcHeightBottom(bottomValue, exitCode);
                    }

                    string auxString=input;
                        auxString.erase(0,4);
                    string topFrac=curlyBrackets(auxString,exitCode);
                        auxString.erase(0,topFrac.length()+2);
                    string bottomFrac=curlyBrackets(auxString,exitCode);
                        auxString.erase(0,topFrac.length()+2);

                    int heightOffset=10+calcHeight(bottomFrac);


                    if (topFrac.length()>bottomFrac.length()) {
                        //*offset+=topFrac.length()*9;
                        auxString=topFrac;
                        for (int i=0; i<topFrac.length(); i++) {
                            if ((i<auxString.length()-4) && (auxString.substr(i,4)=="frac")) {
                                auxString.erase(i,4);
                            }
                        }
                        char auxCharString[1024];
                        strcpy(auxCharString,auxString.c_str());
                        line(posX+(*offset),posY+8+heightOffsetBottom,posX+(*offset)+textwidth(auxCharString)+3,posY+8+heightOffsetBottom);
                        *offset+=textwidth(auxCharString);
                        topWidth=textwidth(auxCharString);


                    } else { ///////////////////////////////////////////////////////////////////////////////////////
                        auxString=bottomFrac;
                        for (int i=0; i<topFrac.length(); i++) {
                            if ((i<auxString.length()-4) && (auxString.substr(i,4)=="frac")) {
                                auxString.erase(i,4);
                            }
                        }
                        char auxCharString[1024];
                        strcpy(auxCharString,auxString.c_str());
                        line(posX+(*offset),posY+8-heightOffsetBottom,posX+(*offset)+textwidth(auxCharString)+3,posY+8-heightOffsetBottom);
                        *offset+=textwidth(auxCharString);
                        bottomWidth=textwidth(auxCharString);

                    }


                    //Centering
                    if (bottomWidth==0) {
                        char auxCharString[1024];
                        auxString=bottomFrac;
                        for (int i=0; i<bottomFrac.length(); i++) {
                            if ((i<auxString.length()-4)) {
                                if (auxString.substr(i,4)=="frac") {
                                    auxString.erase(i,4);
                                }
                            }
                        }
                        strcpy(auxCharString,auxString.c_str());
                        bottomWidth=textwidth(auxCharString);

                        centerOffsetBottom=(topWidth-bottomWidth)/2;

                    } else if (topWidth==0) {
                        char auxCharString[1024];
                        auxString=topFrac;
                        for (int i=0; i<topFrac.length(); i++) {
                            if ((i<auxString.length()-4) && (auxString.substr(i,4)=="frac")) {
                                auxString.erase(i,4);
                            }
                        }
                        strcpy(auxCharString,auxString.c_str());
                        topWidth=textwidth(auxCharString);

                        centerOffsetTop=(bottomWidth-topWidth)/2;
                    }



                    stackElement *topFr = new stackElement;
                    stackElement *bottomFr = new stackElement;
                    topFr=NULL; bottomFr=NULL;

                    topFrac=infixToPostfix(topFrac,&topFr,errorCode, exitCode);
                    bottomFrac=infixToPostfix(bottomFrac,&bottomFr,errorCode, exitCode);

                    node *subTreeTop;
                    node *subTreeBottom;

                    createExpressionTree(topFrac,&subTreeTop, exitCode);

                    ogOffset1+=centerOffsetTop;
                    int paranths=0;
                    assessExpression(subTreeTop,posX,posY-10-heightOffsetBottom,&ogOffset1,"",&paranths,errorCode,exitCode,1);

                    createExpressionTree(bottomFrac,&subTreeBottom,exitCode);

                    ogOffset2+=centerOffsetBottom;
                    paranths=0;
                    assessExpression(subTreeBottom,posX,posY+heightOffset-heightOffsetBottom,&ogOffset2,"",&paranths,errorCode,exitCode,mode);

                    if (ogOffset1>=ogOffset2) {ogOffset1-=centerOffsetTop; (*offset)=ogOffset1;} else {ogOffset2-=centerOffsetBottom; (*offset)=ogOffset2;};

                    (*offset)+=5;

            } else if (input.length()>4 && input.substr(0,4)=="sqrt") {
                int ogOffset=(*offset);
                int heightOffsetOrder=0;

                /*if (mode==1) {
                    string auxString=input;
                        auxString.erase(0,4);
                    string order = brackets(auxString); cout<<"Order "<<order<<endl;

                    heightOffsetOrder = calc::calcHeightBottom(order);
                }*/
                int paranths=0;
                string auxString=input;
                    auxString.erase(0,4);
                string order=brackets(auxString,exitCode);
                    auxString.erase(0,order.length()+2);
                string value=curlyBrackets(auxString,exitCode);

                int heightOffset=10+calcHeight(value);

                if (order!="2"){
                    stackElement *orderTop = new stackElement;
                    orderTop=NULL;
                    order=infixToPostfix(order,&orderTop,errorCode, exitCode);
                    node *subTreeOrder;
                    createExpressionTree(order,&subTreeOrder, exitCode);


                paranths=0;
                assessExpression(subTreeOrder,posX,posY-8,offset,"",&paranths,errorCode,exitCode,1);
                } else *offset+=8;

                line(posX+ogOffset,posY+6,posX+(*offset),posY+12);
                line(posX+(*offset),posY+12,posX+(*offset),posY-heightOffset); //variable height

                ogOffset=(*offset);
                (*offset)+=5;

                stackElement *valueTop = new stackElement;
                valueTop=NULL;
                value=infixToPostfix(value,&valueTop,errorCode,exitCode);
                node *subTreeValue;
                createExpressionTree(value,&subTreeValue,exitCode);

                paranths=0;
                assessExpression(subTreeValue,posX,posY,offset,"",&paranths,errorCode,exitCode);

                line(posX+ogOffset,posY-heightOffset,posX+(*offset),posY-heightOffset); //variable height


            } else if ((input[1]>='0' && input[1]<='9') || input[1]=='.') {
                char auxString[256];
                strcpy(auxString,input.c_str());
                outtextxy(posX+(*offset),posY,auxString);
                (*offset)+=input.length()*5+input.length()*1.1+5;

            }
        }  else {
            char auxString[256];
            strcpy(auxString,input.c_str());
            outtextxy(posX+(*offset),posY,auxString);
            if (input.length()==1) {(*offset)+=3;} else {(*offset)+=18;};
        }
    }
}
    static void assessExpression(node* top, int positionX, int positionY, int* offset, string previousNode, int *paranths,int *errorCode, int *exitCode, int mode = 0) {//Habasescu
    if (*exitCode==0) {
        if (isOperator(previousNode[0])) {
            if ((precedence(previousNode)>precedence(top->inf)) && (precedence(top->inf)!=-1)) {
                *paranths+=1;
                arc(positionX+*offset+10,positionY+10,135,225,15);
            }
        }
        int auxParanths=0;
        if (top->leftNode!=NULL) {assessExpression(top->leftNode,positionX,positionY,offset,top->inf,&auxParanths,errorCode,exitCode);}
        cout<<top->inf<<endl;
        drawExpression(top->inf,positionX,positionY,offset,errorCode,exitCode,mode); (*offset)+=5;
        if (top->inf=="^") {positionY=positionY-10;}
        if (top->rightNode!=NULL) {assessExpression(top->rightNode,positionX,positionY,offset,top->inf,&auxParanths,errorCode,exitCode);}


        while (*paranths>0) {
            arc(positionX+*offset-10,positionY+10,315,45,15);
            *offset+=5;
            *paranths=(*paranths)-1;
        }
    }
    }
};

int errorHandler(string infix, string postfix) {//Habasescu
    int output=0;

    if (postfix.length()>infix.length()) {output=1;}

    return output;
}

