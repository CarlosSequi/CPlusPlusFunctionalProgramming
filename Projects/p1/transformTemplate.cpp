#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double square(double x)
{
	return x * x;
}

// template para el uso de la funcion de transformacion
// de un vector a otro con cualquier tipo de elemento
template<typename F, typename T>
vector<T> transform_vector(F functionToApply, const vector<T> & vectorToTransform)
{
	vector<T> newVector;
	newVector.reserve(vectorToTransform.size());
	transform(begin(vectorToTransform), end(vectorToTransform), back_inserter(newVector), functionToApply);
	return newVector;
}

int main()
{
	vector<double> v{ 1,4,10.1 };
	vector<double> vTransformed = transform_vector(square, v);
	cout << vTransformed[1] << endl;

	return 0;
}