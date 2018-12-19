#include "Matrix.h"

Matrix::Matrix(int size)
{
	this->size = size;
	this->matrix.resize(size);
	this->inversedMatrix.resize(size);

	for (int i = 0; i < size; i++) {
		this->matrix[i].resize(size);
		this->inversedMatrix[i].resize(size);
		for (int j = 0; j < size; j++) {
			this->matrix[i][j] = rand() % 10;
		}
	}

	this->det_m = det(this->matrix);
	this->inversedMatrix = inverseMatrix();
}

Matrix::~Matrix() 
{ 

}

void Matrix::printMatrix()
{
	std::cout << "Wyznacznik macierzy:\t" << this->det_m << std::endl;
	std::cout << "Macierz:\t" << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)	{
			std::cout << this->matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Macierz odwrocona:\t" << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << this->inversedMatrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<std::vector<double>> Matrix::inverseMatrix()
{
	std::vector<std::vector<double>> result;
	result = cofactor(this->matrix);
	result = transpose(result);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			result[i][j] = result[i][j] / this->det_m;
		}
	}

	return result;
}

double Matrix::det(std::vector<std::vector<double>> m) {
	if (m.size() == 1)
		return m[0][0];

	double sum = 0;
	int j = 0;

	for (int i = 0; i < (int)m.size(); i++) {
		sum += pow((double)(-1), (double)(i + j + 1)) * m[i][j] * det(minor(i, j, m));
	}

	return sum;

}

std::vector<std::vector<double>> Matrix::transpose(std::vector<std::vector<double>> m) {

	std::vector<std::vector<double>> result;
	result = m;

	for (int i = 0; i < (int)result.size(); i++) {
		for (int j = 0; j < (int)result.size(); j++) {
			result[j][i] = m[i][j];
		}
	}

	return result;

}

std::vector<std::vector<double>> Matrix::cofactor(std::vector<std::vector<double>> m) {

	std::vector<std::vector<double>> result;
	std::vector<double> row;

	double value;

	for (int i = 0; i < (int)m.size(); i++) {
		row.clear();
		for (int j = 0; j < (int)m.size(); j++) {
			value = pow((double)(-1), (double)(i + 1 + j)) * det(minor(i, j, m));
			row.push_back(value);
		}
		result.push_back(row);
	}

	return result;

}

std::vector<std::vector<double>> Matrix::minor(int deleteRow, int deleteCol, std::vector<std::vector<double>> m) {

	std::vector<std::vector<double>> result;
	std::vector<double> row;

	for (int i = 0; i < (int)m.size(); i++) {
		if (i == deleteRow) continue;

		row.clear();
		for (int j = 0; j < (int)m.size(); j++) {
			if (j == deleteCol) continue;

			row.push_back(m[i][j]);
		}
		result.push_back(row);
	}

	return result;

}