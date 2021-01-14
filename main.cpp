#include <iostream>
#include "linked_list.h"

int main()
{
    try
    {
        char again = 'y';
        linked_list library;
        library.addBook("ds", 12, 5);
        library.addBook("fs", 34, 3);
        library.addBook("al", 78, 2);
        do
        {
            char choice1;
            cout << "\n\t\t\t\tWelcome to our Library ^_^\n";
            cout << "\t\t\t\t--------------------------\n";
            cout << "1- Add Book\n";
            cout << "2- Add Copy For Book\n";
            cout << "3- Borrow A Book\n";
            cout << "4- Return A Book\n";
            cout << "5- Show Inventory\n";
            cout << "6- Exit\n";
            do
            {
                cout << ">> ";
                cin >> choice1;
                if ((choice1 < '1' || choice1 > '6'))
                    cout << "\n Enter a Valid Choice...!\n\n";
            }
            while (choice1 < '1' || choice1 > '6');


            if (choice1 == '1')
            {
                string name;
                int isbn, numOfCopies;
                cout << "Enter Book Name: ";
                cin >> name;
                cout << "Enter the number of pages for the book: ";
                cin >> isbn;
                if (!isbn)
                    throw exception();
                cout << "Enter Number Number Of Copies: ";
                cin >> numOfCopies;
                if (!numOfCopies)
                    throw exception();
                library.addBook(name, isbn, numOfCopies);
            }


            else if (choice1 == '2')
            {
                string bookName;
                cout << "\nEnter Book Name: ";
                cin >> bookName;
                library.addCopy(bookName);
            }

            else if (choice1 == '3')
            {
                string bookName, message;
                cout << "\nEnter Book Name: ";
                cin >> bookName;
                linked_list::copyNode *copy = library.search(bookName, message);
                if (copy)
                {
                    string borrowerName, period;
                    cout << "Enter Borrower Name: ";
                    cin >> borrowerName;
                    cout << "Enter the borrow period: ";
                    cin >> period;
                    library.bookBorrow(copy, borrowerName, period);
                }
                cout << message;
            }

            else if (choice1 == '4')
            {
                string bookName;
                cout << "\nEnter Book Name: ";
                cin >> bookName;
                library.bookReturn(bookName);
            }

            else if (choice1 == '5')
            {
                library.inventory();
            }


            else
                break;

            cout << "\nDo you want to perform any other operation ?! (y, n)\n";
            do
            {
                cout << ">> ";
                cin >> again;
                if ((again != 'y' && again != 'n'))
                    cout << "\n Enter a Valid Choice...!\n\n";
            }
            while (again != 'y' && again != 'n');
        }
        while (again == 'y');
        cout << "\nThanks For Using Our Application ^_^\n";
    }
    catch (...)
    {
        cout << "\nInvalid input...!\n";
    }
    return 0;
}
