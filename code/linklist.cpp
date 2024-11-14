// 链表的每一个节点都是独立分配出来的
// 从当前节点能够找到下一个节点
#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr) {}
    int data_;
    Node *next_;
};

// 单链表：每一个节点只能找到下一个节点，无法回退上一个节点
class CLink
{
public:
    CLink()
    {
        head_ = new Node();
    }
    ~CLink()
    {
        // 节点的释放
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_; // 利用head_指针，不用重新声明变量
            delete p;
            p = head_;
        }
        head_ = nullptr; // 野指针置空
        //cout << "链表释放完毕" << endl;
    }

public:
    // 尾插法O(n)
    void InsertTail(int val)
    {
        // 先找到当前链表的末尾节点
        Node *cur = head_;
        while (cur->next_ != nullptr)
        { // 尾节点的特征是地址域为空
            cur = cur->next_;
        }
        // 生成新节点
        Node *node = new Node(val);
        // 把先前节点的末尾节点指向新节点
        cur->next_ = node;
    }
    // 头插法O(1)
    void InsertHead(int val)
    {
        // 生成新节点，将链表第一个节点挂在新节点后面
        Node *node = new Node(val);
        node->next_ = head_->next_;
        // 将新节点挂在头节点后面
        head_->next_ = node;
    }
    // 按值删除元素
    void Remove(int val)
    {
        // 找到值为val的结点
        Node *p = head_->next_;
        Node *q = head_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            { // 找到val,将pos-1节点的地址域指向pos+1的节点, 删除值为val的节点
                q->next_ = p->next_;
                delete p;
                return;
            }
            else
            { // 没有找到val
                q = p;
                p = p->next_;
            }
        }
    }
    void RemoveAll(int val)
    {
        // 找到值为val的结点
        Node *p = head_->next_;
        Node *q = head_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            { // 找到val,将pos-1节点的地址域指向pos+1的节点, 删除值为val的节点
                q->next_ = p->next_;
                delete p;
                p = q->next_; // 利用野指针，对指针p进行重置
            }
            else
            { // 没有找到val
                q = p;
                p = p->next_;
            }
        }
    }
    // 搜索 list
    bool Search(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
                return true;
            else p = p->next_;
        }
        return false;
    }
    void show()
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    };

private:
    // 给head初始化指向头节点
    Node *head_; // 指向链表的头节点
    friend void Reverse(CLink &link);
    friend bool getLastKNode(CLink &link, int k, int &val);
    friend void MergeLink(CLink & link1, CLink & link2);
};
// 链表逆序
void Reverse(CLink &link)
{
    Node* p = link.head_->next_; // p指向链表第一个节点 // 也可以从第二个节点开始头插
    if(p == nullptr) return; // 特殊情况处理
    // 采用头插法
    link.head_->next_ = nullptr; //头节点指针域置空
    while(p){
        Node* q = p->next_;
        p->next_ = link.head_->next_;
        link.head_->next_ = p;
        p = q;
    }
}
// 单链表倒数第k个节点-双指针
bool getLastKNode(CLink& link, int k, int &val)
{
    if(k<1) return false;
    Node* p = link.head_;
    Node* q = link.head_;
    for(int i = 0; i < k; i++){
        p = p->next_;
        if(p == nullptr){
            return false; // 特殊情况处理
        }
    }
    while(p){
        q = q->next_;
        p = p->next_;
    }
    val = q->data_;
    return true;
}
// 合并两个有序单链表
void MergeLink(CLink &link1, CLink &link2)
{
    Node* p = link1.head_->next_;
    Node* q = link2.head_->next_;
    Node* last = link1.head_;
    link2.head_->next_ = nullptr;
    while(p!=nullptr&&q!=nullptr){
        if(p->data_ < q->data_){
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
        else{
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
    }
    if(p!=nullptr){
        last->next_ = p;
    }
    else{
        last->next_ = q;
    }
}
int main()
{
    int arr[] = {25,37,52,78,88,92,98,108};
    int brr[] = {13,23,40,56,62,77,109};
    CLink link1;
    CLink link2;
    for(int v : arr){
        link1.InsertTail(v);
    }
    for(int v : brr){
        link2.InsertTail(v);
    }
    link1.show();
    link2.show();
    MergeLink(link1, link2);
    link1.show();
    link2.show();
    return 0;
    // CLink clink1, clink2;
    // srand(time(0));
    // for (int i = 0; i < 10; i++)
    // {
    //     int ele = rand() % 100;
    //     clink1.InsertTail(ele);
    //     clink2.InsertHead(ele);
    // }
    // clink1.show();
    // Reverse(clink1);
    // clink1.show();
    // clink2.show();
    // Reverse(clink2);
    // int val;
    // getLastKNode(clink2, 3, val);
    // clink2.show();
    return 0;
}