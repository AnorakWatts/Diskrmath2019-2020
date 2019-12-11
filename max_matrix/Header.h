#include<iostream>
#include<vector>
#include<fstream>
#include <queue>

using namespace std;

vector<vector<int>> Read_and_make_Graff(const char* path)
{
	int sizeL, sizeH;
	ifstream h(path);
	h >> sizeL >> sizeH;
	int size = sizeL + sizeH + 2;
	vector<vector<int>>a(size, vector<int>(size, 2147483647));
	for (int i = 2; i < sizeL + 2; i++)
	{
		h >> a[0][i];
		a[i][0] = a[0][i];
		a[1][i] = 0;
		a[i][1] = 0;
		for (int j = 2; j < sizeL + 2; j++)
		{
			a[i][j] = 0;
			a[j][i] = 0;
		}
	}
	for (int j = sizeL + 2; j < sizeL + sizeH + 2; j++)
	{
		h >> a[1][j];
		a[j][1] = a[1][j];
		a[0][j] = 0;
		a[j][0] = 0;
		for (int i = sizeL + 2; i < sizeL + sizeH + 2; i++)
		{
			a[i][j] = 0;
			a[j][i] = 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		a[i][i] = 0;
	}

	a[0][1] = 0;
	a[1][0] = 0;


	return a;
}

vector<int>OneIteration(vector<vector<int>>v)
{
	int now;
	vector<int> tags(v.size(), -1);
	tags[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 1; i < v.size(); i++)
		{
			if ((v[now][i]) && (tags[i] == -1))
			{
				q.push(i);
				tags[i] = now;
				if (i == 1)
				{
					return tags;
				}
			}
		}
	}
	vector<int >t(1, -99);
	return t;
}

int Ford_Falkerson(const char* path)
{
	int res = 0;
	int smalestonway = 1;
	vector<vector<int>> Graf = Read_and_make_Graff(path);
	vector<int>oneway = OneIteration(Graf);
	while (smalestonway)
	{
		int i = 1;
		smalestonway = Graf[oneway[i]][i];
		while (i != 0)
		{
			if (Graf[oneway[i]][i] < smalestonway)
			{
				smalestonway = Graf[oneway[i]][i];
			}
			i = oneway[i];
		}
		i = 1;
		while (i != 0)
		{
			Graf[oneway[i]][i] -= smalestonway;
			Graf[i][oneway[i]] += smalestonway;
			i = oneway[i];
		}
		res += smalestonway;
		oneway = OneIteration(Graf);
		if ((oneway[0] == -99))
			break;
	}


	return res;
}
