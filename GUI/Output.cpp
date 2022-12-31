#include "Output.h"
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1234;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 47;
	UI.MenuItemWidth = 47;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_SELC] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_CLRA] = "images\\MenuItems\\clearall.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\drawsquare.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\drawrectangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\drawcircle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\drawhexagon.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\drawtriangle.jpg";
	MenuItemImages[ITM_CHBORDER] = "images\\MenuItems\\changebordercolor.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_CHFILL] = "images\\MenuItems\\changefillcolor.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\startrec.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\stoprec.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\playrec.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\drawmode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICKANDHIDE] = "images\\MenuItems\\pickandhide.jpg";
	MenuItemImages[ITM_PICKFIGURE] = "images\\MenuItems\\figure.jpg";
	MenuItemImages[ITM_PICKFILL] = "images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[ITM_PICKFIGFILL] = "images\\MenuItems\\figureandcolor.jpg";
	MenuItemImages[ITM_SWITCHDRAW] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_EXPLAY] = "images\\MenuItems\\exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSqr(Point C1, GfxInfo SqrGfxInfo, bool selected) const {
	color DrawingClr;
	selected ? DrawingClr = UI.HighlightColor : DrawingClr = SqrGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}
	// Assuming that the square side length is 100px
	pWind->DrawRectangle(C1.x - 50, C1.y - 50, C1.x + 50, C1.y + 50, style);
}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const {
	color DrawingClr;
	selected ? DrawingClr = UI.HighlightColor : DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawHex(Point C1, GfxInfo HexGfxInfo, bool selected) const {
	color DrawingClr;
	selected ? DrawingClr = UI.HighlightColor : DrawingClr = HexGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}
	const double pi = 3.14;
	int s = 50;
	//Done to remove double to int warning
#pragma warning( disable : 4244)
#pragma warning( disable : 4838)

	int x[6] = { C1.x + s, C1.x + s * cos(pi / 3),C1.x + s * cos(6 * pi / 9) ,C1.x - s ,C1.x + s * cos(6 * pi / 9),C1.x + s * cos(pi / 3) };
	int y[6] = { C1.y, C1.y + s * sin(pi / 3) , C1.y + s * sin(6 * pi / 9),C1.y,C1.y - s * sin(6 * pi / 9),C1.y - s * sin(pi / 3) };
	pWind->DrawPolygon(x, y, 6, style);
}
void Output::DrawCir(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected) const {
	color DrawingClr;
	selected ? DrawingClr = UI.HighlightColor : DrawingClr = CirGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CirGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}
	int radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

