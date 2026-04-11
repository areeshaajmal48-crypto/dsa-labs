#include<iostream>
using namespace std;

class node {

public:
	int data;
	node* next;
};

class list
{
	node* head;
public:
	list()
	{
		head = nullptr;
	}
	void createnode(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;

		}
	}
	void display()
	{
		node* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << "   ";
			curr = curr->next;
		}
	}

};

int main()
{
	list l1;
	l1.createnode(10);
	l1.createnode(20);
	l1.createnode(30);
	l1.createnode(40);

	l1.display();




}