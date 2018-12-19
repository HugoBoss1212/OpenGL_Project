#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>


class Matrix {
private:
	int size;
	double det_m;
	std::vector<std::vector<double>> matrix;
	std::vector<std::vector<double>> inversedMatrix;

public:
	Matrix(int size);
	~Matrix();

	void printMatrix();
	double det(std::vector<std::vector<double>> m);
	std::vector<std::vector<double>> inverseMatrix();
	std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> m);
	std::vector<std::vector<double>> cofactor(std::vector<std::vector<double>> m);
	std::vector<std::vector<double>> minor(int deleteRow, int deleteCol, std::vector<std::vector<double>> m);
};
