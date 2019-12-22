#include<GLUT/glut.h>


void init(void)
{
	glClearColor(0.1,0.1,0.1,0.1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-200.0,200.0,-200.0,200.0);
}


void Graphics (void)
{
	glClear (GL_COLOR_BUFFER_BIT);


	glPushMatrix();

	glBegin (GL_QUADS);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(0,-25);
	glVertex2i(150,50);
    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(120,60);
	glVertex2i(0,10);
	glEnd ();

	glBegin(GL_TRIANGLES);

    glColor3f (0.30, 0.30, 0.30);
	glVertex2i(0,-150);
	glVertex2i(150,50);
    glColor3f (0.50, 0.50, 0.50);
	glVertex2i(0,0);
	
    glColor3f (0.50, 0.50, 0.50);
	glVertex2i(0,-150);
	glVertex2i(15,-130);
    glColor3f (0.30, 0.30, 0.30);
	glVertex2i(0,-80);

    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(15,-130);
	glVertex2i(0,-25);
    glColor3f (0.30, 0.30, 0.30);
	glVertex2i(0,-80);

    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(15,-130);
	glVertex2i(0,-25);
    glColor3f (0.5, 0.5, 0.5);
	glVertex2i(30,-110);

    glColor3f (0.50, 0.50, 0.50);
	glVertex2i(0,-25);
    glColor3f (0.30, 0.30, 0.30);
	glVertex2i(50,50);
	glVertex2i(0,75);

    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(25,-55);
	glVertex2i(0,-25);
	glColor3f (0.6, 0.6, 0.6);
	glVertex2i(40,35);

	glEnd ();

	glBegin (GL_QUADS);

    glColor3f (0.5, 0.5, 0.5);
	glVertex2i(30,-110);
	glVertex2i(35,-80);
	glVertex2i(10,-10);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(0,-25);

    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(35,-80);
	glVertex2i(55,-75);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(45,-40);
	glVertex2i(25,-55);

    glColor3f (0.5, 0.5, 0.5);
	glVertex2i(25,-55);
	glVertex2i(45,-40);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(50,50);
	glVertex2i(40,35);

    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(55,-75);
	glVertex2i(70,-10);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(45,10);
	glVertex2i(45,-40);

    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(45,10);
	glVertex2i(70,-10);
    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(65,55);
	glVertex2i(50,50);

    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(0,75);
	glVertex2i(50,50);
    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(65,55);
	glVertex2i(0,85);


    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(0,85);
	glVertex2i(65,55);
    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(65,70);
	glVertex2i(0,100);

    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(0,100);
	glVertex2i(10,85);
    glColor3f (0.5, 0.5, 0.5);
	glVertex2i(40,175);
	glVertex2i(25,160);

	glEnd ();


	glPopMatrix();




	glPushMatrix();

	glScalef(-1,1,1);

	glBegin (GL_QUADS);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(0,-25);
	glVertex2i(150,50);
    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(120,60);
	glVertex2i(0,10);
	glEnd ();

	glBegin(GL_TRIANGLES);

    glColor3f (0.20, 0.20, 0.20);
	glVertex2i(0,-150);
	glVertex2i(150,50);
    glColor3f (0.40, 0.40, 0.40);
	glVertex2i(0,0);
	
    glColor3f (0.40, 0.40, 0.40);
	glVertex2i(0,-150);
	glVertex2i(15,-130);
    glColor3f (0.20, 0.20, 0.20);
	glVertex2i(0,-80);

    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(15,-130);
	glVertex2i(0,-25);
    glColor3f (0.20, 0.20, 0.20);
	glVertex2i(0,-80);

    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(15,-130);
	glVertex2i(0,-25);
    glColor3f (0.4, 0.4, 0.4);
	glVertex2i(30,-110);

    glColor3f (0.40, 0.40, 0.40);
	glVertex2i(0,-25);
    glColor3f (0.20, 0.20, 0.20);
	glVertex2i(50,50);
	glVertex2i(0,75);

    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(25,-55);
	glVertex2i(0,-25);
	glColor3f (0.5, 0.5, 0.5);
	glVertex2i(40,35);

	glEnd ();

	glBegin (GL_QUADS);

    glColor3f (0.40, 0.40, 0.40);
	glVertex2i(30,-110);
	glVertex2i(35,-80);
	glVertex2i(10,-10);
    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(0,-25);

    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(35,-80);
	glVertex2i(55,-75);
    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(45,-40);
	glVertex2i(25,-55);

    glColor3f (0.40, 0.40, 0.40);
	glVertex2i(25,-55);
	glVertex2i(45,-40);
    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(50,50);
	glVertex2i(40,35);

    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(55,-75);
	glVertex2i(70,-10);
    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(45,10);
	glVertex2i(45,-40);

    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(45,10);
	glVertex2i(70,-10);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(65,55);
	glVertex2i(50,50);

     glColor3f (0.1, 0.1, 0.1);
	glVertex2i(0,75);
	glVertex2i(50,50);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(65,55);
	glVertex2i(0,85);


    glColor3f (0.3, 0.3, 0.3);
	glVertex2i(0,85);
	glVertex2i(65,55);
    glColor3f (0.2, 0.2, 0.2);
	glVertex2i(65,70);
	glVertex2i(0,100);

    glColor3f (0.1, 0.1, 0.1);
	glVertex2i(0,100);
	glVertex2i(10,85);
    glColor3f (0.5, 0.5, 0.5);
	glVertex2i(40,175);
	glVertex2i(25,160);

	glEnd ();


	glPopMatrix();


/*
	glRotatef(290,0,0,1);
	glTranslatef(60,100,0);

	glEnd ();
*/

	glFlush();
}



int main(int argc, char**argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50,100);
	glutInitWindowSize (850,700);
	glutCreateWindow("Assignment-BlackHawk-Muhammad Bilal Bhatti");
	init();
	glutDisplayFunc (Graphics);
	glutMainLoop();
    return 0;
}
