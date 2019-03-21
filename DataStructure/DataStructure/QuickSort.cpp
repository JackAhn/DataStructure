#include <iostream>

using namespace std;

int main(void) {
	int arr[10] = { 1,10,9,5,6,3,2,4,8,7 };
	int complete[10];
	int pivot = 0, min = 0, max = 0, temp = 0, maxct = 10;

	while (1) {
		temp = 0;
		max = min = pivot;

		for (int i = 0; i < 10; i++) {
			if (complete[i] == 1)
				temp++;
		}
		if (temp == 10)  //모두 검사 완료 시
			break;
		else if (complete[pivot] == 1) { //이미 바뀐 숫자인 경우
			pivot++; //피벗 증가
			continue;
		}

		for (int i = pivot + 1; i < maxct; i++) {
			if (arr[pivot] < arr[i]) {
				max = i;
				break;
			}
		}

		for (int i = maxct - 1; i >= pivot; i--) {
			if (arr[pivot] > arr[i]) {
				min = i;
				break;
			}
		}

		if (max > min) { //크로스
			temp = arr[pivot];
			arr[pivot] = arr[min];
			arr[min] = temp;
			complete[min] = 1;
			//피벗 설정
			for (int i = 0; i < 10; i++) {
				if (complete[i] != 1) { //고정되지 않았으면
					pivot = i; //피벗 설정
					break;
				}
			}
		}
		else if (max < min) { //자리 바꾸기
			temp = arr[max];
			arr[max] = arr[min];
			arr[min] = temp;
			if (max == pivot) {
				complete[min] = 1;
				for (int i = 0; i < 10; i++) {
					if (complete[i] != 1) { //고정되지 않았으면
						pivot = i; //피벗 설정
						break;
					}
				}
			}
		}

		else if (max == min) { //최소와 최대가 같은 경우
			complete[pivot] = 1; //고정
		}

	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}