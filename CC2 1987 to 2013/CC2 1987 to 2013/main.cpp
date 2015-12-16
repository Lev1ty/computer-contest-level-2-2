#include <iostream>
//#define PLACE_VALUE(a) (a==10000?5:a>=1000?4:a>=100?3:a>=10?2:a>=1?1:0)

int Y;

int main()
{
	std::cin >> Y;
	int tempY = Y;
	int digitY = Y % 10;
	int ndigitY = (Y / 10) % 10;
	while (tempY>0)
	{
		int temptempY = tempY;
		while (digitY==ndigitY)
		{
			int ndigitY = (temptempY / 10) % 10;
			if (temptempY /= 10 > 0);
			Y++;
		}
		tempY /= 10;
	}
	std::cout << Y << std::endl;
}