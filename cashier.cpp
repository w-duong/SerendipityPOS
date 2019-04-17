//
// Created by William Duong on 1/18/2019.
//
#include "cashier.h"
#include "invmenu.h"
#include "mainmenu.h"

time_t now = time (0);
char* currentTime = ctime (&now);

void cashierMenu (bookType **thisArray)
{
  int cashierChoice = 0;
  char cashierChoice2;
  char cashierChoice3;
  int resultCounter = 0;
  int qtySubtracted = 0;


  int bookIndex = 0;
  bookType **shoppingCart = new bookType *[DBSIZE];

  // CREATING PARALLEL ARRAY "SHOPPING CART" //
  for (int k = 0; k < bookType::getBookCount (); k++)
  {
    shoppingCart [k] = new bookType (thisArray [k] -> getTitle (), thisArray [k] -> getISBN (), thisArray [k] -> getAuthor (), thisArray [k] -> getPublisher (), thisArray [k] -> getDateAdded (), thisArray [k] -> getQtyOnHand (), thisArray [k] -> getWholesale (), thisArray [k] -> getRetail ());
    shoppingCart [k] -> setQtyOnHand (0);
  }

  do
  {
    paintReceipt (shoppingCart);

    cout << endl
         << endl
         << "\t      **************************************************" << endl
         << "\t      *                                                *" << endl
         << "\t      *  <1> LOOK UP BOOK TO SELL                      *" << endl
         << "\t      *  <2> EDIT QUANTITY TO SELL                     *" << endl
         << "\t      *  <3> COMPLETE SALE                             *" << endl
         << "\t      *  <4> EXIT SALE                                 *" << endl
         << "\t      *                                                *" << endl
         << "\t      **************************************************" << endl
         << "\t                       OPTION (1-4): ";

    cin >> cashierChoice;

    isGoodChoice (cashierChoice, 1, 4);

    switch (cashierChoice)
    {
      case 1:
        int tempArrayIndex [20];
        char buyChoice1;
        char buyChoice2;

        resultCounter = lookUpBook (thisArray, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
               << "View this book record? (Y/N): ";
          cin >> buyChoice1;

          if (buyChoice1 == 'Y' || buyChoice1 == 'y')
          {
            thisArray [tempArrayIndex [i]] -> printBookInfo ();
            cout << endl
                 << "Do you want to SELL this book? (Y/N): ";
            cin >> buyChoice2;
            if (buyChoice2 == 'Y' || buyChoice2 == 'y')
            {
              cout << endl
                   << "ENTER QUANTITY TO BE SOLD: ";
              cin >> qtySubtracted;

              // INITIAL QUANTITY CHECK/INPUT VALIDATION //
              while ((qtySubtracted > thisArray [tempArrayIndex [i]] -> getQtyOnHand ()) || (qtySubtracted < 0))
              {
                cout << endl
                     << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS: " << thisArray [tempArrayIndex [i]] -> getQtyOnHand () << endl
                     << endl
                     << "Please enter valid quantity to sell: ";
                cin >> qtySubtracted;
              }

              // CROSS REFERENCE SHOPPING CART WITH BOOK TO BE SOLD. ISBN MATCH = ITEM TO BE SOLD. UPDATE QTY TO SELL //
              for (int j = 0; j < bookType::getBookCount (); j++)
              {
                // IF SHOPPING CART DOESN'T ALREADY HAVE ITEM //
                if ((thisArray [tempArrayIndex [i]] -> isEqual (shoppingCart [j])) && (shoppingCart [tempArrayIndex [i]] -> getQtyOnHand () == 0))
                  shoppingCart [j] -> setQtyOnHand (qtySubtracted);
                // IF SHOPPING CART HAS ITEM ALREADY INSIDE, ADD ADDITIONAL QUANTITY + VALIDATE TOTAL QUANTITY //
                else if ((thisArray [tempArrayIndex [i]] -> isEqual (shoppingCart [j])) && (shoppingCart [tempArrayIndex [i]] -> getQtyOnHand () > 0))
                {
                  // VALIDATE TOTAL QUANTITY SOLD IS VALID/DOESN'T EXCEED TOTAL QUANTITY ON HAND //
                  while (qtySubtracted + shoppingCart [j] -> getQtyOnHand () > thisArray [tempArrayIndex [i]] -> getQtyOnHand ())
                  {
                    cout << endl
                         << "INVALID QUANTITY! CURRENT CURRENT ON HAND QUANTITY IS   : " << thisArray [tempArrayIndex [i]] -> getQtyOnHand () << endl
                         << "                  CURRENT QUANTITY IN SHOPPING CART IS  : " << shoppingCart [j] -> getQtyOnHand () << endl
                         << endl
                         << "Please enter valid quantity to sell: ";
                    cin >> qtySubtracted;
                  }

                  shoppingCart [j] -> setQtyOnHand (qtySubtracted + shoppingCart [j] -> getQtyOnHand ());
                }
              }
              break;
            }
          }
        }
        break;
      case 2:
        for (int i = 0; i < bookType::getBookCount (); i++)
        {
          if (shoppingCart [i] -> getQtyOnHand () > 0)
          {
            int qtySubtractedEdit = 0;

            cout << endl
                 << shoppingCart [i] -> getTitle () << endl
                 << endl
                 << "EDIT QUANTITY TO BE SOLD? (Y/N): ";
            cin >> cashierChoice3;

            switch (cashierChoice3)
            {
              case 'Y':
              case 'y':
                cout << endl
                     << "ENTER NEW QUANTITY OR ENTER (0) TO REMOVE FROM SHOPPING CART: ";
                cin >> qtySubtractedEdit;

                // SECONDARY QUANTITY CHECK/INPUT VALIDATION //
                while ((qtySubtractedEdit > thisArray [i] -> getQtyOnHand ()) || (qtySubtractedEdit < 0))
                {
                  cout << endl
                       << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS: " << thisArray [i] -> getQtyOnHand () << endl
                       << endl
                       << "Please enter valid quantity to sell: ";
                  cin >> qtySubtractedEdit;
                }

                shoppingCart [i] -> setQtyOnHand (qtySubtractedEdit);
                break;
              case 'N':
              case 'n':
                break;
              default:
                cin.clear ();
                cin.ignore (100, '\n');
                break;
            }
          }
        }
        break;
      case 3:
        cout << endl
             << "FINALIZE THIS SALE? (Y/N): ";
        cin >> cashierChoice2;

        cout << endl;

        if ((cashierChoice2 == 'Y') || (cashierChoice2 == 'y'))
        {
          for (int i = 0; i < bookType::getBookCount (); i++)
          {
            if (shoppingCart [i] -> getQtyOnHand () > 0)
              thisArray [i] -> setQtyOnHand (thisArray [i] -> getQtyOnHand () - shoppingCart [i] -> getQtyOnHand ());
          }

          cout << endl
               << "SALE COMPLETE!" << endl;
          system ("pause");
          return;
        }
        else {}
    }
  }
  while (cashierChoice != 4);
  {
    return;
  }
}

void paintReceipt (bookType **shoppingCart)
{
  int pos = 0;
  int len = 35;

  int qtyCOL = 5;
  int isbnCOL = 15;
  int titleCOL = 35;
  int priceCOL = 10;
  int totalCOL = 10;
  int spacerROW = (qtyCOL + isbnCOL + titleCOL + priceCOL + totalCOL);

  const double TAX_RATE = 0.06;

  system ("CLS");

  cout << fixed << showpoint << setprecision (2);

  cout << "Serendipity Book Sellers" << endl;
  cout << endl;
  cout << "DATE: " << currentTime << endl;
  cout << endl;
  cout << setw (qtyCOL) << left << "Qty" << setw (isbnCOL) << "ISBN" << setw (titleCOL) << "Title" << setw (priceCOL) << right << "Price" << setw (totalCOL) << "Total" << endl;
  cout << setw (spacerROW) << setfill ('_') << "_" << endl;
  cout << endl;

  double subtotalValueLine = 0;

  // *** LOOP FOR PROCESSING SUBTOTAL LINE AS PART OF ARRAY OF ITEMS *** //
  for (int i = 0; i < bookType::getBookCount (); i++)
  {
    double subtotalValueCol [10];

    if (shoppingCart [i] -> getQtyOnHand () > 0)
    {
      subtotalValueCol [i] = shoppingCart [i] -> getQtyOnHand () * shoppingCart [i] -> getRetail ();

      cout << setw (qtyCOL) << setfill (' ') << left << shoppingCart [i] -> getQtyOnHand () << setw (isbnCOL) << shoppingCart [i] -> getISBN () << setw (titleCOL) << shoppingCart [i] -> getTitle ().substr (pos, len) << right << setw (4) << "$" << setw (6) << shoppingCart [i] -> getRetail () << setw (3) << "$" << setw (7) << subtotalValueCol [i] << endl;

      subtotalValueLine += subtotalValueCol [i];
    }
  }

  // *** FORMATTED + ITEMIZED BILL LINE *** //
  //cout << setw (qtyCOL) << setfill (' ') << left << qtySubtracted << setw (isbnCOL) << thisArray [bookIndex].getISBN () << setw (titleCOL) << thisArray [bookIndex].getTitle ().substr (pos, len) << right << setw (4) << "$" << setw (6) << thisArray [bookIndex].getRetail () << setw (3) << "$" << setw (7) << subtotalValueLine << endl;

  double taxValue = subtotalValueLine * TAX_RATE;
  double totalValue = subtotalValueLine * (1 + TAX_RATE);

  cout << endl
       << endl
       << endl;

  cout << setw (30) << setfill (' ') << right << "Subtotal" << setw (38) << "$" << setw (7) << subtotalValueLine << endl;
  cout << setw (30) << right << "Tax" << setw (38) << "$" << setw (7) << taxValue << endl;
  cout << setw (30) << right << "Total" << setw (38) << "$" << setw (7) << totalValue << endl;
  cout << endl;
  cout << "Thank You for Shopping at Serendipity!" << endl;
  cout << endl;
}
