#include "StringSwitch.h"

int main()
{
	int x = 10;
	StringSwitch sw;
	sw.Capture("F") = [&x]() { std::cout << "Foo "<<x<<"\n"; };
	sw.Capture("B") = []() { std::cout << "Bar\n"; };
	sw.Default() = []() { std::cout << "What is that?\n"; };

	sw["F"];
	x++;
	sw["F"];
	sw["rg22tgg"];


	return 0;
}