#include "sintacsisGUI.h"

sintacsisGUI::sintacsisGUI()
{
	CtrlLayout(*this, "LAB Software development technology");

	//String editString = AsString(~editSinp);
	BtStart.WhenPush = THISBACK(WriteFileInput);
	BtStarttxt.WhenPush = THISBACK(ReadFileInput);
	BtStartdocx.WhenPush = THISBACK(ReadFileInputdocx);
	BtoutMan.WhenPush = THISBACK(ListenMan);
	BtDb.WhenPush = THISBACK(ReadDB);
}

GUI_APP_MAIN
{
	sintacsisGUI().Run();
}
