// ----------------------------------------------------------------------
// File name: bookType.h
// Project name: Serendipity
// ----------------------------------------------------------------------
// William Duong, wduong1@saddleback.edu
// CS1B
// Creation Date 5/15/2019
// Last Modified 5/15/2019
// ----------------------------------------------------------------------
// Purpose: Declares and defines bookType class.
// ----------------------------------------------------------------------
// Algorithm: N/A
// ----------------------------------------------------------------------
// -			DATA DICTIONARY
// - CONSTANTS
// -
// - NAME		               DATA TYPE		               INITIAL VALUE
// - --------		           -------------		           -------------
// - DBSIZE		             int			                   20
// -
// - VARIABLES
// -
// - NAME		               DATA TYPE		               INITIAL VALUE
// - --------		           -------------		           -------------
// - bookType		           class
// - bookType.bookTitle	   string
// - bookType.isbn	       string
// - bookType.author	     string
// - bookType.publisher	   string
// - bookType.dateAdded	   string
// - bookType.qtyOnHand	   int			                   0
// - bookType.wholesale	   double			                 0
// - bookType.retail	     double			                 0
// - bookType.searchFlag   bool                        false
// - bookType.qtyInCart    int                         0
// - greaterThan           bool                        false
// -
// - bookCount		         static int		               0
//
// ----------------------------------------------------------------------
#include "bookType.h"

///////////////////////////////////////////////////////////////////////////////
// DEFINING MEMBER FUNCTIONS/VARIABLES                                       //
///////////////////////////////////////////////////////////////////////////////

int bookType::bookCount = 0;

void bookType::incBookCount ()
{
  bookCount++;
}

void bookType::decBookCount ()
{
  bookCount--;
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
  sortCode = 0;
  searchFlag = false;
  qtyInCart = 0;
}

bookType::bookType (string fTitle, string fISBN, string fAuthor, string fPublisher, string fDateAdded, int fQTY, double fWholesale, double fRetail, int fSortCode)
{
  setTitle (fTitle);
  setISBN (fISBN);
  setAuthor (fAuthor);
  setPublisher (fPublisher);
  setDateAdded (fDateAdded);
  setQtyOnHand (fQTY);
  setWholesale (fWholesale);
  setRetail (fRetail);
  setSortCode (fSortCode);
  setSearchFlag (false);
  setQtyInCart (0);
}

// *** COPY CONSTRUCTOR *** //

bookType::bookType (bookType* bookTwo)
{
  bookTitle = bookTwo -> getTitle ();
  isbn = bookTwo -> getISBN ();
  author = bookTwo -> getAuthor ();
  publisher = bookTwo -> getPublisher ();
  dateAdded = bookTwo -> getDateAdded ();
  qtyOnHand = bookTwo -> getQtyOnHand ();
  wholesale = bookTwo -> getWholesale ();
  retail = bookTwo -> getRetail ();
}

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

void bookType::setSortCode (int fSortCode)
{
  sortCode = fSortCode;
}

void bookType::setSearchFlag (bool fFlag)
{
  searchFlag = fFlag;
}

void bookType::setQtyInCart (int fQTY)
{
  qtyInCart = fQTY;
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

int bookType::getSortCode ()
{
  return sortCode;
}

bool bookType::getSearchFlag ()
{
  return searchFlag;
}

int bookType::getQtyInCart ()
{
  return qtyInCart;
}

// *** MISC/OVERLOADED FUNCTIONS *** //

void bookType::printBookInfo () const
{
  int pos = 0;
  int len = 40;

  system ("CLS");

  cout << "************************************************************************************" << endl
       << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
       << "*                                    MAIN MENU                                     *" << endl
       << "*                                                                                  *" << endl
       << "*                                                                                  *" << endl
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

  system ("pause");
}

bool bookType::isEqual (bookType *otherBook)
{
  if (isbn == otherBook -> getISBN ())
    return true;
  else
    return false;
}

bool bookType::operator == (const bookType& otherBook) const
{
  if (isbn == otherBook.isbn)
    return true;
  else
    return false;
}

bool bookType::operator != (const bookType& otherBook) const
{
  if (!(isbn == otherBook.isbn))
    return true;
  else
    return false;
}

bool bookType::operator >= (const bookType& otherBook) const
{
  bool greaterThan = false;
  string temp1 = this -> getTitle ();
  string temp2 = otherBook.getTitle ();
  string one;
  string two;
  int oneTemp = 0;
  int twoTemp = 0;

  if (this != &otherBook)
  {
    switch (otherBook.sortCode)
    {
        case 0: // *** COMPARING BY TITLE *** //
          if (temp1.compare (temp2) >= 0)
            greaterThan = true;
          break;
        case 1: // *** COMPARING BY QTY-ON-HAND *** //
          if (this -> qtyOnHand <= otherBook.qtyOnHand)
            greaterThan = true;
          break;
        case 2: // *** COMPARING BY WHOLESALE-COST *** //
          if (this -> wholesale <= otherBook.wholesale)
            greaterThan = true;
          break;
        case 3: // *** COMPARING BY DATE ADDED *** //
          greaterThan = false;
          one = this -> getDateAdded ().substr (6,10);
          oneTemp = atoi (one.c_str());

          two = otherBook.dateAdded.substr (6,10);
          twoTemp = atoi (two.c_str());

          if (oneTemp > twoTemp)
            greaterThan = true;
          else
          {
            if (oneTemp == twoTemp)
            {
              one = this -> getDateAdded ().substr (0,2);
              oneTemp = atoi (one.c_str());

              two = otherBook.dateAdded.substr (0,2);
              twoTemp = atoi (two.c_str());

              if (oneTemp > twoTemp)
                greaterThan = true;
              else
              {
                if (oneTemp == twoTemp)
                {
                  one = this -> getDateAdded ().substr (3,5);
                  oneTemp = atoi (one.c_str());

                  two = otherBook.dateAdded.substr (3,5);
                  twoTemp = atoi (two.c_str());

                  if (oneTemp > twoTemp)
                    greaterThan = true;
                }
              }
            }
          }
          break;
      }
  }
  return greaterThan;
}

ostream& operator << (ostream& ccout, const bookType& otherBook)
{
  ccout << "\tTITLE         : " << otherBook.bookTitle << endl
        << "\tISBN          : " << otherBook.isbn << endl
        << "\tAUTHOR        : " << otherBook.author << endl
        // << "\tPUBLISHER     : " << otherBook.publisher << endl
        // << "\tDATE ADDED    : " << otherBook.dateAdded << endl
        << "\tQTY-ON-HAND   : " << otherBook.qtyOnHand << endl
        // << "\tWHOLESALE COST: " << otherBook.wholesale << endl
        << "\tRETAIL PRICE  : " << otherBook.retail << endl << endl;
  return ccout;
}
