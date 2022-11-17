// HW1.cpp : 定義主控台應用程式的進入點。
//

//#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

void input(string sMessage, string &sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;

	return;
}

void writeBackwardI(string s)
{
	int length = s.size();

	if ( length == 0 )  // base case 
		return;

	for ( int i = length - 1; i >= 0; i-- )
		cout << s[i];
}

void writeBackwardR1(string s)
{
	int length = s.size();

	if ( length == 0 )  // base case 
		return;

	cout << s[length - 1];
	writeBackwardR1( s.substr( 0, length - 1 ) );
}

void writeBackwardR2(string s)
{
	int length = s.size();

	if ( length == 0 )  // base case 
		return;

	writeBackwardR2( s.substr( 1, length - 1 ) );
	cout << s[0];
}


int countI(string s, char c)
{
	int length = s.size();
	int i;
	int count=0;
	for(i=0;i<s.size();i++){
		if(s[i]==c){
			count=count+1;
		}
	}

	return count;
}

int countR(string s, char c)
{
	int length = s.size();
	int count=0;
//found p
 //happy->appy->ppy->py->y
if(s.size()>0){
	if(s[0]==c){
		
		return count+countR(s.substr( 1, length - 1 ),c)+1;
	}
	else{
		return count+countR(s.substr( 1, length - 1 ),c);
	}
}
else{
	return count;
}
	
}

unsigned char findI(string s)
{
	int length = s.size();
	cout<<"length:"<<length<<endl;
	cout<<"s[5]:"<<s[length]<<endl;
	char max;
	max=s[0];
	int i=0;
	for(i=0;i<s.size();i++){
		if(s[i]<max){
			max=s[i];
		}
	}
	
	return max;
}

char findRR(string s)
{	
	//char min=s[0];
	//cout<<"out if s:"<<s<<endl;
	int length = s.size();
	//cout<<"out if s[0]:"<<s[0]<<endl;
	//cout<<"length:"<<length<<endl;
	//cout<<"s.size:"<<s.size()<<endl;
	if(s.size()>1){
		//cout<<"in if1 s[0]:"<<s[0]<<endl;
		if(s[0]>s[length-1]){
			//cout<<"in if s[0]:"<<s[0]<<endl;
			s[0]=s[length-1];
			
		//	cout<<"s[0]:"<<s[0]<<endl;
		//	cout<<"length:"<<length<<endl;
		//	cout<<"s.size:"<<s.size()<<endl;
			return findRR(s.substr( 0, length - 1 ));
			
					
		}
		else{
			
			return findRR(s.substr( 0, length - 1 ));
			
		} 
	}
	else{
		//cout<<"aaa"<<endl;
		//cout<<"s.size()<1: "<<s[0]<<endl;
		//cout<<"min: "<<min<<endl;
		return s[0];
	}
	
		
		


	


}
char findR(string s)
{
	int length = s.size();
	char count=s[0];
	if (length > 1) {
		count = findR(s.substr(1, length - 1));
	}
	if (s[0] > count) {
		s[0] = count;
	}

	return s[0];
}
string removeI(string s)
{
	int length = s.size();
	int i;
	int j;
	for(i=0;i<length;i++){
		if(s[i]==s[i+1]){
			for(j=i;j<length;j++){
				s[j]=s[j+1];
			}
			i--;
			length--;
		}
		
	}
	
	return s;
}

string removeR(string s)
{
	string c;
	//cout<<"s"<<s<<endl;
	
	int length = s.size();
	if(s.size()>1){
		c = removeR(s.substr(1, length - 1));
	}
	if(s[0]!=c[0]){
		s=s[0]+c;
	}
	else{
		s=c;
	}
return s;
	
}

int TI( int m, int n)
{

int c = 0;
	for (int i = 0; i < m; i++) {
		c = c + n;
	}

	/*
		T(m, n) = 0, if m = 0 or n = 0
		T(m, n) = m + ... + m (n times), if m > n
		T(m, n) =  n + ... + n (m times), otherwise
	*/

	return c;
}

int TR( int m, int n)
{
	int c = 0;
	if (m>n){
	if (m > 1) {
		c += TR(m - 1, c + n);
	}
	c = c + n;
	}
	else{
		if (n > 1) {
		c += TR(c+m, n-1);
	}
	c = c + m;
	}

	return c;
/*
	T(m, n) = 0, if m = 0 or n = 0
	T(m, n) = m + T( m, n - 1 ), if m > n
	T(m, n) =  n + T( m - 1, n ), otherwise
*/
		return m * n;
}

int main()
{
	string commandStr;	
	string inputStr, appendStr;
	char inputChr;
	int m, n;

	while (1) {
		input( "\nEnter command: "
			"\n I to input a string, A to append a string, B to write the string backward, "
			"\n C to count the given character , F to find the smallest character,"
			"\n R to remove the repeated characters, T to compute, and X to Exit", commandStr );
	
		if ( commandStr == "I"  || commandStr == "i" ) {
			cout << "\nInput the string: ";
			cin >> inputStr;
		} 
		else if ( commandStr == "A"  || commandStr == "a" ) {
			cout << "\nInput the string: ";
			cin >> appendStr;
			inputStr += appendStr;
			cout << "\nThe new string: " << inputStr << endl;
		} 
		else if ( commandStr == "B" || commandStr == "b" ) {
			if ( inputStr.length() > 0 ) {
				cout << endl;
				writeBackwardI( inputStr );
				cout << endl;
				writeBackwardR1( inputStr );
				cout << endl;
				writeBackwardR2( inputStr );
				cout << endl;
			}
		}
		else	if ( commandStr == "C"  || commandStr == "c" ) {
			if ( inputStr != "" ) {
				cout << "\nInput the character: ";
				cin >> inputChr;
				cout << "\nCount of " << inputChr <<": " << countI( inputStr, inputChr );
				cout << "\nCount of " << inputChr <<": " << countR( inputStr, inputChr ) << endl;
			}
		}
		else if ( commandStr == "R" || commandStr == "r" ) {
			if ( inputStr != "" ) {
				cout << endl << "Repeated characters removed: " << removeI( inputStr ) ;
				cout << endl << "Repeated characters removed: " << removeR( inputStr ) << endl;;
			}
		}
		else if ( commandStr == "F" || commandStr == "f" ) {
			if ( inputStr != "" ) {
				cout << endl << "Smallest character found: " << findI( inputStr );
				cout << endl << "Smallest character found: " << findR( inputStr ) << endl;
				cout << endl << "Smallest character found: " << findRR( inputStr ) << endl;
			}
		}
		else  if ( commandStr == "T" || commandStr == "t" ) 
		{
			cout << "\nInput two values, m and n: ";
			cin >> m >> n;
			cout << endl << "The result is " << TI( m, n );
			cout << endl << "The result is " << TR( m, n ) << endl;
		}
		else  if ( commandStr == "X" || commandStr == "x" ) 
			return 0;	
		else
			cout << "\nUnknown command!";
	}
  	return 0;
}
