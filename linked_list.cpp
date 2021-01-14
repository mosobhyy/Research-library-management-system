//
// Created by Muhmd on 5/24/2020.
//

#include "linked_list.h"
#include <vector>
#include<ctime>

bool linked_list::isEmpty()
{
    return head == nullptr;
}

void linked_list::addBook(string name, int isbn, int numOfCopies)
{
    time_t t;
    struct tm *tt;
    time(&t);
    tt = localtime(&t);
    bookNode *newBook = new bookNode;
    newBook->name = name;
    newBook->isbn = isbn;
    newBook->numOfCopies = numOfCopies;
    newBook->next = nullptr;
    copyNode *temp = new copyNode;
    for (int i = 0; i < numOfCopies; i++)
    {
        copyNode *newCopy = new copyNode;
        newCopy->date = asctime(tt);
        newCopy->borrowDate = "NULL";
        newCopy->borrower = "NULL";
        newCopy->period = "NULL";
        newCopy->available = true;
        newCopy->next = nullptr;
        temp->next = newCopy;
        temp = newCopy;
        if (i == 0)
            newBook->copyPtr = newCopy;
    }
    if (isEmpty())
        head = tail = newBook;
    else
    {
        tail->next = newBook;
        tail = newBook;
    }
    numOfBooks++;
}

void linked_list::addCopy(string bookName)
{
    time_t t;
    struct tm *tt;
    time(&t);
    tt = localtime(&t);
    bookNode *temp = head;
    copyNode *copyTemp = nullptr;
    while (temp != nullptr)
    {
        if (temp->name == bookName)
            break;
        temp = temp->next;
    }
    if (temp)
    {
        temp->numOfCopies++;
        copyTemp = temp->copyPtr;
        while (copyTemp->next != nullptr)
            copyTemp = copyTemp->next;
        copyNode *newCopy = new copyNode;
        newCopy->date = asctime(tt);
        newCopy->borrowDate = "NULL";
        newCopy->borrower = "NULL";
        newCopy->period = "NULL";
        newCopy->available = true;
        copyTemp->next = newCopy;
        cout << "\nCopy added successfully...!\n\n";
    }
    else
        cout << "\nThere is no book with that name...!\n\n";
}

linked_list::copyNode *linked_list::search(string bookName, string &message)
{
    bookNode *temp = head;
    copyNode *copyTemp = nullptr;
    while (temp != nullptr)
    {
        if (temp->name == bookName)
            break;
        temp = temp->next;
    }
    if (temp)
    {
        copyTemp = temp->copyPtr;
        while (copyTemp != nullptr)
        {
            if (copyTemp->available)
                break;
            copyTemp = copyTemp->next;
        }
        if (copyTemp)
            message = "\nBooked Successfully...!\n\n";
        else
            message = "\nUnfortunately, all copies are borrowed...!\n\n";
    }
    else
        message = "\nUnfortunately, we do not have this book...!\n\n";
    return copyTemp;
}

void linked_list::bookBorrow(copyNode *copy, string borrowerName, string period)
{
    time_t t;
    struct tm *tt;
    time(&t);
    tt = localtime(&t);
    copy->borrower = borrowerName;
    copy->borrowDate = asctime(tt);
    copy->period = period;
    copy->available = false;
}

void linked_list::bookReturn(string bookName)
{
    bookNode *temp = head;
    copyNode *copyTemp = nullptr;
    while (temp != nullptr)
    {
        if (temp->name == bookName)
            break;
        temp = temp->next;
    }
    if (temp)
    {
        copyTemp = temp->copyPtr;
        if (copyTemp->available)
            cout << "\nNo Copies are borrowed for this book to return...!\n\n";
        else
        {
            while (((copyTemp->next) && !(copyTemp->next->available)))
                copyTemp = copyTemp->next;
            copyTemp->borrowDate = "NULL";
            copyTemp->borrower = "NULL";
            copyTemp->period = "NULL";
            copyTemp->available = true;
            cout << "\nCopy returned successfully...!\n\n";
        }
    }
    else
        cout << "\nThere is no book with that name...!\n\n";
}

void linked_list::inventory()
{
    vector<copyNode *> borrowedCopies;
    bookNode *temp = head;
    cout << "\n\t\t\tNumber of Books: " << numOfBooks << endl;
    cout << "\t\t\t------------------\n";
    while (temp != nullptr)
    {
        cout << "Book Name: " << temp->name << endl;
        cout << "Number of pages: " << temp->isbn << endl;
        cout << "The number of total copies: " << temp->numOfCopies << endl;
        copyNode *copyTemp = temp->copyPtr;
        int notAvailable = 0;
        while (copyTemp != nullptr)
        {
            if (!(copyTemp->available))
            {
                borrowedCopies.push_back(copyTemp);
                notAvailable++;
            }
            copyTemp = copyTemp->next;
        }
        cout << "The number of copies borrowed: " << notAvailable;
        if (!borrowedCopies.empty())
        {
            for (int i = 0; i < borrowedCopies.size(); i++)
            {
                cout << "\n\n\t\tCopy Date: " << borrowedCopies[i]->date;
                cout << "\t\tBorrower Name: " << borrowedCopies[i]->borrower << endl;
                cout << "\t\tBorrow Date: " << borrowedCopies[i]->borrowDate;
                cout << "\t\tBorrowing period: " << borrowedCopies[i]->period << " days";
                cout << "\n\n\t\t------------------------------";
            }
        }
        cout << "\n\n*********************************\n\n";
        borrowedCopies.clear();
        temp = temp->next;
    }
}

linked_list::bookNode *linked_list::getHead() const
{
    return head;
}

void linked_list::setHead(linked_list::bookNode *head)
{
    linked_list::head = head;
}

linked_list::bookNode *linked_list::getTail() const
{
    return tail;
}

void linked_list::setTail(linked_list::bookNode *tail)
{
    linked_list::tail = tail;
}

linked_list::linked_list()
{
    numOfBooks = 0;
    head = tail = nullptr;
}
