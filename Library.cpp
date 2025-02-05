#include <iostream>
using namespace std;

int main()
{   
    int size ;
    cout << "Enter the number of books\n";
    cin >> size;
    int *bookNumber = new int[size];
    *bookNumber= {1};
    string *bookTitle = new string[size];
    *bookTitle = { "" };
    string *bookAuthor = new string[size];
    *bookAuthor = { "" };
}