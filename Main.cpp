#include "Cube.h"

void MainMenu()
{
	cout << "\n\tMenu:\n";
	cout << "Enter 1 to create normal cube\n";
	cout << "Enter 2 to create random cube\n";
	cout << "Enter 3 to create cube from file data\n";
	cout << "Enter 4 to check the cube\n";
	cout << "Enter 5 to see the cube\n";
	cout << "Enter 6 to move faces\n";
	cout << "Enter 7 to quit\n\n";
}

void MoveMenu()
{
	cout << "Enter 1 to move left column" << endl;
	cout << "Enter 2 to move right column" << endl;
	cout << "Enter 3 to move high row" << endl;
	cout << "Enter 4 to move down row" << endl;
	cout << "Enter 5 to move front face" << endl;
	cout << "Enter 6 to move back face" << endl;
}

int RandomNumber(int a, int b)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(a, b);
	int number = distribution(generator);
	return number;
}

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
