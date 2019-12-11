#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include <queue>
using namespace std;
vector<vector<int>>Read_and_Make_Graff(const char* path)
{
	int HMF,FR;
	ifstream File(path);
	int size1, size2, sizeGraf;
	File >> size1 >> size2;
	sizeGraf = size1 + size2 + 2;
	vector<vector<int>>Graf(sizeGraf, vector<int>(sizeGraf, 0));
	for (int i = 2; i < size1 + 2; i++)
	{
		Graf[0][i] = 1;
		//Graf[i][0] = 1;
	}

	for (int i = size1+2; i < sizeGraf; i++)
	{
		//Graf[1][i] = 1;
		Graf[i][1] = 1;
	}

	for (int i = 0; i < size1; i++)
	{
		File >> HMF;
		while (HMF)
		{
			File >> FR;
			HMF--;
			Graf[i+2][FR+size1+2] = 1;
		}
	}

	return Graf;
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
	vector<vector<int>> Graf = Read_and_Make_Graff(path);
	vector<vector<int>> resGraf(Graf.size(), vector<int>(Graf.size(), 0));
	vector<int>oneway = OneIteration(Graf);
	while (1)
	{
		if (oneway[0]==-99)
			break;
		int i;
		i = 1;
		
		while (i != 0)
		{
			Graf[oneway[i]][i] -= 1;
			Graf[i][oneway[i]] += 1;		
			resGraf[oneway[i]][i] += 1;
			resGraf[i][oneway[i]] -= 1;
			i = oneway[i];
		}
		
		oneway = OneIteration(Graf);
		if ((oneway[0] == -99))
			break;
	}
	for (int i = 0; i < resGraf.size(); i++)
	{
		res += resGraf[i][1];
	}
	return res;
}
