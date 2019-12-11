#include"Header.h"


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
	for(int i=1;i<=6;i++)
		Test(i);	
}
