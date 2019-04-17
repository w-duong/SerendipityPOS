#include <iostream>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"

int main()
{
  bookType **thisArray = new bookType *[DBSIZE];

  cout << fixed << showpoint << setprecision (2);

  mainMenu (thisArray);

  delete [] thisArray;

  return 0;
}
