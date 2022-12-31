#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "../Figures/CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void CHexagon::PrintInfo(Output* pOut);
	void MoveFigure(Point);
	bool Contains(Point);

	void Save(ofstream& OutFile);


};

#endif