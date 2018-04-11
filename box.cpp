#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<string.h>
#include<cmath>
#include<iostream>
 GLfloat xRotated, yRotated, zRotated;
void init(void)
{
glClearColor(0,0,0,0);
 
}

void DrawCube(void)
{

     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
        glTranslatef(0.0,0.0,-10.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
  glBegin(GL_QUADS);        
    glColor3f(0.0f,1.0f,0.0f);    
    glVertex3f( 1.0f, 1.0f,-1.0f);    
    glVertex3f(-1.0f, 1.0f,-1.0f);    
    glVertex3f(-1.0f, 1.0f, 1.0f);   
    glVertex3f( 1.0f, 1.0f, 1.0f);    
    glColor3f(1.0f,0.5f,0.0f);   
    glVertex3f( 1.0f,-1.0f, 1.0f);    
    glVertex3f(-1.0f,-1.0f, 1.0f);    
    glVertex3f(-1.0f,-1.0f,-1.0f);   
    glVertex3f( 1.0f,-1.0f,-1.0f);   
    glColor3f(1.0f,0.0f,0.0f);     
    glVertex3f( 1.0f, 1.0f, 1.0f);   
    glVertex3f(-1.0f, 1.0f, 1.0f);      
    glVertex3f(-1.0f,-1.0f, 1.0f);   
    glVertex3f( 1.0f,-1.0f, 1.0f);    
    glColor3f(1.0f,1.0f,0.0f);    
    glVertex3f( 1.0f,-1.0f,-1.0f);   
    glVertex3f(-1.0f,-1.0f,-1.0f);   
    glVertex3f(-1.0f, 1.0f,-1.0f);    
    glVertex3f( 1.0f, 1.0f,-1.0f);   
    glColor3f(0.0f,0.0f,1.0f);   
    glVertex3f(-1.0f, 1.0f, 1.0f);    
    glVertex3f(-1.0f, 1.0f,-1.0f);   
    glVertex3f(-1.0f,-1.0f,-1.0f);    
    glVertex3f(-1.0f,-1.0f, 1.0f);    
    glColor3f(1.0f,0.0f,1.0f);    
    glVertex3f( 1.0f, 1.0f,-1.0f);    
    glVertex3f( 1.0f, 1.0f, 1.0f);    
    glVertex3f( 1.0f,-1.0f, 1.0f);   
    glVertex3f( 1.0f,-1.0f,-1.0f);    
  glEnd();            
glFlush();
}


void animation(void)
{
 
     yRotated += 0.01;
     xRotated += 0.02;
    DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}

int main(int argc, char** argv){

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(DrawCube);
glutReshapeFunc(reshape);
glutIdleFunc(animation);        //animation
glutMainLoop();
return 0;
}
