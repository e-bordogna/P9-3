
/*
 *
 * File: P9-2.sln
 * Author: Enzo M Bordogna
 * Date: 10/26/2023
 *
 */
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void displayRun(const int* values, int size);
int rollDie(void);
bool hasRun(const int* values, int size);

int main() {
	srand((unsigned int)time(NULL));
	int roll[20];
	do {
		const int* p = roll;
		for (int i = 0; i < 20; i++) {
			roll[i] = rollDie();
		}
		if (hasRun(roll, 20) == false) {
			cout << "no run: ";
			for (int i = 0; i < 20; i++) {
				cout << *p << " ";
				p++;
			}
			cout << endl;
		}
		else {	// if hasRun is true, displayRun
			displayRun(roll, 20);
		}
	} while (hasRun(roll, 20) == false);
	return 0;
}

int rollDie(void) {
	int num;
	num = rand() % 6 + 1;
	return num;
}

void displayRun(const int* values, int size) {
	cout << "has run: ";
	for (int i = 0; i < size; i++) {
		//case for having a run including number at index 0
		if (i == 0 && values[i] == values[i + 1]) {
			cout << "(";
			cout << values[i] << " ";
			do {
				i++;
				cout << values[i];
				if (values[i] == values[i + 1]) {
					cout << " ";
				}
			} while (values[i] == values[i + 1] && i != 19);
			cout << ") ";
		}
		//case for having a run in the middle of the array
		else if (i != 0 && i != 19 && values[i] == values[i + 1]) {
			cout << "(";
			cout << values[i] << " ";
			do {
				i++;
				cout << values[i];
				if (values[i] == values[i + 1]) {
					cout << " ";
				}
			} while (values[i] == values[i + 1] && i != 19);
			cout << ") ";
		}
		//case for printing numbers
		else {
			cout << values[i] << " ";
		}
	}
}
bool hasRun(const int* values, int size) {
	const int* p = values;
	for (int i = 0; i < size - 1; i++) {
		if (*p == *(p + 1)) {
			return true;
		}
		p++;
	}
	return false;
}