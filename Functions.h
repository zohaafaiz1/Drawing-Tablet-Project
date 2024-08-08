#pragma once
#include <iostream>
using namespace std;
//-----------------------
//-----------------------
// argument calculators
int numCalc(char input_array[])
{ // calculates the integer number at the end of the [fd, bk, rt, lt and circle] commands
    int i, j;
    int key = -1;
    for (i = 0; (((input_array[i] < '0') || (input_array[i] > '9')) && (input_array[i] != '\0')); i++)
    { // stops at the starting digit of the integer
        if ((input_array[i + 1] >= '0') && (input_array[i + 1] <= '9'))
        {
            key = 1;
        }
    }
    int sum = input_array[i] - 48;
    for (j = i; input_array[j + 1] != '\0' && ((input_array[j + 1] >= '0' && input_array[j + 1] <= '9') || input_array[j + 1] == ' '); j++)
    {
        if (input_array[j + 1] != ' ')
        {
            sum = (sum * 10) + (input_array[j + 1] - 48);
        }
    }
    for (int x = j + 1; input_array[x] != '\0'; x++)
    {
        if (input_array[x] != ' ')
        {
            return -1;
        }
    }
    if (key == 1)
    {
        return sum;
    }
    else
    {
        return key; // returns -1 if user enters an incomplete command
    }
}

int widthCalc(char input_array[])
{ // calculates the integer number at the end of the [fd, bk, rt, lt and circle] commands
    int i;
    int key = -1;
    for (i = 0; (((input_array[i] < '0') || (input_array[i] > '9')) && (input_array[i] != '\0')); i++)
    { // stops at the starting digit of the integer
        if ((input_array[i + 1] >= '0') && (input_array[i + 1] <= '9'))
        {
            key = 1;
        }
    }
    int sum = input_array[i] - 48;
    for (int j = i; input_array[j + 1] != '\0'; j++)
    {
        if (input_array[j + 1] != ' ')
        {
            sum = (sum * 10) + (input_array[j + 1] - 48);
        }
    }
    if (sum != 2 && sum != 5 && sum != 8)
    {
        key = -1;
    }
    if (key == 1)
    {
        return sum;
    }
    else
    {
        return key; // returns -1 if user enters an incomplete command
    }
}

int colorCalc(char input_array[])
{ // calculates the color at the end of the [color] command (0 = wrong input, 1 = RED, 2 = WHITE, 3 = PINK, 4 = PURPLE, 5 = VIOLET, 6 = BLUE, 7 = NEON, 8 = ORANGE, 9 = GREY, 10 = SKY)
    int i;
    int key = -1;
    for (i = 0; (((input_array[i] < 65) || (input_array[i] > 90)) && (input_array[i] != '\0')); i++)
    { // stops at the starting of the uppercase color
        if ((input_array[i + 1] >= 65) && (input_array[i + 1] <= 90))
        {
            key = 1;
        }
    }
    int clr = 0;                                                                         // returns 0 if the command is incorrect
    if (input_array[i] == 'R' && input_array[i + 1] == 'E' && input_array[i + 2] == 'D') // RED
    {
        clr = 1;
    }
    if (input_array[i] == 'W' && input_array[i + 1] == 'H' && input_array[i + 2] == 'I' && input_array[i + 3] == 'T' && input_array[i + 4] == 'E') // WHITE
    {
        clr = 2;
    }
    if (input_array[i] == 'P' && input_array[i + 1] == 'I' && input_array[i + 2] == 'N' && input_array[i + 3] == 'K') // PINK
    {
        clr = 3;
    }
    if (input_array[i] == 'P' && input_array[i + 1] == 'U' && input_array[i + 2] == 'R' && input_array[i + 3] == 'P' && input_array[i + 4] == 'L' && input_array[i + 5] == 'E') // PURPLE
    {
        clr = 4;
    }
    if (input_array[i] == 'V' && input_array[i + 1] == 'I' && input_array[i + 2] == 'O' && input_array[i + 3] == 'L' && input_array[i + 4] == 'E' && input_array[i + 5] == 'T') // VIOLET
    {
        clr = 5;
    }
    if (input_array[i] == 'B' && input_array[i + 1] == 'L' && input_array[i + 2] == 'U' && input_array[i + 3] == 'E') // BLUE
    {
        clr = 6;
    }
    if (input_array[i] == 'N' && input_array[i + 1] == 'E' && input_array[i + 2] == 'O' && input_array[i + 3] == 'N') // NEON
    {
        clr = 7;
    }
    if (input_array[i] == 'O' && input_array[i + 1] == 'R' && input_array[i + 2] == 'A' && input_array[i + 3] == 'N' && input_array[i + 4] == 'G' && input_array[i + 5] == 'E') // ORANGE
    {
        clr = 8;
    }
    if (input_array[i] == 'G' && input_array[i + 1] == 'R' && input_array[i + 2] == 'E' && input_array[i + 3] == 'Y') // GREY
    {
        clr = 9;
    }
    if (input_array[i] == 'S' && input_array[i + 1] == 'K' && input_array[i + 2] == 'Y') // SKY
    {
        clr = 10;
    }

    if (clr == 1 || clr == 10)
        for (int x = i + 3; input_array[x] != '\0'; x++)
        {
            if (input_array[x] != ' ')
            {
                return -1;
            }
        }
    if (clr == 2)
        for (int x = i + 5; input_array[x] != '\0'; x++)
        {
            if (input_array[x] != ' ')
            {
                return -1;
            }
        }
    if (clr == 4 || clr == 5 || clr == 8)
        for (int x = i + 6; input_array[x] != '\0'; x++)
        {
            if (input_array[x] != ' ')
            {
                return -1;
            }
        }
    if (clr == 3 || clr == 6 || clr == 7 || clr == 9)
        for (int x = i + 4; input_array[x] != '\0'; x++)
        {
            if (input_array[x] != ' ')
            {
                return -1;
            }
        }
    if (key == 1)
    {
        return clr;
    }
    else
    {
        return key;
    } // returns -1 if user enters an incomplete command
}

//-----------------------
//-----------------------
// save/load related functions
void fileNameMaker(char arrayDest[], char arraySource[], int commaOneIndex, int commaTwoIndex)
{ // stores the string between the indexes of comma 1 and 2 in a seperate arry to be used as the file creation;
    int x = 0;
    for (int i = commaOneIndex + 1; i < commaTwoIndex; i++)
    {
        arrayDest[x] = arraySource[i];
        x += 1;
    }
    arrayDest[x] = '\0';
}

bool fileNameVerifier(char input_array[], char fileName[])
{ // verifies filename inside double quotations and stores filename in the filename array to be used for ifstream/ofstream declarations
    bool firstBrckt = false;
    bool secondBrckt = false;
    bool spaceCheck = false;
    bool txtCheck = false;
    int i, j;
    for (i = 0; input_array[i] != '"' && input_array[i] != '\0'; i++)
    {
    }
    if (input_array[i] == '"')
    {
        firstBrckt = true;
    }
    if (firstBrckt)
    {
        for (j = i + 1; input_array[j] != '"' && input_array[j] != '\0'; j++)
        {
            if (input_array[j] != ' ' && input_array[j] != '"')
            {
                spaceCheck = true; // true means that the space between the brackets is NOT empty
            }
        }
        if (input_array[j] == '"')
        {
            secondBrckt = true;
        }
    }
    if (firstBrckt && secondBrckt)
    {
        if (input_array[j - 1] == 't' && input_array[j - 2] == 'x' && input_array[j - 3] == 't' && input_array[j - 4] == '.')
        {
            txtCheck = true;
        }
    }
    if (firstBrckt && secondBrckt && (input_array[i + 1] != '"') && spaceCheck && txtCheck)
    {
        fileNameMaker(fileName, input_array, i, j);
        {
            return true;
        }
    }
    else
    {
        return false; // returns -1 if the bracket format is not correct
    }
}

//-----------------------
//-----------------------
// repeat related functions
int repeatLoopCalc(char input_array[])
{ // calculates the integer number at the end of the [fd, bk, rt, lt and circle] commands
    int i;
    int key = -1;
    for (i = 0; (((input_array[i] < '0') || (input_array[i] > '9')) && (input_array[i] != '\0') && (input_array[i] != '[')); i++)
    { // stops at the starting digit of the integer
        if ((input_array[i + 1] >= '0') && (input_array[i + 1] <= '9'))
        {
            key = 1;
        }
    }
    int sum;
    if (key == 1)
    {
        sum = input_array[i] - 48;
        for (int j = i; input_array[j + 1] != '[' && input_array[j + 1] != '\0' && input_array[j + 1] != ']'; j++)
        {
            if (input_array[j + 1] != ' ')
            {
                sum = (sum * 10) + (input_array[j + 1] - 48);
            }
        }
    }
    if (key == 1)
    {
        return sum;
    }
    else
    {
        return key; // returns -1 if user enters an incomplete command (if no loop counter is entered specifically)
    }
}

int repeatBracketIndex(char input_array[])
{
    bool firstBrckt = false;
    bool secondBrckt = false;
    bool spaceCheck = false;
    int i, j;
    for (i = 0; input_array[i] != '[' && input_array[i] != '\0'; i++)
    {
    }
    if (input_array[i] == '[')
    {
        firstBrckt = true;
    }
    if (firstBrckt)
    {
        for (j = i + 1; input_array[j] != ']' && input_array[j] != '\0'; j++)
        {
            if (input_array[j] != ' ' && input_array[j] != ']')
            {
                spaceCheck = true; // true means that the space between the brackets is NOT empty
            }
        }
        if (input_array[j] == ']')
        {
            secondBrckt = true;
        }
    }
    if (firstBrckt && secondBrckt && (input_array[i + 1] != ']') && spaceCheck)
    {
        return i + 1; // returns the starting index of the string inside the array
    }
    else
    {
        return -1; // returns -1 if the bracket format is not correct
    }
}

void arrayShifter(char array_to_shift[], int index)
{ // shifts deletes all the elements in array BEFORE the index and shifts array back until index is at position 0
    int start = 0;
    for (int i = index; array_to_shift[i] != '\0'; i++)
    {
        swap(array_to_shift[start], array_to_shift[i]);
        start += 1;
    }
    array_to_shift[start] = '\0';
}

int functionEndIndex(char input_array[])
{
    int i, j;
    for (i = 0; input_array[i] == ' '; i++)
    {
    }
    for (j = i; input_array[j] >= 97 && input_array[j] <= 122; j++)
    {
    } // ends at the index immediately after the function text stops
    return j;
}

int repeatNumCalc(char input_array[])
{ // calculates the integer number at the end of the [fd, bk, rt, lt and circle] commands within the repeat brackets and shifts array back
    int i, j;
    int key = -1;
    int start = functionEndIndex(input_array);
    for (i = start; (((input_array[i] < '0') || (input_array[i] > '9')) && ((input_array[i] < 97) || (input_array[i] > 122)) && ((input_array[i] < 65) || (input_array[i] > 90)) && (input_array[i] != '\0') && (input_array[i] != ']')); i++)
    { // stops at the starting digit of the integer
        if ((input_array[i + 1] >= '0') && (input_array[i + 1] <= '9'))
        {
            key = 1;
        }
    }
    if (((input_array[i] >= '0') && (input_array[i] <= '9')))
    {
        key = 1;
    }
    int sum = input_array[i] - 48;
    for (j = i; input_array[j + 1] != '\0' && ((input_array[j + 1] < 97) || (input_array[j + 1] > 122)) && ((input_array[j + 1] < 65) || (input_array[j + 1] > 90)) && (input_array[j + 1] != ']'); j++)
    {
        if (input_array[j + 1] != ' ')
        {
            sum = (sum * 10) + (input_array[j + 1] - 48);
        }
    }
    arrayShifter(input_array, j + 1); // shifts array backwards so that the next function keyword is at the start of the array and everything before it gets deleted
    if (key == 1)
    {
        return sum;
    }
    else
    {
        return key;
    } // returns -1 if user enters an incomplete command
}

int repeatColorCalc(char input_array[])
{ // calculates the color at the end of the [color] command (0 = wrong input, 1 = RED, 2 = WHITE, 3 = PINK, 4 = PURPLE, 5 = VIOLET, 6 = BLUE, 7 = NEON, 8 = ORANGE, 9 = GREY, 10 = SKY)
    int i;
    int key = -1;
    int start = functionEndIndex(input_array);
    for (i = start; (((input_array[i] < 65) || (input_array[i] > 90)) && ((input_array[i] < 97) || (input_array[i] > 122)) && (input_array[i] != '\0') && (input_array[i] != ']')); i++)
    { // stops at the starting of the uppercase color
        if ((input_array[i + 1] >= 65) && (input_array[i + 1] <= 90))
        {
            key = 1;
        }
    }
    if ((input_array[i] >= 65) && (input_array[i] <= 90))
    {
        key = 1;
    }

    int clr = 0;       // returns 0 if the command is incorrect
    if (input_array[i] == 'R' && input_array[i + 1] == 'E' && input_array[i + 2] == 'D') // RED
    {
        clr = 1;
    }
    if (input_array[i] == 'W' && input_array[i + 1] == 'H' && input_array[i + 2] == 'I' && input_array[i + 3] == 'T' && input_array[i + 4] == 'E') // WHITE
    {
        clr = 2;
    }
    if (input_array[i] == 'P' && input_array[i + 1] == 'I' && input_array[i + 2] == 'N' && input_array[i + 3] == 'K') // PINK
    {
        clr = 3;
    }
    if (input_array[i] == 'P' && input_array[i + 1] == 'U' && input_array[i + 2] == 'R' && input_array[i + 3] == 'P' && input_array[i + 4] == 'L' && input_array[i + 5] == 'E') // PURPLE
    {
        clr = 4;
    }
    if (input_array[i] == 'V' && input_array[i + 1] == 'I' && input_array[i + 2] == 'O' && input_array[i + 3] == 'L' && input_array[i + 4] == 'E' && input_array[i + 5] == 'T') // VIOLET
    {
        clr = 5;
    }
    if (input_array[i] == 'B' && input_array[i + 1] == 'L' && input_array[i + 2] == 'U' && input_array[i + 3] == 'E') // BLUE
    {
        clr = 6;
    }
    if (input_array[i] == 'N' && input_array[i + 1] == 'E' && input_array[i + 2] == 'O' && input_array[i + 3] == 'N') // NEON
    {
        clr = 7;
    }
    if (input_array[i] == 'O' && input_array[i + 1] == 'R' && input_array[i + 2] == 'A' && input_array[i + 3] == 'N' && input_array[i + 4] == 'G' && input_array[i + 5] == 'E') // ORANGE
    {
        clr = 8;
    }
    if (input_array[i] == 'G' && input_array[i + 1] == 'R' && input_array[i + 2] == 'E' && input_array[i + 3] == 'Y') // GREY
    {
        clr = 9;
    }
    if (input_array[i] == 'S' && input_array[i + 1] == 'K' && input_array[i + 2] == 'Y') // SKY
    {
        clr = 10;
    }

    if (clr == 1 || clr == 10)
    {
        arrayShifter(input_array, i + 3);
    }
    if (clr == 3 || clr == 6 || clr == 7 || clr == 9)
    {
        arrayShifter(input_array, i + 4);
    }
    if (clr == 2)
    {
        arrayShifter(input_array, i + 5);
    }
    if (clr == 4 || clr == 5 || clr == 8)
    {
        arrayShifter(input_array, i + 6);
    }

    int x;
    for (x = 0; input_array[x] == ' '; x++)
    {
    }
    arrayShifter(input_array, x);

    if (key == 1)
    {
        return clr;
    }
    else
    {
        return key;
    }// returns -1 if user enters an incomplete command
}

void twoCharFuncShifter(char input_array[])
{
    int i, j;
    for (i = 0; input_array[i] == ' '; i++)
    {
    }
    int firstIndexAfterFunc = i + 2;
    for (j = firstIndexAfterFunc; input_array[j] == ' '; j++)
    {
    }
    arrayShifter(input_array, j);
}

//-----------------------
//-----------------------
// function checkers
bool fdChecker(char input_array[])
{ // returns true if the inputted function is 'fd', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the fd
    bool ans = false;
    if ((input_array[i] == 'f' && input_array[i + 1] == 'd') || (input_array[i] == 'f' && input_array[i + 1] == 'o' && input_array[i + 2] == 'r' && input_array[i + 3] == 'w' && input_array[i + 4] == 'a' && input_array[i + 5] == 'r' && input_array[i + 6] == 'd'))
    {
        ans = true;
    }
    return ans;
}

bool bkChecker(char input_array[])
{ // returns true if the inputted function is 'bk', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the bk
    bool ans = false;
    if ((input_array[i] == 'b' && input_array[i + 1] == 'k') || (input_array[i] == 'b' && input_array[i + 1] == 'a' && input_array[i + 2] == 'c' && input_array[i + 3] == 'k' && input_array[i + 4] == 'w' && input_array[i + 5] == 'a' && input_array[i + 6] == 'r' && input_array[i + 7] == 'd'))
    {
        ans = true;
    }
    return ans;
}

bool rtChecker(char input_array[])
{ // returns true if the inputted function is 'rt', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the rt
    bool ans = false;
    if (input_array[i] == 'r' && input_array[i + 1] == 't')
    {
        ans = true;
    }
    return ans;
}

bool ltChecker(char input_array[])
{ // returns true if the inputted function is 'lt', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the lt
    bool ans = false;
    if (input_array[i] == 'l' && input_array[i + 1] == 't')
    {
        ans = true;
    }
    return ans;
}

bool circleChecker(char input_array[])
{ // returns true if the inputted function is 'circle', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the circle
    bool ans = false;
    if (input_array[i] == 'c' && input_array[i + 1] == 'i' && input_array[i + 2] == 'r' && input_array[i + 3] == 'c' && input_array[i + 4] == 'l' && input_array[i + 5] == 'e')
    {
        ans = true;
    }
    return ans;
}

bool puChecker(char input_array[])
{ // returns true if the inputted function is 'pu', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the pu
    bool ans = false;
    if (input_array[i] == 'p' && input_array[i + 1] == 'u')
    {
        ans = true;
    }
    return ans;
}

bool pdChecker(char input_array[])
{ // returns true if the input function is 'pd', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the pd
    bool ans = false;
    if (input_array[i] == 'p' && input_array[i + 1] == 'd')
    {
        ans = true;
    }
    return ans;
}

bool widthChecker(char input_array[])
{ // returns true if the input function is 'width', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the width
    bool ans = false;
    if ((input_array[i] == 'w' && input_array[i + 1] == 'i' && input_array[i + 2] == 'd' && input_array[i + 3] == 't' && input_array[i + 4] == 'h') || (input_array[i] == 'W' && input_array[i + 1] == 'I' && input_array[i + 2] == 'D' && input_array[i + 3] == 'T' && input_array[i + 4] == 'H'))
    {
        ans = true;
    }
    return ans;
}

bool colorChecker(char input_array[])
{ // returns true if the input function is 'color', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the color
    bool ans = false;
    if (input_array[i] == 'c' && input_array[i + 1] == 'o' && input_array[i + 2] == 'l' && input_array[i + 3] == 'o' && input_array[i + 4] == 'r')
    {
        ans = true;
    }
    return ans;
}

bool csChecker(char input_array[])
{ // returns true if the input function is 'cs', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the cs
    bool ans = false;
    if (input_array[i] == 'c' && input_array[i + 1] == 's')
    {
        ans = true;
    }
    return ans;
}

bool repeatChecker(char input_array[])
{ // returns true if the input function is 'repeat', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the repeat
    bool ans = false;
    if (input_array[i] == 'r' && input_array[i + 1] == 'e' && input_array[i + 2] == 'p' && input_array[i + 3] == 'e' && input_array[i + 4] == 'a' && input_array[i + 5] == 't')
    {
        ans = true;
    }
    return ans;
}

bool saveChecker(char input_array[])
{ // returns true if the input function is 'repeat', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the repeat
    bool ans = false;
    if (input_array[i] == 's' && input_array[i + 1] == 'a' && input_array[i + 2] == 'v' && input_array[i + 3] == 'e')
    {
        ans = true;
    }
    return ans;
}

bool loadChecker(char input_array[])
{ // returns true if the input function is 'repeat', returns false otherwise.
    int i;
    for (i = 0; input_array[i] == ' '; i++)
    {
    } // checks for spaces before the repeat
    bool ans = false;
    if (input_array[i] == 'l' && input_array[i + 1] == 'o' && input_array[i + 2] == 'a' && input_array[i + 3] == 'd')
    {
        ans = true;
    }
    return ans;
}

//-----------------------
//-----------------------
// misc functions needed for megafunction calcs
float xIncrementFinder(int angle)
{
    float x = -1;
    if (angle == 30 || angle == 150)
    {
        x = 0.5;
    }
    if (angle == 210 || angle == 330)
    {
        x = -0.5;
    }
    if (angle == 60 || angle == 120 || angle == 90 || angle == 45 || angle == 135 || angle == 75 || angle == 105)
    {
        x = 1;
    }
    if (angle == 240 || angle == 300 || angle == 225 || angle == 315 || angle == 270 || angle == 255 || angle == 285)
    {
        x = -1;
    }
    if (angle == 0 || angle == 180)
    {
        x = 0;
    }
    if (angle == 15 || angle == 165)
    {
        x = 0.25;
    }
    if (angle == 195 || angle == 345)
    {
        x = -0.25;
    }
    return x;
}

float yIncrementFinder(int angle)
{
    float y = -1;
    if (angle == 120 || angle == 240)
    {
        y = 0.5;
    }
    if (angle == 60 || angle == 300)
    {
        y = -0.5;
    }
    if (angle == 150 || angle == 210 || angle == 180 || angle == 135 || angle == 225 || angle == 165 || angle == 195)
    {
        y = 1;
    }
    if (angle == 30 || angle == 330 || angle == 0 || angle == 45 || angle == 315 || angle == 15 || angle == 345)
    {
        y = -1;
    }
    if (angle == 90 || angle == 270)
    {
        y = 0;
    }
    if (angle == 105 || angle == 255)
    {
        y = 0.25;
    }
    if (angle == 75 || angle == 285)
    {
        y = -0.25;
    }
    return y;
}

int argumentUpdater(int arg, int ang)
{ // argument and angle, use this to find the limit for running the loop to get the new coordinates for the lines
    int updatedArg = 0;
    if (ang == 0 || ang == 90 || ang == 180 || ang == 270)
    {
        updatedArg = arg;
    }
    else if (ang == 45 || ang == 135 || ang == 225 || ang == 315)
    {
        updatedArg = arg - (arg / 3);
    }
    else if (ang == 30 || ang == 60 || ang == 120 || ang == 150 || ang == 210 || ang == 240 || ang == 300 || ang == 330)
    {
        updatedArg = (arg - (arg / 10)) - (arg / 20);
    }
    else
    {
        updatedArg = arg - ((arg / 10) / 2);
    }
    return updatedArg;
}

int angleIncrCalc(int angleArg)
{
    int ans = 0;
    if (angleArg % 30 == 0 || angleArg % 45 == 0)
    {
        if (angleArg >= 360)
        {
            while (angleArg >= 360)
            {
                angleArg -= 360;
            }
        }
        ans = angleArg;
    }
    return ans;
}

void lineskip(int lines, int tabs)
{
    for (int i = 0; i <= lines; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < tabs; i++)
    {
        cout << "\t";
    }
}
//-----------------------
//-----------------------
// mega functions
int functionIDfinder(char findID[])
{
    int ID = -1;
    if (fdChecker(findID))
    {
        ID = 1;
    }
    if (bkChecker(findID))
    {
        ID = 2;
    }
    if (rtChecker(findID))
    {
        ID = 3;
    }
    if (ltChecker(findID))
    {
        ID = 4;
    }
    if (circleChecker(findID))
    {
        ID = 5;
    }
    if (widthChecker(findID))
    {
        ID = 6;
    }
    if (colorChecker(findID))
    {
        ID = 7;
    }
    if (puChecker(findID))
    {
        ID = 8;
    }
    if (pdChecker(findID))
    {
        ID = 9;
    }
    if (csChecker(findID))
    {
        ID = 10;
    }
    if (repeatChecker(findID))
    {
        ID = 11;
    }
    if (saveChecker(findID))
    {
        ID = 12;
    }
    if (loadChecker(findID))
    {
        ID = 13;
    }
    return ID;
}

int repeatArgumentSorter(char repeatArgString[], int repeatFunctions[], int repeatArguments[])
{
    int x = repeatBracketIndex(repeatArgString);
    if (x == -1)
    {
        return -1; // returns -1 if bracket index is wrong
    }
    arrayShifter(repeatArgString, x);
    int funcID;
    int arg = 0;
    int index = 0;
    while (repeatArgString[0] != ']')
    {
        funcID = functionIDfinder(repeatArgString);
        if (funcID >= 1 && funcID <= 6)
        {
            arg = repeatNumCalc(repeatArgString);
        }
        if (funcID == 7)
        {
            arg = repeatColorCalc(repeatArgString);
        }
        if (funcID >= 8 && funcID <= 10)
        {
            twoCharFuncShifter(repeatArgString);
            arg = 0;
        }
        if (funcID == 11 || funcID == 12 || funcID == 13)
        {
            funcID = -1;
        }
        // cout << funcID << ", " << arg << endl;
        repeatFunctions[index] = funcID;
        repeatArguments[index] = arg;
        index += 1;
        if (arg == -1 || funcID == -1)
        {
            return -1; // returns -1 if any wrong function or argument is encountered within the brackets
        }
    }
    return index; // if no errors are encountered within the brackets the functions retruns the index up to which the functions and their arguments are stored
}

void forward(int& xOrigin, int& yOrigin, int argument, int angle, bool draw, int& lineIndex, int lineX1[], int lineY1[], int lineX2[], int lineY2[], int lineRed[], int lineGreen[], int lineBlue[], int lineW[], int r, int g, int b, int w)
{
    int limit = argumentUpdater(argument, angle); // updates limit depending on angle
    float xIncr = xIncrementFinder(angle);
    float yIncr = yIncrementFinder(angle);
    if (draw)
    {
        lineX1[lineIndex] = xOrigin;
        lineY1[lineIndex] = yOrigin;
        lineRed[lineIndex] = r;
        lineGreen[lineIndex] = g;
        lineBlue[lineIndex] = b;
        lineW[lineIndex] = w;
    }
    float tempxOrg = xOrigin;
    float tempyOrg = yOrigin;
    for (int i = 0; i <= limit; i++)
    {
        tempxOrg += xIncr;
        tempyOrg += yIncr;
    }
    xOrigin = tempxOrg;
    yOrigin = tempyOrg;
    if (draw)
    {
        lineX2[lineIndex] = xOrigin;
        lineY2[lineIndex] = yOrigin;
        lineIndex += 1;
    }
}

void backward(int& BxOrigin, int& ByOrigin, int Bargument, int Bangle, bool Bdraw, int& BlineIndex, int BlineX1[], int BlineY1[], int BlineX2[], int BlineY2[], int BlineRed[], int BlineGreen[], int BlineBlue[], int BlineW[], int Br, int Bg, int Bb, int Bw)
{
    int newAngle = 0;
    if (Bangle >= 0 && Bangle <= 179)
    {
        newAngle = Bangle + 180;
    }
    else if (Bangle >= 180 && Bangle <= 359)
        newAngle = Bangle - 180;
    forward(BxOrigin, ByOrigin, Bargument, newAngle, Bdraw, BlineIndex, BlineX1, BlineY1, BlineX2, BlineY2, BlineRed, BlineGreen, BlineBlue, BlineW, Br, Bg, Bb, Bw);
}

void rightTurn(int& angle, int angleArgument)
{ // remember to add a paremeter that lets the program know whether an invalid angle was entered or not
    angleArgument = angleIncrCalc(angleArgument);
    angle += angleArgument;
    if (angle >= 360)
    {
        angle -= 360;
    }
}

void leftTurn(int& angle, int angleArgument)
{ // remember to add a paremeter that lets the program know whether an invalid angle was entered or not
    angleArgument = angleIncrCalc(angleArgument);
    angle -= angleArgument;
    if (angle < 0)
    {
        angle += 360;
    }
}

void circle(int xCoord, int yCoord, int radiusArg, int& circle_index, bool draw, int X1[], int Y1[], int X2[], int Y2[], int circleRed[], int circleGreen[], int circleBlue[], int circleWidth[], int Cr, int Cg, int Cb, int Cw)
{
    if (draw)
    {
        X1[circle_index] = xCoord - radiusArg;
        Y1[circle_index] = yCoord - radiusArg;
        X2[circle_index] = xCoord + radiusArg;
        Y2[circle_index] = yCoord + radiusArg;
        circleRed[circle_index] = Cr;
        circleGreen[circle_index] = Cg;
        circleBlue[circle_index] = Cb;
        circleWidth[circle_index] = Cw;
        circle_index += 1;
    }
}

void penUp(bool& draw)
{
    draw = false;
}

void penDown(bool& draw)
{
    draw = true;
}

void width(int& wid, int arg)
{
    if (arg == 2 || arg == 5 || arg == 8)
    {
        wid = arg;
    }
}

void clearScreen(int LX1[], int LY1[], int LX2[], int LY2[], int CX1[], int CY1[], int CX2[], int CY2[], int& Lindx, int& Cindx, int LR[], int LG[], int LB[], int LW[], int CR[], int CG[], int CB[], int CW[], int& cursorx, int& cursory, int& angle)
{
    for (int i = 0; i < Lindx; i++)
    {
        LX1[i] = 0;
        LX2[i] = 0;
        LY1[i] = 0;
        LY2[i] = 0;
        LR[i] = 0;
        LG[i] = 0;
        LB[i] = 0;
        LW[i] = 0;
    }
    for (int i = 0; i < Cindx; i++)
    {
        CX1[i] = 0;
        CX2[i] = 0;
        CY1[i] = 0;
        CY2[i] = 0;
        CR[i] = 0;
        CG[i] = 0;
        CB[i] = 0;
        CW[i] = 0;
    }
    cursorx = 650;
    cursory = 350;
    angle = 0;
    Lindx = 0;
    Cindx = 0;
}
void color(int col_id, int& R, int& G, int& B)
{
    if (col_id == 1)
    {
        R = 255;
        B = 0;
        G = 0;
    }
    if (col_id == 2)
    {
        R = 255;
        B = 255;
        G = 255;
    }
    if (col_id == 3)
    {
        R = 255;
        B = 201;
        G = 174;
    }
    if (col_id == 4)
    {
        R = 163;
        B = 164;
        G = 73;
    }
    if (col_id == 5)
    {
        R = 200;
        B = 231;
        G = 191;
    }
    if (col_id == 6)
    {
        R = 0;
        B = 255;
        G = 0;
    }
    if (col_id == 7)
    {
        R = 181;
        B = 29;
        G = 230;
    }
    if (col_id == 8)
    {
        R = 255;
        B = 39;
        G = 127;
    }
    if (col_id == 9)
    {
        R = 127;
        B = 127;
        G = 127;
    }
    if (col_id == 10)
    {
        R = 153;
        B = 217;
        G = 234;
    }
}

void functionExecuter(int megaFunctionID, int megaArgument, int& megaAngle, bool& megaDraw, int& megaWidth, int& megaRed, int& megaGreen, int& megaBlue, int& megaLineIndex, int& megaCircIndex, int& megaXcoord, int& megaYcoord, int megaLX1[], int megaLY1[], int megaLX2[], int megaLY2[], int megaLR[], int megaLG[], int megaLB[], int megaLW[], int megaCX1[], int megaCY1[], int megaCX2[], int megaCY2[], int megaCR[], int megaCG[], int megaCB[], int megaCW[])
{
    if (megaFunctionID == 1)
    {
        forward(megaXcoord, megaYcoord, megaArgument, megaAngle, megaDraw, megaLineIndex, megaLX1, megaLY1, megaLX2, megaLY2, megaLR, megaLG, megaLB, megaLW, megaRed, megaGreen, megaBlue, megaWidth);
    }
    if (megaFunctionID == 2)
    {
        backward(megaXcoord, megaYcoord, megaArgument, megaAngle, megaDraw, megaLineIndex, megaLX1, megaLY1, megaLX2, megaLY2, megaLR, megaLG, megaLB, megaLW, megaRed, megaGreen, megaBlue, megaWidth);
    }
    if (megaFunctionID == 3)
    {
        rightTurn(megaAngle, megaArgument);
    }
    if (megaFunctionID == 4)
    {
        leftTurn(megaAngle, megaArgument);
    }
    if (megaFunctionID == 5)
    {
        circle(megaXcoord, megaYcoord, megaArgument, megaCircIndex, megaDraw, megaCX1, megaCY1, megaCX2, megaCY2, megaCR, megaCG, megaCB, megaCW, megaRed, megaGreen, megaBlue, megaWidth);
    }
    if (megaFunctionID == 6)
    {
        width(megaWidth, megaArgument);
    }
    if (megaFunctionID == 7)
    {
        color(megaArgument, megaRed, megaGreen, megaBlue);
    }
    if (megaFunctionID == 8)
    {
        penUp(megaDraw);
    }
    if (megaFunctionID == 9)
    {
        penDown(megaDraw);
    }
    if (megaFunctionID == 10)
    {
        clearScreen(megaLX1, megaLY1, megaLX2, megaLY2, megaCX1, megaCY1, megaCX2, megaCY2, megaLineIndex, megaCircIndex, megaLR, megaLG, megaLB, megaLW, megaCR, megaCG, megaCB, megaCW, megaXcoord, megaYcoord, megaAngle);
    }
}