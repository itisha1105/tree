#include<iostream>
using namespace std;
class node{
    public:
node *lchild;
node *rchild;
int data;
};
class Queue{
private:
    int front;
    int rear;
    node **Q;
    int size;
public:
    Queue()
    {
    front = rear= -1;
    size=10;
    Q= new node*[size];

    }
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new node*[size];
    }
    void enqueue(node*p)
    {
        if(rear==size-1)
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
         rear++;
         Q[rear]=p;
        }
    }
    node* dequeue()
    {
        node*x=NULL;
        if(front==rear)
        {
            cout<<"queue is empty"<<endl;
        }
        else{
            front++;
            x=Q[front];
        }
        return x;
    }
    bool isempty()
    {
        if(front == rear)
            return true;
        else {return false;}
    }
    };
class tree{
public:
    node *root=NULL;
    void createtree()
    {
        node *p,*t=NULL;
        Queue q(100);
        root = new node;
        int x;
        cin>>x;
        root->data=x;
        root->rchild=root->lchild=NULL;
        q.enqueue(root);
        while(q.isempty()!=true)
        {
            p=q.dequeue();
            cout<<"enter the value of left child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->data=x;
                t->lchild=t->rchild=NULL;
                p->lchild=t;
                q.enqueue(t);
            }
            cout<<"enter right child of "<<p->data<<endl;
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->data=x;
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                q.enqueue(t);
            }
        }
    }
    void preorder(struct node*p)
    {
            if(p)
        {
            cout<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
    }
    void postorder(struct node*p)
    {
        if(p)
        {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data;
    }
    }
};

int main()
{
    tree t;
    t.createtree();
    t.preorder(t.root);

    t.postorder(t.root);
    return 0;
}
