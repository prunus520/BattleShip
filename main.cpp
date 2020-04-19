//			main.cpp


#include "battle_ship_function.h"

void shipInit( );
void WindowSize( int w, int h );
void Keyboard( unsigned char key, int x, int y );
void KeyboardSpecial( int key, int x, int y );
void MouseButton(int button, int state, int x, int y );
void MouseMove( int x, int y );
void MousePassiveMotion( int x, int y );
void Display( );
void Init_one( );
void Init_two( );
void Init_three( );
void glint_START_Timer( int id );
void check_shot( int row, int column, int shot[][table], int ships[][table], int board[][table], int hits[] );
void transWidthHeight( );
void shipXY( GLfloat x, GLfloat y, GLfloat width, GLfloat height );
void initShipXY( );
void player_computer_sleep_Timer( int id );
void player_computer_flag_Timer( int id );


float windowX = 1196 * 1.2, windowY = 720 * 1.2;
float sizeMagn = 1;
bool glint_START = true;
int frame = 1;
int mouseX, mouseY;
int button_mouseX, button_mouseY;
int move_mouseX, move_mouseY;
int pointX = windowX, pointY = 0;
IplImage *battle_ship = cvLoadImage( "img//battle_ship.jpg" );
IplImage *battleship = cvLoadImage( "img//battleship.png" );
IplImage *reel = cvLoadImage( "img//reel.png" );
IplImage *sea = cvLoadImage( "img//sea.jpg" );
IplImage *radar_board = cvLoadImage( "img//radar_board.jpg" );
IplImage *ship0 = cvLoadImage( "img//ship0.png" );
IplImage *ship1 = cvLoadImage( "img//ship1.png" );
IplImage *ship2 = cvLoadImage( "img//ship2.png" );
IplImage *ship3 = cvLoadImage( "img//ship3.png" );
IplImage *ship4 = cvLoadImage( "img//ship4.png" );
IplImage *ship5 = cvLoadImage( "img//ship5.png" );
IplImage *back = cvLoadImage( "img//back.png" );
IplImage *wave = cvLoadImage( "img//wave.jpg" );
IplImage *fire = cvLoadImage( "img//fire.png" );
int mouse_down;
Ship ship[6];
int shipMOVE = -1;
bool player_computer_flag = true;
bool player_computer_sleep = false;
bool palyer_init = false;
bool palyer_down = true;
uchar alpha = 0;


//		computer
int computer_row, computer_column;
int computer_board[table][table] = {0};
int computer_ships[table][table] = {0};
int computer_shot[table][table] = {0};
int computer_hits[2] = {0};

//		player
int player_row, player_column;
int player_board[table][table] = {0};
int player_ships[table][table] = {0};
int player_shot[table][table] = {0};
int player_hits[2] = {0};


FILE *pFile;
char buffer[1024];


void testtable( )
{
	glColor3f( 1, 1, 0 );
	setFontHeight( 20 );
	setFontXY( 0, 200 );
	for( int i = 0; i < table; i++ )
	{
    	for( int j = 0; j < table; j++ )
		{
    		Print_Font( "%d ", player_ships[i][j] );
		}
		Print_Font( "\n" );
	}
}

int main( )
{
	srand( time( NULL ) );
	//		battle_ship_main.h
		//	computer
    startBoard( computer_board, computer_shot );
    startShips( computer_ships );
    	//	player
    startBoard( player_board, player_shot );
	
	//		battle_ship_function.h
	shipInit( );

	
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
	glutInitWindowSize( windowX, windowY );
	glutInitWindowPosition( 100, 100 );
	glutCreateWindow( "Battle Ship" );
	
	cvCvtColor( battle_ship, battle_ship, CV_BGR2RGB );
	cvCvtColor( battleship, battleship, CV_BGR2RGB );
	cvCvtColor( reel, reel, CV_BGR2RGB );
	cvCvtColor( sea, sea, CV_BGR2RGB );
	cvCvtColor( ship0, ship0, CV_BGR2RGB );
	cvCvtColor( ship1, ship1, CV_BGR2RGB );
	cvCvtColor( ship2, ship2, CV_BGR2RGB );
	cvCvtColor( ship3, ship3, CV_BGR2RGB );
	cvCvtColor( ship4, ship4, CV_BGR2RGB );
	cvCvtColor( ship5, ship5, CV_BGR2RGB );
	cvCvtColor( wave, wave, CV_BGR2RGB );
	cvCvtColor( fire, fire, CV_BGR2RGB );
//	cvCvtColor( back, back, CV_BGR2RGB );
	
	glutReshapeFunc( WindowSize );
	glutKeyboardFunc( Keyboard );
	glutSpecialFunc( KeyboardSpecial );
	glutDisplayFunc( Display );
	glutMouseFunc( MouseButton );
	glutMotionFunc( MouseMove );
	glutPassiveMotionFunc( MousePassiveMotion );
	glutTimerFunc( 200, glint_START_Timer, 1 );
	
	glutMainLoop( );
	
	cvReleaseImage( &battle_ship );
	cvReleaseImage( &battleship );
	cvReleaseImage( &reel );
	cvReleaseImage( &sea );
	cvReleaseImage( &radar_board );
	cvReleaseImage( &ship0 );
	cvReleaseImage( &ship1 );
	cvReleaseImage( &ship2 );
	cvReleaseImage( &ship3 );
	cvReleaseImage( &ship4 );
	cvReleaseImage( &ship5 );
	cvReleaseImage( &wave );
	cvReleaseImage( &back );
}
 
void shipInit( )
{
	for( int i = 0; i < 6 ; i++){
		ship[i].ID = i;
	}
	ship[0].imagePath = ship0;
	ship[0].XY = { 1108, 186 };
	ship[0].shipSize = { 16, 67.2 };
	ship[0].real_shipSize = ship[0].shipSize;
	ship[0].oldXY = ship[0].XY;
	ship[0].newXY = ship[0].XY;
	ship[0].ShipRowCol = {0};
	ship[0].shipLength = { 1,1 };
	ship[0].rotation = false;
	ship[0].ready = false;
	
	ship[1].imagePath = ship1;
	ship[1].XY = { 1161, 186 };
	ship[1].shipSize = { 24, 65.6 };
	ship[1].real_shipSize = ship[1].shipSize;
	ship[1].oldXY = ship[1].XY;
	ship[1].newXY = ship[1].XY;
	ship[1].ShipRowCol = {0};
	ship[1].shipLength = { 1, 1 };
	ship[1].rotation = false;
	ship[1].ready = false;
	
	ship[2].imagePath = ship2;
	ship[2].XY = { 1228, 186 };
	ship[2].shipSize = { 16, 67.2 };
	ship[2].real_shipSize = ship[2].shipSize;
	ship[2].oldXY = ship[2].XY;
	ship[2].newXY = ship[2].XY;
	ship[2].ShipRowCol = {0};
	ship[2].shipLength = { 1, 1 };
	ship[2].rotation = false;
	ship[2].ready = false;
	
	ship[3].imagePath = ship3;
	ship[3].XY = { 1100, 280 };
	ship[3].shipSize = { 65, 212.5 };
	ship[3].real_shipSize = ship[3].shipSize;
	ship[3].oldXY = ship[3].XY;
	ship[3].newXY = ship[3].XY;
	ship[3].ShipRowCol = {0};
	ship[3].shipLength = { 1, 3 };
	ship[3].rotation = false;
	ship[3].ready = false;
	
	ship[4].imagePath = ship4;
	ship[4].XY = { 1202, 280 };
	ship[4].shipSize = { 50, 212.5 };
	ship[4].real_shipSize = ship[4].shipSize;
	ship[4].oldXY = ship[4].XY;
	ship[4].newXY = ship[4].XY;
	ship[4].ShipRowCol = {0};
	ship[4].shipLength = { 1, 3 };
	ship[4].rotation = false;
	ship[4].ready = false;
	
	ship[5].imagePath = ship5;
	ship[5].XY = { 1010, 170 };
	ship[5].shipSize = { 54, 336 };
	ship[5].real_shipSize = ship[5].shipSize;
	ship[5].oldXY = ship[5].XY;
	ship[5].newXY = ship[5].XY;
	ship[5].ShipRowCol = {0};
	ship[5].shipLength = { 1, 5};
	ship[5].rotation = false;
	ship[5].ready = false;
}

void WindowSize(int w, int h)
{
	sizeMagn *= h / windowY;
	windowX = w;
	windowY = h;
	glViewport( 0, 0, w, h );
}

void Keyboard( unsigned char key, int x, int y )
{
	if( key == ESC )
		exit( 1 );
}

void KeyboardSpecial( int key, int x, int y )
{
	
}

void MouseButton(int button, int state, int x, int y )
{
	mouse_down = state;
	button_mouseX = x;
	button_mouseY = y;
	switch( button )
	{
		case GLUT_LEFT_BUTTON:
			switch( frame )
			{
				case 0:
					if( x >= 923 && x <= 993 && y >= 643 && y <= 723 )
					{
						glutTimerFunc( 200, glint_START_Timer, 1 );
						frame++;
					}
					break;
				case 1:
					if( x >= 637.6 && x <= 807.6 && y >= 674 && y <= 729 )
						frame++;
					else if( x >= 643 && x <= 802 && y >= 729 && y <= 784 )
						frame--;
					break;
				case 2:
					for( int i = 0; i < 6; i++)
					{
						if(  state == 0 && x >= ship[i].newXY.x && x <= ship[i].newXY.x + ship[i].real_shipSize.width &&
										   y >= ship[i].newXY.y && y <= ship[i].newXY.y + ship[i].real_shipSize.height )
						{
							shipMOVE = ship[i].ID;
							break;
						}
					}
					if( shipMOVE != -1 )
					{
						if( state == 1 && ( ship[shipMOVE].newXY.x < 123 || ship[shipMOVE].newXY.x + ship[shipMOVE].real_shipSize.width > 701 ||
											ship[shipMOVE].newXY.y < 167 || ship[shipMOVE].newXY.y + ship[shipMOVE].real_shipSize.height > 745 ) )
						{
							initShipXY( );
						}else if( state == 1 && x >= ship[shipMOVE].newXY.x && x <= ship[shipMOVE].newXY.x + ship[shipMOVE].real_shipSize.width &&
										   		y >= ship[shipMOVE].newXY.y && y <= ship[shipMOVE].newXY.y + ship[shipMOVE].real_shipSize.height )
						{
							shipXY( 123, 167, 578, 578 );
							for( int i = ship[shipMOVE].ShipRowCol.HeadColumn; i <= ship[shipMOVE].ShipRowCol.BodyColumn; i++)
								for( int j = ship[shipMOVE].ShipRowCol.HeadRow; j <= ship[shipMOVE].ShipRowCol.BodyRow; j++)
									if( player_ships[j][i] != 0 )
										initShipXY( );
									else
									{
										if( ship[i].rotation )
											player_ships[j][i] = ship[shipMOVE].shipLength.width;
										else
											player_ships[j][i] = ship[shipMOVE].shipLength.height;
										ship[i].ready = true;
									}
						}
					}
					if( x >= 0 && x <= 100 && y >= 0 && y <= 100 )
					{
						glutTimerFunc( 200, glint_START_Timer, 1 );
						alpha = 0;
						frame--;
					}
					else if( x >= 1165 && x <= 1315 && y >= 620 && y <= 770 )
					{
						int i;
						for( i = 0; i < 6; i++)
						{
							if( ship[i].ready == false )
								break;
						}
						if( i == 6 )
						{
							frame++;
						}
					}
					else if( state == 0 && x >= 960 && x <= 1110 && y >= 620 && y <= 770 )
					{
						for( int i = 5; i >= 0; i--)
						{
							shipMOVE = i;
							initShipXY( );
						}
						initShip( player_ships );
					}
					if( state == 0 )
					{
						for( int j = ship[shipMOVE].ShipRowCol.HeadColumn; j <= ship[shipMOVE].ShipRowCol.BodyColumn; j++)
							for( int k = ship[shipMOVE].ShipRowCol.HeadRow; k <= ship[shipMOVE].ShipRowCol.BodyRow; k++)
							{
								if( ship[shipMOVE].rotation )
									player_ships[k][j] = 0;
								else
									player_ships[k][j] = 0;
								ship[shipMOVE].ready = false;
							}
					}
					break;
				case 3:
					if( state == 1 && button_mouseX >= 800 && button_mouseX <= 1340 &&
						button_mouseY >= 310 &&button_mouseY <= 850 && player_computer_sleep
						&& palyer_down )
					{
						computer_row = ( button_mouseY - 310 ) / 67.5;
						computer_column = ( button_mouseX - 800 ) / 67.5;
						player_computer_flag = true;
						palyer_init = true;
					}
					break;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if( frame == 2 )
			{
				for( int i = 0; i < 6; i++)
					{
						if(  state == 0 && x >= ship[i].newXY.x && x <= ship[i].newXY.x + ship[i].real_shipSize.width &&
										   y >= ship[i].newXY.y && y <= ship[i].newXY.y + ship[i].real_shipSize.height )
						{
							shipMOVE = ship[i].ID;
							break;
						}
					}
				for( int i = 0; i < 6; i++)
				{
					if(  state == 0 && x >= ship[i].newXY.x && x <= ship[i].newXY.x + ship[i].real_shipSize.width &&
									   y >= ship[i].newXY.y && y <= ship[i].newXY.y + ship[i].real_shipSize.height )
					{
						if( ship[i].XY.x != ship[i].newXY.x && ship[i].XY.x != ship[i].newXY.x &&
							ship[i].XY.y != ship[i].newXY.y && ship[i].XY.y != ship[i].newXY.y )
							shipMOVE = ship[i].ID;
						for( int i = ship[shipMOVE].ShipRowCol.HeadColumn; i <= ship[shipMOVE].ShipRowCol.BodyColumn; i++)
							for( int j = ship[shipMOVE].ShipRowCol.HeadRow; j <= ship[shipMOVE].ShipRowCol.BodyRow; j++)
							{
								if( ship[shipMOVE].rotation )
									player_ships[j][i] = 0;
								else
									player_ships[j][i] = 0;
								ship[shipMOVE].ready = false;
								if( player_ships[i][j] == 0 )
								{
									if( ship[shipMOVE].rotation )
									{
										ship[shipMOVE].rotation = false;
										transWidthHeight( );
										if( ship[shipMOVE].newXY.x < 123 || ship[shipMOVE].newXY.x + ship[shipMOVE].real_shipSize.width > 701 ||
											ship[shipMOVE].newXY.y < 167 || ship[shipMOVE].newXY.y + ship[shipMOVE].real_shipSize.height > 745 )
										{
											ship[shipMOVE].rotation = true;
											transWidthHeight( );
										}
									}
									else
									{
										ship[shipMOVE].rotation = true;
										transWidthHeight( );
										if( ship[shipMOVE].newXY.x < 123 || ship[shipMOVE].newXY.x + ship[shipMOVE].real_shipSize.width > 701 ||
											ship[shipMOVE].newXY.y < 167 || ship[shipMOVE].newXY.y + ship[shipMOVE].real_shipSize.height > 745 )
										{
											ship[shipMOVE].rotation = false;
											transWidthHeight( );
										}
									}
									if( ship[shipMOVE].rotation )
										player_ships[j][i] = ship[shipMOVE].shipLength.width;
									else
										player_ships[j][i] = ship[shipMOVE].shipLength.height;
									ship[shipMOVE].ready = true;
								}
							}
						ship[shipMOVE].ShipRowCol = { ( ship[shipMOVE].newXY.y - 167 ) / 72.25, ( ship[shipMOVE].newXY.x - 123 ) / 72.25,
														ship[shipMOVE].ShipRowCol.HeadRow + ship[shipMOVE].shipLength.height - 1,
														ship[shipMOVE].ShipRowCol.HeadColumn + ship[shipMOVE].shipLength.width - 1 };
						shipXY( 123, 167, 578, 578 );
						shipMOVE = -1;
						break;
					}
				}
			}
			break;
	}
	glutPostRedisplay( );
}

void MouseMove( int x, int y )
{
	move_mouseX = x;
	move_mouseY = y;
	if( frame == 2 )
	{
		if( shipMOVE != -1 && mouse_down == 0 )
		{
			ship[shipMOVE].newXY = { ship[shipMOVE].oldXY.x - button_mouseX + move_mouseX,
									 ship[shipMOVE].oldXY.y - button_mouseY + move_mouseY };
			ship[shipMOVE].ShipRowCol = { ( ship[shipMOVE].newXY.y - 167 ) / 72.25, ( ship[shipMOVE].newXY.x - 123 ) / 72.25,
											ship[shipMOVE].ShipRowCol.HeadRow + ship[shipMOVE].shipLength.height - 1,
											ship[shipMOVE].ShipRowCol.HeadColumn + ship[shipMOVE].shipLength.width - 1 };
		}
	}
	glutPostRedisplay( );
}

void MousePassiveMotion( int x, int y )
{
	mouseX = x;
	mouseY = y;
	if( frame == 2 )
	{
		ship[shipMOVE].oldXY = ship[shipMOVE].newXY;
		shipMOVE = -1;
	}
	glutPostRedisplay( );
}

void Display( )
{
	glLoadIdentity( );  //恢復初始坐標系 ( 中心為 0 , 0 )
	gluOrtho2D( 0, windowX, windowY, 0 );  //設定2D坐標系 ( 左上為 0 , 0 )
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );  //清除緩存
	
	switch( frame )
	{
		case 0:
		case 1:
			Init_one( );
			break;
		case 2:
			Init_two( );
			break;
		case 3:
			Init_three( );
			break;
	}
}

void Init_one( )
{
	Image( battle_ship );
	Image_Size( 0, 0, windowX, windowY );
	Image_Transparent( battleship, 0, 0, 0, alpha );
	Image_Size( windowX / 2 - 360, 20, 508 * 1.5, 105 * 1.5 );
	if( alpha < 255 ) alpha++;
	glDisable( GL_TEXTURE_2D );
	
	//閃爍的 START 字體 
	if( glint_START )
	{
		glColor3f( 1, 1, 0 );
		setFontHeight( 55 );
		setFontXY( windowX / 2 - 80, windowY - 190 );
		Print_Font( "START" );
		setFontXY( windowX / 2 - 74, windowY - 135 );
		Print_Font( "MENU" );
	}
	
	if( frame == 0 )
	{
		Image_Transparent( reel );
		Image_Size( 420, 20, 644, 824.6 );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );  //顏色加亮 
		glColor3f( 0, 0, 0 );
		setFontHeight( 45 );
	    setFontXY( 650, 190 );
	    Print_Font( "Battle Ship" );
		setFontHeight( 25 );
	    setFontXY( 480, 190 );
		pFile = fopen( "rule.txt", "r" );
		if ( NULL == pFile ){
        	Print_Font( "Open failure" );
    	}else{
		    fread( buffer, 1024, 1, pFile );
		    Print_Font( "%s", buffer );
		} 
	    
		glColor3f( 1, 0, 0 );
		setFontHeight( 100 );
		setFontXY( 925, 635 );
		Print_Font( "X" );
	}
	
	glutPostRedisplay( );  //重新繪製
	glutSwapBuffers( );  //交換兩個緩衝區指針 
}

void Init_two( )
{
	Image( radar_board );
	Image_Size( 0, 0, windowX, windowY );
	Image_Transparent( back );
	Image_Size( 0, 0, 100, 100 );
	glDisable( GL_TEXTURE_2D );
	
	battle_ship_green;
	checkerboard( 123, 167, 578, 578, table, table, 2 );
	
	for( int i = 5; i >= 0; i--)
	{
		Image_Transparent( ship[i].imagePath );
		Image_Size( ship[i].XY.x, ship[i].XY.y, ship[i].shipSize.width, ship[i].shipSize.height, 0, 0, 0 );
		if( ship[i].rotation )
			Counterclockwise_Degree_Rotation( ship[i].newXY.x, ship[i].newXY.y );
			
		Image_Size( ship[i].newXY.x, ship[i].newXY.y, ship[i].shipSize.width, ship[i].shipSize.height, 0, 1, 0 );
		glLoadIdentity( );
		gluOrtho2D( 0, windowX, windowY, 0 );
	}
	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	setFontHeight( 50 );
	setFontXY( 0, 0 );
		
	if( mouse_down )
	{
		initShip( player_ships );
		for( int i = 0; i < 6; i++)
			if( 123 > ship[i].newXY.x || 701 < ship[i].newXY.x || 167 > ship[i].newXY.y || 745 < ship[i].newXY.y )
			{
				ship[i].ready = false;
			}else
			{
				for( int j = ship[i].ShipRowCol.HeadColumn; j <= ship[i].ShipRowCol.BodyColumn; j++)
					for( int k = ship[i].ShipRowCol.HeadRow; k <= ship[i].ShipRowCol.BodyRow; k++)
					{
						if( ship[i].rotation )
							player_ships[k][j] = ship[i].shipLength.width;
						else
							player_ships[k][j] = ship[i].shipLength.height;
						ship[i].ready = true;
					}
			}
	}
	
	testtable( );
	
	glutSwapBuffers( );
}

void Init_three( )
{
	Image( sea );
	Image_Size( 0, 0, windowX, windowY );
	
	battle_ship_blue;
	setFontHeight( 67 );
	setFontXY( 85, 314 );
	for( int i = 65 ; i < 65 + table ; i++ )
		Print_Font( "%c\n", i );
	setFontXY( 745, 314 );
	for( int i = 65 ; i < 65 + table ; i++ )
		Print_Font( "%c\n", i );
	setFontXY( 140, 247 );
	for( int i = 1 ; i < 1 + table ; i++ )
		Print_Font( "% d ", i );
	setFontXY( 800, 247 );
	for( int i = 1 ; i < 1 + table ; i++ )
		Print_Font( "% d ", i );
	
	battle_ship_blue;
	checkerboard( 140, 310, 540, 540, table, table, 5 );
	checkerboard( 800, 310, 540, 540, table, table, 5 );
	
	for( int i = 5; i >= 0; i--)
	{
		shipMOVE = i;
		shipXY( 140, 310, 540, 540 );
		Image_Transparent( ship[i].imagePath );
		if( ship[shipMOVE].real_shipSize.width > ship[shipMOVE].real_shipSize.height || ship[i].rotation )
			Counterclockwise_Degree_Rotation( ship[i].newXY.x, ship[i].newXY.y );
		Image_Size( ship[i].newXY.x, ship[i].newXY.y, ship[i].shipSize.width, ship[i].shipSize.height, 1, 1, 1 );
		glLoadIdentity( );
		gluOrtho2D( 0, windowX, windowY, 0 );
	}
	
	if( player_computer_flag && player_computer_sleep == false )
		glutTimerFunc( 1, player_computer_sleep_Timer, 2 );
	
	if( player_computer_flag && player_computer_sleep && palyer_down && palyer_init )
	{
		check_shot( computer_row, computer_column, computer_shot, computer_ships, computer_board, computer_hits );
		glutTimerFunc( 500, player_computer_flag_Timer, 3 );
		palyer_down = false;
		palyer_init = false;
	}else if( player_computer_flag == false && player_computer_sleep )
	{
		check_shot( player_row, player_column, player_shot, player_ships, player_board, player_hits );
		palyer_down = true;
		palyer_init = true;
	}
	
	showBoard( player_board, 140, 310, fire, wave );
	showBoard( computer_board, 800, 310, fire, wave );
	
	Sleep(100);
	
	glColor3f( 0, 0, 0 );
	setFontHeight( 55 );
	setFontXY( windowX / 2 - 260, windowY / 2 );
	
	/*result( computer_hits );
	result( player_hits );*/
	if( computer_hits[0] == 14 || computer_hits[1] == 40 || player_hits[0] == 14 || player_hits[1] == 40 )
	{
		if( computer_hits[0] == 14 )
	        Print_Font( "You win the game" );
	    else if( computer_hits[1] == 40 )
	    	Print_Font( "You are garbage" );
	    if( player_hits[0] == 14 )
	        Print_Font( "You lose the game" );
	    else if( player_hits[1] == 40 )
	    	Print_Font( "You are garbage" );
	    palyer_down = false;
	}
	
	glutPostRedisplay( );
	glutSwapBuffers( );
}

void glint_START_Timer( int id )
{
	if( glint_START )
		glint_START = false;
	else
		glint_START = true;
	
	if( frame == 1 )
		glutTimerFunc( 200, glint_START_Timer, id );
}

void check_shot( int row, int column, int shot[][table], int ships[][table], int board[][table], int hits[] )
{
	if( giveShot( row, column, shot, board ) )
	{
	    changeBoard( row, column, shot, ships, board );
	    if( board[row][column] == 1 )
	        hits[0]++;
	    else if( board[row][column] == 0 )
	    	hits[1]++;
	}
}

void transWidthHeight( )
{
	GLfloat tempf;
	tempf = ship[shipMOVE].real_shipSize.width;
	ship[shipMOVE].real_shipSize.width = ship[shipMOVE].real_shipSize.height;
	ship[shipMOVE].real_shipSize.height = tempf;
	int tempi;
	tempi = ship[shipMOVE].shipLength.width;
	ship[shipMOVE].shipLength.width = ship[shipMOVE].shipLength.height;
	ship[shipMOVE].shipLength.height = tempi;
}

void shipXY( GLfloat x, GLfloat y, GLfloat width, GLfloat height )
{
	ship[shipMOVE].newXY = { x + ship[shipMOVE].ShipRowCol.HeadColumn * width / 8  + ( ship[shipMOVE].shipLength.width * width / 8 - ship[shipMOVE].real_shipSize.width ) / 2,
							 y + ship[shipMOVE].ShipRowCol.HeadRow * height / 8 + ( ship[shipMOVE].shipLength.height * height / 8 - ship[shipMOVE].real_shipSize.height ) / 2 };
}

void initShipXY( )
{
	ship[shipMOVE].oldXY = ship[shipMOVE].XY;
	ship[shipMOVE].newXY = ship[shipMOVE].XY;
	if( ship[shipMOVE].rotation )
	{
		transWidthHeight( );
		ship[shipMOVE].rotation = false;
	}
	ship[shipMOVE].ready == false;
	shipMOVE = -1;
}

void player_computer_sleep_Timer( int id )
{
	if( player_computer_sleep )
		player_computer_sleep = false;
	else
		player_computer_sleep = true;
}

void player_computer_flag_Timer( int id )
{
	if ( player_computer_flag )
	{
		player_computer_flag = false;
		do
		{
			player_row = rand( ) % 8;
			player_column = rand( ) % 8;
		}while( player_board[player_row][player_column] != -1 );
	}
	else
		if( player_computer_sleep == false )
			player_computer_flag = true;
}
