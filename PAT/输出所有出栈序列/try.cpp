#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int num = 0, n, Array[17];
stack<int> s;
void printstack(int p) {
	if (p < n) {
		s.push(p + 1);
		printstack(p + 1);
		//�ָ�������֮�� ����
		//**����3��ʱ��p�ǵ���2�ģ�
		s.pop();//����֮���������if����ת�Ƶ�Array��
	}
	if (!s.empty()) {
		int temp = s.top();
		Array[num++] = temp;
		s.pop();
		if (s.empty() && p >= n) {
			for (int i = 0; i < n; i++) {
				printf("%d ", Array[i]);
			}
			printf("\n");
		}
		printstack(p);//��һ������Ͳ�˵�ˣ��ڶ��������ת������֮��
		//sΪ�գ�
		//ջ��Ԫ��ȫ��ת�Ƶ�Array���飬
		//push�ָ�����
		s.push(temp);
		num--;
	}
}
int main() {
	scanf("%d", &n);
	s.push(1);
	printstack(1);
	return 0;
}