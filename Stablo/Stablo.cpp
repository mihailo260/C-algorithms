
#include <stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Queue
{
    struct Node* node;
    struct Queue* next;
    int level;
};
struct Node* nizKaoQueue[100];
//funkcije za queue----------------
void init();
void enqueue(Node* element);
void dequeue();




void enqueue2(struct Queue** proot, struct Node* newNode,int level){
    struct Queue* newQueueNode = (struct Queue*)malloc(sizeof(struct Queue));
    newQueueNode->node = newNode;
    newQueueNode->next = NULL;
    newQueueNode->level = level;
    if (*proot == NULL) {
        *proot = newQueueNode;

        return;
    }
    struct Queue* current = *proot;
    while(current->next !=NULL){
        current = current->next;
    }
    current->next = newQueueNode;

}
void dequeue2(struct Queue** phead) {
    struct Queue* newphead = (*phead)->next; 
    free(*phead);
    *phead = newphead;
}
bool isEmptyQueue(struct Queue* root){
    if (root == NULL) {
        return true;
    }
    return false;
}


//funkicje za stablo-------------
void addNode(struct Node** proot, struct Node* newNode);
void addNodeIterative(struct Node** proot, struct Node* newNode);
void deleteAllRec(struct Node** proot);
void printTree(struct Node* root);
struct Node* createNode(int data);
void printTreeByLevel(struct Node* root);
void deleteNodeinTree(struct Node** proot,int elem) {
    if (*proot == NULL) {
        return;
    }
    if (elem == (*proot)->data) {
        
        
        if ((*proot)->left == NULL && (*proot)->right == NULL) {
            free(*proot);
            *proot = NULL;
            return;
        }
        else if((*proot)->left == NULL && (*proot)->right != NULL) {
            struct Node* temp = *proot;
            *proot = (*proot)->right;
            free(temp);
        }
        else if ((*proot)->left != NULL && (*proot)->right == NULL) {
            struct Node* temp = *proot;
            *proot = (*proot)->left;
            free(temp);
        }
        else {
            struct Node* temp = *proot;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*proot)->data = temp->data;
            deleteNodeinTree(&(*proot)->right, temp->data);
        }
    }
    if (elem > (*proot)->data) {
        
        deleteNodeinTree(&(*proot)->right, elem);
    }
    else {
        
        deleteNodeinTree(&(*proot)->left, elem);
    }
}
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;

}
struct Node* delete_node(struct Node* root,int elem){
    if (root == NULL) {
        return root;
    }
    else if (elem < root->data) {
        root->left = delete_node(root->left, elem);
        
    }
    else if (elem > root->data) {
        root->right = delete_node(root->right, elem);
    }
    else {
        if (root->right == NULL && root->left == NULL) {
            free(root);
            root = NULL;
            
        }
        else if (root->right == NULL && root->left != NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->right != NULL && root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);

        }

    }
    return root;
}

int main()
{
    int arr[] = {4,5,6,8,1,5,58,3,0,-11,42};
    int length = sizeof(arr) / sizeof(int);

    struct Node* root = NULL;
    
    for (int i = 0; i < length; i++)
    {
        struct Node* node =  createNode(arr[i]);
        addNode(&root, node);  
    }
    
    /*delete_node(root, 6);*/
    deleteNodeinTree(&root, 6);
    printTreeByLevel(root);

}











void addNode(struct Node** proot, struct Node* newNode) {
    if (*proot == NULL) {
        *proot = newNode;
        return;
    }
    if (newNode->data < (*proot)->data) {
        addNode(&(*proot)->left, newNode);
    }
    else {
        addNode(&(*proot)->right, newNode);
    }
}


void deleteAllRec(struct Node** proot) {
    if (*proot == NULL) {
        return;
    }
    deleteAllRec(&(*proot)->left);
    deleteAllRec(&(*proot)->right);
    free(*proot);
    *proot = NULL;

}

void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d\n", root->data);
    printTree(root->right);
}
void printTreeByLevel(struct Node* root) {

    struct Queue* qroot = NULL;
    int tekuciRed = 1;
    if (root == NULL) {
        return;
    }
    enqueue2(&qroot, root,tekuciRed);
    while (!isEmptyQueue(qroot)) { 
        if (qroot->node->left != NULL) {
            enqueue2(&qroot, qroot->node->left, qroot->level + 1);
        }
        if (qroot->node->right != NULL) {
            enqueue2(&qroot, qroot->node->right, qroot->level + 1);
        }
        if (qroot->level != tekuciRed) {
            printf("\n");
            tekuciRed++;
        }
        printf("%d ", qroot->node->data);
        dequeue2(&qroot);
        
    }
}
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void init() {
    for (int i = 0; i < 100; i++) {
        nizKaoQueue[i] = NULL; 
    }
}
void enqueue(Node* element){
    int i = 0;
    while (nizKaoQueue[i] != NULL) {
        i++;
    }
    nizKaoQueue[i] = element;
}
void dequeue(){
    for (int i = 0; i < 99; i++) {
        nizKaoQueue[i] = nizKaoQueue[i+1];
        if (nizKaoQueue[i] == NULL) {
            break;
        }
    }
}
