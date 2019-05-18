// ----------------------------------------------------------------------
// File name: reports.cpp
// Project name: Serendipity
// ----------------------------------------------------------------------
// William Duong, wduong1@saddleback.edu
// CS1B
// Creation Date 1/22/2019
// Last Modified 5/17/2019
// ----------------------------------------------------------------------
// Purpose: Displays reports menu.
// ----------------------------------------------------------------------
// Algorithm: Void display function for reports module.
// ----------------------------------------------------------------------
// -			                   DATA DICTIONARY
// - CONSTANTS
// -
// - NAME                    DATA TYPE	                INITIAL VALUE
// - --------	               -------------	            -------------
//
// - VARIABLES
// -
// - NAME	                   DATA TYPE	                INITIAL VALUE
// - --------	               -------------	            -------------
// - thisArray               unorderedLinkedList *
// - convertedList           orderedLinkedList *
// - it                      linkedListIterator
// - userChoice              int
// - totalPageCount          int                        0
// - currentPageCount        int                        0
// - totalINVWhole           double                     0
// - totalINVRetail          double                     0
// - dateTime                string
// ----------------------------------------------------------------------

#include "reports.h"

void reportsMenu (unorderedLinkedList <bookType>* thisArray)
{
  int userChoice = 0;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                  REPORTS MENU                                    *" << endl
         << "*                                                                                  *" << endl
         << "*                              " << dateTime << "                              *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> INVENTORY LISTING                                                           *" << endl
         << "*  <2> INVENTORY WHOLESALE VALUE                                                   *" << endl
         << "*  <3> INVENTORY RETAIL VALUE                                                      *" << endl
         << "*  <4> LISTING BY QUANTITY                                                         *" << endl
         << "*  <5> LISTING BY COST                                                             *" << endl
         << "*  <6> LISTING BY AGE                                                              *" << endl
         << "*  <7> RETURN TO MAIN MENU                                                         *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                            Enter Your Choice (1-7): ";

    cin >> userChoice;

    isGoodChoice (userChoice, 1, 7);

    switch (userChoice)
    {
      case 1:
        repListing (thisArray);
        break;
      case 2:
        repWholesale (thisArray);
        break;
      case 3:
        repRetail (thisArray);
        break;
      case 4:
        repQty (thisArray);
        break;
      case 5:
        repCost (thisArray);
        break;
      case 6:
        repAge (thisArray);
        break;
    }
  }
  while (userChoice != 7);
  {
    return;
  }
}

void repListing (unorderedLinkedList <bookType>* thisArray)
{
  linkedListIterator <bookType> it;
  int totalPageCount = 0;
  int currentPageCount = 1;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = (thisArray -> length () / 10);
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  system ("CLS");

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                                       REPORT LISTING                                                 *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                       ISBN       AUTHOR         PUBLISHER      DATE ADDED  QTY O/H WHOLESALE COST RETAIL PRICE *" << endl
       << "* --------------------------- ---------- -------------- -------------- ----------  ------- -------------- ------------ *" << endl;

  int i = 0;
  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    cout << "* " << left << setw (27) << (*it).getTitle ().substr (0, 25) << " " << setw (10) << (*it).getISBN ().substr (0, 10) << " " << setw (14) << (*it).getAuthor ().substr (0, 12) << " " << setw (14) << (*it).getPublisher ().substr (0, 12) << " " << setw (10) << (*it).getDateAdded () << "  " << right << setw (7) << (*it).getQtyOnHand () << " " << setw (6) << "$" << setw (8) << (*it).getWholesale () << " " << setw (4) << "$" << setw (8) << (*it).getRetail () << " *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      dateTime = getDateStr () + " @ " + getTimeStr ();
      currentPageCount++;
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                                       REPORT LISTING                                                 *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                       ISBN       AUTHOR         PUBLISHER      DATE ADDED  QTY O/H WHOLESALE COST RETAIL PRICE *" << endl
           << "* --------------------------- ---------- -------------- -------------- ----------  ------- -------------- ------------ *" << endl;
    }
    i++;
  }
  system ("pause");
}

void repWholesale (unorderedLinkedList <bookType>* thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  double totalINVWhole = 0;
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = thisArray -> length () / 10;
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                               REPORT LISTING: INVENTORY COST                                         *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                                                  ISBN                QTY O/H          WHOLESALE COST           *" << endl
       << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;

  int i = 0;
  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    cout << "* " << left << setw (45) << (*it).getTitle ().substr (0, 43) << "          " << setw (10) << (*it).getISBN ().substr (0, 10) << "          " << right << setw (7) << (*it).getQtyOnHand () << "          " << setw (6) << "$" << setw (8) << (*it).getWholesale () << "           *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      dateTime = getDateStr () + " @ " + getTimeStr ();
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                               REPORT LISTING: INVENTORY COST                                         *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                                                  ISBN                QTY O/H          WHOLESALE COST           *" << endl
           << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;
    }

    totalINVWhole = totalINVWhole + ((*it).getQtyOnHand () * (*it).getWholesale ());
    i++;
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl
       << "                                                   TOTAL WHOLESALE COST (ON-HAND INVENTORY): $" << right << setw (14) << totalINVWhole << "           *" << endl;
  //////////////////////
  system ("pause");
}

void repRetail (unorderedLinkedList <bookType>* thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  double totalINVRetail = 0;
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = thisArray -> length () / 10;
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                              REPORT LISTING: INVENTORY VALUE                                         *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                                                  ISBN                QTY O/H             RETAIL COST           *" << endl
       << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;

  int i = 0;
  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    cout << "* " << left << setw (45) << (*it).getTitle ().substr (0, 43) << "          " << setw (10) << (*it).getISBN ().substr (0, 10) << "          " << right << setw (7) << (*it).getQtyOnHand () << "          " << setw (6) << "$" << setw (8) << (*it).getRetail () << "           *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      dateTime = getDateStr () + " @ " + getTimeStr ();
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                              REPORT LISTING: INVENTORY VALUE                                         *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                                                  ISBN                QTY O/H          RETAIL COST              *" << endl
           << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;
    }

    totalINVRetail = totalINVRetail + ((*it).getQtyOnHand () * (*it).getRetail ());
    i++;
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl
       << "                                                     TOTAL RETAIL VALUE (ON-HAND INVENTORY): $" << right << setw (14) << totalINVRetail << "           *" << endl;

  //////////////////////
  system ("pause");
}

void repQty (unorderedLinkedList <bookType>* thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  orderedLinkedList <bookType> *convertedList = new orderedLinkedList <bookType> (listConverter (thisArray, 1));
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = thisArray -> length () / 10;
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                            REPORT LISTING BY ON-HAND-QUANTITY                                        *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "*                              TITLE                                                  ISBN               QTY O/H       *" << endl
       << "* ----------------------------------------------------------------------          -------------          -------       *" << endl;

  int i = 0;
  for (it = convertedList -> begin (); it != convertedList -> end (); ++it)
  {
    cout << "* " << left << setw (70) << (*it).getTitle ().substr (0, 70) << "          " << setw (13) << (*it).getISBN ().substr (0, 13) << "          " << right << setw (7) << (*it).getQtyOnHand () << "       *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      dateTime = getDateStr () + " @ " + getTimeStr ();
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                            REPORT LISTING BY ON-HAND-QUANTITY                                        *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "*                              TITLE                                                  ISBN               QTY O/H       *" << endl
           << "* ----------------------------------------------------------------------          -------------          -------       *" << endl;
    }
    i++;
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl;

  //////////////////////
  system ("pause");
}

void repCost (unorderedLinkedList <bookType>* thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  orderedLinkedList <bookType> *convertedList = new orderedLinkedList <bookType> (listConverter (thisArray, 2));
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = thisArray -> length () / 10;
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                              REPORT LISTING BY WHOLESALE COST                                        *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "*                              TITLE                                                  ISBN               WHOLESALE     *" << endl
       << "*                                                                                                           COST       *" << endl
       << "* ----------------------------------------------------------------------          -------------          ---------     *" << endl;

  int i = 0;
  for (it = convertedList -> begin (); it != convertedList -> end (); ++it)
  {
    cout << "* " << left << setw (70) << (*it).getTitle ().substr (0, 70) << "          " << setw (13) << (*it).getISBN ().substr (0, 13) << "          " << right << setw (9) << (*it).getWholesale () << "     *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      dateTime = getDateStr () + " @ " + getTimeStr ();
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                              REPORT LISTING BY WHOLESALE COST                                        *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "*                              TITLE                                                  ISBN               WHOLESALE     *" << endl
           << "*                                                                                                           COST       *" << endl
           << "* ----------------------------------------------------------------------          -------------          ---------     *" << endl;
    }
    i++;
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl;

  //////////////////////
  system ("pause");
}

void repAge (unorderedLinkedList <bookType>* thisArray)
{
  system ("CLS");
  ///////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  orderedLinkedList <bookType>* convertedList = new orderedLinkedList <bookType> (listConverter (thisArray, 3));
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  totalPageCount = thisArray -> length () / 10;
  if (thisArray -> length () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                               REPORT LISTING BY DATE ADDED                                           *" << endl
       << "*                                                                                                                      *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                                                  ISBN                QTY O/H            DATE ADDED             *" << endl
       << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;

  int i = 0;
  for (it = convertedList -> begin (); it != convertedList -> end (); ++it)
  {
    cout << "* " << left << setw (45) << (*it).getTitle ().substr (0, 43) << "          " << setw (10) << (*it).getISBN ().substr (0, 10) << "          " << right << setw (7) << (*it).getQtyOnHand () << "                " << setw (10) << (*it).getDateAdded () << "         *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      dateTime = getDateStr () + " @ " + getTimeStr ();
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                               REPORT LISTING BY DATE ADDED                                           *" << endl
           << "*                                                                                                                      *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                                 CURRENT BOOK COUNT:" << setw (5) << thisArray -> length () << "                  " << right << setw (26) << dateTime << " *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                                                  ISBN                QTY O/H            DATE ADDED             *" << endl
           << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;
    }
    i++;
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl;


  ///////////////////////
  system ("pause");
}

orderedLinkedList <bookType> listConverter (unorderedLinkedList <bookType>* otherList, int pSortCode)
{
  orderedLinkedList <bookType> convertedTemp;
  linkedListIterator <bookType> it;

  for (it = otherList -> begin (); it != otherList -> end (); ++it)
  {
    bookType *tempBookHolder = new bookType ((*it));
    tempBookHolder -> setSortCode (pSortCode);
    convertedTemp.insert (*tempBookHolder);
    delete tempBookHolder;
  }
  return convertedTemp;
}
