//
// Created by Muhmd on 5/24/2020.
//

#ifndef RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKED_LIST_H
#define RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKED_LIST_H

#include <iostream>

using namespace std;

class linked_list
{
public:

    struct copyNode
    {
        string date, borrower, borrowDate, period;
        bool available;
        copyNode *next;
    };

private:

    struct bookNode
    {
        string name;
        int isbn, numOfCopies;
        copyNode *copyPtr;
        bookNode *next;
    };

    int numOfBooks;

    bookNode *head, *tail;

    bool isEmpty();

public:

    void addBook(string name, int isbn, int numOfCopies);

    void addCopy(string bookName);

    copyNode *search(string bookName, string &message);

    void bookBorrow(copyNode *copy, string borrowerName, string period);

    void bookReturn(string bookName);

    void inventory();

    bookNode *getHead() const;

    void setHead(bookNode *head);

    bookNode *getTail() const;

    void setTail(bookNode *tail);

    linked_list();

};


#endif //RESEARCH_LIBRARY_MANAGEMENT_SYSTEM_LINKED_LIST_H
