/*
*  _____                   ____                           _               __  __       _                              _
* | ____|_ __   __ _   _  |  _ \ __ _ _ __ ___   __ _  __| | __ _ _ __   |  \/  | ___ | |__   __ _ _ __ ___   ___  __| |
* |  _| | '_ \ / _` | (_) | |_) / _` | '_ ` _ \ / _` |/ _` |/ _` | '_ \  | |\/| |/ _ \| '_ \ / _` | '_ ` _ \ / _ \/ _` |
* | |___| | | | (_| |  _  |  _ < (_| | | | | | | (_| | (_| | (_| | | | | | |  | | (_) | | | | (_| | | | | | |  __/ (_| |
* |_____|_| |_|\__, | (_) |_| \_\__,_|_| |_| |_|\__,_|\__,_|\__,_|_| |_| |_|  |_|\___/|_| |_|\__,_|_| |_| |_|\___|\__,_|
*              |___/
*/
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
class XO_game
{
private:
	int Size;
	char** currentState;
	int* placeNumber;
	int x_Score;
	int y_Score;
	char currentPlayer;
	int countSteps;
public:
	XO_game(int s)
	{
		Size = s;
		placeNumber = new int[Size*Size];
		currentState = new char* [Size];
		for (int i = 0; i < Size; i++)
		{
			currentState[i] = new char[Size];
		}
		x_Score = 0;
		y_Score = 0;
		cout << "\033[32m" << "Let's Start The Game" << "\033[0m";
		Sleep(500);
		cout << "\033[32m" << "." << "\033[0m";
		Sleep(500);
		cout << "\033[32m" << "." << "\033[0m";
		Sleep(500);
		cout << "\033[32m" << "." << "\033[0m";
		Sleep(500);
		ResetTheGame();
	}
	void increaseX_Score()
	{
		x_Score++;
	}
	void increaseY_Score()
	{
		y_Score++;
	}
	void play()
	{
		int pos;
		bool isFound = false;
		do
		{
			int index = 0;
			cout << "Enter the position you want to mark ( player " << currentPlayer << " ) : ";
			cin >> pos;
			for (int row = 0; row < Size; row++)
			{
				for (int col = 0; col < Size; col++)
				{
					if (placeNumber[index] == pos)
					{
						currentState[row][col] = currentPlayer;
						placeNumber[index] = -1;
						isFound = true;
						countSteps++;
					}
					index++;
				}
			}
			if (!isFound)
			{
				cout << endl << "\033[31m" << "Not Allowed Here, Try Again." << "\033[0m";
				Sleep(1000);
				printCurrentState();
			}
		} while (!isFound);
		currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
		printCurrentState();
	}
	char isOver()
	{
		char ans = 'N';
		int count_X = 0, count_O = 0;
		for (int row = 0; row < Size; row++)
		{
			count_X = 0;
			count_O = 0;
			for (int col = 0; col < Size; col++)
			{
				if (currentState[row][col] == 'X')
					count_X++;
				else if (currentState[row][col] == 'O')
					count_O++;
			}
			if (count_X == Size)
			{
				ans = 'X';
				break;
			}
			else if (count_O == Size)
			{
				ans = 'O';
				break;
			}
		}
		if(ans!='N')
			return ans;
		count_X = 0;
		count_O = 0;
		for (int row = 0; row < Size; row++)
		{
			count_X = 0;
			count_O = 0;
			for (int col = 0; col < Size; col++)
			{
				if (currentState[col][row] == 'X')
					count_X++;
				else if (currentState[col][row] == 'O')
					count_O++;
			}
			if (count_X == Size)
			{
				ans = 'X';
				break;
			}
			else if (count_O == Size)
			{
				ans = 'O';
				break;
			}
		}
		if (ans != 'N')
			return ans;
		count_X = 0;
		count_O = 0;
		for (int diag = 0; diag < Size; diag++)
		{
			if (currentState[diag][diag] == 'X')
				count_X++;
			else if (currentState[diag][diag] == 'O')
				count_O++;
		}
		if (count_X == Size)
			ans = 'X';
		else if (count_O == Size)
			ans = 'O';
		if (ans != 'N')
			return ans;

		count_X = 0;
		count_O = 0;
		for (int diag = 0; diag < Size; diag++)
		{
			if (currentState[diag][Size-1-diag] == 'X')
				count_X++;
			else if (currentState[diag][Size - 1 - diag] == 'O')
				count_O++;
		}
		if (count_X == Size)
			ans = 'X';
		else if (count_O == Size)
			ans = 'O';
		if (ans != 'N')
			return ans;

		if (countSteps == Size * Size)
			ans = 'F';
		return ans;
	}
	void ResetTheGame()
	{
		countSteps = 0;
		currentPlayer = 'X';
		for (int i = 0; i < Size* Size; i++)
		{
			placeNumber[i] = i + 1;
		}
		for (int row = 0; row < Size; row++)
		{
			for (int col = 0; col < Size; col++)
				currentState[row][col] = 'N';
		}
		printCurrentState();
	}
	void printCurrentState()
	{
		system("cls");
		int index = 0;
		for (int row = 0; row < Size; row++)
		{
			for (int col = 0; col < Size; col++)
			{
				if (currentState[row][col] == 'X')
					cout << setw(14) << "\033[34m" << currentState[row][col] << "\033[0m" << "   ";
				else if (currentState[row][col] == 'O')
					cout << setw(14) << "\033[36m" << currentState[row][col] << "\033[0m" << "   ";
				else
					cout <<setw(10)<< placeNumber[index] << "   ";
				index++;
			}
			cout << endl << endl;
		}
		cout << "\033[34m" << "Score_X : " << x_Score << "\033[0m" << endl << endl;
		cout << "\033[36m" << "Score_O : " << y_Score << "\033[0m" << endl << endl << endl;
	}
	~XO_game()
	{
		delete[] placeNumber;
		for (int i = 0; i < Size; ++i)
			delete currentState[i];

		delete[] currentState;
	}
};
int main()
{
	int Size;
	do
	{
		cout << "Enter the game size you want : ";
		cin >> Size;
	} while (Size < 3);
	XO_game game1(Size);
	char keepPlaying;
	do
	{
		while (true)
		{
			game1.printCurrentState();
			game1.play();
			if (game1.isOver() == 'X')
			{
				cout << "\033[34m" << "Player X wins" << "\033[0m" << endl;
				Sleep(2000);
				game1.increaseX_Score();
				game1.printCurrentState();
				break;
			}
			else if (game1.isOver() == 'O')
			{
				cout << "\033[36m" << "Player O wins" << "\033[0m" << endl;
				Sleep(2000);
				game1.increaseY_Score();
				game1.printCurrentState();
				break;
			}
			else if (game1.isOver() == 'F')
			{
				cout << "\033[31m" << "The Game Is Over, No One Wins (*_*)." << "\033[0m" << endl;
				Sleep(2000);
				break;
			}
		}
		cout << "Do you want to play again ? : ";
		cin >> keepPlaying;
		game1.ResetTheGame();
	} while (toupper(keepPlaying) == 'Y');
	cout << "\033[32m" << "Thanks For Playing My Game (^_^)" << "\033[0m" << endl;
	return 0;
}