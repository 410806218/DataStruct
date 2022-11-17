// HW5.cpp : 定義主控台應用程式的進入點。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 20 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};                                                                          /////

class ArrayPolynomial {                                        /////
public:                                                                  /////
	PolynomialTerm terms[MAX_TERMS]; /////

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo) /////
	{
		int i;
		for ( i = 0; i < MAX_TERMS; i++) {
			//int j;
			if (terms[i].expo == expo) {
				
				if (coef == 0) {
					break;
				}
				else {
					terms[i].coef = coef;
					return;
				}
			}
			else if (terms[i].expo < expo) {
				int j = 0;
				for (j = MAX_TERMS - 2; j >= i; j--) {
					terms[j] = terms[j - 1];
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


		return;
	}

	void addArrayBasedPoly(ArrayPolynomial& a, ArrayPolynomial& b) /////
	{	
		int posa = 0;
		int posb = 0;
		
		for (int i = 0; i < MAX_TERMS; i++) {
			if (a.terms[posa].coef == 0 && b.terms[posb].coef == 0) {
			break;
		}
			if (a.terms[posa].expo > b.terms[posb].expo) {
				terms[i].coef = a.terms[posa].coef;
				terms[i].expo = a.terms[posa].expo;
				posa++;
			}
			else if (a.terms[posa].expo < b.terms[posb].expo) {
				terms[i].coef = b.terms[posb].coef;
				terms[i].expo = b.terms[posb].expo;
				posb++;
			}
			else if (a.terms[posa].expo == b.terms[posb].expo) {
				terms[i].coef = a.terms[posa].coef + b.terms[posb].coef;
				terms[i].expo = a.terms[posa].expo;
				if (terms[i].coef==0) {
					i--;
				}
					posa++;
					posb++;

			}







		}

		

		return;
	}

	void reverseArrayBasedPoly() /////
	{
		int c=0;
		for (int i = 0; i < MAX_TERMS; i++) {
			if (terms[i].expo == 0 && terms[i].coef == 0) {
				break;
			}
			c = c + 1;
		}
		c = c - 2;
		for (int i = 0; i <c; i++) {
			
				PolynomialTerm tep;
				tep = terms[i];
				terms[i] = terms[c];
				terms[c] = tep;
				c--;
			}

		return;
	}

	void printArrayBasedPoly() /////
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			std::cout << terms[0].coef;
		else
			std::cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				std::cout << " + " << terms[i].coef;
			else
				std::cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	int compute(int x)
	{
		int co = 0;
		for (int i = 0; i < MAX_TERMS; i++) {
			co = co + (terms[i].coef * (pow(x, terms[i].expo)));
		}



		// add your code here


		return co;

		
	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm* nextTermPtr; /////
};                                                                  /////

class LinkPolynomial {                                /////
public:                                                          /////
	LinkedPolynomialTerm* polynomialTermPtr = nullptr; /////

	void clear() /////
	{
		LinkedPolynomialTerm* tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputLinkTerms(int coef, int expo) /////
	{
		LinkedPolynomialTerm* newnode;
		LinkedPolynomialTerm* curptr;
		LinkedPolynomialTerm* preptr;
		
		newnode = new LinkedPolynomialTerm;
		newnode->coef = coef;
		newnode->expo = expo;
		newnode->nextTermPtr = nullptr;
		if (polynomialTermPtr == nullptr &&  coef == 0) {
			printf("check point87");
			return;
		}

		if (polynomialTermPtr == nullptr) {
			printf("check point1");
			polynomialTermPtr = newnode;
			return;
		}
		
		curptr = polynomialTermPtr;
		preptr = nullptr;
		while (curptr) {
			
			if (expo>curptr->expo) {
				if (preptr == nullptr) {
					newnode->nextTermPtr = curptr;
					preptr = newnode;
					polynomialTermPtr = newnode;
					return;
				}
				else {
					newnode->nextTermPtr = curptr;
					preptr->nextTermPtr = newnode;
					return;
				}
			}
			else if(curptr->expo==newnode->expo) {
				curptr->coef = newnode->coef;
				if (curptr->coef == 0) {
					if (preptr==nullptr) {
						printf("check point");
						polynomialTermPtr = curptr->nextTermPtr;
						return;
					}
					else {
						printf("check point");
						preptr->nextTermPtr = curptr->nextTermPtr;
						
						return;
					}

				}
				else {
					return;
				}
			}
			else {
				if (curptr->nextTermPtr != nullptr) {
					preptr = curptr;
					curptr = curptr->nextTermPtr;
				}
				else {
					curptr->nextTermPtr = newnode;
					return;
				}
			} 
		}
		return;
	}

	void addLinkBasedPoly(LinkPolynomial& aPol, LinkPolynomial& bPol) /////
	{
		LinkPolynomial a = aPol;
		LinkPolynomial b = bPol;
		while (a.polynomialTermPtr != nullptr && b.polynomialTermPtr != nullptr) {
			
			if (a.polynomialTermPtr->expo > b.polynomialTermPtr->expo) {
				//printf("check point");
				inputLinkTerms(a.polynomialTermPtr->coef, a.polynomialTermPtr->expo);
				a.polynomialTermPtr = a.polynomialTermPtr->nextTermPtr;
				
			}
			else if (a.polynomialTermPtr->expo < b.polynomialTermPtr->expo) {

				inputLinkTerms(b.polynomialTermPtr->coef, b.polynomialTermPtr->expo);
				b.polynomialTermPtr = b.polynomialTermPtr->nextTermPtr;

			}
			else if (a.polynomialTermPtr->expo == b.polynomialTermPtr->expo) {
				if (a.polynomialTermPtr->coef + b.polynomialTermPtr->coef != 0) {
					inputLinkTerms(a.polynomialTermPtr->coef + b.polynomialTermPtr->coef, a.polynomialTermPtr->expo);
					a.polynomialTermPtr = a.polynomialTermPtr->nextTermPtr;
					b.polynomialTermPtr = b.polynomialTermPtr->nextTermPtr;
				}
				else {
					a.polynomialTermPtr = a.polynomialTermPtr->nextTermPtr;
					b.polynomialTermPtr = b.polynomialTermPtr->nextTermPtr;
				}

			}
		}
		while (a.polynomialTermPtr == nullptr && b.polynomialTermPtr != nullptr) {
			inputLinkTerms(b.polynomialTermPtr->coef, b.polynomialTermPtr->expo);
			b.polynomialTermPtr = b.polynomialTermPtr->nextTermPtr;
		}
		while (a.polynomialTermPtr != nullptr && b.polynomialTermPtr == nullptr) {
			inputLinkTerms(a.polynomialTermPtr->coef, a.polynomialTermPtr->expo);
			a.polynomialTermPtr = a.polynomialTermPtr->nextTermPtr;
		}

		return;
	}

	void reverseLinkBasedPoly() /////
	{
		LinkedPolynomialTerm* b = NULL;
		LinkedPolynomialTerm* a = polynomialTermPtr;
		if (polynomialTermPtr == NULL) {
			return;
		}
		do {
			b = a;
			a = a->nextTermPtr;
		} while (a);
		a = b;
		b = polynomialTermPtr;
		LinkedPolynomialTerm* c = NULL;

		do {
			if (b == a) {
				break;
			}

			c = new 	LinkedPolynomialTerm;
			c->coef = b->coef;
			c->expo = b->expo;
			c->nextTermPtr = a->nextTermPtr;
			a->nextTermPtr = c;
			b = b->nextTermPtr;
		} while (b != a);

		polynomialTermPtr = a;

		return;
	}

	void printLinkBasedPoly()                                                            /////
	{
		LinkedPolynomialTerm* termPtr = polynomialTermPtr; /////

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;

		while (termPtr != nullptr) {
			if (termPtr->coef == 0)
				return;

			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}

	int compute(int x)
	{
		LinkedPolynomialTerm* pre = NULL;
		LinkedPolynomialTerm* first = polynomialTermPtr;
		if (polynomialTermPtr == NULL) {

			return 0;


		}
		int t = 0;
		do {
			t = t + first->coef * (pow(x, first->expo));
			pre = first;
			first = first->nextTermPtr;
		} while (first);




		return t;
	}


		// add your code here


		
	
};

int main()
{
	ArrayPolynomial a, b, d;                                                              /////
	LinkPolynomial aPol, bPol, dPol;                                             /////

	int coef, expo, x;

	// aPtr = bPtr = dPtr = nullptr; /////

	while (1) {
		a.clear(); b.clear(); d.clear();                                    /////
					  // aPtr->clear(aPtr); bPtr->clear(bPtr); dPtr->clear(dPtr); /////


		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			a.inputTerms(coef, expo);             /////
			aPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\na = ";
		a.printArrayBasedPoly();     /////
		cout << "\na = ";
		aPol.printLinkBasedPoly(); /////
		cout << "\n";

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			b.inputTerms(coef, expo);             /////
			bPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\nb = ";
		b.printArrayBasedPoly();      /////

		cout << "\nb = ";
		bPol.printLinkBasedPoly(); /////

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		d.addArrayBasedPoly(a, b); /////
		cout << "\na + b = ";
		d.printArrayBasedPoly();     /////

		dPol.addLinkBasedPoly(aPol, bPol); /////
		cout << "\na + b = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		d.reverseArrayBasedPoly(); /////
		cout << "\nreversed d = ";
		d.printArrayBasedPoly();     /////

		dPol.reverseLinkBasedPoly(); /////
		cout << "\nreversed d = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		cout << "\ninput X: ";
		cin >> x;

		cout << "\nd = ";
		cout << d.compute(x);      //////

		cout << "\nd = ";
		cout << dPol.compute(x); //////

		cout << "\n";

		aPol.clear(); bPol.clear(); dPol.clear(); /////
	}

	return 0;
}
