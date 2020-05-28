#include"Sysframe.h"




void SetCurPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { y, x };
	SetConsoleCursorPosition(handle, pos);
}
void DrawRow(int x, int y)
{
	for (int i = 0; i < WIDTH - 4; ++i)
	{
		SetCurPos(x, y + i);
		printf("=");
	}
}
void DrawCol(int x, int y)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		SetCurPos(i, y);
		printf("||");
	}
}
void DrawFrame(char* title)
{
	//设置标题
	char buffer[MAX_TITLE_SIZE + 5 + 1 + 1] = "title ";
	strcat(buffer, title);
	system(buffer);

	//设置宽度 高度
	char mode[128] = { 0 };
	sprintf(mode, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(mode);


	//设置背景颜色
	system("color E4");

	//绘制界面框架
	DrawCol(0, 0);
	DrawCol(0, WIDTH - 2);
	DrawRow(0, 2);
	DrawRow(2, 2);
	DrawRow(4, 2);
	DrawRow(HEIGHT - 4, 2);
	DrawRow(HEIGHT - 2, 2);
	
	//

}








