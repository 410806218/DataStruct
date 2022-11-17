#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "iostream"

using namespace std;

struct node {
	int data;
	node* next;
};
void print(node* first) {
	node* tep = first;
	while (tep) {
		cout << " " << tep->data << " " ;
		tep = tep->next;
	}
}
node *insert (node*first,int data){
	node *newnode=new node;
	node *curptr=first;
	node *preptr=nullptr;
	newnode->data=data;
	newnode->next=nullptr;
	
	if(curptr==nullptr){
		first=newnode;
		return first;
	}
	while(curptr!=nullptr){
		if(data<curptr->data){
			if(preptr==nullptr){
				newnode->next=curptr;
				first=newnode;
				return first;
				}
		
				else{
					
					preptr->next=newnode;
					newnode->next=curptr;
					return first;
				}
			}
			else{
			preptr=curptr;
			curptr=curptr->next;	
			}
			
				
		
	}	
		preptr->next=newnode;
		return first;
	}	
	node* del(node* first, int n) {
	node* tep = first;
	node* pre = nullptr;
	while (tep) {

		if (n == tep->data) {
			if (pre == nullptr) {
				tep = tep->next;
				first = tep;
			}
			else if (tep == nullptr) {
				pre->next = NULL;
			}
			else {
				pre->next = tep->next;
				tep = tep->next;
			}
		}
		else {
			pre = tep;
			tep = tep->next;

		}
	}

	return first;







}
	
	
	
	

int main() {
	int input;
	node* first = nullptr;
	char id;

	while (1) {

		cout <<endl<< "d or l" << endl;
		cout << endl;
		cin >> id;
		if (id == 'l') {
			cin >> input;
			

			
			first = insert(first, input);
			print(first);
		}
		else if (id == 'd') {
			cin >> input;


			first = del(first, input);
			print(first);
		}

	}

	system("pause");
	return 0;
}


