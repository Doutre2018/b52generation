#include "Random.h"



Random::Random()
{
}


Random::~Random()
{
}

int Random::uniformRandomize(size_t min, size_t max)
{
	std::mt19937 gen(generator());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}