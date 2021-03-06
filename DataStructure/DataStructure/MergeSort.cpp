#include <iostream>

using namespace std;

// Ver 0.1 초기 버전 작성

// Ver 0.2 같은 숫자를 대입한 경우 추가

// Ver 0.3(예정) 홀수개의 숫자를 받거나 2의 배수가 아닌 숫자를 받는 경우

int main(void) {
	int much = 0;
	cin >> much;
	int * arr = new int[much];
	int * answer = new int[much];

	for (int i = 0; i < much; i++) {
		cin >> arr[i];
	}

	int len = 1; //분할 배열 개수
	int mul = 2; //2의 배수씩 증가
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