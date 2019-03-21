#include <iostream>

using namespace std;

int main(void) {
	int arr[10] = { 1,10,9,5,6,3,2,4,8,7 };
	int min, ind, temp;
	for (int i = 0; i < 10; i++) {
		ind = i;
		min = arr[i];
		for (int j = i + 1; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				ind = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[ind] = temp;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}