#include<GLUT/glut.h>
#include<iostream>
#include<cmath>
#define R2 1.4142135623730950488016887242097
#define F5 0.78539816339744830961566084581988

using namespace std;

int h,k,r;

void init( void )
{
    glClearColor( 0.0 , 0.0 , 0.0 , 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1500,0,750);
    
}

void Plot(int x,int y)
{
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    
    glVertex2f(x,y);
    glEnd();
}



void Plotf(double x,double y)
{
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    
    glVertex2f(x,y);
    glEnd();
}

void bresc(int h,int k,int r)
{
    int x=0;
    int y=r;
    int d=3-2*r;
    
    while(x<=y)
    {
        Plot(x+h,y+k);
        Plot(x+h,-y+k);
        Plot(-x+h,y+k);
        Plot(-x+h,-y+k);
        Plot(y+h,x+k);
        Plot(y+h,-x+k);
        Plot(-y+h,x+k);
        Plot(-y+h,-x+k);
        
        if(d<0)
            d+=(4*x+6);
        
        else
        {
            y--;
            d+=(4*(x-y)+10);
        }
        x++;
        
    }
    glutSwapBuffers();
}

void Para(int h,int k,int r)
{
    double a=0;
    double aend=F5;
    
    double x=r*cos(a);
    double y=r*sin(a);
    
    double xn,yn;
    double da=1.0/(double)r;
    
    while(a<=aend)
    {
        Plotf(x+h,y+k);
        Plotf(x+h,-y+k);
        Plotf(-x+h,y+k);
        Plotf(-x+h,-y+k);
        Plotf(y+h,x+k);
        Plotf(y+h,-x+k);
        Plotf(-y+h,x+k);
        Plotf(-y+h,-x+k);
        
        xn=x*cos(da)-y*sin(da);
        yn=x*sin(da)+y*cos(da);
        
        x=xn;
        y=yn;
        
        a+=da;
    }
    glutSwapBuffers();
}

void Poly(int h,int k,int r)
{
    int x=0;
    int y=r;
    int xend=((double)(r)/R2);
    
    while(x<=xend)
    {
        Plot(x+h,y+k);
        Plot(x+h,-y+k);
        Plot(-x+h,y+k);
        Plot(-x+h,-y+k);
        Plot(y+h,x+k);
        Plot(y+h,-x+k);
        Plot(-y+h,x+k);
        Plot(-y+h,-x+k);
        
        x++;
        y=(int)(sqrt(r*r-x*x));
        
    }
    glutSwapBuffers();
}

void midp(int h,int k,int r)
{
    int x=0;
    int y=r;
    
    double p=1.25-r;
    
    while(x<=y)
    {
        Plot(x+h,y+k);
        Plot(x+h,-y+k);
        Plot(-x+h,y+k);
        Plot(-x+h,-y+k);
        Plot(y+h,x+k);
        Plot(y+h,-x+k);
        Plot(-y+h,x+k);
        Plot(-y+h,-x+k);
        
        if(p<0)
            p+=(2*x+3);
        
        else
        {
            y--;
            p+=(2*(x-y)+5);
        }
        x++;
    }
    glutSwapBuffers();
}

void display1(void)
{
	glClear( GL_COLOR_BUFFER_BIT );
	glutSwapBuffers();
	Poly(h,k,r);
}

void display2(void)
{
    glClear( GL_COLOR_BUFFER_BIT );
	glutSwapBuffers();
	Para(h,k,r);
}

void display3(void)
{
	glClear( GL_COLOR_BUFFER_BIT );
	glutSwapBuffers();
	bresc(h,k,r);
}

void display4(void)
{
	glClear( GL_COLOR_BUFFER_BIT );
	glutSwapBuffers();
	midp(h,k,r);
}


int main(int argc, char *argv[])
{
    int ch;
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGB );
	glutInitWindowPosition(0,0);
    
	glutInitWindowSize(1300,650);
    cout<<"Enter the +ve integral coordinates of the circle's centre\n\n";
    cin>>h;
    cin>>k;
    
    cout<<"\nEnter the radius of the circle\n\n";
    cin>>r;
    
    glutCreateWindow("Circle drawing Algorithm Implementation");
    init();
    
    cout<<"\nChoose your circle generation technique\n1-Polynomial\n2-Parametric\n3-Bresenham circle generation algorithm\n4-Mid-point circle generation\nEnter your choice\n\n";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
            glutDisplayFunc(display1);
            glutMainLoop();
            break;
            
        case 2:
            glutDisplayFunc(display2);
            glutMainLoop();
            break;
            
        case 3:
            glutDisplayFunc(display3);
            glutMainLoop();
            break;
            
        case 4:
            glutDisplayFunc(display4);
            glutMainLoop();
            break;
            
        default:
            cout<<"Entered wrong choice\n";
    }
    
    return 0;
}