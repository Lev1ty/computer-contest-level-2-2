#include <iostream>
#include <string>
using namespace std;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	int a; cin >> a;
	string b; cin >> b;
	for (int i = 0, pos; i < b.length(); ++i)
	{
		for (int j = 0; j < alpha.length(); ++j)
		{
			if (b[i] == alpha[j])
			{
				pos = j;
			}
		}
		pos -= (3 * (i + 1) + a);
		pos < 0 ? pos = 26 + pos : pos;
		cout << alpha[pos];
	}
}