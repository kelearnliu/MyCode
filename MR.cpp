#include <iostream>

using namespace std;


//给定一个单向链表，请找出它的倒数第K个节点，要求时间效率最优。
//typedef struct Lnode
//{
//    int data;
//    struct Lnode* next;
//}Lnode,*Linklist;
//
//Lnode* GetElem(LinkList L, int K);
class Lnode
{
public:
    Lnode(int data, Lnode* next):data(data),next(next) {}
    Lnode(int data):data(data),next(nullptr) {}
public:
    int data;
    Lnode* next;
};
Lnode* GetElem(Lnode* head, int k)
{
    Lnode* fast = head;     Lnode* slow = head;
    while(k--)
    {
        // 如果k比较大 比链表长度大 fast已经到达结尾的话 就没有符合条件的
        if(!fast)
        {
            return nullptr;
        }
        fast=fast->next;
    }
    while (fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void t1()
{
    // 1->2->3->4->5 倒数第k个 这里k=2
    Lnode* head = new Lnode(1);
    head->next = new Lnode(2);
    head->next->next = new Lnode(3);
    head->next->next->next = new Lnode(4);
    head->next->next->next->next = new Lnode(5);

    int k=7;
    Lnode* res = GetElem(head,k);
    if(res)
        cout<<res->data<<endl;
    else
        cout<<"没有符合条件的"<<endl;
}
int main()
{
    t1();
    return 0;
}