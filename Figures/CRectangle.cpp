#include "CRectangle.h"
#include<cmath>
CRectangle::CRectangle() {

}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = count;
	Corner1 = P1;
	Corner2 = P2;
	Width = abs(Corner2.x - Corner1.x);
	Height = abs(Corner2.y - Corner1.y);
}
void CRectangle::Save(ofstream& OutFile) {
	OutFile << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << CheckColor(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
//Printing Rectangle information in status bar
void CRectangle::PrintInfo(Output* pOut) {
	string data1, data2, data3, data4;
	string dataid = "ID: " + to_string(ID);
	data1 = " Corner1: (" + to_string(Corner1.x) + ',' + to_string(Corner1.y) + ')';
	data2 = " Corner2: (" + to_string(Corner2.x) + ',' + to_string(Corner2.y) + ')';
	data3 = " Width = " + to_string(Width);
	data4 = " Height = " + to_string(Height);
	pOut->PrintMessage("Rectangle " + dataid + data1 + data2 + data3 + data4);
}

bool CRectangle::Contains(Point test) {
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	if (test.x >= (Center.x - Width / 2) && test.x <= (Center.x + Width / 2) && test.y >= (Center.y - Height / 2) && test.y <= (Center.y + Height / 2))
		return true;
	else
		return false;
}
void CRectangle::Load(ifstream& InFile) {
	int x;
	InFile >> x;
	ID = x;
	InFile >> x;
	Corner1.x = x;
	InFile >> x;
	Corner1.y = x;
	InFile >> x;
	Corner2.x = x;
	InFile >> x;
	Corner2.y = x;
	Width = abs(Corner2.x - Corner1.x);
	Height = abs(Corner2.y - Corner1.y);
	string y;
	InFile >> y;
	FigGfxInfo.DrawClr = StringToColor(y);
	InFile >> y;
	FigGfxInfo.FillClr = StringToColor(y);
	
	FigGfxInfo.isFilled = (FigGfxInfo.FillClr != HOTPINK);
}
void CRectangle::MoveFigure(Point change) {

	Point Center;
	Center.x = (Corner1.x+Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Corner1.x = change.x + (Corner1.x - Center.x);
	Corner1.y = change.y + (Corner1.y - Center.y);
	Corner2.x = change.x + (Corner2.x - Center.x);
	Corner2.y = change.y + (Corner2.y - Center.y);
	
}