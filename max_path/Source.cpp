#include"Header.h"
#include<ctime>
void Megatest()
{
	int realres;
	ifstream f;
	double t = clock();
	cout << "My res 1: " << Ford_Falkerson("test/test1.in");
	f.open("test/test1.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;
	
	t = clock();
	cout << "My res 2: " << Ford_Falkerson("test/test2.in");
	f.open("test/test2.out");
	f >> realres;
	cout << "\t Real: " << realres<<endl;
	f.close();
	cout << endl <<"Time in sec: "<< (clock() - t) / 1000 << endl<<endl<<endl;

	t = clock();
	cout << "My res 3: " << Ford_Falkerson("test/test3.in");
	f.open("test/test3.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;

	t = clock();
	cout << "My res 4: " << Ford_Falkerson("test/test4.in");
	f.open("test/test4.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;

	t = clock();
	cout << "My res 5: " << Ford_Falkerson("test/test5.in");
	f.open("test/test5.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;

	t = clock();
	cout << "My res 6: " << Ford_Falkerson("test/test6.in");
	f.open("test/test6.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;

	t = clock();
	cout << "My res 7: " << Ford_Falkerson("test/test7.in");
	f.open("test/test7.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t) / 1000 << endl << endl << endl;

	t = clock();
	cout << "My res 8: " << Ford_Falkerson("test/test8.in");
	f.open("test/test8.out");
	f >> realres;
	cout << "\t Real: " << realres << endl;
	f.close();
	cout << endl << "Time in sec: " << (clock() - t)/1000 << endl << endl << endl;

}


int main()
{
	Megatest();
}