#include <iostream>
#include<vector>
using namespace std;
template <class T>
class heap {
	vector<T>list;
	int getparent(int child){
		return child%2==0?(child/2) -1 :child/2;
	}	
	int getlchild(int parent) {
		return parent*2 +1;
	}
	int getrchild(int parent){
		return parent*2+2;
	}
	void swap(int child, int parent){
		T tmp = list[child];
			list[child] = list[parent];
			list[parent] = tmp; 
	}
	void bubbleup(){
		int child = list.size() -1;
		int parent = getparent(child);
		while(child>=0&&parent>=0 && list[child]<list[parent]){
			swap(child, parent);
			child = parent;
			parent = getparent(child);
		}
	}
	void bubbledown(){
		int parent = 0;
			while(1){
			int left = getlchild(parent);
			int right =getrchild(parent);
			int largest = parent;
			int length = list.size() ;
			if(left<length && list[left]<list[largest]) largest = left;
			if(right<length && list[right]<list[largest] ) largest = right;
			if(largest !=parent) {
				swap(largest, parent);
				parent = largest;			
			}
			else break;
		}
	}
public:
	void insert(int el){
		list.push_back(el);
		bubbleup();
	}
	T remove(){
		int child = list.size()-1;
		swap(child, 0);
		T value = list.back();
		list.pop_back();
		bubbledown();
		return value;
	}
	int getsize(){
		return list.size();
	}
};
int main(){
	heap<int> h;
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++) cin>>array[i];
	
	for(int i=0;i<n;i++) h.insert(array[i]);
	int k;
cin>>k;
for(int i=0;i<k;i++){
	cout<<h.remove()<<" ";
}



}