#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<utility>
#define MAX(a,b) (a>b?a:b)
//int imax = INT_MAX;
using namespace std;
namespace dec_5_n {
	vector<char>input;
	vector<bool>vis;
	char in;
	int bra = 2, exp_ = 0, div_ = 0, mul = 0, add = 0, sub = 0;
	double result = 0;
	bool positive = true;
	pair<int, int>b_pos;
	int search_pos(char c) {
		using namespace dec_5_n;
		for (int i = 0; i < input.size(); i++)
			if (input[i] == c&&!vis[i])
				return i;
	}
	bool is_op(char c) {
		switch (in)
		{
		case'(':case')':case'^':case'/':case'*':case'+':case'-':return true;
		default:return false;
		}
	}
	inline int pwr_ten(char u, int v) {
		int n = (int)(u - '0');
		for (int i = 0; i < v; i++)
			n *= 10;
		return n;
	}
}
namespace calulator_n {
	int a, b;
	char op;
	inline void exponent(int&a, int b) {
		int t = a;
		for (int i = 1; i < b; i++)
			a *= t;
	}
	inline void factorial(int&a) {
		if (a == 0) a = 1;
		else for (int i = a - 1; i > 0; i--)
			a *= i;
	}
}
namespace class_n {
	enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	Month int_to_month(int x) {
		if (x<int(Month::jan) || int(Month::dec) < x)cout << "error" << endl;
		return Month(x);
	}
	Month operator++(Month&m) {
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}
	class Year
	{
		static constexpr int min = 1800;
		static constexpr int max = 2200;
	public:
		Year(int y);
		~Year();
		class Invalid {};
		int year() { return y; }
	private:
		int y;
	};
	Year::Year(int y) :y{ y }
	{
		if (y<min || y>max)throw Invalid{};
	}
	Year::~Year()
	{
	}
	class Date
	{
	public:
		class Invalid {};
		Date(Year y, Month m, int d);
		~Date();
		void Date::print() { cout << (int)m << ' ' << d << ' ' << y.year() << ' '; }
		int Date::year() { return y.year(); }
		int Date::month() { return static_cast<int>(m); }
		int Date::day() { return d; }
	private:
		int d;
		Month m;
		Year y;
		bool Date::is_valid() {
			if ((int)m < 1 || (int)m>12 || y.year() < 0 || d < 0 || d>31)return false;
			return true;
		}
	};
	Date::Date(Year y, Month m, int d) :y{ y.year() }, m{ m }, d{ d }
	{
		if (!is_valid())throw Invalid{};
	}
	Date::~Date()
	{
	}
}
namespace dec_6_n {
	vector<vector<int>>test;
	typedef vector<int> row;
	vector<row>adj;
	row adj_r;
}
void dec_5(){
	using namespace dec_5_n;
	input.push_back('(');
	while (cin >> in) {
		input.push_back(in);
		vis.push_back(false);
		switch (in)
		{
		case'(':++bra;break;
		case'^':++exp_;break;
		case'/':++div_;break;
		case'*':++mul;break;
		case'+':++add;break;
		case'-':++sub;break;
		default:
			break;
		}
	}
	input.push_back(')');
	while (bra > 0) {
		bra-=2;
		for (int i = 0; i < input.size(); i++)
			if (input[i] == '('&&!vis[i])
				b_pos.first = i;
		b_pos.second = search_pos(')');
		vis[b_pos.first] = true;
		vis[b_pos.second] = true;
		for (int i = b_pos.first + 1; i < b_pos.second; i++) {
			int num = 0;
			if (!vis[i]) {
				if (is_op(input[i])) {
					if (i == b_pos.first + 1 && input[i] == '-')positive = false;
					vis[i] = true;
				}
				else {
					int j = i;
					for (; !is_op(input[j]); j++);
					for (int k = 0; j >= i; j--, k++) {
						num += pwr_ten(input[j], k);
						vis[j] = true;
					}
				}
			}
		}
		positive = true;
	}
}
void calculator(){
	using namespace calulator_n;
	cout << '>';
	cin >> a >> op;
	if (op!='!') cin >> b;
	double c;
	switch (op)
	{
	case'+':cout << a + b << endl;break;
	case'-':cout << a - b << endl;break;
	case'*':cout << a*b << endl;break;
	case'/':c = a / (b*1.0);cout << c << endl;break;
	case'^':exponent(a, b);cout << a << endl;break;
	case'!':factorial(a);cout << a << endl;break;
	default:
		cout << "Sorry, this calulator cannot perform this operation." << endl;
		break;
	}
}
void class__() try
{
	using namespace class_n;
	Date today{ Year{2015},Month::dec,5 };
	today.print();cout << endl;
	cout << "Month" << endl << '>';
	Month month_s = Month::mar;
	cout << int(month_s) << endl;
}
catch (class_n::Date::Invalid)
{
	cout << "Error, invalid date" << endl;
}
void dec_6() {
	using namespace dec_6_n;
	/*for (int i = 0; i < 10; i++)
		test.push_back(i + 1);*/
	for (int i = 0; i < 10; i++) {
		vector<int>row;
		test.push_back(row);
		for (int j = 0; j < 10; j++)
			test.at(i).push_back(j);
	}
	for (const vector<int>&i : test) {
		for (const int&j : i)
			cout << j << ' ';
		cout << endl;
	}
	cout << "Please enter nodes of edges below (0 to exit)" << endl;
	cout << '>';
	pair<int, int>node_in{ 1,1 }; cin >> node_in.first >> node_in.second;
	while (node_in.first != 0) {
		int bound = MAX(node_in.first, node_in.second) + 2;
		if (bound > adj.size()) {
			adj.resize(bound, adj_r);
			for (row&i : adj)
				i.resize(bound);
		}
		try
		{
			adj.at(node_in.first).at(node_in.second) = 1;
		}
		catch (const out_of_range)
		{
			cerr << "Out of range error at adj or row." << node_in.first << ' ' << node_in.second << ' ' << adj.size() << ' ' << adj.capacity() << endl;
		}
		//adj[node_in.first][node_in.second] = 1;
		cout << '>';
		cin >> node_in.first >> node_in.second;
	}
	for (const row&t : adj) {
		for (const int&x : t)
			cout << x << ' ';
		cout << endl;
	}
	//Buggy
	/*cout << "File to produce sum af all the numbers in a file of whitespace-separated integers." << endl;
	cout << "Please end your input with a *" << endl;
	char c;vector<int>int_stream;
	while ((cin >> noskipws >> c)&&(c != '*'))
		if (!(c == 32 || (c<'0'&&c>'9')))
			int_stream.push_back(static_cast<int>(c - '0'));
	for (const int&i : int_stream)
		cout << i << ' ';
	cout << endl;*/
	//Text stuff
	{
		cout << "HEY LOOK AT MY NUMBERS" << endl;
		cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << endl;
		cout << showbase << dec;
		cout << 1234 << '\t' << hex << 1234 << '\y' << oct << 1234 << endl;
		cout << 1234.56789 << fixed << 12345.67865 << scientific << 123.446362 << endl;
		cout << "defaultfloat" << '\n' << defaultfloat << 123.254235234 << endl;
		cout << "Set width" << endl << "got too lazy" << endl;
	}

}
const int&largest_int() {
	static const int i = INT_MAX;
	return i;
}
constexpr int random_number_() {
	return 1;
}
int main(){
	int input;
	do {
		cout << endl << "Menu" << endl;
		cout << "----------" << endl;
		cout << "0. Quit" << endl;
		cout << "1. [unfinished]dec_5" << endl;
		cout << "2. calculator" << endl;
		cout << "3. Class Excercise" << endl;
		cout << "4. dec_6" << endl;
		cout << endl;
		//cout << imax;
		cin >> input;
		cout << endl;
		{
			const int largest_int_ = largest_int();
			constexpr int number_one = random_number_();
			switch (input)
			{
			case 1:dec_5();break;
			case 2:calculator();break;
			case 3:class__();break;
			case 4:dec_6();break;
			default:
				break;
			}
		}
	} while (input!=0);
	return 0;
}