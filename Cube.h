#include <iostream>
#include <conio.h>
#include <random>
#include <fstream>
#include <string> 

using namespace std;

int RandomNumber(int a, int b);
int add(int a, int b);

class Cube
{
private:
	char cube[6][3][3];
	char temp[3];
	char tempmas[6][3][3];

	int getFaceIndex(char centerColor);

	int getEdgeIndex(int face, int position);

	int getCornerIndex(int face, int position);

public:

	char getFace(int face, int row, int col) const; 

	void TempRowChange(int face, int row, int way);

	void print();

	void FillingTheCube(Cube& cube1);

	void RightColumnMove(Cube& cube, int& selectTurn);

	void LeftColumnMove(Cube& cube, int& selectTurn);

	void HighRowMove(Cube& cube, int& selectTurn);

	void DownRowMove(Cube& cube, int& selectTurn);

	void FrontFaceMove(Cube& cube, int& selectTurn);

	void BackFaceMove(Cube& cube, int& selectTurn);

	void RandomFilling(Cube& cube);

	void ReadCubeFromFile(const string& filename);

	void transferToCube();

	bool isSolvable();

	int countChanges(const Cube& initialState) const; 
};

void MainMenu();

void MoveMenu();

int RandomNumber(int a, int b);
