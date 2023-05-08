#pragma once

class Vector
{
	
public:
	float x;
	float y;
	Vector() :x(0), y(0) {}; // Constructor por defecto me inicializa con (0,0)
	Vector(float _x, float _y) :x(_x), y(_y) {}; // Constructor para inicializar variables
	
	bool operator==(const Vector& v) {
		if (x == v.x && y == v.y)return true;
		else return false;
	}

};


