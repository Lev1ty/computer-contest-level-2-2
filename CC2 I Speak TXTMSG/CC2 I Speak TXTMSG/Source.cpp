#include<iostream>
#include<string>
using namespace std;
int main()
{
	const string t[12] = { "CU",":-)",":-(",";-)",":-P","(~.~)","TA","CCC","CUZ","TY","YW","TTYL" };
	const string T[12] = {
		"see you","I'm happy","I'm unhappy","wink","stick out my tongue","sleepy","totally awesome",
		"Canadian Computing Competition","because","thank-you","you're welcome","talk to you later"
	};
	string in;
	do
	{
		cin >> in;
		bool flag = true;
		for (int i = 0; i < 12; ++i)
		{
			if (in.compare(t[i]) == 0)
			{
				flag = false;
				cout << T[i] << endl;
				break;
			}
		}
		if (flag) cout << in << endl;
	} while (in.compare("TTYL") != 0);
}