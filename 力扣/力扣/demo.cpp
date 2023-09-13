#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
/*
每个 有效电子邮件地址 都由一个 本地名 和一个 域名 组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+' 。

例如，在 alice@leetcode.com中， alice 是 本地名 ，而 leetcode.com 是 域名 。
如果在电子邮件地址的 本地名 部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 不适用于域名 。

例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。
如果在 本地名 中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 不适用于域名 。

例如 m.y+name@email.com 将转发到 my@email.com。
可以同时使用这两个规则。

给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。返回实际收到邮件的不同地址数目。
*/
/*int numUniqueEmails(vector<string>& emails) 
{
	for (string& email : emails)//先删除“ + ”之后“@”之前，再去删除“.”，避免之后内容移动
	{
		size_t find_plus = email.find('+');
		if (find_plus != email.npos)//找到“+”
		{
			email.erase(find_plus,1);//删除“+”
			size_t find_at = email.find('@');
			email.erase(find_plus, find_at- find_plus); //删除“ + ”之后“@”之前
			size_t find_fullstop = email.find('.'); 
			while (find_fullstop < find_plus)//“+”Q前有“.”
			{
				email.erase(find_fullstop, 1);//删除“.”，email已经被修改
				find_fullstop = email.find('.');
			}	
		}
		else
		{
			size_t find_fullstop = email.find('.');
			size_t find_at = email.find('@');
			while (find_fullstop < find_at)
			{
				email.erase(find_fullstop, 1);
				find_fullstop = email.find('.');
			}
		}
	}
	map<string, int>total;
	for (string& email : emails)
	{
		total[email]++;
	}
	return total.size();
}*/
/*class Solution {
public:
	Solution(double radius, double x_center, double y_center):r(radius),x(x_center),y( y_center){}
	vector<double> randPoint() 
	{
		srand(time(NULL));
		double xx = rand() / RAND_MAX;
		while (1)
		{
			double yy = rand() / RAND_MAX;
			if(yy*yy<(r*r-xx*xx))
				return vector<double>{ x+xx, y+yy };
		}
		
	}
private:
	double x, y, r;
};*/
/*class Solution 
{
private:
	double x, y, r;
public:
	Solution(double radius, double x_center, double y_center):x(radius), y(x_center), r(y_center){}
	vector<double> randPoint() 
	{
		srand(time(NULL));
		while (true) 
		{
			double x1 = rand() * (2 * r) - r; 
			double y1 = rand() * (2 * r) - r; 
			if (x1 * x1 + y1 * y1 <= r * r) 
			{
				return vector<double>{ x1+x, y1+y };
			}
		}
	}
};*/
//int consecutiveNumbersSum(int n) 
//{
//	int flag = 1;
//	int count = 0;
//	while ((n - (flag - 1) / flag / 2) != 1)
//	{
//		int temp = n - (flag - 1) / flag / 2;
//		if (temp % flag == 0)
//		{
//			int first = temp / flag;
//			int total = 0;
//			for (int time = 1; time <= flag; time++)
//			{
//				total += first;
//				++first;
//				if (total < n)
//					continue;
//				if (total > n)
//					break;
//				if (total == n)
//				{
//					++flag;
//					++count;
//					break;
//				}
//			}
//		}
//		else
//			++flag;
//	}
//
//	return count;
//}
class Solution {
public:
	int myAtoi(string s)
	{
		int begin = s.find_first_of("+-123456789");
		int end = s.find_last_of("1234567890");
		int other = s.find_first_not_of(" +-1234567890");
		/*s.erase(0, begin);*/
		if (other < begin&&other!=-1)
		{
			return 0;
		}
		else 
		{
			string s1 = s.erase(end + 1).erase(0, begin);
			int num = stoi(s1);
			if (num >= INT_MIN && num <= INT_MAX)
			{
				return num;
			}
			else if (num > INT_MIN)
			{
				return INT_MIN;
			}
			else
				return INT_MAX;
		}
		}
};
int main()
{
	Solution a;
	cout << a.myAtoi("words and 987") << endl;
	/*int n = 5;
	cout << consecutiveNumbersSum(n);*/
	return 0;
}