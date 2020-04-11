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
	for (int i = y / TILE; i < (y + HeroY) / TILE; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
		for (int j = x / TILE; j < (x + HeroX) / TILE; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if (map[i][j] == 'U' || map[i][j] == 'b' || map[i][j] == 'c' || map[i][j] == 'd' || map[i][j] == 'e' || map[i][j] == 'f' || map[i][j] == 'g' || map[i][j] == 'm' || map[i][j] == 'n' || map[i][j] == 'o' || map[i][j] == 'q' || map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'J' || map[i][j] == 'K' || map[i][j] == 'L' || map[i][j] == 'M' || map[i][j] == 'N' || map[i][j]=='jw')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy > 0)//если мы шли вниз,
				{
					y = i * TILE - HeroY;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
				//	y -= HeroY/20;
				}
				if (dy < 0)
				{
					y = i * TILE + HeroY*2;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
				//	y += HeroY/20;
				}
				if (dx > 0)
				{
				//	x -= HeroX/20;
					x = j * TILE -HeroX;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
				}
				if (dx < 0)
				{
				//	x += HeroX/20;
					x = j * TILE + HeroX*2;//аналогично идем влево
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
