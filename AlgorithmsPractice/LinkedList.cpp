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

	void print() {
		cout << "|" << previous << "|" << "  (" << id << "," << name << ")  " << "|" << next << "|";
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
			cout << "Empty List";
			return;
		}
		cout << "|| Front || <-- ";
		while (temp != tail) {
			cout << "(" << temp->id << "," << temp->name << ")";
			if (temp->next != tail)
				cout << " < ";
			else
				cout << " <-- || Back ||";
			temp = temp->next;
		}
		cout << "";
	}

};

void linkedList_Main()
{
	LinkedList list;
	cout << "Use as a queue, Adding ABC, DEF & GHI: \n";
	list.addFromBack(new Node("ABC", 1));
	list.addFromBack(new Node("DEF", 2));
	list.addFromBack(new Node("GHI", 3));
	list.print();
	cout << "\n\nRemoved from front: ";
	Node* recieved = list.removeFromFront();
	recieved->print(); cout << "\n";
	list.print();

	cout << "\n\nUse as a stack, Adding AAA & BBB from back: \n";
	list.addFromBack(new Node("AAA", 4));
	list.addFromBack(new Node("BBB", 5));
	list.print();
	cout << "\n\nRemoving from back: ";
	recieved = list.removeFromBack();
	recieved->print(); cout << "\n";
	list.print();
}