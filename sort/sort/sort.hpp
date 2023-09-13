template<typename A>
void my_swap(A& lhs, A& rhs)
{
	A temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<typename T>
std::string Ascending_order(const std::vector<T>& vec)
{
	for (int i = 0; i < vec.size() - 2; i++)
	{
		if(vec[i]>vec[i+1])
			return "false";
	}
	return "true";
}

template<typename T>
std::vector<T>& Select_sort(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size()-1; i++)
	{
		for (int j = i + 1; j < vec.size()&& vec[i] > vec[j]; j++)
			my_swap(vec[i], vec[j]);
	}
	return vec;
}

template<typename B>
std::vector<B>& Bubble_sort(std::vector<B>& vec)
{
	for (int i = vec.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i-1&& vec[j] > vec[j + 1]; j++)
			my_swap(vec[j], vec[j+1]);
	}
	return vec;
}

template<typename C>
std::vector<C>& Insert_sort(std::vector<C>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = i - 1; j >= 0&& vec[j + 1] < vec[j]; j--)
			my_swap(vec[j + 1], vec[j]);
	}
	return vec;
}