// HW3.cpp : 定義主控台應用程式的進入點。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 20

typedef struct{
	int coef;
	int expo;
} polynomialTerm;

void clear(polynomialTerm t[]) 
{
	for ( int i = 0; i < MAX_TERMS; i++ ) {
		t[i].coef = 0;
		t[i].expo = 0;
	}

	return;
}

void printArrayBasedPoly(polynomialTerm t[])
{
	if ( t[0].coef == 0 ) 
		return;

	if ( t[0].expo == 0 )
		cout << t[0].coef;
	else
		cout << t[0].coef << "X^" << t[0].expo;

	for ( int i = 1; i < MAX_TERMS; i++ ) {
		if ( t[i].coef == 0 ) 
			return;

		if ( t[i].expo == 0 )
			cout << " + " << t[i].coef;
		else
			cout << " + "<< t[i].coef  << "X^" << t[i].expo;
	}
}

void inputTerm(polynomialTerm t[], int coef, int expo)
{
	int i;
	int j;
	//-5 5 4 4 3 3 3 3 -7 7 0 0
	//6 6 5 5 7 7 -3 3 -5 11 0 0
		for(i=0;i<MAX_TERMS;i++){
			if(t[i].expo==expo){
				t[i].coef=coef;
				if(coef==0){
					for(j=i;j<=MAX_TERMS;j++){
						t[j]=t[j+1];
					}
					break;	
				}
				break;	
			}	
			if(t[i].expo<expo){
				for(j=MAX_TERMS-2;j>=i;j--){
					t[j]=t[j-1];
				}
				t[i].expo=expo;
				t[i].coef=coef;
				break;
			}
				
		}

	// add your code here


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

int main()
{
	polynomialTerm a[MAX_TERMS], b[MAX_TERMS], d[MAX_TERMS];
	int coef, expo;

	while (1) {
		clear( a ); clear( b ); clear( d );

		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerm( a, coef, expo );
		}

		cout << "\n\na = ";
		printArrayBasedPoly( a );
		cout << "\n";
		
		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerm( b, coef, expo );
		}

		cout << "\n\nb = ";
		printArrayBasedPoly( b );
		cout << "\n";

		// d =a + b, where a, b, and d are polynomials
		addArrayBasedPoly( a, b, d );
		cout << "\na + b = ";
		printArrayBasedPoly( d );
		cout << "\n";
	}

	return 0;
}
