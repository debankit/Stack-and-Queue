//queues using array
#include<iostream>
using namespace std;

class QueueArr
{
	public:
	int top;
	int last;
	int arr[20];
	int n = 20;
	QueueArr()
	{
		top = -1;
		last = -1;
	}

	void enqueue(int value)
	{
		if(top == -1)
		{
			top++;
			arr[top] = value;
			last ++;
		}
		if(top >= n-1)
		{
			cout<<"stack overflow!"<<endl;
		}
		else
		{
			top ++;
			arr[top] = value;
		}
	}

	void dequeue()
	{
		if(top<last)
		{
			cout<<"No elements!"<<endl;
		}
		else
		{
			last ++;
		}	
	}

	void size()
	{
		int j=0;
		for(int i=top; i>last;i--)
		{
			j++;
		}
		cout<<"The size of the queue is"<<j<<endl;
	}

	int isempty()
	{
		if(top<=-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		for(int i = top;i>last;i--)
		{
			cout<<arr[i];
		}
		cout<<endl;
	}
};

//write the main function
int main()
{
	int n;
	QueueArr qarr;
	cout<<"Enter the number of elements of the array within 20"<<endl;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		qarr.enqueue(i);
	}
	qarr.display();
	qarr.dequeue();
	qarr.display();
	qarr.size();
}