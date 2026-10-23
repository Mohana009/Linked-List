//Double Linkedlists

//For Users
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;	
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
	nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = val;
	nn->next = NULL;
	nn->prev = NULL;
	return nn;
}
//To insert the created node at tail 
void Insert_At_Tail(int val){
		struct Node *nn = Create_A_Node(val);
		if(head == NULL){
			head = nn;
			tail = head;
		}
		else{
			tail->next = nn;
			nn->prev = tail;
			tail = tail->next;	//tail = nn;
		}
		
	
}
//To insert the created node at head
void Insert_At_Head(int val){
	struct Node *nn = Create_A_Node(val);
	if(head == NULL){
		head = nn;
		tail = head;
	}
	else{
		nn->next = head;
		head->prev = nn;
		head = nn;	//head = head->prev;
	}

}
//To insert created node in the middle
void Insert_At_Middle(int pos, int val){
	struct Node *nn = Create_A_Node(val);
	struct Node *temp = head;
	int count = 1;
	while(count < pos - 1){
		temp = temp->next;
		count++;
	}
	struct Node *p1 = temp;
	struct Node *p2 = temp->next;
	p1->next = nn;
	nn->prev = p1;
	nn->next = p2;
	p2->prev = nn;
	
}
//To delete a node at head
struct Node* Delete_At_Head(struct Node *head){
	head = head->next;
	return head;
}
//To delete a node at tail
void Delete_At_Tail(struct Node *head, struct Node *tail){
		struct Node *temp = head;
		int nodes_count = 1;
		while(temp->next != NULL){
			nodes_count++;
			temp = temp->next;
		}
		int count = 1;
		temp = head;
		while(count < nodes_count - 1){
			temp = temp->next;
			count++;
		}
		
		temp->next = NULL;
	}
//To delete a node in middle
void Delete_At_Middle(int pos, struct Node *head){
	struct Node *temp = head;
	int count = 1;
	while(count < pos - 1){
		temp = temp->next;
		count++;
	}
	struct Node *p1 = temp;
	struct Node *p2 = temp->next->next;
	p1->next = p2;
	p2->prev = p1;
	
	
}

//To print in reverse
void Display_in_reverse(struct Node* tail){
	struct Node *temp = tail;
	while(temp->prev){
		printf("%d ", temp->data);
			temp = temp->prev;
	}
	printf("%d ", temp->data);
}
int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf("\nEnter data: ");
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		Insert_At_Tail(val);
	}
	Display(head);
	int s = 100;
	int c;
	printf("\nClick 1 for inserting data at tail.");
	printf("\nClick 2 for inserting data at head.");
	printf("\nClick 3 for inserting data at middle.");
	printf("\nClick 4 for deleting data at head.");
	printf("\nClick 5 for deleting data at tail.");
	printf("\nClick 6 for deleting data at middle.");
	printf("\nClick 7 to print reverse linked list.");
	printf("\nClick 0 to exit.");
	while(s){
	printf("\nEnter your choice: ");
	scanf("%d", &c);
	if(c == 1){
			int val;
			printf("\nEnter value: ");
			scanf("%d", &val);
			Insert_At_Tail(val);
			Display(head);
	}
	else if(c == 2){
			int val;
			printf("\nEnter value: ");
			scanf("%d", &val);
			Insert_At_Head(val);
			Display(head);
	}
	else if(c == 3){
			int pos, val;
			printf("\nEnter position: ");
			scanf("%d", &pos);
			printf("\nEnter value: ");
			scanf("%d", &val);
			Insert_At_Middle(pos, val);
			Display(head);
	}
	else if(c == 4){
			head = Delete_At_Head(head);
			Display(head);
	}		
	else if(c == 5){
	Delete_At_Tail(head, tail);
	Display(head);
	}
	else if(c == 6){
		int p;
		printf("\nEnter the position: ");
		scanf("%d", &p);
		Delete_At_Middle(p, head);
		Display(head);
	}
	else if(c == 7){
		Display_in_reverse(tail);
	}	
	else if(c == 0) break;
	else	printf("\nInvalid option.\nPlease select one of these options.");
	} 
		
}