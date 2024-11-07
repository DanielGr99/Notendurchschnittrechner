#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;


int main()
{
	//Datei zum schreiben öffnen
	ofstream chartout("chart.txt");
	char c;
	int i;
	string s;
	int w = 20;
	int lines = 36;
	
	cout << "Neue Zeile hinzufuegen?(J/N): ";
	cin >> c;
	system("cls");
	while(c == 'J' || c == 'j') 
	{
		cout << "Gebe das Fach ein: ";	//Fach abfragen
		cin.ignore();
		getline(cin, s);
		chartout  << s + ";";
		cout << "Wertung der Note in Prozent: ";	//Wertung der Note
		getline(cin, s);
		chartout << s + ";";
		cout << "Note(Wenn Note nicht vorliegend 0 eintragen): ";			//Note abfragen
		getline(cin, s);
		chartout << s + "\n";
		system("cls");
		cout << "Neue Zeile hinzufuegen?(J/N): ";
		cin >> c;
		system("cls");
	}
	chartout.close();
	string column1;
	string column2;
	string column3;
	double percentage=0;
	double mark =0;
	double markpercent = 0;
	double percent =0;
	ifstream chartin;
	chartin.open("chart.txt");
	cout <<"\n\n" << setw(w) << "Fach" << setw(w) << "Wertung in %" << setw(w) << "Note" << endl;
	for (int i=0;i<36;i++)
	{
		column1="", column2="", column3="";
		getline(chartin, column1, ';');
		getline(chartin, column2, ';');
		getline(chartin, column3, '\n');
		cout << setw(w)<<column1 << setw(w)<<column2 << setw(w)<< column3 << endl;
		if (column2 != "" && column3 != "") 
		{
			percentage = stod(column2);
			mark = stod(column3);
		}
		if (column3 != "0" && column3!= "")
		{
			markpercent+= percentage / 100 * mark;
			percent += percentage;
		}
	}
	cout << "Sie haben " << percent << " Prozent ihrer Note erreicht." << endl;
	cout << "Ihr Durchschnitt ist: " << 100 / percent * markpercent << endl;
	chartin.close();
	

	return 0;
}


