#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int minDist, maxDist; cin >> minDist >> maxDist;
	int numLines; cin >> numLines;
	vector<int> hotels = {
		0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000
	};
	for (int i = 0; i < numLines; ++i) {
		int hotel; cin >> hotel;
		for (int i = 1; i < hotels.size(); ++i)
			if (hotel>=hotels.at(i-1)&&hotel<=hotels.at(i))
				hotels.insert(hotels.begin() + i, hotel);
	}
	for_each(hotels.begin(), hotels.end(), [](auto&a) {cout << a << ' ';});
}