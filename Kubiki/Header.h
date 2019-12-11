#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> Read_and_make_graf(int&wordsize,const char* path)
{
	char c;
	int size = 0;
	wordsize = 0;
	ifstream File(path);
	File >> size;
	c = File.get();
	while ((c = File.get()) != '\n')
	{
		wordsize++;
	}
	File.close();
	File.open(path);

	File >> size;
	int sizeGraf = wordsize + size + 2;
	vector<vector<int>> Graf(sizeGraf, vector<int>(sizeGraf, 0));
	vector<vector<int>> kubiki(size, vector<int>(6, 0));
	vector<int> word(wordsize, 0);
	c = File.get();
	while ((c = File.get()) != EOF)
	{
		word[0] = (int)c - 97;

		for (int i = 1; i < wordsize; i++)
		{
			c = File.get();
			word[i] = (int)c - 97;
		}
		c = File.get();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				c = File.get();
				kubiki[i][j] = (int)c - 97;
			}
			c = File.get();
		}
	}


	for (int i = 2; i < wordsize+ 2; i++)
	{
		Graf[0][i] = 1;
		Graf[i][0] = 1;
	}


	for (int i = wordsize + 2; i < sizeGraf; i++)
	{
		Graf[1][i] = 1;
		Graf[i][1] = 1;
	}


	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int c = 0; c < 6; c++)
			{
				if (word[i] == kubiki[j][c])
				{
					Graf[i + 2][j + wordsize + 2] = 1;
					break;
				}
			}
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

void Ford_Falkerson(const char* path)
{
	int wordlen = 0;
	int res = 0;
	vector<vector<int>> Graf = Read_and_make_graf(wordlen,path);
	vector<int>oneway = OneIteration(Graf);
	int er = 0;
	while (1)
	{
		if (oneway[0] == -99)
			break;
		int i = 1;
		while (i != 0)
		{
			Graf[oneway[i]][i] -= 1;
			Graf[i][oneway[i]] += 1;
			i = oneway[i];
		}
		res += 1;
		oneway = OneIteration(Graf);
		if ((oneway[0] == -99))
			break;
	}

	if (res == wordlen)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
