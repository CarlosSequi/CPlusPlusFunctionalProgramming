#include <fplus/fplus.hpp>
#include <cmath>

using namespace std;
using namespace fplus;

typedef std::pair<float, float> point;
typedef std::pair<point, point> edge;
typedef std::vector<point> points;


template <typename ValOut, typename F, typename Key, typename ValIn>
std::map<Key, ValOut> lift_dict(F f, const std::map<Key, ValIn>& dict)
{
	map<Key, ValOut> result;
	for (const auto& key_and_val : dict)
	{
		result[key_and_val.first] = f(key_and_val.second);
	}
	   
	return result;
}

int main() {

	// Exercise:
	//     write lift_dict as a function template on your own
	//     and test it with the following code.

	// lift_dict : ((a -> b), Map key a) -> Map key b

	std::map<int, double> dict ={ {2, 1.41}, {3, 1.73}, {4, 2.0} };
	auto dict_squared = lift_dict<double>(square<double>, dict);
	auto dict_shown = lift_dict<std::string>(show<double>, dict);
	std::cout << show_cont(dict_squared) << std::endl;
	std::cout << show_cont(dict_shown) << std::endl;


	return 0;
}