#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct QueueNode{
	
	int data;
	QueueNode* next;
};

QueueNode* front = NULL;
QueueNode* rear = NULL;


//Enqueue Function
void enqueue(int x){
	
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	
	temp -> data = x;
	temp -> next = NULL;
	
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear -> next = temp;
	rear = temp;
	
}

//Dequeue Function
void dequeue(){
	
	QueueNode* temp = front;
	front = front -> next;
	
	if(front == NULL){
		cout<<"Queue is empty!\n";
		return;
	}
	if(front == rear){
		front = rear = NULL;
	}

	delete temp;
}

//Is Empty function
bool isEmpty(QueueNode* front){
	
	if(front == NULL && rear == NULL){
		cout<<"Queue Linked List is empty!\n\n";
		return true;
	}
	else{
		
		return false;
	} 
		
}

//Print function
void printQueue(QueueNode* front){
	
	if(isEmpty(front)){
		return;
	}
	else{
		
		QueueNode* temp = front;
	
		if(temp == NULL){
			return;
		}
	
		cout<<temp -> data<<" ";
		printQueue(temp -> next);
	
	}

}


int main(){
	
	printQueue(front);
	
	enqueue(14);
	enqueue(34);
	enqueue(73);
	enqueue(88);
	enqueue(54);
	
	cout<<"Queue before Dequeue : ";
	printQueue(front);
	
	dequeue();
	
	cout<<"\n\nQueue after Dequeue : ";
	printQueue(front);
	
	
}
