#include "../include/Geometry.h"

Vec::Vec(const float x, const float y):x(x), 
	y(y)
{}

Vec Vec::operator+(const Vec& operand)
{
	return Vec(x+operand.x, y+operand.y);
}

Vec Vec::operator-(const Vec& operand)
{
	return Vec(x-operand.x, y-operand.y);
}

Vec Vec::operator*(const Vec& operand)
{
	return Vec(x*operand.x, y*operand.y);
}

Vec Vec::operator/(const Vec& operand)
{
	return Vec(x/operand.x, y/operand.y);
}

Vec& Vec::operator+=(const Vec& operand) 
{
	x += operand.x;
	y += operand.y;
	return *this;
}

Vec& Vec::operator-=(const Vec& operand) 
{	
	x -= operand.x;
	y -= operand.y;
	return *this;

}

Vec& Vec::operator*=(const Vec& operand) 
{
	x *= operand.x;
	y *= operand.y;
	return *this;
}

Vec& Vec::operator/=(const Vec& operand) 
{
	x /= operand.x;
	y /= operand.y;
	return *this;
}

Vec& Vec::operator=(const Vec& operand) 
{
	x = operand.x;
	y = operand.y;
	return *this;
}

float Vec::getLength()
{
	return sqrt(x*x + y*y);
}

//Rectangle


Rectangle::Rectangle(const Vec& pos, const Vec& move):pos(pos),
	size(size)
{}

Rectangle::Rectangle(const float x, const float y, const float w, const float h):pos(x, y),
	size(w, h)
{}

Rectangle::~Rectangle()
{}

void Rectangle::resize(const Vec& newSize)
{
	size += newSize;
}

void Rectangle::move(const Vec& vec)
{
	pos += vec;
}

SDL_Rect Rectangle::getSDLRect()
{
	SDL_Rect r;
	r.x = pos.x;
	r.y = pos.y;
	r.w = size.x;
	r.h = size.y;

	return r;
}

////////////////////////////////////////////
