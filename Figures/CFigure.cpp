#include "CFigure.h"
#include <iostream>
int CFigure::count = 0;

CFigure::CFigure()
{
	count++;
	
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	count++;
	FigGfxInfo = FigureGfxInfo;	
	Selected = false;
}

void CFigure::SetFilled(color c) {
	FigGfxInfo.FillClr = c;
}

bool CFigure::IsFilled() const {
	return FigGfxInfo.isFilled;
}

//Sets Figure selection status
void CFigure::SetSelected(bool s)
{
	Selected = s;
}
//Takes a string and returns its color
color CFigure::StringToColor(string x) {
	if (x == "BLACK") {
		return BLACK;
	}
	if (x == "YELLOW") {
		return YELLOW;
	}
	if (x == "ORANGE") {
		return ORANGE;
	}
	if (x == "RED") {
		return RED;
	}
	if (x == "GREEN") {
		return GREEN;
	}
	if (x == "BLUE") {
		return BLUE;
	}
	return HOTPINK;
}
color CFigure::GetColor() {
	return (FigGfxInfo.FillClr);
}
//Takes a color and returns a string
string CFigure::CheckColor(color x) {

	if (x == BLACK) {
		return "BLACK";
	}
	if (x == YELLOW) {
		return "YELLOW";
	}
	if (x == ORANGE) {
		return "ORANGE";
	}
	if (x == RED) {
		return "RED";
	}
	if (x == GREEN) {
		return "GREEN";
	}
	if (x == BLUE) {
		return "BLUE";
	}
	return "NO_FILL";
}


//Checks if the figure is selected
bool CFigure::IsSelected() const
{
	return Selected;
}
//Changes figure drawing color
void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}
//Changes figure fill color
void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
//Sets figure ID
void CFigure::setID(int id) {
	ID = id;
}

