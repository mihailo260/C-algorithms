#include<stdio.h>
#include<stdlib.h>
struct Node;



typedef struct ListNode {
	struct Node* node;
	struct ListNode* next;
}LISTNODE;
typedef struct Node {
	int ID;
	struct ListNode* head;
}NODE;

typedef struct Graph {
	NODE* nodes[9];
	int V;
}GRAPH;

GRAPH* createGraph(int numElem);
NODE* createNode(int ID);
LISTNODE* createListNode(NODE* node);
void addEdge(GRAPH* graph,int src,int dest);
void BFS(GRAPH* graph, int startID);


void initQueue(NODE* nodes[]);
void enqueue(NODE* nodes[],NODE* node);
void deQueue(NODE* nodes[]);
bool isQueueEmpty(NODE* nodes[]);
int main() {
	GRAPH* graph = createGraph(9);
	addEdge(graph, 0,1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 4, 2);
	addEdge(graph, 2, 5);
	addEdge(graph, 2, 3);
}


GRAPH* createGraph(int numElem) {
	GRAPH* graphPtr = (GRAPH*)malloc(sizeof(GRAPH));
	/*graphPtr->nodes = (NODE**)malloc(sizeof(NODE*) * numElem);*/
	int i;
	for ( i = 0; i < numElem; i++)
	{
		graphPtr->nodes[i] = NULL;
	}
	graphPtr->V = numElem;
	return graphPtr;
}
NODE* createNode(int ID) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->head = NULL;
	node->ID = ID;
	return node;
}
LISTNODE* createListNode(NODE* node) {
	LISTNODE* listNode = (LISTNODE*)malloc(sizeof(LISTNODE));
	listNode->node = node;
	listNode->next = NULL;
}
void addEdge(GRAPH* graph, int src, int dest) {
	NODE* srcPtr;
	NODE* destPtr;
	LISTNODE* srclistPtr;
	LISTNODE* destlistPtr;
	if (graph->nodes[src] != NULL) {
		srcPtr = graph->nodes[src];
	}
	else {
		srcPtr = createNode(src);
		graph->nodes[src] = srcPtr;
	}
	if (graph->nodes[dest] != NULL) {
		destPtr = graph->nodes[dest];
	}
	else {
		destPtr = createNode(dest);
		graph->nodes[dest] = destPtr;
	}
	srclistPtr = createListNode(srcPtr);
	destlistPtr = createListNode(destPtr);
	LISTNODE* current;
	if (srcPtr->head == NULL) {
		srcPtr->head = destlistPtr;
	}
	else {
		current = srcPtr->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = destlistPtr;
	}


	if (destPtr->head == NULL) {
		destPtr->head = srclistPtr;
	}
	else {
		current = destPtr->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = srclistPtr;
	}
	
}