#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = count;
	vert1 = P1;
	vert2 = P2;
	vert3 = P3;
}

void CTriangle::Save(ofstream& OutFile) {
	OutFile << "TRIANG" << " " << ID << " " << vert1.x << " " << vert1.y << " " << vert2.x << " " << vert2.y << " " << vert3.x << " " << vert3.y << " " << CheckColor(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? CheckColor(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pOut->DrawTri(vert1, vert2, vert3, FigGfxInfo, Selected);
}
//Printing Triangle information in status bar
void CTriangle::PrintInfo(Output* pOut) {
	string data1, data2, data3;
	string dataid = "ID: " + to_string(this->ID);
	data1 = " Vertex 1: (" + to_string(vert1.x) + ',' + to_string(vert1.y) + ')';
	data2 = " Vertex 2: (" + to_string(vert2.x) + ',' + to_string(vert2.y) + ')';
	data3 = " Vertex 3: (" + to_string(vert3.x) + ',' + to_string(vert3.y) + ')';
	pOut->PrintMessage("Triangle " + dataid + data1 + data2 + data3);
}
bool CTriangle::Contains(Point test) {
	int area, test_area1, test_area2, test_area3;
	area = abs((vert1.x) * (vert2.y - vert3.y) + (vert2.x) * (vert3.y - vert1.y) + (vert3.x) * (vert1.y - vert2.y));
	test_area1 = abs((test.x) * (vert2.y - vert3.y) + (vert2.x) * (vert3.y - test.y) + (vert3.x) * (test.y - vert2.y));
	test_area2 = abs((vert1.x) * (test.y - vert3.y) + (test.x) * (vert3.y - vert1.y) + (vert3.x) * (vert1.y - test.y));
	test_area3 = abs((vert1.x) * (vert2.y - test.y) + (vert2.x) * (test.y - vert1.y) + (test.x) * (vert1.y - vert2.y));
	bool cond;
	cond = (area == test_area1 + test_area2 + test_area3) ? true : false;
	return cond;

}
void CTriangle::MoveFigure(Point change) {
	Point Centroid;
	Centroid.x = (vert1.x + vert2.x + vert3.x) / 3;
	Centroid.y = (vert1.y + vert2.y + vert3.y) / 3;
	vert1.x = change.x + (vert1.x - Centroid.x);
	vert1.y = change.y + (vert1.y - Centroid.y);
	vert2.x = change.x + (vert2.x - Centroid.x);
	vert2.y = change.y + (vert2.y - Centroid.y);
	vert3.x = change.x + (vert3.x - Centroid.x);
	vert3.y = change.y + (vert3.y - Centroid.y);
}
void CTriangle::ResizeFigure(Point initial,Point final) {
	if (initial.x==vert1.x && initial.y==vert1.y) {
	
		vert1.x=final.x;
		vert1.x=final.y;
	
	}
	if (initial.x == vert2.x && initial.y == vert2.y) {

		vert2.x = final.x;
		vert2.x = final.y;

	}
	if (initial.x == vert3.x && initial.y == vert3.y) {

		vert3.x = final.x;
		vert3.x = final.y;

	}

}