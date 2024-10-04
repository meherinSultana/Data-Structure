#include<stdio.h>

struct Node
{
    Node* prev;//delete
    int data;
    Node* next;

    Node(int x)
    {
        prev = NULL;//delete
        data = x;
        next = NULL;
    }
};

Node* hd;

void print()
{
    Node* temp = hd;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/*int SEARCH(int key)
{
     Node* temp = hd;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Found");
            return 0;
        }
        printf("Not found");
    }

}*/

void INSERT(int x)
{
    Node* n = new Node(x);
    if(hd == NULL)
    {
        hd=n;
    }
    else
    {
        Node* temp = hd;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void DELETE()
{
    hd = hd->next;
}

int main()
{
    /*Node* n1 = new Node(4);
    Node* n2 = new Node(5);
    Node* n3 = new Node(6);

    n1 -> next = n2;
    n2 -> next = n3;
    hd = n1;
    print();
    SEARCH(5);*/

    hd = NULL;
    INSERT(4);
    INSERT(5);
    INSERT(6);
    //INSERT(7);
    print();
    return 0;
}
