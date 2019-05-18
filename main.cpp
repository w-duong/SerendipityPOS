//
// Created by William Duong on 5/15/2019.
//
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookType.h"
#include "linkedListType.h"
#include "orderedLinkList.h"
#include "unorderedLinkList.h"

unorderedLinkedList <bookType>* loadDataBase ();

int main()
{
  unorderedLinkedList <bookType>* thisArray = new unorderedLinkedList <bookType> (*loadDataBase());

  cout << fixed << showpoint << setprecision (2);

  mainMenu (thisArray);

  writeDataBase (thisArray);

  thisArray -> destroyList ();

  delete thisArray;

  return 0;
}

unorderedLinkedList <bookType>* loadDataBase ()
{
  ifstream cinFile;
  unorderedLinkedList <bookType> *list1 = new unorderedLinkedList <bookType>;

  cinFile.open ("database-3.txt");

  while (!cinFile.eof ())
  {
    string tempTitle;
    string tempISBN;
    string tempAuthor;
    string tempPublisher;
    string tempDateAdded;
    int tempQtyOnHand;
    double tempWholesale;
    double tempRetail;

    // READ IN DATA TO TEMPORARY VARIABLES //
    getline (cinFile, tempTitle, '\n');
    if (cinFile.fail ())
      return list1;
    getline (cinFile, tempISBN, '\n');
    getline (cinFile, tempAuthor, '\n');
    getline (cinFile, tempPublisher, '\n');
    getline (cinFile, tempDateAdded, '\n');
    cinFile >> tempQtyOnHand;
    cinFile >> tempWholesale;
    cinFile >> tempRetail;
    cinFile.ignore ();

    // INITIALIZING TEMPORARY BOOK AND POPULATING FIELDS //
    bookType tempBookHolder (tempTitle, tempISBN, tempAuthor, tempPublisher, tempDateAdded, tempQtyOnHand, tempWholesale, tempRetail);

    // INSERTING BOOK INTO GENERIC LIST OF UNSORTED TYPE //
    list1 -> insertLast (tempBookHolder);

    // SETTING BOOK TO DIFFERENT SORT CODE (quantity on hand) //
    //tempBookHolder.setSortCode (1);

    // INSERTING BOOK INTO SPECIFIC LIST OF SORTED TYPE (quantity on hand) //
    //listQTY.insert (tempBookHolder);

    // SETTING BOOK TO DIFFERENT SORT CODE (wholesale) //
    //tempBookHolder.setSortCode (2);

    // INSERTING BOOK INTO SPECIFIC LIST OF SORTED TYPE (wholesale) //
    //listWHOLE.insert (tempBookHolder);

    // SETTING BOOK TO DIFFERENT SORT CODE (date added) //
    //tempBookHolder.setSortCode (3);

    // INSERTING BOOK INTO SPECIFIC LIST OF SORTED TYPE (date added) //
    //listDATE.insert (tempBookHolder);
  }

  cinFile.close ();
  return list1;
}
