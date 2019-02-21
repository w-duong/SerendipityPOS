//
// Created by admin on 1/18/2019.
//
#include "mainmenu.h"
#include "reports.h"
#include "invmenu.h"
#include "cashier.h"

void mainMenu (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount)
{
  int userChoice = 0;

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Cashier Module                                                              *" << endl
         << "*  <2> Inventory Database Module                                                   *" << endl
         << "*  <3> Report Module                                                               *" << endl
         << "*  <4> Exit                                                                        *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                               Enter Your Choice: ";

    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        cashierMenu ();
        break;
      case 2:
        inventoryMenu (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
        break;
      case 3:
        reportsMenu ();
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
