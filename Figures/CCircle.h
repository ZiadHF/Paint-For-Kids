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
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CCircle::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool Contains(Point);

	void Save(ofstream& OutFile);

};

#endif