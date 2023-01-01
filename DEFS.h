#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SAVE,
	LOAD,
	UNDO,
	REDO,
	SELECT,
	MOVE,
	CLEARALL,
	DRAW_SQR,
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,
	DRAW_HEX,
	DRAW_TRI,
	CHANGEBORDERCOLOR,
	BLACK_COLOR,
	YELLOW_COLOR,
	ORANGE_COLOR,
	RED_COLOR,
	GREEN_COLOR,
	BLUE_COLOR,
	CHANGEFILL,
	STARTREC,
	STOPREC,
	PLAYREC,
	SWITCH,
	SWITCHDRAW,
	EXIT,	//Exit
	DEL,
	//EXPLAY,
	PICKANDHIDE,
	EMPTY,	//A click on empty place in the toolbar

	PICKFIGURE,
	PICKFILL,
	PICKFIGFILL,
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

enum PickAndHideModes {
	Figure,
	Fill,
	FigFill,
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif