#pragma once
#ifndef CCir_H
#define CCir_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	string TempSave();
	void TempLoad(istringstream& InFile);
	virtual void Draw(Output* pOut) const;//Draws circle on screen
	void CCircle::PrintInfo(Output* pOut);//Prints circle info
	void MoveFigure(Point);//Moves circle
	bool Contains(Point);//Checks if circle contains point
	void Save(ofstream& OutFile);//Saves circle info
	void Load(ifstream& InFile);//Loads circle info

};

#endif