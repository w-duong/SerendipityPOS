#include <iostream>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "reports.h"

string bookTitle [DBSIZE];
string isbn [DBSIZE];
string author [DBSIZE];
string publisher [DBSIZE];
string dateAdded [DBSIZE];
int qtyOnHand [DBSIZE];
double wholesale [DBSIZE];
double retail [DBSIZE];

int main()
{
  int bookCount = 0;

  cout << fixed << showpoint << setprecision (2);

  mainMenu (bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail, bookCount);

  return 0;
}
