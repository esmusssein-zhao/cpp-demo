#pragma once
#include <vector>
#include <iostream>
#include <map>
#include "Player.h"
static int base = 0;
//±ÈÈü
std::map<int, Player>& match(const int groupNumber,const int groupMember);
//Ñ¡ºÅ
//std::vector<int> selectNumber(const int groupNumber, const int groupMember);
std::vector<int>& selectNumber(std::vector<int>& number);
