#include "Generation.h"
#include "Shape2D.h"
#include "Cercle.h"
#include "Point2d.h"
#include <iostream>
#include "debugstream.h"
using namespace std;





int main()
{
	//Creation des variables pour cr�er la generation
	size_t width = 350;
	size_t height = 200;
	std::string type = "cercle";
	size_t nbShape = 100;
	size_t nbObstacles = 10;



	debug()<< "tesst";
	//Creation de Generation
	Generation g(width, height, type, nbShape, nbObstacles);

	//commencer la generation
	g.start();
	return 0;
}