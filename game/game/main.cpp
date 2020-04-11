#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Player.h"
#include "Npc.h"
#define HeroX 50
#define HeroY 50
#define ScreenX 1024
#define ScreenY 720
#define TILE 100

const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 
using namespace sf;

sf::String TileMap[HEIGHT_MAP] = {
"AAAAAAAAAAA4AA8BBBBBBBBBB4AA8CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"bbbbbabbbbb4008bbabbbbabb4008bbbbbabbbbb",
"zzzzz1zzzzz4008yy1yyyy1yy4008xxxxx1xxxxx",
"2222222222230092222222222300922222222222",
"0000000000000000000000000000000000000000",
"xyzxyzxyzxy1001zxyzxyzxyz1001xyzxyzxyzxy",
"0000000000000000000000000000000000000000",
"6666666666650076666666666500766666666666",
"qqqqqqqqqpq400800000000004008ssssssssssv",
"qpqpppppqpq400800000000004008sssssssssvw",
"qpqpqqqpqpq400800000000004008ssssssssvwr",
"qpppqpppqpq400800000000004008sssssssvwrr",
"qpqqqpqpqpq400800000000004008sssssssurrr",
"qpqpppqpqpq400800000000004008ssssssvwrrr",
"qpqpqpqpqpq400800000000004008sssssvwrrrr",
"qpqqqpqqqpq400800000000004008ssssvwrrrrr",
"qpppqpppppq400800000000004008ssvtwrrrrrr",
"qqqqqqqqqqq400800000000004008vtwrrrrrrrr", };

sf::String TileMap0[HEIGHT_MAP] = {
"AAAAAAAAAAAffffBBBBBBBBBBffffCCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"AAAAAAAAAAA4008BBBBBBBBBB4008CCCCCCCCCCC",
"dddddaddddd4008ddaddddadd4008dddddaddddd",
"fzzzz1zzzzz4008yy1yyyy1yy4008xxxxx1xxxxf",
"f222222SS223ii922222T22223ii92222222222f",
"f0000000000h00h0000000000h00h0000000000f",
"fyzxyzxyzxy1001zxyzxyzxyz1001xyzxyzxyzxf",
"f0000000000h00h0000000000h00h0000000000f",
"f66666666665ii766666666665ii76666666666f",
"qpqqqqqqqqq400811111111114008sQssssssQsf",
"qppppppRqpq40081xxx11xxx14008ssssQssssvf",
"qpqqqqqqqpq40081x111111x14008ssQsssssvwf",
"qpqpqpqpqpq40081x1yyyy1x14008sssssQsvwrf",
"qpqppqppqpq40081111yy11114008sQsssssurrf",
"qpqppqpqqpq4008111yyyy1114008ssssQsvwrrf",
"qpqppqqqppq40081z11yy11z14008sssssvwrrrf",
"qpqqqqYqqqq40081zz1111zz14008ssQsvwrrrrf",
"qpppppppppp40081111111jjj4008ssvtwrrrrrf",
"qqqqqqqqqqqfffffffffffffffffffffffffffff", };

sf::String TileMap1[HEIGHT_MAP] = {
"AAAAAAAAAAAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHKKHHJJHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHHHHHHHHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHMHHHHHHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHHHHHHHNHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHMHHHHHHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHHHHHHNHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"AHHHHIHHHHAZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"bbbbbZbbbbbZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"6666666666650076666666666500766666666666",
"qqqqqqqqqpq400800000000004008ssssssssssv",
"qpqpppppqpq400800000000004008sssssssssvw",
"qpqpqqqpqpq400800000000004008ssssssssvwr",
"qpppqpppqpq400800000000004008sssssssvwrr",
"qpqqqpqpqpq400800000000004008sssssssurrr",
"qpqpppqpqpq400800000000004008ssssssvwrrr",
"qpqpqpqpqpq400800000000004008sssssvwrrrr",
"qpqqqpqqqpq400800000000004008ssssvwrrrrr",
"qpppqpppppq400800000000004008ssvtwrrrrrr",
"qqqqqqqqqqq400800000000004008vtwrrrrrrrr", };

sf::String TileMap2[HEIGHT_MAP] = {
"ZZZZZZZZZZZZZZZBBBBBBBBBBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHJHKKHJHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHHHHHHHHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHLHHHHLHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHHHHHHHHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBMIHHHHIMBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHHHHHHHHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZBHIHHHHIHBZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZbbZbbbbZbbZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"xyzxyzxyzxy1001zxyzxyzxyz1001xyzxyzxyzxy",
"0000000000000000000000000000000000000000",
"6666666666650076666666666500766666666666",
"qqqqqqqqqpq400800000000004008ssssssssssv",
"qpqpppppqpq400800000000004008sssssssssvw",
"qpqpqqqpqpq400800000000004008ssssssssvwr",
"qpppqpppqpq400800000000004008sssssssvwrr",
"qpqqqpqpqpq400800000000004008sssssssurrr",
"qpqpppqpqpq400800000000004008ssssssvwrrr",
"qpqpqpqpqpq400800000000004008sssssvwrrrr",
"qpqqqpqqqpq400800000000004008ssssvwrrrrr",
"qpppqpppppq400800000000004008ssvtwrrrrrr",
"qqqqqqqqqqq400800000000004008vtwrrrrrrrr", };

sf::String TileMap3[HEIGHT_MAP] = {
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCCCCCCCCCCC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCKHHUHHHHJC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHMHHHMHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHMC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHNHHHNHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHNC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHIHHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZbbbbbZbbbbb",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"0000000000000000000000000000000000000000",
"6666666666650076666666666500766666666666",
"qqqqqqqqqpq400800000000004008ssssssssssv",
"qpqpppppqpq400800000000004008sssssssssvw",
"qpqpqqqpqpq400800000000004008ssssssssvwr",
"qpppqpppqpq400800000000004008sssssssvwrr",
"qpqqqpqpqpq400800000000004008sssssssurrr",
"qpqpppqpqpq400800000000004008ssssssvwrrr",
"qpqpqpqpqpq400800000000004008sssssvwrrrr",
"qpqqqpqqqpq400800000000004008ssssvwrrrrr",
"qpppqpppppq400800000000004008ssvtwrrrrrr",
"qqqqqqqqqqq400800000000004008vtwrrrrrrrr", };

sf::String TileMap4[HEIGHT_MAP] = {
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCCCCCCCCCCC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCKHHHHHHHJC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHMHHMHHMHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHNHHHNHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHNC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHHHHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZCHHHHIHHHHC",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZbbbbbZbbbbb",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmmmmmmmmmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmZZZZZZZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmZoZnZoZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmZZZVZZZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmZZZZZZZmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZmmmmZmmmmZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ", };


View view;



void getplayercoordinateforview(float x, float y)
{
	view.setCenter(x, y);
}

void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/play2.png");
	menuTexture2.loadFromFile("images/exit2.png");
	menuBackground.loadFromFile("images/LoGo.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 60);
	menu2.setPosition(100, 120);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 60, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu1.setColor(Color::Blue);
			menuNum = 1;
		}
		else
		{
			menu1.setColor(Color::White);
		}
		if (IntRect(100, 120, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu2.setColor(Color::Blue);
			menuNum = 2;
		}
		else
		{
			menu2.setColor(Color::White);
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	////////////////////////////////////////////////////
}

void pause(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/play2.png");
	menuTexture2.loadFromFile("images/exit2.png");
	menuBackground.loadFromFile("images/LoGo.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(-833, -520);
	menu2.setPosition(-833, -470);
	menuBg.setPosition(-960, -539);
	view.setCenter(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		window.clear();
		window.setView(view);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 60, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu1.setColor(Color::Blue);
			menuNum = 1;
		}
		else
		{
			menu1.setColor(Color::White);
		}
		if (IntRect(100, 120, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu2.setColor(Color::Blue);
			menuNum = 2;
		}
		else
		{
			menu2.setColor(Color::White);
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	////////////////////////////////////////////////////
}


/////////////////////////////////////ТЕКСТ МИССИИ/////////////////////////////////
std::string getTextMission(int currentMission) {

	std::string missionText = "";//текст миссии и его инициализация
	switch (currentMission)//принимается номер миссии и в зависимости от него переменной missionText присваивается различный текст
	{
	case 33: missionText = "\nТы сдал кота\n барыге на шавуху"; break;
	case 2: missionText = "\n Помоги найти\n котика "; break;
	case 22: missionText = "Вы помогли \n найти кота"; break;
	case 3: missionText = "\nПринеси кота \n барыге или отнеси \n девочке"; break;
	case 1: missionText = "Помоги найти \nтаблетки"; break;
	case 11: missionText = "ВЫ помогли  \n дедушке найти \nтаблетки"; break;
	case 4: missionText = "2+2\n =5 нажмите Z \n =4 нажмите X"; break;
	case 44: missionText = "Правильный ответ"; break;
	case 5: missionText = "sin(ln(5))\n =0.005 нажмите Z \n =0.028 нажмите X"; break;
	case 55: missionText = "Неправильный ответ"; break;
	}

	return missionText;//ф-ция возвращает текст
};


int main()
{
//	bool pasxalka=0;
	int sflag = 0;
	//int mission = 1;
	bool npcflag = 1, devflag=1;
	setlocale(LC_ALL, "Russian");
	float CurrentFrame=0;
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	Text pasx("", font, 20);
	text.setStyle(Text::Bold | Text::Underlined);
	text.setFillColor(sf::Color::Black);
	pasx.setStyle(Text::Bold | Text::Underlined);
	pasx.setFillColor(sf::Color::White);
	RenderWindow window(VideoMode(1920, 1080), "Game", Style::Fullscreen);
	//RenderWindow window(VideoMode(1024, 720), "Game");
	view.reset(FloatRect(0, 0, 1920, 1080));

	Clock clock;
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	int score=0, mysor=0;
	Image pasxa;
	pasxa.loadFromFile("images/text.png");
	//pasxa.createMaskFromColor(Color(255, 0, 255));
	Sprite pasxaSpr;
	Texture pasxaTex;
	pasxaTex.loadFromImage(pasxa);
	pasxaSpr.setTexture(pasxaTex);
	pasxaSpr.setPosition(800, 1200);
	Image quest_image;
	quest_image.loadFromFile("images/missionbg.jpg");
	quest_image.createMaskFromColor(Color(255, 0, 255));
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite s_quest;
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0, 0, 340, 510));
	s_quest.setScale(0.6f, 0.6f);

	Player player("hero.png", 200, 400, HeroX, HeroY);
	Npc npc("npc1.png", 600, 1000, HeroX, HeroY);
	Npc dev("npc2.png", 1125, 1000, HeroX, HeroY);
	Npc std("mpc3.png", 1425, 1000, HeroX, HeroY);
	Npc useless("npc0.png", 2000, 2000, HeroX, HeroY);
	useless.dir = 1;
	Npc useless0("npc0.png", 1500, 1500, HeroX, HeroY);
	useless0.dir = 1;
	Npc useless1("npc0.png", 2500, 2000, HeroX, HeroY);
	useless1.dir = 4;
	Npc useless2("npc0.png", 2850, 2500, HeroX, HeroY);
	useless2.dir = 4;
	std.dir = 1;
	dev.dir = 3;
	bool showMissionText = true, flag = true;
	menu(window);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if ((event.key.code == Keyboard::Tab))
			{
				flag = !flag;

				switch (showMissionText)
				{
				case true:
				{
					std::ostringstream playerCarmaString;//строка здоровья игрока
					playerCarmaString << player.carma;
					std::ostringstream task;//строка текста миссии
					task << getTextMission(player.mission);//вызывается функция getTextMission (она возвращает текст миссии), которая принимает в качестве аргумента функцию getCurrentMission(возвращающую номер миссии), а уже эта ф-ция принимает в качестве аргумента функцию p.getplayercoordinateX() (эта ф-ция возвращает Икс координату игрока)
					text.setString(task.str());
					if (flag)
						showMissionText = false;//эта строка позволяет убрать все что мы вывели на экране
					break;//выходим , чтобы не выполнить условие "false" (которое ниже)
				}
				case false:
				{
					text.setString("");//если не нажата клавиша таб, то весь этот текст пустой
					if (flag)
						showMissionText = true;// а эта строка позволяет снова нажать клавишу таб и получить вывод на экран
					break;
				}
				}
			}
		}
		float speed = 0.4;
			if (player.playerscore == -1)
			{
				sflag = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				pause(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.dir = 1; player.speed = speed;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 4)
					CurrentFrame = 0;
				player.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY, HeroX, HeroY));
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.dir = 2; player.speed = speed;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 4)
					CurrentFrame = 0;
				player.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*2, HeroX, HeroY));
			}
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.dir = 3; player.speed = speed;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 4)
					CurrentFrame = 0;
				player.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*3, HeroX, HeroY));
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.dir = 4; player.speed = speed;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 4)
					CurrentFrame = 0;
				player.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY *0, HeroX, HeroY));
			}
			if (Keyboard::isKeyPressed(Keyboard::X))
			{
				player.mission = 44;
				player.carma += 50;
				score = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Z))
			{
				player.mission = 55;
				player.carma -= 100; 
					score = -1;
			}
			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				if (player.interact1==1)
				{
					mysor = +1;
					player.carma += 1;
				}
				
			}
			if (1)
			{
				if (devflag)
				{
					dev.speed = 0.1;

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					dev.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY, HeroX, HeroY));
				}
			}
			if (1)
			{
				if (devflag)
				{
					useless.speed = 0.1;

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					useless.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*useless.dir, HeroX, HeroY));
				}
			}
			if (1)
			{
				if (devflag)
				{
					useless0.speed = 0.1;

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					useless0.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*useless0.dir, HeroX, HeroY));
				}
			}
			if (1)
			{
				if (devflag)
				{
					useless1.speed = 0.1;

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					useless1.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*useless1.dir, HeroX, HeroY));
				}
			}
			if (1)
			{
				if (devflag)
				{
					useless2.speed = 0.1;

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					useless2.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), HeroY*useless2.dir, HeroX, HeroY));
				}
			}
			if (1)
			{
				if (npcflag)
				{

					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					npc.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), 0*HeroY, HeroX, HeroY));
				}
			}
			if (player.getplayercoordinateX()>=npc.getplayercoordinateX()-HeroX && player.getplayercoordinateX() <= npc.getplayercoordinateX() + HeroX && player.getplayercoordinateY() >= npc.getplayercoordinateY() - HeroY && player.getplayercoordinateY() <= npc.getplayercoordinateY() + HeroY && Keyboard::isKeyPressed(Keyboard::E))
			{
				///////////////ded
				npcflag = !npcflag;
				if (player.playerscore1 == 1)
				{
					player.mission = 11;
					player.carma += 10;
				}
				if (player.playerscore1 ==0)
					player.mission = 1;
			}

			if (1)
			{
				//std.dir = 1;
				std.speed = 0.1;
					CurrentFrame += 0.005*time;
					if (CurrentFrame > 4)
					{
						CurrentFrame = 0;
					}
					std.sprite.setTextureRect(IntRect(HeroX*int(CurrentFrame), (std.dir-1)*HeroY, HeroX, HeroY));

			}
			if (player.getplayercoordinateX() >= dev.getplayercoordinateX() - HeroX && player.getplayercoordinateX() <= dev.getplayercoordinateX() + HeroX && player.getplayercoordinateY() >= dev.getplayercoordinateY() - HeroY && player.getplayercoordinateY() <= dev.getplayercoordinateY() + HeroY && Keyboard::isKeyPressed(Keyboard::E))
			{
				///////////////devochka
				devflag = !devflag;
				dev.speed = 0;
				
				if (player.playerscore == 1)
				{
					player.mission = 22;
					player.carma += 10;
					player.playerscore = 3;
				}
				if (player.playerscore == 0)
					player.mission = 2;

			}
			if (player.getplayercoordinateX() >= std.getplayercoordinateX() - HeroX && player.getplayercoordinateX() <= std.getplayercoordinateX() + HeroX && player.getplayercoordinateY() >= std.getplayercoordinateY() - HeroY && player.getplayercoordinateY() <= std.getplayercoordinateY() + HeroY && Keyboard::isKeyPressed(Keyboard::E))
			{
				///////////////devochka
			
				std.speed = 0;

				if (player.playerscore2 == 1)
				{
					player.mission = 4;
				}
				if (player.playerscore2 == 0)
					player.mission = 5;
				
			}
			getplayercoordinateforview(player.getplayercoordinateX(), player.getplayercoordinateY());
			player.Move(time, TileMap, HEIGHT_MAP, WIDTH_MAP);
			npc.Move(time);
			dev.Move(time);
			std.Move(time);
			useless.Move(time);
			useless0.Move(time);
			useless1.Move(time);
			useless2.Move(time);
			window.setView(view);
			window.clear();
			
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					
					if (TileMap[i][j] == 'Y')
						s_map.setTextureRect(IntRect(0, TILE * 8, TILE, TILE));
					if (TileMap[i][j] == 'Z')
						s_map.setTextureRect(IntRect(0, TILE * 9, TILE, TILE));
					if (TileMap[i][j] == '0')
						s_map.setTextureRect(IntRect(0, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == '1')
						s_map.setTextureRect(IntRect(TILE * 6, 0, TILE, TILE));
					if (TileMap[i][j] == '2')
						s_map.setTextureRect(IntRect(TILE * 2, TILE, TILE, TILE));
					if (TileMap[i][j] == '3')
						s_map.setTextureRect(IntRect(TILE * 9, TILE, TILE, TILE));
					if (TileMap[i][j] == '4')
						s_map.setTextureRect(IntRect(TILE * 4, TILE, TILE, TILE));
					if (TileMap[i][j] == '5')
						s_map.setTextureRect(IntRect(TILE * 8, TILE, TILE, TILE));
					if (TileMap[i][j] == '6')
						s_map.setTextureRect(IntRect(TILE * 3, TILE, TILE, TILE));
					if (TileMap[i][j] == '7')
						s_map.setTextureRect(IntRect(TILE * 7, TILE, TILE, TILE));
					if (TileMap[i][j] == '8')
						s_map.setTextureRect(IntRect(TILE * 5, TILE, TILE, TILE));
					if (TileMap[i][j] == '9')
						s_map.setTextureRect(IntRect(TILE * 6, TILE, TILE, TILE));
					if (TileMap[i][j] == 'A')
						s_map.setTextureRect(IntRect(TILE * 2, TILE * 6, TILE, TILE));
					if (TileMap[i][j] == 'B')
						s_map.setTextureRect(IntRect(TILE * 2, TILE * 7, TILE, TILE));
					if (TileMap[i][j] == 'C')
						s_map.setTextureRect(IntRect(TILE * 2, TILE * 9, TILE, TILE));
					if (TileMap[i][j] == 'H')
						s_map.setTextureRect(IntRect(TILE * 4, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'I')
						s_map.setTextureRect(IntRect(TILE * 5, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'J')
						s_map.setTextureRect(IntRect(TILE * 6, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'K')
						s_map.setTextureRect(IntRect(TILE * 7, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'L')
						s_map.setTextureRect(IntRect(TILE * 8, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'M')
						s_map.setTextureRect(IntRect(TILE * 9, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'N')
						s_map.setTextureRect(IntRect(TILE * 9, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'Q')
						s_map.setTextureRect(IntRect(0, TILE * 7, TILE, TILE));
					if (TileMap[i][j] == 'a')
						s_map.setTextureRect(IntRect(TILE * 4, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'b')
						s_map.setTextureRect(IntRect(TILE * 5, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'c')
						s_map.setTextureRect(IntRect(TILE * 6, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'd')
						s_map.setTextureRect(IntRect(TILE * 7, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'e')
						s_map.setTextureRect(IntRect(TILE * 8, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'f')
						s_map.setTextureRect(IntRect(TILE * 6, TILE * 8, TILE, TILE));
					if (TileMap[i][j] == 'g')
						s_map.setTextureRect(IntRect(TILE * 6, TILE * 9, TILE, TILE));
					if (TileMap[i][j] == 'h')
						s_map.setTextureRect(IntRect(TILE, TILE * 3, TILE, TILE));
					
					if (TileMap[i][j] == 'i')
						s_map.setTextureRect(IntRect(TILE * 2, TILE * 3, TILE, TILE));
					if (TileMap[i][j] == 'm')
						s_map.setTextureRect(IntRect(TILE * 8, TILE * 9, TILE, TILE));
					if (TileMap[i][j] == 'n')
						s_map.setTextureRect(IntRect(TILE * 8, TILE * 7, TILE, TILE));
					if (TileMap[i][j] == 'o')
						s_map.setTextureRect(IntRect(TILE * 8, TILE * 8, TILE, TILE));
					if (TileMap[i][j] == 'p')
						s_map.setTextureRect(IntRect(TILE * 7, TILE * 9, TILE, TILE));
					if (TileMap[i][j] == 'q')
						s_map.setTextureRect(IntRect(0, TILE * 6, TILE, TILE));
					if (TileMap[i][j] == 'r')
						s_map.setTextureRect(IntRect(0, TILE * 5, TILE, TILE));
					if (TileMap[i][j] == 's')
						s_map.setTextureRect(IntRect(TILE, 0, TILE, TILE));
					if (TileMap[i][j] == 't')
						s_map.setTextureRect(IntRect(0, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'u')
						s_map.setTextureRect(IntRect(TILE, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'v')
						s_map.setTextureRect(IntRect(TILE * 2, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'w')
						s_map.setTextureRect(IntRect(TILE * 3, TILE * 4, TILE, TILE));
					if (TileMap[i][j] == 'x')
						s_map.setTextureRect(IntRect(TILE * 2, 0, TILE, TILE));
					if (TileMap[i][j] == 'y')
						s_map.setTextureRect(IntRect(TILE * 3, 0, TILE, TILE));
					if (TileMap[i][j] == 'f')
						s_map.setTextureRect(IntRect(TILE * 7, 0, TILE, TILE));
					if (TileMap[i][j] == 'z')
						s_map.setTextureRect(IntRect(TILE * 4, 0, TILE, TILE));   
					{
						if (TileMap[i][j] == 'j')//////////////////////////////////bariga
							s_map.setTextureRect(IntRect(TILE * 6, TILE * 9, TILE, TILE));
					}
					if(player.playerscore == -1)
					{
						if (TileMap[i][j] == 'j')
							s_map.setTextureRect(IntRect(TILE * 6, TILE * 8, TILE, TILE));
					}
					if (player.playerscore == 0)
					{
						if (TileMap[i][j] == 'R')///////////////////////////////////kot
							s_map.setTextureRect(IntRect(TILE * 7, TILE * 7, TILE, TILE));
					}
					else
					{
						if (TileMap[i][j] == 'R')
							s_map.setTextureRect(IntRect(TILE * 7, TILE * 9, TILE, TILE));
					}
					if (TileMap[i][j] == 'T')/////////////////////////////////////yrna
						s_map.setTextureRect(IntRect(TILE * 5, TILE *8, TILE, TILE));
					if (TileMap[i][j] == 'S')/////////////////////////////////////mysor
					{
						if(!mysor)
							s_map.setTextureRect(IntRect(TILE * 4, TILE * 8, TILE, TILE));
						else
							s_map.setTextureRect(IntRect(TILE * 2, TILE, TILE, TILE));
					}

					if (TileMap[i][j] == 'U')
					{
						if (player.playerscore1 == 0)
							s_map.setTextureRect(IntRect(TILE * 7, TILE * 8, TILE, TILE));
						else
							s_map.setTextureRect(IntRect(TILE * 8, TILE * 4, TILE, TILE));
					}
					if (TileMap[i][j] == 'V')
					{
						if (player.playerscore2 == 0)
							s_map.setTextureRect(IntRect(TILE * 6, TILE * 7, TILE, TILE));
						else
							s_map.setTextureRect(IntRect(0, TILE * 9, TILE, TILE));
					}
						
					
					s_map.setPosition(j * TILE, i * TILE);
					
					pasxaSpr.setPosition(450, 1800);
					
				window.draw(s_map);
			}
			
		if (!showMissionText)
		{
			text.setPosition(view.getCenter().x + 125, view.getCenter().y - 130);//позиция всего этого текстового блока
			s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);//позиция фона для блока			
			window.draw(s_quest); window.draw(text); //рисуем спрайт свитка (фон для текста миссии). а затем и текст. все это завязано на логическую переменную, которая меняет свое состояние от нажатия клавиши ТАБ
		}
		float x, y;
		x = player.getplayercoordinateX();
		y = player.getplayercoordinateY();
		if (x >= 0 && x <= 1000 && y >= 0 && y <= 899)
			for (int height = 0; height <= HEIGHT_MAP; height++)
				TileMap[height] = TileMap1[height];
		else if (x >= 1500 && x <= 2400 && y >= 0 && y <= 899)
			for (int height = 0; height <= HEIGHT_MAP; height++)
				TileMap[height] = TileMap2[height];
		else if (x >= 2900 && x <= 4000 && y >= 0 && y <= 899)
			for (int height = 0; height <= HEIGHT_MAP; height++)
				TileMap[height] = TileMap3[height];
		else if (x >= 200 && x <= 1000 && y >= 1700 && y <= 2200)
		{
			window.draw(pasxaSpr);
			for (int height = 0; height <= HEIGHT_MAP; height++)
				TileMap[height] = TileMap4[height];
			
			
		}
		else
			for (int height = 0; height <= HEIGHT_MAP; height++)
			{
				window.draw(std.sprite);
				window.draw(useless.sprite);
				window.draw(useless0.sprite);
				window.draw(useless1.sprite);
				window.draw(useless2.sprite);
				window.draw(npc.sprite);
				window.draw(dev.sprite);
				TileMap[height] = TileMap0[height];
			}
		window.draw(player.sprite);
	//	std::cout << "\n " << player.getplayercoordinateX() << "\n" << player.getplayercoordinateY();
		if ((player.playerscore == 3 || player.playerscore == -1) && player.playerscore1 == 1 && score != 0)
		{
			if (player.carma > 0)
			{
				Texture win;
				win.loadFromFile("images/win.png");
				Sprite swin(win);
				view.setCenter(0, 0);
				swin.setPosition(-960, -540);
				window.setView(view);
				window.clear();
				window.draw(swin);
				//	window.display();
			}
			else
			{
				Texture lose;
				lose.loadFromFile("images/lose.png");
				Sprite slose(lose);
				view.setCenter(0, 0);
				slose.setPosition(-960, -540);
				window.setView(view);
				window.clear();
				window.draw(slose);
				//	window.display();
			}
			
		}
		window.display();
		
		
	}
	

	return 0;
}