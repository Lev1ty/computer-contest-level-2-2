#include <iostream>
#include <string>
using namespace std;
int main()
{
	//while (true)
	//{
		string s;
		getline(cin, s);
		//cout << s << endl;
		int sad = 0, happy = 0;
		if (s.length() <= 2)
		{
			goto PRINT;
			//cout << "goto" << endl;
		}
		for (int i = 0; i < s.length(); ++i)
		{
			string sub = s.substr(i, 3);
			if (sub.compare(":-(") == 0)
			{
				++sad;
				//cout << i << "s: " << sub << endl;
			}
			else if (sub.compare(":-)") == 0)
			{
				++happy;
				//cout << i << "h: " << sub << endl;
			}
		}
	PRINT:
		if (sad == 0 && happy == 0)
		{
			cout << "none" << endl;
		}
		else if (sad == happy)
		{
			cout << "unsure" << endl;
		}
		else if (sad > happy)
		{
			cout << "sad" << endl;
		}
		else
		{
			cout << "happy" << endl;
		}
	//}
}