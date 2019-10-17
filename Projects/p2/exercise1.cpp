#include <vector>
#include <fplus/fplus.hpp>
#include <string>

class Exercise1{

	int str_to_int(const std::string& str)
	{
		int result;
		std::istringstream(str) >> result;
		return result;
	}

};