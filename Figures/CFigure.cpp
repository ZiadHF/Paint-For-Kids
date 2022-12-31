#include "CFigure.h"
#include <iostream>
int CFigure::count = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	count++;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetFilled(color c) {
	FigGfxInfo.FillClr = c;
}

bool CFigure::IsFilled() const {
	return (FigGfxInfo.isFilled);
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}
color CFigure::GetColor() {
	return (FigGfxInfo.FillClr);
}
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
void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
void CFigure::setID(int id) {
	ID = id;
}
