#include <iostream>
using namespace std;

class Node {
public:
	string name;
	int id;
	Node* next;
	Node* previous;

	Node(string name, int id) {
		this->name = name; this->id = id;
		next = NULL; previous = NULL;
	}
};

class LinkedList {
	Node* head, * tail;
	int size;
public:
	LinkedList() {
		head = new Node("head", -1); tail = new Node("tail", -1);
		head->next = tail; tail->previous = head;
		size = 0;
	}

	void addFromBack(Node* data) {
		tail->previous->next = data; data->previous = tail->previous;
		data->next = tail; tail->previous = data;
		size++;
	}

	Node* removeFromFront() {
		if (size == 0)
			return NULL;
		Node* data;
		data = head->next; data->next->previous = head;
		head->next = data->next;
		size--;
		return data;
	}

	void addFromFront(Node* data) {
		data->next = head->next; data->previous = head;
		head->next->previous = data; head->next = data;
		size++;
	}

	Node* removeFromBack() {
		Node* data;
		data = tail->previous; data->previous->next = tail;
		tail->next = data->previous;
		size--;
		return data;
	}

	void print() {
		Node* temp;
		temp = head->next;
		if (size == 0) {
			cout << "\nEmpty List";
			return;
		}
		cout << "\n<-";
		while (temp != tail) {
			cout << "(" << temp->name << "," << temp->id << ")";
			if (temp->next != tail)
				cout << "--";
			else
				cout << "<-";
			temp = temp->next;
		}
	}

};

void linkedList_Main()
{
	cout << "Linkedlist Example\n";
	LinkedList queue;
	cout << "\nUse as a queue, Adding ABC & DEF";
	queue.addFromBack(new Node("ABC", 1));
	queue.addFromBack(new Node("DEF", 2));
	queue.print();
	cout << "\nRemoving DEF";
	queue.removeFromFront();
	queue.print();

	LinkedList stack;
	cout << "\nUse as a stack, Adding AAA & BBB";
	stack.addFromBack(new Node("AAA", 1));
	stack.addFromBack(new Node("BBB", 2));
	stack.print();
	cout << "\nRemoving BBB";
	Node* t = stack.removeFromBack();
	cout << endl << t->name << " removed";
	//stack.addFromFront(new Node("xxx", 3));
	stack.print();
}