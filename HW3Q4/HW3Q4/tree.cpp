
#include <cassert>
#include <iostream>
using namespace std;


// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//	10 50 40 20 50 40 30
// then for this value of a2     the function must return
//	10 20 40			1
//	10 40 30			2
//	20 10 40			0
//	50 40 30			3
int countIncludes(const double a1[], int n1, const double a2[], int n2)
{
	if (n2 <= 0)
		return 1;
	if (n1 <= 0)
		return 0;
	/*
	if (n1 <= 1 && n2 == 1 && a1[0] == a2[0])
		return 1;
	else if (n1 <= 1)
		return 0;
	*/
	if (a1[0] == a2[0])
		return countIncludes(a1 + 1, n1 - 1, a2 + 1, n2 - 1) + countIncludes(a1 + 1, n1 - 1, a2, n2); //first one checks subsequent elements after first match, second checks if there's another matching first element
	else
		return countIncludes(a1 + 1, n1 - 1, a2, n2);

	/*
	Scratchwork:
	if (n1 <= 0 && n2 > 0) //run out of a1 elements to check
		return 0;

	if (n2 <= 0) //empty sequence appears in 1 way
		return 1;

	if (a1[0] == a2[0])
		return countIncludes(a1 , n1 , a2 + 1, n2 - 1); 
	else
		return countIncludes(a1 + 1, n1 - 1, a2, n2);
	*/

	
}

// Exchange two doubles
void exchange(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > divider come before all the other elements,
// and all the elements whose value is < divider come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= divider, or n if there is no such element, and firstLess is
// set to the index of the first element that is < divider, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > divider
//   * for firstNotGreater <= i < firstLess, a[i] == divider
//   * for firstLess <= i < n, a[i] < divider
// All the elements > divider end up in no particular order.
// All the elements < divider end up in no particular order.
void divide(double a[], int n, double divider,
	int& firstNotGreater, int& firstLess)
{
	if (n < 0)
		n = 0;

	// It will always be the case that just before evaluating the loop
	// condition:
	//  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
	//  Every element earlier than position firstNotGreater is > divider
	//  Every element from position firstNotGreater to firstUnknown-1 is
	//    == divider
	//  Every element from firstUnknown to firstLess-1 is not known yet
	//  Every element at position firstLess or later is < divider

	firstNotGreater = 0;
	firstLess = n;
	int firstUnknown = 0;
	while (firstUnknown < firstLess)
	{
		if (a[firstUnknown] < divider)
		{
			firstLess--;
			exchange(a[firstUnknown], a[firstLess]);
		}
		else
		{
			if (a[firstUnknown] > divider)
			{
				exchange(a[firstNotGreater], a[firstUnknown]);
				firstNotGreater++;
			}
			firstUnknown++;
		}
	}
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
	if (n <= 1)
		return;  
	int middle = n / 2;
	int firstNot = 0; // or anything works really since it will be changed by divide 
	int firstLess = n;

	divide(a, n, a[middle], firstNot, firstLess);
	order(a, firstNot); //sort left half
	order(a + firstLess, n - firstLess); //sort right half
	//change: firstLess to 1 for n - firstLess
}


int main()
{
	double a1[7] = { 10, 50, 40, 20, 50, 40, 30 };
	double a2[3] = { 10, 20, 40 };
	double a3[3] = { 10, 40, 30 };
	double a4[3] = { 20, 10, 40 };
	double a5[3] = { 50, 40, 30 };
	double a6[4] = { 10, 20, 30, 40 };

	assert(countIncludes(a1, 7, a2, 3) == 1);
	assert(countIncludes(a1, 7, a3, 3) == 2);
	assert(countIncludes(a1, 7, a4, 3) == 0);
	assert(countIncludes(a1, 7, a5, 3) == 3);
	assert(countIncludes(a1, 7, a6, 2) == 1);
	assert(countIncludes(a1, 7, a2, 0) == 1);
	assert(countIncludes(a1, 0, a2, 0) == 1);
	order(a4, 3);
	for (int i = 0; i < 3; i++)
		cerr << a4[i] << " ";
	cerr << "\n";
	order(a4, 4);
	for (int i = 0; i < 4; i++)
		cerr << a6[i] << " ";

	cerr << "success\n";
}


/*
(Hint: Using the divide function, 
the order function can be written in fewer than eight short lines of code.)

Consider all operations that a function performs that compares two doubles (e.g. <=, ==, etc.). 
You will not receive full credit if for nonnegative n1 and n2, the countIncludes function causes 
operations like these to be called more than factorial(n1+1) / (factorial(n2)*factorial(n1+1-n2)) times. 
The countIncludes function can be implemented in a way that meets the spec without calling any of the 
functions in problem 2. (If you implement it so that it does call one of those functions, then it will 
probably not meet the limit stated in this paragraph.)

For this part of the homework, you will turn in one file named tree.cpp that contains 
the four functions above and nothing more.
*/