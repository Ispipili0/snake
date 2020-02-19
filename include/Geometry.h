#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <SDL2/SDL.h>
#include "math.h"

struct Vec
{
	public:

		Vec(const float x, const float y);

		Vec operator+(const Vec& operand);
		Vec operator-(const Vec& operand);
		Vec operator*(const Vec& operand);
		Vec operator/(const Vec& operand);
		Vec& operator+=(const Vec& operand);
		Vec& operator-=(const Vec& operand);
		Vec& operator*=(const Vec& operand);
		Vec& operator/=(const Vec& operand);
		Vec& operator=(const Vec& operand);

		float x, y;

		float getLength();
};

struct Rectangle
{
	public:
		Rectangle(const Vec& pos, const Vec& move);
		Rectangle(const float x, const float y, const float w, const float h);
		~Rectangle();
	
		void resize(const Vec& newSize);
		void move(const Vec& vec);

		SDL_Rect getSDLRect();

		Vec pos, size;
};

#endif
