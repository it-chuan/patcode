#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
string num[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge", "Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
vector<string> res;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "ling";
		return 0;
	}
	if (n < 0) {
		cout << "Fu ";
		n = -n;
	}
	int part[3];
	part[0] = n / 100000000;//�ڵĲ���
	part[1] = (n % 100000000) / 10000;
	part[2] = n % 10000;
	bool zero = false;//�Ƿ��ڷ�������ǰ������ʵ�ling
	int printCnt = 0;//����ά������ǰû�пո�֮������ĵ��ʶ���ǰ���һ���ո�
	for (int i = 0; i < 3; i++) {
		int temp = part[i];//�������� ÿ�����ڲ�����������һ��������xǧx��xʿx
		for (int j = 3; j >= 0; j--) {
			int curpos = 8 - i * 4 + j;//��ǰ���ֵ�λ��
			if (curpos >= 9) continue;//���9λ�� ��һ���� �������⴦��
			int cur = (temp / J[j]) % 10;//ȡ����ǰ����
			if (cur != 0) {
				if (zero) {

				}
			}
		}
	}
	return 0;
}