/**************
	C++ code

	Declaration	vector<type> v(initial_size);
	Accessors	v.empty(), v.size(), v.front(), v.back()
	Mutators	 v.push_back(T), v.pop_back()
	Operators	v[int], v.at(int), v1=v2;, v1==v2

**************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm> // swap // reverse

using namespace::std;

vector<int> generateNextPermutation(vector<int> &T) {
	//1 2 0 3 --> 1 2 3 0
	//1 0 3 2 --> 1 2 0 3

	vector<int> V;

	int k = T.size() - 2;
	while ( (T[k] > T[k+1]) && (k >= 0) ) {
		k--;
	}

	if (k < 0) {   //input as 3 2 1 0
		return  V;
	}
	
	// 1 0 3 2: k point to 0
	// find largest position that > k
	
	int l = k + 1;
	while( (l < T.size() - 1 ) && (T[l] < T[l+1]) ) {
		l = l +1;
	}
	
	swap(T[k], T[l]); // swap 0 with 2.

	reverse(T.begin() + k + 1, T.end());

	return T;
}

void main_12() {
	vector<int> T; //vector<int> T(3);
	vector<int> V;

	T.push_back(1);
	T.push_back(2);
	T.push_back(0);
	T.push_back(3);

	for (int i = 0; i< T.size(); i ++ ) {
		printf("%d ",T[i]);
	}
	printf("\n");

	V = generateNextPermutation(T);

	for (int i = 0; i< V.size(); i ++ ) {
		printf("%d ",V[i]);
	}
	printf("\n");

}