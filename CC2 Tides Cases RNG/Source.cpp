#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream text;
	text.open("text.txt");
	int num_case = rand() % 997 + 3;
	text << num_case << endl;
	for (int i = 0; i < num_case; i++)
	{
		int rnd = rand() % 9999 + 1;
		text << rnd << endl;
	}
	text.close();
}