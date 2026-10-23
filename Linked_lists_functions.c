//inserting at head and tail//
#include<stdio.h>
#include<stdlib.h>

//creating user define data type using struct for node
struct Node{
    int data;
    struct Node *next;
    
};


struct Node *head = NULL;
struct Node *tail = NULL;


//O(1)
struct Node* Create_A_Node(int val){
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    
    return newnode;
}
//O(n)
void Display(struct Node *head){
    struct Node* temp = head;
    while(temp){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
//O(n) --> O(1)
void Insert(int val){
    //check it is first node or not 
    struct Node *nn = Create_A_Node(val); // 2
    if(head == NULL){
        head = nn;
        tail = head;
    }
    else{
        tail->next = nn;
        tail = tail->next;
    }
}
void Insert_At_Head(int val){
	struct Node *nn = Create_A_Node(val);
		struct Node *temp = head;
		head = nn;
		head->next = temp;
}
struct Node* Delete_At_Head(struct Node *head){
	head = head->next;
	return head;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int val;
        scanf("%d", &val); // 1 2
        Insert(val);
    }
    Insert_At_Head(5);	//5 will come at starting
    //Insert_At_Position(pos, val);
    Display(head);
    printf("\n");
    head = Delete_At_Head(head);
    Display(head);
    
    
    
}