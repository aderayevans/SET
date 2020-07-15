using std::string;
const int B = 10; //bucket
const std::string deleted = "+++";
const std::string empty = "***";
using ElementType = std::string;
struct Node
{
    ElementType data;
    Node* next;
};
typedef Node* Position;
typedef Position Dictionary[B];

int h(ElementType x)
{
    int sum = 0;
    for (int i = 0; i < x.length(); i++)
        sum = sum + x[i];
    return sum % B;
}
int hi(int i, int hx) //hash i time: hi(x) = (h(x) + 1) % B
{
    return (hx + i) % B;
}
//declarations:
void makenull_set(Dictionary& d);
bool member(ElementType x, Dictionary d);
bool locate(ElementType x, Dictionary d);
bool locate1(ElementType x, Dictionary d);
void insert_set(ElementType x, Dictionary& d);
void delete_set(ElementType x, Dictionary& d);
//definitions:
void makenull_set(Dictionary& d)
{
    for (int i = 0; i < B; i++)
        d[i] = empty;
}
bool locate(ElementType x, Dictionary d)
{
    int initial, i;
    initial = h(x);
    i = 0;
    while ((i < B) && (A[hi(i, x)] != x) && (A[hi(i, x)] != empty))
        i++;
    return hi(i, x)];
}
bool locate1(ElementType x, Dictionary d)
{
    int initial, i;
    initial = h(x);
    i = 0;
    while ((i < B) && (d[hi(i, x)] != x) && (d[hi(i, x)] != empty)
                    && (d[hi(i, x)] != deleted))
        i++;
    return hi(i, x)];
}
bool member(ElementType x, Dictionary d)
{
    return d[locate(x, d)] == x;
}
void insert_set(ElementType x, Dictionary& d)
{
    int bucket;
    if(!member(x, d))
    {
        bucket = locate1(x, d);
        if ((d[bucket] == empty) || (d[bucket] == deleted))
            d[bucket] = x;
    }
    else std::cout << "Error: hashtable was full"
}
void delete_set(ElementType x, Dictionary& d)
{
    int bucket;
    bucket = locate(x, d);
    if (membet(x, d))
        d[bucket] = deleted;
}
