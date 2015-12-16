// VectorTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void fillVector(std::vector<int>& newMyVector)
{
	int input;
	std::cin >> input;
	while (input!=-1)
	{
		newMyVector.push_back(input);
	}
}

int main()
{
	//format: vector<DataType> nameOfVector
	//myVector.push_back(i): insert i at first free spot in vector
	//myVector.at(i): returns value at index i
	//myVector.size(): returns size_t of myVector
	//myVector.begin(): sets point to beginning of vector, reads vector from first element
	//myVector.insert(myVector.begin() + integer, new value): add element before specified index number
	//myVector.erase(myVector.begin() + integer): removes element at specified index
	//myVector.clear(): removes all elements in vector
	//myVector.empty(): returns bool depending if vector is empty

	std::vector<int>myVector;
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	std::cout << "Vector: ";
	for (size_t i = 0; i < myVector.size(); i++)
		std::cout << myVector[i] << " ";
	myVector.insert(myVector.begin() + 3, 5);
	std::cout << std::endl;
    return 0;
}

