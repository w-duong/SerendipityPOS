//
// Created by William Duong on 1/18/2019.
//

#include "invmenu.h"

void inventoryMenu ()
{
  int userChoice = 0;

  do
  {
    system ("CLS");

    const int NUMBER_COL = 4;

    cout << endl;
    cout << setw (26) << setfill (' ') << right << "Serendipity Booksellers" << endl;
    cout << setw (24) << setfill (' ') << right << "Inventory Database" << endl;
    cout << endl;

    cout << setw (NUMBER_COL) << left << "1." << "Look Up a Book" << endl
         << setw (NUMBER_COL) << left << "2." << "Add a Book" << endl
         << setw (NUMBER_COL) << left << "3." << "Edit a Book's Record" << endl
         << setw (NUMBER_COL) << left << "4." << "Delete a Book" << endl
         << setw (NUMBER_COL) << left << "5." << "Return to the Main Menu" << endl;
    cout << endl;
    cout << "Enter Your Choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        bookSearch ();
        break;
      case 2:
        addBook ();
        break;
      case 3:
        bookEdit ();
        break;
      case 4:
        bookDelete ();
        break;
    }
  }
  while (userChoice != 5);
  {
    return;
  }
}

void bookSearch ()
{
    system ("CLS");
    cout << endl;
    cout << "PLACEHOLDER FOR BOOK LOOKUP";
    cout << endl;
    system ("pause");
}

void addBook (int bookCount)
{
  int userChoice = -1;

  do
  {
    system ("CLS");

    cout << "******************************************************************************" << endl
         << "*                          SERENDIPITY BOOKSELLERS                           *" << endl
         << "*                                 ADD BOOK                                   *" << endl
         << "*                   DATABASE SIZE:        CURRENT BOOK COUNT:                *" << endl
         << "*                                                                            *" << endl
         << "*                                                      --PENDING VALUES--    *" << endl
         << "*                                                                            *" << endl
         << "*  <1> Enter Book Title              >  ;" << bookTitle [i] << endl
         << "*  <2> Enter ISBN                    >  ;" << isbn [i] << endl
         << "*  <3> Enter Author                  >  ;" << author [i] << endl
         << "*  <4> Enter Publisher               >  ;" << publisher [i] << endl
         << "*  <5> Enter Date Added (MM/DD/YYYY) >  ;" << dateAdded [i] << endl
         << "*  <6> Enter Quantity on Hand        >  ;" << qtyOnHand [i] << endl
         << "*  <7> Enter Wholesale Price         >  ;" << wholesale [i] << endl
         << "*  <8> Enter Retail Price            >  ;" << retail [i] << endl
         << "*  <9> Save Book to Database                                                 *" << endl
         << "*  <0> Return to Inventory Menu                                              *" << endl
         << "*                                                                            *" << endl
         << "******************************************************************************" << endl
         << "                                CHOICE (0-9): "; << endl;

    cout << endl;
    cin >> userChoice;
    while (cin.fail () || userChoice < 0 || userChoice > 9)
    {
      cout << "Please input correct OPTION: ";
      cin.clear ();
      cin.ignore ();
      cin >> userChoice;
    }

    cout << endl;
    switch (userChoice)
    {
      case 1:
        cout << ""
    }

  }
  while (userChoice != 0);
  {
    return;
  }
}

void bookEdit ()
{
    system ("CLS");
    cout << endl;
    cout << "PLACEHOLDER FOR BOOK EDIT";
    cout << endl;
    system ("pause");
}

void bookDelete ()
{
  system ("CLS");
  cout << endl
       << "PLACEHOLDER FOR BOOK DELETE"
       << endl;
  system ("pause");
}
