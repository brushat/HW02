/*
 * @file Rect.cpp
  * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 * @author Scott Vincent
 * @date 09/09/2012
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 */ 

#include "cinder/gl/gl.h"
#include "Rect.h"

using namespace ci;
using namespace std;		// standard library


	// constructor

	Rect::Rect();

	Rect::Rect (float x1, float y1, float x2, float y2, Color8u(0,0,0) )
   {	x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;

		color = new uint8_t[3];
		//question is how to get the colors from the function call into the array
		color[0] = 255;
		color[1] = 255;
		color[2] = 255;
	}

void drawRectangle(int xA, int yA, int xB, int yB, Color8u* line, Color8u* fill);

void Rect::drawRect(){

//using cinder: http://libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html
// set color
gl::color(color[0], color[1], color[2]);
// draw rectangle
gl::drawSolidRect(Rectf (x1_, y1_, x2_, y2_) );


}

/**

// original rect code from HW01

	void Rect::drawRect(uint8_t* pixels, int x_width, int y_height, int x_origin, int y_origin, Color8u cn) {

		if ( (x_width < AppWidth) && (y_height < AppHeight) ){
		
		// start at y_origin
		for ( int y = y_origin; y <= (y_height); y++ ){
			for ( int  x = x_origin; x <= (x_origin + x_width); x++ ) {
				pixels [3* (x + y*(TextureSize))  ] = c.r;
				pixels [3* (x + y*(TextureSize))+1] = c.g;
				pixels [3* (x + y*(TextureSize))+2] = c.b;
				//rect_width-1
				}
			}
		} //end if

	} // end drawRect
*/


