#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
int main(){
	struct Node *head;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data = 10;
	head->next = NULL;
	
	struct Node *first;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = 20;
	first->next = NULL;
	head->next = first;
	while(head != NULL){
		printf("%d\n", head->data);
		head = head->next;
	}
	
	
}