#include <stdio.h>

#include "memory.h"
#include <iostream>
using namespace std;
#define MAX_degree 20 /*MAX degree of polynomial+1*/

typedef struct{
	int degree;
	int coef [MAX_degree];
} polynomial;

#define MAX_TERMS 50 /*size of terms array*/
typedef struct{
	int coef;
	int expo;
} polynomial_term;

polynomial_term terms [MAX_TERMS];
int avail = 0;
	
polynomial Zero(polynomial p)
{
	memset(&p, 0, sizeof(p));

	return p;
}

int IsZero(polynomial p)
{
	
	if (!p.degree&&!p.coef[p.degree]){
		return 1;
	}

	return 0;
}

int Lead_Exp(polynomial p)
{
	return p.degree;
}

int COMPARE(int i, int j)
{
	if(i<j){
		return -1;
	
	} 
	if(i==j){
		return 0;
	
	} 
	if(i>j){
		return 1;
	
	} 

	
	return 0;
}

int Coef(polynomial p, int expo)
{
	return p.coef[expo];
}

polynomial Attach(polynomial p, int coef, int expo)
{
	if(p.degree<expo){
		p.degree=expo;
	}
	p.coef[expo]=coef;

		

	return p;
}

polynomial Remove(polynomial p, int expo)
{
	int i;
	p.coef[expo]=0;
	if(p.degree==expo){
		p.degree=0;
		for(i=0;i<MAX_degree;i++){
			if(i>p.degree&&p.coef[i]!=0)
				p.degree=i;
		}
	}
	
	return p;
}

void attach(int coef, int expo)
{
	if (avail >= MAX_TERMS)   
		return;

	terms[avail].coef = coef;
	terms[avail++].expo = expo;
}

void PrintPoly1(polynomial p)
{
	for (int i = p.degree; i >= 0; i--) {
		if (p.coef[i] != 0 ) {
			if (p.degree == i) {
				if (i == 0 )
					printf("%d", p.coef[i]);
				else
					printf("%dX^%d", p.coef[i], i);
			}
			else {
				if ( i == 0 )
					printf(" + %d", p.coef[i]);
				else
					printf(" + %dX^%d", p.coef[i], i);
			}
		}
	}
}

void PrintPoly2(polynomial_term t[], int start, int finish)
{
	int i;
	int j;
	for(i=start;i<finish;i++){
	for(j=start;j<finish;j++){
		if(t[j].expo<t[j+1].expo){
			polynomial_term temp=t[j];
			t[j]=t[j+1];
			t[j+1]=temp;
		}
	}	
}	
//	for(i=start;i<=finish;i++){
//			printf("      %dX^%d     ",t[i].coef,t[i].expo);
//		}
//	printf("\n\n\n\n");
	for(i=start;i<finish;i++){
			
		if(t[i].expo==t[i+1].expo||t[i].coef==0){
			
			for(j=i;j<=finish;j++){
			if(t[i+1].coef==0&&t[i+1].expo==0){
				break;
				}
				t[j]=t[j+1];
				}
			i--;
			finish--;	
		}	
			
	}

	for(i=start;i<=finish+1;i++){
		
		if(t[i].expo!=0&&t[i].coef!=0){
			
			printf("%dX^%d",t[i].coef,t[i].expo);
		}
		else if(t[i].expo==0&&t[i].coef!=0){	
				printf("%d",t[i].coef);
		}
	
		else{
			continue;
		}
		
				
		if(i!=finish&&t[i+1].coef!=0){
			
			//printf("t[i].coef: %d  ",t[i].coef);
			printf(" + ");
	
		
		}
		
		
		
		
		
	}
		

}

polynomial padd1(polynomial p1, polynomial p2)
{
	polynomial p3;
	int sum;

	p3.degree = 0;
	p3 = Zero(p3);

	while ( ! IsZero(p1) && ! IsZero(p2) ) {
	   switch ( COMPARE( Lead_Exp(p1), Lead_Exp(p2) ) ) {
		   case -1: 
			   p3 = Attach(p3, Coef(p2, Lead_Exp(p2)), Lead_Exp(p2));
			   p2 = Remove(p2, Lead_Exp(p2));
			   break;
		  case  0:
			  sum = Coef(p1, Lead_Exp (p1)) + Coef( p2, Lead_Exp(p2));
			  
			  if (sum)
				  p3 = Attach (p3, sum, Lead_Exp(p1));
			  
			  p1 = Remove(p1 , Lead_Exp(p1));
			  p2 = Remove(p2 , Lead_Exp(p2));
			  break;
		  case 1:
			  p3 = Attach(p3, Coef (p1, Lead_Exp(p1)), Lead_Exp(p1));
			  p1 = Remove(p1, Lead_Exp(p1));
	   }  
	}

	while (!IsZero(p1) ) {
		p3 = Attach(p3, Coef (p1, Lead_Exp(p1)), Lead_Exp(p1));
		p1 = Remove(p1, Lead_Exp(p1));
	}
	while (!IsZero(p2) ) {
		p3 = Attach(p3, Coef (p2, Lead_Exp(p2)), Lead_Exp(p2));
		p2 = Remove(p2, Lead_Exp(p2));
	}

	return p3;
}

void padd2(int starta, int finisha, int startb, int finishb, int* startd, int* finishd)
{
	int sum;

	*startd = avail;

	while (starta <= finisha && startb <= finishb) {
		switch (COMPARE( terms[starta].expo, terms[startb].expo) ) {
		   case -1: 
			   attach(terms[startb].coef, terms[startb].expo);
			   startb++;
			   break;
		  case  0:
			  sum = terms[starta].coef + terms[startb].coef;
			  
			  if (sum)
				  attach(sum, terms[starta].expo);
			  starta++;
			  startb++;			  
			  break;
		  case 1:
			   attach(terms[starta].coef, terms[starta].expo);
			   starta++;
	   }  
	}

	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expo);
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expo);

	*finishd = avail -1;
}

int main()
{
	polynomial a, b, d;
	int coef, expo, sum;
	
	int starta = 0, finisha, startb, finishb, startd, finishd;
	
	memset(terms, 0, sizeof(terms));

	a.degree = b.degree = d.degree = 0;

	a = Zero(a);
	b = Zero(b);
	d = Zero(d);

	while (1) {
		printf("\ninput a's coefficient and exponent: ");
		scanf_s("%d %d", &coef, &expo);

		if (expo == 0 && coef == 0)
			break;

		a.coef[expo] = coef;

		if (a.degree < expo)
			a.degree = expo;

		terms[avail].coef = coef;
		terms[avail].expo = expo;
		avail++;
	}

	finisha = avail - 1;
	startb = avail;

	printf("\n\na = ");
	PrintPoly1(a);
	printf("\na = ");
	PrintPoly2(terms, starta, finisha);
	printf("\n");

	while (1) {
		printf("\ninput b's coefficient and exponent: ");
		scanf_s("%d %d", &coef, &expo);

		if (expo == 0 && coef == 0)
			break;

		b.coef[expo] = coef;

		if (b.degree < expo)
			b.degree = expo;

		terms[avail].coef = coef;
		terms[avail].expo = expo;
		avail++;
	}

	finishb = avail - 1;

	printf("\n\nb = ");
	PrintPoly1(b);
	printf("\nb = ");
	PrintPoly2(terms, startb, finishb);

	/* d =a + b, where a, b, and d are polynomials */

	d = padd1(a, b);
	printf("\n\nd = ");
	PrintPoly1(d);
	
	padd2(starta, finisha, startb, finishb, &startd, &finishd);
	printf("\nd = ");
	PrintPoly2(terms, startd, finishd);

  	return 0;
}
