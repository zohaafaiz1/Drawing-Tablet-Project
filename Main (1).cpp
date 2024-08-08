#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include "Draw.h"
#include "Functions.h"
using namespace std;

//-----------------------
//-----------------------
// main test function
int main()
{
	char name[100];
	char instructionStorage[900][100];
	char fileNameDeclarer[50];
	int instructionIndex = -1;

	float cursorXinc, cursorYinc;
	float cursorNewX, cursorNewY;
	int IcursorNewX, IcursorNewY;

	int pointerX = 650;
	int pointerY = 350;
	int FUNCTION_ID = 0;
	int ARGUMENT = 100;
	int ANGLE = 0;
	bool DRAW = true;

	int WIDTH = 2;

	int RED = 255;
	int GREEN = 255;
	int BLUE = 255;

	int LINE_INDEX = 0;
	int lineX1[900] = {};
	int lineY1[900] = {};
	int lineX2[900] = {};
	int lineY2[900] = {};
	int lineR[900] = {};
	int lineB[900] = {};
	int lineG[900] = {};
	int lineWidth[900] = {};

	int CIRC_INDEX = 0;
	int circX1[900] = {};
	int circY1[900] = {};
	int circX2[900] = {};
	int circY2[900] = {};
	int circR[900] = {};
	int circG[900] = {};
	int circB[900] = {};
	int circleWidth[900] = {};

	int REPEAT_FUNC[100] = {};
	int REPEAT_ARGS[100] = {};
	char temp_storage[100];
	int repeatNumberOfCommands;

	bool invalid = false;
	bool incomplete = false;

	// cout << "Welcome to paint...";
	// system("cls");

	while (true)
	{
		ARGUMENT = 0;
		repeatNumberOfCommands = 0;

		for (int i = 0; i < CIRC_INDEX; i++)
		{
			myEllipse(circX1[i], circY1[i], circX2[i], circY2[i], circR[i], circG[i], circB[i], circleWidth[i]);
		}
		for (int i = 0; i < LINE_INDEX; i++)
		{
			myLine(lineX1[i], lineY1[i], lineX2[i], lineY2[i], lineR[i], lineG[i], lineB[i], lineWidth[i]);
		}
		if (DRAW)
		{
			cursorNewX = pointerX;
			cursorNewY = pointerY;
			int L = 20;
			cursorXinc = xIncrementFinder(ANGLE);
			cursorYinc = yIncrementFinder(ANGLE);
			if (ANGLE % 45 == 0 && ANGLE % 90 != 0)
			{
				L = 15;
			}
			for (int i = 0; i < L; i++)
			{
				cursorNewX += cursorXinc;
				cursorNewY += cursorYinc;
			}
			IcursorNewX = cursorNewX;
			IcursorNewY = cursorNewY;
			myLine(pointerX, pointerY, IcursorNewX, IcursorNewY, 234, 63, 247, 2);
		}
		myEllipse(pointerX - 10, pointerY - 10, pointerX + 10, pointerY + 10, 234, 63, 247, 2);

		myLine(220, 503, 220, 645, 255, 255, 255, 2);
		// command history
		lineskip(19, 0);
		cout << "___________________";
		lineskip(0, 0);
		if (instructionIndex >= 0 && !repeatChecker(instructionStorage[instructionIndex]))
		{
			cout << instructionStorage[instructionIndex];
		}
		else if (instructionIndex >= 0 && repeatChecker(instructionStorage[instructionIndex]))
			cout << "repeat " << repeatLoopCalc(instructionStorage[instructionIndex]) << "[...]";

		lineskip(0, 0);
		if (instructionIndex >= 1 && !repeatChecker(instructionStorage[instructionIndex - 1]))
		{
			cout << instructionStorage[instructionIndex - 1];
		}
		else if (instructionIndex >= 1 && repeatChecker(instructionStorage[instructionIndex - 1]))
			cout << "repeat " << repeatLoopCalc(instructionStorage[instructionIndex - 1]) << "[...]";

		lineskip(0, 0);
		if (instructionIndex >= 2 && !repeatChecker(instructionStorage[instructionIndex - 2]))
		{
			cout << instructionStorage[instructionIndex - 2];
		}
		else if (instructionIndex >= 2 && repeatChecker(instructionStorage[instructionIndex - 2]))
			cout << "repeat " << repeatLoopCalc(instructionStorage[instructionIndex - 2]) << "[...]";

		lineskip(0, 0);
		if (instructionIndex >= 3 && !repeatChecker(instructionStorage[instructionIndex - 3]))
		{
			cout << instructionStorage[instructionIndex - 3];
		}
		else if (instructionIndex >= 3 && repeatChecker(instructionStorage[instructionIndex - 3]))
			cout << "repeat " << repeatLoopCalc(instructionStorage[instructionIndex - 3]) << "[...]";

		lineskip(0, 0);
		if (instructionIndex >= 4 && !repeatChecker(instructionStorage[instructionIndex - 4]))
		{
			cout << instructionStorage[instructionIndex - 4];
		}
		else if (instructionIndex >= 4 && repeatChecker(instructionStorage[instructionIndex - 4]))
		{
			cout << "repeat " << repeatLoopCalc(instructionStorage[instructionIndex - 4]) << "[...]";
		}

		lineskip(0, 0);
		cout << "___________________";
		myLine(232, 646, 1315, 646, 255, 255, 255, 2);

		// command input
		lineskip(0, 0);
		if (invalid)
		{
			cout << "Invalid input: ";
			invalid = false;
		}
		else if (incomplete)
		{
			cout << "Incomplete input: ";
			incomplete = false;
		}
		else
		{
			cout << "Enter Command: ";
		}

		cin.getline(name, 100);

		// functionID input
		FUNCTION_ID = functionIDfinder(name);
		if (FUNCTION_ID >= 1 && FUNCTION_ID <= 5)
		{
			ARGUMENT = numCalc(name);
		}
		else if (FUNCTION_ID == 6)
		{
			ARGUMENT = widthCalc(name);
		}
		else if (FUNCTION_ID == 7)
		{
			ARGUMENT = colorCalc(name);
		}
		else if (FUNCTION_ID == 11)
		{
			ARGUMENT = repeatLoopCalc(name); // stores the loop number for repeat in ARGUMENT, stores -1 if there is no repeat number
			strcpy_s(temp_storage, name);
			repeatNumberOfCommands = repeatArgumentSorter(temp_storage, REPEAT_FUNC, REPEAT_ARGS); //-1 if content inside the brackets is wrong
		}

		if (FUNCTION_ID == -1)
		{
			invalid = true;
		}
		if (ARGUMENT == -1)
		{
			incomplete = true;
		}
		if (repeatNumberOfCommands == -1)
		{
			invalid = true;
		}
		if ((FUNCTION_ID == 3 || FUNCTION_ID == 4) && (ARGUMENT % 30 != 0 && ARGUMENT % 45 != 0))
		{
			invalid = true;
		}
		// command execution for everything other than repeat, save and lod
		if (!invalid && !incomplete && FUNCTION_ID < 11)
		{
			functionExecuter(FUNCTION_ID, ARGUMENT, ANGLE, DRAW, WIDTH, RED, GREEN, BLUE, LINE_INDEX, CIRC_INDEX, pointerX, pointerY, lineX1, lineY1, lineX2, lineY2, lineR, lineG, lineB, lineWidth, circX1, circY1, circX2, circY2, circR, circG, circB, circleWidth);
			if (instructionIndex < 299)
			{
				instructionIndex += 1;
			}
			strcpy_s(instructionStorage[instructionIndex], name);
		}
		// command execution for repeat
		if (!invalid && !incomplete && FUNCTION_ID == 11)
		{
			if (instructionIndex < 299)
			{
				instructionIndex += 1;
			}
			strcpy_s(instructionStorage[instructionIndex], name);
			for (int i = 0; i < ARGUMENT; i++)
			{
				for (int j = 0; j < repeatNumberOfCommands; j++)
				{
					functionExecuter(REPEAT_FUNC[j], REPEAT_ARGS[j], ANGLE, DRAW, WIDTH, RED, GREEN, BLUE, LINE_INDEX, CIRC_INDEX, pointerX, pointerY, lineX1, lineY1, lineX2, lineY2, lineR, lineG, lineB, lineWidth, circX1, circY1, circX2, circY2, circR, circG, circB, circleWidth);
				}
			}
		}
		// command execution for save :)
		if (FUNCTION_ID == 12)
		{
			if (fileNameVerifier(name, fileNameDeclarer))
			{
				ofstream fout(fileNameDeclarer);
				if (fout.is_open())
				{
					int start = 0;
					if (instructionIndex > 99)
					{
						start = instructionIndex - 100;
					}
					for (int i = start; i <= instructionIndex; i++)
					{
						fout << instructionStorage[i] << endl;
					}
				}
			}
			else
			{
				invalid = true;
			}
		}

		// command execution for load :o
		if (FUNCTION_ID == 13)
		{
			if (fileNameVerifier(name, fileNameDeclarer))
			{
				ifstream fin(fileNameDeclarer);
				if (fin.is_open())
				{
					ANGLE = 0;
					WIDTH = 2;
					RED = 255;
					GREEN = 255;
					BLUE = 255;
					while (fin.getline(name, 100))
					{
						ARGUMENT = 0;
						repeatNumberOfCommands = 0;

						// functionID input
						FUNCTION_ID = functionIDfinder(name);
						if (FUNCTION_ID >= 1 && FUNCTION_ID <= 5)
						{
							ARGUMENT = numCalc(name);
						}
						else if (FUNCTION_ID == 6)
						{
							ARGUMENT = widthCalc(name);
						}
						else if (FUNCTION_ID == 7)
						{
							ARGUMENT = colorCalc(name);
						}
						else if (FUNCTION_ID == 11)
						{
							ARGUMENT = repeatLoopCalc(name); // stores the loop number for repeat in ARGUMENT, stores -1 if there is no repeat number
							strcpy_s(temp_storage, name);
							repeatNumberOfCommands = repeatArgumentSorter(temp_storage, REPEAT_FUNC, REPEAT_ARGS); //-1 if content inside the brackets is wrong
						}

						if (FUNCTION_ID == -1)
						{
							invalid = true;
						}
						if (ARGUMENT == -1)
						{
							incomplete = true;
						}
						if (repeatNumberOfCommands == -1)
						{
							invalid = true;
						}
						// command execution for everything other than repeat, save and lod
						if (!invalid && !incomplete && FUNCTION_ID < 11)
						{
							functionExecuter(FUNCTION_ID, ARGUMENT, ANGLE, DRAW, WIDTH, RED, GREEN, BLUE, LINE_INDEX, CIRC_INDEX, pointerX, pointerY, lineX1, lineY1, lineX2, lineY2, lineR, lineG, lineB, lineWidth, circX1, circY1, circX2, circY2, circR, circG, circB, circleWidth);
						}
						// command execution for repeat
						if (!invalid && !incomplete && FUNCTION_ID == 11)
						{
							for (int i = 0; i < ARGUMENT; i++)
							{
								for (int j = 0; j < repeatNumberOfCommands; j++)
								{
									functionExecuter(REPEAT_FUNC[j], REPEAT_ARGS[j], ANGLE, DRAW, WIDTH, RED, GREEN, BLUE, LINE_INDEX, CIRC_INDEX, pointerX, pointerY, lineX1, lineY1, lineX2, lineY2, lineR, lineG, lineB, lineWidth, circX1, circY1, circX2, circY2, circR, circG, circB, circleWidth);
								}
							}
						}
					}
				}
				else
				{
					invalid = true;
				}
			}
			else
			{
				invalid = true;
			}
		}
		system("cls");
	}
	return 0;
}