#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int arr[10];
int rear = -1;
int front = -1;
int n = 10;
int count = -1;

//Empty Function
void isEmpty(){
	if(rear == -1 && front == -1){
		cout<<"Array is Empty!";
	}
	else{
		cout<<"Array is not Empty!";
	} 
}

//Enqueue Function
int enqueue(int x){
	
	if ((rear+1)%n == front){
		cout<<"Queue Overflow";;
	}
	else if(rear == -1 && front == -1){
		rear++;
		front++;
		
		arr[rear] = x;
		
		count++;
	}
	else{
		rear = (rear + 1) % n;
		arr[rear] = x;
		
		count++;
	}
	return rear;	
	
}

//Dequeue function
int dequeue(){
	
	if(rear == -1 && front == -1){
		cout<<"Stack Underflow!";
	}
	else if(front == rear){
		front = -1;
		rear = -1;
		
		count--;
	}
	else{
	//	front = (front + 1) % n;
		front++;
		
		count--;
	}
	return front;
}


int main(){
	
	isEmpty();
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(70);
	enqueue(10);

	
	cout<<"\nBefore Dequeue : ";
	for(int i = 0; i<= count; i++){
		
		int index = (front+i) % 10;  // Index of element while travesing circularly from front
		
		cout<<arr[index]<<" ";
	}

	dequeue();

	
	cout<<"\nAfter Dequeue : ";
	for(int i = 0; i<= count; i++){
		
		int index = (front+i) % 10; // Index of element while travesing circularly from front
		
		cout<<arr[index]<<" "; //if we do not put index in this statement So delete elements from end.
	}
}
