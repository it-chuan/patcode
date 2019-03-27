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
#include <queue>
#include <ctype.h>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};
int n, x;
node* root = new node;//�½������
vector<int> v;
void init() {//�����������
	int m = n - 1;//n-1�Σ�
	scanf("%d", &x);
	root->data = x;
	root->left = root->right = NULL;
	queue<node*> q;
	q.push(root);
	while (!q.empty() && m > 0) {
		node* tmp = q.front();
		q.pop();
		if (m > 0) {
			scanf("%d", &x);
			node* k = new node;
			k->data = x;
			k->left = k->right = NULL;
			tmp->left = k;
			m--;
			q.push(k);
		}
		if (m > 0) {
			scanf("%d", &x);
			node* k = new node;
			k->data = x;
			k->left = k->right = NULL;
			tmp->right = k;
			q.push(k);
			m--;
		}
	}
	return;
}
void DFS(node* tree) {
	if (tree->left == NULL && tree->right == NULL) {//����Ҷ�ӽ��
		for (int i = 0; i < v.size(); i++) {//���·��
			cout << v[i];
			if (i != v.size() - 1)	cout << " ";
			else cout << "\n";
		}
	}
	if (tree->right != NULL) {
		v.push_back(tree->right->data);//·���еĽ��ȫ����������
		DFS(tree->right);
		v.pop_back();
	}
	if (tree->left != NULL) {
		v.push_back(tree->left->data);
		DFS(tree->left);
		v.pop_back();//����
	}
}
int check(node* tree) {
	queue<node*> q;
	q.push(tree);
	int big = 0, small = 0;
	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		if (tmp->left != NULL) {
			q.push(tmp->left);
			if (tmp->data > tmp->left->data) {
				if (small) {
					return 0;//��֮ǰ��ì�ܣ����Ƕѽṹ
				}
				big = 1;//�󶥶ѵı�־
			}
			else {
				if (big)	return 0;
				small = 1;
			}
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
			if (tmp->data > tmp->right->data) {
				if (small) {//ͬ��
					return 0;
				}
				big = 1;
			}
			else {
				if (big)	return 0;
				small = 1;
			}
		}
	}
	if (big == 1)	return 1;//�󶥶�
	if (small == 1)	return 2;//С����
}
int main() {
	scanf("%d", &n);
	init();//������
	v.push_back(root->data);
	DFS(root);
	int k = check(root);
	if (k == 0)	cout << "Not Heap";
	else if (k == 1)	cout << "Max Heap";
	else if (k == 2)	cout << "Min Heap";
	return 0;
}