#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	int Height, Width;

public:
	CRectangle();
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool Contains(Point);
	string TempSave();
	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);
};

#endif