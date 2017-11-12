#include <iostream>
#include <cassert>
#include <queue>
using namespace std;


template <typename T>
struct node
{
    T data;
    node* next;
};

template <typename T>
class LStack
{
private:
    node<T>* topNode;
    void copy(node<T>* toCopy);
    void eraseStack();
    void copyStack(LStack const&);
public:
    LStack(); // създаване на празен стек
    LStack(LStack const&); // Конструктор за копиране
    LStack& operator=(LStack const&); // операция за    присвояване
    ~LStack(); // деструктор
    bool empty() const;
    void push(T const& x);
    T pop();
    T top() const;
    void print();
    T maxelem();
};

template <typename T>
LStack<T>::LStack() : topNode(nullptr) {}

template <typename T>
bool LStack<T>::empty() const {
 return topNode == nullptr;
}

template <typename T>
void LStack<T>::push(T const& x) {
 node<T>* p = new node<T>;
 p->data = x;
 p->next = topNode;
 topNode = p;
}

template <typename T>
T LStack<T>::pop()
 {
    if (empty()) {
    cerr << "празен стек!\n";
    return 0;
    }
    node<T>* p = topNode;
    topNode = topNode->next;
    T x = p->data;
    delete p;
    return x;
}

template <typename T>
T LStack<T>::top() const
{
    if (empty()) {
    cerr << "празен стек!\n";
    return 0;
    }
    return topNode->data;
}

template <typename T>
void LStack<T>::eraseStack()
 {
    while (!empty())
    pop();
}

template <typename T>
LStack<T>::~LStack()
{
    eraseStack();
}

template <typename T>
void LStack<T>::copy(node<T>* toCopy)  //Рекурсия , ЧИКИ БРИКИ
{
    if (toCopy == nullptr)
    return;
    copy(toCopy->next);
    push(toCopy->data); //добавямe първия елемент отгоре
}

template <typename T>
void LStack<T>::copyStack(LStack const& ls)
{
    topNode = nullptr;
    copy(ls.topNode);
}

template <typename T>
LStack<T>::LStack(LStack const& ls)
{
    copyStack(ls);
}

template <typename T>
LStack<T>& LStack<T>::operator=(LStack const& ls)
{
    if (this != &ls) {
    eraseStack();
    copyStack(ls);
    }
 return *this;
}

template <typename T>
void LStack<T>::print()
{
    node<T> *p = topNode;
    while(p!= NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

template <typename T>
T LStack<T>::maxelem()
{
    T maxElem = top();
    node<T> *p = topNode;
    while(p!= NULL)
    {
        if(maxElem < p->data) maxElem = p->data;
        p = p->next;
    }
    return maxElem;
}
int main()
{

    LStack<int> Bomb1 , Bomb2;
    int n,m;
    cin>>n;
    for(int i=0 ; i<n ;i++)
    {
        cin>>m;
        switch(m)
        {   case 1:
                int x;
                cin>>x;
                if(Bomb1.empty())
                {
                    Bomb1.push(x);
                    Bomb2.push(x);
                }
                else {
                Bomb1.push(x);
                    if(x >= Bomb2.top())
                    {
                        Bomb2.push(x);
                    }
                }
                break;
            case 2:
                if (Bomb1.empty()) break;
                if(Bomb1.top() == Bomb2.top())
                {
                    Bomb1.pop();
                    Bomb2.pop();
                }
                else Bomb1.pop();
                break;
            case 3:
                cout<<Bomb2.top()<<endl;
                break;
        }
    };
return 0;
}
