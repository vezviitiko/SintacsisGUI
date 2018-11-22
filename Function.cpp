#include "sintacsisGUI.h"

void sintacsisGUI::ReadFileInput(){
	StringStream inStream;
	String inString, Stringsave;
	inStream.Open(LoadFile("/home/comis/develop/project/sintacsis/input.txt"));
	do{
		inString = inStream.GetLine();
		Stringsave = Stringsave + inString + "\n";
		}
		while(!inStream.IsEof());
	editSinp <<= Stringsave;
	
	PythonAnaliz();
}

void sintacsisGUI::ReadFileInputdocx(){
	StringStream inStream;
	String inString, Stringsave;
	inStream.Open(LoadFile("/home/comis/develop/project/sintacsis/input.docx"));
	do{
		inString = inStream.GetLine();
		Stringsave = Stringsave + inString + "\n";
		}
		while(!inStream.IsEof());
	editSinp <<= Stringsave;
	
	system("cd /home/comis/develop/project/sintacsis && /usr/bin/python3 phrases.py 2");
	ReadFileOutput();
	ListenMan();
}

void sintacsisGUI::WriteFileInput(){
	FILE * pFile;
	pFile = fopen ("/home/comis/develop/project/sintacsis/input.txt","w");
	if (pFile!=NULL){
		fputs(Format("%s\n",AsString(~editSinp)),pFile);
		fclose(pFile);
		}
		
	PythonAnaliz();
}

void sintacsisGUI::ReadFileOutput(){
	StringStream inStream;
	String inString, Stringsave;
	inStream.Open(LoadFile("/home/comis/develop/project/sintacsis/output.txt"));
	do{
		inString = inStream.GetLine();
		Stringsave = Stringsave + inString + "\n";
		}
		while(!inStream.IsEof());
	editSout <<= Stringsave;
}

void sintacsisGUI::PythonAnaliz(){
	system("cd /home/comis/develop/project/sintacsis && /usr/bin/python3 phrases.py 1 ");
	ReadFileOutput();
	ListenMan();
}
void sintacsisGUI::CreateStatistics(){

}

void sintacsisGUI::ReadDB(){
	PostgreSQLTest dlg;
	if(dlg.OpenDB()){
		Sql sql;
		String outString;
		sql.Clear();
		sql.Execute("SELECT Count(*) FROM information_schema.tables WHERE table_name = 'wordsafe' ");
		while (sql.Fetch())
		{
			if ((int)sql[0] == 0)
			{
				outString = "Таблицы не существует";
			}
			else{
				outString = "База данных \n ======================================= \n Cлово				Часть речи	Падеж	Количество \n ======================================= \n";
				sql.Execute("Select * from wordsafe");
				while (sql.Fetch()){
					outString = outString + AsString(sql[0]) + "	" + AsString(sql[1]) + "	" + AsString(sql[2]) + "	" + AsString(sql[3]) + "\n";
				}
			outstat <<= outString;
			}
		}
	}
	dlg.CloseDB();
}
void sintacsisGUI::ListenMan(){
	StringStream inStream;
	String inString, Stringsave;
	inStream.Open(LoadFile("/home/comis/develop/project/sintacsis/manual.txt"));
	do{
		inString = inStream.GetLine();
		Stringsave = Stringsave + inString + "\n";
		}
		while(!inStream.IsEof());
	outstat <<= Stringsave;
}
