#pragma once
#ifndef _Map_H_
#define _Map_H_
#include <iostream>
#include <math.h>

int MapWidth = 60;
int MapHeight = 24;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void setPos(int _x, int _y)//π‚±ÍŒª÷√
{
	COORD pos;
	pos.X = _x * 2;
	pos.Y = _y;
	SetConsoleCursorPosition(h, pos);
}
struct Line
{
	int x0, x1, y0, y1;
	int kind;
};
class Maps
{
public:
	int num;
	struct Line L[18];
	void paint(int x, int y,int m)
	{
		for (int i = 0; i < num; i++)
		{
			int l;
			if (L[i].x0==L[i].x1)
			{
				int Y = L[i].y0 < L[i].y1 ? L[i].y0 : L[i].y1;
				l = (abs(L[i].y0 - L[i].y1) + 1);
				for (int j=1;j<=l;j++)
				{
					setPos(L[i].x0/m + x, Y/m + y);
					Y++;
					if (L[i].kind == 0)cout << "°ı";
					else cout << "°ˆ";
				}
			}
			else
			{
				int X = L[i].x0 < L[i].x1 ? L[i].x0 : L[i].x1;
				l = (abs(L[i].x0 - L[i].x1) + 1);
				for (int j = 1; j <= l; j++)
				{
					setPos(X/m + x, L[i].y0/m + y);
					X++;
					if (L[i].kind == 0)cout << "°ı";
					else cout << "°ˆ";
				}
			}
		}
	}
};

void InitialMap(Maps & m1,Maps & m2,Maps & m3,Maps & m4,Maps & m5,Maps & m6,Maps & m7,Maps & m8)
{
	{
		m1.num = 4;
		m1.L[0].kind = 0;
		m1.L[0].x0 = 0;
		m1.L[0].y0 = 0;
		m1.L[0].x1 = MapWidth - 1;
		m1.L[0].y1 = 0;

		m1.L[1].kind = 0;
		m1.L[1].x0 = MapWidth - 1;
		m1.L[1].y0 = 1;
		m1.L[1].x1 = MapWidth - 1;
		m1.L[1].y1 = MapHeight - 2;

		m1.L[2].kind = 0;
		m1.L[2].x0 = 0;
		m1.L[2].y0 = MapHeight - 1;
		m1.L[2].x1 = MapWidth - 1;
		m1.L[2].y1 = MapHeight - 1;

		m1.L[3].kind = 0;
		m1.L[3].x0 = 0;
		m1.L[3].y0 = 1;
		m1.L[3].x1 = 0;
		m1.L[3].y1 = MapHeight - 2;
	}
	{
		m2.num = 4;

		m2.L[0].kind = 1;
		m2.L[0].x0 = 0;
		m2.L[0].y0 = 0;
		m2.L[0].x1 = MapWidth - 1;
		m2.L[0].y1 = 0;

		m2.L[1].kind = 1;
		m2.L[1].x0 = MapWidth - 1;
		m2.L[1].y0 = 1;
		m2.L[1].x1 = MapWidth - 1;
		m2.L[1].y1 = MapHeight - 2;

		m2.L[2].kind = 1;
		m2.L[2].x0 = 0;
		m2.L[2].y0 = MapHeight - 1;
		m2.L[2].x1 = MapWidth - 1;
		m2.L[2].y1 = MapHeight - 1;

		m2.L[3].kind = 1;
		m2.L[3].x0 = 0;
		m2.L[3].y0 = 1;
		m2.L[3].x1 = 0;
		m2.L[3].y1 = MapHeight - 2;
	}
	{
		m3.num = 14;

		m3.L[0].kind = 1;
		m3.L[0].x0 = 0;
		m3.L[0].y0 = 0;
		m3.L[0].x1 = 5;
		m3.L[0].y1 = 0;

		m3.L[1].kind = 1;
		m3.L[1].x0 = 0;
		m3.L[1].y0 = 1;
		m3.L[1].x1 = 0;
		m3.L[1].y1 = 5;

		m3.L[2].kind = 1;
		m3.L[2].x0 = 0;
		m3.L[2].y0 = MapHeight-7;
		m3.L[2].x1 = 0;
		m3.L[2].y1 = MapHeight-1;

		m3.L[3].kind = 1;
		m3.L[3].x0 = 1;
		m3.L[3].y0 = MapHeight-1;
		m3.L[3].x1 = 5;
		m3.L[3].y1 = MapHeight-1;

		m3.L[4].kind = 1;
		m3.L[4].x0 = MapWidth-6;
		m3.L[4].y0 = 0;
		m3.L[4].x1 = MapWidth-1;
		m3.L[4].y1 = 0;

		m3.L[5].kind = 1;
		m3.L[5].x0 = MapWidth-1;
		m3.L[5].y0 = 1;
		m3.L[5].x1 = MapWidth-1;
		m3.L[5].y1 = 5;

		m3.L[6].kind = 1;
		m3.L[6].x0 = MapWidth-1;
		m3.L[6].y0 = MapHeight-6;
		m3.L[6].x1 = MapWidth-1;
		m3.L[6].y1 = MapHeight-1;

		m3.L[7].kind = 1;
		m3.L[7].x0 = MapWidth-6;
		m3.L[7].y0 = MapHeight-1;
		m3.L[7].x1 = MapWidth-2;
		m3.L[7].y1 = MapHeight-1;

		m3.L[8].kind = 1;
		m3.L[8].x0 = 20;
		m3.L[8].y0 = 8;
		m3.L[8].x1 = 40;
		m3.L[8].y1 = 8;

		m3.L[9].kind = 1;
		m3.L[9].x0 = 20;
		m3.L[9].y0 = 16;
		m3.L[9].x1 = 40;
		m3.L[9].y1 = 16;

		m3.L[10].kind = 0;
		m3.L[10].x0 = 6;
		m3.L[10].y0 = 0;
		m3.L[10].x1 = MapWidth-7;
		m3.L[10].y1 = 0;

		m3.L[11].kind = 0;
		m3.L[11].x0 = 6;
		m3.L[11].y0 = MapHeight-1;
		m3.L[11].x1 = MapWidth-7;
		m3.L[11].y1 = MapHeight-1;

		m3.L[12].kind = 0;
		m3.L[12].x0 = 0;
		m3.L[12].y0 = 6;
		m3.L[12].x1 = 0;
		m3.L[12].y1 = MapHeight-7;

		m3.L[13].kind = 0;
		m3.L[13].x0 = MapWidth-1;
		m3.L[13].y0 = 6;
		m3.L[13].x1 = MapWidth-1;
		m3.L[13].y1 = MapHeight-7;
	}
	{
		m4.num = 12;

		m4.L[0].kind = 0;
		m4.L[0].x0 = 0;
		m4.L[0].y0 = 0;
		m4.L[0].x1 = 19;
		m4.L[0].y1 = 0;

		m4.L[1].kind = 0;
		m4.L[1].x0 = 21;
		m4.L[1].y0 = 0;
		m4.L[1].x1 = MapWidth-1;
		m4.L[1].y1 = 0;

		m4.L[2].kind = 0;
		m4.L[2].x0 = 0;
		m4.L[2].y0 = MapHeight-1;
		m4.L[2].x1 = 39;
		m4.L[2].y1 = MapHeight-1;

		m4.L[3].kind = 0;
		m4.L[3].x0 = 41;
		m4.L[3].y0 = MapHeight-1;
		m4.L[3].x1 = MapWidth-1;
		m4.L[3].y1 = MapHeight-1;

		m4.L[4].kind = 0;
		m4.L[4].x0 = 0;
		m4.L[4].y0 = 1;
		m4.L[4].x1 = 0;
		m4.L[4].y1 = 14;

		m4.L[5].kind = 0;
		m4.L[5].x0 = 0;
		m4.L[5].y0 = 16;
		m4.L[5].x1 = 0;
		m4.L[5].y1 = MapHeight-1;

		m4.L[6].kind = 0;
		m4.L[6].x0 = MapWidth-1;
		m4.L[6].y0 = 1;
		m4.L[6].x1 = MapWidth-1;
		m4.L[6].y1 = 7;

		m4.L[7].kind = 0;
		m4.L[7].x0 = MapWidth-1;
		m4.L[7].y0 = 9;
		m4.L[7].x1 = MapWidth-1;
		m4.L[7].y1 = MapHeight-1;

		m4.L[8].kind = 1;
		m4.L[8].x0 = 0;
		m4.L[8].y0 = 15;
		m4.L[8].x1 = MapWidth/2-1;
		m4.L[8].y1 = 15;

		m4.L[9].kind = 1;
		m4.L[9].x0 = 20;
		m4.L[9].y0 = 0;
		m4.L[9].x1 = 20;
		m4.L[9].y1 = 10;

		m4.L[10].kind = 1;
		m4.L[10].x0 = MapWidth/2+1;
		m4.L[10].y0 = 8;
		m4.L[10].x1 = MapWidth-1;
		m4.L[10].y1 = 8;

		m4.L[11].kind = 1;
		m4.L[11].x0 = 40;
		m4.L[11].y0 = MapHeight-11;
		m4.L[11].x1 = 40;
		m4.L[11].y1 = MapHeight-1;
	}
	{
		m5.num = 10;

		m5.L[0].kind = 1;
		m5.L[0].x0 = 0;
		m5.L[0].y0 = 0;
		m5.L[0].x1 = MapWidth-1;
		m5.L[0].y1 = 0;

		m5.L[1].kind = 1;
		m5.L[1].x0 = 0;
		m5.L[1].y0 = MapHeight-1;
		m5.L[1].x1 = MapWidth - 1;
		m5.L[1].y1 = MapHeight-1;

		m5.L[2].kind = 1;
		m5.L[2].x0 = 0;
		m5.L[2].y0 = 1;
		m5.L[2].x1 = 0;
		m5.L[2].y1 = 9;

		m5.L[3].kind = 1;
		m5.L[3].x0 = MapWidth-1;
		m5.L[3].y0 = 1;
		m5.L[3].x1 = MapWidth - 1;
		m5.L[3].y1 = 9;

		m5.L[4].kind = 1;
		m5.L[4].x0 = 0;
		m5.L[4].y0 = 15;
		m5.L[4].x1 = 0;
		m5.L[4].y1 = MapHeight-1;

		m5.L[5].kind = 1;
		m5.L[5].x0 = MapWidth-1;
		m5.L[5].y0 = 15;
		m5.L[5].x1 = MapWidth - 1;
		m5.L[5].y1 = MapHeight-1;

		m5.L[6].kind = 0;
		m5.L[6].x0 = 0;
		m5.L[6].y0 = 10;
		m5.L[6].x1 = 0;
		m5.L[6].y1 = 14;

		m5.L[7].kind = 0;
		m5.L[7].x0 = MapWidth-1;
		m5.L[7].y0 = 10;
		m5.L[7].x1 = MapWidth - 1;
		m5.L[7].y1 = 14;

		m5.L[8].kind = 1;
		m5.L[8].x0 = 19;
		m5.L[8].y0 = 5;
		m5.L[8].x1 = 19;
		m5.L[8].y1 = 19;

		m5.L[9].kind = 1;
		m5.L[9].x0 = 39;
		m5.L[9].y0 = 5;
		m5.L[9].x1 = 39;
		m5.L[9].y1 = 19;
	}
	{
		m6.num = 11;
		
		m6.L[0].kind = 0;
		m6.L[0].x0 = 0;
		m6.L[0].y0 = 0;
		m6.L[0].x1 = MapWidth/2-1;
		m6.L[0].y1 = 0;

		m6.L[1].kind = 0;
		m6.L[1].x0 = MapWidth/2+1;
		m6.L[1].y0 = 0;
		m6.L[1].x1 = MapWidth-1;
		m6.L[1].y1 = 0;

		m6.L[2].kind = 0;
		m6.L[2].x0 = 0;
		m6.L[2].y0 = MapHeight-1;
		m6.L[2].x1 = MapWidth / 2 - 1;
		m6.L[2].y1 = MapHeight-1;

		m6.L[3].kind = 0;
		m6.L[3].x0 = MapWidth/2+1;
		m6.L[3].y0 = MapHeight-1;
		m6.L[3].x1 = MapWidth - 1;
		m6.L[3].y1 = MapHeight-1;

		m6.L[4].kind = 0;
		m6.L[4].x0 = 0;
		m6.L[4].y0 = 1;
		m6.L[4].x1 = 0;
		m6.L[4].y1 = MapHeight/2-1;

		m6.L[5].kind = 0;
		m6.L[5].x0 = 0;
		m6.L[5].y0 = MapHeight/2+1;
		m6.L[5].x1 = 0;
		m6.L[5].y1 = MapHeight-1;

		m6.L[6].kind = 0;
		m6.L[6].x0 = MapWidth-1;
		m6.L[6].y0 = 1;
		m6.L[6].x1 = MapWidth-1;
		m6.L[6].y1 = MapHeight/2-1;

		m6.L[7].kind = 0;
		m6.L[7].x0 = MapWidth-1;
		m6.L[7].y0 = MapHeight/2+1;
		m6.L[7].x1 = MapWidth - 1;
		m6.L[7].y1 = MapHeight-1;

		m6.L[8].kind = 1;
		m6.L[8].x0 = 0;
		m6.L[8].y0 = MapHeight/2;
		m6.L[8].x1 = MapWidth-1;
		m6.L[8].y1 = MapHeight/2;

		m6.L[9].kind = 1;
		m6.L[9].x0 = MapWidth/2;
		m6.L[9].y0 = 0;
		m6.L[9].x1 = MapWidth / 2;
		m6.L[9].y1 = MapHeight/2-1;

		m6.L[10].kind = 1;
		m6.L[10].x0 = MapWidth/2;
		m6.L[10].y0 = MapHeight/2+1;
		m6.L[10].x1 = MapWidth / 2;
		m6.L[10].y1 = MapHeight-1;
	}
	{
		m7.num = 11;

		m7.L[0].kind = 0;
		m7.L[0].x0 = 0;
		m7.L[0].y0 = 0;
		m7.L[0].x1 = MapWidth-1;
		m7.L[0].y1 = 0;

		m7.L[1].kind = 0;
		m7.L[1].x0 = 0;
		m7.L[1].y0 = 1;
		m7.L[1].x1 = 0;
		m7.L[1].y1 = MapHeight/2-1;

		m7.L[2].kind = 0;
		m7.L[2].x0 = 0;
		m7.L[2].y0 = MapHeight/2+1;
		m7.L[2].x1 = 0;
		m7.L[2].y1 = MapHeight-1;

		m7.L[3].kind = 0;
		m7.L[3].x0 = MapWidth-1;
		m7.L[3].y0 = 1;
		m7.L[3].x1 = MapWidth - 1;
		m7.L[3].y1 = MapHeight/2-1;

		m7.L[4].kind = 0;
		m7.L[4].x0 = MapWidth-1;
		m7.L[4].y0 = MapHeight/2+1;
		m7.L[4].x1 = MapWidth - 1;
		m7.L[4].y1 = MapHeight-1;

		m7.L[5].kind = 1;
		m7.L[5].x0 = 0;
		m7.L[5].y0 = MapHeight/2;
		m7.L[5].x1 = MapWidth - 1;
		m7.L[5].y1 = MapHeight/2;

		m7.L[6].kind = 0;
		m7.L[6].x0 = 1;
		m7.L[6].y0 = MapHeight-1;
		m7.L[6].x1 = MapWidth/3-1;
		m7.L[6].y1 = MapHeight-1;

		m7.L[7].kind = 0;
		m7.L[7].x0 = MapWidth/3+1;
		m7.L[7].y0 = MapHeight-1;
		m7.L[7].x1 = MapWidth/3*2-1;
		m7.L[7].y1 = MapHeight-1;

		m7.L[8].kind = 0;
		m7.L[8].x0 = MapWidth/3*2+1;
		m7.L[8].y0 = MapHeight-1;
		m7.L[8].x1 = MapWidth - 1;
		m7.L[8].y1 = MapHeight-1;

		m7.L[10].kind = 1;
		m7.L[10].x0 = MapWidth/3;
		m7.L[10].y0 = MapHeight/2+1;
		m7.L[10].x1 = MapWidth/3;
		m7.L[10].y1 = MapHeight-1;

		m7.L[9].kind = 1;
		m7.L[9].x0 = MapWidth/3*2;
		m7.L[9].y0 = MapHeight/2+1;
		m7.L[9].x1 = MapWidth/3*2;
		m7.L[9].y1 = MapHeight-1;
	}
	{
		m8.num = 18;

		m8.L[0].kind = 1;
		m8.L[0].x0 = 0;
		m8.L[0].y0 = 0;
		m8.L[0].x1 = 5;
		m8.L[0].y1 = 0;

		m8.L[1].kind = 0;
		m8.L[1].x0 = 6;
		m8.L[1].y0 = 0;
		m8.L[1].x1 = 10;
		m8.L[1].y1 = 0;

		m8.L[2].kind = 1;
		m8.L[2].x0 = 11;
		m8.L[2].y0 = 0;
		m8.L[2].x1 = MapWidth-6;
		m8.L[2].y1 = 0;

		m8.L[3].kind = 0;
		m8.L[3].x0 = MapWidth-5;
		m8.L[3].y0 = 0;
		m8.L[3].x1 = MapWidth-1;
		m8.L[3].y1 = 0;

		m8.L[4].kind = 1;
		m8.L[4].x0 = 0;
		m8.L[4].y0 = 1;
		m8.L[4].x1 = 0;
		m8.L[4].y1 = 3;

		m8.L[5].kind = 0;
		m8.L[5].x0 = 0;
		m8.L[5].y0 = 4;
		m8.L[5].x1 = 0;
		m8.L[5].y1 = 9;

		m8.L[6].kind = 1;
		m8.L[6].x0 = 0;
		m8.L[6].y0 = 10;
		m8.L[6].x1 = 24;
		m8.L[6].y1 = 10;

		m8.L[7].kind = 1;
		m8.L[7].x0 = 24;
		m8.L[7].y0 = 10;
		m8.L[7].x1 = 24;
		m8.L[7].y1 = 1;

		m8.L[8].kind = 0;
		m8.L[8].x0 = 0;
		m8.L[8].y0 = 11;
		m8.L[8].x1 = 0;
		m8.L[8].y1 = 15;

		m8.L[9].kind = 0;
		m8.L[9].x0 = 0;
		m8.L[9].y0 = 17;
		m8.L[9].x1 = 0;
		m8.L[9].y1 = MapHeight-1;

		m8.L[10].kind = 0;
		m8.L[10].x0 = MapWidth-1;
		m8.L[10].y0 = 1;
		m8.L[10].x1 = MapWidth-1;
		m8.L[10].y1 = 9;

		m8.L[11].kind = 1;
		m8.L[11].x0 = MapWidth/2;
		m8.L[11].y0 = 10;
		m8.L[11].x1 = MapWidth-1;
		m8.L[11].y1 = 10;

		m8.L[12].kind = 0;
		m8.L[12].x0 = MapWidth-1;
		m8.L[12].y0 = 11;
		m8.L[12].x1 = MapWidth-1;
		m8.L[12].y1 = 15;

		m8.L[13].kind = 0;
		m8.L[13].x0 = MapWidth-1;
		m8.L[13].y0 = 17;
		m8.L[13].x1 = MapWidth-1;
		m8.L[13].y1 = MapHeight-1;

		m8.L[14].kind = 1;
		m8.L[14].x0 = 0;
		m8.L[14].y0 = 16;
		m8.L[14].x1 = MapWidth-1;
		m8.L[14].y1 = 16;

		m8.L[15].kind = 1;
		m8.L[15].x0 = MapWidth/2;
		m8.L[15].y0 = 17;
		m8.L[15].x1 = MapWidth/2;
		m8.L[15].y1 = MapHeight-1;

		m8.L[16].kind = 0;
		m8.L[16].x0 = 1;
		m8.L[16].y0 = MapHeight-1;
		m8.L[16].x1 = MapWidth/2-1;
		m8.L[16].y1 = MapHeight-1;

		m8.L[17].kind = 0;
		m8.L[17].x0 = MapWidth/2+1;
		m8.L[17].y0 = MapHeight-1;
		m8.L[17].x1 = MapWidth-1;
		m8.L[17].y1 = MapHeight-1;
	}
}
    
void DrawMap(int num,int x,int y, int bl, Maps& m1, Maps& m2, Maps& m3, Maps& m4, Maps& m5, Maps& m6, Maps& m7, Maps& m8)
{
	switch (num)
	{
	case 1:
		m1.paint(x, y, bl);
		break;
	case 2:
		m2.paint(x, y, bl);
		break;
	case 3:
		m3.paint(x, y, bl);
		break;
	case 4:
		m4.paint(x, y, bl);
		break;
	case 5:
		m5.paint(x, y,bl);
		break;
	case 6:
		m6.paint(x, y, bl);
		break;
	case 7:
		m7.paint(x, y, bl);
		break;
	case 8:
		m8.paint(x, y, bl);
		break;
	default:
		break;
	}
}

void setMap(int id,Maps & m, Maps& m1, Maps& m2, Maps& m3, Maps& m4, Maps& m5, Maps& m6, Maps& m7, Maps& m8)
{
	switch (id)
	{
	case 1:
		m = m1;
		break;
	case 2:
		m = m2;
		break;
	case 3:
		m = m3;
		break;
	case 4:
		m = m4;
		break;
	case 5:
		m = m5;
		break;
	case 6:
		m = m6;
		break;
	case 7:
		m = m7;
		break;
	case 8:
		m = m8;
		break;
	default:
		break;
	}
}

int Judge(int kind,int x,int y,Maps & map)
{
	int XXX;
		for (int i=0;i<map.num;i++)
		{
			if (map.L[i].x0==map.L[i].x1)
			{
				if (map.L[i].x0+15==x)
				{
					int v = map.L[i].y0;
					int l = map.L[i].y0 > map.L[i].y1 ? -1 : 1;
					while (true)
					{
						if (l > 0 && v > map.L[i].y1)break;
						else if (l < 0 && v < map.L[i].y1)break;
						if (y==v+2)
						{
							if (kind==0)
							{
								return 1;
							}
							else
							{
								if (map.L[i].kind == 0)
								{
									return 2;
								}
								else return 1;
							}
						}
						v += l;
					}
				}
			}
				else if (map.L[i].y0==map.L[i].y1)
			{
				if (map.L[i].y0+2==y)
				{
					int v = map.L[i].x0;
					int l = map.L[i].x0 > map.L[i].x0 ? -1 : 1;
					while (true)
					{
						if (l > 0 && v > map.L[i].x1)break;
						else if (l < 0 && v < map.L[i].x1)break;
						if (x == v + 15)
						{
							if (kind == 0)
							{
								return 1;
							}
							else
							{
								if (map.L[i].kind == 0)
								{
									return 2;
								}
								else return 1;
							}
						}
						v += l;
					}
				}
			}
		}
	return 0;
}

void MapClear()
{
	for (int i = 2; i < 26; i++)
	{
		for (int j = 15; j < 75; j++)
		{
			setPos(j, i);
			cout << "  ";
		}
	}
}
#endif 