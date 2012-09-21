/**
 * @file HW02App.cpp
 * CSE 274 - Fall 2012
 * My solution for HW02.
 *
 * @author Scott Vincent
 * @date 09-09-2012
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 *
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "Rect.h"		 // class header
#include "List.h"		 // class header



using namespace ci;
using namespace ci::app;
using namespace std;



// this HW02App should go in a header file
class HW02App : public AppBasic {

  public:

	// Cinder specific methods
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );
	void prepareSettings(Settings* settings);
	void setup();
	void update();
	void draw();
	//void showMenu(int);


  private:

	  // define the List
	  Node* theList_;

	  // define sentinel
	  Node* sentinel_;

		//Width and height of the screen
		static const int AppWidth=800;
		static const int AppHeight=600;
		static const int TextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
		Surface* mySurface_;
		uint8_t* dataArr;
		//bgColor = new Color8u (255,255,255);
		
		
		// declare the menu functions
		bool menuOn_;
		Surface* menu_;
		Surface* background_;

		

		//maybe I'll need this
		Rect* tempRect_;

	
};  // the above should really go in a .h file


/**
Local Variables
*/
	int red = 200;
	int green = 200;
	int blue = 000;
	



void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(AppWidth,AppHeight);
	settings->setResizable(false);
}



void HW02App::setup()
{
	// prepare the surface
	mySurface_ = new Surface(TextureSize,TextureSize,false);
	dataArr = mySurface_->getData();
	
	// set the menu image function to on
	menuOn_ = true;
	
	Surface menu (loadImage( loadResource(RES_MENU) ) );
	menu_ = new Surface(TextureSize, TextureSize, true);
	//background_ = new Surface(TextureSize, TextureSize, true);

	
	/**
	First:	construct the sentinel node
	//Establishes the inital sentinal node for our circular list. 
	*/
	sentinel_ = new Node;
	sentinel_ = next_ = prev_ = this;
	sentinel_->data_ = NULL;

    
	/**
	Second:
	/// make node call 4x for rectangles

	this is the code from cinder web
		Rectf rect( mLoc.x, mLoc.y, mLoc.x + mRadius, mLoc.y + mRadius );
		gl::drawSolidRect( rect );
	?? can I pass in a color?? 
	
	http://libcinder.org/docs/v0.8.4/classcinder_1_1_rect_t.html#adf917a76e5a25087be8094989d4e352d
	Rect::rect(int startX, int startY, int endX, int endY, color() );
	Rect::rect(100, 100, 200, 200, (100,200,50) );
	Rect::rect(120, 120, 220, 220, (20,10,150) );
	Rect::rect(140, 140, 240, 240, (150,150,150) );
	
	... or ...
	Rect::rect(int position, startX+20, startY+20, endX+20, endY+20, (200,100,50) );
	
	...	or ...
	Node::insertAfter (Rect::rect(int position, 100, 50, 100, 100, (200,100,50), node) );


	Third:
	?? how do we add this rect node to the link list
	?  insertAfter();
	*/
	
	theList_ = new Node(rect1, sentinel_);

	theList_ ;
	
	drawRect(10,10,50,50,new Color8u(0,0,0), new Color8u(255,0,0), dataArr);
    insertNode(sentinel, 600, 190, 100);
    insertNode(sentinel->next, 400, 350, 100);

}


void HW02App::mouseDown( MouseEvent event ) {
	
	/// if doing something with coordinates:
	//int x = event.getX();
	//int y = event.getY();
	
	 if( event.isRight() ) {
		 // call reorder list
    }

	  if( event.isLeft() ) {
		 // call something list
    }

	 aRect_ =  new Rect(event.getX(), event.getY(), event.getX()+10. event.getX()+10); // pass some mouse click info here
}



/**
libcinder.org/docs/v0.8.2/hello_cinder_chapter3.html
*/
void  HW02App::keyDown( KeyEvent event ) {
	

    if( event.getChar() == 'q' ){
        // call  add rect node
    } else if( event.getChar() == 'w' ){
        //call reverse node
    } else if( event.getChar() == 'e' ){
        // call rearrange rect node
    } else if( event.getChar() == '?' ){
        if (menuOn_) {
			// toggle console to off
			menuOn_ = false;
		} else { 
			// toggle to on 
			menuOn_ = true; //menuOn_ = true
			
		}
    }


} // end keyDown


/**
void HW02App::showMenu(int on){
    if (on = 1) {
		// draw menu screen
		  menuOn_ = true;
	} else {
		// turn menu screen off
		// have to call the image/resources function from HW01
		menuOn_ = false;
	} 
}
*/


void HW02App::update()
{
	// show console with controls q, w, e, r, t,
	// keep the instructions in the console screen
	 console() << "Press Q for something. \n Press W for something else. \n Press E for something else. \n Press T for something else. \n Press ? to toggle the display. \n "  << std::endl;

	 //Go through linked list draw every node. 
	for(Node* cur_ = sentinel_->next_; cur_->item != NULL; cur_ = cur_->next_)
	   {
		cur_-> data_ -> drawRect();
		}

}

void HW02App::draw()
{
		// clear out the window with black
		gl::clear( Color( 0, 0, 0 ) ); 


		// draw background, if I decide to use it
		gl::draw(*background_);

		// draw the menu if it's value is true
		/**
		if( myImage )
			gl::draw( myImage, getWindowBounds() );
		*/
		if(menuOn_){
		gl::draw(*menu_ , getWindowBounds());
		}



	// for drawing text on screen
	//http://libcinder.org/docs/v0.8.4/_text_8h.html
	//http://libcinder.org/docs/v0.8.4/classcinder_1_1_text_layout.html
	//http://libcinder.org/docs/v0.8.4/classcinder_1_1_text_box.html
	
	
}


void randomColor(){
    red =   rand()%256;		//use modulus to get a random color
    green = rand()%256;
    blue =  rand()%256;
}

CINDER_APP_BASIC( HW02App, RendererGl )
