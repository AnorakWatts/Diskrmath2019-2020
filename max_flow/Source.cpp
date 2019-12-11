#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include <queue>

using namespace std;

vector<vector<int>> ReadGraff(const char* path)
{
        int size;
        ifstream h(path);
        h >> size;
        vector<vector<int>>a(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++)
        {
                for (int j = 0; j < size; j++)
                {
                        h >> a[i][j];
                }
        }
	h.close();

        return a;
}

vector<int>OneIteration(vector<vector<int>>v)
{
        int now;
        vector<int> tags(v.size(),-1);
        tags[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
                now = q.front();
                q.pop();
                for (int i = 1; i < v.size(); i++)
                {
                        if ((v[now][i])&&(tags[i]==-1))
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

int Ford_Falkerson(const char*path)
{
        int smalestonway=1;
        vector<vector<int>> Graff=ReadGraff(path);
        vector<vector<int>> resGraff(Graff.size(),vector<int>(Graff.size(),0));
        vector<int>oneway = OneIteration(Graff);
        while (smalestonway)
        {
                int i = 1;
                smalestonway = Graff[oneway[i]][i];
                while (i != 0)
                {
                        if (Graff[oneway[i]][i] < smalestonway)
                        {
                                smalestonway = Graff[oneway[i]][i];
                        }
                        i = oneway[i];
                }
                i = 1;
                while (i != 0)
                {
                        Graff[oneway[i]][i] -= smalestonway;
                        Graff[i][oneway[i]] += smalestonway;
                        resGraff[oneway[i]][i] += smalestonway;
                        resGraff[i][oneway[i]] -= smalestonway;
                        i = oneway[i];
                }

                oneway = OneIteration(Graff);
                if ((oneway[0] == -99))
                        break;
        }
        int res=0;
        for (int i = 0; i < Graff.size(); i++)
        {
                res += resGraff[i][1];
        }

        return res;
}

void Test(int x)
{
	unsigned long long int realres,myres;
	double t;
        ifstream f;
	std::string path;
	ostringstream ss;
	ss<<"test/test"<<x<<".in";
	path = ss.str();
	t = clock();
	myres = Ford_Falkerson(path.c_str());
	t = clock() - t;
	cout << "My res " << x << ": " << myres;
	ss.str("");
	ss << "test/test" << x << ".out";
	path = ss.str();
	f.close();
	f.open(path.c_str());
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << t / 1000 << endl << endl << endl;
	if (realres != myres)
		cout << endl << endl << "WROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONG" << endl << endl;
}

int main()
{
	for(int i=1;i<9;i++)
	Test(i);
}
