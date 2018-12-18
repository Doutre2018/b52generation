#include "Generation.h"
#include "Shape2D.h"
#include "Cercle.h"
#include "Point2d.h"
#include <iostream>
using namespace std;

int main()
{
	//Creation des variables pour créer la generation
	size_t width = 350;
	size_t height = 200;
	std::string type = "cercle";
	size_t nbShape = 30;
	size_t nbObstacles = 100;

	//Creation de Generation
	Generation g(width, height, type, nbShape, nbObstacles);

	//commencer la generation
	g.start();
	return 0;
}