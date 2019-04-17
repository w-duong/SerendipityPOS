//
//Created by William Duong on 1/21/2019.
//
#include "reports.h"

void reportsMenu (bookType **thisArray)
{
  int userChoice = 0;

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
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
        repQty ();
        break;
      case 5:
        repCost ();
        break;
      case 6:
        repAge ();
        break;
    }
  }
  while (userChoice != 7);
  {
    return;
  }
}

void repListing (bookType **thisArray)
{
  int totalPageCount = 0;
  int currentPageCount = 1;

  totalPageCount = (bookType::getBookCount () / 10);
  if (bookType::getBookCount () % 10 > 0)
    totalPageCount += 1;

  system ("CLS");

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                                       REPORT LISTING                                                 *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                       ISBN       AUTHOR         PUBLISHER      DATE ADDED  QTY O/H WHOLESALE COST RETAIL PRICE *" << endl
       << "* --------------------------- ---------- -------------- -------------- ----------  ------- -------------- ------------ *" << endl;

  for (int i = 0; i < bookType::getBookCount (); i++)
  {
    cout << "* " << left << setw (27) << thisArray [i] -> getTitle ().substr (0, 25) << " " << setw (10) << thisArray [i] -> getISBN () << " " << setw (14) << thisArray [i] -> getAuthor ().substr (0, 12) << " " << setw (14) << thisArray [i] -> getPublisher ().substr (0, 12) << " " << setw (10) << thisArray [i] -> getDateAdded () << "  " << right << setw (7) << thisArray [i] -> getQtyOnHand () << " " << setw (6) << "$" << setw (8) << thisArray [i] -> getWholesale () << " " << setw (4) << "$" << setw (8) << thisArray [i] -> getRetail () << " *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                                       REPORT LISTING                                                 *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                       ISBN       AUTHOR         PUBLISHER      DATE ADDED  QTY O/H WHOLESALE COST RETAIL PRICE *" << endl
           << "* --------------------------- ---------- -------------- -------------- ----------  ------- -------------- ------------ *" << endl;
    }
  }
  system ("pause");
}

void repWholesale (bookType **thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  double totalINVWhole = 0;

  totalPageCount = (bookType::getBookCount () / 10);
  if (bookType::getBookCount () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                                       REPORT LISTING                                                 *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                                                  ISBN                QTY O/H          WHOLESALE COST           *" << endl
       << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;

  for (int i = 0; i < bookType::getBookCount (); i++)
  {
    cout << "* " << left << setw (45) << thisArray [i] -> getTitle ().substr (0, 43) << "          " << setw (10) << thisArray [i] -> getISBN () << "          " << right << setw (7) << thisArray [i] -> getQtyOnHand () << "          " << setw (6) << "$" << setw (8) << thisArray [i] -> getWholesale () << "           *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                                       REPORT LISTING                                                 *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                                                  ISBN                QTY O/H          WHOLESALE COST           *" << endl
           << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;
    }

    totalINVWhole = totalINVWhole + (thisArray [i] -> getQtyOnHand () * thisArray [i] -> getWholesale ());
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl
       << "                                                   TOTAL WHOLESALE COST (ON-HAND INVENTORY): $" << right << setw (14) << totalINVWhole << "           *" << endl;
  //////////////////////
  system ("pause");
}

void repRetail (bookType **thisArray)
{
  system ("CLS");
  //////////////////////
  int totalPageCount = 0;
  int currentPageCount = 1;
  double totalINVRetail = 0;

  totalPageCount = (bookType::getBookCount () / 10);
  if (bookType::getBookCount () % 10 > 0)
    totalPageCount += 1;

  cout << "************************************************************************************************************************" << endl
       << "*                                                                                                                      *" << endl
       << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
       << "*                                                       REPORT LISTING                                                 *" << endl
       << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
       << "*                                                                                                                      *" << endl
       << "* TITLE                                                  ISBN                QTY O/H             RETAIL COST           *" << endl
       << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;

  for (int i = 0; i < bookType::getBookCount (); i++)
  {
    cout << "* " << left << setw (45) << thisArray [i] -> getTitle ().substr (0, 43) << "          " << setw (10) << thisArray [i] -> getISBN () << "          " << right << setw (7) << thisArray [i] -> getQtyOnHand () << "          " << setw (6) << "$" << setw (8) << thisArray [i] -> getRetail () << "           *" << endl;
    cout << "*                                                                                                                      *" << endl;

    if ((((i + 1) % 10) == 0) && (currentPageCount < totalPageCount))
    {
      system ("pause");
      currentPageCount++;
      system ("CLS");
      cout << "************************************************************************************************************************" << endl
           << "*                                                                                                                      *" << endl
           << "*                                                  SERENDIPITY BOOKSELLERS                                             *" << endl
           << "*                                                       REPORT LISTING                                                 *" << endl
           << "* PAGE:" << right << setw (3) << currentPageCount << " of " << setw (3) << totalPageCount << "                             DATABASE SIZE:" << setw (5) << DBSIZE << "    CURRENT BOOK COUNT:" << setw (5) << bookType::getBookCount () << "                          *" << endl
           << "*                                                                                                                      *" << endl
           << "* TITLE                                                  ISBN                QTY O/H          RETAIL COST              *" << endl
           << "* ---------------------------------------------          ----------          -------          --------------           *" << endl;
    }

    totalINVRetail = totalINVRetail + (thisArray [i] -> getQtyOnHand () * thisArray [i] -> getRetail ());
  }
  cout << "*                                                                                                                      *" << endl
       << "************************************************************************************************************************" << endl
       << "                                                     TOTAL RETAIL VALUE (ON-HAND INVENTORY): $" << right << setw (14) << totalINVRetail << "           *" << endl;

  //////////////////////
  system ("pause");
}

void repQty ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY QUANTITY"
       << endl;
  system ("pause");
}

void repCost ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY COST"
       << endl;
  system ("pause");
}

void repAge ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY AGE"
       << endl;
  system ("pause");
}
