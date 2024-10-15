#include "Header.h"

int Cube::getFaceIndex(char centerColor)
{
	switch (centerColor)
	{
	case 'W': return 0;
	case 'R': return 1;
	case 'Y': return 2;
	case 'O': return 3;
	case 'B': return 4;
	case 'G': return 5;
	default:
		return -1;
	}
}

int Cube::getEdgeIndex(int face, int position)
{
	if (face == 0) {
		return position;
	}
	else if (face == 1)
	{
		return 4 + position;
	}
	else if (face == 2)
	{
		return 8 + position;
	}
	else if (face == 3)
	{
		return 10 + position;
	}
	else
	{
		return -1;
	}
}

int Cube::getCornerIndex(int face, int position) {
	if (face == 0)
	{
		return position;
	}
	else if (face == 1)
	{
		return 4 + position;
	}
	else
	{
		return -1;
	}
}

void Cube::TempRowChange(int face, int row, int way)
{
	for (int i = 0; i < 3; i++)
	{
		if (way == 1)
		{
			temp[i] = cube[face][row][i];
		}
		if (way == 2)
		{
			temp[i] = cube[face][i][row];
		}
	}

}

void Cube::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << cube[4][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int face = 0; face < 4; face++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cube[face][i][j] << " ";
			}
			cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << cube[5][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Cube::FillingTheCube(Cube& cube1)
{
	const char faces[6] = { 'W', 'R', 'Y', 'O', 'B', 'G' };
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cube[i][j][k] = faces[i];
			}
		}
	}
}

void Cube::RightColumnMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[1][i][j];
		}
	}
	cube.TempRowChange(0, 2, 2);

	switch (selectTurn)
	{
	case 1://Up
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][i][2] = cube.cube[5][i][2];
			cube.cube[5][i][2] = cube.cube[2][j][0];
			cube.cube[2][j][0] = cube.cube[4][i][2];
			cube.cube[4][i][2] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[1][i][0] = tempFace[2][i];
			cube.cube[1][i][1] = tempFace[1][i];
			cube.cube[1][i][2] = tempFace[0][i];
		}
		cout << "Action Completed!(Right column up)\n";
		selectTurn = 0;
		break;

	case 2://Down
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][i][2] = cube.cube[4][i][2];
			cube.cube[4][i][2] = cube.cube[2][j][0];
			cube.cube[2][j][0] = cube.cube[5][i][2];
			cube.cube[5][i][2] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[1][0][i] = tempFace[i][2];
			cube.cube[1][1][i] = tempFace[i][1];
			cube.cube[1][2][i] = tempFace[i][0];
		}
		cout << "Action Completed!(Right column down)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::LeftColumnMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[3][i][j];
		}
	}
	cube.TempRowChange(0, 0, 2);

	switch (selectTurn)
	{
	case 1://Up
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][i][0] = cube.cube[5][i][0];
			cube.cube[5][i][0] = cube.cube[2][j][2];
			cube.cube[2][j][2] = cube.cube[4][i][0];
			cube.cube[4][i][0] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[3][0][i] = tempFace[i][2];
			cube.cube[3][1][i] = tempFace[i][1];
			cube.cube[3][2][i] = tempFace[i][0];
		}
		cout << "Action Completed!(Left column up)\n";
		selectTurn = 0;
		break;

	case 2://Down
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][i][0] = cube.cube[4][i][0];
			cube.cube[4][i][0] = cube.cube[2][j][2];
			cube.cube[2][j][2] = cube.cube[5][i][0];
			cube.cube[5][i][0] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[3][i][0] = tempFace[2][i];
			cube.cube[3][i][1] = tempFace[1][i];
			cube.cube[3][i][2] = tempFace[0][i];
		}
		cout << "Action Completed!(left column down)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::HighRowMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[4][i][j];
		}
	}
	cube.TempRowChange(0, 0, 1);

	switch (selectTurn)
	{
	case 1://Clockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][0][i] = cube.cube[1][0][i];
			cube.cube[1][0][i] = cube.cube[2][0][i];
			cube.cube[2][0][i] = cube.cube[3][0][i];
			cube.cube[3][0][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[4][i][0] = tempFace[2][i];
			cube.cube[4][i][1] = tempFace[1][i];
			cube.cube[4][i][2] = tempFace[0][i];
		}
		cout << "Action Completed!(High row clockwise)\n";
		selectTurn = 0;
		break;

	case 2://Counterclockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][0][i] = cube.cube[3][0][i];
			cube.cube[3][0][i] = cube.cube[2][0][i];
			cube.cube[2][0][i] = cube.cube[1][0][i];
			cube.cube[1][0][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[4][0][i] = tempFace[i][2];
			cube.cube[4][1][i] = tempFace[i][1];
			cube.cube[4][2][i] = tempFace[i][0];
		}
		cout << "Action Completed!(High row counterclockwise)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::DownRowMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[5][i][j];
		}
	}
	cube.TempRowChange(0, 2, 1);

	switch (selectTurn)
	{
	case 1://clockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][2][i] = cube.cube[1][2][i];
			cube.cube[1][2][i] = cube.cube[2][2][i];
			cube.cube[2][2][i] = cube.cube[3][2][i];
			cube.cube[3][2][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[5][0][i] = tempFace[i][2];
			cube.cube[5][1][i] = tempFace[i][1];
			cube.cube[5][2][i] = tempFace[i][0];
		}
		cout << "Action Completed!(Down row clockwise)\n";
		selectTurn = 0;
		break;

	case 2://counterclockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[0][2][i] = cube.cube[3][2][i];
			cube.cube[3][2][i] = cube.cube[2][2][i];
			cube.cube[2][2][i] = cube.cube[1][2][i];
			cube.cube[1][2][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[5][i][0] = tempFace[2][i];
			cube.cube[5][i][1] = tempFace[1][i];
			cube.cube[5][i][2] = tempFace[0][i];
		}
		cout << "Action Completed!(Down row counterclockwise)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::FrontFaceMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[0][i][j];
		}
	}
	cube.TempRowChange(1, 0, 2);

	switch (selectTurn)
	{
	case 1://counterclockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[1][i][0] = cube.cube[5][0][j];
			cube.cube[5][0][j] = cube.cube[3][j][2];
			cube.cube[3][j][2] = cube.cube[4][2][i];
			cube.cube[4][2][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[0][0][i] = tempFace[i][2];
			cube.cube[0][1][i] = tempFace[i][1];
			cube.cube[0][2][i] = tempFace[i][0];
		}
		cout << "Action Completed!(Front face counterclockwise)\n";
		selectTurn = 0;
		break;

	case 2://clockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[1][i][0] = cube.cube[4][2][i];
			cube.cube[4][2][i] = cube.cube[3][j][2];
			cube.cube[3][j][2] = cube.cube[5][0][j];
			cube.cube[5][0][j] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[0][i][0] = tempFace[2][i];
			cube.cube[0][i][1] = tempFace[1][i];
			cube.cube[0][i][2] = tempFace[0][i];
		}
		cout << "Action Completed!(Front face clockwise)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::BackFaceMove(Cube& cube, int& selectTurn)
{
	char tempFace[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempFace[i][j] = cube.cube[2][i][j];
		}
	}
	cube.TempRowChange(1, 2, 2);

	switch (selectTurn)
	{
	case 1://counterclockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[1][i][2] = cube.cube[5][2][j];
			cube.cube[5][2][j] = cube.cube[3][j][0];
			cube.cube[3][j][0] = cube.cube[4][0][i];
			cube.cube[4][0][i] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[2][i][0] = tempFace[2][i];
			cube.cube[2][i][1] = tempFace[1][i];
			cube.cube[2][i][2] = tempFace[0][i];

		}
		cout << "Action Completed!(Back face counterclockwise)\n";
		selectTurn = 0;
		break;

	case 2://clockwise
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			cube.cube[1][i][2] = cube.cube[4][0][i];
			cube.cube[4][0][i] = cube.cube[3][j][0];
			cube.cube[3][j][0] = cube.cube[5][2][j];
			cube.cube[5][2][j] = cube.temp[i];
		}

		for (int i = 0; i < 3; i++)
		{
			cube.cube[2][0][i] = tempFace[i][2];
			cube.cube[2][1][i] = tempFace[i][1];
			cube.cube[2][2][i] = tempFace[i][0];

		}
		cout << "Action Completed!(Back face clockwise)\n";
		selectTurn = 0;
		break;

	default:
		cout << "Invalid selection." << endl;
		selectTurn = 0;
		break;
	}
}

void Cube::RandomFilling(Cube& cube)
{
	FillingTheCube(cube);
	int MoveNums = RandomNumber(10, 30);
	cout << "Moves comlited:" << MoveNums << endl;
	cout << "They are:\n";
	for (int i = 0; i < MoveNums; i++)
	{
		int way = RandomNumber(1, 6);
		int way2 = RandomNumber(1, 2);
		switch (way)
		{
		case 1:
		{
			LeftColumnMove(cube, way2);
			break;
		}
		case 2:
		{
			RightColumnMove(cube, way2);
			break;
		}
		case 3:
		{
			HighRowMove(cube, way2);
			break;
		}
		case 4:
		{
			DownRowMove(cube, way2);
			break;
		}
		case 5:
		{
			FrontFaceMove(cube, way2);
			break;
		}
		case 6:
		{
			BackFaceMove(cube, way2);
			break;
		}
		}
	}
}

void Cube::ReadCubeFromFile(const string& filename)
{
	std::ifstream file(filename + ".txt");
	if (!file.is_open())
	{
		cerr << "Error: cannot open the file " << filename << std::endl;
		return;
	}

	string line;
	int face = 0;
	int row = 0;

	while (getline(file, line))
	{
		if (line.empty())
			continue;

		int col = 0;
		for (int i = 0; i < line.size(); i += 2)
		{
			tempmas[face][row][col] = line[i];
			col++;
		}

		row++;
		if (row == 3)
		{
			row = 0;
			face++;
		}

		if (face == 6)
			break;
	}

	file.close();

	transferToCube();
}

void Cube::transferToCube()
{
	for (int i = 0; i < 6; i++)
	{
		char center = tempmas[i][1][1];
		int targetFace = getFaceIndex(center);

		if (targetFace != -1)
		{
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
				{
					cube[targetFace][row][col] = tempmas[i][row][col];
				}
			}
		}
		else
		{
			std::cerr << "Invalid daat\n";
		}
	}

	std::cout << "Cube loaded from the selected file\n";
}

bool Cube::isSolvable() {
	int edgeCount[12] = { 0 };
	int cornerCount[8] = { 0 };
	int colorCount[6] = { 0 };
	const int expectedCount = 9;
	const char colors[6] = { 'W', 'R', 'Y', 'O', 'B', 'G' };


	for (int face = 0; face < 6; ++face)
	{
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				char color = cube[face][row][col];
				int index = getFaceIndex(color);

				if (index != -1)
				{
					colorCount[index]++;
				}
				else
				{
					return false;
				}
			}
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (colorCount[i] != expectedCount)
		{
			return false;
		}
	}

	int edgeOrientationCount = 0;
	int cornerOrientationCount = 0;
	int edgePermutationCount = 0;
	int cornerPermutationCount = 0;

	for (int face = 0; face < 6; ++face)
	{
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				if ((row == 1 || col == 1) && (row != 1 || col != 1))
				{
					char color1 = cube[face][row][col];
					int edgeIndex = getEdgeIndex(face, (row == 1) ? (col == 0 ? 0 : 1) : (row == 0 ? 0 : 1));
					if (color1 != 'W') edgeOrientationCount++;
					edgePermutationCount++;
				}
			}
		}
	}

	for (int face = 0; face < 6; ++face)
	{
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				if (row != 1 && col != 1)
				{
					char color1 = cube[face][row][col];
					int cornerIndex = getCornerIndex(face, (row == 0 && col == 0) ? 0 : (row == 0 && col == 2) ? 1 : (row == 2 && col == 0) ? 2 : 3);
					if (color1 != 'W') cornerOrientationCount++;
					cornerPermutationCount++;
				}
			}
		}
	}

	int totalEdges = edgePermutationCount / 2;
	int totalCorners = cornerPermutationCount / 3;

	int edgeParity = totalEdges % 2;
	int cornerParity = totalCorners % 2;

	int totalParity = (edgeParity + cornerParity) % 2;

	return totalParity == 0;
}

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

