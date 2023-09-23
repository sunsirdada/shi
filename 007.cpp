#include<iostream>
using namespace std;
int n;
int afs=0;


int find2(int front1, int rear1, int* list1); 
int* list = new int[n + 1];
int flag = 0;
int main()
{
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> list[j];
	}
	int oper;
	cin >> oper;
	while (oper--)
	{
		flag = 0;
		cin >> list[0];
		int temp = find2(1, n, list);
		if (!temp)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << temp << endl;
		}
	}
	return 0;
}
int find2(int front1, int rear1, int* list1)
{
	int front = front1;
	int rear = rear1;
	int midindex = (front + rear) / 2;
	while (front < rear)
	{
		if (list[0] == list[midindex])
		{
			flag = 1;
			return midindex;
		}
		else if (list[0] > list[midindex])
		{
			front = midindex + 1;
			find2(front, rear, list);
		}
		else if (list[0] < list[midindex])
		{
			rear = midindex - 1;
			find2(front, rear, list);
		}
	}
	if (!flag)
	{
		return -1;
	}
}
