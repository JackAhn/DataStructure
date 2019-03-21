#include <iostream>

using namespace std;

int main(void) {
	int arr[10] = { 1,10,9,5,6,3,2,4,8,7 };
	for (int i = 0; i < 10; i++) {
		int index = i;
		int temp = 0;
		for (int j = i - 1; j >= 0; j+=0) {
			if (arr[index] < arr[j]) {
				temp = arr[index];
				index = j;
				arr[j + 1] = arr[j];
				arr[index] = temp;
			}
			else
				j--;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

}