#include <iostream>
using namespace std;
int main()
{
	int lim, spd;
	cin >> lim >> spd;
	if (spd<=lim)
	{
		cout << "Congratulations, you are within the speed limit!" << endl;
	}
	else
	{
		cout << "You are speeding and your fine is $";
		if (spd<=lim+20)
		{
			cout << "100." << endl;
		}
		else if (spd<=lim+30)
		{
			cout << "270." << endl;
		}
		else
		{
			cout << "500." << endl;
		}
	}
}