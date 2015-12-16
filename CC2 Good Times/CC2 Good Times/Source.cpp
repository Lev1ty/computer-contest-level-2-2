#include<iostream>
using namespace std;
struct Time {
	int hours, minutes;
};
Time ottawa, victoria, edmonton, winnipeg, toronto, halifax, stjohn;
int input;
Time convert(Time start, int difference) {
	Time temp; 
	temp.hours = difference / 100;
	temp.minutes = difference % 100;
	Time end;
	end.hours = start.hours + temp.hours;
	end.minutes = start.minutes + temp.minutes;
	if (end.minutes >= 60 && ++end.hours > 0 && (end.minutes -= 60) > 0);
	if (end.minutes < 0) {--end.hours;end.minutes += 60;}
	if (end.hours >= 24 && (end.hours -= 24) > 0);
	if (end.hours < 0) end.hours += 24;
	return end;
}
void print(Time t) {
	if (t.minutes == 0 && t.hours != 0)cout << t.hours * 100;
	else if (t.hours == 0 && t.minutes != 0)cout << t.minutes;
	else cout << t.hours << t.minutes;
}
int main() {
	cin >> input;
	ottawa.hours = input / 100;
	ottawa.minutes = input % 100;
	victoria = convert(ottawa, -300);
	edmonton = convert(ottawa, -200);
	winnipeg = convert(ottawa, -100);
	toronto = convert(ottawa, 0);
	halifax = convert(ottawa, 100);
	stjohn = convert(ottawa, 130);
	print(ottawa);cout << " in Ottawa" << endl;
	print(victoria);cout << " in Victoria" << endl;
	print(edmonton);cout << " in Edmonton" << endl;
	print(winnipeg);cout << " in Winnipeg" << endl;
	print(toronto);cout << " in Toronto" << endl;
	print(halifax);cout << " in Halifax" << endl;
	print(stjohn);cout << " in St. John's" << endl;
}