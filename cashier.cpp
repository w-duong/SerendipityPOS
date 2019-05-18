// ----------------------------------------------------------------------
// File name: cashier.cpp
// Project name: Serendipity
// ----------------------------------------------------------------------
// William Duong, wduong1@saddleback.edu
// CS1B, Ticket #23665
// Creation Date: 1/21/2019
// Last Modified: 5/16/2019
// ----------------------------------------------------------------------
// Purpose: Cashier module for outputting receipts.
// ----------------------------------------------------------------------
// Algorithm: Takes in input for various receipt elements, processes tax,
// subtotal, total and COUT receipt.
// ----------------------------------------------------------------------
// -			DATA DICTIONARY
// - CONSTANTS
// -
// - NAME		               DATA TYPE	                INITIAL VALUE
// - --------		           -------------	            -------------
//   TAX_RATE		           double		                  0.06
//
// - VARIABLES
// -
// - NAME		               DATA TYPE	                INITIAL VALUE
// - --------		           -------------	            -------------
// - thisArray             unorderedLinkedList *
// - it                    linkedListIterator
// - tempBookHolder        bookType *
// - cashierChoice	       int		                    0
// - cashierChoice2	       char
// - cashierChoice3	       char
// - buyChoice1		         char
// - buyChoice2		         char
// - resultCounter	       int
// - quantityChoice	       char
// - qtySubtracted	       int		                    0
// - qtySubtractedEdit	   int		                    0
// - subtotalValueLine	   double		                  0
// - subtotalValueCol   double
// - taxValue		           double                     0
// - totalValue		         double                     0
// - counter    	         int                        0
// - shoppingCart	         bookType
//
// ----------------------------------------------------------------------

#include "cashier.h"
#include "invmenu.h"

void cashierMenu (unorderedLinkedList <bookType>* thisArray)
{
  int cashierChoice = 0;
  char cashierChoice2;
  char cashierChoice3;
  int resultCounter = 0;
  int qtySubtracted = 0;

  linkedListIterator <bookType> it;
  bookType *tempBookHolder = nullptr;

  do
  {
    paintReceipt (thisArray);

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
        lookUpBook (thisArray);
        for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
        {
          if ((*it).getSearchFlag () == true)
          {
            tempBookHolder = new bookType ((*it));
            thisArray -> deleteNode ((*it));

            cout << endl
                 << tempBookHolder -> getTitle () << endl
                 << tempBookHolder -> getQtyOnHand () << endl
                 << tempBookHolder -> getRetail () << endl << endl
                 << "ENTER QUANTITY TO BE SOLD: ";
            cin >> qtySubtracted;

            // *** INITIAL QUANTITY CHECK/INPUT VALIDATION *** //
            while ((qtySubtracted > tempBookHolder -> getQtyOnHand ()) || (qtySubtracted < 0))
            {
              cout << endl
                   << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS: " << tempBookHolder -> getQtyOnHand () << endl << endl
                   << "Please enter valid quantity to sell: ";
              cin >> qtySubtracted;
            } // END VALIDATION WHILE-LOOP //

            // *** IF SHOPPING CART DOESN'T ALREADY HAVE ITEM *** //
            if (tempBookHolder -> getQtyInCart () == 0)
              tempBookHolder -> setQtyInCart (qtySubtracted);
            // *** IF SHOPPING CART HAS ITEM ALREADY INSIDE, ADD ADDITIONAL QUANTITY + VALIDATE TOTAL QUANTITY TO SELL *** //
            else if (tempBookHolder -> getQtyInCart () > 0)
            {
              // *** VERIFY TOTAL QUANTITY TO SELL IS VALID/DOESN'T EXCEED TOTAL QUANTITY-ON-HAND *** //
              while (qtySubtracted + tempBookHolder -> getQtyInCart () > tempBookHolder -> getQtyOnHand ())
              {
                cout << endl
                     << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS          : " << tempBookHolder -> getQtyOnHand () << endl
                     << "                  CURRENT QUANTITY IN SHOPPING CART IS : " << tempBookHolder -> getQtyInCart () << endl
                     << endl
                     << "Please enter valid quantity to sell: ";
                cin >> qtySubtracted;
              } // END VERIFICATION WHILE-LOOP //

              tempBookHolder -> setQtyInCart (qtySubtracted + tempBookHolder -> getQtyInCart ());
            } // END ITEM IN CART ELSE-IF STATEMENT //
          } // END ITEM FOUND IF STATEMENT //
        } // END ITERATOR LOOP FOR ITEM FOUND //
        thisArray -> insertLast (*tempBookHolder);
        break;

        // *** COMBINING ITEMS IN SHOPPING CART IF USING ARRAY *** //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // int tempArrayIndex [20];
        // char buyChoice1;
        // char buyChoice2;
        //
        // resultCounter = lookUpBook (thisArray, tempArrayIndex);
        //
        // for (int i = 0; i < resultCounter; i++)
        // {
        //   cout << ">>> BOOK LOOK UP <<<" << endl
        //        << endl
        //        << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
        //        << "View this book record? (Y/N): ";
        //   cin >> buyChoice1;
        //
        //   if (buyChoice1 == 'Y' || buyChoice1 == 'y')
        //   {
        //     thisArray [tempArrayIndex [i]] -> printBookInfo ();
        //     cout << endl
        //          << "Do you want to SELL this book? (Y/N): ";
        //     cin >> buyChoice2;
        //     if (buyChoice2 == 'Y' || buyChoice2 == 'y')
        //     {
        //       cout << endl
        //            << "ENTER QUANTITY TO BE SOLD: ";
        //       cin >> qtySubtracted;
        //
        //       // INITIAL QUANTITY CHECK/INPUT VALIDATION //
        //       while ((qtySubtracted > thisArray [tempArrayIndex [i]] -> getQtyOnHand ()) || (qtySubtracted < 0))
        //       {
        //         cout << endl
        //              << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS: " << thisArray [tempArrayIndex [i]] -> getQtyOnHand () << endl
        //              << endl
        //              << "Please enter valid quantity to sell: ";
        //         cin >> qtySubtracted;
        //       }
        //
        //       // CROSS REFERENCE SHOPPING CART WITH BOOK TO BE SOLD. ISBN MATCH = ITEM TO BE SOLD. UPDATE QTY TO SELL //
        //       for (int j = 0; j < bookType::getBookCount (); j++)
        //       {
        //         // IF SHOPPING CART DOESN'T ALREADY HAVE ITEM //
        //         if ((thisArray [tempArrayIndex [i]] -> isEqual (shoppingCart [j])) && (shoppingCart [tempArrayIndex [i]] -> getQtyOnHand () == 0))
        //           shoppingCart [j] -> setQtyOnHand (qtySubtracted);
        //         // IF SHOPPING CART HAS ITEM ALREADY INSIDE, ADD ADDITIONAL QUANTITY + VALIDATE TOTAL QUANTITY //
        //         else if ((thisArray [tempArrayIndex [i]] -> isEqual (shoppingCart [j])) && (shoppingCart [tempArrayIndex [i]] -> getQtyOnHand () > 0))
        //         {
        //           // VALIDATE TOTAL QUANTITY SOLD IS VALID/DOESN'T EXCEED TOTAL QUANTITY ON HAND //
        //           while (qtySubtracted + shoppingCart [j] -> getQtyOnHand () > thisArray [tempArrayIndex [i]] -> getQtyOnHand ())
        //           {
        //             cout << endl
        //                  << "INVALID QUANTITY! CURRENT CURRENT ON HAND QUANTITY IS   : " << thisArray [tempArrayIndex [i]] -> getQtyOnHand () << endl
        //                  << "                  CURRENT QUANTITY IN SHOPPING CART IS  : " << shoppingCart [j] -> getQtyOnHand () << endl
        //                  << endl
        //                  << "Please enter valid quantity to sell: ";
        //             cin >> qtySubtracted;
        //           }
        //
        //           shoppingCart [j] -> setQtyOnHand (qtySubtracted + shoppingCart [j] -> getQtyOnHand ());
        //         }
        //       }
        //       break;
        //     }
        //   }
        // }
        // break;
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      case 2:
        for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
        {
          if ((*it).getQtyInCart () > 0)
          {
            int qtySubtractedEdit = 0;

            cout << endl
                 << (*it).getTitle () << endl
                 << endl
                 << "EDIT QUANTITY TO BE SOLD? (Y/N): ";
            cin >> cashierChoice3;

            switch (cashierChoice3)
            {
              case 'Y':
              case 'y':
                tempBookHolder = new bookType ((*it));
                thisArray -> deleteNode ((*it));

                cout << endl
                     << "ENTER NEW QUANTITY OR ENTER (0) TO REMOVE FROM SHOPPING CART: ";
                cin >> qtySubtractedEdit;

                // SECONDARY QUANTITY CHECK/INPUT VALIDATION //
                while ((qtySubtractedEdit > tempBookHolder -> getQtyOnHand ()) || (qtySubtractedEdit < 0))
                {
                  cout << endl
                       << "INVALID QUANTITY! CURRENT ON HAND QUANTITY IS: " << tempBookHolder -> getQtyOnHand () << endl
                       << endl
                       << "Please enter valid quantity to sell: ";
                  cin >> qtySubtractedEdit;
                }

                tempBookHolder -> setQtyInCart (qtySubtractedEdit);
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
        thisArray -> insertLast (*tempBookHolder);
        break;
      case 3:
        cout << endl
             << "FINALIZE THIS SALE? (Y/N): ";
        cin >> cashierChoice2;

        cout << endl;

        if ((cashierChoice2 == 'Y') || (cashierChoice2 == 'y'))
        {
          for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
          {
            if ((*it).getQtyInCart () > 0)
            {
              tempBookHolder = new bookType ((*it));
              thisArray -> deleteNode ((*it));
              tempBookHolder -> setQtyOnHand (tempBookHolder -> getQtyOnHand () - tempBookHolder -> getQtyInCart ());
              tempBookHolder -> setQtyInCart (0);
              thisArray -> insertLast (*tempBookHolder);
            }
          }
          cout << endl
               << "SALE COMPLETE!" << endl;
          system ("pause");
          return;
        }
        else {}
        tempBookHolder = nullptr;
    }
  }
  while (cashierChoice != 4);
  {
    for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
    {
      bookType *temp = new bookType ((*it));
      thisArray -> deleteNode ((*it));
      temp -> setQtyInCart (0);
      thisArray -> insertLast (*temp);
      delete temp;
    }
    return;
  }
}

void paintReceipt (unorderedLinkedList <bookType>* thisArray)
{
  int pos = 0;
  int len = 35;
  int qtyCOL = 5;
  int isbnCOL = 15;
  int titleCOL = 35;
  int priceCOL = 10;
  int totalCOL = 10;
  int spacerROW = (qtyCOL + isbnCOL + titleCOL + priceCOL + totalCOL);
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  linkedListIterator <bookType> it;

  const double TAX_RATE = 0.06;

  system ("CLS");

  cout << fixed << showpoint << setprecision (2);

  cout << "Serendipity Book Sellers" << endl;
  cout << endl;
  cout << "DATE/TIME: " << dateTime << endl;
  cout << endl;
  cout << setw (qtyCOL) << left << "Qty" << setw (isbnCOL) << "ISBN" << setw (titleCOL) << "Title" << setw (priceCOL) << right << "Price" << setw (totalCOL) << "Total" << endl;
  cout << setw (spacerROW) << setfill ('_') << "_" << endl;
  cout << endl;

  double subtotalValueLine = 0;

  // *** LOOP FOR PROCESSING SUBTOTAL LINE AS PART OF ARRAY OF ITEMS *** //
  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    double subtotalValueCol;

    if ((*it).getQtyInCart () > 0)
    {
      subtotalValueCol = (*it).getQtyInCart () * (*it).getRetail ();

      cout << setw (qtyCOL) << setfill (' ') << left << (*it).getQtyInCart () << setw (isbnCOL) << (*it).getISBN () << setw (titleCOL) << (*it).getTitle ().substr (pos, len) << right << setw (4) << "$" << setw (6) << (*it).getRetail () << setw (3) << "$" << setw (7) << subtotalValueCol << endl;

      subtotalValueLine += subtotalValueCol;
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
