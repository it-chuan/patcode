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
int main() {
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)	cin >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//�����ȼ���i,jΪ����
			vector<int> lie, a(n + 1, 1);//a�ĳ�ʼֵΪ1
			a[i] = a[j] = -1;//����i j ������
			for (int k = 1; k <= n; k++) {
				if (v[k] * a[abs(v[k])] < 0) {//abs(v[k])��k����˵��ĳ����
					//a[abs(v[k])] ��k����˵������˵����
					//v[k]�ǵ�k����˵������˵����
					//���С��0������ì���ˣ�˵����k��������
					lie.push_back(k);
				}
			}
			//�պ������������� ���������
			if (lie.size() == 2&&a[lie[0]] + a[lie[1]] == 0 ) {//?������һ������˵��
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}