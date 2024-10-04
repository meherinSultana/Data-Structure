#include <bits/stdc++.h>
using namespace std;

int graph[20][20];
int status[20];

struct Node
{
    int val;
    Node* next;

    Node(int x)
    {
        val = x;
        next = NULL;
    }
};
Node* head;

void enqueue(int node)
{

    Node* n = new Node(node);

    if(head == NULL )
    {
        head= n;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = n;
    }
}
int dequeue()
{
    int value;
    if(head == NULL)
        return 0;
    Node* temp = head;
    value = temp -> val;
    head = head -> next;

    delete(temp);

    return value;

}
bool isEmpty()
{
    return head == NULL;

}
void inputGraph(int N, int E)
{
    int x,y;
    for(int i=0; i<E; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }
}
void printAM(int N)
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}
void initStatus(int N)
{
    for(int i=1; i<=N; i++)
    {
        status[i]=1;
    }
}
void addNeighbors(int N, int nodeN)
{
    for(int i=0; i<=N; i++)
    {
        if(graph[nodeN][i]==1)
        {
            if(status[i]==1)
            {
                enqueue(i);
                status[i]=1;
            }
        }
    }
}
void bfs(int source, int n)
{
    //step 1
    initStatus(n);

    //step 2
    enqueue(source);
    status[source] = 2;

    //step 3
    while(!isEmpty())
    {
        //step 4
        int N = dequeue();
        printf("node: %d\t", N);
        status[N] = 3;
        //step 5
        addNeighbors(n,N);

    }
}

int main()
{
    int n,e, source;
    printf("Enter no of Node: ");
    scanf("%d",&n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);

    printf("Enter no of Source: ");
    scanf("%d", &source);
    inputGraph(n,e);
    printAM(n);
    bfs(source,n);

    return 0;
}

