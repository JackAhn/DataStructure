#include <iostream>

using namespace std;

/*int Heapify(int *arr, int parentind, int maxind) {
	int parentdata = arr[parentind];
	if ((parentind * 2) <= maxind) {
		int data = Heapify(arr, parentind * 2, maxind);
		if (parentdata < data) {
			arr[parentind] = data;
			arr[parentind * 2] = parentdata;
			Heapify(arr, parentind, maxind);
			return data;
		}
	}
	else {
		return parentdata;
	}

	if ((parentind * 2) + 1 <= maxind) {
		int data = Heapify(arr, (parentind * 2) + 1, maxind);
		if (parentdata < data) {
			arr[parentind] = data;
			arr[(parentind * 2) + 1] = parentdata;
			Heapify(arr, parentind, maxind);
			return data;
		}
	}
	else {
		return parentdata;
	}
	return parentdata;
}*/

int Heapify(int *arr, int parentind, int maxind) {
	int parentdata = arr[parentind];
	if ((parentind * 2) <= maxind) {
		int data = Heapify(arr, parentind * 2, maxind);
		int data2 = Heapify(arr, (parentind * 2) + 1, maxind);
		if (parentdata < data) {
			arr[parentind] = data;
			arr[parentind * 2] = parentdata;
			Heapify(arr, parentind * 2, maxind);
			return data;
		}
		else if (parentdata < data2) {
			arr[parentind] = data;
			arr[(parentind * 2) + 1] = parentdata;
			Heapify(arr, (parentind * 2) + 1, maxind);
			return data;
		}
	}
	else {
		return parentdata;
	}
	return parentdata;
}

int main(void) {
	int much = 0;
	cin >> much;
	int * arr = new int[much + 1];
	for (int i = 1; i < much + 1; i++) {
		cin >> arr[i];
	}

	Heapify(arr, 1, much + 1);

	for (int i = 1; i < much + 1; i++) {
		cout << arr[i] << ' ';
	}
	delete[] arr;
}