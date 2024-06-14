/*
*  _____                   ____                           _               __  __       _                              _
* | ____|_ __   __ _   _  |  _ \ __ _ _ __ ___   __ _  __| | __ _ _ __   |  \/  | ___ | |__   __ _ _ __ ___   ___  __| |
* |  _| | '_ \ / _` | (_) | |_) / _` | '_ ` _ \ / _` |/ _` |/ _` | '_ \  | |\/| |/ _ \| '_ \ / _` | '_ ` _ \ / _ \/ _` |
* | |___| | | | (_| |  _  |  _ < (_| | | | | | | (_| | (_| | (_| | | | | | |  | | (_) | | | | (_| | | | | | |  __/ (_| |
* |_____|_| |_|\__, | (_) |_| \_\__,_|_| |_| |_|\__,_|\__,_|\__,_|_| |_| |_|  |_|\___/|_| |_|\__,_|_| |_| |_|\___|\__,_|
*              |___/
*/

#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <deque>
using namespace std;
enum Direction { Top, Down, Right, Left, Stop };
enum Level{Level1=150,Level2=100,Level3=50};
struct Location
{
	int _x;
	int _y;
	Location():_x(0),_y(0){}
	Location(int x,int y):_x(x),_y(y){}
};
struct Map
{
	int _height;
	int _width;
	Map():_height(0),_width(0){}
};
struct FoodLocation
{
	Location foodLoc;
};
struct Snake
{
	deque<Location> snakeLocations;
	int tall;
	Direction dir;
};
class Game
{
private:
	bool Lose;
	Level myLevel;
	Map myMap;
	FoodLocation myFood;
	Snake mySnake;
	int score;
public:
	Game()
	{
		Lose = false;
		score = 0;
	}
	void setMap(int width, int height)
	{
		myMap._height = height;
		myMap._width = width;
		setSnake();
		do
		{
			setFood();
		} while ((mySnake.snakeLocations.front()._x == myFood.foodLoc._x && mySnake.snakeLocations.front()._y == myFood.foodLoc._y)
				||isSnakeHere(myFood.foodLoc._y, myFood.foodLoc._x));
	}
	void setLevel(Level level)
	{
		myLevel = level;
	}
	void setSnake()
	{
		mySnake.snakeLocations.push_back(Location(myMap._width / 2, myMap._height / 2));
	}
	void setFood()
	{
		srand(time(NULL));
		myFood.foodLoc._x = rand() % (myMap._width - 2) + 1;
		myFood.foodLoc._y = rand() % (myMap._height - 2) + 1;
	}
	void takeInput()
	{
		char ch = '\0';
		if (_kbhit())
		{
			ch = _getch();
			switch (tolower(ch))
			{
			case'w':
				if(mySnake.dir!=Down)
					mySnake.dir = Top;
				break;
			case 's':
				if (mySnake.dir != Top)
					mySnake.dir = Down;
				break;
			case 'd':
				if (mySnake.dir != Left)
					mySnake.dir = Right;
				break;
			case 'a':
				if (mySnake.dir != Right)
					mySnake.dir = Left;
				break;
			}
		}
	}
	void move()
	{
		Sleep(myLevel);
		switch (mySnake.dir)
		{
		case Top:
			mySnake.snakeLocations.push_front(Location(mySnake.snakeLocations.front()._x, mySnake.snakeLocations.front()._y - 1)); // Add new head position
			if (mySnake.snakeLocations.size() > mySnake.tall)
			{
				mySnake.snakeLocations.pop_back();
			}
			Sleep(myLevel+20);
			break;
		case Down:
			mySnake.snakeLocations.push_front(Location(mySnake.snakeLocations.front()._x, mySnake.snakeLocations.front()._y + 1)); // Add new head position
			if (mySnake.snakeLocations.size() > mySnake.tall)
			{
				mySnake.snakeLocations.pop_back();
			}
			Sleep(myLevel+20);
			break;
		case Left:
			mySnake.snakeLocations.push_front(Location(mySnake.snakeLocations.front()._x - 1, mySnake.snakeLocations.front()._y)); // Add new head position
			if (mySnake.snakeLocations.size() > mySnake.tall)
			{
				mySnake.snakeLocations.pop_back();
			}
			break;
		case Right:
			mySnake.snakeLocations.push_front(Location(mySnake.snakeLocations.front()._x + 1, mySnake.snakeLocations.front()._y)); // Add new head position
			if (mySnake.snakeLocations.size() > mySnake.tall)
			{
				mySnake.snakeLocations.pop_back();
			}
			break;
		}
		increaseTallAndGenerateFood();
	}
	bool isEatFood()
	{
		if (mySnake.snakeLocations.front()._x == myFood.foodLoc._x && mySnake.snakeLocations.front()._y == myFood.foodLoc._y)
			return true;
		return false;
	}
	void increaseTallAndGenerateFood()
	{
		if (isEatFood())
		{
			mySnake.tall++;
			setFood();
			Location added;
			switch (mySnake.dir)
			{
			case Top:

				added._x = mySnake.snakeLocations.back()._x;
				if(mySnake.snakeLocations.back()._y + 1!= myMap._height - 1)
					added._y = mySnake.snakeLocations.back()._y + 1;
				else
				{
					added._y = mySnake.snakeLocations.back()._y;
					if (mySnake.snakeLocations.back()._x - 1 != 0)
						added._x = mySnake.snakeLocations.back()._x - 1;
					else
						added._x = mySnake.snakeLocations.back()._x + 1;
				}
				break;
			case Down:
				added._x = mySnake.snakeLocations.back()._x;
				if (mySnake.snakeLocations.back()._y - 1 != 0)
					added._y = mySnake.snakeLocations.back()._y - 1;
				else
				{
					added._y = mySnake.snakeLocations.back()._y;
					if (mySnake.snakeLocations.back()._x - 1 != 0)
						added._x = mySnake.snakeLocations.back()._x - 1;
					else
						added._x = mySnake.snakeLocations.back()._x + 1;
				}
				break;
			case Left:
				added._y = mySnake.snakeLocations.back()._y;
				if (mySnake.snakeLocations.back()._x + 1 != myMap._height - 1)
					added._x = mySnake.snakeLocations.back()._x + 1;
				else
				{
					added._x = mySnake.snakeLocations.back()._x;
					if (mySnake.snakeLocations.back()._y - 1 != 0)
						added._y = mySnake.snakeLocations.back()._y - 1;
					else
						added._y = mySnake.snakeLocations.back()._y + 1;
				}
				break;
			case Right:
				added._y = mySnake.snakeLocations.back()._y;
				if (mySnake.snakeLocations.back()._x - 1 != 0)
					added._x = mySnake.snakeLocations.back()._x - 1;
				else
				{
					added._x = mySnake.snakeLocations.back()._x;
					if (mySnake.snakeLocations.back()._y - 1 != 0)
						added._y = mySnake.snakeLocations.back()._y - 1;
					else
						added._y = mySnake.snakeLocations.back()._y + 1;
				}
				break;
			}
			mySnake.snakeLocations.push_back(added);
		}
	}
	bool isSnakeHere(int r,int c)
	{
		for (int i = 0; i < mySnake.snakeLocations.size(); i++)
		{
			if (mySnake.snakeLocations[i]._x == c && mySnake.snakeLocations[i]._y == r)
				return true;
		}
		return false;
	}
	void Draw()
	{
		system("cls");
		for (int r = 0; r < myMap._height; r++)
		{
			for (int c = 0; c < myMap._width; c++)
			{
				if (r == 0 || r == (myMap._height - 1) || c == 0 || c == (myMap._width - 1))
					cout << "\033[31m" << "#" << "\033[0m";
				else if (myFood.foodLoc._x == c && myFood.foodLoc._y == r)
					cout <<"\033[32m"<< "@" << "\033[0m";
				else if (isSnakeHere(r,c))
					cout << "\033[36m" << "O" << "\033[0m";
				else
					cout << " ";
			}
			cout << endl;
		}
		cout << endl << "\033[32m" << "Score : " << mySnake.tall << "\033[0m" << endl;
	}
	bool isLose()
	{
		if (mySnake.snakeLocations.front()._x == 0 || mySnake.snakeLocations.front()._x == (myMap._width - 1))
			Lose = true;
		else if (mySnake.snakeLocations.front()._y == 0 || mySnake.snakeLocations.front()._y == (myMap._height - 1))
			Lose = true;
		return Lose;
	}
	void resetTheGame()
	{
		Lose = false;
		score = 0;
		mySnake.dir = Stop;
		mySnake.tall = 0;
		mySnake.snakeLocations.clear();
		setSnake();
		setFood();
	}
};
int main()
{
	Game myGame;
	char again = '\0';
	char level = '\0';
	do
	{
		cout << "Enter the level you want ( 1 , 2 , 3 ) : ";
		cin >> level;
	} while (level != '1' && level != '2' && level != '3');
	
	switch (level)
	{
	case '1':
		myGame.setMap(60, 20);
		myGame.setLevel(Level1);
		break;
	case '2':
		myGame.setMap(50, 15);
		myGame.setLevel(Level2);
		break;
	case '3':
		myGame.setMap(40, 10);
		myGame.setLevel(Level3);
		break;
	}
	cout << "\033[32m" << "Let's Start The Game" << "\033[0m";
	Sleep(500);
	cout << "\033[32m" << "." << "\033[0m";
	Sleep(500);
	cout << "\033[32m" << "." << "\033[0m";
	Sleep(500);
	cout << "\033[32m" << "." << "\033[0m";
	Sleep(500);
	do
	{
		myGame.resetTheGame();
		while (!myGame.isLose())
		{
			myGame.Draw();
			myGame.takeInput();
			myGame.move();
		}
		cout << endl << "\033[31m" << "Game Over..." << "\033[0m" << endl << endl;
		cout << "Do you want play again ( y to play again or any to not) ? : ";
		cin >> again;
	} while (tolower(again) == 'y');
	cout << endl << "\033[32m" << "Thanks For Playing My Game (^_^)" << "\033[0m" << endl;
	return 0;
}
