//============================================================================
// Name        : practice.cpp
// Author      : anebrao
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

bool order2(int &x, int &y);
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
int sum_array(int *arr, int size);
int min_array(int *arr, int size);
bool pali(int a[], int size);
int findMin(int *arr, int size);


int main() {
	srand(time(NULL));
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "Problems 3 & 4" << endl;
	int x = 20;
	int arr[x];
	fillArray(arr, x);
	printArray(arr, x);
	//cout << "Question 9" << endl;
	//cout << "SUM OF VALUES" << endl;
	//int sum1 = sum_array(&arr[0], x);
	//cout << sum1 << endl;
	//cout << "Question 8" << endl;
	//cout << "MINIMUM VALUE" << endl;
	//min_array(&arr[0], x);
	return 0;
}

// Problem 2 Taken from that github
bool order2(int &x, int &y) {
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
		return false;
	} else {
		return true;
	}
}

// Problem 3
void fillArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int r = rand() % 100;
		arr[i] = r;
	} //for
} //fillarray

// Problem 4
// This is a new version
void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

//Problem 5
// this is the one taken from that other github
void MinFind(int a[], int size, int &min, int &index) {
	min = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
			index = i;
		}
	}
	cout << "The smallest value in this array is " << min
			<< " which can be found at index " << index << endl;
	return;
}

//Question 7a
// input address of a value in an array
// and takes the sum of it all
int sum_array(int *arr, int size) {
	int sum = arr[size - 1];
	if (size - 1 > 0) {
		sum = sum + sum_array(&arr[0], size - 1);
	} // if, end condition.
	return sum;
}

int findMin(int *arr, int size) {
	int y = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < y) {
			y = arr[i];
		}
	}
	return y;
}

// Problem 7b
int min_array(int a[], int length) {
	int x = rand() % 5 + 3;
	int minsum = 10000;
	int index = 0;
	for (int i = 0; i <= length - x; i++) {
		//cout<<i<<endl;
		sum_array(&a[i], x);
		if (sum_array(&a[i], x) <= minsum) {
			minsum = sum_array(&a[i], x);
			index = i;
		}
	}
	cout << index << endl;
	return index;

}

// Problem 8
//Uses the function above
// sort the array by using the find smallest
void sortarr(int arr[], int size) {
	if (size <= 2) {
		return;
	}
	int min = 0;
	int mindex = 0;
	MinFind(arr, size, min, mindex);
	if (min < arr[0]) {
		arr[mindex] = arr[0];
		order2(arr[0], min);
	}
	//ArrayPrint(a,size);
	int *newarr = &arr[1];
	sortarr(newarr, size - 1);

}

// Promblem 9

bool pali(int a[], int size) {
	int pos = 0;
	int i = 0;
	while (pos == 0 && i < size) {
		if (a[i] == a[size - i - 1]) {
			pos = 0;
			i++;
		} else {
			pos = 1;
		}
	}
	if (pos == 0)
		return true;
	else
		return false;
}

// Problem 11
// needs to be refactored
// first value in the array, the length of the array, the x
// (the length of the potential palindrome) and a 4th int parameter
// modified by call by reference that will hold the index in the array
// of the first value in a palindrome of length x if a palindrome of length x is found.
bool palindref(int arr[], int size, int x, int &fourth) {
	int i = 0;
	    while(i <= (size-x)){
	        if(pali(&arr[i], size)){
	            fourth = i;
	            return true;
	        }
	        i++;
	    }
	    return false;
	}

// Problem 12
// needs to be refactored
// This one has 4 input parameters: the int array
// (or the address of the first value in the array), the size of the array,
// and 2 int parameters that are modified within the function using call by reference.
// should return the
void finalpalin(int arr[], int size, int &x, int &y) {
	int i = size;
	    while(i > 0){
	        if(palindref(&array[0], size, i, x)){
	            y = i;
	            return;// return here because we have found the largest palindrome
	        }
	        i--;
	    }
}

/*
 // Problem 15
 // input parameter an array of ints between 0 and 50 (including 50) and an int pointer
 //representing the length of this array.
 void updatearr(int arr[], int length) {

 }

 // Problem 16
 //

 */
