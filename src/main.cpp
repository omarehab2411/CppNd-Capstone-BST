
#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    int value;
    char choice;
    Node<int>* found;
    BST <int> theTree;

    theTree.Insert(50);
    theTree.Insert(25);
    theTree.Insert(75);
    theTree.Insert(12);
    theTree.Insert(37);
    theTree.Insert(43);
    theTree.Insert(30);
    theTree.Insert(33);
    theTree.Insert(87);
    theTree.Insert(93);
    theTree.Insert(97);
    theTree.Display();

while(choice != 'q')
{
 cout << "Enter first letter of ";
 cout << "show, insert, find, traverse or quit: ";
 cin >> choice;
 switch(choice)
 {
 case 's':
 theTree.Display();
 break;

 case 'i':
 cout << "Enter value to insert: ";
 cin >> value;
 theTree.Insert(value);
 break;

 case 'f':
 cout << "Enter value to find: ";
 cin >> value;
 found = theTree.Find(value);
 if(found != NULL)
 {
 cout << "Found: ";
 found->displayNode();
 cout << endl;
 }
 else
 cout << "Could not find " << value << endl;
 break;

 case 't':
 cout << "Enter traverse type (1=preorder, "<< "2=inorder, 3=postorder): ";
 cin >> value;
 theTree.Traverse( (BST<int>::traverseType)(value) );
 break;

 case 'q':
 theTree.destroy();
 cout << endl;
 break;

 default:
 cout << "Invalid entry\n";
 }
}
return 0;
}
