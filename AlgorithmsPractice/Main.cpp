#include <iostream>
#include "LinkedList.cpp"
#include "Sort.cpp"
void linkedList_Main();
void bubbleSort_Main();
using namespace std;

int main() {
	cout << "Welcome to Algorithm Practice\n========================\n\n\n";

	cout << "===== Insertion Sort Example >>>>>\n\n\n";
	insertionSort_Main();
	cout << "\n\n\n<<<<< Insertion Sort Example =====\n\n\n";

	cout << "===== Bubble Sort Example >>>>>\n\n\n";
	bubbleSort_Main();
	cout << "\n\n\n<<<<< Bubble Sort Example =====\n\n\n";

	cout << "===== Linked List Example >>>>>\n\n\n";
	linkedList_Main();
	cout << "\n\n\n<<<<< Linked List Example =====\n\n\n";

	return 0;
}