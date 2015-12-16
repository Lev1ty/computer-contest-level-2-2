#include<iostream>
using namespace std;
int brown_trout, northern_pike, yellow_pickerel, total, counter;
int main() {
	cin >> brown_trout >> northern_pike >> yellow_pickerel >> total;
	for (int a = 0; a <= total / brown_trout; a++)
		for (int b = 0; b <= total / northern_pike; b++)
			for (int c = 0; c <= total / yellow_pickerel; c++)
				if (a + b + c != 0 && a*brown_trout + b*northern_pike + c*yellow_pickerel <= total&&++counter > 0)
					cout << a << " Brown Trout, " << b << " Northern Pike, " << c << " Yellow Pickerel" << endl;
	cout << "Number of ways to catch fish: " << counter << endl;
}