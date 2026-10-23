//Circular Linkedlist 


#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;	
};
struct Node *head = NULL;
struct Node *tail = NULL;
//To print the Linked List
void Display(struct Node *head){
	struct Node *temp = head;
	while(temp){
		printf("%d  ", temp->data);
		temp =temp->next;
	}
	printf("\n");
}
//To create a Node
struct Node* Create_A_Node(int val){
	struct Node *nn;
	nn = (struct Node*)malloc(sizeof(struct Node*));
	nn->data = val;
	nn->next = NULL;
	return nn;
}
void Create_Circular_LL(int val){
		struct Node *nn = Create_A_Node(val);
		if(head == NULL){
			head = nn;
			tail = head;
			tail->next = head;	//tail pointing to head: As there is only one node it points to itself
		}
		else{
			tail->next = nn;
			tail = tail->next;
			tail->next = head;	//tail pointing to head
		}
		
	
}
int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf("\nEnter data: ");
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		Create_Circular_LL(val);
	}
	Display(head);
}