const int B = 10; //bucket
using ElementType = int;
struct Node
{
    ElementType data;
    Node* next;
};
typedef Node* Position;
typedef Position Dictionary[B];

int h(ElementType x)
{
    return x % 10;
}
//declarations:
void makenull_set(Dictionary& d);
bool member(ElementType x, Dictionary d);
void insert_set(ElementType x, Dictionary& d);
void delete_set(ElementType x, Dictionary& d);
//definitions:
void makenull_set(Dictionary& d)
{
    for (int i = 0; i < B; i++)
        d[i] = nullptr;
}
bool member(ElementType x, Dictionary d)
{
    Position p = d[h(x)];
    while (p != nullptr)
        if (p->data == x) return true;
        else p = p->Next;
    return false;
}
void insert_set(ElementType x, Dictionary& d)
{
    int bucket;
    Position p;
    if(!member(x, d))
    {
        bucket = h(x);
        p = d[bucket];
        d[bucket] = new Node();
        d[bucket]->data = x;
        d[bucket]->next = p;
    }
}
void delete_set(ElementType x, Dictionary& d)
{
    int bucket;
    Position p, temp;
    bucket = h(x);
    if (d[bucket] != nullptr)
    {
        if (d[bucket]->data == x)
        {
            temp = d[bucket];
            d[bucket] = d[bucket]->next;
            delete temp;
        }
        else
        {
            p = d[bucket];
            while (p->next != nullptr)
                if (p->next->data == x) breakl
                else p = p->next;
            if (p->next != nullptr)
            {
                temp = p->next;
                p->next = temp->next;
                delete temp;
            }
        }
    }
}
