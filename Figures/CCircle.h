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
	virtual void Draw(Output* pOut) const;
	void CCircle::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool Contains(Point);
	string TempSave();
	void TempLoad(istringstream& InFile);
	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);

};

#endif