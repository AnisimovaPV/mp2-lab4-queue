#include "TClasster.h"
#include <iostream>
#include <ctime>

TClasster::TClasster()
{
	CntGenerationTasks = 0;
	CntFulfilledTask = 0;
	CntUnfulfilledTask = 0;
	CntTaskError = 0;
	LoadProc = 0;
}

void TClasster::StartNewJob(int _size, int _Proc, int _tact,double _ProcIntensity)
{
	Proc = CntFreeProc = _Proc;
	Tact =  _tact; 
	ProcIntensity = _ProcIntensity;
	masProc = new int[Proc];
	for (int i = 0; i < Proc; i++)
	{
		masProc[i] = 0;
	}
	TQueue<Task> queue(_size);
	ProcessJob(queue);
}

void TClasster::ProcessJob(TQueue<Task> &queue)
{
	for (int i = 0; i < Tact; i++)
	{	
			Task Task;
				Task = TaskGeneration();
				if (Task.CntTacts != 0)
				{ 
					if (!queue.IsFull())
					{
						queue.Push(Task);
					}
					if (queue.IsFull())
					{
						CntTaskError++;
					}
				}			
				if (!queue.IsEmpty())
				{
					int CountProc = queue.GetTop().CntProc;
					int CountTact = queue.GetTop().CntTacts;
					int ChangeCountProc = CountProc;

					if ( (CntFreeProc >= CountProc))
					{
						for (int i = 0; i < Proc; i++)
						{
							if ((masProc[i] == 0) && (ChangeCountProc > 0))
							{
								masProc[i] = CountTact + 1;
								ChangeCountProc--;
							}
						}
						CntFreeProc -= CountProc;
						queue.Pop();
					}
				}
			for (int i = 0; i < Proc; i++)
			{
				if (masProc[i] > 0)
				{
					masProc[i]--;
					if (masProc[i] == 0)
					{
						CntFreeProc++;
					}
				}
			}
			LoadProc += (Proc - CntFreeProc);
	}
	CntUnfulfilledTask = queue.GetLenght();
}

Task TClasster::TaskGeneration()
{
	Task cl;
	srand((unsigned int)time(NULL));
	double pr = (rand() % 9 + 1)/10.0;
	if (pr < ProcIntensity)
	{
		srand((unsigned int)time(NULL));
		cl.CntProc = rand() % (Proc)+1;
		cl.CntTacts = rand() % 9 + 1;
		CntGenerationTasks++;
	}
	else
		cl.CntProc = cl.CntTacts = 0;	
	return cl;
}

int TClasster::GetGenerationTasks()
{
	return CntGenerationTasks;
}
int TClasster::GetCountCompleteTask()
{
	CntFulfilledTask = CntGenerationTasks - (CntUnfulfilledTask + CntTaskError);
	return CntFulfilledTask;
}

int TClasster::GetCountNotCompleteTask()
{
	return CntUnfulfilledTask;
}

int TClasster::GetCountTaskError()
{
	return CntTaskError;
}

int TClasster::GetAverageLoadProc()
{
	return LoadProc / Tact + 1;
}