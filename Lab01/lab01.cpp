//Frankie Galtieri
//Lab 01
//9-11-17
//Cosc II

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string userFile;
	ifstream fileName;
	int ticker = 0; //Adds up the amount of digits in the file.
	double totalC = 0; //Adds up all characters in the file.
	double digits; //Stores a temp number read from file.
	double uno, dos, tres, quatro; //Stores the first and last two digits from the file.
	
	cout << "Enter the file name: " << endl;
	cin >> userFile;
	fileName.open(userFile);
	cout << "opening File..." << endl;
		if (!fileName)
		{
			cout << "file not found." << endl;
		}
		else
		{
			while (!fileName.eof())
			{
				//cout << "File opened: " << endl;
				fileName >> digits;
				cout << digits << endl;
				if (ticker == 0)
				{
					uno = digits;
				}
				else if (ticker == 1)
				{
					dos = digits;
				}
				ticker++;
			}

			fileName.seekg(0, ios::beg); //resets stream back to beginning
			fileName.clear();
			double size = ticker; //stores the amount of doubles in the file just read.
			ticker = 0; //resets ticker.


			while (!fileName.eof())
			{
				/*cout << "File RE-opened: " << endl;*/
				fileName >> digits;
				cout << digits << endl;
				ticker - 1;
				if (ticker == size - 2)
				{
					quatro = digits;
				}
				else if (ticker == size - 1)
				{
					tres = digits;
				}
				ticker++;
			}
			cout << "First two digits: " << uno << " " << dos << endl;
			cout << "Last two digits: " << tres << " " << quatro << endl;
			cout << "Total digits in file: " << ticker << endl;
			fileName.close();
			system("PAUSE");
			return 0;
	}
}