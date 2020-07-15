const int maxlength = 256; //256 ASCII
using ElementType = int;
typedef int Set[maxlength];

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
    for (int i = 0; i < maxlength; i++)
        c[i] = ((a[i] == 1) || (b[i] == 1));
}
void intersection(Set a, Set b, Set& c)
{
    for (int i = 0; i < maxlength; i++)
        c[i] = ((a[i] == 1) && (b[i] == 1));
}
void difference(Set a, Set b, Set& c)
{
    for (int i = 0; i < maxlength; i++)
        c[i] = (((a[i] == 1) && (b[i] == 0)) || ((a[i] == 0) && (b[i] == 1)));
}
bool member(ElementType x, Set a)
{
    if (x >= 0 && x < maxlength)
        return a[x] == 1;
    else return false;
}
void makenull_set(Set& a)
{
    for (int i = 0; i < maxlength; i++)
        a[i] = 0;
}
void insert_set(ElementType x, Set& a)
{
    if (x >= 0 && x < maxlength)
        a[x] = 1;
}
void delete_set(ElementType x, Set& a)
{
    if (x >= 0 && x < maxlength)
        a[x] = 0;
}
void assign(Set a, Set& b)
{
    makenull_set(b);
    for (int i = 0; i < maxlength; i++)
        b[i] = a[i];
}
ElementType min(Set a)
{
    for (int i = 0; i < maxlength; i++) 
        if (member(i, a)) return i;
    return -1;
}
bool equal(Set a, Set b)
{
    for (int i = 0; i < maxlength; i++) 
        if (a[i] != b[i]) return false;
    return true;
}
void print_set(Set a)
{
    for (int i = 0; i < maxlength; i++)
    {
        if (a[i] == 1) std::cout << i << std::endl;
    }
}
