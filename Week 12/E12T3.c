#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

///DEF FROM STACK, FROM EXERCISE 7
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value)
{
    if(top<SIZE-1)
    {
        if (top < 0)
        {
            stack[0] = value;
            top = 0;
        }
        else
        {
            stack[top+1] = value;
            top++;
        }
    }
    else
    {
        printf("Stackoverflow!!!!\n");
    }
}

int isempty()
{
    return top<0;
}

int pop()
{
    if(!isempty())
    {
        int n = stack[top];
        top--;
        return n;
    } 
    else
    {
        printf("Error: the stack is empty!\n");
        return -99999;
    }
}

int Top()
{
    if (!isempty()) 
    {
        return stack[top];
    } 
    else 
    {
        printf("Error: the stack is empty!\n");
        return -99999;
    }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d,",stack[i]);
    }
    printf("\n");
}
///UNTIL HERE; STACK DEFINITION, 

///IMPLEMENTATION OF GRAPH
struct node{
	int vertex;
	struct node* next;
};

struct Graph{
	int numVertices;
	//we need int** to store a two dimensional array
	//similarly, we need struct node** to store an array of linked lists
	struct node** adjLists;
};

struct node* createNode(int v);


struct node* createNode(int v){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices){
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	
	graph->adjLists = malloc(vertices * sizeof(struct node*));
	
	int i;
	for (i = 0; i < vertices; i++){
		graph->adjLists[i] = NULL; //setting every value in the adj.list to 0
	}
	return graph;
}


void addEdge(struct Graph* graph, int src, int dest){ //eg addEdge(graph, 0, 1);
	//add edge from src to dest
	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
	
	//add edge from dest to src
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}


//to implement: fct that prints a DFS on the graph from start vertex
//before we implement the fct, we also need an implementation of a STACK
void DFS(struct Graph* graph, int start){ //if you find an unvisited node, put it into the stack!
	int visited[SIZE] = {0};  //keeps track of already visited nodes, direct adressing (vertex with value 0 is in arr[0]!)
	struct node *tmp;
	int cur_vertex;
	int time = 0;
	push(start); //stack is already initialized, so no need to do it
	visited[start] = 1;
	printf("DFS represenatiton: ");
	while(isempty() == false){
		cur_vertex = pop();
		printf("%d - ", cur_vertex);
		++time;
		//for all adj nodes..
		tmp = graph->adjLists[cur_vertex];
		while(tmp != NULL){
			if(visited[tmp->vertex] == 0 ){
				visited[tmp->vertex] = 1;
				push(tmp->vertex);
			}
			tmp = tmp->next;
		}
	}
}


void DFS_SOL(struct Graph * graph, int start) {
  bool added[graph->numVertices];
  memset(added, false, sizeof added);
  push(start);
  added[start] = true;
  while(!isempty()){
    int current = pop();
    // mark current node as visited and print it.
    struct node* adjList = graph->adjLists[current];
    struct node* temp = adjList; 
    printf("Visited %d \n", current);
    while (temp != NULL) { // while we still have neighbours
      int connectedVertex = temp->vertex;
      if (added[connectedVertex] == 0) { // if they are unvisited, visit them
          push(connectedVertex);
          added[connectedVertex] = true;
      }
      temp = temp->next; //check next neighbour
    }
  }
}


int main(){
	struct Graph *g1 = createGraph(5);
	addEdge(g1, 0,4);
	addEdge(g1, 0,2);
	addEdge(g1, 1,2);
	addEdge(g1, 2,3);

	
	for(int i=0; i < g1->numVertices; ++i){ //prints all 5 vertices
		struct node* tmp = g1->adjLists[i];
		printf("Adjacency list of vertex %d:	", i);
		while(tmp != NULL){
			printf("%d -> ", tmp->vertex);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("\n");
	
	DFS(g1, 0);
	

	
	return 0;
}

