#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;
View getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	if (x < 330) tempX = 330;
	view.setCenter(tempX +300 , 304); 
	return view;

} 
