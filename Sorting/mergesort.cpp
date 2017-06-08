#include <iostream>
using namespace std;
void merge(int *a, int start, int mid, int end){
	int n1 = mid-start+1;
    int n2 = end -mid;
    int L[n1], R[n2];
    int i=0,j=0,k=0;
    while(i<n1){
        L[i] = a[start+i];
        i++;
    }
    while(j<n2) {
        R[j] = a[mid+1+j];
        j++;
    }
    i=j=0;
    k=start;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            a[k]=L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        a[k] = L[i];
        k++;i++;
    }
    while(j<n2) {
        a[k] = R[j];
        k++;j++;
    }
}
void mergesort(int *a, int start, int end){
	if(start<end){
		int mid = start + (end-start)/2;
		mergesort(a, start, mid);
		mergesort(a, mid+1, end);
		merge(a, start, mid, end);
	}
}        

int main(){
	int A[] ={4,447,65,12,8,26,12,3,8,9,46};
	int n = sizeof(A)/sizeof(int);
	mergesort(A,0,10);
	for (int i=0;i<11;i++){
		cout<<A[i]<<" ";
	}
}