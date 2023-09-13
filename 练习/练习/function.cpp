#include "function.h"
#include<algorithm>

//std::vector<int> selectNumber(const int groupNumber, const int groupMember)
//{
//	srand(unsigned(time(0)));
//	std::vector<int> number;
//	for (int i = 1; i < groupNumber * groupMember+1; i++)
//	{
//		number.push_back(i + base);
//	}
//	random_shuffle(number.begin(), number.end());
//	return number;
//}

std::vector<int>& selectNumber(std::vector<int>&number)
{
	srand(unsigned(time(0)));
	random_shuffle(number.begin(), number.end());
	return number;
}

std::map<int, Player>& match(const int groupNumber, const int groupMember)
{
	std::vector<int> orderNmber;
	for (int i = 1; i < groupNumber * groupMember + 1; i++)
	{
		orderNmber.push_back(i + base);
	}
	auto& unOrderNumber = selectNumber(orderNmber);
	std::map<int, Player> matchMember;
	
}