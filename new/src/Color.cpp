#include "Color.h"
#include <freeglut.h>

Color::Color(unsigned char r = 0, unsigned char a = 0, unsigned char v = 0) :rojo(r), azul(a), verde(v) {
	CheckColor(rojo);
	CheckColor(azul);
	CheckColor(verde);
}

void Color::SetColor(unsigned char r, unsigned char a, unsigned char v) 
{
	rojo = r; 
	azul = a; 
	verde = v;

	CheckColor(rojo);
	CheckColor(azul);
	CheckColor(verde);

	glColor3ub(rojo, verde, azul);
}
void Color::CheckColor(unsigned char c)
{
	if (c > 255)c = 255;
	if (c < 0)c = 0;
}