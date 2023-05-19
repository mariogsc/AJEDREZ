#pragma once

class Vector
{

public:

	int x;
	int y;

	Vector(int _x = 0, int _y = 0) :x(_x), y(_y) {}; // Constructor por defecto con inicialización por defecto a 0

	// Sobrecarga del operador == para comparar dos vectores
	bool operator==(const Vector& v) {
		if (x == v.x && y == v.y)return true;
		else return false;
	}

	bool operator != (const Vector& v) {
		if (x != v.x || y != v.y)return true;
		else return false;
	}

	bool operator < (const int& MAX) {
		if (x < MAX && y < MAX)return true;
		else return false;
	}
	bool operator >= (const int& MAX) {
		if (x >= MAX && y >= MAX)return true;
		else return false;
	}
};
