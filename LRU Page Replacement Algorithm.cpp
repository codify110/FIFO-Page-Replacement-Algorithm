#include<iostream>
using namespace std;
class Queue
{
public:
	int front = -1;
	int rear = -1;
	int *ptr;
	int size;
	Queue(int n)
	{
		size = n;
		ptr = new int[size];
	}
	void enqueue(int num)
	{
		if (!isFull())
		{
			front++;
			ptr[front % size] = num;
		}
		else
			cout << "\nThe Queue is FULL !!\n";
	}
	int dequeue()
	{
		if (!isEmpty())
		{
			rear++;
			return ptr[rear % size];
		}
		else
			cout << "\nThe Queue is Empty !!\n";
	}
	bool search(int key)
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] == key)
			{
				flag = true;
			}
		}
		return flag;
	}
	bool isFull()
	{
		if (front - rear == size)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}
};
int checkFurther(Queue queue1, int *pages_arr, int cursorInPageArray, int totalPages)
{
	int latestPosition = 0, pageExistNotFurtherUsed = 0, id;
	bool flag;
	for (int i = 0; i < queue1.size; i++)
	{
		flag = false;
		for (int j = cursorInPageArray + 1; j < totalPages; j++)
		{
			if (queue1.ptr[i] == pages_arr[j] && j > latestPosition)
			{
				latestPosition = j;
				id = i;
				flag = true;
			}
		}
		if (flag == false)		//to check for a page not used further at all
		{
			pageExistNotFurtherUsed = 1;
			id = i;
			return id;
		}
	}
	return id;
}
int main()
{
	int totalPages, currentPage, frames, temp, pageFault = 0;
	bool flag;
	cout << "Enter the Total Pages= ";
	cin >> totalPages;
	int *pages_arr = new int[totalPages];
	cout << "Enter the number of Frames= ";
	cin >> frames;
	Queue queue1(frames);
	cout << endl;
	for (int i = 0; i < totalPages; i++)
	{
		cout << "Enter Page Number= ";
		cin >> pages_arr[i];
	}
	for (int i = 0; i < totalPages; i++)
	{
		flag = queue1.search(pages_arr[i]);
		if (flag == false)						//not present in any frame
		{
			if (queue1.isFull())				//find the page to swap
			{
				int target_id = checkFurther(queue1, pages_arr, i, totalPages);   //check for latest page used or a page not used further at all
				queue1.ptr[target_id] = pages_arr[i];
			}
			else
				queue1.enqueue(pages_arr[i]);
			pageFault++;
		}
	}
	cout << "\n\nPage fault= " << pageFault << endl << endl;
	system("pause");
}

