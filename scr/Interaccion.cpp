#include <Interaccion.h>
#include <Tablero.h>

// INTENTAR METER AQUI INTERACCION CON TECLADO Y RATON

void Interaccion::SetX(float _x) {
	x = _x;
}
void Interaccion::SetY(float _y) {
	y = _y;
}
float Interaccion::GetX() {
	return x;
}
float Interaccion::GetY() {
	return y;
}

void Interaccion::CheckPosition(float _x, float _y) {
	if (_x < 0.0)x = 2.5;
	else if (_x > 40.0)x = 37.5;
	else if (_y < 0.0)y = 2.5;
	else if (_y > 40.0)y = 37.5;
}

void Interaccion::teclado(char k) {
	switch (k)
	{
	case ' ':
		 
		// ¿Como hacer la seleccion?
		//cambiar aswd a flechas
	case 'd':
		x += 5.0;
		break;
	case 'a':
		x-=5.0;
		break;
	case 'w':
		y += 5.0;
		break;
	case 's':
		y -= 5.0;
		break;
	}
	CheckPosition(x,y);
	GrisOscuro->setPos(x,y);
}
