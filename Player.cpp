#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cstdlib>

//class Player { // ����� ������
//public:
//	float x, y, w, h, dx, dy, speed; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
//	int dir; //����������� (direction) �������� ������
//	string File; //���� � �����������
//	Image image;//���� �����������
//	Texture texture;//���� ��������
//	Sprite sprite;//���� ������
//	Player(String F, float X, float Y, float W, float H) { //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
//		dx = 0;dy = 0;speed = 0;dir = 0;
//		File = F;//��� �����+����������
//		w = W; h = H;//������ � ������
//		image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");
//		image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
//		texture.loadFromImage(image);//���������� ���� ����������� � ��������
//		sprite.setTexture(texture);//�������� ������ ���������
//		x = X; y = Y;//���������� ��������� �������
//		sprite.setTextureRect(IntRect(0, 0, w, h)); //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
//	}