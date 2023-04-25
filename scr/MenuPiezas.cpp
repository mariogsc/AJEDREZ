#include "MenuPiezas.h"
#include <ETSIDI.h>
#include "freeglut.h"

Menu::Menu(){
glColor3ub(0, 0, 0);
glDisable(GL_LIGHTING);
glBegin(GL_POLYGON);
glVertex3f(41.3f, 37.3, 0.0f);
glVertex3f(41.3f, 39.7, 0.0f);
glVertex3f(47.85f, 39.7, 0.0f);
glVertex3f(47.85f, 37.3, 0.0f);
glEnd();
glEnable(GL_LIGHTING);

glColor3ub(0, 0, 0);
glDisable(GL_LIGHTING);
glBegin(GL_POLYGON);
glVertex3f(48.15f, 37.3, 0.0f);
glVertex3f(48.15f, 39.7, 0.0f);
glVertex3f(54.7f, 39.7, 0.0f);
glVertex3f(54.7f, 37.3, 0.0f);
glEnd();
glEnable(GL_LIGHTING);

glColor3ub(0, 0, 0);
glDisable(GL_LIGHTING);
glBegin(GL_POLYGON);
glVertex3f(41.3f, 0.3, 0.0f);
glVertex3f(54.7f, 0.3, 0.0f);
glVertex3f(54.7f, 37.0, 0.0f);
glVertex3f(41.3f, 37.0, 0.0f);
glEnd();
glEnable(GL_LIGHTING);


glColor3ub(255, 255, 255);
glDisable(GL_LIGHTING);
glBegin(GL_POLYGON);
glVertex3f(41.0f, 0.0, 0.0f);
glVertex3f(55.0f, 0.0, 0.0f);
glVertex3f(55.0f, 40.0, 0.0f);
glVertex3f(41.0f, 40.0, 0.0f);
glEnd();
glEnable(GL_LIGHTING);
}