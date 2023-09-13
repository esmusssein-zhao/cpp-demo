#pragma once
#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
	Player();
	Player(std::string Name);
	Player(std::string Name,std::string Addition);
	void getInfor();
	void getScore();
	double finalScore();
private:
	std::string name;
	std::string addition;
	std::vector<double> score;
};