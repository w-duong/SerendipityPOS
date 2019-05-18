//
// Created by William Duong on 5/15/2019.
//
#include "mainmenu.h"
#include "reports.h"
#include "invmenu.h"
#include "cashier.h"

void mainMenu (unorderedLinkedList <bookType>* thisArray)
{
  int userChoice = 0;
  linkedListIterator <bookType> it;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                              " << dateTime << "                              *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Cashier Module                                                              *" << endl
         << "*  <2> Inventory Database Module                                                   *" << endl
         << "*  <3> Report Module                                                               *" << endl
         << "*  <4> Exit                                                                        *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                               Enter Your Choice: ";

    cin >> userChoice;

    isGoodChoice (userChoice, 1, 4);

    switch (userChoice)
    {
      case 1:
        char cashierChoice4;
        do
        {
          cashierMenu (thisArray);

          cout << "CREATE A NEW SALE? (Y/N): ";
          cin >> cashierChoice4;
        }
        while ((cashierChoice4 != 'N') && (cashierChoice4 != 'n'));
        break;
      case 2:
        inventoryMenu (thisArray);
        break;
      case 3:
        reportsMenu (thisArray);
        break;
    }
  }
  while (userChoice != 4);
  {
    cout << endl
         << "THANKS FOR USING SERENDIPITY!" << endl
         << endl;
  }
}

void isGoodChoice (int whateverChoice, int first, int last)
{
  if ((whateverChoice < first) || (whateverChoice > last) || cin.fail ())
  {
    cout << endl
         << "INVALID INPUT! Please select integer option (" << first << " - " << last << ") " << endl
         << endl;
    system ("pause");
    cin.clear ();
    cin.ignore (100, '\n');
  }
}

string getDateStr ()
{
    time_t t = time(0);   // get time now
    tm* now = localtime (&t);

    string temp = to_string (now -> tm_mon + 1) + "-" + to_string (now -> tm_mday) + "-" + to_string (now -> tm_year + 1900);

    return temp;
}

string getTimeStr ()
{
    time_t now = chrono::system_clock::to_time_t (chrono::system_clock::now());

    string s(10, '\0');
    strftime (&s[0], s.size(), "%H:%M:%S", localtime (&now));
    return s;
}

void writeDataBase (unorderedLinkedList <bookType>* thisArray)
{
  linkedListIterator <bookType> it;
  ofstream coutFile;
  coutFile.open ("database-3.txt");

  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    coutFile << (*it).getTitle () << endl
             << (*it).getISBN () << endl
             << (*it).getAuthor () << endl
             << (*it).getPublisher () << endl
             << (*it).getDateAdded () << endl
             << (*it).getQtyOnHand () << endl
             << (*it).getWholesale () << endl
             << (*it).getRetail () << endl;
  }

  coutFile.close ();
}
