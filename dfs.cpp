#include <bits/stdc++.h>
using namespace std;

int graph[20][20];
int status[20];
int val;

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

void push(int node)
{
    Node* temp = new Node(node);
    temp->val= val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *curr_node=head;
        temp->next=curr_node;
        head=temp;
    }

}
int pop()
{
    Node *curr_node=head;
    if(head==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        printf("%d\n",curr_node->val);
        head=curr_node->next;
        free(curr_node);
       // printf("Pop Complete\n");
    }
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

void addNeighbors(int N,int nodeN)
{
    for(int i=0; i<=N; i++)
    {
        if(graph[nodeN][i]==1)
        {
            if(status[i]==1)
            {
                push(i);
                status[i]=1;
            }
        }
    }
}

void dfs(int source, int n)
{
    //step 1
    initStatus(n);

    //step 2
    push(source);
    status[source] = 2;

    //step 3
    while(!isEmpty())
    {
        //step 4
        int N = pop();  //do necessary things
        printf("node: %d\t", N);
        status[N] = 3;
        //step 5
        addNeighbors(n,N);
    }
}

int main()
{
    int n, e, source;
    printf("Enter no of Node: ");
    scanf("%d",&n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);

    printf("Enter no of Source: ");
    scanf("%d", &source);
    inputGraph(n,e);
    printAM(n);
    dfs(source,n);

    return 0;
}

