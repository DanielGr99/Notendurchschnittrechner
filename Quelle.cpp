#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

#define clearc system("cls")		//Konstante zum leeren der Konsole

void printmenu();					//Druckt das Menü
void printchart();					//Druckt die Liste
void writeline();					//fügt eine Zeile der Liste hinzu
void clearchart();					//löscht die Einträge in der Liste

int main()
{
	char c;
	do
	{
		printmenu();
		cin >> c;
		clearc;
		if (c == '2')				
		{
			writeline();
		}
		else if (c == '1')
		{
			printchart();
		}
		else if (c == '3')
		{
			clearchart();
		}
	} while (c != '0');
	

	return 0;
}

void printmenu()
{
	cout << "Liste anzeigen(1)\t" << "Zeile hinzufuegen(2)\t" << "Liste loeschen(3)\t" << "Programm beenden(0)"<<endl;
}
void printchart()
{
	string column1;
	string column2;
	string column3;
	int w = 30;
	int lines = 36;
	double percentage = 0;
	double mark = 0;
	double markpercent = 0;
	double percent = 0;
	ifstream chartin;
	chartin.open("chart.txt");
	cout << "\n\n" << setw(w) << "Fach" << setw(w) << "Wertung in %" << setw(w) << "Note" << endl;
	for (int i = 0; i < lines; i++)
	{
		column1 = "", column2 = "", column3 = "";
		getline(chartin, column1, ';');
		getline(chartin, column2, ';');
		getline(chartin, column3, '\n');
		cout << setw(w) << column1 << setw(w) << column2 << setw(w) << column3 << endl;
		if (column2 != "" && column3 != "")
		{
			percentage = stod(column2);
			mark = stod(column3);
		}
		if (column3 != "0" && column3 != "")
		{
			markpercent += percentage / 100 * mark;
			percent += percentage;
		}
	}
	cout << "\nSie haben " << percent << " Prozent ihrer Note erreicht." << endl;
	cout << "\nIhr Durchschnitt ist: " << 100 / percent * markpercent<<"\n" << endl;
	chartin.close();
}
void writeline()
{
	string s;
	ofstream chartout("chart.txt", ios::out | ios::app);
	
	cout << "Gebe das Fach ein: ";	//Fach abfragen
	cin.ignore();
	getline(cin, s);
	chartout << s + ";";
	cout << "Wertung der Note in Prozent: ";	//Wertung der Note
	getline(cin, s);
	chartout << s + ";";
	cout << "Note(Wenn Note nicht vorliegend 0 eintragen): ";			//Note abfragen
	getline(cin, s);
	chartout << s + "\n";
	system("cls");
	chartout.close();
}
void clearchart()
{
	ofstream chartout("chart.txt", ios::out | ios::trunc);
	chartout.close();
}

