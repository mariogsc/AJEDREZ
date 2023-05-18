
#pragma once

class Vector
{
	int x;
	int y;

public:

	Vector(int _x = 0, int _y = 0) :x(_x), y(_y) {}; // Constructor por defecto con inicialización por defecto a 0

	// FUNCIONES DE INTERFAZ
	int getx() { return x; }
	int gety() { return y; }
	void setx(int _x) { x = _x; }
	void sety(int _y) { y = _y; }
	void set(Vector v) { setx(v.x); sety(v.y); }

	// Sobrecarga del operador == para comparar dos vectores
	bool operator==(const Vector& v) {
		if (x == v.x && y == v.y)return true;
		else return false;
	}
};
