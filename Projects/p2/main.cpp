#include <fplus/fplus.hpp>
using namespace std;

double str_to_int(const std::string& str)
{
	double result;
	istringstream(str) >> result;
	return result;
}

int main() {

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 1

	const std::string input = "1.3,5,4,7,2,2,3";
	const auto parts = fplus::split(',', false, input);

	const auto nums = fplus::transform(str_to_int, parts);

	const auto result = fplus::reduce(std::plus<double>(), 1, nums);

	std::cout << result << std::endl;

}