//
// Created by William Duong on 1/18/2019.
//
#include "mainmenu.h"
#include "reports.h"
#include "invmenu.h"
#include "cashier.h"

int bookType::bookCount = 0;

void bookType::incBookCount ()
{
  bookCount++;
}

void bookType::decBookCount ()
{
  bookCount--;
}

void mainMenu (bookType **thisArray)
{
  int userChoice = 0;

  do
  {
    system ("clear");

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

// *** CONSTRUCTORS *** //
bookType::bookType ()
{
  bookTitle = "EMPTY";
  isbn = "EMPTY";
  author = "EMPTY";
  publisher = "EMPTY";
  dateAdded = "EMPTY";
  qtyOnHand = 0;
  wholesale = 0;
  retail = 0;
}

bookType::bookType (string fTitle, string fISBN, string fAuthor, string fPublisher, string fDateAdded, int fQTY, double fWholesale, double fRetail)
{
  setTitle (fTitle);
  setISBN (fISBN);
  setAuthor (fAuthor);
  setPublisher (fPublisher);
  setDateAdded (fDateAdded);
  setQtyOnHand (fQTY);
  setWholesale (fWholesale);
  setRetail (fRetail);
}

// *** COPY CONSTRUCTOR *** //

// bookType::bookType (const booktype*& bookTwo)
// {
//   bookTitle = bookTwo.getTitle ();
//   isbn = bookTwo.getISBN ();
//   author = bookTwo.getAuthor ();
//   publisher = bookTwo.getPublisher ();
//   dateAdded = bookTwo.getDateAdded ();
//   qtyOnHand = bookTwo.getQtyOnHand ();
//   wholesale = bookTwo.getWholesale ();
//   retail = bookTwo.getRetail ();
// }

// *** SETTERS *** //
void bookType::setTitle (string fTitle)
{
  bookTitle = fTitle;
}

void bookType::setISBN (string fISBN)
{
  isbn = fISBN;
}

void bookType::setAuthor (string fAuthor)
{
  author = fAuthor;
}

void bookType::setPublisher (string fPublisher)
{
  publisher = fPublisher;
}

void bookType::setDateAdded (string fDateAdded)
{
  dateAdded = fDateAdded;
}

void bookType::setQtyOnHand (int fQTY)
{
  if (fQTY < 0)
    qtyOnHand = 0;
  else
    qtyOnHand = fQTY;
}

void bookType::setWholesale (double fWholesale)
{
  wholesale = fWholesale;
}

void bookType::setRetail (double fRetail)
{
  retail = fRetail;
}

// *** GETTERS *** //
string bookType::getTitle () const
{
  return bookTitle;
}

string bookType::getISBN () const
{
  return isbn;
}

string bookType::getAuthor () const
{
  return author;
}

string bookType::getPublisher () const
{
  return publisher;
}

string bookType::getDateAdded () const
{
  return dateAdded;
}

int bookType::getQtyOnHand () const
{
  return qtyOnHand;
}

double bookType::getWholesale () const
{
  return wholesale;
}

double bookType::getRetail () const
{
  return retail;
}

int bookType::getBookCount ()
{
  return bookCount;
}

// *** MISC *** //

void bookType::printBookInfo () const
{
  int pos = 0;
  int len = 40;

  system ("clear");

  cout << "************************************************************************************" << endl
       << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
       << "*                                    MAIN MENU                                     *" << endl
       << "*                                                                                  *" << endl
       << "*                  DATABASE SIZE: " << setw (8) << left << DBSIZE << "CURRENT BOOK COUNT: " << setw (8) << bookType::getBookCount () << "             *" << endl
       << "*                                                                                  *" << endl
       << "*                                                                                  *" << endl
       << "*   +  Book Title                    >  " << setw (43) << left << getTitle ().substr (pos, len) << "*" << endl
       << "*   +  I.S.B.N.                      >  " << setw (43) << getISBN () << "*" << endl
       << "*   +  Author                        >  " << setw (43) << getAuthor () << "*" << endl
       << "*   +  Publisher                     >  " << setw (43) << getPublisher () << "*" << endl
       << "*   +  Date Added (MM/DD/YYYY)       >  " << setw (43) << getDateAdded () << "*" << endl
       << "*   +  Quantity-on-Hand              >  " << setw (43) << getQtyOnHand () << "*" << endl
       << "*   +  Wholesale Price               >  " << setw (43) << getWholesale () << "*" << endl
       << "*   +  Retail Price                  >  " << setw (43) << getRetail () << "*" << endl
       << "*                                                                                  *" << endl
       << "************************************************************************************" << endl
       << endl;

  systemPause ();
}

bool bookType::isEqual (bookType *otherBook)
{
  if (isbn == otherBook -> getISBN ())
    return true;
  else
    return false;
}

void isGoodChoice (int whateverChoice, int first, int last)
{
  if ((whateverChoice < first) || (whateverChoice > last) || cin.fail ())
  {
    cout << endl
         << "INVALID INPUT! Please select integer option (" << first << " - " << last << ") " << endl
         << endl;
    systemPause ();
    cin.clear ();
    cin.ignore (100, '\n');
  }
}

void systemPause ()
{
  char ch;
  cout << "Please ENTER any key to continue: ";
  cin >> ch;
}
