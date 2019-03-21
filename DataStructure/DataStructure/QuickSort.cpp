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
		if (temp == 10)  //��� �˻� �Ϸ� ��
			break;
		else if (complete[pivot] == 1) { //�̹� �ٲ� ������ ���
			pivot++; //�ǹ� ����
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

		if (max > min) { //ũ�ν�
			temp = arr[pivot];
			arr[pivot] = arr[min];
			arr[min] = temp;
			complete[min] = 1;
			//�ǹ� ����
			for (int i = 0; i < 10; i++) {
				if (complete[i] != 1) { //�������� �ʾ�����
					pivot = i; //�ǹ� ����
					break;
				}
			}
		}
		else if (max < min) { //�ڸ� �ٲٱ�
			temp = arr[max];
			arr[max] = arr[min];
			arr[min] = temp;
			if (max == pivot) {
				complete[min] = 1;
				for (int i = 0; i < 10; i++) {
					if (complete[i] != 1) { //�������� �ʾ�����
						pivot = i; //�ǹ� ����
						break;
					}
				}
			}
		}

		else if (max == min) { //�ּҿ� �ִ밡 ���� ���
			complete[pivot] = 1; //����
		}

	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}