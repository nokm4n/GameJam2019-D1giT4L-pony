#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class Player
{
private:
	float x, y;
public:
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	float dx, dy, w, h, speed, carma=0;
	int dir, playerscore = 0, playerscore1 = 0, playerscore2 = 0, mission = 0, interact1 = 0;
	void Move(float, String[], int, int);
	void Collision(String[], int, int);
	float getplayercoordinateX();
	float getplayercoordinateY();
	Player(String, float, float, float, float);
	~Player();
};

