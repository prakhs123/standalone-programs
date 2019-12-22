/* Koch.c  */

/*
 Purpose: generate Koch curve and snowflake
 */

#include <GLUT/glut.h>	/* includes gl.h */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



/* Global Variables */
static GLdouble mOldX = 0.0;
static GLdouble mOldY = 0.0;
GLdouble theta = 0.0;



/*
 Functions
 */

void printHelp( char *progname )
{
	fprintf(stdout,
			"\n%s - Koch curves\n\n"
			"Any key to go to the next iteration\n"
			"Escape key    - exit the program\n\n",
			progname);
}


GLvoid init( GLvoid )
{
    glClearColor( 1.0, 1.0, 1.0, 1.0);
    glColor3f(0.3, 0.25, 0.8);
    glLineWidth(3.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -0.05, 1.05, -0.05, 0.35, -1.0, 1.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLvoid keyboard( GLubyte key, GLint x, GLint y)
{
    switch (key)
	{
        case 27:   /* exit when escape key is pressed */
            exit(0);
            break;
        default:
            glutPostRedisplay();
    }
}


GLvoid specialkeys( GLint key, GLint x, GLint y)
{
    switch (key) {
        case GLUT_KEY_F1:   /* print Help information */
            printHelp( "Koch curves" );
            break;
    }
}


GLvoid drawKoch( GLdouble dir, GLdouble len, GLint n)
{
	GLdouble dirRad = 0.0174533 * dir;  /* convert to radians  */
	GLdouble newX = mOldX + len * cos(dirRad);
	GLdouble newY = mOldY + len * sin(dirRad);
    
	if (n == 0)
	{
		/* Now draw the line */
		glVertex2f(mOldX, mOldY);
		glVertex2f(newX, newY);
		mOldX = newX;
		mOldY = newY;
	}
	else
	{
		n--;          /* reduce the order  */
		len /= 3.0;   /* reduce the length */
		drawKoch(dir, len, n);
        
		dir += 60.0;
		drawKoch(dir, len, n);
        
		dir -= 120.0;
		drawKoch(dir, len, n);
        
		dir += 60.0;
		drawKoch(dir, len, n);
	}
}


GLvoid display( GLvoid )
{
	static int maxLevel = -1;
    maxLevel++;
    
	glClear( GL_COLOR_BUFFER_BIT );
	/* Do all your OpenGL rendering here */
	glBegin(GL_LINES);
    
	/* Construct the Koch snowflake - generate Koch curves on
     each side of an equilateral triangle. */
    GLdouble factor = 0.15;
    GLdouble X = 0.5;
    GLdouble Y = 0.13;
	mOldX = X + 0.0; mOldY = Y + 0.0;
    
    //GLdouble radtodeg = 57.295779513082320876798154814105;
    GLdouble degtorad = 0.01745329251994329576923690768489;
	drawKoch(theta+60.0, factor * 1.0, maxLevel);
	mOldX = X + factor * cos((60+theta)*degtorad); mOldY = Y + factor * sin((60+theta)*degtorad);
	drawKoch(-(60.0-theta), factor * 1.0, maxLevel);
	mOldX = X + factor * cos(theta*degtorad); mOldY = Y + factor * sin(theta*degtorad);
	//printf("%f %f\n", mOldX, mOldY);
    drawKoch(-(180.0-theta), factor * 1.0, maxLevel);
    
	/* single Koch curve :  */
    /*
     mOldX = 0.0;
     mOldY = 0.0;
     drawKoch( 0.0, 1.0, maxLevel ); */
	glEnd();
	glFlush();
}


int main( int argc, char *argv[] )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGB );
    glutInitWindowSize(1024, 768);
	glutCreateWindow( argv[0] );
    
    
	init();
    scanf("%lf", &theta);
    
    glutKeyboardFunc( keyboard );
    glutSpecialFunc( specialkeys );
    
	glutDisplayFunc( display );
    
	printHelp( argv[0] );
    
	glutMainLoop();
    
	return 0;
}