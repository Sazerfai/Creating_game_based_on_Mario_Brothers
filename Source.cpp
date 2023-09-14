#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>
#include "Object.cpp"
#include "Camera.h"

using namespace sf;
using namespace std;


class Map  {
public:
	String TileMap[19] = {
	"                                                                        c                 ",
	"               c                                   c                                 c    ",
	"      c                                  c                      c        c                ",
	"                         c                                                                ",
	"          c                                        c                                      ",
	"                        c                                                        c        ",
	"      c       c                 c              c                 c                        ",
	"                                   m    e                                                 ",
	"                                   0000000000000000                                       ",
	"                                   0                                                      ",
	"                                   0              m                                       ",
	"0                                  0     00000000000                                     0",
	"0                                   0          0                                         0",
	"0                                    0  m      0                                         0",
	"0                                    00000     0                                         0",
	"0                0           0000             0                                          0",
	"0               0           0           m    0                                           0",
	"0 t       t   0   e      s0    t 000000000000 m                                          0",
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	};
};

class Object {
public:
	float dx, dy, x, y, speed;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;
	Object(Image& image, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; 
		speed = 0; health = 3; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
	~Object();
};
/////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player :public Object {
public:
	enum { left, right, up, down, jump, stay } state;// тип перечисления - состояние объекта
	int playerScore;
	Player(Image& image, float X, float Y, int W, int H, String Name) :Object(image, X, Y, W, H, Name) {
		playerScore = 0; state = stay;
		float currentFrame = 0;

		if (name == "Player1") {
			sprite.setTextureRect(IntRect(0, 0, w + 120, 210));
		}
	}
	~Player();
	void control() {
		if (Keyboard::isKeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				state = left; speed = 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = 0.1;
			}

			if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//если нажата клавиша вверх и мы на земле, то можем прыгать
				state = jump; dy = -0.6; onGround = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down;
			}
		}
	}
	void update(float time, Map carta)
	{
		control();
		switch (state)
		{
		case right: dx = speed;break;//состояние идти вправо
		case left: dx = -speed;break;//состояние идти влево
		case up: break;
		case down: break;
		case jump: break;
		case stay: break;
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0, carta);//обрабатываем столкновение по Х
		y += dy * time;
		checkCollisionWithMap(0, dy, carta);//обрабатываем столкновение по Y
		if (!isMove) speed = 0;
		sprite.setPosition(x, y);
		if (health <= 0) { life = false; }
		dy = dy + 0.0015 * time;
	}

	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}

	void checkCollisionWithMap(float Dx, float Dy, Map carta)//ф ция проверки столкновений с картой
	{
		for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (carta.TileMap[i][j] == '0')
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx > 0) { x = j * 32 - w; }
					if (Dx < 0) { x = j * 32 + 32; }
				}
				if (carta.TileMap[i][j] == 'm') {
					carta.TileMap[i][j] = ' ';
					playerScore = playerScore + 50;
				}
				if (carta.TileMap[i][j] == 'e') {
					carta.TileMap[i][j] = ' ';
					health = health - 1;
				}
				if (carta.TileMap[i][j] == 's') {
					carta.TileMap[i][j] = ' ';
					playerScore = playerScore + 50;
					health = health - 1;
				}

			}
	}
};


int main()
{


	RenderWindow window(VideoMode(1216, 608), "Super Mario Bros.");
	view.reset(FloatRect(0, 0, 1216, 608));

	Font font;
	font.loadFromFile("C:\\Users\\RedNewty\\Desktop\\Course work\\Code\\Font.ttf");
	Text text("", font, 22);
	Font font1;
	font1.loadFromFile("C:\\Users\\RedNewty\\Desktop\\Course work\\Code\\Font.ttf");
	Text text1("", font1, 60);
	Image map_image;
	map_image.loadFromFile("C:\\Users\\RedNewty\\Desktop\\Course work\\Code\\f_map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Image heroImage;
	heroImage.loadFromFile("C:\\Users\\RedNewty\\Desktop\\Course work\\Code\\hero1.png");
	heroImage.createMaskFromColor(Color::Black);

	Player p(heroImage, 100, 502.5, 50, 60, "Player1");
	p.sprite.scale(0.35, 0.35);
	Map carta;
	
	float currentFrame = 0;
	Clock clock;
	float dX = 0;
	float dY = 0;
	Clock gameTimeClock;//переменная игрового времени
	int gameTime = 0;
	float CurrentFrame = 0;

	while (window.isOpen())
	{
		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds(); 
		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;



		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

/////////////Управление персонажем с анимацией/////////////
{
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
				p.state = p.right; p.speed = 120;
				CurrentFrame += time * 0.005;
				if (CurrentFrame > 1.5) CurrentFrame -= 1;
				p.sprite.setTextureRect(IntRect(170 * int(CurrentFrame), 210, 170, 210));

			}
			if (sf::Keyboard::isKeyPressed(Keyboard::Right)) {
				p.state = p.left; p.speed = 120;
				CurrentFrame += time * 0.005;
				if (CurrentFrame > 1.5) CurrentFrame -= 1;
				p.sprite.setTextureRect(IntRect(170 * int(CurrentFrame), 0, 170, 210));
			}
			if (sf::Keyboard::isKeyPressed(Keyboard::Up)) {
				p.state = p.up; p.speed = 120;
				p.sprite.setTextureRect(IntRect(0, 420, 170, 210));
			}
		}

		p.update(time, carta);
		window.setView(view);
		window.clear();

		for (int i = 0; i < 19; i++)
			for (int j = 0; j < 91; j++)
			{
				if (carta.TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(64, 0, 32, 32)); 
				if (carta.TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(96, 0, 32, 32));  
				if ((carta.TileMap[i][j] == 'c')) s_map.setTextureRect(IntRect(32, 0, 32, 32)); 
				if ((carta.TileMap[i][j] == 't')) s_map.setTextureRect(IntRect(0, 0, 32, 32));  
				if ((carta.TileMap[i][j] == 'm')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
				if ((carta.TileMap[i][j] == 's')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
				if ((carta.TileMap[i][j] == 'e')) s_map.setTextureRect(IntRect(192, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}

		window.draw(p.sprite);
		if (p.life == 0) {
			text1.setString("Game over");

		}
		if (p.playerScore >= 200) {
			text1.setString("You win");
		}
		std::ostringstream playerScoreString, playerHealthString, gameTimeString;
		playerHealthString << p.health;
		playerScoreString << p.playerScore;
		gameTimeString << gameTime;
		text.setString("Player score: " + playerScoreString.str() + "    Player health: "
			+ playerHealthString.str() + "  Time in game: " + gameTimeString.str());
		text.setPosition(view.getCenter().x - 600, view.getCenter().y - 300);//задаем позицию текста, отступая от центра камеры
		window.draw(text);
		text1.setPosition(view.getCenter().x - 100, view.getCenter().y);
		window.draw(text1);
		window.display();
	}
	return 0;
}

