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
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool Contains(Point);

	void Save(ofstream& OutFile);

};

#endif