#pragma once
namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may , jun, jul, aug, sep, oct, nov, dec
	};
	class Date {
	public:
		class Invalid {};
		Date();
		Date(int y, Month m, int d);
		int day()const { return d; }
		Month month()const { return m; }
		int year()const { return y; }
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};
	bool is_date(int y, Month m, int d);
	bool leap_year(int y);
	bool operator==(const Date&a, const Date&b);
	bool operator!=(const Date&a, const Date&b);
	ostream&operator<<(ostream&os, const Date&d);
	istream&operator>>(istream&is, Date&dd);
}