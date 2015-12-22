#include<iostream>
using namespace std;
int main()
{
	int N; cin >> N;
	for (int i = 0, y, m, d; i < N; ++i)
	{
		cin >> y >> m >> d;
		if ((y < 1989) || (y == 1989 && m <= 2 && d <= 27))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}