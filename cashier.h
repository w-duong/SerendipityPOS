//
// Created by admin on 1/18/2019.
//
#ifndef SERENDIPITY_CASHIER_H
#define SERENDIPITY_CASHIER_H

#include <ctime>
#include <string>
#include "mainmenu.h"

// namespace cashMOD
// {
//   time_t now = time (0);
//   char* currentTime = ctime (&now);
//   int qtyCOL = 5;
//   int isbnCOL = 25;
//   int titleCOL = 25;
//   int priceCOL = 10;
//   int totalCOL = 10;
//   int spacerROW = (qtyCOL + isbnCOL + titleCOL + priceCOL + totalCOL);
//
//   char userAction;
//   int userChoice = -1;
//
//   int index = 0;
//   int counter = 0;
//   string isbnValue [50];
//   string titleValue [50];
//   int qtyValue [50];
//   double priceValue [50];
//   const double TAX_RATE = 0.0825;
// }

void cashierMenu ();
void paintReceipt (const string isbnValue [50], const string titleValue [50], const int qtyValue [50], const double priceValue [50], int counter);

#endif //SERENDIPITY_CASHIER_H
