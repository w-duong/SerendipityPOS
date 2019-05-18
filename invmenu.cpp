// ----------------------------------------------------------------------
// File name: invmenu.cpp
// Project name: Serendipity
// ----------------------------------------------------------------------
// William Duong, wduong1@saddleback.edu
// CS1B
// Creation Date 1/22/2019
// Last Modified 5/15/2019
// ----------------------------------------------------------------------
// Purpose: Displays inventory menu.
// ----------------------------------------------------------------------
// Algorithm: Void display function for inventory menu and various related
// functions of the inventory module.
// ----------------------------------------------------------------------
// -		                      	DATA DICTIONARY
// - CONSTANTS
// -
// - NAME		                    DATA TYPE		             INITIAL VALUE
// - --------		                -------------		         -------------
//
// - VARIABLES
// -
// - NAME		                    DATA TYPE		             INITIAL VALUE
// - --------		                -------------		         -------------
// - thisArray                  unorderedLinkedList *
// - it                         linkedListIterator
// - tempBookHolder             bookType *
// - dateTime                   string
// - userChoice		              int			                 0
// - editChoice		              char
// - deleteChoice	              char
// - searchStr		              string
// - counterNegative	          int			                 0
// - editChoice		              int			                 0
// - tempArrayIndexVal	        int			                 0
// - deleteChoice	              int			                 0
// - pos		                    int			                 0
// - len		                    int			                 30
// - tempBookTitle	            string			             EMPTY
// - tempISBN		                string			             EMPTY
// - tempAuthor		              string			             EMPTY
// - tempPublisher	            string			             EMPTY
// - tempDateAdded	            string			             EMPTY
// - tempQtyOnHand	            int			                 0
// - tempWholesale	            double			             0
// - tempRetail		              double			             0
// - variableStr	              string
//
// ----------------------------------------------------------------------

#include "invmenu.h"

void inventoryMenu (unorderedLinkedList <bookType>* thisArray)
{
  int userChoice = 0;
  int resultCounter = 0;
  string dateTime = getDateStr () + " @ " + getTimeStr ();

  do
  {
    system ("CLS");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                 INVENTORY MENU                                   *" << endl
         << "*                                                                                  *" << endl
         << "*                              " << dateTime << "                              *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Look Up a Book                                                              *" << endl
         << "*  <2> Add a Book                                                                  *" << endl
         << "*  <3> Edit a Book's Record                                                        *" << endl
         << "*  <4> Delete a Book                                                               *" << endl
         << "*  <5> Return to the Main Menu                                                     *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                            Enter Your Choice (1-5): ";

    cin >> userChoice;

    isGoodChoice (userChoice, 1, 5);

    switch (userChoice)
    {
      case 1:
        lookUpBook (thisArray);
        // *** IF RETURNING AN ARRAY OF RESULTS (from array database, i.e. NOT linked list) *** //
        //////////////////////////////////////////////////////////////////////////////////////////
        // int tempArrayIndex [20];
        // char userChoice1;
        //
        // resultCounter = lookUpBook (thisArray, tempArrayIndex);
        //
        // for (int i = 0; i < resultCounter; i++)
        // {
        //   cout << ">>> BOOK LOOK UP <<<" << endl
        //        << endl
        //        << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
        //        << "View this book record? (Y/N): ";
        //   cin >> userChoice1;
        //
        //   if (userChoice1 == 'Y' || userChoice1 == 'y')
        //   {
        //     thisArray [tempArrayIndex [i]] -> printBookInfo ();
        //     break;
        //   }
        // }
        /////////////////////////////////////////////////////////////////////////////////////////
        break;
      case 2:
        addBook (thisArray);
        break;
      case 3:
        lookUpBook (thisArray);
        bookEdit (thisArray);
        break;
      case 4:
        lookUpBook (thisArray);
        bookDelete (thisArray);
        break;
    }
  }
  while (userChoice != 5);
  {
    return;
  }
}

void lookUpBook (unorderedLinkedList <bookType>* thisArray)
{
  linkedListIterator <bookType> it;
  bookType *tempBookHolder = nullptr;

  // *** RESET SEARCH FLAG FOR EVERY NEW SEARCH *** //
  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    if ((*it).getSearchFlag () == true)
    {
      tempBookHolder = new bookType ((*it));
    }
  }

  if (tempBookHolder != nullptr)
  {
    thisArray -> deleteNode (*tempBookHolder);
    tempBookHolder -> setSearchFlag (false);
    thisArray -> insertLast (*tempBookHolder);
    tempBookHolder = nullptr;
  }

  string searchStr;
  int counterNegative = 0;

  cout << ">>> BOOK LOOK UP <<<" << endl
       << endl
       << "Search:> ";
  cin.ignore ();
  getline (cin, searchStr);

  cout << endl << endl;

  string temp1 = toLower (searchStr);

  for (it = thisArray -> begin(); it != thisArray -> end(); ++it)
  {
    string temp2 = toLower ((*it).getTitle ());
    char lookupChoice;

    // *** IF FOUND *** //
    if ((temp2.find (temp1) != string::npos) || ((*it).getISBN ().find (searchStr) != string::npos))
    {
      cout << "RESULT => " << endl << endl
           << (*it) << endl
           << "Select this book? (Y/N): ";
      cin >> lookupChoice;

      // *** IF POSITIVE, SET SEARCH FLAG *** //
      if (lookupChoice == 'Y' || lookupChoice == 'y')
      {
        (*it).printBookInfo ();
        tempBookHolder = new bookType ((*it));
        break;
      }
    }

    // *** IF NOT FOUND *** //
    if ((temp2.find (temp1) == string::npos) && ((*it).getISBN ().find (searchStr) == string::npos))
    {
      counterNegative++;
    }
  }

  if (counterNegative == thisArray -> length ())
  {
    cout << "ITEM NOT FOUND!" << endl
         << endl;
    system ("pause");
  }

  if (tempBookHolder != nullptr)
  {
    thisArray -> deleteNode (*tempBookHolder);
    tempBookHolder -> setSearchFlag (true);
    thisArray -> insertLast (*tempBookHolder);
  }

  delete tempBookHolder;

  // *** IF RETURNING AN ARRAY OF RESULTS (from array database, i.e. NOT linked list) *** //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // for (int i = 0; i < bookType::getBookCount (); i++)
  // {
    // string temp2 = toLower (thisArray [i] -> getTitle ());
    // if ((temp2.find (temp1) != string::npos) || (thisArray [i] -> getISBN ().find (searchStr) != string::npos))
    // {
    //   tempArray [resultCounter] = thisArray [i] -> getTitle ();
    //   tempArrayIndex [resultCounter] = i;
    //   resultCounter++;
    // }
    // if ((temp2.find (temp1) == string::npos) && (thisArray [i] -> getISBN ().find (searchStr) == string::npos))
    // {
    //   counterNegative++;
    // }
  // }
  //
  // if (counterNegative == bookType::getBookCount ())
  // {
  //   cout << "ITEM NOT FOUND!" << endl
  //        << endl;
  //   system ("pause");
  // }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void addBook (unorderedLinkedList <bookType>* thisArray)
{
  int userChoice = -1;
  int pos = 0;
  int len = 35;

  string tempBookTitle = "EMPTY";
  string tempISBN = "EMPTY";
  string tempAuthor = "EMPTY";
  string tempPublisher = "EMPTY";
  string tempDateAdded = "EMPTY";
  int tempQtyOnHand = 0;
  double tempWholesale = 0;
  double tempRetail = 0;

  // *** IF RESTRICTED DATABASE SIZE *** //
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // if (bookType::getBookCount () >= 20)
  // {
  //   cout << endl
  //        << "*** ERROR: BOOK DATABASE FULL. CURRENT BOOK COUNT: " << bookType::getBookCount () << " ***" << endl
  //        << endl
  //        << "Please delete a book to add more items to database." << endl;
  //   system ("pause");
  //   return;
  // }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  do
  {
    system ("CLS");

    string dateTime = getDateStr () + " @ " + getTimeStr ();

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                     ADD MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                              " << dateTime << "                              *" << endl
         << "*                                                                                  *" << endl
         << "*                           CURRENT BOOK COUNT: " << setw (8) << thisArray -> length () << "                           *" << endl
         << "*                                                                                  *" << endl
         << "*                                                   --PENDING VALUES--             *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Enter Book Title              >  " << setw (43) << left << tempBookTitle.substr (pos, len) << "*" << endl
         << "*  <2> Enter ISBN                    >  " << setw (43) << tempISBN << "*" << endl
         << "*  <3> Enter Author                  >  " << setw (43) << tempAuthor << "*" << endl
         << "*  <4> Enter Publisher               >  " << setw (43) << tempPublisher << "*" << endl
         << "*  <5> Enter Date Added (MM/DD/YYYY) >  " << setw (43) << tempDateAdded << "*" << endl
         << "*  <6> Enter Quantity on Hand        >  " << setw (43) << tempQtyOnHand << "*" << endl
         << "*  <7> Enter Wholesale Price         >  " << setw (43) << tempWholesale << "*" << endl
         << "*  <8> Enter Retail Price            >  " << setw (43) << tempRetail << "*" << endl
         << "*  <9> Save Book to Database                                                       *" << endl
         << "*  <0> Return to Inventory Menu                                                    *" << endl
         << "*                                                                                  *" << endl
         << "************************************************************************************" << endl
         << "                                  CHOICE (0-9): ";

    cin >> userChoice;

    isGoodChoice (userChoice, 0, 9);

    switch (userChoice)
    {
      case 1:
        cout << "Enter Book Title: ";
        cin.ignore ();
        getline (cin, tempBookTitle);
        break;
      case 2:
        cout << "Enter ISBN: ";
        cin.ignore ();
        getline (cin, tempISBN, '\n');
        break;
      case 3:
        cout << "Enter Author: ";
        cin.ignore ();
        getline (cin, tempAuthor, '\n');
        break;
      case 4:
        cout << "Enter Publisher: ";
        cin.ignore ();
        getline (cin, tempPublisher, '\n');
        break;
      case 5:
        cout << "Enter Date Added (MM/DD/YYYY): ";
        cin.ignore ();
        getline (cin, tempDateAdded, '\n');
        break;
      case 6:
        cout << "Enter Quantity-on-Hand: ";
        cin >> tempQtyOnHand;
        break;
      case 7:
        cout << "Enter Wholesale Price: ";
        cin >> tempWholesale;
        break;
      case 8:
        cout << "Enter Retail Price: ";
        cin >> tempRetail;
        break;
      case 9:
        bookType tempBookHolder (tempBookTitle, tempISBN, tempAuthor, tempPublisher, tempDateAdded, tempQtyOnHand, tempWholesale, tempRetail);
        thisArray -> insertLast (tempBookHolder);
        break;
    }

  }
  while (userChoice != 0);
  {
    return;
  }

  // *** IF RESTRICTED DATABASE SIZE *** //
  /////////////////////////////////////////////////////////////////////////////
  // while ((userChoice != 0) && (bookType::getBookCount () != 20));
  // {
  //   return;
  // }
  /////////////////////////////////////////////////////////////////////////////
}

void bookEdit (unorderedLinkedList <bookType>* thisArray)
{
  linkedListIterator <bookType> it;
  bookType *tempBookHolder;

  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
  {
    if ((*it).getSearchFlag () == true)
    {
      tempBookHolder = new bookType ((*it));

      thisArray -> deleteNode ((*it));

      int userChoice = 0;
      string editTemp1;
      int editTemp2 = 0;
      double editTemp3 = 0;

      do
      {
        system ("CLS");

        int pos = 0;
        int len = 35;
        string dateTime = getDateStr () + " @ " + getTimeStr ();

        cout << "************************************************************************************" << endl
             << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
             << "*                                    EDIT MENU                                     *" << endl
             << "*                                                                                  *" << endl
             << "*                              " << dateTime << "                              *" << endl
             << "*                                                                                  *" << endl
             << "*                           CURRENT BOOK COUNT: " << setw (8) << thisArray -> length () << "                           *" << endl
             << "*                                                                                  *" << endl
             << "*                                                   --PENDING VALUES--             *" << endl
             << "*                                                                                  *" << endl
             << "*  <1> Enter Book Title              >  " << setw (43) << left << tempBookHolder -> getTitle ().substr (pos, len) << "*" << endl
             << "*  <2> Enter ISBN                    >  " << setw (43) << tempBookHolder -> getISBN () << "*" << endl
             << "*  <3> Enter Author                  >  " << setw (43) << tempBookHolder -> getAuthor () << "*" << endl
             << "*  <4> Enter Publisher               >  " << setw (43) << tempBookHolder -> getPublisher () << "*" << endl
             << "*  <5> Enter Date Added (MM/DD/YYYY) >  " << setw (43) << tempBookHolder -> getDateAdded () << "*" << endl
             << "*  <6> Enter Quantity on Hand        >  " << setw (43) << tempBookHolder -> getQtyOnHand () << "*" << endl
             << "*  <7> Enter Wholesale Price         >  " << setw (43) << tempBookHolder -> getWholesale () << "*" << endl
             << "*  <8> Enter Retail Price            >  " << setw (43) << tempBookHolder -> getRetail () << "*" << endl
             << "*  <9> Return to Previous Menu                                                     *" << endl
             << "*                                                                                  *" << endl
             << "************************************************************************************" << endl
             << "                                  CHOICE (1-9): ";
        cin >> userChoice;

        isGoodChoice (userChoice, 1, 9);

        switch (userChoice)
        {
          case 1:
            cout << "Enter Book Title: > ";
            cin.ignore ();
            getline (cin, editTemp1);
            tempBookHolder -> setTitle (editTemp1);
            break;
          case 2:
            cout << "Enter ISBN : > ";
            cin.ignore ();
            getline (cin, editTemp1);
            tempBookHolder -> setISBN (editTemp1);
            break;
          case 3:
            cout << "Enter Author: > ";
            cin.ignore ();
            getline (cin, editTemp1);
            tempBookHolder -> setAuthor (editTemp1);
            break;
          case 4:
            cout << "Enter Publisher: > ";
            cin.ignore ();
            getline (cin, editTemp1);
            tempBookHolder -> setPublisher (editTemp1);
            break;
          case 5:
            cout << "Enter Date Added: > ";
            cin.ignore ();
            getline (cin, editTemp1);
            tempBookHolder -> setDateAdded (editTemp1);
            break;
          case 6:
            cout << "Enter quantity-on-hand: > ";
            cin >> editTemp2;
            tempBookHolder -> setQtyOnHand (editTemp2);
            break;
          case 7:
            cout << "Enter wholesale price: > ";
            cin >> editTemp3;
            tempBookHolder -> setWholesale (editTemp3);
            break;
          case 8:
            cout << "Enter retail price: > ";
            cin >> editTemp3;
            tempBookHolder -> setRetail (editTemp3);
            break;
        }
      }
      while (userChoice != 9);
      {
        tempBookHolder -> setSearchFlag (false);
        thisArray -> insertLast (*tempBookHolder);
        delete tempBookHolder;
        return;
      } // END OF DO-WHILE LOOP //
    } // END OF IF SEARCH FLAG TRUE STATEMENT //
  } // END OF ITERATING THROUGH LINKED LIST FOR LOOP //
} // END OF BOOK EDIT FUNCTION //

void bookDelete (unorderedLinkedList <bookType>* thisArray)
{
  linkedListIterator <bookType> it;

  for (it = thisArray -> begin (); it != thisArray -> end (); ++it)
    if ((*it).getSearchFlag () == true)
      thisArray -> deleteNode ((*it));

  return;
}

string toLower (string variableStr)
{
  for (int i = 0; i < variableStr.length (); i++)
    if ((variableStr [i] >= 'A') && (variableStr [i] <= 'Z'))
      variableStr [i] = variableStr [i] + 32;

  return variableStr;
}
