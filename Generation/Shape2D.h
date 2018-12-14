
#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>
#include <cmath>

class Shape2D
{
public:
	Shape2D();
	~Shape2D();


protected:
	virtual int64_t encodePropreties() = 0;

};

#endif //SHAPE2D_H