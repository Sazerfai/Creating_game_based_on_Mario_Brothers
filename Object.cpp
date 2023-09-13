#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace std;

class Object :public RectangleShape
{
private:
	int x = 100;
	int y = 100;
public:
	//string name;
	Object() {};
	Object(int new_x, int new_y);
	Object(Object& other);

	~Object() {};
	virtual void setPositionn(float new_x, float new_y);
	virtual Vector2f getPositionn();
	virtual void draww(RenderTarget& target) const;
};
