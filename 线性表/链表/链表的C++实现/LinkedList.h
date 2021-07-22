#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(Node<T>* ptr=nullptr){
        next=nullptr;
    }
    Node(const T& item,Node<T>*ptr=nullptr){
        data = item;
        next = ptr;
    }
};

template<class T>
class LinkedList
{  
public:
    LinkedList(){
        first = new Node<T>;
    }
    LinkedList(const T&x){
        first =new Node<T>(x);
    }
    LinkedList(LinkedList<T>& l);//复制构造函数
    void makeEmpty();
    int Length()const;
    Node<T>* getHead()const{return first;}//返回附加头结点地址
    Node<T>*Search(T x);//搜索含数据x的元素
    Node<T>*Locate(int i )const;//搜索第i个元素的地址
    bool getData(int i,T& x)const;
    bool setData(int i,T& x);
    bool Insert(int i,T& x);//i后面插入值x
    bool remove(int i,T& x);//删除i上元素，x是返回值
    bool isEmpty()const{
        return first->next==nullptr?true:false;
    }
    bool isFull()const{
        return false;
    }
    void sort();
    void input(int num);
    void output();
    LinkedList<T>& operator=(LinkedList<T>&L);
    Node<T> *first;//链表头指针
    
};
//复制构造函数
template<class T>
LinkedList<T>::LinkedList(LinkedList<T>& l){
    T value;
    Node<T>* oldptr= l.getHead();
    Node<T>* newptr = first = new Node<T>();
    while(oldptr!=nullptr){
        value  =oldptr->next->data;
        newptr->next = new Node<T>(value);
        newptr = newptr->next;
        oldptr = oldptr->next;
    }
    newptr->next=nullptr;
}

//输出
template<class T>
void LinkedList<T>::output(){
    Node<T>* current=first;
    while((current!=nullptr)&&(current!=0)){
        cout<< current->data <<"->";
        current = current->next;
    }
    cout<<endl;
} 

//插入
template< class T>
bool LinkedList<T>::Insert(int i,T& x){
    Node<T>*p = Locate(i);
    if(p==nullptr)return false;
    Node<T>* newNode=new Node<T>(x);
    if(newNode==nullptr){cout<<"内存分配错误";exit(1);}
    newNode->next = p->next;
    p->next = newNode;
    return true;
}
//查找位置
template<class T>
Node<T>* LinkedList<T>::Locate(int i)const{
    if(i<0){
        return nullptr;
    }
    Node<T>* current=first;
    int k=0;
    while(current!=nullptr&&k<i){
        current = current->next;
        k++;
    }
    return current;
}
//建立单链表
template<class T>
void LinkedList<T>::input(int num){
    Node<T>* newNode;
    Node<T>* last;
    T val;
    int count=0;
    makeEmpty();
    last = first;
    while(count<num){
        cin>>val;
        newNode = new Node<T>(val);
        if(newNode==nullptr){
            cout<<"存储分配错误"<<endl;
            exit(1);
        }
        last->next=newNode;
        last = newNode;
        count++;
    }
    
}
//做空
template<class T>
void LinkedList<T>::makeEmpty(){
    //将链表设置为空表
    Node<T>*q;
    while(first->next!=nullptr){
        q=first->next;
        first->next = q->next;
        delete q;
    }
}
template<class T>
int LinkedList<T>::Length()const {
    Node<T> *p= first->next;
    int count=0;
    while(p!=nullptr){
        count++;
        p=p->next;
    }
    return count;
}
template<class T>
Node<T> *LinkedList<T>::Search(T x){
    Node<T> *p=first->next;
    while (p!=nullptr)
    {
        if(p->data==x){
            return p;
        }
    }
    return nullptr;
    
}
template<class T>
bool LinkedList<T>::getData(int i,T &x)const{
    Node<T>* p=first->next;
    int count=0;
    while (p!=nullptr)
    {
        if(count==i){
            x=p->data;
            return true;
        }
        p=p->next;
        count++;
    }
    return false;
    //另一种实现方式
    /*
     if(i<0){
         return ;
     }
     LinkedList<T>* p=Locate(i);
     if(p==nullptr)return nullptr;
     else{
         x=p->data;
         return true;
     }
    */
}
template<class T>
bool LinkedList<T>::setData(int i,T &x){
    if(i<0)return false;
    Node<T> *p=Locate(i);
    if(p==nullptr)return false;
    else{
        p->data=x;
        return true;
    }
}
template<class T>
bool LinkedList<T>::remove(int i,T&x){
    //将链表中第i个元素删除，通过引用型参数x返回该元素的值
    Node<T>* p=Locate(i-1);
    if(p==nullptr||p->next==nullptr)return false;
    Node<T>* del= p->next;
    x= del->data;
    p->next = del->next;
    delete del;
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& l){
    T value;
    Node<T>*  srcptr = l.getHead();
    Node<T>*  desptr = first = new Node<T>;
    while(srcptr!=nullptr){
        value =srcptr->next->data;
        desptr->next = new Node<T>(value);
        desptr = desptr->next;
        srcptr = srcptr->next;
    }
    desptr->next=nullptr;
    return  *this;
}