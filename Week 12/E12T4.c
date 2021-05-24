#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define GRIDSIZE 7
#define MAXQSIZE 49

struct Point{
    int x;
    int y;
};

struct queueNode
{
    struct Point pt;  // The cordinates of a cell
    int dist;  // cell's distance of from the source
};

bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < GRIDSIZE) &&
           (col >= 0) && (col < GRIDSIZE);
}

struct queueNode queue[MAXQSIZE]; //initialize QUEUE

int front = -1;
int rear = -1;
int size = -1;

bool q_isempty()
{
    return size < 0;
}

void q_enqueue(struct queueNode value)
{
    if(size<MAXQSIZE)
    {
        if(size<0)
        {
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXQSIZE-1)
        {
            queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            queue[rear+1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int q_dequeue()
{
    if(size<0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        size--;
        front++;
    }
}

struct queueNode q_front()
{
    return queue[front];
}


////FUNCTION WE NEED TO IMPLEMENT...
int sp_algo(int A[GRIDSIZE][GRIDSIZE], struct Point start, struct Point end){
	int visited[GRIDSIZE][GRIDSIZE];
	for (int i=0; i<GRIDSIZE; ++i){
		for(int j=0; j<GRIDSIZE; ++j){
			visited[i][j] = -1;
		}
	}

	//all 4 directions we can go to (up,down,left,right)
	int row_num[] = {-1, 0, 0, 1};
	int col_num[] = {0, -1, 1, 0};
	
	struct queueNode n1;
	struct queueNode tmp;
	n1.dist = 0;
	n1.pt = start;
	q_enqueue(n1);
	
	while(q_isempty() == false){
		tmp = q_front();
		q_dequeue();
		if(tmp.pt.x == end.x && tmp.pt.y == end.y){ //we found it!!!
			return tmp.dist;
		}
		///else, search the neighbors!
		for(int i=0; i<4; ++i){
			int new_row = tmp.pt.x + row_num[i];
			int new_col = tmp.pt.y + col_num[i];
			if (isValid(new_row, new_col) == true && visited[new_row][new_col] == -1 && A[new_row][new_col] == '.'){
						struct queueNode adjCell;
						struct Point new_point;
						new_point.x = new_row;
						new_point.y = new_col;
						adjCell.dist = tmp.dist+1;
						adjCell.pt = new_point;
						visited[new_row][new_col] = 1;
						q_enqueue(adjCell);		
			}
	
		}
	}
}




int main() {
  int A[7][7] =
    {
        { '.', '.', '#', '.', '.', '#', '#'},
        { '.', '.', '#', '.', '.', '.', '.'},
        { '.', '.', '#', '.', '#', '.', '.'},
        { '.', '.', '#', '.', '#', '.', '#'},
        { '#', '.', '#', '.', '#', '.', '.'},
        { '.', '.', '#', '.', '.', '#', '.'},
        { '#', '.', '.', '.', '.', '.', '.'},
    };
  struct Point start = {0, 0};
  struct Point end = {2, 6};

  	int spDist = sp_algo(A, start, end);
  	printf("It takes a total of %d steps to reach the destination!\n", spDist);
}
