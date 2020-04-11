#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#define HeroX 50
#define HeroY 50
#define TILE 100

using namespace sf;

void Player::Move(float time, String map[25], int height, int width)
{
	
	switch (dir)
	{
	case 1:
		dx = -speed;
		dy = 0;
		break;
	case 2:
		dx = speed;
		dy = 0;
		break;
	case 3:
		dy = -speed;
		dx = 0;
		break;
	case 4:
		dy = speed;
		dx = 0;
		break;
	}
	
	x += dx * time;
	y += dy * time;
	Collision(map, height, width);
	speed = dx = dy = 0;

	
	sprite.setPosition(x, y);
}

Player::Player(String F, float X, float Y, float W, float H)
{
	File = F;
	dx = dy = 0;
	File = F;
	w = W; h = H;
	image.loadFromFile("images/" + File);
	image.createMaskFromColor(Color(41, 33, 59));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
	sprite.setTextureRect(IntRect(0, 48, w, h));
}

float Player::getplayercoordinateX()
{
	return x;
}
float Player::getplayercoordinateY()
{
	return y;
}

Player::~Player()
{
}

void Player::Collision(String map[25], int Height, int Width)
{
	for (int i = y / TILE; i < (y + HeroY) / TILE; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
		for (int j = x / TILE; j < (x + HeroX) / TILE; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
		{
			if (map[i][j] == 'U' || map[i][j] == 'b' || map[i][j] == 'c' || map[i][j] == 'd' || map[i][j] == 'e' || map[i][j] == 'f' || map[i][j] == 'g' || map[i][j] == 'm' || map[i][j] == 'n' || map[i][j] == 'o' || map[i][j] == 'q' || map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'J' || map[i][j] == 'K' || map[i][j] == 'L' || map[i][j] == 'M' || map[i][j] == 'N' || map[i][j]=='jw')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
			{
				if (dy > 0)//���� �� ��� ����,
				{
					y = i * TILE - HeroY;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
				//	y -= HeroY/20;
				}
				if (dy < 0)
				{
					y = i * TILE + HeroY*2;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
				//	y += HeroY/20;
				}
				if (dx > 0)
				{
				//	x -= HeroX/20;
					x = j * TILE -HeroX;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
				}
				if (dx < 0)
				{
				//	x += HeroX/20;
					x = j * TILE + HeroX*2;//���������� ���� �����
				}
				
			}
			if (map[i][j] == 'x' || map[i][j] == 'y' || map[i][j] == 'z')
			{
				carma -= 0.01;
			}
			if (map[i][j] == 'j' ) // bariga
			{
				
				if (playerscore == 1)
				{
					mission = 33;
					playerscore = -1;
					carma -= 10;
				}
				if(playerscore==0)
					mission = 3;
			}
			if (map[i][j] == 'R') // kot
				playerscore = 1;
			if (map[i][j] == 'U')
				playerscore1 = 1;
			if (map[i][j] == 'S')
			{
				interact1 = 1;
			}
			if (map[i][j] == 'V')
				playerscore2 = 1;
		}
}
