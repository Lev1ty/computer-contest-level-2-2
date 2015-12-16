#include<iostream>
using namespace std;
int angle1, angle2, angle3;
int main() {
	cin >> angle1 >> angle2 >> angle3;
	if (angle1 == 60 && angle2 == 60 && angle3 == 60)
		cout << "Equilateral";
	else if (angle1 + angle2 + angle3 == 180 && (angle1 == angle2 || angle2 == angle3 || angle3 == angle1))
		cout << "Isosceles";
	else if (angle1 + angle2 + angle3 == 180)
		cout << "Scalene";
	else
		cout << "Error";
}