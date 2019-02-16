#include <iostream>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "reports.h"

int main()
{
  const int DBSIZE = 20;
  int bookCount = 0;

  string bookTitle [DBSIZE];
  string isbn [DBSIZE];
  string author [DBSIZE];
  string publisher [DBSIZE];
  string dateAdded [DBSIZE];
  int qtyOnHand [DBSIZE];
  double wholesale [DBSIZE];
  double retail [DBSIZE];

  mainMenu ();

  return 0;
}
