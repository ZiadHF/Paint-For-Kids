#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SAVE,
	ITM_LOAD,
	ITM_UNDO,
	ITM_REDO,
	ITM_SELC,
	ITM_DELETE,
	ITM_MOVE,
	ITM_CLRA,
	ITM_SQR,
	ITM_RECT,	//Recangle item in menu
	ITM_CIRC,
	ITM_HEX,
	ITM_TRI,
	ITM_CHBORDER,
	ITM_BLACK,
	ITM_YELLOW,
	ITM_ORANGE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_CHFILL,
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_SWITCH,

	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_PICKANDHIDE,
	ITM_PICKFIGURE,
	ITM_PICKFILL,
	ITM_PICKFIGFILL,
	ITM_SWITCHDRAW,
	ITM_EXPLAY,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif