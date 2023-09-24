#include <iostream>

using namespace std;


//����һ�������������ҳ����ĵ�����K���ڵ㣬Ҫ��ʱ��Ч�����š�
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
        // ���k�Ƚϴ� �������ȴ� fast�Ѿ������β�Ļ� ��û�з���������
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
    // 1->2->3->4->5 ������k�� ����k=2
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
        cout<<"û�з���������"<<endl;
}
int main()
{
    t1();
    return 0;
}