#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>
#include "Object.cpp"
#include "Player.cpp"
#include "Camera.h"

using namespace sf;


class Player { // класс Игрока
private: float x, y;//объявили переменные, в конструкторе Player ниже дадим им значения
public:
	float w, h, dx, dy, speed;
	int dir; 
	String File;
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	Player(String F, float X, float Y, float W, float H) { 
		dx = 0;dy = 0;speed = 0;dir = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile("D:\\" + File);
		image.createMaskFromColor(Color::Black);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(1320, 0, 170, 210));
	}
	float getplayercoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float getplayercoordinateY() {	//этим методом будем забирать координату Y 	
		return y;
	}
};


int main()
	{
		srand(static_cast<unsigned int>(time(0)));
		RenderWindow window(VideoMode(1200, 600), "Super Mario Bros.");
		view.reset(sf::FloatRect(0, 0, 1200, 600));

		Texture texture1;
		texture1.loadFromFile("D:\\background.jpg");
		Sprite backgroundsprite(texture1);

		Texture texture2;
		texture2.loadFromFile("D:\\ground.png");
		Sprite groundsprite(texture2);

		groundsprite.scale(0.2, 0.2);

		Player p("mario.png", 1320, 0, 170, 210);

		//Texture herotexture;//создаем объект Texture (текстура)
		//herotexture.loadFromFile("C:\\Users\\RedNewty\\Desktop\\Course work\\Code\\hero.png");//загружаем картинку
		//Sprite herosprite(herotexture);//создаем объект Sprite(спрайт)
		//herosprite.setTextureRect(IntRect(560, 0, 137.5, 160));

		p.sprite.scale(0.35, 0.35);
		p.sprite.setPosition(100, 475);
		Clock clock;
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время

		time = time / 8000; //скорость игры
		//float CurrentFrame = 170;
		
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
				
				p.sprite.move(-90 * time, 0);
				p.sprite.setTextureRect(IntRect(1090, 0, 170, 210));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}
			if (sf::Keyboard::isKeyPressed(Keyboard::Right)) { 
				p.sprite.move(90 * time, 0);
				p.sprite.setTextureRect(IntRect(1320, 0, 170, 210));
				getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}
			window.setView(view);
			window.clear();

			window.draw(backgroundsprite);
			groundsprite.setPosition(0, 550);
			window.draw(groundsprite);
			groundsprite.setPosition(400, 550);
			window.draw(groundsprite);
			groundsprite.setPosition(800, 550);
			window.draw(groundsprite);
			
			//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) { 
			//	CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			//	if (CurrentFrame > 4) CurrentFrame -= 4; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			//	p.sprite.setTextureRect(IntRect(1320 * int(CurrentFrame), 0, 170, 210)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
			//	p.sprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
			//	p.sprite.move(0, -0.1 ); }
			//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) { p.sprite.move(0, 0.1); }

			window.draw(p.sprite);

			window.display();
		}

		return 0;
	}

