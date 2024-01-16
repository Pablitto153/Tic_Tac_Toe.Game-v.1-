
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Creating the global array and initialize it with numbers of grid
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

//Declare variables row and column for filling the game board
int row;
int column;

//
char mark = 'x';

bool tie = false;

//Declare 2 variables for player names
string plyr1 = "";
string plyr2 = "";

//Displaying the greet and rules of the game 
void greet()
{
	cout << endl;
	cout << "               Welocome      " << endl;
	cout << "                  to         " << endl;
	cout << "            Tic-Tac-Toe game " << endl;
	cout << "              in console     " << endl << endl;
	cout << "*************_(Game Rules)_*************" << endl;
	cout << "*                                      *" << endl;
	cout << "*       This game for 2 players        *" << endl;
	cout << "*            in a grid 3x3             *" << endl;
	cout << "*  The player who succeeds in placing  *" << endl;
	cout << "*  3 of their marks (x or 0) in a      *" << endl;
	cout << "*  horizontal, vertical or diagonal    *" << endl;
	cout << "*           row is winner              *" << endl;
	cout << "*                                      *" << endl;
	cout << "****************************************" << endl;
	cout << endl << endl;

	cout << "First player enter the name: ";
	getline(cin, plyr1);

	cout << "Second player enter the name: ";
	getline(cin, plyr2);

	cout << endl;
	cout << plyr1 << " will be X" << endl;
	cout << plyr2 << " will be 0" << endl << endl;

}

void game_board()
{
	// Creating game board, grid 3x3
	// Where we're adding the values of the variable board, which one we declared above it
	cout << "     |    |     " << endl;
	cout << "   " << board[0][0] << " | " << board[0][1] << "  | " << board[0][2] << endl;
	cout << " ____|____|____ " << endl;
	cout << "     |    |     " << endl;
	cout << "   " << board[1][0] << " | " << board[1][1] << "  | " << board[1][2] << endl;
	cout << " ____|____|____ " << endl;
	cout << "     |    |     " << endl;
	cout << "   " << board[2][0] << " | " << board[2][1] << "  | " << board[2][2] << endl;
	cout << "     |    |     " << endl << endl;
}


void plyr_turn()
{

	//Declare variable for inputing in game board
	int board_number = 0;

	//Player 1 turn
	if (mark == 'x')
	{
		cout << plyr1 << ", enter the number: ";
		cin >> board_number;
	}

	//Player 2 turn
	if (mark == '0')
	{
		cout << plyr2 << ", enter the number: ";
		cin >> board_number;
	}

	//Fill raw and columns
	if(board_number == 1) 
	{
		row = 0;
		column = 0;
	}
	if (board_number == 2)
	{
		row = 0;
		column = 1;
	}
	if (board_number == 3)
	{
		row = 0;
		column = 2;
	}
	if (board_number == 4)
	{
		row = 1;
		column = 0;
	}
	if (board_number == 5)
	{
		row = 1;
		column = 1;
	}
	if (board_number == 6)
	{
		row = 1;
		column = 2;
	}
	if (board_number == 7)
	{
		row = 2;
		column = 0;
	}
	if (board_number == 8)
	{
		row = 2;
		column = 1;
	}
	if (board_number == 9)
	{
		row = 2;
		column = 2;
	}
	else if (board_number < 1 || board_number > 9)
	{
		cout << "Invalid!" << endl;
	}

	// Check if it's X or 0
	if (mark == 'x' && board[row][column] != 'x' && board[row][column] != '0') 
	{
		board[row][column] = 'x';
		mark = '0';
	}
	else if (mark == '0' && board[row][column] != 'x' && board[row][column] != '0') 
	{
		board[row][column] = '0';
		mark = 'x';
	}
	else
	{
		cout << "There is no empty space!" << endl;
		plyr_turn();

	} 
	//Add game board to iterate in main function
	game_board();
}


bool check_win()
{
	for (int i = 0; i < 3; i++) {

		//Horizontal win and Vertical win
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]
			|| board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{

			return true;
		}
	}

	//Diagonal win
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		|| board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return true;
	}

	//Checking if the game is still going on 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'x' && board[i][j] != '0')
			{
				return false;
			}
		}
	}

	tie = true;
	return false;
}

void win()
{
	if (mark == 'x' && tie == false)
	{
		cout << plyr2 << ", Wins!" << endl;
	}
	else if (mark == '0' && tie == false) 
	{
		cout << plyr1 << ", Wins!" << endl;
	}
	else
	{
		cout << "Game draw!" << endl;
	}
}
