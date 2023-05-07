#include "Marcador.h"
#include <ETSIDI.h>
#include "freeglut.h"

Marcador marcador1;

void Marcador::CreaMarcador(ColorCasilla color1,ColorCasilla color2) {

	//rectangulo grande derecha
	marcador1.SetColor(color1);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(9.8f, 7.3, 0.0f);
	glVertex3f(11.1f, 7.3, 0.0f);
	glVertex3f(11.1f, 7.9, 0.0f);
	glVertex3f(9.8f, 7.9, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	
	//rectangulo grande izquierda
	marcador1.SetColor(color2);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(8.3f, 7.3, 0.0f);
	glVertex3f(9.7f, 7.3, 0.0f);
	glVertex3f(9.7f, 7.9, 0.0f);
	glVertex3f(8.3f, 7.9, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	
	CartelBlancas->draw();
	CartelNegras->draw();
	
	//rectangulo pequeño derecha
	glColor3ub(0, 0, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(9.8f, 0.1, 0.0f);
	glVertex3f(11.1f, 0.1, 0.0f);
	glVertex3f(11.1f, 7.2, 0.0f);
	glVertex3f(9.8f, 7.2, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	
	//rectangulo pequeño izquierda
	glColor3ub(0, 0, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(8.3f, 0.1, 0.0f);
	glVertex3f(9.7f, 0.1, 0.0f);
	glVertex3f(9.7f, 7.2, 0.0f);
	glVertex3f(8.3f, 7.2, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	
	//rectangulo grande blanco
	glColor3ub(255, 255, 255);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(8.2f, 0.0, 0.0f);
	glVertex3f(11.2f, 0.0, 0.0f);
	glVertex3f(11.2f, 8, 0.0f);
	glVertex3f(8.2f, 8, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Marcador::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	this->ColorMarcador.SetColor(r, v, a);
}

void Marcador::SetColor(ColorCasilla _color) {
	this->ColorMarcador.SetColor(_color.GetRojo(), _color.GetVerde(), _color.GetAzul());
}
