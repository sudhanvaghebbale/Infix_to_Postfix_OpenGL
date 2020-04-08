#include <stdio.h>
#include <stdlib.h>      /* For exit() */
#include <ctype.h>     /* For isdigit(char ) */
#include <string.h>
#include <GLUT/glut.h>

# define SIZE 100

char infix[SIZE];
char prefix[SIZE];
char stack[SIZE];
int stack1[SIZE];
char str [SIZE];
char temp[SIZE];

float color[4][3]={{0.0,0.0,1.0},{0.8,0.0,0.0,},{1.0,1.0,1.0},{0.0,0.0,0.8}};
int top = -1;
int x1=400,x2=500,y2=900;

void delay()
{
    int i,j;
    for(i=0;i<10000;i++)
        for(j=0;j<10000;j++);
}

void Translating(int z){
    int p,c=0;
    for(p=0;p<z;p++){
        glPushMatrix();
        glTranslatef(938-50*c,938-50*c,938-50*c);
        glPopMatrix();
        c+=1;
        delay();
    }
}
void drawstring(float x,float y,char *string,int col)
{
    char *c;
    glColor3fv(color[col]);
    glRasterPos2f(x,y);
    for(c=string;*c!='\0';c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
    }
}

void title()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    drawstring(350.0,900.0,"BNM INSTITUTE OF TECHNOLOGY",2);
    drawstring(350.0,850.0,"COMPUTER GRAPHICS PROJECT",2);
    drawstring(330.0,650.0,"TITLE  : PREFIX EXPRESSION EVALUATION",2);
    drawstring(330.0,600.0,"NAME   : SUDHANVA G HEBBALE",2);
    drawstring(330.0,550.0,"BRANCH : COMPUTER SCIENCE",2);
    drawstring(330.0,500.0,"USN    : 1BG15CS107",2);
    drawstring(350.0,350.0,"(Click Right Mouse Button For Options)",2);
    //glColor3f(0.85,0.85,0.4);
    glColor3f(1.0,1.0,1.0);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(18,1000);
    glVertex2i(18,5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glLineWidth(50);
    glBegin(GL_LINES);
    glVertex2i(30,1000);
    glVertex2i(30,5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glLineWidth(100);
    glBegin(GL_LINES);
    glVertex2i(42,1000);
    glVertex2i(42,5);
    glEnd();
    glFlush();
}

void draw(){
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(450, 980);
    glVertex2f(450, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(350, 980);
    glVertex2f(350, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(200, 980);
    glVertex2f(200, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(600, 980);
    glVertex2f(600, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(600, 980);
    glVertex2f(600, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(200, 980);
    glVertex2f(600, 980);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(200, 20);
    glVertex2f(600, 20);
    glEnd();
    glFlush();
    
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(200, 910);
    glVertex2f(600, 910);
    glEnd();
    glFlush();
}

char *strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;
    
    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
// Function to output text on the screen
void drawString(float x,float y,char *string) {
    char *c;
    glRasterPos2f(x,y);
    
    for(c=string; *c!='\0';c++) {
        glColor3f(1.0,1.0,1.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
    }
}

void drawStack(float x,float y,char *string,int top) {
    int i=0;
    glRasterPos2f(x,y);
    
    for(i=0;i<=top;i++) {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,stack[i]);
    }
}

void drawChar(float x,float y,char s) {
    glRasterPos2f(x,y);
    glColor3f(1.0,1.0,1.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s);
}

void displayInExp(char item,int z) {
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(350, y2-50*z -50);
    glVertex2f(450, y2-50*z -50);
    glVertex2f(450, y2-50*z);
    glVertex2f(350, y2-50*z);
    glEnd();
    drawChar(375,y2-50*z-30,item);
    glFlush();
    Translating(z);
}

void displayExp(int z) {
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(450, y2-50*z -50);
    glVertex2f(600, y2-50*z -50);
    glVertex2f(600, y2-50*z);
    glVertex2f(450, y2-50*z);
    glEnd();
    drawString(475,y2-50*z-30,prefix);
    glFlush();
    Translating(z);
    
}

void displayStack(int z,int top) {
    int p=0; int c=50;
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200, y2-50*z -50);
    glVertex2f(350, y2-50*z -50);
    glVertex2f(350, y2-50*z);
    glVertex2f(200, y2-50*z);
    glEnd();
    drawStack(255,y2-50*z-30,stack,top);
    glFlush();
    Translating(z);
}

/* Push operation */

void push(char item) {
    if( top >= SIZE-1) {
        drawString(20,950,"Stack Overflow");
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

void push1(int item) {
    if( top >= SIZE-1) {
        drawString(20,950,"Stack Overflow");
    }
    else {
        top = top + 1;
        stack1[top] = item;
    }
}
/* Pop operation */
char pop() {
    char item ;
    
    if(top < 0) {
        drawString(20,950,"Stack Underflow");
        
    }
    
    item = stack[top];
    top = top - 1;
    return(item);
}

int pop1() {
    int item ;
    
    if(top < 0) {
        drawString(20,950,"Stack Underflow");
        
    }
    
    item = stack1[top];
    top = top - 1;
    return(item);
}

/* Define function that is used to determine whether any symbol is operator or not
 * This fucntion returns 1 if symbol is opreator else return 0 */

int isOperator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Define fucntion that is used to assign precendence to operator.
 * Here ^ denotes exponent operator.
 * In this fucntion we assume that higher integer value
 * Means higher precendence */

int precedence(char symbol)
{
    if(symbol == '^')/* Exponent operator, highest precedence*/
    {
        return(3);
    }
    else if(symbol == '*' || symbol == '/')
    {
        return(2);
    }
    else if(symbol == '+' || symbol == '-')          /* Lowest precedence */
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

int anomalies() {
    int i = 0,symbol,ch;
    for(i=0;i<strlen(infix);i++){
        symbol = infix[i];
        ch = infix[++i];
        if( isOperator(symbol) == 1  &&  ch == ')' ){
            drawString(20,950,"Invalid Expression");
            return 0;
        }
        
        if( symbol == '(' && isOperator(ch) == 1){
            drawString(20,950,"Invalid Expression");
            return 0;
        }
        
        if((isdigit(symbol) || isalpha(symbol)) && ch == '('){
            drawString(20,950,"Invalid Expression");
            return 0;
        }
        
        if (isOperator(symbol)==1 && isOperator(ch)==1 ){
            drawString(20,950,"Invalid Expression");
            return 0;
        }
    }
    return 1;
}

void PrefixEval() {
    int i,l=0,j=0,k;
    l = strlen(prefix);
    char ch;
    int ch3=0;
    char e=0;
    //char e[SIZE];
    int ch1,ch2;
    strrev(prefix);
    for(i=0;i<l;i++){
        
        ch = prefix[i];
        
        if(isalpha(ch)){
            printf("Enter the value of %c : ",ch);
            scanf("%d",&ch3);
            fflush(stdin);
            push1(ch3);
        }
        
        else
        {
            ch2= pop1();
            ch1 = pop1();
            switch(prefix[i])
            {
                case '+':
                    push1(ch2+ch1); break;
                case '-':
                    push1(ch2-ch1); break;
                case '*':
                    push1(ch2*ch1); break;
                case '/':
                    push1(ch2/ch1); break;
                case '%':
                    push1(ch2%ch1); break;
            }
        }
    }
    
    e= pop1();
    int b;
    b=e/10;
    b=b+48;
    int c;
    c=e%10;
    c=c+48;
    drawString(675,500,"Prefix Evaluation :");
    glRasterPos2f(850.0,500.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,b);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c);
    drawString(675,700,"Infix Expression :");
    drawString(850,700, strrev(infix));
    drawstring(675,600,"Prefix Expression :",2);
    drawString(850,600, strrev(prefix));
}


void InfixPrefix() {
    int i,j=0;
    int q=0,b=0,u=0;
    char symbol;
    int x;
    x = anomalies();
    
    if (x == 0){
        drawString(x1,y2,infix);
        draw();
        
    }
    
    else {
        push('#');
        strrev(infix);
        drawChar(475,y2-85,'-');
        for (i=0;i<strlen(infix);i++) {
            symbol=infix[i];
            displayStack(++u,top);
            displayExp(++q);
            displayInExp(symbol,++b);
            
            if (isdigit(symbol) || isalpha(symbol)) {
                prefix[j]=symbol;
                j++;
            }
            
            else {
                if (symbol==')') {
                    push(symbol);
                    
                }
                
                else if(symbol == '(') {
                    while (stack[top]!=')') {
                        prefix[j]=pop();
                        
                        j++;
                    }
                    pop();
                    
                }
                else {
                    if(isOperator(symbol)== 1){
                        if (precedence(stack[top])<=precedence(symbol)) {
                            push(symbol);
                            
                        }
                        else {
                            while(precedence(stack[top])>=precedence(symbol)) {
                                prefix[j]=pop();
                                j++;
                            }
                            push(symbol);
                            
                        }
                    }
                    else {
                        drawString(20,950,"Invalid Operator");
                        break;
                    }
                }
            }
        }
        //end for for
        while (stack[top]!='#') {
            prefix[j]=pop();
            j++;
            displayStack(++u,top);
            displayExp(++q);
        }
        prefix[j]='\0';
        strrev(prefix);
        displayExp(++q);
        draw();
    }
}
void InfixPrefix1() {
    int i,j=0;
    int q=0,b=0,u=0;
    char symbol;
    int x;
    x = anomalies();
    if (x == 0){
        drawString(x1,y2,infix);
        draw();
    }
    
    else {
        push('#');
        strrev(infix);
        //  drawChar(455,y2-65,'-');
        
        for (i=0;i<strlen(infix);i++) {
            symbol=infix[i];
            //     displayInExp(symbol,++b);
            //     displayStack(++u,top);
            //     displayExp(++q);
            
            if (isdigit(symbol) || isalpha(symbol)) {
                prefix[j]=symbol;
                j++;
            }
            
            else {
                if (symbol==')') {
                    push(symbol);
                    
                }
                
                else if(symbol == '(') {
                    while (stack[top]!=')') {
                        prefix[j]=pop();
                        
                        j++;
                    }
                    pop();
                    
                }
                else {
                    if(isOperator(symbol)== 1){
                        if (precedence(stack[top])<=precedence(symbol)) {
                            push(symbol);
                            
                        }
                        else {
                            while(precedence(stack[top])>=precedence(symbol)) {
                                prefix[j]=pop();
                                j++;
                            }
                            push(symbol);
                            
                        }
                    }
                    else {
                        //           drawString(20,950,"Invalid Operator");
                        break;
                    }
                }
            }
        }
        //end for for
        while (stack[top]!='#') {
            prefix[j]=pop();
            j++;
            //     displayStack(++u,top);
            //     displayExp(++q);
        }
        prefix[j]='\0';
        strrev(prefix);
        //    displayExp(++q);
        //    draw();
    }
    
    // PrefixEval();
}
void display()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    title();
    // glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void menu(int choice)
{
    switch(choice)
    {
        case 1: printf("Enter Infix expression :\n");
            gets(infix);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            int w;
            w = anomalies();
            if(w==0){
                drawString(20,950,"Invalid Expression");
                break;
            }
            else {
                drawString(250,938,"Stack");
                drawString(380,938,"Item");
                drawString(480,938,"Prefix");
                InfixPrefix();
                PrefixEval();
                glFlush();
                break;
            }
            
        case 2: exit(0);
    }
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,1000);
    glMatrixMode(GL_MODELVIEW);
    
}
int main(int argc, char **argv)
{
    // printf("Enter Infix expression :\n");
    // gets(infix);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Infix to Prefix Expression");
    init();
    glutDisplayFunc(display);
    glFlush();
    glutCreateMenu(menu);
    glutAddMenuEntry("Prefix Evaluation",1);
    glutAddMenuEntry("Exit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}





