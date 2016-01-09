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
		hotels.push_back(hotel);
	}
	sort(hotels.begin(), hotels.end());
	vector<int> ways(hotels.size());
	ways.front() = 1;
	for (int i = 1; i < hotels.size(); ++i)
		for (int j = i - 1; j >= 0; --j)
			if (hotels.at(i) - hotels.at(j) >= minDist&&
				hotels.at(i) - hotels.at(j) <= maxDist)
				ways.at(i) += ways.at(j);
	/*for_each(ways.begin(), ways.end(), [](int& i) {cout << i << ' ';});
	cout << endl;
	for_each(hotels.begin(), hotels.end(), [](int& i) {cout << i << ' ';});
	cout << endl;*/
	cout << ways.back() << endl;
}