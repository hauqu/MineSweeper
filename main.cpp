#include"MineSweeper.h"
#include<graphics.h>
#include<time.h>
#include<conio.h>
using namespace std;
const int K = 60;
const int MapW = 10;
const int MapH = 10;

void drawGame(Map& m);
void load();
Map mainGame = Map(MapW, MapH, 10);

IMAGE p0;
IMAGE p_1;
IMAGE p1; IMAGE p2; IMAGE p3; IMAGE p4; 
IMAGE p5; IMAGE p6;IMAGE p7; IMAGE p8;
IMAGE p10;
IMAGE p9;
IMAGE p11;


int main(int argc,char *argv[])
{
	initgraph(MapW * K, MapH * K);
	load();
	srand(time(nullptr));
	drawGame(mainGame);
	
	while (true)
	{
		MOUSEMSG ms = GetMouseMsg();
		if (ms.mkLButton || ms.mkRButton)
		{
			int w = ms.x / K;
			int h = ms.y / K;
			if (w < 0||w>mainGame.W||h<0||h>mainGame.H)
				continue;

			if((mainGame.draw[w][h]==-1||mainGame.draw[w][h]==9)&&ms.mkLButton)
			{
				if(mainGame.mine[w][h]==true)
				{
					mainGame.draw[w][h] = 10;
					//goto GameOver;
				}else
				{
					mainGame.draw[w][h] = mainGame.findMine(w, h);
				}
			}
			
			//处理标记
			if(ms.mkRButton&&mainGame.draw[w][h]==-1)
			{
				mainGame.draw[w][h] = 9;
			}
			else if (ms.mkRButton && mainGame.draw[w][h] == 9)
			{
				mainGame.draw[w][h] = -1;
			}
			drawGame(mainGame);
		}
	}

	
GameOver:
	drawGame(mainGame);
	_getch();
	closegraph();

	return 0;
}
void drawGame(Map& m)
{
		/*
		-1代表不显示
		0 代表深色不显示
		12345678数字代表有几颗雷
		9代表小旗子
		10 代表 踩着雷了
		11 代表雷

		*/
	for (int i =0; i < m.W; i++)
	{
		for (int j = 0; j < m.H; j++)
		{
			switch (m.draw[i][j])
			{
			case -1:
				putimage(i * K, j * K, &p_1);
				break;
			case 0:
				putimage(i * K, j * K, &p0);
				break;
			case 1:
				putimage(i * K, j * K, &p1);
				break;
			case 2:
				putimage(i * K, j * K, &p2);
				break;
			case 3:
				putimage(i * K, j * K, &p3);
				break;
			case 4:
				putimage(i * K, j * K, &p4);
				break;
			case 5:
				putimage(i * K, j * K, &p5);
				break;
			case 6:
				putimage(i * K, j * K, &p6);
				break;
			case 7:
				putimage(i * K, j * K, &p7);
				break;
			case 8:
				putimage(i * K, j * K, &p8);
				break;
			case 9:
				putimage(i * K, j * K, &p9);
				break;
			case 10:
				putimage(i * K, j * K, &p10);
				break;
			case 11:
				putimage(i * K, j * K, &p11);
				break;
			default:
				break;
			}
		}
	}
	
}

void load()
{
	loadimage(&p0, L"0.jpg", K, K);
	loadimage(&p1, L"1.jpg", K, K);
	loadimage(&p2, L"2.jpg", K, K);
	loadimage(&p3, L"3.jpg", K, K);
	loadimage(&p4, L"4.jpg", K, K);
	loadimage(&p5, L"5.jpg", K, K);
	loadimage(&p6, L"6.jpg", K, K);
	loadimage(&p7, L"7.jpg", K, K);
	loadimage(&p8, L"8.jpg", K, K);
	loadimage(&p9, L"9.jpg", K, K);
	loadimage(&p10, L"10.jpg", K, K);
	loadimage(&p11, L"11.jpg", K, K);
	loadimage(&p_1, L"-1.jpg", K, K);
}