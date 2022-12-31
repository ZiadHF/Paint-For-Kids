#pragma once
#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point vert1;
	Point vert2;
	Point vert3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CTriangle::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool CTriangle::Contains(Point);

	void Save(ofstream& OutFile);

};

#endif