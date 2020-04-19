//			battle_ship.cpp

#include "battle_ship_function.h"


void startBoard( int board[][table], int shot[][table] )
{
	for( int i = 0; i < table; i++ )
	{
		for( int j = 0; j < table; j++ )
		{
			board[i][j] = -1;
			shot[i][j] = 0;
		}
	}
}

void initShip( int ships[][table] )
{
	for( int i = 0; i < table; i++ )
		for( int j = 0; j < table; j++ )
			ships[i][j] = 0;
}

void startShips( int ships[][table] )
{
	int r_row, r_col;
    initShip( ships );
    for( int r_ship = 1; r_ship <= 6; r_ship++ )
	{
        if( r_ship <= 3 )
		{
			do{
				r_row = rand( ) % table;
	            r_col = rand( ) % table;
		    }while( ships[r_row][r_col] == 1 );           
		    ships[r_row][r_col] = 1; 
		}
	    if( r_ship == 4 )
		{
	        while( ships[r_row][r_col] != 3 )
			{
	            r_row = ( rand( ) % 5 ) + 1;
		        r_col = ( rand( ) % 5 ) + 1;
		        if( ships[r_row - 1][r_col] == 1 || ships[r_row][r_col] == 1 || ships[r_row + 1][r_col] == 1 )
				{
					continue;
				}else
				{
		            ships[r_row - 1][r_col] = 3;
		            ships[r_row][r_col] = 3;
					ships[r_row + 1][r_col] = 3;
					break;
		        }
	        }
		}
	    if( r_ship == 5 )
		{
	        while( 1 )
			{
	            r_row = ( rand( ) % 5 ) + 1;
		        r_col = ( rand( ) % 5 ) + 1;
		        if( ships[r_row][r_col] == 3 || ships[r_row][r_col - 1] == 3 || ships[r_row][r_col + 1] == 3 )
				{
					continue;
				}else if( ships[r_row][r_col] == 1 || ships[r_row][r_col - 1] == 1 || ships[r_row][r_col + 1] == 1 )
				{
					continue;
				}else
				{
		            ships[r_row][r_col - 1] = 3;
		            ships[r_row][r_col] = 3;
					ships[r_row][r_col + 1] = 3;
					break;
		        }
	        }          	   
		}
		if( r_ship == 6 )
		{
		    if( rand( ) % 2 == 0 )
			{
		    	while( ships[r_row][r_col] != 5 )
				{
	            	r_row = ( rand( ) % 4 ) + 2;
		            r_col = ( rand( ) % 4 ) + 2;
		            if( ships[r_row][r_col - 2] == 3 || ships[r_row][r_col - 1] == 3 || ships[r_row][r_col] == 3 ||
						ships[r_row][r_col + 1] == 3 || ships[r_row][r_col + 2] == 3)
					{
						continue;
					}else if( ships[r_row][r_col - 2] == 1 || ships[r_row][r_col - 1] == 1 || ships[r_row][r_col] == 1 ||
							  ships[r_row][r_col + 1] == 1 || ships[r_row][r_col + 2] == 1 )
					{
						continue;
					}else
					{
		            	ships[r_row][r_col - 2] = 5;
	            		ships[r_row][r_col - 1] = 5;
						ships[r_row][r_col] = 5;
						ships[r_row][r_col + 1] = 5;
	            		ships[r_row][r_col + 2] = 5;
						break;
		            }
	        	}
		    }else
			{
				while( ships[r_row][r_col] != 5 )
				{
	            	r_row = ( rand( ) % 4 ) + 2;
		            r_col = ( rand( ) % 4 ) + 2;
		            if( ships[r_row - 2][r_col] == 3 || ships[r_row - 1][r_col] == 3|| ships[r_row][r_col] == 3 ||
						ships[r_row + 1][r_col] == 3 || ships[r_row + 2][r_col] == 3 )
					{
						continue;
					}else if( ships[r_row - 2][r_col] == 1 || ships[r_row - 1][r_col] == 1 || ships[r_row][r_col] == 1 ||
							  ships[r_row + 1][r_col] == 1 || ships[r_row + 2][r_col] == 1 )
					{
						continue;
					}else
					{
		            	ships[r_row - 2][r_col] = 5;
	            		ships[r_row - 1][r_col] = 5;
						ships[r_row][r_col] = 5;
						ships[r_row + 1][r_col] = 5;
	            		ships[r_row + 2][r_col] = 5;
						break;
		            }
	        	}
		    }
		}
	}					
}
	
void showBoard( int board[][table], int x, int y, IplImage *hit, IplImage *nohit )
{
	for( int i = 0; i < table; i++ )
	{
	 	for( int j = 0; j < table; j++ )
		{
			if( board[i][j] == 0 )
			{
				Image( nohit );
				Image_Size( x + 1.5 + j * 67.5, y + 1.5 + i * 67.5, 64.5, 64.5 );
			}
			else if( board[i][j] == 1 )
			{
				Image_Transparent( hit );
				Image_Size( x + 1.5 + j * 67.5, y + 1.5 + i * 67.5, 64.5, 64.5 );
			}
		}
	}
}

bool giveShot( int row, int column, int shot[][table], int board[][table] )
{
	if(board[row][column] == 0 || board[row][column] == 1 )
	{
		return false;
	}else
	{
		shot[row][column] = 1;
		return true;
	}
}

int hitShip( int row, int column, int shot[][table], int ships[][table] )
{
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	glColor3f( 0, 0, 0 );
	setFontHeight( 65 );
	setFontXY( 270, 100 );
    if( shot[row][column] == ships[row][column] )
	{
		if( row >= 800 )
        	Print_Font( "You hit a small ship with the shot ( %d , %d )", row + 1, column + 1 );
        else
        	Print_Font( "Hit a small ship with the shot ( %d , %d )", row + 1, column + 1 );
    }else if( shot[row][column] + 2 == ships[row][column] )
	{
		if( row >= 800 )
        	Print_Font( "You hit a medium ship with the shot (%d , %d )", row + 1, column + 1 );
        else
        	Print_Font( "Hit a medium ship with the shot (%d , %d )", row + 1, column + 1 );
    }else if( shot[row][column] + 4 == ships[row][column] )
	{
		if( row >= 800 )
        	Print_Font( "You hit a large ship with the shot ( %d , %d )", row + 1, column + 1 );
        else
        	Print_Font( "Hit a large ship with the shot ( %d , %d )", row + 1, column + 1 );
    }else
	{
		if( row >= 800 )
		{
			setFontXY( 600, 100 );
        	Print_Font("Oops !");
		}
        else
        {
        	setFontXY( 350, 100 );
        	Print_Font("Where did you shoot ? Noob !");
		}
        return 0;
	}
	return 1;
}

void changeBoard( int row, int column, int shot[][table], int ships[][table], int board[][table] )
{
	if( hitShip( row, column, shot, ships ) == 1 )
        board[row][column] = 1;
    else 
		board[row][column] = 0;
}
