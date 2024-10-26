#include "Cube.h"


int main()
{
	Cube myCube;
	int selectTurn;
	while (true)
	{
		MainMenu();
		switch (_getch())
		{
		case '1':
		{
			myCube.FillingTheCube(myCube);
			cout << "Cube was created!\n";
			break;
		}
		case '2':
		{
			myCube.RandomFilling(myCube);
			break;
		}
		case '3':
		{
			string filename;
			cout << "Enter the file name:\n";
			cin >> filename;
			myCube.ReadCubeFromFile(filename);
			break;
		}
		case '4':
		{
			if (myCube.isSolvable() == true)
			{
				cout << "Cube can be assembled\n";
			}
			else
			{
				cout << "Cube can't be assembled\n";
			}
			break;
		}
		case '5':
		{
			cout << "\tYour cube:\n";
			myCube.print();
			break;
		}
		case '6':
		{
			MoveMenu();
			switch (_getch())
			{
			case '1':
			{
				cout << "Select:" << endl << "1-UP" << endl << "2-DOWN" << endl;
				cin >> selectTurn;
				myCube.LeftColumnMove(myCube, selectTurn);
				break;
			}
			case '2':
			{
				cout << "Select:" << endl << "1-UP" << endl << "2-DOWN" << endl;
				cin >> selectTurn;
				myCube.RightColumnMove(myCube, selectTurn);
				break;
			}
			case '3':
			{
				cout << "Select:" << endl << "1-Clockwise" << endl << "2-Counterclockwise" << endl;
				cin >> selectTurn;
				myCube.HighRowMove(myCube, selectTurn);
				break;
			}
			case '4':
			{
				cout << "Select:" << endl << "1-Clockwise" << endl << "2-Counterclockwise" << endl;
				cin >> selectTurn;
				myCube.DownRowMove(myCube, selectTurn);
				break;
			}
			case '5':
			{
				cout << "Select:" << endl << "1-Counterclockwise" << endl << "2-Clockwise" << endl;
				cin >> selectTurn;
				myCube.FrontFaceMove(myCube, selectTurn);
				break;
			}
			case '6':
			{
				cout << "Select:" << endl << "1-Counterclockwise" << endl << "2-Clockwise" << endl;
				cin >> selectTurn;
				myCube.BackFaceMove(myCube, selectTurn);
				break;
			}
			default:
			{
				cout << "Invalid choise" << endl;
				break;
			}
			}
			break;
		}
		case '7':
		{
			cout << "Press any button to close the program\n";
			exit(0);
		}
		default:
		{
			cout << "Invalid choise" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
}
