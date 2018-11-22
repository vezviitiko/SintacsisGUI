#ifndef _sintacsisGUI_sintacsisGUI_h
#define _sintacsisGUI_sintacsisGUI_h

#include <CtrlLib/CtrlLib.h>

#include "Postgres.h"

using namespace Upp;

#define LAYOUTFILE <sintacsisGUI/sintacsisGUI.lay>
#include <CtrlCore/lay.h>

class sintacsisGUI : public WithsintacsisGUILayout<TopWindow> {
public:
	typedef sintacsisGUI CLASSNAME;
	sintacsisGUI();
	void ReadFileInput();
	void WriteFileInput();
	void ReadFileOutput();
	void ReadFileInputdocx();
	void PythonAnaliz();
	void ReadDB();
	void CreateStatistics();
	void ListenMan();
};

#endif
