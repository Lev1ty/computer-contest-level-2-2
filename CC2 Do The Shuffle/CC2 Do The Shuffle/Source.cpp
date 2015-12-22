#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int b, n;
	vector<char>c = { 'A','B','C','D','E' };
	do
	{
		cin >> b >> n;
		switch (b)
		{
		case 1:
			for (int i = 0; i < n; ++i)
			{
				char t = c.front();
				c.erase(c.begin());
				c.push_back(t);
			}
			break;
		case 2:
			for (int i = 0; i < n; ++i)
			{
				char t = c.back();
				c.insert(c.begin(), t);
				c.pop_back();
			}
		case 3:
			for (int i = 0; i < n; ++i)
			{
				char f = c.front();
				c.erase(c.begin());
				char l = c.front();
				c.erase(c.begin());
				c.insert(c.begin(), f);
				c.insert(c.begin(), l);
			}
		default:
			break;
		}
	} while (b != 4);
	for (char& ch : c)
	{
		cout << ch << ' ';
	}
	cout << endl;
}