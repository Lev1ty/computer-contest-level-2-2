#include<iostream>
using namespace std;
int main() {
	int w; double h;
	cin >> w >> h;
	double d = w / (h*h);
	if (d > 25) cout << "Overweight" << endl;
	else if (d <= 25 && d >= 18.5) cout << "Normal weight" << endl;
	else if (d < 18.5) cout << "Underweight" << endl;
}