#pragma once
#ifndef CSQR_H
#define CSQR_H

#include "..\Figures\CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	void Load(ifstream& InFile);
	virtual void Draw(Output* pOut) const;
	void CSquare::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	void TempLoad(istringstream& InFile);
	bool CSquare::Contains(Point);
	string TempSave();
	void Save(ofstream& OutFile);
	 
};

#endif