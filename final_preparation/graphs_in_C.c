#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
#define WHITE -1
#define GRAY -2
#define BLACK -3

struct node{
	int vertex;
	int col;
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

///directedgraph
void addEdge(struct Graph* graph, int src, int dest){ //eg addEdge(graph, 0, 1);
	//add edge from src to dest
	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
	

}


bool isAcyclic(struct Graph* g){
	//stack is already initialized
	int col[100];
	for (int i=0; i<g->numVertices; ++i){
		col[i] = WHITE;
	}
		
	for (int i=0; i<g->numVertices; ++i){
		if (col[i] == WHITE){
			push(i);
			col[i] = GRAY;
		}
		while(!isempty()){
			int cur = pop();
			struct node *tmp = g->adjLists[cur];
			while(tmp!=NULL){ 	//for all neighbors of the popped vertex
				if(col[tmp->vertex] == GRAY){
					printf("The graph is not a DAG!\n");
					return false;
				}else if(col[tmp->vertex] == WHITE){
					push(tmp->vertex);
					col[tmp->vertex] = GRAY;
					tmp = tmp->next;
				}
			}		
		}	
	}
	printf("The graph is a DAG!\n");
	return true;
}





int main(){
	struct Graph *g1 = createGraph(5);
	addEdge(g1, 0,1);
	//addEdge(g1, 1,2);
	addEdge(g1, 0,2);
	addEdge(g1, 2,3);
	addEdge(g1, 3,4);
	addEdge(g1, 2,1);
	
	int res = isAcyclic(g1);
	printf("res: %d", res);	
}

