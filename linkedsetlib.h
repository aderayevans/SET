using ElementType = int;
struct Cell
{
    ElementType element;
    Cell* next;
};
typedef Cell* Set;

//declarations:
void _union(Set a, Set b, Set& c);
void intersection(Set a, Set b, Set& c);
void difference(Set a, Set b, Set& c);
bool member(ElementType x, Set a);
void makenull_set(Set& a);
void insert_set(ElementType x, Set& a);
void delete_set(ElementType x, Set& a);
void assign(Set a, Set& b);
int min(Set a);
bool equal(Set a, Set b);
//definitions:
void _union(Set a, Set b, Set& c)
{
    while (a->next != nullptr || b->next != nullptr)
    {
        if (a->next != nullptr && b->next == nullptr)
        {
            insert_set(a->next->element, c);
            a = a->next;
        }
        else if (a->next == nullptr && b->next != nullptr)
        {
            insert_set(b->next->element, c);
            b = b->next;
        }
        else if (a->next->element < b->next->element)
        {
            insert_set(a->next->element, c);
            a = a->next;
        }
        else if (a->next->element == b->next->element)
        {
            insert_set(a->next->element, c);
            a = a->next;
            b = b->next;
        }
        else 
        {
            insert_set(b->next->element, c);
            b = b->next;
        }
    }
}
void intersection(Set a, Set b, Set& c)
{
    while (a->next != nullptr)
    {
        if (b->next == nullptr)
        {
            break;
        }
        else if (a->next->element < b->next->element)
        {
            a = a->next;
        }
        else if (a->next->element == b->next->element)
        {
            insert_set(a->next->element, c);
            a = a->next;
            b = b->next;
        }
        else 
        {
            b = b->next;
        }
    }
}
void difference(Set a, Set b, Set& c)
{
    while (a->next != nullptr || b->next != nullptr)
    {
        if (a->next != nullptr && b->next == nullptr)
        {
            insert_set(a->next->element, c);
            a = a->next;
        }
        else if (a->next == nullptr && b->next != nullptr)
        {
            insert_set(b->next->element, c);
            b = b->next;
        }
        else if (a->next->element < b->next->element)
        {
            insert_set(a->next->element, c);
            a = a->next;
        }
        else if (a->next->element == b->next->element)
        {
            a = a->next;
            b = b->next;
        }
        else 
        {
            insert_set(b->next->element, c);
            b = b->next;
        }
    }
}
bool member(ElementType x, Set a)
{
    while (a->next != nullptr)
        if (a->next->element < x)  a = a->next;
        else return a->next->element == x;
    return false;
}
void makenull_set(Set& a)
{
    a = new Cell();
    a->next = nullptr;
}
void insert_set(ElementType x, Set& a)
{
    Set p = a;
    while (p->next != nullptr)
        if (p->next->element <= x)
            p = p->next;
        else
            break;
    if ((p->next == nullptr) || (p->next != nullptr && p->next->element != x))
    {
        Cell* newcell = new Cell();
        newcell->element = x;
        newcell->next = p->next;
        p->next = newcell;
    }
}
void delete_set(ElementType x, Set& a)
{
    Set p = a;
    while (p->next != nullptr)
        if (p->next->element < x)
            p = p->next;
        else if (p->next->element > x)
            break;
        else
        {
            Cell* T = p->next;
            p->next = p->next->next;
            delete T;
            break;
        }
}
void assign(Set a, Set& b)
{
    makenull_set(b);
    while (a->next != nullptr)
    {
        insert_set(a->next->element, b);
        a = a->next;
    }
}
ElementType min(Set a)
{
    if (a->next != nullptr) return a->next->element;
    else return -1;
}
bool equal(Set a, Set b)
{
    while (a->next != nullptr)
    {
        if (a->next->element != b->next->element 
                || b->next == nullptr)
            return false;
        a = a->next;
        b = b->next;
    }
    return true;
}
void print_set(Set a)
{
    while (a->next != nullptr)
    {
       std::cout << a->next->element << std::endl;
        a = a->next;
    }
}
