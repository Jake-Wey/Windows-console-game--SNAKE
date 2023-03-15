#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include"Title.h"
#include "Map.h"
using namespace std;

const int width = 180;
const int height = 30;
#define white_black 0xf0
#define white_glory 0xf8

Maps map1, map2, map3, map4, map5, map6, map7, map8,currentMap;
int mapID;
enum eDirection
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
eDirection sDir,Dir;
string datalist[10];
int degree;
bool gameover;
bool isFullWidth;
bool isPause = false;
int x, y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail = 1;
string name;

void ReadData()
{
	ifstream file("data.txt");
	for (int i = 0; i < 10; i++)
	{
		getline(file, datalist[i]);
	}
	file.close();
}
void Initial()
{
	ShowWindow(GetForegroundWindow(), SW_MAXIMIZE);
    InitialMap(map1,map2,map3,map4,map5,map6,map7,map8);
   
	SetConsoleTitleA("Console_贪吃蛇");
	COORD dSize = { 80,25 };
	SetConsoleScreenBufferSize(h, dSize);
	CONSOLE_CURSOR_INFO _cursor = { 1,false };
	SetConsoleCursorInfo(h, &_cursor);
}
void Initial0()
{
	mapID = 0;
	sDir = STOP;
	ReadData();
	gameover = false;
	isFullWidth = true;
	Dir = STOP;
	score = 0;
	fruitX = rand() % MapWidth + 15;
	fruitY = rand() % MapHeight + 2;
	x = 40;
	y = 12;
	nTail = 1;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < 100; i++)
	{
		tailX[i] = 0;
		tailY[i] = 0;
	}
	name = "";
}

void DrawBorder()
{
	SetConsoleTextAttribute(h, 0xf8);
	for (int i=0;i<height;i++)
	{
		cout << endl;
	}
    system("cls");
    setPos(0, 0);

    for (int i=0;i<width/2+1;i++)
    {
        cout << "▓ ";
    }
    for (int i=1;i<height-1;i++)
    {
        setPos(0, i);
        cout << "▓ ";
        setPos(width / 2, i);
        cout << "▓ ";
    }
	setPos(0, height - 1);
	for (int i = 0; i < width / 2+1 ; i++)
	{
		cout << "▓ ";
	}
}
void TitlePage()
{
    DrawBorder();
    setPos(1, 1);
	SetConsoleTextAttribute(h, white_black);
    DrawTitle();
	SetConsoleTextAttribute(h, white_glory);
    for (int i=2;i<24;i++)
    {
        setPos(0, i);
        cout << "▓ ";
    }
    setPos(35, height - 3);
    cout << "★ ★ ★     S U N D A Y     ★ ★ ★";
    setPos(40, height-7);
}

void DrawSelector(int n)
{
	SetConsoleTextAttribute(h, white_black);
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 22; i++)
		{
			setPos((n - 1) % 4 * 22 + 1 + i, (n - 1) / 4 * 11 + 3 + a * 9);
			cout << "◆";
		}
	}
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 10; i++)
		{
			setPos((n - 1) % 4 * 22 + 1 + a * 21, (n - 1) / 4 * 11 + 3 + i);
			cout << "◆";
		}
	}
}
void TitleClear() 
{
    for (int i = 1; i<width/2;i++)
    {
        for (int j=2;j<26;j++)
        {
            setPos(i, j);
            cout << "  ";
        }
    }
}
void Input0(int num,int & x)
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
        case 'A':
            sDir = LEFT;
            x = 1;
            break;
        case 'w':
        case 'W':
            sDir = UP;
            x = 1;
            break;
		case 's':
		case 'S':
            sDir = DOWN;
            x = 1;
            break;
		case 'd':
		case 'D':
			sDir = RIGHT;
            x = 1;
            break;
		case 0x0D:
			mapID=num;
			break;
        case 224:
            switch (_getch())
			{
			case 72:
					sDir = UP;
                    x = 1;
				break;
			case 80:
					sDir = DOWN;
                    x = 1;
				break;
			case 75:
					sDir = LEFT;
                    x = 1;
				break;
			case 77:
					sDir = RIGHT;
                    x = 1;
				break;
            default:
                break;
            }
        default:
            break;
        }
    }
}
void eraseSelector(int n)
{
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 22; i++)
		{
			setPos((n - 1) % 4 * 22 + 1 + i, (n - 1) / 4 * 11 + 3 + a * 9);
			cout << "  ";
		}
	}
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < 10; i++)
		{
			setPos((n - 1) % 4 * 22 + 1 + a * 21, (n - 1) / 4 * 11 + 3 + i);
			cout << "  ";
		}
	}
}
void Logic0(int & num,int x)
{
    if (x)
    {
        switch (sDir)
        {
        case LEFT:
            if (num != 1 && num != 5)
            {
                num--;
            }
            break;
        case RIGHT:
            if (num != 4 && num != 8)
            {
                num++;
            }
            break;
        case UP:
            if (num > 4)
            {
                num = num - 4;
            }
            break;
        case DOWN:
            if (num <= 4)
            {
                num += 4;
            }
            break;
        default:
            break;
        }
    }
}
void MapPage()
{
    int _num = 1;
    int move = 0;
    TitleClear();
    for (int i = 1; i<9; i++)
    {
        DrawMap(i,(i-1)%4*22+2, (i-1)/4*11+4, 3,map1,map2,map3,map4,map5,map6,map7,map8);
    }
    DrawSelector(_num);
	setPos(10, height - 5);
	cout << "↑ W : 向上移动  ↓ S : 向下移动  ← A : 向左移动  → D : 向右移动  回车：确定";
    while (!mapID)
    {
        Input0(_num,move);
        if (move != 0) {
            eraseSelector(_num);
            Logic0(_num, move);
            DrawSelector(_num);
        }
        move = 0;
        Sleep(200);
    }
}

void Tickets()
{
    setPos(80, 3);
    cout << "↑ W : 向上移动";
	setPos(80, 5);
	cout << "↓ S : 向下移动";
	setPos(80, 7);
	cout << "← A : 向左移动";
	setPos(80, 9);
	cout << "→ D : 向右移动";
	setPos(80, 11);
	cout << " Q  : 暂停游戏";
	setPos(80, 13);
	cout << " X  : 退出游戏";
	setPos(80, 15);
	cout << " 回车 : 切换画面";
	setPos(80, 17);
	cout << " □  : 可以穿越";
	setPos(80, 19);
	cout << " ■  : 不可穿越";
}
void Billboard()
{
    for (int i=0;i<10;i++)
    {
        setPos(2, i * 2+3);
        switch (i+1)
        {
        case 1:
			if (datalist[i] == "")cout << "1st ";
            else cout << "1st "+datalist[i].substr(0,4)+"-"+datalist[i].substr(4,2)+"-"+datalist[i].substr(6,2)+" "+datalist[i].substr(8,3)+" "+datalist[i].substr(11,7);
            break;
        case 2:
			if (datalist[i] == "")cout << "2nd ";
			else cout << "2nd " + datalist[i].substr(0, 4) + "-" + datalist[i].substr(4, 2) + "-" + datalist[i].substr(6, 2) + " " + datalist[i].substr(8, 3) + " " + datalist[i].substr(11, 7);
            break;
        case 3:
			if (datalist[i] == "")cout << "3rd ";
            else cout << "3rd " + datalist[i].substr(0, 4) + "-" + datalist[i].substr(4, 2) + "-" + datalist[i].substr(6, 2) + " " + datalist[i].substr(8, 3) + " " + datalist[i].substr(11,7);
            break;
        default:
			if (datalist[i] == "")cout << i+1<<" ";
            else cout << i+1<<"  " + datalist[i].substr(0, 4) + "-" + datalist[i].substr(4, 2) + "-" + datalist[i].substr(6, 2) + " " + datalist[i].substr(8, 3) + " " + datalist[i].substr(11,7);
            break;
        }
    }
}
void DrawDegree()
{
    setPos(40, 10);
    cout << "       ★    简单";
    setPos(40, 13);
    cout << "     ★ ★   困难";
    setPos(40, 16);
    cout << "   ★ ★ ★  自杀";
    setPos(40, 19);
    cout << " ★ ★ ★ ★ 地狱";
    setPos(40, 5);
    cout << "输入难度等级1-4:";
	setPos(48, 5);
	cin >> degree;
	while (degree < 1 || degree>4)
	{
		setPos(44, 6);
		cout << "输入错误！重新输入！";
		setPos(48, 5);
		cin >> degree;
	}
}
void DegreePage()
{
	SetConsoleTextAttribute(h, white_glory);
    TitleClear();
    Tickets();
    Billboard();
    DrawDegree();
}

void DegreeClear()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			setPos(40 + i, j + 5);
			cout << "  ";
		}
	}
}
void Prepare()
{
	/*for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int flag = 0;
			for (int k = 0; k < nTail; k++)
			{
				if (tailX[k] == j+15 && tailY[k] == i+2)
					flag = 1;
			}
			if (i+2 == y && j+15 == x)
			{
                setPos(x, y);
				if (isFullWidth) cout << "●";
				else cout << "O";
			}
			else if(flag){
                setPos(j + 15, i + 2);
				if (isFullWidth) cout << "○";
				else cout << "o";
			}
		}
		cout << endl;
	}*/
	setPos(x, y);
	cout << "●";
	while (Judge(0, fruitX, fruitY, currentMap))
	{
		fruitX = rand() % MapWidth + 16;
		fruitY = rand() % MapHeight + 3;
	}
	setPos(fruitX, fruitY);
	cout << "★";
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'A':
		case 'a':
			if (Dir != RIGHT)
				Dir = LEFT;
			break;
		case 'D':
		case 'd':
			if (Dir != LEFT)
				Dir = RIGHT;
			break;
		case 'W':
		case 'w':
			if (Dir != DOWN)
				Dir = UP;
			break;
		case 'S':
		case 's':
			if (Dir != UP)
				Dir = DOWN;
			break;
		case 'X':
		case 'x':
			gameover = true;
			break;
		case 'Q':
		case 'q':
			isPause = !isPause;
			break;
		case 0x0D:
			if (isFullWidth) isFullWidth = false;
			else isFullWidth = true;
			break;
		case 224:
			switch (_getch())
			{
			case 72:
				if (Dir != DOWN)
					Dir = UP;
				break;
			case 80:
				if (Dir != UP)
					Dir = DOWN;
				break;
			case 75:
				if (Dir != RIGHT)
					Dir = LEFT;
				break;
			case 77:
				if (Dir != LEFT)
					Dir = RIGHT;
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i <= nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (Dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x == fruitX && y == fruitY)
	{
		score += 1;
		fruitX = rand() % MapWidth+15;
		fruitY = rand() % MapHeight+2;
		nTail++;
	}
	for (int i = 1; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameover = true;
	}
	int m = Judge(1, x, y, currentMap);
	if (m == 1) gameover = true;
	else
	{
		if (x < 16)x = 73;
		else if (x > 73)x = 16;
		else if (y < 3)y = 24;
		else if(y>24) y = 3;
	}
}
void DrawLocally()
{
	for (int i = 0; i < nTail; i++)
	{
		setPos(tailX[i], tailY[i]);
		if (i == 0)
		{
			SetConsoleTextAttribute(h, 0xf9);
			if (isFullWidth) cout << "●";
			else cout << "OO";
		}
		else
		{
			SetConsoleTextAttribute(h, 0xfb);
			if (isFullWidth) cout << "○";
			else cout << "oo";
		}
	}

	while (Judge(0, fruitX, fruitY, currentMap))
	{
		fruitX = rand() % MapWidth + 15;
		fruitY = rand() % MapHeight + 2;
	}
	setPos(fruitX, fruitY);
	SetConsoleTextAttribute(h, 0xf4);
	if (isFullWidth) cout << "★";
	else cout << "[]";
}
void eraseSnake()
{
	for (int i = 0; i < nTail; i++)
	{
		setPos(tailX[i], tailY[i]);
        cout << "  ";
	}
}

void writeScore(int n)
{
	ofstream outfile;
	outfile.open("data.txt", ios::out | ios::trunc);
	for (int i=0;i<n;i++)
	{
		outfile << datalist[i]<<endl;
	}
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm,&now);
	outfile << 1900 + ltm.tm_year;
	if (1 + ltm.tm_mon < 10)outfile << "0" << 1 + ltm.tm_mon;
	else outfile << 1 + ltm.tm_mon;
	if (ltm.tm_mday < 10)outfile << "0" <<ltm.tm_mday;
	else outfile <<ltm.tm_mday;
	if (score < 100&&score>9)outfile << "0" <<score;
	else if(score < 10)outfile << "00" << score;
	else outfile << score;
	outfile<< name.substr(0,6) << endl;
	for (int j=n+1;j<10;j++)
	{
		outfile << datalist[j]<<endl;
	}
	outfile.close();
}
void compareScore()
{
	for (int i=0;i<10;i++)
	{
		if (datalist[i] == "")
		{
			writeScore(i);
			break;
		}
		else if (atoi(datalist[i].substr(8,3).c_str())<=score)
		{
			for (int j=10;j>i;j--)
			{
				datalist[j] = datalist[j - 1];
			}
			writeScore(i);
			break;
		}
	}
}
void gameOver_info()
{
	setPos(40, 12);
	SetConsoleTextAttribute(h, 0xfc);
	cout << "游戏结束!!";
	setPos(40, 13);
	cout << "Y 重新开始/其它退出";
}
int main()
{

    Initial();

    TitlePage();
	system("pause");

start:
	Initial0();
	SetConsoleTextAttribute(h, white_glory);
    MapPage();
	setMap(mapID,currentMap, map1, map2, map3, map4, map5, map6, map7, map8);

    DegreePage();

	DegreeClear();
	DrawMap(mapID, 15, 2, 1, map1, map2, map3, map4, map5, map6, map7, map8);
    Prepare();
    while (!gameover)
    {
        Input();
		eraseSnake();
		if(!isPause)
            Logic();
		DrawLocally();

		SetConsoleTextAttribute(h, white_black);
		setPos(25, height - 3);
		cout << "得分："<<score;
		int sleep_time = 150 -30* (degree-1);
		Sleep(sleep_time);
    }
	MapClear();
	setPos(40, 8);
	cout << "最终得分：" << score;
	setPos(40, 10);
	cout << "请留下用户名（只取6位）:";
	cin >> name;
	compareScore();
	gameOver_info();
	bool gamequit = false;
	while (!gamequit)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'y':
			case 'Y':
				gameover = false;
				goto start;
				break;
			default:
				gamequit = true;
				break;
			}
		}
		Sleep(50);
	}
    setPos(0, height);
	system("pause");
	return 0;
}