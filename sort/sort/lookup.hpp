template<typename T>
bool binary_search(const std::vector<T>& vec,T find)
{
	int lhs = 0;
	int rhs = vec.size()-1;
	while (lhs < rhs)
	{
		int temp = (lhs + rhs) / 2;
		if (vec[temp] == find)
			return true;
		else if (vec[temp] > find)
			rhs = temp - 1;
		else
			lhs = temp + 1;
	}
	return false;
}

template<typename T>
int binary_more_and_same_left(const std::vector<T>& vec, T flag)
{
	int lhs = 0;
	int rhs = vec.size() - 1;
	int ret = -1;
	while (lhs <= rhs)
	{
		int temp = (rhs + lhs) / 2;
		if (vec[temp] >= flag)
		{ 
			ret = temp;
			rhs = temp-1;
		}	
		else
			lhs = temp+1;		
	}
	return ret;
}

template<typename T>
int binary_less_and_same_right(const std::vector<T>& vec, T flag)
{
	int lhs = 0;
	int rhs = vec.size() - 1;
	int ret = -1;
	while (lhs <= rhs)
	{
		int temp = (rhs + lhs) / 2;
		if (vec[temp] > flag)
			rhs = temp - 1;
		else
		{
			ret = temp;
			lhs = temp + 1;
		}	
	}
	return ret;
}