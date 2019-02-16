//
//Created by William Duong on 1/21/2019.
//

#include "bookinfo.h"
#include <string>

void bookInfo (const string bookTitle [DBSIZE], const string isbn [DBSIZE], const string author [DBSIZE], const string pubisher [DBSIZE], const string date [DBSIZE], const int qty [DBSIZE], const double wholesale [DBSIZE], const double retail [DBSIZE], int bookIndex)
{
  system ("CLS");

  cout << endl;
  cout << setw (26) << setfill (' ') << right << "Serendipity Booksellers" << endl;
  cout << setw (20) << setfill (' ') << right << "Book Information" << endl;
  cout << endl;
  cout << "ISBN: " << isbn [bookIndex] << endl
       << "Title: " << bookTitle [bookIndex] << endl
       << "Author: " << author [bookIndex] << endl
       << "Publisher: " << publisher [bookIndex] << endl
       << "Date Added: " << date [bookIndex] << endl
       << "Quantity-On-Hand: " << qtyOnHand [bookIndex] << endl
       << "Wholesale Cost: " << wholesale [bookIndex] << endl
       << "Retail Price: " << retail [bookIndex] << endl;
  cout << endl;

  cout << "Return any key to go back to previous menu." << endl;

  system ("pause");
}
