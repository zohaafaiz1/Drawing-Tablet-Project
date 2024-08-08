#pragma once
#include <windows.h>
//-----------------------
//-----------------------
// modified drawing functions
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void myLine(int x1, int y1, int x2, int y2, int red, int green, int blue, int penWidth) // use three 3 integers if you want colored lines.
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
    HPEN pen = CreatePen(PS_SOLID, penWidth, RGB(red, green, blue)); // 2 is the width of the pen
    SelectObject(device_context, pen);
    MoveToEx(device_context, x1, y1, NULL);
    LineTo(device_context, x2, y2);
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
}

void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int W)
{
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    // change the color by changing the values in RGB (from 0-255)
    HPEN pen = CreatePen(PS_SOLID, W, RGB(R, G, B));
    SelectObject(device_context, pen);
    // HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));  //Fill color is black
    HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
    SelectObject(device_context, brush);
    Ellipse(device_context, x1, y1, x2, y2);
    ReleaseDC(console_handle, device_context);
    DeleteObject(pen);
    DeleteObject(brush);
}
