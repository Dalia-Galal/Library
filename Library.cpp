#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void addBook(int* bookNumber, string* bookTitle, string* bookAuthor, int& size);
void printDataBase(int* bookNumber, string* bookTitle, string* bookAuthor, int& size);
void updateBook(int* bookNumber, string* bookTitle, string* bookAuthor, int& size);
void removeBook(int* bookNumber, string* bookTitle, string* bookAuthor,int &size);
void borrowBook(int* bookNumber, string* bookTitle, string* bookAuthor,int &size);

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
void printDataBase(int* bookNumber, string* bookTitle, string* bookAuthor, int& size)
{   
    for (int i = 0;i < size;i++)
    {
        cout << bookNumber[i] << " " <<  bookTitle[i] << " " << bookAuthor[i] << endl;
    }
    
}
void updateBook(int* bookNumber, string* bookTitle, string* bookAuthor, int& size)
{   
    int id, new_id;
    char letter;
    string newTitle ,newAuthor;
   
    cout << "please enter the id of the book you want to update\n";
    cin >> id;
    
    for (int i = 0; i < size; i++)
    {   

        if(bookNumber[i] == id)
        {   
            cout << "choose what do you want to ubdate in book no. " << bookNumber[i] << endl<< "for id press 'i'"
            << endl << "for title press 't'" << endl<< "for author press 'a' ";
            cin >> letter;

            if(letter == 'i')
            {
                cout << "enter the new id ";
                cin >> new_id;
                bookNumber[i] = new_id;
            }
            else if(letter =='t')
            {
                cout << "enter the new title ";
                cin >> newTitle;
                bookTitle[i] = newTitle;
            }
            else 
            {
                cout << "enter the new author ";
                cin >> newAuthor;
                bookAuthor[i] = newTitle;
            }
        }
    }
}
void removeBook(int* bookNumber, string* bookTitle, string* bookAuthor,int &size)
{
    int id;
   
    cout << "please enter the id of the book you want to remove\n";
    cin >> id;
    for (int i = 0; i < size; i++)
    { 
        if(bookNumber[i] == id)
        {
            bookNumber[i] = 0;
            bookTitle[i] = "";
            bookAuthor[i]="";
        }
    }
}
 void borrowBook(int* bookNumber, string* bookTitle, string* bookAuthor,int &size)
{
    int id; 
  
    bool isAvailable=false;
    cout << "please enter the id of the book you want to borrow\n";
    cin >> id;
  
    for (int i = 0; i < size; i++)
    { 
        if(id == bookNumber[i]  && bookNumber[i] != 0)
        {   isAvailable =true;
            bookNumber[i] = 0;
            break;
        }
        else
        {
            isAvailable=false;
        }
    }
    if(isAvailable)
    {
        cout << "=======================================\n";
        cout << "book is available ,you now borrowed it \n";
        cout << "=======================================\n";
    }
        
   else 
   {
     cout << "=======================================\n";
     cout << "book is not available, you can't boorrow \n";
     cout << "=======================================\n";
   }
    
       
    
}