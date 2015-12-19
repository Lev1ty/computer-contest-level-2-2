//conceptually flawed?

#include<iostream>
using namespace std;
constexpr double cnvrt = (24 * 60) / (24 * 60 + 37 + (22.663 / 60));
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		double d, h, m;
		cin >> d >> h >> m;
		double val = d * 24 * 60 + h * 60 + m;
		val *= cnvrt;
		double rd = val / 24 * 60;
		double rh = (val - rd * 24 * 60) / 60;
		double rm = val - rd * 24 * 60 - rh * 60;
		cout << "Day " << rd << ", " << rh << ":" << rm << endl;
	}
}