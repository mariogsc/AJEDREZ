#include "Vector2D.h"

void Vector2D::SetVector(float _x, float _y) {  // Cambio de valores del vector (x,y privados)
	x = _x;
	y = _y;
}

Vector2D Vector2D::Conversor(float fila, float columna) { 
	//Función que recibe coordenadas en matriz 8x8 y convierte en posiciones del tablero
	float tam = 5.0, centro=tam/2;
	Vector2D posicion;

	posicion.x = (tam * fila) - centro;  // ojo orden inverso

	posicion.y = 8*tam - (tam * columna) + centro;

	return posicion;
}
