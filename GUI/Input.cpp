#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
bool Input::MouseClicked(){
	buttonstate test;
	int x, y;
		test= pWind->GetButtonState(LEFT_BUTTON,x,y);
		if (test == BUTTON_DOWN)
			return true;
		return false;
}
void Input::MousePos(int&x, int&y) {
	pWind->GetMouseCoord(x, y);

}
string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SELC: return SELECT;
			case ITM_MOVE: return MOVE;
			case ITM_CLRA: return CLEARALL;
			case ITM_SQR: return DRAW_SQR;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_HEX: return DRAW_HEX;
			case ITM_TRI: return DRAW_TRI;
			case ITM_CHBORDER: return CHANGEBORDERCOLOR;
			case ITM_BLACK: return BLACK_COLOR;
			case ITM_YELLOW: return YELLOW_COLOR;
			case ITM_ORANGE: return ORANGE_COLOR;
			case ITM_RED: return RED_COLOR;
			case ITM_GREEN: return GREEN_COLOR;
			case ITM_BLUE: return BLUE_COLOR;
			case ITM_CHFILL: return CHANGEFILL;
			case ITM_STARTREC: return STARTREC;
			case ITM_STOPREC: return STOPREC;
			case ITM_PLAYREC:return PLAYREC;
			case ITM_SWITCH: return SWITCH;
			case ITM_DELETE: return DEL;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PICKANDHIDE: return PICKANDHIDE;
			case ITM_PICKFIGURE: return PICKFIGURE;
			case ITM_PICKFILL:	return PICKFILL;
			case ITM_PICKFIGFILL: return PICKFIGFILL;
			case ITM_SWITCHDRAW: return SWITCHDRAW;
			case ITM_EXPLAY: return EXIT;
				///TODO:
				//perform checks similar to Draw mode checks above
				//and return the correspoding action
				//return TO_PLAY;	//just for now. This should be updated
			}
		}
	}

}
/////////////////////////////////

Input::~Input()
{
}
