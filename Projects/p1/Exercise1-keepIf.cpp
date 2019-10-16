#include <fplus/fplus.hpp>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool is_even(int x)
{
	return x % 2 == 0;
}


// en el typename del container lo hacemos
// asi en lugar de "typename vector<T>"
// porque de esta forma tambien podemos
// usarlo para distintos tipos de contenedores
// (listas por ejemplo)
template<typename F, typename container>
container keep_if(F function, const container & v)
{
	container newContainer;
	for (const auto x : v)
	{
		if (is_even(x))
			newContainer.push_back(x);
	}

	return newContainer;
}

int main()
{
	vector<int> xs = { 0,1,2,3,4 };
	const auto ys = keep_if(is_even, xs);
	cout << (ys == vector<int>({ 0,2,4 })) << endl;
	//assert(ys == std::vector<int>({ 0,2,4 })); // es "lo mismo" que comprobar con el if si son iguales


}
