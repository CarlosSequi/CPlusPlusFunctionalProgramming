#include <vector>
#include <fplus/fplus.hpp>
#include "exercise1.h"

using namespace std;

int main() {

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 1
	Exercise1 e1;

	const std::string input = "1,5,4,7,2,2,3";
	const auto parts = fplus::split(',', false, input);

	const auto nums =
		transform(e1.str_to_int, parts);

	const auto result =
		reduce(std::multiplies<int>(), 1, nums);

	std::cout << result << std::endl;

}