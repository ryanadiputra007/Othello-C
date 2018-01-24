#include <stdio.h>
#include <stdlib.h>

////////////////// function:           print_board //////////////////

void print_board(int array[8][8]) {
	
	int i, j;
	

	printf("    0   1   2   3   4   5   6   7\n");
	printf("  +---+---+---+---+---+---+---+---+\n");

	for (i = 0; i <= 7; i++)
	{
		printf("%d ",i);
		for (j = 0; j <= 7; j++)
		{
			printf("|");
			if (array[i][j] == 0)
				printf("   ");

			else if (array[i][j] == 1)
				printf(" O ");

			else
				printf(" # ");
		}printf("|\n");
		printf("  +---+---+---+---+---+---+---+---+\n");
	}printf("\n");
}

////////////////// function:    print_game_details //////////////////

void print_game_details(int board[8][8], int current_player) {
	int x, y, count[3] = { 0 };
	for (x = 0; x <= 7; x++)
		for (y = 0; y <= 7; y++)
		{
		count[board[x][y]] += 1;
		}
	printf("Player O: %d            Player #: %d\n", count[1], count[2]);
}

////////////////// function:    Counting //////////////////
int count(int board[8][8], int player)
{
	int x, y, count[3] = { 0 };
	for (x = 0; x <= 7; x++)
		for (y = 0; y <= 7; y++)
		{
		count[board[x][y]] += 1;
		}
	return count[player];
}
////////////////// function:             need_pass //////////////////
/*
123
4 5
678
*/
// 0:  current player fill
// 1: empty space
// 2: opp's piece
// opponent's piece: skip
int horrg(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (j + x > 7)
		{
			code = 2;
			break;
			continue;
		}
		if (board[i][j+x] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i][j+x] == 0)
		{
			code = 1;
			break;
		}
		
	}
	return code;
}

int horlf(int board[8][8], int current_player, int i, int j)
{
	int x, code=2;
	for (x = 2; x <= 7; x++)
	{
		if (j - x < 0){
			code = 2;
			break; continue;
		}
		if (board[i][j-x] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i][j-x] == 0)
		{
			code = 1;
			break;
		}
	}
	return code;
}

int vertup(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i - x < 0)
		{
			code = 2; break; continue;
		}
		if (board[i-x][j] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i-x][j] == 0)
		{
			code = 1;
			break;
		}
	}
	return code;
}

int vertdw(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i + x > 7)
		{
			code = 2; break; continue;
		}
		if (board[i+x][j] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i+x][j] == 0)
		{
			code = 1;
			break;
		}
		
	}
	return code;
}

int upright(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i - x < 0 || j + x > 7)
		{
			code = 2; break; continue;
		}
		if (board[i - x][j + x] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i - x][j + x] == 0)
		{
			code = 1;
			break;
		}
		
	}
	return code;
}

int upleft(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i - x < 0 || j - x < 0)
		{
			code = 2; break; continue;
		}
		if (board[i - x][j - x] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i - x][j - x] == 0)
		{
			code = 1;
			break;
		}
		
	}
	return code;
}

int dwright(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i + x > 7 || j + x > 7)
		{
			code = 2; break; continue;
		}
		if (board[i + x][j + x] == current_player)
		{
			code = 0;
			break;
		}
		else if (board[i + x][j + x] == 0)
		{
			code = 1;
			break;
		}
		
	}
	return code;
}

int dwleft(int board[8][8], int current_player, int i, int j)
{
	int x, code = 2;
	for (x = 2; x <= 7; x++)
	{
		if (i + x > 7 || j - x < 0)
		{
			code = 2; break; continue;
		}
		if (board[i + x][j - x] == current_player)
		{
			code= 0;
			break;
		}
		else if (board[i + x][j - x] == 0)
		{
			code= 1;
			break;
		}
		
	}
	return code;
}
int need_pass(int board[8][8], int current_player) {
	int i, j, opp, stat = 2, code = 0;

	if (current_player == 1)
		opp = 2;
	else
		opp = 1;

	for (i = 0; i<8; i++)
		for (j = 0; j<8; j++)
		{
		if (board[i][j] == current_player)
		{
			if (board[i][j + 1] == opp)
			{
				stat = horrg(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			if (board[i][j - 1] == opp)
			{
				stat = horlf(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			if (board[i - 1][j] == opp)
			{
				stat = vertup(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			 if (board[i + 1][j] == opp)
			{
				stat = vertdw(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			 if (board[i - 1][j + 1] == opp)
			{
				stat = upright(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			 if (board[i - 1][j - 1] == opp)
			{
				stat = upleft(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			 if (board[i + 1][j + 1] == opp)
			{
				stat = dwright(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

			 if (board[i + 1][j - 1] == opp)
			{
				stat = dwleft(board, current_player, i, j);
				if (stat == 1)
				{
					code = 1;
					break; break; continue;
				}
			}

		}
		}

		return code;//possible to continue
}


////////////////// function:          is_end_game //////////////////

int is_end_game(int board[8][8]) {
	/*
	Purpose: to determine if the game has been ended or not

	Return value:
	0: false, i.e., the game is not ended.
	1: true,  i.e., the game is ended.
	*/
	if (need_pass(board, 1) == 0 && need_pass(board, 2) == 0)
		return 1;
	else
		return 0;
}

////////////////// function: is_wrong_input_range //////////////////

int is_wrong_input_range(int row, int column) {

	if (row>=0 && column>=0 && row<=7 && column<=7)
		return 0;

	else
		return 1;
}

////////////////// function:        is_empty_cell //////////////////

int is_empty_cell(int board[8][8], int row, int column) {
	/*
	Purpose: to determine if (row, column) refers to an empty cell

	Return value:
	0: no,  i.e., not empty.
	1: yes, i.e., empty.
	*/
	if (board[row][column] == 0)
		return 1;
	else
		return 0;
}

////////////////// function:    can_flip_opponent //////////////////

int can_flip_opponent(int board[8][8], int row, int column, int current_player) {
	/*
	Purpose: to determine the new disc in (row, column)
	can flip any opponent's discs

	Return value:
	0: no,  i.e., cannot flip.
	1: yes, i.e., can flip.
	*/
	int opp, stat, code = 2;

	if (current_player == 1)
		opp = 2;
	else
		opp = 1;

	
	if (board[row][column] == 0)
	{
		if (board[row][column + 1] == opp)
		{
			stat = horrg(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row][column - 1] == opp)
		{
			stat = horlf(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row - 1][column] == opp)
		{
			stat = vertup(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row + 1][column] == opp)
		{
			stat = vertdw(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row - 1][column + 1] == opp)
		{
			stat = upright(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row - 1][column - 1] == opp)
		{
			stat = upleft(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row + 1][column + 1] == opp)
		{
			stat = dwright(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}

		if (board[row + 1][column - 1] == opp)
		{
			stat = dwleft(board, current_player, row, column);
			if (stat == 0)
				code = 1;
		}
	}

	if (code == 0)
		return 0;//no more space to move
	else if (code == 1)
		return 1;//possible to continue
	else
		return 2;//hit the edge
}

////////////////// function:        flip_opponent //////////////////


void flip_opponent(int board[8][8], int row, int column, int current_player) {
	/*
	Purpose: using a new disc in (row, column) to flip opponent's disc

	Because "board" is an array, update it in this function
	will also change the variable in the main function.

	No return value.
	*/
	int opp, stat = 0, x;
	board[row][column] = current_player;
	if (current_player == 1)
		opp = 2;
	else
		opp = 1;

		if (board[row][column + 1] == opp)
		{
			stat = horrg(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = column + 1; x <= 7; x++)
				{
					if (board[row][x] == current_player)
						break;
					board[row][x] = current_player;
				}
			}
		}

		if (board[row][column - 1] == opp)
		{
			stat = horlf(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = column - 1; x >= 0; x--)
				{
					if (board[row][x] == current_player)
						break;
					board[row][x] = current_player;
				}
			}
		}

		if (board[row - 1][column] == opp)
		{
			stat = vertup(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = row - 1; x >= 0; x--)
				{
					if (board[x][column] == current_player)
						break;
					board[x][column] = current_player;
				}
			}
		}

		if (board[row + 1][column] == opp)
		{
			stat = vertdw(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = row + 1; x <= 7; x++)
				{
					if (board[x][column] == current_player)
						break;
					board[x][column] = current_player;
				}
			}
		}

		 if (board[row - 1][column + 1] == opp)
		{
			stat = upright(board, current_player, row, column);
			if (stat == 0)
			{
				for (x =1; x <= 7; x++)
					{
					if (board[row - x][column + x] == current_player)
						break;
					board[row - x][column + x] = current_player;
					}
			}
		}

		 if (board[row - 1][column - 1] == opp)
		{
			stat = upleft(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row - x][column - x] == current_player)
						break;
					board[row - x][column - x] = current_player;
				}
			}
		}

		 if (board[row + 1][column + 1] == opp)
		{
			stat = dwright(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row + x][column + x] == current_player)
						break;
					board[row + x][column + x] = current_player;
				}
			}
		}

		 if (board[row + 1][column - 1] == opp)
		{
			stat = dwleft(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row + x][column - x] == current_player)
						break;
					board[row + x][column - x] = current_player;
				}
			}
		}
	}

////////////////// function:        AI logic /////////////////
	int corner_move(int board[8][8])
	{
		int x,stat=0;
		if (board[0][0] == 2)
		{
			for (x = 1; x <= 7; x++)
			{
				if (can_flip_opponent(board, 0, x, 2) == 1 && is_empty_cell(board,0,x)==1)
				{
					flip_opponent(board, 0, x, 2);
					stat = 1;
					break;
				}
				else if (can_flip_opponent(board, x, 0, 2) == 1 && is_empty_cell(board, x, 0) == 1)
				{
					flip_opponent(board, x, 0, 2);
					stat = 1;
					break;
				}
			}
		}
		if (board[0][7] == 2 && stat==0)
		{
			for (x = 1; x <= 7; x++)
			{
				if (can_flip_opponent(board, 0, (7 - x), 2) == 1 && is_empty_cell(board, 0, (7-x)) == 1)
				{
					flip_opponent(board, 0, (7 - x), 2);
					stat = 1;
					break;
				}
				else if (can_flip_opponent(board, x, 7, 2) == 1 && is_empty_cell(board, x, 7) == 1)
				{
					flip_opponent(board, x, 7, 2);
					stat = 1;
					break;
				}
			}
		}
		if (board[7][0] == 2 && stat == 0)
		{
			for (x = 1; x <= 7; x++)
			{
				if (can_flip_opponent(board, 7, x, 2) == 1 && is_empty_cell(board, 7, x) == 1)
				{
					flip_opponent(board, 7, x, 2);
					stat = 1;
					break;
				}
				else if (can_flip_opponent(board, (7 - x), 0, 2) == 1 && is_empty_cell(board, (7 - x), 0) == 1)
				{
					flip_opponent(board, (7 - x), 0, 2);
					stat = 1;
					break;
				}
			}
		}
		if (board[7][7] == 2 && stat == 0)
		{
			for (x = 6; x >=0; x--)
			{
				if (can_flip_opponent(board, 7, x, 2) == 1 && is_empty_cell(board, 7, x) == 1)
				{
					flip_opponent(board, 7, x, 2);
					stat = 1;
					break;
				}
				else if (can_flip_opponent(board, x, 7, 2) == 1 && is_empty_cell(board, x, 7) == 1)
				{
					flip_opponent(board, x, 7, 2);
					stat = 1;
					break;
				}
			}
		}
		return stat;
	}

void cpu_move(int board[8][8])
{
	int x, y, comp =  0 , temp =  0 , row, col, get =  0 ;

	if (is_end_game(board) == 1) {
		printf("Game Over\n\n");
	}
	else if (need_pass(board, 2) == 0) {
		printf("CPU have to pass this turn\n\n");
	}
	else
	{
		if (board[0][0] == 2 || board[0][7] == 2 || board[7][0] == 2 || board[7][7] == 2)
		{
			for (x = 0; x <= 7; x++)
				for (y = 0; y <= 7; y++)
				{
				if (is_empty_cell(board, x, y) == 1)
				{
					if (can_flip_opponent(board, x, y, 2) == 1)
					{
						if (x == 0 && y == 0)
						{
							flip_opponent(board, x, y, 2);
							break; break; get = 1;
						}
						else if (x == 0 && y == 7)
						{
							flip_opponent(board, x, y, 2);
							break; break; get = 1;
						}
						else if (x == 7 && y == 0)
						{
							flip_opponent(board, x, y, 2);
							break; break; get = 1;
						}
						else if (x == 7 && y == 7)
						{
							flip_opponent(board, x, y, 2);
							break; break; get = 1;
						}
					}
				}
				}
			if (get == 0)
			{
				if (board[0][0] == 2)
				{
					for (x = 1; x <= 7; x++)
					{
						if (can_flip_opponent(board, 0, x, 2) == 1 && is_empty_cell(board, 0, x) == 1)
						{
							flip_opponent(board, 0, x, 2);
							get = 1;
							break;
						}
						else if (can_flip_opponent(board, x, 0, 2) == 1 && is_empty_cell(board, x, 0) == 1)
						{
							flip_opponent(board, x, 0, 2);
							get = 1;
							break;
						}
					}
				}
				if (board[0][7] == 2 && get == 0)
				{
					for (x = 1; x <= 7; x++)
					{
						if (can_flip_opponent(board, 0, (7 - x), 2) == 1 && is_empty_cell(board, 0, (7 - x)) == 1)
						{
							flip_opponent(board, 0, (7 - x), 2);
							get = 1;
							break;
						}
						else if (can_flip_opponent(board, x, 7, 2) == 1 && is_empty_cell(board, x, 7) == 1)
						{
							flip_opponent(board, x, 7, 2);
							get = 1;
							break;
						}
					}
				}
				if (board[7][0] == 2 && get == 0)
				{
					for (x = 1; x <= 7; x++)
					{
						if (can_flip_opponent(board, 7, x, 2) == 1 && is_empty_cell(board, 7, x) == 1)
						{
							flip_opponent(board, 7, x, 2);
							get = 1;
							break;
						}
						else if (can_flip_opponent(board, (7 - x), 0, 2) == 1 && is_empty_cell(board, (7 - x), 0) == 1)
						{
							flip_opponent(board, (7 - x), 0, 2);
							get = 1;
							break;
						}
					}
				}
				if (board[7][7] == 2 && get == 0)
				{
					for (x = 6; x >= 0; x--)
					{
						if (can_flip_opponent(board, 7, x, 2) == 1 && is_empty_cell(board, 7, x) == 1)
						{
							flip_opponent(board, 7, x, 2);
							get = 1;
							break;
						}
						else if (can_flip_opponent(board, x, 7, 2) == 1 && is_empty_cell(board, x, 7) == 1)
						{
							flip_opponent(board, x, 7, 2);
							get = 1;
							break;
						}
					}
				}
			}
		
		}
		

		 if(get==0){
			 for (x = 0; x <= 7; x++)
				 for (y = 0; y <= 7; y++)
				 {
				 if (is_empty_cell(board, x, y) == 1)
				 {
					 if (can_flip_opponent(board, x, y, 2) == 1)
					 {
						 if (x == 0 && y == 0)
						 {
							 flip_opponent(board, x, y, 2);
							 break; break;
						 }
						 else if (x == 0 && y == 7)
						 {
							 flip_opponent(board, x, y, 2);
							 break; break;
						 }
						 else if (x == 7 && y == 0)
						 {
							 flip_opponent(board, x, y, 2);
							 break; break;
						 }
						 else if (x == 7 && y == 7)
						 {
							 flip_opponent(board, x, y, 2);
							 break; break;
						 }



						 else
						 {
							 /*if (!= 0 && y != 1) && (x != 0 && y != 6) && (x != 1 && y != 7) && (x != 1 && y != 6) &&
								 (x != 7 && y != 6) && (x != 6 && y != 7) && (x != 6 && y != 6) && (x != 1 && y != 0) &&
								 (x != 1 && y != 1) && (x != 7 && y != 1) && (x != 6 && y != 0) && (x != 6 && y != 1))
								 {*/
							 temp = count(board, 2);
							 if (temp > comp)
							 {
								 row = x; col = y;
								 get = 2;
								 comp = temp;
							 }
							 else if (temp == comp)
							 {
								 if (x < 4)
								 {
									 if (y < 4)
									 {
										 if (x + y < col + row)
										 {
											
											 row = x; col = y;
											 get = 2;
											 comp = temp;
										 }
									 }
									 else
									 {
										 if (horlf(board, 1, x, y) == 2 || horrg(board, 1, x, y) == 2 || vertdw(board, 1, x, y) == 2 || vertup(board, 1, x, y) == 2
											 || upleft(board, 1, x, y) == 2 || upright(board, 1, x, y) == 2 || dwleft(board, 1, x, y) == 2 || dwright(board, 1, x, y) == 2)
										 {
											 row = x; col = y;
											 get = 2;
											 comp = temp;
										 }
									 }
								 }
								 else
								 {
									 if (y < 4)
									 {
										 if (horlf(board, 1, x, y) == 2 || horrg(board, 1, x, y) == 2 || vertdw(board, 1, x, y) == 2 || vertup(board, 1, x, y) == 2
											 || upleft(board, 1, x, y) == 2 || upright(board, 1, x, y) == 2 || dwleft(board, 1, x, y) == 2 || dwright(board, 1, x, y) == 2)
										 {

											 row = x; col = y;
											 get = 2;
											 comp = temp;
										 }
									 }
									 else
									 {
										 
										 row = x; col = y;
										 get = 2;
										 comp = temp;
									 }} }}
					 } }
				 }
		 }
			if (get == 2)
				flip_opponent(board, row, col, 2);
	}
}

	////////////////// function:    extreme_flip //////////////////
	/*
	Extreme Rules: if a player owned two or more pieces in the corner, the spaces between (either empty or filled) turned into his pieces
	A.k.a: Battle of the Corners
	*/

void extreme_flip(int board[8][8], int row, int column, int current_player) {
		/*
		Purpose: using a new disc in (row, column) to flip opponent's disc

		Because "board" is an array, update it in this function
		will also change the variable in the main function.

		No return value.
		*/
		int opp, stat = 0, x;
		board[row][column] = current_player;
		if (current_player == 1)
			opp = 2;
		else
			opp = 1;
		if (board[0][0] == current_player && board[0][7] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[0][x] = current_player;
			}
		}

		if (board[0][0] == current_player && board[7][0] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[x][0] = current_player;
			}
		}

		if (board[7][0] == current_player && board[7][7] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[7][x] = current_player;

			}
		}
		if (board[0][7] == current_player && board[7][7] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[x][7] = current_player;
			}
		}

		if (board[0][0] == current_player && board[7][7] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[x][x] = current_player;
			}
		}

		if (board[0][7] == current_player && board[7][0] == current_player)
		{
			for (x = 0; x <= 7; x++)
			{
				board[x][7 - x] = current_player;
			}
		}
		if (board[row][column + 1] == opp)
		{
			stat = horrg(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = column + 1; x <= 7; x++)
				{
					if (board[row][x] == current_player)
						break;
					board[row][x] = current_player;
				}
			}
		}

		if (board[row][column - 1] == opp)
		{
			stat = horlf(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = column - 1; x >= 0; x--)
				{
					if (board[row][x] == current_player)
						break;
					board[row][x] = current_player;
				}
			}
		}

		if (board[row - 1][column] == opp)
		{
			stat = vertup(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = row - 1; x >= 0; x--)
				{
					if (board[x][column] == current_player)
						break;
					board[x][column] = current_player;
				}
			}
		}

		if (board[row + 1][column] == opp)
		{
			stat = vertdw(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = row + 1; x <= 7; x++)
				{
					if (board[x][column] == current_player)
						break;
					board[x][column] = current_player;
				}
			}
		}

		if (board[row - 1][column + 1] == opp)
		{
			stat = upright(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row - x][column + x] == current_player)
						break;
					board[row - x][column + x] = current_player;
				}
			}
		}

		if (board[row - 1][column - 1] == opp)
		{
			stat = upleft(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row - x][column - x] == current_player)
						break;
					board[row - x][column - x] = current_player;
				}
			}
		}

		if (board[row + 1][column + 1] == opp)
		{
			stat = dwright(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row + x][column + x] == current_player)
						break;
					board[row + x][column + x] = current_player;
				}
			}
		}

		if (board[row + 1][column - 1] == opp)
		{
			stat = dwleft(board, current_player, row, column);
			if (stat == 0)
			{
				for (x = 1; x <= 7; x++)
				{
					if (board[row + x][column - x] == current_player)
						break;
					board[row + x][column - x] = current_player;
				}
			}
		}
		
	}

////////////////// function:         print_winner //////////////////

void print_winner(int board[8][8]) 
{
	/*
	Purpose:
	- print number of 'O' in the board;
	- print number of '#' in the board;
	- print who the winner is / draw grame
	*/
	int x, y, count[3] = { 0 };
	for (x = 0; x <= 7; x++)
		for (y = 0; y <= 7; y++)
		{
		count[board[x][y]] += 1;
		}
	printf("Player O: %d            Player #: %d\n", count[1], count[2]);
	if (count[1] > count[2])
		printf("The Winner is: Player O \n");
	else if (count[1] < count[2])
		printf("The Winner is: Player # \n");
	else
		printf("The Game is Tie\n");
}

///////////////// Main /////////////////

int main(int argc, char **argv) {
	int current_player = 1;  // current_player can be 1 or 2;
	int board[8][8] = { 0 };
	char player[4];
	int turn = 0, row, column, rules,mode, stop, all_test_pass;

	player[1]= 'O';
	player[2]= '#';
	printf("Game Select: [1. Normal Rules | 2. Extreme Rules | 3. Versus CPU ] ?\n");
	scanf("%d", &rules);
	printf("Select Mode: [1. Normal Mode | 2. Debug Mode ] ?\n");
	scanf("%d", &mode);
	
	


	stop = 0;

	if (rules ==1 )
	{
		if (mode == 1) {
			board[3][3] = board[4][4] = 2;
			board[3][4] = board[4][3] = 1; // store the current game board

		}
		else if (mode == 2) {
			/*
			Initialize the board based on the
			input file format as described in
			P.7 of the specification.
			*/
			FILE *fptr;
			int a, b;

			fptr = fopen("board.txt", "r");  // open file

			// Read two integers from the file
			for (a = 0; a <= 7; a++)
				for (b = 0; b <= 7; b++)
					fscanf(fptr, "%d", &board[a][b]);

			fclose(fptr);  // close file

		}

		while (stop == 0) { // the big game loop begins

			print_board(board);
			print_game_details(board, current_player);


			printf("Current Turn: %c	       Turns: %d\n\n", player[current_player], turn);
			turn++;

			if (is_end_game(board, current_player) == 1) {
				stop = 1;

				print_board(board);
				print_winner(board);
				break; continue;
			}

			else if (need_pass(board, current_player) == 0) {
				printf("you have to pass this turn\n\n");
				if (current_player == 1)
					current_player = 2;
				else
					current_player = 1;
			}
			else {
				do {
					all_test_pass = 1;
					printf("Row: [0-7]:\n");
					scanf("%d", &row);
					printf("Column: [0-7]:\n");
					scanf("%d", &column);
					if (is_wrong_input_range(row, column) == 1) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Wrong input range\n\n");
						all_test_pass = 0;
					}
					else if (is_empty_cell(board, row, column) == 0) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}
					else if (can_flip_opponent(board, row, column, current_player) == 0 || can_flip_opponent(board, row, column, current_player) == 2) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}

					if (all_test_pass == 1) {
						flip_opponent(board, row, column, current_player);
					}

				} while (all_test_pass == 0);

				if (current_player == 1)
					current_player = 2;
				else
					current_player = 1;			}
		}  // the big game loop ends
	}

	else if (rules == 2)
	{

		if (mode == 1) {
			board[3][3] = board[4][4] = 2;
			board[3][4] = board[4][3] = 1; // store the current game board

		}
		else if (mode == 2) {
			/*
			Initialize the board based on the
			input file format as described in
			P.7 of the specification.
			*/
			FILE *fptr;
			int a, b;

			fptr = fopen("board.txt", "r");  // open file

			// Read two integers from the file
			for (a = 0; a <= 7; a++)
				for (b = 0; b <= 7; b++)
					fscanf(fptr, "%d", &board[a][b]);

			fclose(fptr);  // close file
		}

		while (stop == 0) { // the big game loop begins

			print_board(board);
			print_game_details(board, current_player);


			printf("Current Turn: %c\t\tTurns: %d\n\n", player[current_player], turn);
			turn++;

			if (is_end_game(board, current_player) == 1) {
				stop = 1;

				print_board(board);
				print_winner(board);
				break; continue;
			}

			else if (need_pass(board, current_player) == 0) {
				printf("you have to pass this turn\n\n");
				if (current_player == 1)
					current_player = 2;
				else
					current_player = 1;
			}
			else {
				do {
					all_test_pass = 1;
					printf("Row: [0-7]:\n");
					scanf("%d", &row);
					printf("Column: [0-7]:\n");
					scanf("%d", &column);
					if (is_wrong_input_range(row, column) == 1) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Wrong input range\n\n");
						all_test_pass = 0;
					}
					else if (is_empty_cell(board, row, column) == 0) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}
					else if (can_flip_opponent(board, row, column, current_player) == 0 || can_flip_opponent(board, row, column, current_player) == 2) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}

					if (all_test_pass == 1) {
						extreme_flip(board, row, column, current_player);
					}

				} while (all_test_pass == 0);

				if (current_player == 1)
					current_player = 2;
				else
					current_player = 1;

			}
		}
	}

	else if (rules == 3)
	{
		if (mode == 1) {
			board[3][3] = board[4][4] = 2;
			board[3][4] = board[4][3] = 1; // store the current game board

		}
		else if (mode == 2) {
			/*
			Initialize the board based on the
			input file format as described in
			P.7 of the specification.
			*/
			FILE *fptr;
			int a, b;

			fptr = fopen("board.txt", "r");  // open file

			// Read two integers from the file
			for (a = 0; a <= 7; a++)
				for (b = 0; b <= 7; b++)
					fscanf(fptr, "%d", &board[a][b]);

			fclose(fptr);  // close file
		}

		while (stop == 0) { // the big game loop begins

			print_board(board);
			print_game_details(board, current_player);


			printf("Current Turn: %c	       Turns: %d\n\n", player[current_player], turn);
			turn++;

			if (is_end_game(board, current_player) == 1) {
				stop = 1;

				print_board(board);
				print_winner(board);
				break; continue;
			}

			else if (need_pass(board, current_player) == 0) {
				printf("you have to pass this turn\n\n");
					cpu_move(board);
			}
			else {
				do {
					all_test_pass = 1;
					printf("Row: [0-7]:\n");
					scanf("%d", &row);
					printf("Column: [0-7]:\n");
					scanf("%d", &column);
					if (is_wrong_input_range(row, column) == 1) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Wrong input range\n\n");
						all_test_pass = 0;
					}
					else if (is_empty_cell(board, row, column) == 0) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}
					else if (can_flip_opponent(board, row, column, current_player) == 0 || can_flip_opponent(board, row, column, current_player) == 2) {
						print_board(board);
						print_game_details(board, current_player);
						printf("Invalid location: (%d, %d)\n\n", row, column);
						all_test_pass = 0;
					}

					if (all_test_pass == 1) {
						flip_opponent(board, row, column, current_player);
					}

				} while (all_test_pass == 0);
			}
			cpu_move(board);
		}
	}
	return 0;

}
