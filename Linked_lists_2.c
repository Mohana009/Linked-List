#include<stdio.h>
#include<stdlib.h>
#define lld long long 
struct Node{
	lld Adhar;
	struct Node *next;
};
int main(){
	printf("%d\n", sizeof(struct Node));
	//Creating a node
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->Adhar = 12345678901;
	head->next = NULL;
	//Another node
	struct Node *first;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->Adhar = 34567889013;
	first->next = NULL;
	head->next = first;
	//Another node
	struct Node *second;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->Adhar = 678907543;
	second->next = NULL;
	first->next = second;
	//Printing data from nodes
	while(head != NULL){
		printf("%lld ", head->Adhar);
		printf("%p\n", head->next);
		head = head->next;
	}
	
}