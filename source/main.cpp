#include "JADE.h"
#include "SHADE.h"
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
	string algo_type = argv[10]; // JADE or SHADE
	transform(algo_type.begin(), // ���b! �ഫalgo_type�����j�g
		algo_type.end(),
		algo_type.begin(),
		toupper);

	if (func_id < 1 || func_id > 13)
	{
		cout << "Invalid function ID. Please enter a value between 1 and 13." << endl;
		return 1; // �����{��
	}

	bool archive_flag; 					// �O�_�ϥ� archive list A
	string a = argv[9];					// �O�_�ϥ� archive list A
	if (a == "0")
	{
		archive_flag = false;			// ���ϥ� archive list A
	}
	else if (a == "1")
	{
		archive_flag = true;			// �ϥ� archive list A
	}
	else
	{
		cout << "Invalid input for archive list A. Please enter 0 or 1." << endl;
		return 1; // �����{��
	}
	

	bool canrun = 0;

	while (canrun == 0)
	{
		canrun = 1;

		if (algo_type == "JADE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | iter = " << iter << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | mCR = " << mCR << " | mF = " << mF << " | c = " << c << " | p = " << p << " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
			algo_JADE algo;
			algo.RunALG(iter, dim, pop_size, mCR, mF, c, p, func_id, archive_flag);
		}
		else if (algo_type == "SHADE")
		{
			cout << "algo_type = " << algo_type << " | func_id = " << func_id << " | iter = " << iter << " | dim = " << dim << " | pop_size = " << pop_size <<
				" | mCR = " << mCR << " | mF = " << mF << " | MCR & MF size = " << c << " | p = " << p << " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
			algo_SHADE algo;
			algo.RunALG(iter, dim, pop_size, mCR, mF, c, p, func_id, archive_flag);
		}
		else
		{
			cout << "Invalid algorithm type. Please enter JADE or SHADE." << endl;
			canrun = 0; // ���ŦX����A���s��J
			continue; // ���L��e�j��A���s��J
		}
	}

}