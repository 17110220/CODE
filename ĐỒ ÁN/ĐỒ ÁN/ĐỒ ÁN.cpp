#include "windows.h"
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
node* Merge(node* h1, node* h2);
// Hàm thực hiện Hợp nhất Sắp xếp trên danh sách được liên kết bằng cách sử dụng tham chiếu.
void MergeSort(node **head);
long Random(int a, int b);

int main()
{
	long int n, i, num,a,b;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	HANDLE Bienmau;
	Bienmau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Bienmau, 1);
	cout << "\nNhap vao so phan tu de sap xep: ";
	cin >> n;
	SetConsoleTextAttribute(Bienmau, 2);
	cout << "nhap khoang a --> b de tao node ngau nhien\n";
	cout << "nhap a = ";
	cin >> a;
	cout << "nhap b = ";
	cin >> b;
	SetConsoleTextAttribute(Bienmau, 3);
	clock_t start = clock();// ham bất đầu đếm thời gian thực hiện chương trình
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
	cout << "\nDanh sach sau khi sap xep " << endl;
	while (head != NULL)
	{
		cout << "     " << head->data << " ";
		printf_s("%p\n", head->next);
		head = head->next;
	}
	clock_t finish = clock();// ham đếm thời gian kết thúc
	SetConsoleTextAttribute(Bienmau, 4);
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n\n\n";
	printf("Thoi gian thuc thi: %.2lf", duration);
	return 0;
}
long  Random(int a, int b)
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
node* Merge(node* h1, node* h2)
{
	node *t1 = new node;
	node *t2 = new node;
	node *temp = new node;
	//Quay trở lại nếu danh sách thứ nhất trống.
	if (h1 == NULL)
		return h2;
	//Quay trở lại nếu danh sách thứ hai trống.
	if (h2 == NULL)
		return h1;
	t1 = h1;
	//Một vòng lặp để duyệt qua danh sách thứ hai, để hợp nhất các nút thành h1 theo cách được sắp xếp.
	while (h2 != NULL)
	{
		// Đặt nút đầu của danh sách thứ hai là t2.
		t2 = h2;

		// Chuyển đầu danh sách thứ hai sang đầu danh sách tiếp theo
		h2 = h2->next;
		t2->next = NULL;
		//Nếu giá trị dữ liệu nhỏ hơn đầu của danh sách đầu tiên, hãy thêm nút đó vào đầu.
		if (h1->data > t2->data)
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
		// đi qua danh sách đầu tiên.
	flag:

		if (t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		//chuyển danh sách đầu tiên cho đến t2->data nhiều hơn dữ liệu của nút.
		else if ((t1->next)->data <= t2->data)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			//Chèn nút dưới dạng t2->data sẽ nhỏ hơn nút tiếp theo.
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}

	}

	//Trả lại phần đầu của danh sách được sắp xếp mới.
	return h1;
}

// Một hàm thực hiện Hợp nhất Sắp xếp trên danh sách được liên kết bằng cách sử dụng tham chiếu.
void MergeSort(node **head)  // trỏ đa cấp
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