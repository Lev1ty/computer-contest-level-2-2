#include <iostream>
#include <string>
using namespace std;
const char icon[3][3] = {
	{'*','x','*'},
	{' ','x','x'},
	{'*',' ','*'}
};
int main()
{
	int scl; cin >> scl;
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < scl; ++b)
		{
			for (int c = 0, d; c < 3 * scl; ++c)
			{
				d = c / scl;
				cout << icon[a][d];
			}
			cout << endl;
		}
	}
}