#include <iostream>

using namespace std;

// Ver 0.1 �ʱ� ���� �ۼ�

// Ver 0.2 ���� ���ڸ� ������ ��� �߰�

// Ver 0.3(����) Ȧ������ ���ڸ� �ްų� 2�� ����� �ƴ� ���ڸ� �޴� ���

int main(void) {
	int much = 0;
	cin >> much;
	int * arr = new int[much];
	int * answer = new int[much];

	for (int i = 0; i < much; i++) {
		cin >> arr[i];
	}

	int len = 1; //���� �迭 ����
	int mul = 2; //2�� ����� ����
	int i = 0, j = 0, ct = 0, ind = 0;
	int iflag = 0, jflag = 0;
	while (1) {
		if (mul > much)
			break;
		ind = 0;
		ct = 0;
		i = 0;
		j = len;
		iflag = i + len;
		jflag = j + len;
		while (j < much) {
			ct++;
			if (arr[i] > arr[j]) {
				answer[ind++] = arr[j];
				j++;
			}

			else if (arr[i] < arr[j]) {
				answer[ind++] = arr[i];
				i++;
			}

			else if (arr[i] == arr[j]) {
				answer[ind++] = arr[i];
				answer[ind++] = arr[j];
				i++;
				j++;
			}

			if (ct >= len) {
				if (i == iflag) {
					int c = 0;
					while (c < jflag - j) {
						answer[ind++] = arr[j++];
						c++;
					}
					i += len;
					j = i + len;
					iflag = i + len;
					jflag = j + len;
					ct = 0;
				}

				else if (j == jflag) {
					int c = 0;
					while (c < iflag - i) {
						answer[ind++] = arr[i++];
						c++;
					}
					i = j;
					j += len;
					iflag = i + len;
					jflag = j + len;
					ct = 0;
				}
			}

		}
		for (int i = 0; i < much; i++) {
			arr[i] = answer[i];
		}

		len = mul;
		mul *= 2;
	}
	for (int i = 0; i < much; i++) {
		cout << arr[i] << ' ';
	}
	delete[] arr;
	delete[] answer;
}