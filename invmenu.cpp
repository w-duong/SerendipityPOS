//
// Created by William Duong on 1/18/2019.
//
#include "invmenu.h"
#include "bookinfo.h"

void inventoryMenu (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount)
{
  int userChoice = 0;
  int resultCounter = 0;

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Look Up a Book                                                              *" << endl
         << "*  <2> Add a Book                                                                  *" << endl
         << "*  <3> Edit a Book's Record                                                        *" << endl
         << "*  <4> Delete a Book                                                               *" << endl
         << "*  <5> Return to the Main Menu                                                     *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                            Enter Your Choice (1-5): ";

    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        int tempArrayIndex [20];
        char userChoice1;

        resultCounter = lookUpBook (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << bookTitle [tempArrayIndex [i]] << endl
               << "View this book record? (Y/N): ";
          cin >> userChoice1;

          if (userChoice1 == 'Y' || userChoice1 == 'y')
          {
            bookInfo (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, tempArrayIndex [i]);
          }
        }
        break;
      case 2:
        addBook (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);
        break;
      case 3:
        char editChoice1;
        char editChoice2;

        resultCounter = lookUpBook (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << bookTitle [tempArrayIndex [i]] << endl
               << "View this book record? (Y/N): ";
          cin >> editChoice1;

          if (editChoice1 == 'Y' || editChoice1 == 'y')
          {
            bookInfo (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, tempArrayIndex [i]);
            cout << endl
                 << "Do you want to EDIT this book? (Y/N): ";
            cin >> editChoice2;
            if (editChoice2 == 'Y' || editChoice2 == 'y')
            {
              bookEdit (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount, tempArrayIndex [i]);
            }
          }
        }
        break;
      case 4:
        char deleteChoice1;
        char deleteChoice2;

        resultCounter = lookUpBook (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << bookTitle [tempArrayIndex [i]] << endl
               << "View this book record? (Y/N): ";
          cin >> deleteChoice1;

          if (deleteChoice1 == 'Y' || deleteChoice1 == 'y')
          {
            bookInfo (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, tempArrayIndex [i]);
            cout << endl
                 << "Do you want to DELETE this book? (Y/N): ";
            cin >> deleteChoice2;
            if (deleteChoice2 == 'Y' || deleteChoice2 == 'y')
            {
              bookDelete (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount, tempArrayIndex [i]);
              cout << endl
                   << "BOOK DELETED" << endl
                   << endl;
              system ("pause");
            }
           }
         }
         break;
        }
  }
  while (userChoice != 5);
  {
    return;
  }
}

int lookUpBook (const string bookTitle [], const string isbn [], const string author [], const string publisher [], const string dateAdded [], const int qtyOnHand [], const double wholesale [], const double retail [], const int bookCount, int tempArrayIndex [])
{
  string searchStr;
  string tempArray [20];
  int counterNegative = 0;
  int resultCounter = 0;

  cout << ">>> BOOK LOOK UP <<<" << endl
       << endl
       << "Search:> " << endl;
  cin.ignore ();
  getline (cin, searchStr);

  string temp1 = toLower (searchStr);

  // //VISUAL CHECK:
  // cout << "SEARCH STRING...: " << temp1 << endl;
  //
  // system ("pause");

  for (int i = 0; i < bookCount; i++)
  {
    string temp2 = toLower (bookTitle [i]);
    if ((temp2.find (temp1) != string::npos) || (isbn [i].find (searchStr) != string::npos))
    {
      tempArray [resultCounter] = bookTitle [i];
      tempArrayIndex [resultCounter] = i;
      resultCounter++;
    }
    if ((temp2.find (temp1) == string::npos) && (isbn [i].find (searchStr) == string::npos))
    {
      counterNegative++;
    }
  }

  if (counterNegative == bookCount)
  {
    cout << "ITEM NOT FOUND!" << endl
         << endl;
    system ("pause");
  }
  return resultCounter;
}

void addBook (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount)
{
  int userChoice = -1;
  int pos = 0;
  int len = 35;

  string tempBookTitle = "EMPTY";
  string tempISBN = "EMPTY";
  string tempAuthor = "EMPTY";
  string tempPublisher = "EMPTY";
  string tempDateAdded = "EMPTY";
  int tempQtyOnHand = 0;
  double tempWholesale = 0;
  double tempRetail = 0;

  if (bookCount >= 20)
  {
    cout << endl
         << "*** ERROR: BOOK DATABASE FULL. CURRENT BOOK COUNT: " << bookCount << " ***" << endl
         << endl
         << "Please delete a book to add more items to database." << endl;
    system ("pause");
    return;
  }

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                  DATABASE SIZE: " << setw (8) << left << DBSIZE << "CURRENT BOOK COUNT: " << setw (8) << bookCount << "             *" << endl
         << "*                                                                                  *" << endl
         << "*                                                   --PENDING VALUES--             *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Enter Book Title              >  " << setw (43) << left << tempBookTitle.substr (pos, len) << "*" << endl
         << "*  <2> Enter ISBN                    >  " << setw (43) << tempISBN << "*" << endl
         << "*  <3> Enter Author                  >  " << setw (43) << tempAuthor << "*" << endl
         << "*  <4> Enter Publisher               >  " << setw (43) << tempPublisher << "*" << endl
         << "*  <5> Enter Date Added (MM/DD/YYYY) >  " << setw (43) << tempDateAdded << "*" << endl
         << "*  <6> Enter Quantity on Hand        >  " << setw (43) << tempQtyOnHand << "*" << endl
         << "*  <7> Enter Wholesale Price         >  " << setw (43) << tempWholesale << "*" << endl
         << "*  <8> Enter Retail Price            >  " << setw (43) << tempRetail << "*" << endl
         << "*  <9> Save Book to Database                                                       *" << endl
         << "*  <0> Return to Inventory Menu                                                    *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                                  CHOICE (0-9): ";

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
        cout << "Enter Book Title: ";
        cin.ignore ();
        getline (cin, tempBookTitle);
        break;
      case 2:
        cout << "Enter ISBN: ";
        cin.ignore ();
        getline (cin, tempISBN, '\n');
        break;
      case 3:
        cout << "Enter Author: ";
        cin.ignore ();
        getline (cin, tempAuthor, '\n');
        break;
      case 4:
        cout << "Enter Publisher: ";
        cin.ignore ();
        getline (cin, tempPublisher, '\n');
        break;
      case 5:
        cout << "Enter Date Added (MM/DD/YYYY): ";
        cin.ignore ();
        getline (cin, tempDateAdded, '\n');
        break;
      case 6:
        cout << "Enter Quantity-on-Hand: ";
        cin >> tempQtyOnHand;
        break;
      case 7:
        cout << "Enter Wholesale Price: ";
        cin >> tempWholesale;
        break;
      case 8:
        cout << "Enter Retail Price: ";
        cin >> tempRetail;
        break;
      case 9:
        bookTitle [bookCount] = tempBookTitle;
        isbn [bookCount] = tempISBN;
        author [bookCount] = tempAuthor;
        publisher [bookCount] = tempPublisher;
        dateAdded [bookCount] = tempDateAdded;
        qtyOnHand [bookCount] = tempQtyOnHand;
        wholesale [bookCount] = tempWholesale;
        retail [bookCount] = tempRetail;
        bookCount++;
        break;
    }

  }
  while ((userChoice != 0) && (bookCount != 20));
  {
    return;
  }
}

void bookEdit (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int bookCount, int tempArrayIndexVal)
{
  int userChoice = 0;
  do
  {
    system ("CLS");

    int pos = 0;
    int len = 35;

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                 DATABASE SIZE: " << setw (8) << left << DBSIZE << "CURRENT BOOK COUNT: " << setw (8) << bookCount << "             *" << endl
         << "*                                                                                  *" << endl
         << "*                                                   --PENDING VALUES--             *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Enter Book Title              >  " << setw (43) << left << bookTitle [tempArrayIndexVal].substr (pos, len) << "*" << endl
         << "*  <2> Enter ISBN                    >  " << setw (43) << isbn [tempArrayIndexVal] << "*" << endl
         << "*  <3> Enter Author                  >  " << setw (43) << author [tempArrayIndexVal] << "*" << endl
         << "*  <4> Enter Publisher               >  " << setw (43) << publisher [tempArrayIndexVal] << "*" << endl
         << "*  <5> Enter Date Added (MM/DD/YYYY) >  " << setw (43) << dateAdded [tempArrayIndexVal] << "*" << endl
         << "*  <6> Enter Quantity on Hand        >  " << setw (43) << qtyOnHand [tempArrayIndexVal] << "*" << endl
         << "*  <7> Enter Wholesale Price         >  " << setw (43) << wholesale [tempArrayIndexVal] << "*" << endl
         << "*  <8> Enter Retail Price            >  " << setw (43) << retail [tempArrayIndexVal] << "*" << endl
         << "*  <9> Return to Previous Menu                                                     *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                                  CHOICE (1-9): ";
    cin >> userChoice;

    switch (userChoice)
    {
      case 1:
        cout << "Enter Book Title: > ";
        cin.ignore ();
        getline (cin, bookTitle [tempArrayIndexVal]);
        break;
      case 2:
        cout << "Enter ISBN : > ";
        cin.ignore ();
        getline (cin, isbn [tempArrayIndexVal]);
        break;
      case 3:
        cout << "Enter Author: > ";
        cin.ignore ();
        getline (cin, author [tempArrayIndexVal]);
        break;
      case 4:
        cout << "Enter Publisher: > ";
        cin.ignore ();
        getline (cin, publisher [tempArrayIndexVal]);
        break;
      case 5:
        cout << "Enter Date Added: > ";
        cin.ignore ();
        getline (cin, dateAdded [tempArrayIndexVal]);
        break;
      case 6:
        cout << "Enter quantity-on-hand: > ";
        cin >> qtyOnHand [tempArrayIndexVal];
        break;
      case 7:
        cout << "Enter wholesale price: > ";
        cin >> wholesale [tempArrayIndexVal];
        break;
      case 8:
        cout << "Enter retail price: > ";
        cin >> retail [tempArrayIndexVal];
        break;
    }
  }
  while (userChoice != 9);
  {
    return;
  }
}

void bookDelete (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount, int tempArrayIndexVal)
{
  for (int i = tempArrayIndexVal; i < (bookCount - 1); i++)
  {
    bookTitle [i] = bookTitle [i + 1];
    isbn [i] = isbn [i + 1];
    author [i] = author [i + 1];
    publisher [i] = publisher [i + 1];
    dateAdded [i] = dateAdded [i + 1];
    qtyOnHand [i] = qtyOnHand [i + 1];
    wholesale [i] = wholesale [i + 1];
    retail [i] = retail [i + 1];
  }

  bookCount--;
  return;
}

string toLower (string variableStr)
{
  for (int i = 0; i < variableStr.length (); i++)
  {
    if ((variableStr [i] >= 'A') && (variableStr [i] <= 'Z'))
    {
      variableStr [i] = variableStr [i] + 32;
    }
  }

  return variableStr;
}

// void printBookDB (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount)
// {
//   cout << bookCount << endl;
//   cout << endl;
//
//   for (int i = 0; i < 20; i++)
//   {
//     cout << bookTitle [i] << endl
//          << isbn [i] << endl
//          << author [i] << endl
//          << publisher [i] << endl;
//   }
// }
