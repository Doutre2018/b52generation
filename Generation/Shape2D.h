#pragma once
#include <vector>
#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>
#include "Point2d.h"
#include "Console\Console.h"
#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>


class Shape2D
{
public:
	Shape2D();
	~Shape2D();


	//virtual Point2d centerPoint();                code temporaire ds cpp en comment - under construction
	virtual int64_t encodePropreties() = 0;
	virtual void decodePropreties(int64_t data) = 0;

	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) = 0;
	virtual int calculateArea() = 0;
	virtual bool pointInShape() = 0;
<<<<<<< HEAD
	
=======
	virtual void randomize() = 0;
>>>>>>> de7c5c32e2542e3002b7c88309a95883dbc80901

protected:
	double mX;
	double mY;
	int mHeight;
	int mWidth;
	Point2d	mCloseCollider;
	double mArea;
	double solution;
	double fitness;
	std::string type = "Circle";    //hardcode temporaire, utile pour collisions
	std::vector<Shape2D*> shapePtrs;

};

#endif //SHAPE2D_H