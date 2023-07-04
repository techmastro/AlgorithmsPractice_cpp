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

	void add(Node* data) {
		tail->previous->next = data; data->previous = tail->previous;
		data->next = tail; tail->previous = data;
		size++;
	}

	Node* removeFromFront() {
		if (size == 0)
			return NULL;
		Node* data;
		data = head->next; head->next->next->previous = head; data->previous = head;
		data->next = head->next; head->next = head->next->next;
		size--;
		return data;
	}

	void print() {
		Node* temp;
		temp = head->next;
		while (temp != tail) {
			cout << temp->name<<","<<temp->id<<"->";
			temp = temp->next;
		}
	}

};

void linkedList_Main()
{
	cout << "Linkedlist Example\n";
	LinkedList ld;
	ld.add(new Node("Sumant", 1));
	ld.add(new Node("Jai", 2));
	ld.print();
}