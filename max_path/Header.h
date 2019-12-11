#include<iostream>
#include<vector>
#include<fstream>
#include <queue>

using namespace std;

int ReadSize(const char* path)
{
	int size;
	ifstream h(path);
	h >> size;
	return size;
}

void ReadGraff(const char*path,int** a)
{
	int size;
	ifstream h(path);
	h >> size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			h >> a[i][j];
		}
	}
	a[0][0] = size;

}


void OneIteration(int**Graf, int*tags)
{
	int now;
	tags[0] = 0;
	for (int i = 1; i < Graf[0][0]; i++)
	{
		tags[i] = -1;
	}
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 1; i < Graf[0][0]; i++)
		{
			if ((Graf[now][i]) && (tags[i] == -1))
			{
				q.push(i);
				tags[i] = now;
				if (i == 1)
				{
					return;
				}
			}
		}
	}
	tags[0] = -99;
	return;
}

int Ford_Falkerson(const char* path)
{
	int size;
	int boutlenack = 0;
	int res = 0;
	int smalestonway = 1;
	size = ReadSize(path);
	int**Graf = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
	{
		Graf[i] = (int*)malloc(sizeof(int) * size);
	}
	ReadGraff(path,Graf);
	int* oneway = (int*)malloc(sizeof(int) * size);
	OneIteration(Graf,oneway);
	while (smalestonway)
	{
		int i = 1;
		smalestonway = Graf[oneway[i]][i];
		while (i != 0)
		{
			if (Graf[oneway[i]][i] <= smalestonway)
			{
				smalestonway = Graf[oneway[i]][i];
				boutlenack = i;
			}
			i = oneway[i];
		}
		Graf[oneway[boutlenack]][boutlenack] -= smalestonway;
		if (res < smalestonway)
			res = smalestonway;
		OneIteration(Graf,oneway);
		if ((oneway[0] == -99))
			break;
	}

	for (int i = 0; i < size; i++)
	{
		free(Graf[i]);
	}
	free(Graf);
	free(oneway);

	return res;
}