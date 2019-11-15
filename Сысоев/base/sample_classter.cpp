#include "TClasster.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int QueueSize;
	cout << "Enter size queue " << endl;
	cin >> QueueSize;

	int CntProc;
	cout << "Enter count of processor " << endl;
	cin >> CntProc;

	int  Tact;
	cout << "Enter count of Tact " << endl;
	cin >> Tact;

	double  ProcIntensity;
	cout << "Enter processor intensity " << endl;
	cin >> ProcIntensity;

	TClasster classter;
	classter.StartNewJob(QueueSize, CntProc, Tact, ProcIntensity);

	cout << "Count Generation Tasks " << classter.GetGenerationTasks() << endl;
	cout << "Count Filled Tasks " << classter.GetCountCompleteTask() << endl;
	cout << "Count Unfulfilled Tasks " << classter.GetCountNotCompleteTask() << endl;
	cout << "Count Tasks Error " << classter.GetCountTaskError() << endl;
	cout << "Average Load Proc " << classter.GetAverageLoadProc() << endl;

	system("pause");
	return 0;
}