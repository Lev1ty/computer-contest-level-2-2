#include<iostream>
#include<string>
using namespace std;
string in, win, subparse;
int lowest, parse;
int main() {
	while (true)
	{
		subparse = "";
		int cnt = 1;
		bool neg = false;
		getline(cin, in);
		for (int i = 0; i < in.size(); i++)
		{
			if (in[i] == ' ')break;
			else subparse += in[i];
		}
		if (subparse.compare("Waterloo") == 0)break;
		for (int i = 0; i < in.size(); i++)
		{
			if (in[i] >= '0'&&in[i] <= '9')
			{
				parse += cnt*(in[i] - '0');
				cnt *= 10;
			}
			else if (in[i] == '-')
			{
				neg = true;
			}
		}
		if (neg) parse *= (-1);
		if (parse < lowest)
		{
			lowest = parse;
			win = subparse;
		}
	}
	cout << win << endl;
}