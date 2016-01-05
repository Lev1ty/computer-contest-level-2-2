#include <iostream>
#include <string>
using namespace std;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	string s; cin >> s;
	string r = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			r += s[i];
		}
		else
		{
			r += s[i];

			int pos = alpha.find(s[i]);
			for (int i = pos, j = pos; ; --i, ++j)
			{
				if (i >= 0 && (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u'))
				{
					pos = i;
					break;
				}
				else if (j < alpha.length() && (alpha[j] == 'a' || alpha[j] == 'e' || alpha[j] == 'i' || alpha[j] == 'o' || alpha[j] == 'u'))
				{
					pos = j;
					break;
				}
			}
			r += alpha[pos];

			int j = alpha.find(s[i]);
			j = (j == 25 ? j : j + 1);
			while (alpha[j] == 'a' || alpha[j] == 'e' || alpha[j] == 'i' || alpha[j] == 'o' || alpha[j] == 'u')
			{
				++j;
			}
			r += alpha[j];
		}
	}
	cout << r << endl;
}