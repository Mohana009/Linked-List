//reversing linked list using array 

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node* Create_node(int val){
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->next = NULL;
	return nn;
}
void Insert_tail(int val){
	struct node *nn = Create_node(val);
	if(head == NULL){
		head = nn;
		tail = nn;
	}
	else{
		tail->next = nn;
		tail = nn;
	}
}
void Insert_head(int val){
	struct node *nn = Create_node(val);
	if(head == NULL){
		head = nn;
		tail = nn;
	}
	else{
		nn->next = head;
		head = nn;
	}
}
void Insert_position(int val, int pos){
	struct node *nn = Create_node(val);
	struct node *temp = head;
	int c = 1;
	while(c < pos - 1){
		temp = temp->next;
		c++;
	}
	struct node *p1 = temp;
	struct node *p2 = temp->next;
	p1->next = nn;
	nn->next = p2;
}
void Delete_head(){
	if(head == NULL)	return;
	head = head->next;
}
void Delete_tail(){
	if(head == NULL)	return;
	struct node *temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = NULL;
}
void Delete_position(int pos){
	if(head == NULL)	return;
	struct node *temp = head;
	int c = 1;
	while(c < pos - 1){
		temp = temp->next;
		c++;
	}
	struct node *p1 = temp;
	struct node *p2 = temp->next->next;
	p1->next = p2;
}
void Display(){
	if(head == NULL)	return;
	struct node *temp = head;
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int size(){
	struct node *temp = head;
	int s = 0;
	while(temp){
		temp = temp->next;
		s++;
	}
	return s;
}
void reverse(){
	int *arr;
	int s = size();
	arr = (int*)malloc(sizeof(int)*s);
	struct node *temp = head;
	int i = 0;
	while(i < s){
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
	temp = head;
	int j = s - 1;
	while(j >= 0){
		temp->data = arr[j];
		temp = temp->next;
		j--;
	}
	
}
int main(){
	int n;
	printf("Enter no.of nodes: ");
	scanf("%d", &n);
	int val;
	printf("\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		Insert_tail(val);
	}
	Display();
//	Delete_head();
//	Display();
//	Delete_tail();
// 	Display();
//	Delete_position(1);
//	Display();
//	Insert_head(0);
//	Insert_tail(100);
//	Display();
//	Insert_position(200, 3);
//	Display();
	reverse();
	Display();
	
	
}

/*Enter no.of nodes: 5

1 2 3 4 5
1 2 3 4 5
5 4 3 2 1

--------------------------------
Process exited after 3.753 seconds with return value 0
Press any key to continue . . .


*/