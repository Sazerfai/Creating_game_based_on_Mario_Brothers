#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>
#include "Object.cpp"
using namespace sf;
using namespace std;

class MovableObject : public Object
{

public:
	int speed;
	int damage;
	int health;

	MovableObject() {};
	~MovableObject() {};

};
