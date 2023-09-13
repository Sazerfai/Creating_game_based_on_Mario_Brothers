#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>

//class Player { // класс Игрока
//public:
//	float x, y, w, h, dx, dy, speed; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
//	int dir; //направление (direction) движения игрока
//	string File; //файл с расширением
//	Image image;//сфмл изображение
//	Texture texture;//сфмл текстура
//	Sprite sprite;//сфмл спрайт
//	Player(String F, float X, float Y, float W, float H) { //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
//		dx = 0;dy = 0;speed = 0;dir = 0;
//		File = F;//имя файла+расширение
//		w = W; h = H;//высота и ширина
//		image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
//		image.createMaskFromColor(Color(41, 33, 59));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
//		texture.loadFromImage(image);//закидываем наше изображение в текстуру
//		sprite.setTexture(texture);//заливаем спрайт текстурой
//		x = X; y = Y;//координата появления спрайта
//		sprite.setTextureRect(IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
//	}