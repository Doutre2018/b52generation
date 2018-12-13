#pragma once
class Area
{
private:
	Area();
	~Area();
public:
	void generatePoint();
	static Area& getInstance()
	{
		static Area instance;
		return instance;
	}
};

