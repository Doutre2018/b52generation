#ifndef RANDOM_H
#define RANDOM_H
#include <random>

class Random
{
private:
	std::random_device generator;
	Random();
	~Random();
public:
	static Random& getInstance()
	{
		static Random instance;
		return instance;
	}
	int uniformRandomize(size_t min, size_t max);
};

#endif // RANDOM_H