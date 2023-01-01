#ifndef CFIGURE_H
#define CFIGURE_H
#include<cmath>
#include<string>
#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
//Base class for all figures
class CFigure
{
protected:


	
	static int count;
	int ID;		//Each figure has an ID

	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.

public:
	CFigure();

	CFigure(GfxInfo FigureGfxInfo);
	void SetFilled(color c);
	bool IsFilled() const;
	
	string CheckColor(color x);//Returns color as String
	
	color StringToColor(string x);//Takes string and returns color
	
	void SetSelected(bool s);	//select/unselect the figure
	
	bool IsSelected() const;	//check whether fig is selected
	
	virtual void MoveFigure(Point)=0;//Moves Figure
	
	virtual void Draw(Output* pOut) const = 0;//Draw the figure
	
	void setID(int);//Sets figure id
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetColor();


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	
	virtual bool Contains(Point) = 0;//Virtual function for checking if the clicked point is contained in shape
	
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif