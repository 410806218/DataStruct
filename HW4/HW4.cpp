// HW4.cpp : 定義主控台應用程式的進入點。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 20 /*size of terms array*/

typedef struct{
	int coef;
	int expo;
} polynomialTerm;

typedef struct linkedTerm {
	int coef;
	int expo;
	linkedTerm *nextTermPtr;
} linkedPolynomialTerm;

void clear(polynomialTerm t[]) 
{
	for ( int i = 0; i < MAX_TERMS; i++ ) {
		t[i].coef = 0;
		t[i].expo = 0;
	}

	return;
}

void clear(linkedPolynomialTerm *&polynomialTermPtr) 
{
	linkedPolynomialTerm *tmpPtr;

	while ( polynomialTermPtr != nullptr ) {
		tmpPtr = polynomialTermPtr;
		polynomialTermPtr = polynomialTermPtr->nextTermPtr;
		delete tmpPtr;
	}
}

void inputTerms(polynomialTerm terms[], int coef, int expo)
{

	int i;
	int j;
	//-5 5 4 4 3 3 3 3 -7 7 0 0
	//6 6 5 5 7 7 -3 3 -5 11 0 0
	
		for(i=0;i<MAX_TERMS;i++){
			if(terms[i].expo==expo){
//				terms[i].coef=coef;
				if(coef==0){
//					for(j=i;j<=MAX_TERMS;j++){
//						terms[j]=terms[j+1];
//					}
					break;	
				}
				else{
						terms[i].coef = coef;
						return;
				}
			}	
			else if(terms[i].expo<expo){
				for(j=MAX_TERMS-2;j>=i;j--){
					terms[j]=terms[j-1];
				}
			
				break;
			}
				
		}
		terms[i].expo = expo;
		terms[i].coef = coef;
		if (terms[i], coef == 0) {
			for (int k = i; k <MAX_TERMS - 1; k++) {
				terms[k] = terms[k + 1];
			}
		}
	// add your code here




	return;
}

void inputLinkTerms(linkedPolynomialTerm *&polyPtr, int coef, int expo)
{
	linkedPolynomialTerm *newnode;
	newnode = new linkedPolynomialTerm;
	newnode->coef = coef ;
	newnode->expo = expo;
	newnode->nextTermPtr = nullptr;
	linkedPolynomialTerm *curptr=polyPtr;
	linkedPolynomialTerm *preptr=nullptr;
	if (polyPtr == nullptr &&  coef == 0) {
		
			return;
		}
	if(polyPtr==nullptr){
		polyPtr=newnode;
		return;
	}	

	while(curptr){
		if(expo>curptr->expo){
			if(preptr==nullptr){
				newnode->nextTermPtr=curptr;
				preptr=newnode;
				polyPtr=newnode;
				return;
			}
			else{
				newnode->nextTermPtr=curptr;
				preptr->nextTermPtr=newnode;
				return;
			}
		}
		else if (expo==curptr->expo){
			curptr->coef = newnode->coef;
			if (curptr->coef == 0) {
				if(preptr==nullptr){
					polyPtr=curptr->nextTermPtr;
						return;
				}
				else{
					//	printf("checkpoint 3 \n");
						preptr->nextTermPtr=curptr->nextTermPtr;
						return;
					}
				}	
			else{
				return;	
			}
			
			
			
		}
		
		else{
			if(curptr->nextTermPtr!=nullptr){
				//printf("aaaa4");
				preptr=curptr;
				curptr=curptr->nextTermPtr;
				//printf("aaaa5");
			}
			else{
				//printf("aaaa6");
				curptr->nextTermPtr=newnode;
				return;
			}
			
		
			}
		

	}
		//curptr->nextTermPtr=newnode;
		
//		if(curptr->nextTermPtr!=nullptr){
//				curptr->nextTermPtr=newnode;
//				
//			}
			

	return;
}


void addArrayBasedPoly(polynomialTerm a[], polynomialTerm b[], polynomialTerm d[])
{

	int i;
	int j;
	int k=0;
	for(i=0;i<MAX_TERMS;i++){
		d[i]=a[i];
	}
	for(i=0;i<MAX_TERMS;i++){
		int expo=b[i].expo;
		int coef=b[i].coef;
		for(j=0;j<MAX_TERMS;j++){
			if(d[j].expo==expo){
				coef=d[j].coef+coef;
				break;	
			}
			
			if(d[j].expo<expo){
				for(k=MAX_TERMS-2;k>=j;k--){
					d[k]=d[k-1];
				}
				
				break;
			}
			
		}
				d[j].expo=expo;
				d[j].coef=coef;
			if(d[j].coef==0){
				for(k=j;k<MAX_TERMS-1;k++){
						d[k]=d[k+1];
					}
	
				}
	
	
	
	
	}
	

	// add your code here


	

	return;
}

linkedPolynomialTerm *addLinkBasedPoly(linkedPolynomialTerm *aPtr, linkedPolynomialTerm *bPtr)
{
	linkedPolynomialTerm* dPtr = nullptr;

	// add your code here
	linkedPolynomialTerm* aCurr = aPtr;
	linkedPolynomialTerm* bCurr = bPtr;
	int coef, expo;
	
	while (aCurr != nullptr && bCurr != nullptr) {
		if (aCurr->expo > bCurr->expo) {
			inputLinkTerms(dPtr, aCurr->coef, aCurr->expo);
			aCurr = aCurr->nextTermPtr;
		}
		else if (aCurr->expo < bCurr->expo) {
			inputLinkTerms(dPtr, bCurr->coef, bCurr->expo);
			bCurr = bCurr->nextTermPtr;
		}
		else if (aCurr->expo == bCurr->expo) {
			coef = aCurr->coef + bCurr->coef;
			if (coef != 0) {
				inputLinkTerms(dPtr, coef, aCurr->expo);
				aCurr = aCurr->nextTermPtr;
				bCurr = bCurr->nextTermPtr;
			}
			else {
				aCurr = aCurr->nextTermPtr;
				bCurr = bCurr->nextTermPtr;
			}
			
		}	
	}
	while(aCurr == nullptr&&bCurr!=nullptr){

			inputLinkTerms(dPtr, bCurr->coef, bCurr->expo);
			bCurr = bCurr->nextTermPtr;
		}
	while (bCurr == nullptr&&aCurr!=nullptr) {
			inputLinkTerms(dPtr, aCurr->coef, aCurr->expo);
			aCurr = aCurr->nextTermPtr;
		}
	
	return dPtr;
}

void printArrayBasedPoly(polynomialTerm terms[])
{
	if ( terms[0].coef == 0 ) 
		return;

	if ( terms[0].expo == 0 )
		cout << terms[0].coef;
	else
		cout << terms[0].coef << "X^" << terms[0].expo;

	for ( int i = 1; i < MAX_TERMS; i++ ) {
		if ( terms[i].coef == 0 ) 
			return;

		if ( terms[i].expo == 0 )
			cout << " + " << terms[i].coef;
		else
			cout << " + "<< terms[i].coef  << "X^" << terms[i].expo;
	}
}

void printLinkBasedPoly(linkedPolynomialTerm *polyPtr)
{
	linkedPolynomialTerm *termPtr =  polyPtr;

	if ( termPtr  == nullptr )
			return;

	if ( termPtr->expo == 0 )
		cout << termPtr->coef;
	else
		cout << termPtr->coef << "X^" << termPtr->expo;

	termPtr  = termPtr->nextTermPtr;
	
	while ( termPtr  != nullptr ) {
		if ( termPtr->coef == 0 ) 
			return;

		if ( termPtr->expo == 0 )
			cout << " + " << termPtr->coef;
		else
			cout << " + "<< termPtr->coef  << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;
	}
}

int main()
{
	polynomialTerm a[MAX_TERMS], b[MAX_TERMS], d[MAX_TERMS];
	linkedPolynomialTerm *aPtr, *bPtr, *dPtr;

	int coef, expo;

	aPtr = bPtr = dPtr = nullptr;

	while (1) {
		clear( a ); clear( b ); clear( d );
		clear( aPtr ); clear( bPtr ); clear( dPtr );

		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerms( a, coef, expo );
			inputLinkTerms( aPtr, coef, expo );
		}

		cout << "\n\na = ";
		printArrayBasedPoly( a );
		cout << "\na = ";
		printLinkBasedPoly( aPtr );
		cout << "\n";
		
		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerms( b, coef, expo );
			inputLinkTerms( bPtr, coef, expo );
		}

		cout << "\n\nb = ";
		printArrayBasedPoly( b );

		cout << "\nb = ";
		printLinkBasedPoly( bPtr );

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		addArrayBasedPoly( a, b, d );
		cout << "\na + b = ";
		printArrayBasedPoly( d );
		
		dPtr = addLinkBasedPoly( aPtr, bPtr );
		cout << "\na + b = ";
		printLinkBasedPoly( dPtr );

		cout << "\n";
	}
	return 0;
}
 
