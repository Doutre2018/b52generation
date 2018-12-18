#include "Generation.h"
#include "Shape2D.h"
#include "Cercle.h"
#include "Point2d.h"
#include <iostream>
using namespace std;

int main()
{
	Generation::getInstance().start(350,200,"cercle", 30, 100);
	return 0;
}