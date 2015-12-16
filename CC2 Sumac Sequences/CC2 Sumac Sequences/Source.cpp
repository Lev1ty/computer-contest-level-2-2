#include <iostream>
using namespace std;
int a, b, i = 2;
int term(int p, int q) {
	i++;
	int u = p - q;
	if (q < u)
		return i;
	p = q;
	q = u;
	if (u >= 0)
		term(p, q);
}
int main() {
	cin >> a >> b;
	int out = term(a, b);
	cout << out << endl;
}