#include "Area.h"
#include "Console\Console.h"


Area::Area()
{
	ConsoleContext context(6000, 6000, "Guess the best solution!", 3,3 , L"Consolas");
	Console::defineContext(context);

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & area{ writer.createImage("area") };
	writer.push("area");
	area.fill(178, ConsoleColor::bK + ConsoleColor::tb);
}


Area::~Area()
{
}

void Area::generatePoint()
{
}
