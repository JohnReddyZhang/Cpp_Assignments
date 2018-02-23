#include <iostream>
#include <fstream>
#include <string>
//#define DEBUG
using namespace std;
//Parameter is set in properties.
int main(int argc, char* argv[])
{
#ifdef DEBUG
	cout << argc << endl;
	if (argc == 2) cout << "file name is " << argv[0] << "\nParameter is " << argv[1] << endl;
	cout << "Hello world!" << endl;
	system("pause");
#endif
	cout << "Opening file " << argv[1] << "..." << endl;
	fstream filestream(argv[1], ios_base::in);
	if (filestream.is_open())
	{
		cout << "Found File" << argv[1] << ", the file content is:" << endl;
		string fileContents;
		while (filestream.good())
		{
			getline(filestream, fileContents);
			cout << fileContents << endl;
		}
		cout << "\nThis is the end of your file." << endl;
		filestream.close();

		bool restart =false;
		do
		{
			char choice = NULL;
			cout << "Do you want to [A}dd new content, [O]verwrite, or just [Q]uit?" << endl;
			cin >> choice;
			switch (toupper(choice))
			{
			case 'A':
			{
				cout << "You can now Add contents to the file" << endl;
				filestream.open(argv[1], ios_base::out | ios_base::app);
				string Buffer;
				while (getline(cin, Buffer)) filestream << Buffer << endl;
				filestream.close();
				restart = false;
				break;
			}
			case 'O':
			{
				cout << "You can Overwrite the file:" << endl;
				filestream.open(argv[1], ios_base::out | ios_base::trunc);
				string Buffer;
				while (getline(cin, Buffer)) filestream << Buffer << endl;
				filestream.close();
				restart = false;
				break;
			}
			case 'Q':
			{
				cout << "Nothning happens." << endl;
				restart = false;
				break;
			}
			default:
			{
				cout << "wrong choice." << endl;
				restart = true;
				break;
			}
			}
		} while (restart);

		cout << "Reopening file " << argv[1] << "..." << endl;
		filestream.open(argv[1], ios_base::in);
		cout << "Found File" << argv[1] << ", the file content is:" << endl;
		while (filestream.good())
		{				
			getline(filestream, fileContents);
			cout << fileContents << endl;
		}
		cout << "\nThis is the end of your file." << endl;
		filestream.close();
	}

	else
	{
		filestream.open(argv[1], ios_base::out);
		cout << "No file found, creating new file " << argv[1] << endl;
		filestream << "Hello New file! User content: " << endl;
		cout << "Input your content, end with '^ + z'" << endl;
		string Buffer;
		while (getline(cin, Buffer)) filestream << Buffer << endl;
		cout << "End of your input. Your input is:" << endl;
		filestream.close();
	}
	system("pause");
	return 0;
}