#include "Player.h"
#include "model.hpp"
#include <algorithm>


Player::Player()
{
	srand((unsigned)time(NULL));
	int iRange1 = 0xf7 - 0xb0;
	int iRange2 = 0xfe - 0xa1;
	char iCode1 = rand() % iRange1 + 0xb0;
	char iCode2 = rand() % iRange2 + 0xa1;
	char surname[3] = { iCode1,iCode2,0 };
	std::string Name = "小" + static_cast<std::string>(surname);
	this->name = Name;
	this->addition = "null";
}

Player::Player(std::string Name)
{
	this->name = Name;
	this->addition = "null";
}

Player::Player(std::string Name, std::string Addition)
{
	this->name = Name;
	this->addition = Addition;
}

void Player::getInfor()
{
	std::cout << "姓名：" << name << '\t' << "成绩：" << score << '\t' << "备注：" << addition << std::ends;
}

void Player::getScore()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		score.push_back(rand() % 100);
	}
	std::sort(score.begin(), score.end());
}

double Player::finalScore()
{
	double sum = 0;
	score.pop_back();
	score.erase(score.begin());
	for(auto a:score)
		sum += a;
	return sum / score.size();
}
