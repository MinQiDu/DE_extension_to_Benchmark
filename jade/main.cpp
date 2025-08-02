#include "JADE.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	int iter = atoi(argv[1]);
	int dim = atoi(argv[2]);
	int pop_size = atoi(argv[3]);
	double mCR = atof(argv[4]); // adaptive parameter 1 (cross_rate)
	double mF = atof(argv[5]);  // adaptive parameter 2 (= F, donor_rate)
	double c = atof(argv[6]);   // adaptation rate c
	double p = atof(argv[7]);   // adaptation rate c and top % pop chosen for pbest
	int func_id = atoi(argv[8]);
	if (func_id < 1 || func_id > 13)
	{
		cout << "Invalid function ID. Please enter a value between 1 and 13." << endl;
		return 1; // �����{��
	}

	bool a_func; 				// �O�_�ϥ� archive list A
	string a = argv[9];			// �O�_�ϥ� archive list A
	if (a == "0")
	{
		a_func = false;			// ���ϥ� archive list A
	}
	else if (a == "1")
	{
		a_func = true;			// �ϥ� archive list A
	}
	else
	{
		cout << "Invalid input for archive list A. Please enter 0 or 1." << endl;
		return 1;				// �����{��
	}
	

	bool canrun = 0;

	while (canrun == 0)
	{
		cout << "algo_type = " << "JADE " << "| iter = " << iter << " | dim = " << dim << " | pop_size = " << pop_size << 
			" | mCR = " << mCR << " | mF = " << mF << " | c = " << c << " | p = " << p << " | func_id = " << func_id << " | w/o archive list = " << (a_func ? "true" : "false") << endl;
		canrun = 1;

		algo_JADE algo;
		algo.RunALG(iter, dim, pop_size, mCR, mF, c, p, func_id, a_func);
	}

}