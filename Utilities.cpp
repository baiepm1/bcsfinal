#include <windows.h>  
COORD coord = { 0, 0 };

void gotoxy(int x, int y)         //For Setting the position of Cursor
{
	coord.X = x;
	coord.Y = y;
	SetConsoleTitle("Airport Menu");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
