//			font.cpp

#include "battle_ship_function.h"


DWORD fdwCharSet = CHINESEBIG5_CHARSET;
const char *pszFaceName = "Courier New";
int cHeight = 16;
GLuint base = glGenLists( 65536 );
HFONT hFont = CreateFont( cHeight, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, fdwCharSet, 
						  OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
						  FF_DONTCARE | DEFAULT_PITCH, pszFaceName );
GLfloat FontX = 4, FontY = 0;
bool fontxy = false;

int Print_Font( const char *format, ... )
{
	char buffer[65536];
	va_list args;
	va_start( args, format );
	vsprintf( buffer, format, args );
	va_end( args );

	static bool loaded[65536] = {0};
	float p0[4], p1[4], c0[2][4] = {{ 0, 0, 0, 1}, {1, 1, 1, 1}};
	int i, j, len;
	wchar_t *wstr;
	GLint viewport[4];
	HDC hdc = 0;

	glGetIntegerv( GL_VIEWPORT, viewport );
	glGetFloatv( GL_CURRENT_RASTER_POSITION, p0 );

	glPushAttrib( GL_LIGHTING_BIT | GL_DEPTH_BUFFER_BIT );
		glDisable( GL_LIGHTING );
		glDisable( GL_DEPTH_TEST );

	glMatrixMode( GL_PROJECTION );
		glPushMatrix( );
		glLoadIdentity( );
		gluOrtho2D( 0, viewport[2], 0, viewport[3] ); 

	glMatrixMode( GL_MODELVIEW );
		glPushMatrix( );
		glLoadIdentity( );

	if( fontxy )
	{
		glRasterPos2f( FontX, viewport[3] - cHeight / 1.3 - FontY );
		fontxy = false;
	}else
	{
		glRasterPos2f( p0[0], p0[1] );
		glGetFloatv( GL_CURRENT_RASTER_COLOR, c0[1] );
		len = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, buffer, -1, 0, 0 );
		wstr = ( wchar_t * )malloc( len * sizeof( wchar_t ) );
		MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, buffer, -1, wstr, len );
		glColor4fv( c0[1] );
		glRasterPos2f( p0[0], p0[1] );
		for( i = 0; i < len - 1; i++ )
		{
			if( wstr[i] == '\n' )
			{
				glGetFloatv( GL_CURRENT_RASTER_POSITION, (float*)&p1 );
				glRasterPos2f( FontX, p1[1] - cHeight );
			}else
			{
				if( hdc == 0 )
				{
					hdc = wglGetCurrentDC( );
					SelectObject( hdc, hFont );
				}
				wglUseFontBitmapsW( hdc, wstr[i], 1, base + wstr[i] );
				loaded[wstr[i]] = true;
				glCallList( base + wstr[i] );
			}
		}
		free( wstr );
	}

	glMatrixMode( GL_PROJECTION );
		glPopMatrix( );
	glMatrixMode( GL_MODELVIEW );
		glPopMatrix( );
	glPopAttrib( );
	
	return 0;
}

void setFontXY( GLfloat x, GLfloat y )
{
	FontX = x;
	FontY = y;
	fontxy = true;
	Print_Font( "" );
}

void setFontHeight( int Height )
{
	cHeight = Height;
	setCreateFont( );
}

void setFontFace( const char *FaceName )
{
	pszFaceName = FaceName;
	setCreateFont( );
}

void setCreateFont( )
{
	hFont = CreateFont( cHeight, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, fdwCharSet, 
						OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
						FF_DONTCARE | DEFAULT_PITCH, pszFaceName );
}
