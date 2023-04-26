#include "ColorCasilla.h"
#include <freeglut.h>

void ColorCasilla::SetColor(unsigned char r, unsigned char a, unsigned char v) 
{
	rojo = r; 
	azul = a; 
	verde = v;

	CheckColor(rojo);
	CheckColor(azul);
	CheckColor(verde);

	glColor3ub(rojo, verde, azul);
}
void ColorCasilla::CheckColor(unsigned char c)
{
	if (c > 255)c = 255;
	if (c < 0)c = 0;
}