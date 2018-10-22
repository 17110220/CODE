// DOAN_CTDL.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "iostream"
#include <sys/timeb.h>
#include <time.h>
using namespace std;
struct node
{
	long int data;
	node *next;
};
int Random(int n);
node* NewNode(int d);
node* AddToList(node *tail, int data);
int main()
{
	long int n, i, num, a, b;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	cout << "nhap so Node muon Tao: ";
	cin >> n;
	cout << "nhap khoang a-->b de gioi han tao ngau nhien Node\n";
	cin >> a;
	cin >> b;
	cout << "\n";
	// thêm node vào danh sách liên kết
	for (i = 0; i < n; i++)
	{
		num = Random(a,b);
		tail = AddToList(tail, num);
		if (head == NULL)
			head = tail;
	}
	return 0;
}
// hàm tạo số ngẫu nhiên 
int Random(int n)
{
	return rand() % (n + 100);
}
// tạo Node mới
node* NewNode(int d)
{
	struct node *temp = new node;
	temp->data = d;
	temp->next = NULL;
	return temp;
}
//thêm node vào cuối danh sách liên kết 
node* AddToList(node *tail, int data)
{
	struct node *newnode;
	newnode = NewNode(data);

	if (tail == NULL)
	{
		tail = newnode;
	}
	// nếu phần tử cuối khác rỗng thì gán phần tử cuối cho phần tử tiếp theo
	else
	{
		tail->next = newnode;
		//chuyển con trỏ cuối  đến node vừa thêm
		tail = tail->next;
	}

	return tail;
}