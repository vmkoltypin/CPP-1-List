#include <iostream>
#include "List.h"
#include "Train.cpp"
using namespace std;


int main()
{
    List<Train> a;

    Train ab("a", 1, 2);
    Train c("b", 1, 3);
    a.push_back(ab);
    a.push_back(c);
   // a.push_front( { "aa", 2, 4 } );

    Train q("u", 5, 3);

    a.insert(q, 2);

    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << a[i] << endl;
    }

    cout << "Elements: " << a.GetSize() << endl << "Remove at: " << endl;
    
   // a.removeAt(1);
    a.pop_back();
   // a.pop_front();

    //a.clear();
    for (int i = 0; i < a.GetSize(); i++)
    {
        cout << a[i] << endl;
    }
    cout << "Elements: " << a.GetSize() << endl;


    //int n;
    //cin>>n;
    //for (int i = 0; i < n; i++)
    //{
    //    a.push_back(rand() % 10);
    //}
    
    return 0;
}

