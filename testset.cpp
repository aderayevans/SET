#include <iostream>
#include "vectorbitlib.h"
//#include "linkedsetlib.h"

using std::cout;
using std::endl;

int main() {
    Set a, b, c;
    makenull_set(a);
    makenull_set(b);
    makenull_set(c);
    
    insert_set(65, a);
    
    insert_set(6, a);
    insert_set(9, a);

    insert_set(65, b);
    insert_set(6, b);
    insert_set(11, b);
    /*
    assign(a, c);
    assign(b, c);
    cout << "test equal function: " << endl;
    cout << "1: " << equal(b, c) << endl;
    assign(a, b);
    cout << "2: " << equal(b, c) << endl;
    */
    //_union(a, b, c);
    //intersection(a, b, c);
    difference(a, b, c);

    print_set(a);
    cout << endl;
    print_set(b);
    cout << endl;
    print_set(c);
    cout << endl;
}
