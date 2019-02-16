//
// Created by admin on 1/18/2019.
//
#include "cashier.h"
#include <string>
#include <iomanip>

//using namespace cashMOD;
time_t now = time (0);
char* currentTime = ctime (&now);
int qtyCOL = 5;
int isbnCOL = 25;
int titleCOL = 25;
int priceCOL = 10;
int totalCOL = 10;
int spacerROW = (qtyCOL + isbnCOL + titleCOL + priceCOL + totalCOL);

const double TAX_RATE = 0.0825;

void cashierMenu ()
{
    int userChoice = 1;

    int index = 0;
    int counter = 0;
    string isbnValue [50];
    string titleValue [50];
    int qtyValue [50];
    double priceValue [50];

    do
    {
      paintReceipt (isbnValue, titleValue, qtyValue, priceValue, counter);

      if (userChoice = 1)
      {
        /*
        string dateTime;

        cout << "Please enter the date: ";
        getline (cin, dateTime);
        */

        cout << "Please enter ISBN # of book: ";
        cin.clear ();
        cin.ignore ();
        getline (cin, isbnValue [index]);
        cout << "Please enter title of book: ";
        getline (cin, titleValue [index]);
        cout << "Please enter price of book: ";
        cin >> priceValue [index];

        while (cin.fail () || priceValue [index] < 0)
        {
          cout << "Please input correct DOLLAR amount!" << endl;
          cin.clear ();
          cin.ignore (5, '\n');
          cin >> priceValue [index];
        }

        cout << "Please enter quantity of book(s): ";
        cin >> qtyValue [index];

        while (cin.fail () || qtyValue [index] < 1)
        {
          cout << "Please input correct QUANTITY of book to be sold!" << endl;
          cin.clear ();
          cin.ignore (5, '\n');
          cin >> qtyValue [index];
        }

        counter++;
        index++;

        paintReceipt (isbnValue, titleValue, qtyValue, priceValue, counter);

        cout << "Would you like to continue? (NO = 0, YES = 1): ";
        cin >> userChoice;
        while (cin.fail () || userChoice < 0 || userChoice > 1)
        {
          cout << "Please input correct OPTION: ";
          cin.clear ();
          cin.ignore ();
          cin >> userChoice;
        }
      }

    }
    while(userChoice != 0);
    {
      return;
    }
}

void paintReceipt (const string isbnValue [50], const string titleValue [50], const int qtyValue [50], const double priceValue [50], int counter)
{
  system ("CLS");

  cout << fixed << showpoint << setprecision (2);

  cout << "Serendipity Book Sellers" << endl;
  cout << endl;
  cout << "Date: " << currentTime << endl;
  cout << endl;
  cout << setw (qtyCOL) << left << "Qty" << setw (isbnCOL) << "ISBN" << setw (titleCOL) << "Title" << setw (priceCOL) << right << "Price" << setw (totalCOL) << "Total" << endl;
  cout << setw (spacerROW) << setfill ('_') << "_" << endl;
  cout << endl;

  double subtotalValueLine = 0;

  for (int i = 0; i < counter; i++)
  {
    double subtotalValueCol [50];

    subtotalValueCol [i] = qtyValue [i] * priceValue [i];
    subtotalValueLine += subtotalValueCol [i];

    cout << setw (qtyCOL) << setfill (' ') << left << qtyValue [i] << setw (isbnCOL) << isbnValue [i] << setw (titleCOL) << titleValue [i] << setw (priceCOL) << right << priceValue [i] << setw (totalCOL) << subtotalValueCol [i] << endl;
  }

  double taxValue = subtotalValueLine * TAX_RATE;
  double totalValue = subtotalValueLine * (1 + TAX_RATE);

  cout << endl
       << endl
       << endl;

  cout << setw (20) << setfill (' ') << right << "Subtotal" << setw (47) << "$ " << setw (8) << subtotalValueLine << endl;
  cout << setw (20) << right << "Tax" << setw (47) << "$ " << setw (8) << taxValue << endl;
  cout << setw (20) << right << "Total" << setw (47) << "$ " << setw (8) << totalValue << endl;
  cout << endl;
  cout << "Thank You for Shopping at Serendipity!" << endl;
  cout << endl;
}
