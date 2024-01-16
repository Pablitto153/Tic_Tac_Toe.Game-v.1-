

#include<iostream>
#include"ttt_functions.h"


int main()
{

	greet();
	game_board();

	while (!check_win())
	{
		
		plyr_turn();
		check_win();
	} 

	win();
	
}


