#include <iostream>

using namespace std;

int main(void) {
	int arr[10] = { 1,10,9,5,6,3,2,4,8,7 };
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j + 1 < 10 - i; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}