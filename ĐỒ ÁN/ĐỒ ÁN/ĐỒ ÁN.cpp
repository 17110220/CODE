// ĐỒ ÁN.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "iostream"
#include <sys/timeb.h>
#include <time.h>
using namespace std;
// Một cấu trúc biểu diễn một nút của một danh sách liên kết.
struct node
{
	long int data;
	node *next;
};
//Trả về temp làm nút mới
node* NewNode(int d);
// Hàm thêm dữ liệu đã cho vào cuối danh sách liên kết.
node* AddToList(node *tail, int data);
void MergeSort(node **head);
int Random(int a, int b);
int main()
{
	long int n, i, num,a,b;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	printf_s("Nhap So Node Muon Tao: ");
	scanf_s("%d", &n);
	printf_s("Nhap khoang tu a-->b muon tao Node:");
	printf_s("\nNhap a: ");
	scanf_s("%d", &a);
	printf_s("\nNhap b: ");
	scanf_s("%d", &b);
	clock_t start = clock();// ham bất đầu đếm thời gian thực hiện chương trình
							// Tạo danh sách
	for (i = 0; i < n; i++)
	{
		num = Random(a,b);
		tail = AddToList(tail, num);
		if (head == NULL)
			head = tail;
	}
	// Gửi tham chiếu đầu vào MergeSort ().
	MergeSort(&head);
	// In dữ liệu được sắp xếp.
	printf_s("\nDanh sach sau khi sap xep:\n");
	while (head != NULL)
	{
		cout << "     " << head->data << "    ";
		cout << head->next << endl;
		head = head->next;
	}
	clock_t finish = clock();// ham đếm thời gian kết thúc
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf_s( "\n\n\n");
	printf("Thoi gian thuc thi: %.2lf", duration);
	//system("pause");
	return 0;
}
int Random(int a, int b)
{
	return a + rand() % (b - a + 1);
}

//Trả về temp làm nút mới
node* NewNode(int d)
{
	struct node *temp = new node;
	temp->data = d;
	temp->next = NULL;
	return temp;
}

// Hàm thêm dữ liệu đã cho vào cuối danh sách liên kết.
node* AddToList(node *tail, int data)
{
	struct node *newnode;
	newnode = NewNode(data);

	if (tail == NULL)
	{
		tail = newnode;
	}
	// Nếu đuôi không null gán nút mới cho đuôi tiếp theo.
	else
	{
		tail->next = newnode;
		// Chuyển con trỏ đuôi sang nút đã thêm.
		tail = tail->next;
	}

	return tail;
}

// Một hàm thực hiện Hợp nhất Sắp xếp trên danh sách được liên kết bằng cách sử dụng tham chiếu.
void MergeSort(node **head)
{
	node *first = new node;
	node *second = new node;
	node *temp = new node;
	first = *head;
	temp = *head;

	//Quay trở lại nếu danh sách có ít hơn hai nút.
	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		//Chia danh sách thành hai nửa đầu tiên và thứ hai là người đứng đầu danh sách.
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}

	//Thực hiện cách tiếp cận phân chia và chinh phục.
	MergeSort(&first);
	MergeSort(&second);
	// Hợp nhất hai phần của danh sách thành một phần được sắp xếp.
	*head = Merge(first, second);
}

