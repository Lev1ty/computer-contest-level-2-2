#include "iostream"
#include "string"
#include "vector"
#include "utility"
#include "algorithm"
using namespace std;
bool equal(pair<string, string> pair1, pair<string, string> pair2)
{
	return (pair1.first == pair2.second&&pair1.second == pair2.first);
}
