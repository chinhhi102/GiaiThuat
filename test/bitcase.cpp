#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(i,a,b) for(ll i=a;i<b;i++)
typedef struct LinkedList *node;
struct LinkedList{
	int data;
	struct LinkedList *next;
};
node creatNode(){
	node temp;
	(node)malloc(sizeof(struct LinkedList));
	temp->next=NULL;
	return temp;
}
node addNode(node head,int value){
	node temp,p;
	temp=creatNode();
	temp->data=value;
	if(head==NULL)
		head=temp;
	else{
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
	}
	return head;
}
int main() {
	int n;
	node a=NULL;
	cin>>n;
	fora(i,0,n){
		int x;
		cin>>x;
		a=addNode(a,x);
	}
	while(a!=NULL){
		cout<<a->data<<" ";
		a=a->next;
	};
	return 0;
}
