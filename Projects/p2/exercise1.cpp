#include "exercise1.h"
#include <fplus/fplus.hpp>

	int Exercise1::str_to_int(const std::string& str)
	{
		int result;
		istringstream(str) >> result;
		return result;
	}