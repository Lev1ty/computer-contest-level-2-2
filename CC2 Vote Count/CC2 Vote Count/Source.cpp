//#include<iostream>
//#define VOTE(a) (a=='A'?true:false)
//#define MAX(a,b,c) (a==b?c:a>b?a:b)
//using namespace std;
//int V, A, B;
//bool which;
//int main() {
//	cin >> V;
//	for (int i = 0;i < V; i++) {
//		which = VOTE(getchar());
//		which ? A++ : B++;
//	}
//	//cout << A << " " << B << endl;
//	cout << (MAX(A, B, 0) == 0 ? "Tie" : MAX(A, B, 0)? "B" : "A") << endl;
//}

#include<iostream>
#include<string>
using namespace std;
int a, b;
string s, i;
int main() {
	getline(cin, i);
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') a++;
		else if (s[i] == 'B') b++;
	}
	//cout << A << " " << B << endl;
	cout << ((a == b) ? "Tie" : ((a > b) ? "A" : "B")) << endl;
}