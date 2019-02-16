//
//Created by William Duong on 1/21/2019.
//
#include "reports.h"

void reportsMenu ()
{
  int userChoice = 0;

  do
  {
    const int NUMBER_COL = 4;

    system ("CLS");

    cout << endl;
    cout << setw (26) << setfill (' ') << right << "Serendipity Booksellers" << endl;
    cout << setw (18) << setfill (' ') << right << "Reports" << endl;
    cout << endl;

    cout << setw (NUMBER_COL) << left << "1." << "Inventory Listing" << endl
         << setw (NUMBER_COL) << left << "2." << "Inventory Wholesale Value" << endl
         << setw (NUMBER_COL) << left << "3." << "Inventory Retail Value" << endl
         << setw (NUMBER_COL) << left << "4." << "Listing by Quantity" << endl
         << setw (NUMBER_COL) << left << "5." << "Listing by Cost" << endl
         << setw (NUMBER_COL) << left << "6." << "Listing by Age" << endl
         << setw (NUMBER_COL) << left << "7." << "Return to Main Menu" << endl;
    cout << endl;
    cout << "Enter Your Choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        listing ();
        break;
      case 2:
        wholesale ();
        break;
      case 3:
        retail ();
        break;
      case 4:
        qtyList ();
        break;
      case 5:
        costList ();
        break;
      case 6:
        ageList ();
        break;
    }
  }
  while (userChoice != 7);
  {
    return;
  }
}

void listing ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR INVENTORY LISTING"
       << endl;
  system ("pause");
}

void wholesale ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR INVENTORY WHOLESALE VALUE"
       << endl;
  system ("pause");
}

void retail ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR INVENTORY RETAIL VALUE"
       << endl;
  system ("pause");
}

void qtyList ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY QUANTITY"
       << endl;
  system ("pause");
}

void costList ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY COST"
       << endl;
  system ("pause");
}

void ageList ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR LISTING BY AGE"
       << endl;
  system ("pause");
}
