#include "..\Figures\CSquare.h"
CSquare::CSquare() {
	ID = 0;
}

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = count;
	Center = P1;

}
void CSquare::Save(ofstream& OutFile) {
	OutFile << "SQR" << " " << ID << " " << Center.x << " " << Center.y << " " << CheckColor(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a Square on the screen	
	pOut->DrawSqr(Center, FigGfxInfo, Selected);
}
//Printing Square information in status bar
void CSquare::PrintInfo(Output* pOut) {
	string data1, data2;
	string dataid = "ID: " + to_string(ID);
	data1 = " Center: (" + to_string(Center.x) + ',' + to_string(Center.y) + ')';
	data2 = " Side = 100";
	pOut->PrintMessage("Square " + dataid + data1 + data2);
}
bool CSquare::Contains(Point test) {
	if (test.x >= (Center.x - 50) && test.x <= (Center.x + 50) && test.y >= (Center.y - 50) && test.y <= (Center.y + 50))
		return true;
	else
		return false;
}
void CSquare::Load(ifstream& InFile) {
	int x;
	InFile >> x;
	ID = x;
	InFile >> x;
	Center.x = x;
	InFile >> x;
	Center.y = x;
	string y;
	InFile >> y;
	FigGfxInfo.DrawClr = StringToColor(y);
	InFile >> y;
	FigGfxInfo.FillClr = StringToColor(y);
	FigGfxInfo.isFilled = (FigGfxInfo.FillClr != HOTPINK);
}
void CSquare::MoveFigure(Point change) {
	Center.x = change.x;
	Center.y = change.y;
}