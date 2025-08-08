#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void FileOutput(
    const std::vector<double>& best_fit_record,
    const std::vector<std::vector<double>>& iter_fit_record,
    int func_id, int iter, int dim, int pop_size,
    double _mCR, double _mF, int H, double p,
    bool archive_flag, double avg_best_fit
) {
	// ===== �o�̥i�H�p�� run �ƶq =====
	int run = (int)iter_fit_record.size();        // �~�h�ƶq = run

	// ===== �b�o�̶�J�A���� .txt ���{���X =====
	// ��X�C run �B�檺�̨� fitness �� SHADE_fitness_func_iter_dim_archive_.txt
	ofstream output_file("SHADE_fitness_func" + to_string(func_id) + "_iter" + to_string(iter) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".txt", ios::out);
	if (!output_file) {
		cerr << "Error opening output file." << endl;
		return;
	}
	output_file << "SHADE | func_id = " << func_id << " | iter = " << iter << " | dim = " << dim << " | pop_size = " << pop_size
		<< " | mCR = " << _mCR << " | mF = " << _mF << " | MCR & MF size = " << H << " | p = " << p
		<< " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
	output_file << "Avg Best fitness: " << avg_best_fit << endl;
	for (int i = 0; i < run; ++i) {
		output_file << " | Best fitness run " << (i + 1) << ": " << best_fit_record[i] << endl;
	}
	output_file.close();

	// ��X��X���G�� SHADE_integrated_fitness.txt
	ofstream integrated_output("SHADE_integrated_fitness.txt", ios::app);
	if (!integrated_output) {
		cerr << "Error opening integrated output file." << endl;
		return;
	}
	integrated_output << "SHADE | func_id = " << func_id << "| iter = " << iter << " | dim = " << dim << " | pop_size = " << pop_size
		<< " | mCR = " << _mCR << " | mF = " << _mF << " | MCR & MF size = " << H << " | p = " << p
		<< " | w/o archive list = " << (archive_flag ? "true" : "false") << endl;
	integrated_output << "Avg Best fitness: " << avg_best_fit << endl;
	integrated_output.close();

	/* �X�� */
	// ��X�C run �B�檺 fitness �� SHADE_fitness_cvg.txt
	ofstream cvg_file("SHADE_fitness_cvg" + to_string(func_id) + "_iter" + to_string(iter) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".txt");
	if (!cvg_file) {
		cerr << "Error opening fitness convergence file." << endl;
		return;
	}

	// ����m��X�G�C�@�C�O iteration�A�欰�C run
	for (int t = 0; t < iter; ++t) {
		for (int r = 0; r < run; ++r) {
			cvg_file << iter_fit_record[r][t];
			if (r != run - 1) cvg_file << " ";
		}
		cvg_file << "\n";
	}
	cvg_file.close();

	// ===== �b�o�̶�J�A���� .plt ���{���X =====
	// ���� plot_SHADE.plt �e�X���Ĺ�
	ofstream plot_file("plot_SHADE_func" + to_string(func_id) + "_iter" + to_string(iter) + "_dim" + to_string(dim) + "_archive_" + (archive_flag ? "true" : "false") + ".plt");
	if (!plot_file) {
		cerr << "Error opening plot file." << endl;
		return;
	}
	plot_file << "set terminal pngcairo size 1200,600 enhanced font 'Verdana,10'\n";
	plot_file << "set output 'SHADE_cvg_plot" << "_func" << func_id << "_iter" << iter << "_dim" << dim << "_archive_" << (archive_flag ? "true" : "false") << ".png'\n";
	plot_file << "set title 'SHADE Convergence Plot" << " (f" << func_id << ", iter" << iter << ", dim" << dim << ", archive: " << (archive_flag ? "true" : "false") << ")'\n";
	plot_file << "set xlabel 'Iteration'\n";
	plot_file << "set ylabel 'Best Fitness'\n";
	plot_file << "set grid\n";
	plot_file << "set label 'Avg best fitness: " << avg_best_fit << "' at graph 0.02, graph 0.95 font ',10' tc rgb 'black'\n";
	plot_file << "set lmargin 10\n";
	plot_file << "set tmargin 5\n";
	plot_file << "plot ";
	for (int i = 2; i <= run + 1; ++i) {
		plot_file << "'SHADE_fitness_cvg" << to_string(func_id) << "_iter" << to_string(iter) << "_dim" << to_string(dim) << "_archive_" << (archive_flag ? "true" : "false") << ".txt' using :" << i
			<< " with lines title 'Run " << (i - 1) << "'";
		if (i != run + 1) plot_file << ", ";
	}
	plot_file << "\n";
	plot_file.close();
}
