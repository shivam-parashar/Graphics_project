#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<string.h>
#include<cmath>
#include<iostream>



GLfloat xRotated, yRotated, zRotated,dx=0.02,dy=0.03,dz=0.04;
GLfloat xTranslated=0.0,yTranslated=0.0,zTranslated=-5.0;
GLdouble radius=0.5;
GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0}; 
GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0}; 
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; 
GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0}; 

GLfloat qaAmbientLight[]    = {0.2, 0.2, 0.2, 1.0};
GLfloat qaDiffuseLight[]    = {0.8, 0.8, 0.8, 1.0};
GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
    
GLfloat qaLightPosition[]    = {0.5, 0, -3.5, 0.5};		// Light source position
 
 void display(void);
 void reshape(int x, int y);
void redirect()
{
    if(xTranslated>1.5||xTranslated<-1.5)
    {
        dx=-1*dx;
    }
    if(yTranslated>=1.5||yTranslated<=-1.5)
    {
        dy=-1*dy;
    }
    if(zTranslated>=-4.5||zTranslated<=-6.5)
    {
        dz=-1*dz;
    }
    
}
void idleFunc(void)
{
   redirect();
   xTranslated+=dx;
   yTranslated+=dy;
   zTranslated+=dz;

    display();
}
void initLighting()
{

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
     glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

     glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}

int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,350);
    glutCreateWindow("Solid Sphere");
    initLighting(); 
    xRotated = yRotated = zRotated = 0.0;
    
    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
 
void display(void)
{


    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
   

    glTranslatef(xTranslated,yTranslated,zTranslated);
     

   
    glScalef(1.0,1.0,1.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    
       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

   
    glutSolidSphere(radius,25,25);
    
    glFlush();
    glutSwapBuffers();      
    
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}

