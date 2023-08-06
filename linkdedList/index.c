#include<stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
void push(struct node** phead,int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	struct node* current = *phead;
	if (*phead == NULL) {
		*phead = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

}
void rec_push(struct node** phead,int data){
	
	if (*phead == NULL) {
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		*phead = newNode;
		return;
	}
	else {
		rec_push(&((*phead)->next),data);
	}


}
void delete_el_from_list(struct node** phead,int element ){
	struct node* current = (*phead)->next;
	struct node* prev = *phead;

	while (current->next != NULL) {
		
		if (current->data == element) {
			prev->next = current->next;
			free(current);
			return;
		}
		prev = prev->next;
		current = current->next;
	}
	
	

}
void delete_all_rec(struct node** phead) {
	if (*phead == NULL) {
		return;
	}
	delete_all_rec(&((*phead)->next));
	free(*phead);
	*phead = NULL;

}
void print(struct node* headNode) {
	if (headNode == NULL) {
		return;
	}
	printf("%d\n", headNode->data);
	print(headNode->next);
}
main() {
	struct node* headNode = NULL;
	for (int i = 0; i < 10; i++)
	{
		/*push(&headNode, i);*/
		rec_push(&headNode, i);
	}
	/*delete_el_from_list(&headNode, 7);*/
	/*delete_all_rec(&headNode);*/
	print(headNode);
}
