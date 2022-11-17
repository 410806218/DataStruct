// HW0.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

#define MAX 5

struct Node
{
	int item;
	Node* next;
};

typedef Node* nodePtr;

Node *inputData(int num, nodePtr headPtr)
{
	nodePtr currentPtr = headPtr;

	nodePtr tmpPtr = (nodePtr) malloc(sizeof(Node)) ; 
	tmpPtr->item = num;
	tmpPtr->next = NULL;

	if(headPtr == NULL)
		return tmpPtr;
	else	{
		while ( currentPtr->next != NULL )
			currentPtr = currentPtr->next;

		currentPtr->next = tmpPtr;

		return headPtr;
	}
}

void printArrayForward(int A[])
{
	int i=0;
	for(i=0;i<MAX;i++){
		cout<<A[i]<<" ";
	}
	return;

}


void printArrayBackward(int A[], int i)
{
	 
	if(i<MAX){
	
		cout<<A[MAX-i-1]<<" ";	
	}
	else{
		return;
	}
	printArrayBackward(A,i+1);

	// add your code here


}

void printListForward(nodePtr ptr)
{
	nodePtr currentptr;
	currentptr=ptr;
	while(currentptr!=nullptr){
		cout<<currentptr->item<<" ";
		currentptr=currentptr->next;
	}

	


}

void printListBackward(nodePtr ptr)
{

	if(ptr->next!=nullptr){
		printListBackward(ptr->next);
		
	}
	cout<<ptr->item<<" ";
	return;
	
	
	
	// add your code here


}

int main()
{
	int num;
	int A[MAX] = {0};
	nodePtr headPtr = NULL;

	printf("Input %d numbers: ", MAX);
	
	for ( int i=0; i<MAX; i++ ) {
		cin >> num;
		A[i] = num;
		headPtr = inputData( num, headPtr );
	}

	printf("\nArray Forward Iteratively:  ");
	printArrayForward(A);
	printf("\nArray Backward Recursively: ");
	printArrayBackward(A, 0);

	printf("\nList Forward Iteratively:  ");
	printListForward(headPtr);
	printf("\nList Backward Recursively: ");
	printListBackward(headPtr);

	printf("\n");
	system("PAUSE");
	return 0;
}
