#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void addBook(int* bookNumber, string* bookTitle, string* bookAuthor, int& size);
int main()
{   
    int size ;
    cout << "Enter the number of books\n";
    cin >> size;
    int *bookNumber = new int[size];
    *bookNumber= {1};
    string *bookTitle = new string[size];
    *bookTitle = { " " };
    string *bookAuthor = new string[size];
    *bookAuthor = { " " };
}
void addBook(int* bookNumber, string* bookTitle, string* bookAuthor,int &size)
{  
    for (int i = 0; i < size; i++)
    { 
        char tempBookNum;
        cin >> tempBookNum;
        if(isdigit(tempBookNum))
        {
            bookNumber[i] = tempBookNum - 48;
        }
        else
        {   
            cout << " enter a number \n";
            return addBook(bookNumber,bookTitle, bookAuthor,size);
        }
           
        cin.ignore();
        
        getline(cin,bookTitle[i],'\n');
        getline(cin,bookAuthor[i],'\n');
    }
}