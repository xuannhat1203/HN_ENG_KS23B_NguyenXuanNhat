#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertStart(Node** head, int data) {
    Node* newNode = createNode(data); 
    newNode->next = *head;           
    *head = newNode;                 
}
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertPosition(Node** head,int data,int position){
	Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteStart(Node** head){
	if(head == NULL) return;
	Node* temp = *head;
	*head = temp->next;
}
void deleteEnd(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteValue(Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;        
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;       
        temp = temp->next;  
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
}
void findElement(Node* node, int data) {
    Node* temp = node;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Co phan tu trong danh sach\n");
            return; 
        }
        temp = temp->next; 
    }
    printf("Khong co phan tu dang tim trong danh sach\n");
}

void printList(Node* node){
	Node* temp = node;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
int main(){
	int choice;
	int data;
	Node* node = NULL;
	int position;
	do{
		printf("\n---------------MENU---------------\n");
		printf("1. Them phan tu vao dau danh sach\n");
		printf("2. Them phan tu vao cuoi danh sach\n");
		printf("3. Chen phan tu vao vi tri cu the\n");
		printf("4. Xoa phan tu dau danh sach\n");
		printf("5. Xoa phan tu cuoi danh sach\n");
		printf("6. Xoa phan tu theo gia tri\n");
		printf("7. Tim kiem phan tu theo gia tri\n");
		printf("8. In danh sach ra man hinh\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap du lieu muon them: ");
				scanf("%d",&data);
				insertStart(&node,data);
				printf("Da them phan tu vao dau thanh cong\n");
				break;
			case 2:
				printf("Nhap du lieu muon them: ");
				scanf("%d",&data);
				insertEnd(&node,data);
				printf("Da them phan tu vao cuoi thanh cong\n");
				break;
			case 3: 
				printf("Nhap du lieu muon them: ");
				scanf("%d",&data);
				printf("Nhap vi tri muon them: ");
				scanf("%d",&position);
				insertPosition(&node,data,position);
				printf("Them thanh cong");
				break;
			case 4: 
				deleteStart(&node);
				printf("Da xoa thanh cong\n");
				break;
			case 5:
				deleteEnd(&node);
				printf("Xoa thanh cong");
				break;
			case 6: 
				printf("Nhap du lieu muon xoa:");
				scanf("%d",&data);
				deleteValue(&node,data);
				break;
			case 7:
				printf("Nhap phan tu muon tim kiem: ");
				scanf("%d",&data);
				findElement(node,data);
				break;
			case 8: 
				printList(node);
				break;
			default:
				printf("Lua chon khong hop le!!!!");
				break;
				
		}
		
	}while(1==1);
}

