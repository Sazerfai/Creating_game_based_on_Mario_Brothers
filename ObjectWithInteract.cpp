#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>
#include "StationaryObject.cpp"
using namespace sf;
using namespace std;

class ObjectWithInteract : public StationaryObject
{

public:
	int points;


	ObjectWithInteract() {};
	~ObjectWithInteract() {};

};
