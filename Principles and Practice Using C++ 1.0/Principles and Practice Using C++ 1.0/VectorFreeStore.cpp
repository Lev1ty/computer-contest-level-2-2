#include"stdafx.h"
#include"VectorFreeStore.h"

void VectorFreeStoreN::sizes(char ch, int i, int * p)
{
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << endl;
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << endl;
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << endl;
}

void VectorFreeStoreN::VectorFreeStore()
{
	char ch = 'A';
	int i = 0;
	int * p = &i;
	sizes(ch, i, p);
}
