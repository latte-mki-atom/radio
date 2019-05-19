#include <GL/glut.h>
#include <GL/gl.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>


using namespace std;

float x;
GLuint sphere;
GLdouble r;
GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]= { 3.0f, 5.0f, -2.0f, 1.0f };

GLvoid BuildList(){
sphere = glGenLists(1);
glNewList(sphere,GL_COMPILE);
glutSolidSphere(r,20,20);
glEndList();
}


void renderScene(void) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0,1.0,1.0);
glRotated(10,0.0f,1.0f,0.0f);
glScalef(1.0f,1.0f,1.0f);
while ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) == 0){
glCallList(sphere);
Sleep(120);
glutSwapBuffers();
x=r;
glTranslated(-x,x*0.2,0);
}
glutLeaveGameMode();
}

int main(int argc, char **argv) {
cin » r;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutGameModeString("1920x1800:64");
glutEnterGameMode();
glShadeModel(GL_SMOOTH);
glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHTING);
glClearColor(0.0f, 1.0f, 0.0f, 0.5f);
BuildList();
glLoadIdentity();
glutDisplayFunc(renderScene);
glutMainLoop();
return 0;
}
