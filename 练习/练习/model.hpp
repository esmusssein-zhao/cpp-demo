#include <ostream>
#include <vector>

//vector���
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>&v)
{
	for(auto i : v)
		os << i << " ";
	return os;
}