#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int num = 0, n, temp;//��¼���и���
int ans[17];
stack<int> s;
void oper(int p) {
	//����ջ
	if (p < n) {
		s.push(p + 1);
		//printf("%d ", p);
		oper(p + 1);//s[1 2 3 4]
		//�ָ�����
		s.pop();
	}
	//�ɳ�ջ
	if (!s.empty()) {
		int temp = s.top();//ȡ��ջ��
		ans[num++] = temp;//�洢ջ��
		s.pop();
		if (s.empty() && p >= n) {//���ջԪ��ȫ��ת�Ƶ�ans����
			//�����
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
				//if (i != n - 1)	printf(" ");
			}
			printf("\n");
		}
		oper(p);//p��ʱ��n���ص�ȡ��ջ������
		//�ָ�����
		//printf("temp = %d p = %d", temp, p);
		s.push(temp);
		num--;
	}
}
int main() {
	scanf("%d", &n);
	s.push(1);
	oper(1);
	return 0;
}
