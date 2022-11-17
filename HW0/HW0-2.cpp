
#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;
int main(){
	int count=-1;
	int i=0;
	int b;
	int A[500];
	int t=0;
	char id;
	while(1){
		cin>>id;
		if (id == 'l') {
		cin>>b;
		count++;
		A[count]=b;
		if(count==0){
				for(t=0;t<=count;t++){
		cout<<A[t]<<" ";	
		}
			continue;
		}
	
	
		
		for(i=0;i<=count;i++){
			int j=0;
			if(A[i]>=b&&A[i-1]<=b){
			
				for(j=count;j>=i;j--){
					A[j]=A[j-1];
		
					
			}
				A[i]=b;
				break;
			}
		}
		
		for(t=0;t<=count;t++){
		cout<<A[t]<<" ";	
		}
	
		
		cout<<endl;
	}
	else if (id == 'D') {
			int D;
			cin >> D;
			
				for (int i = 0; i <= count; i++) {
					if (A[i] == D) {
						for (int j = i; j <count; j++) {
							A[j] = A[j + 1];
							
						}
						i--;
						count--;
					}
				}
			
			

			for (int i = 0; i <= count; i++) {
				printf("%d ", A[i]);
			}
			printf("\n");


		}
}
}
