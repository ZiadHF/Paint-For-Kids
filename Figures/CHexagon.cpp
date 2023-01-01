
#include "..\Figures\CHexagon.h"
#include<cmath>
#include<string>
CHexagon::CHexagon()  
{
	 
}
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = count;
	Center = P1;
}
void CHexagon::Save(ofstream& OutFile) {
	OutFile << "HEX" << " " << ID << " " << Center.x << " " << Center.y << " " << CheckColor(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}
//Printing Hexagon information in status bar
void CHexagon::PrintInfo(Output* pOut) {
	string data1;
	string dataid = "ID: " + to_string(ID);
	data1 = " Center: (" + to_string(Center.x) + ',' + to_string(Center.y) + ')';
	pOut->PrintMessage("Hexagon " + dataid + data1);
}
bool CHexagon::Contains(Point test) {
	const double pi = 3.14;
	int s = 50;
	int vertx[6] = { Center.x + s, Center.x + s * cos(pi / 3),Center.x + s * cos(6 * pi / 9) ,Center.x - s ,Center.x + s * cos(6 * pi / 9),Center.x + s * cos(pi / 3) };
	int verty[6] = { Center.y, Center.y + s * sin(pi / 3) , Center.y + s * sin(6 * pi / 9),Center.y,Center.y - s * sin(6 * pi / 9),Center.y - s * sin(pi / 3) };
	int i, j;
	bool c = false;
	for (i = 0, j = 6 - 1; i < 6; j = i++) {
		if (((verty[i] > test.y) != (verty[j] > test.y)) &&
			(test.x < (vertx[j] - vertx[i]) * (test.y - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
			c = !c;
	}
	return c;
}
void CHexagon::Load(ifstream& InFile) {
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
void CHexagon::MoveFigure(Point change) {
	Center.x = change.x;
	Center.y = change.y;

}