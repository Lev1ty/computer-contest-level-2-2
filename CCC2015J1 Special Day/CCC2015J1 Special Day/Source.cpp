#include <iostream>
using namespace std;
int main()
{
	int m, d;
	cin >> m >> d;
	if (m > 2)
	{
		cout << "After" << endl;
	}
	if (m < 2)
	{
		cout << "Before" << endl;
	}
	if (m == 2)
	{
		if (d > 18)
		{
			cout << "After" << endl;
		}
		if (d < 18)
		{
			cout << "Before" << endl;
		}
		if (d == 18)
		{
			cout << "Special" << endl;
		}
	}
}