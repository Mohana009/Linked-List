//Singly linkedlist

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;	
};
struct Node *head = NULL;
struct Node *tail = NULL;

//To create a Node
struct Node* Create_A_Node(int val){
	struct Node *nn;
	nn = (struct Node*)malloc(sizeof(struct Node*));
	nn->data = val;
	nn->next = NULL;
	return nn;
}

//To insert the created node at tail (At end) 
void Insert_At_Tail(int val){
	struct Node *nn = Create_A_Node(val);
	if(head == NULL){	//checking if linked list is empty
		head = nn;
		tail = head;
	}
	else{	
		tail->next = nn;		//Placing the new node after the current tail
		tail = tail->next;		//Making the inserted node as tail
	}
}

//To insert the created node at head (Beginning)
void Insert_At_Head(int val){
	struct Node *nn = Create_A_Node(val);
	if(head == NULL){	//checking if linked list is empty
		head = nn;
		tail = head;
	}
	else{
		nn->next = head;	//Placing the new node before the current head
		head = nn;			//Making the inserted node as head
	}
}

//To insert the created node in the middle (At position)
void Insert_At_Middle(int pos, int val){
	
	//Identifying the previous node and the target(correct position) node 
	//corresponding to the given position i.e, p1 and p2
	
	struct Node *nn = Create_A_Node(val);
	struct Node *temp = head;
	int count = 1;
	while(count < pos - 1){
		temp = temp->next;
		count++;
	}
	struct Node *p1 = temp;
	struct Node *p2 = temp->next;
	p1->next = nn;		//Inserting new node between p1 & p2
	nn->next = p2;
}

//To delete a node at head
struct Node* Delete_At_Head(struct Node *head){
	if(head == NULL)	printf("List is empty\n"); //Checking if linked list empty
	head = head->next;		
	return head;
}

//To delete a node at tail
void Delete_At_Tail(struct Node *head, struct Node *tail){
		struct Node *temp = head;
		int count = 1;
		temp = head;
		while(temp->next->next){	//finding the previous node to the tail
			temp = temp->next;
			count++;
		}
		temp->next = NULL;	//Pointing the previous node's next to null removes the link to tail
}
	
//To delete a node in middle
void Delete_At_Middle(int pos, struct Node *head){
	
  //Identifying the previous node and next node corresponding to the given position i.e, p1 and p2
	//linking p1's next to p2 deletes the node at given position
  
	struct Node *temp = head;
	int count = 1;
	while(count < pos - 1){
		temp = temp->next;
		count++;
	}
	struct Node *p1 = temp;
	struct Node *p2 = temp->next->next;
	p1->next = p2;
}

//To print the Linked List
void Display(struct Node *head){
	struct Node *temp = head;
	printf("\n");
	while(temp){
		printf("%d  ", temp->data);
		temp =temp->next;
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf("\nEnter data: ");
	int val;
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		Insert_At_Tail(val);
	}
	Display(head);
	int c;
	printf("\nClick 1 for inserting data at tail.");
	printf("\nClick 2 for inserting data at head.");
	printf("\nClick 3 for inserting data at middle.");
	printf("\nClick 4 for deleting data at head.");
	printf("\nClick 5 for deleting data at tail.");
	printf("\nClick 6 for deleting data at middle.");
	printf("\nClick 0 to exit.");
	while(1){
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
	else if(c == 0) break;
	else	printf("\nPlease select one of these options.");
	}
}


