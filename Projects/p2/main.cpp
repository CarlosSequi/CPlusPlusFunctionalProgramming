#include <fplus/fplus.hpp>

typedef std::pair<float, float> point;
typedef std::pair<point, point> edge;
typedef std::vector<point> points;

using namespace std;

double str_to_int(const std::string& str)
{
	double result;
	istringstream(str) >> result;
	return result;
}


float point_distance(const point& p1, const point& p2)
{
	const float dx = p2.first - p1.first;
	const float dy = p2.second - p1.second;
	return std::sqrt(dx * dx + dy * dy);
}

template <typename Cont>
Cont product(const Cont & nums)
{
	return fplus::reduce(std::multiplies<double>(), 1, nums);
}

template <typename Cont>
typename Cont::value_type sum(const Cont& xs)
{
	return fplus::reduce(std::plus<int>(), 1, xs);
}

vector<edge> get_edges(vector<point> polygon)
{
	return fplus::overlapping_pairs_cyclic(polygon);
}

float edge_length(const edge& e)
{
	return  point_distance(e.first, e.second);
}


int main() {

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 1

	/*const std::string input = "1.3,5,4,7,2,2,3";
	const auto parts = fplus::split(',', false, input);
	const auto nums = fplus::transform(str_to_int, parts);
	const auto result = fplus::reduce(std::plus<double>(), 1, nums);
	std::cout << result << std::endl;*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 2
//     Change the call to maximum_on
//     by using a lambda function
//     using point_distance internally,
//     so the code compiles and runs as intended.

	/*vector<point> polygon = { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };
	const auto edges = fplus::overlapping_pairs_cyclic(polygon);
	const auto calculatePointDistance = [](auto pair) {
		return point_distance(pair.first, pair.second);
	};
	const auto result = fplus::maximum_on( calculatePointDistance, edges);
	cout << fplus::show(result) << endl;*/

	// otra solucion:
	/*
	const auto result = fplus::maximum_on(
        [](const std::pair<point, point>& edge) -> float
        {
            return point_distance(edge.first, edge.second);
        }, edges);
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 3
//     Implement edge_length and get_edges functions
//     so the improved code from below works.
	vector<point> polygon = { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };
	const auto result = fplus::maximum_on(
		edge_length,
		get_edges(polygon));
	cout << fplus::show(result) << endl; 
}



