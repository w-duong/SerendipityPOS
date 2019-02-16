//
// Created by admin on 1/18/2019.
//

#include "mainmenu.h"
#include "reports.h"
#include "invmenu.h"
#include "cashier.h"

void mainMenu ()
{
  int userChoice = 0;

  do
  {
    system ("CLS");

    const int NUMBER_COLUMN = 4;

    cout << endl;
    cout << setw (35) << setfill ('*') << "*" << endl;
    cout << "* " << setw (26) << setfill (' ') << right << "Serendipity Booksellers" << setw (7) << " *" << endl;
    cout << "* " << setw (20) << setfill (' ') << right << "Main Menu" << setw (13) << " *" << endl;
    cout << "* " << setw (31) << " " << " *" << endl;
    cout << "* " << setw (NUMBER_COLUMN) << left << "1." << setw (27) << "Cashier Module" << " *" << endl;
    cout << "* " << setw (NUMBER_COLUMN) << left << "2." << setw (27) << "Inventory Database Module" << " *" << endl;
    cout << "* " << setw (NUMBER_COLUMN) << left << "3." << setw (27) << "Report Module" << " *" << endl;
    cout << "* " << setw (NUMBER_COLUMN) << left << "4." << setw (27) << "Exit" << " *" << endl;
    cout << "* " << endl;
    cout << "* Enter Your Choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        cashierMenu ();
        break;
      case 2:
        inventoryMenu ();
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
