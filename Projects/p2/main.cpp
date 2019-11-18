#include <fplus/fplus.hpp>
#include <cmath>

typedef std::pair<float, float> point;
typedef std::pair<point, point> edge;
typedef std::vector<point> points;

struct user
{
	std::string name;
	std::string country;
	std::size_t visits;
};

std::string get_country(const user& u)
{
	return u.country;
}

std::size_t get_visits(const user& u)
{
	return u.visits;
}

const auto visit_sum = [](const std::vector<user>& xs) -> std::size_t
{
	return fplus::fwd::apply(xs
		, fplus::fwd::transform(get_visits)
		, fplus::fwd::sum());
};

double str_to_int(const std::string& str)
{
	double result;
	istringstream(str) >> result;
	return result;
}

double str_to_double(const std::string& str)
{
	double result;
	std::istringstream(str) >> result;
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
	/*vector<point> polygon = { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };
	const auto result = fplus::maximum_on(
		edge_length,
		get_edges(polygon));
	cout << fplus::show(result) << endl; */



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 4
	/*std::vector<std::vector<int>> xss = { {0,1,2}, {3,4,5} };*/

	// Exercise a:
//     Square every inner value of xss, so
//     {{0,1,2}, {3,4,5}}
//     turns into
//     {{0,1,4}, {9,16,25}}
//     Try out different possibilities to achieve your goal.

	// el transform externo recibe una funcion y un contenedor.
	// el transform interno es de fwd (forward), por lo que toma el contenedor
	// del transform externo y se lo aplica a la funcion que recibe, el square.
	// hay dos transform debido a que el contenedor es un vector de vectores.
	// el square tiene un <int> siguiendo la notación std::function<return(parameter)>
	/*fplus::transform(fplus::fwd::transform(fplus::square<int>), xss);*/

	// Exercise b:
	//     Use nested lambda expressions
	//     to make a fully curried version of add_four.
	//     add_four (Int, Int, Int, Int) -> Int
	//     add_four_curried : Int -> Int -> Int -> Int -> Int
	//     so that
	//     add_four(1,2,3,4)
	//     means the same as
	//     add_four_curried(1)(2)(3)(4)

	/*const auto add_four_curried = [](int a)
	{
		return [a](int b)
		{
			return [a, b](int c)
			{
				return [a, b, c](int d)
				{
					return (a + b + c + d);
				};
			};
		};
	};

	add_four_curried(1)(2)(3)(4);*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 5
	/*vector<point> polygon = { {1,2}, {7,3}, {6,5}, {4,4}, {2,9} };*/

	/*const auto result = fplus::maximum_on(
		edge_length,
		get_edges(polygon));*/

	// exercise a
	//     Rewrite the the longest-edge code
//     in forward-application style.
	/*const auto result = fplus::fwd::apply(polygon,
		get_edges,
		fplus::fwd::maximum_on(edge_length));*/

	// exercise b
	//     Invent a quite long chain of function applications,
//     at least 5 functions,
//     and implement its application to an input value
//     in all three styles:
//         1) Assign intermediate values to variables.
		/*	int a = 3;
			int b = fplus::square(a);
			int c = fplus::min_2(2, b);
			int d = fplus::abs_diff(7, c);
			int e = fplus::clamp(1, 4, d);
			int f = fplus::max_2(6, e);
			std::cout << f << std::endl;
//         2) Nested function calls
			int f_nested = fplus::max_2(6,
				fplus::clamp(1, 4,
					fplus::abs_diff(7,
						fplus::min_2(2,
							fplus::square(a)))));
			std::cout << f_nested << std::endl;
//         3) Foward-application style
			int f_fwd = fplus::fwd::apply(a
				, fplus::fwd::square()
				, fplus::fwd::min_2(2)
				, fplus::fwd::abs_diff(7)
				, fplus::fwd::clamp(1, 4)
				, fplus::fwd::max_2(6));
			std::cout << f_fwd << std::endl;
//     Compare all three versions and contemplate
//     the readability of all of them.

	cout << fplus::show(result) << endl;*/

	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	// EXERCISE 6
	/*const std::vector<user> users = {
		{"Nicole", "GER", 2},
		{"Justin", "USA", 1},
		{"Rachel", "USA", 5},
		{"Robert", "USA", 6},
		{"Stefan", "GER", 4}
	};*/

	// SELECT country, SUM(visits)
	//     FROM users
	//     GROUP BY country;

	// Exercise:
//     Implement the task solved by the SQL query above
//     in C++ using the following fplus functions:
//     - group_globally_on_labeled
//     - transform_snd
//     - mean
//     Look them up in the API search,
//     and understand the type signatures.

	// primero agrupa por paises con el group globally
	// aplica la transformacion_snd para hacer la sumatoria de las visitas a cada pais
	// aplica el transform externo por que users es un vector de structs
	/*const auto result = fplus::fwd::apply(users,
		fplus::fwd::group_globally_on_labeled(get_country),
		fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum))
		);

	std::cout << fplus::show_cont(result) << std::endl;*/

	// Bonus Exercise:
//     The run-time complexity of your algorithm will be O(n^2),
//     due to using group_globally_on_labeled.
//     But Strings form a partially ordered set.
//     See if you can get down to O(n*log(n))
//     by using sort and group_on_labeled.
	/*const auto result_n_log_n = fplus::fwd::apply(users
		, fplus::fwd::sort_on(get_country)
		, fplus::fwd::group_on_labeled(get_country)
		, fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum))
	);*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
		// EXERCISE 7
		/*const std::string input = "1,5,4,7,2,2,3.34";

		const auto parse_and_product = fplus::fwd::compose(fplus::fwd::split(',', false), fplus::fwd::transform(str_to_double), fplus::fwd::product());

		const auto result = parse_and_product(input);

		std::cout << result << std::endl;*/

}



