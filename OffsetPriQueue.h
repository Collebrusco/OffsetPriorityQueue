/*
Offset Priority Queue:
	Queue of structs or other composite type that is
	automatically kept based on comparison of a specific member.
Use:
	template arg T is structure queue will store
	template arg U is data type of member to sort with
	pass offset of desired member to constructor
	then use as regular queue
*/

#pragma once
#include <string>
#include <assert.h>
#include <iostream>

template <typename T, typename U>
class OffsetPriQueue {
private:
	struct Node {
		T val;
		Node* next;
		Node(T v, Node* n = nullptr) : val(v) {
			// val = v;
			next = n;
		}
	};
	int maxSize;
	int count;
	Node* front;
	Node* tail;
	size_t offset;
	U internal(T*);
public:
	OffsetPriQueue(size_t);
	~OffsetPriQueue();

	bool isEmpty();

	void enqueue(T);
	T dequeue();

	int size();

	void display();
};

template <typename T, typename U>
U OffsetPriQueue<T, U>::internal(T* obj){
	return *((U*)(((char*)obj) + offset));
}

template <typename T, typename U>
OffsetPriQueue<T, U>::OffsetPriQueue(size_t off){
	offset = off;
	count = 0;
	front = nullptr;
	tail = nullptr;
}

template <typename T, typename U>
OffsetPriQueue<T, U>::~OffsetPriQueue(){
	while (front){
		Node* p = front;
		front = front->next;
		delete p;
	}
}

template <typename T, typename U>
bool OffsetPriQueue<T, U>::isEmpty(){
	return (count == 0);
}

template <typename T, typename U>
void OffsetPriQueue<T, U>::enqueue(T itm){
	count++;
	Node* newNode = new Node(itm);
	if (front){
		Node* p = front;
		Node* n = nullptr;
		while (p && internal(&p->val) < internal(&itm)){
			n = p;
			p = p->next;
		}
		if (n){
			n->next = newNode;
			newNode->next = p;
		} else {
			newNode->next = p;
			front = newNode;
		}
	} else {
		front = newNode;
		tail = newNode;
	}
}

template <typename T, typename U>
T OffsetPriQueue<T, U>::dequeue(){
	assert(!isEmpty());
	count--;
	T result = front->val;
	Node* p = front;
	if (front == tail)
		tail = nullptr;
	front = front->next;
	delete p;
	return result;
}

template <typename T, typename U>
void OffsetPriQueue<T, U>::display(){
	Node* p = front;
	while (p){
		std::cout << internal(&p->val) << " ";
		p = p->next;
	}
	std::cout << "\n";
}

template <typename T, typename U>
int OffsetPriQueue<T, U>::size(){
	return count;
}
