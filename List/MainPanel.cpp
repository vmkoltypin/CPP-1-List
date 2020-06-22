#include <iostream>
#include "List.h"
#include "Train.h"
using namespace std;


int main()
{
    List<Train> a;
    Train ab("a", 1, 3);
    Train c("b", 1, 3);
    a.push_back(ab);
    a.push_back(c);
    a.push_front( { "aa", 2, 4 } );

    cout << "\nfor a" << endl;
    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << a[i] << endl;
    }

    List<Train> b;
    b.copy(a);

    cout << "\nfor b" << endl;
    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << b[i] << endl;
    }

    List<Train> ñ;
    ñ = a;
    
    cout << "\nfor c" << endl;
    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << ñ[i] << endl;
    }

    Train q("u", 5, 3);
    b.insert(q, 2);

   
    

    cout << "Elements: " << a.GetSize() << endl << "Remove at: " << endl;
    
    a.removeAt(1);
    b.pop_back();
    a.pop_front();

    a.clear();
    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << a[i] << endl;
    }
    cout << "Elements: " << a.GetSize() << endl;
    
    return 0;
}

