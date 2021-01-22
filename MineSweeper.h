#include<vector>
#include<iostream>
using namespace std;


/*
0������ʾ
��1 ������ɫ����ʾ
12345678���ִ����м�����
9����С����
10 ���� ��������
11 ������

*/
class Map
{

public:
	vector<vector<bool>>mine;//��

	vector<vector<int>>draw;//��ʾ
	Map(int w, int h, int n);
	int findMine(int x, int y);//Ѱ��ĳһ��������Χ�׵�����
	//��ͼ��С���׵ĸ���
public:
	const int W;
	const int H;
	const int N;

private:
	vector<vector<bool>>visit;//��¼�Ƿ񱻷���
};

Map::Map(int w, int h, int n) :
	W(w), H(h), N(n)
{
	mine.resize(w);
	draw.resize(w);
	visit.resize(w);
	for (int i = 0; i < W; i++)
	{
		mine[i].resize(H, false);
		draw[i].resize(H, -1);
		visit[i].resize(H, false);
	}

	while (n >= 0)
	{
		n--;
		int x = rand() % W;
		int y = rand() % H;
		if (mine[x][y] == false) {
			mine[x][y] = true;
		}
		else
		{
			n++;
		}

	}


}
int Map::findMine(int x, int y)
{
	
	if (x < 0) return 0;
	if (x == W) return 0;
	if (y < 0) return 0;
	if (y == H) return 0;
	//���������ĸ��߽�
	if (visit[x][y] == true)
		return draw[x][y];
	else visit[x][y] = true;

	int n = 0;
	bool xl, xh, yl, yh;
	xl = xh = yl = yh = false;
	//�ϱ߽�
	if (y > 0)
	{
		if (mine[x][y - 1] == true)
			n++;
		yl = true;
	}
	//�±߽�
	if (y < H - 2)
	{
		if (mine[x][y + 1] == true)
			n++;
		yh = true;
	}
	if (x > 0)
	{
		if (mine[x - 1][y] == true)
			n++;
		xl = true;
	}
	if (x < W - 2)
	{
		if (mine[x + 1][y] == true)
			n++;

		xh = true;
	}

	if (xl && yl)
	{
		if (mine[x - 1][y - 1] == true)
			n++;
	}
	if (xl && yh)
	{
		if (mine[x - 1][y + 1] == true)
			n++;
	}
	if (xh && yl)
	{
		if (mine[x + 1][y - 1] == true)
			n++;
	}
	if (xh && yh)
	{
		if (mine[x + 1][y + 1] == true)
			n++;
	}
	//���������ո�

	draw[x][y] = n;
	if(n==0)
	{
		//findMine(x - 1, y);
		
		if (xl)
			findMine(x - 1, y);
		if (xh)
			findMine(x + 1, y);
		if (yl)
			findMine(x, y - 1);
		if (yh)
			findMine(x, y + 1);
		if (xl && yl)
			findMine(x - 1, y - 1);
		if (xl && yh)
			findMine(x - 1, y + 1);
		if (xh && yl)
			findMine(x + 1, y - 1);
		if (xh && yh)
			findMine(x + 1, y + 1);
		
		return 0;
	}
	return n;

}

