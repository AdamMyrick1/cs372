#pragma once
template <typename T>
class List
{
private:
	class Node {
	public:
		T  data;
		Node* prev;
		Node* next;
		bool deleted;
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int numNonDeleted = 0; 
	int numDeleted = 0;   

	void setupList() {
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		newNode->deleted = false;
		head = newNode;
		tail = newNode;
		numNonDeleted = 0;
		numDeleted = 0;
	}

	void deleteListContents() {
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->next;
			delete current;
			current = temp;
		}
	}

public:
	List() = default;
	List(T newData) {
		setupList();
		head->data = newData;
		numNonDeleted = 1;
	}

	List(List& rhs) { 
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
		numNonDeleted = rhs.numNonDeleted;
		numDeleted = rhs.numDeleted;
	}

	~List() {
		deleteListContents();
	}

	bool empty() {
		return (numNonDeleted == 0);
	}

	void push_front(T data)
	{
		if (empty()) {
			setupList();
			head->data = data;
			tail = head;
			head->deleted = false;
			numNonDeleted = 1;
			return;
		}

		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;
		newNode->deleted = false;
		head->prev = newNode;
		head = newNode;
		numNonDeleted++;
	}

	void push_back(T data)
	{
		if (empty()) {
			setupList();
			head->data = data;
			tail = head;
			head->deleted = false;
			numNonDeleted = 1;
			return;
		}

		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = tail;
		newNode->deleted = false;
		tail->next = newNode;
		tail = newNode;
		numNonDeleted++;
	}

	T front() {
        return head->data;
	}

	T back() {		
		return tail->data;
	}

	void pop_back() {
		Node* lastNode = tail;

		do {
			tail = tail->prev;
		} while (tail != nullptr && tail->deleted);

		if (tail != nullptr)
			tail->next = nullptr;

		delete lastNode;
		numDeleted--;

		if (numDeleted == numNonDeleted) {
			deleteListContents();
			setupList();
		}
	}

	void pop_front() {
		Node* firstNode = head;

		do {
			head = head->next;
		} while (head != nullptr && head->deleted);

		if (head != nullptr)
			head->prev = nullptr;

		delete firstNode;
		numDeleted--;

		if (numDeleted == numNonDeleted) {
			deleteListContents();
			setupList();
		}
	}

	void traverse(void(*doIt)(T data)) {
		Node* current = head;
		while (current != nullptr) {
			if (!current->deleted)
				doIt(current->data);
			current = current->next;
		}
	}

	void markDeleted(T data) {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == data && !current->deleted) {
				current->deleted = true;
				numDeleted++;
				numNonDeleted--;
				break;
			}
			current = current->next;
		}
	}
};