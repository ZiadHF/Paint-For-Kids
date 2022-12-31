#pragma once
#ifndef CSQR_H
#define CSQR_H

#include "..\Figures\CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CSquare::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool CSquare::Contains(Point);
	void ResizeFigure();
	void Save(ofstream& OutFile);
	 
};

#endif