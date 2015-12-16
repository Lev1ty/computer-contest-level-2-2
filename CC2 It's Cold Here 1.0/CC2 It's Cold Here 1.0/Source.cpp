#include<iostream>
#include<string>
using namespace std;
string parse1, parse2, win;
int lowest, parse;
int main()
{
	while (true)
	{
		parse1 = "", parse2 = "";
		parse = 0;
		bool neg = false;
		cin >> parse1 >> parse2;
		if (parse1.compare("Waterloo") == 0)break;
		if (parse2[0] == '-')
		{
			neg = true;
			parse2.erase(parse2.begin());
		}
		int dig = parse2.size();
		int cnt = 1;
		for (int i = 0; i < dig - 1; i++)
		{
			cnt *= 10;
		}
		for (int i = 0; i < dig; i++)
		{
			parse += cnt*(parse2[i] - '0');
			cnt /= 10;
		}
		if (neg)parse *= -1;
		if (parse < lowest)
		{
			lowest = parse;
			win = parse1;
		}
	}
	cout << win <<endl;
}