/*
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
//*/

/*
bool somePredicate(double x)
{
	//cerr << "somePredicate called " << endl;
	return x < 0;
}
*/

// Return true if the somePredicate function returns true for at
// least one of the array elements, false otherwise.
bool anyTrue(const double a[], int n)
{
	if (n <= 0)
		return false;

	if (somePredicate(a[0]))
		return true;
	else
		return anyTrue(a + 1, n - 1); //shifts to next element and takes smaller subset

}


// Return the number of elements in the array for which the
// somePredicate function returns true.
int countTrue(const double a[], int n)
{
	
	if (n <= 0)
		return 0;
	
	if (somePredicate(a[0]))
		return 1 + countTrue(a + 1, n - 1);
	else
		return countTrue(a + 1, n - 1);

}

// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrue(const double a[], int n)
{
	if (n <= 0)
		return -1;

	if (somePredicate(a[0]))
		return 0;
	else if (firstTrue(a + 1, n - 1) == -1) //return -1 if we never find true during recursion
		return -1; 
	else
		return 1 + firstTrue(a + 1, n - 1); //adding 1 keeps track of number of times we increment a
	
}

// Return the subscript of the smallest element in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told to examine no 
// elements, return -1.
int positionOfMin(const double a[], int n)
{
	if (n <= 0)
		return -1;
	
	int index = 1 + positionOfMin(a + 1, n - 1);
	if (a[0] <= a[index]) //<= or <, not sure
		return 0;
	else 
		return index;

	
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2)
{
	if (n2 <= 0)
		return true; //finished through a2 means all n2 elements appeared in n1
	if (n1 <= 0)
		return false; //did not find all n2 elements, so return false

	if (a1[0] == a2[0])
		return includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
	else
		return includes(a1 + 1, n1 - 1, a2, n2);

	
}


//
//	IGNORE STUFF AFTER THIS. 
//
/*

int main()
{
	double a[3] = { -1, 0, 4 };
	double b[3] = { 0, 2, 4 };
	double c[3] = { 0, 5, -1 };
	double d[3] = { 0, -2, 4 };
	double e[5] = { 1, 0, 4, 3, -2 };
	double f[5] = { -1, -2, -3, -4, -5 };
	double g[5] = { -1, -2 };
	double h[3] = {-1, -4, -5};




	
	//Testing anyTrue
	assert(anyTrue(a, 3));
	assert(!anyTrue(b, 3));
	assert(!anyTrue(c, 2));
	assert(anyTrue(d, 3));
	assert(anyTrue(e, 5));
	

	
	//Testing countTrue
	assert(countTrue(a, 3) == 1);
	assert(countTrue(f, 5) == 5);
	assert(countTrue(e, 5) == 1);
	assert(countTrue(f, 4) == 4 && countTrue(e, 4) == 0);
	
	
	
	//Testing firstTrue
	assert(firstTrue(b, 3) == -1);
	assert(firstTrue(e, 4) == -1);
	assert(firstTrue(f, 3) == 0);
	assert(firstTrue(c, 3) == 2);
	assert(firstTrue(d, 3) == 1);
	assert(firstTrue(e, 5) == 4);
	//

	
	//Testing positionOfMin
	assert(positionOfMin(b, 3) == 0);
	assert(positionOfMin(f, 5) == 4);
	assert(positionOfMin(d, 3) == 1);
	

	
	//Testing includes
	assert(includes(f, 5, g, 2));
	assert(!includes(f, 5, a, 2));
	assert(!includes(f, 5, b, 1));
	assert(includes(f, 5, h, 3));
	
	
	
	//cerr << "success" << endl;
}

*/