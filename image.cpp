//			image.cpp

#include "battle_ship_function.h"


void Image( IplImage *img )
{
	glEnable( GL_TEXTURE_2D );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData );
}

void Image_Transparent( IplImage *img, uchar red, uchar green, uchar blue, uchar alpha )
{
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glEnable( GL_TEXTURE_2D );
	IplImage *dst = NULL;         
   	CvSize dst_cvsize;
   	dst_cvsize.width = img->width;
	dst_cvsize.height = img->height;
	dst = cvCreateImage( dst_cvsize, img->depth, 4 );
	int x;
	int y;
	uchar r, g, b;
	for ( y = 0; y < img->height; y++ )
	{
		uchar *ptrimg = ( uchar* )( img->imageData + y * img->widthStep );
		uchar *ptrDst = ( uchar* )( dst->imageData + y * dst->widthStep );
		for ( x = 0; x < img->width; x++ )
		{
			r = ptrimg[3 * x];
			g = ptrimg[3 * x + 1];
			b = ptrimg[3 * x + 2];
			ptrDst[4 * x] = r;
			ptrDst[4 * x + 1] = g;
			ptrDst[4 * x + 2] = b;
			if (red == r && green == g && blue == b)
				ptrDst[4 * x + 3] = 0;
			else
				ptrDst[4 * x + 3] = alpha;
		}
	} 
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, dst->width, dst->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dst->imageData );
	cvReleaseImage(&dst);
}

void Image_Size( GLfloat x1, GLfloat y1, GLfloat width, GLfloat height, GLfloat red,GLfloat green,GLfloat blue )
{
	GLfloat x2 = x1 + width;
	GLfloat y2 = y1 + height;
	glColor3f( red, green, blue );
	glBegin(GL_QUADS);
		glTexCoord2f( 0, 0 ); glVertex2f( x1, y1 );
		glTexCoord2f( 0, 1 ); glVertex2f( x1, y2 );
		glTexCoord2f( 1, 1 ); glVertex2f( x2, y2 );
		glTexCoord2f( 1, 0 ); glVertex2f( x2, y1 );
	glEnd( );
}
