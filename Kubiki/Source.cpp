#include"Header.h"
#include<sstream>
void Test(int x)
{
	string realres;
	double t;
        ifstream f;
	std::string path;
	ostringstream ss;
	ss<<"tests/test"<<x<<".in";
	path = ss.str();
	t = clock();
	Ford_Falkerson(path.c_str());
	t = clock() - t;
	ss.str("");
	ss << "tests/test" << x << ".out";
	path = ss.str();
	f.close();
	f.open(path.c_str());
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << t / 1000 << endl << endl << endl;
}

int main()
{
	for(int i=1;i<9;i++)
	Test(i);
}
