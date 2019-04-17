//
// Created by William Duong on 1/18/2019.
//
#include "invmenu.h"
#include "mainmenu.h"

void inventoryMenu (bookType **thisArray)
{
  int userChoice = 0;
  int resultCounter = 0;

  do
  {
    system ("clear");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
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
        int tempArrayIndex [20];
        char userChoice1;

        resultCounter = lookUpBook (thisArray, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
               << "View this book record? (Y/N): ";
          cin >> userChoice1;

          if (userChoice1 == 'Y' || userChoice1 == 'y')
          {
            thisArray [tempArrayIndex [i]] -> printBookInfo ();
            break;
          }
        }
        break;
      case 2:
        addBook (thisArray);
        break;
      case 3:
        char editChoice1;
        char editChoice2;

        resultCounter = lookUpBook (thisArray, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
               << "View this book record? (Y/N): ";
          cin >> editChoice1;

          if (editChoice1 == 'Y' || editChoice1 == 'y')
          {
            thisArray [tempArrayIndex [i]] -> printBookInfo ();
            cout << endl
                 << "Do you want to EDIT this book? (Y/N): ";
            cin >> editChoice2;
            if (editChoice2 == 'Y' || editChoice2 == 'y')
            {
              bookEdit (thisArray, tempArrayIndex [i]);
            }
          }
        }
        break;
      case 4:
        char deleteChoice1;
        char deleteChoice2;

        resultCounter = lookUpBook (thisArray, tempArrayIndex);

        for (int i = 0; i < resultCounter; i++)
        {
          cout << ">>> BOOK LOOK UP <<<" << endl
               << endl
               << "RESULT:> " << thisArray [tempArrayIndex [i]] -> getTitle () << endl
               << "View this book record? (Y/N): ";
          cin >> deleteChoice1;

          if (deleteChoice1 == 'Y' || deleteChoice1 == 'y')
          {
            thisArray [tempArrayIndex [i]] -> printBookInfo ();
            cout << endl
                 << "Do you want to DELETE this book? (Y/N): ";
            cin >> deleteChoice2;
            if (deleteChoice2 == 'Y' || deleteChoice2 == 'y')
            {
              bookDelete (thisArray, tempArrayIndex [i]);
              cout << endl
                   << "BOOK DELETED" << endl
                   << endl;
              systemPause ();
            }
           }
         }
         break;
        }
  }
  while (userChoice != 5);
  {
    return;
  }
}

int lookUpBook (bookType **thisArray, int tempArrayIndex [])
{
  string searchStr;
  string tempArray [20];
  int counterNegative = 0;
  int resultCounter = 0;

  cout << ">>> BOOK LOOK UP <<<" << endl
       << endl
       << "Search:> " << endl;
  cin.ignore ();
  getline (cin, searchStr);

  string temp1 = toLower (searchStr);

  // //VISUAL CHECK:
  // cout << "SEARCH STRING...: " << temp1 << endl;
  //
  // systemPause ();

  for (int i = 0; i < bookType::getBookCount (); i++)
  {
    string temp2 = toLower (thisArray [i] -> getTitle ());
    if ((temp2.find (temp1) != string::npos) || (thisArray [i] -> getISBN ().find (searchStr) != string::npos))
    {
      tempArray [resultCounter] = thisArray [i] -> getTitle ();
      tempArrayIndex [resultCounter] = i;
      resultCounter++;
    }
    if ((temp2.find (temp1) == string::npos) && (thisArray [i] -> getISBN ().find (searchStr) == string::npos))
    {
      counterNegative++;
    }
  }

  if (counterNegative == bookType::getBookCount ())
  {
    cout << "ITEM NOT FOUND!" << endl
         << endl;
    systemPause ();
  }
  return resultCounter;
}

void addBook (bookType **thisArray)
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

  if (bookType::getBookCount () >= 20)
  {
    cout << endl
         << "*** ERROR: BOOK DATABASE FULL. CURRENT BOOK COUNT: " << bookType::getBookCount () << " ***" << endl
         << endl
         << "Please delete a book to add more items to database." << endl;
    systemPause ();
    return;
  }

  do
  {
    system ("clear");

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                  DATABASE SIZE: " << setw (8) << left << DBSIZE << "CURRENT BOOK COUNT: " << setw (8) << bookType::getBookCount () << "             *" << endl
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
        // thisArray [bookType::getBookCount ()].setTitle (tempBookTitle);
        // thisArray [bookType::getBookCount ()].setISBN (tempISBN);
        // thisArray [bookType::getBookCount ()].setAuthor (tempAuthor);
        // thisArray [bookType::getBookCount ()].setPublisher (tempPublisher);
        // thisArray [bookType::getBookCount ()].setDateAdded (tempDateAdded);
        // thisArray [bookType::getBookCount ()].setQtyOnHand (tempQtyOnHand);
        // thisArray [bookType::getBookCount ()].setWholesale (tempWholesale);
        // thisArray [bookType::getBookCount ()].setRetail (tempRetail);
        // thisArray [bookType::getBookCount ()].incBookCount ();
        thisArray [bookType::getBookCount ()] = new bookType (tempBookTitle, tempISBN, tempAuthor, tempPublisher, tempDateAdded, tempQtyOnHand, tempWholesale, tempRetail);
        thisArray [bookType::getBookCount ()] -> incBookCount ();
        break;
    }

  }
  while ((userChoice != 0) && (bookType::getBookCount () != 20));
  {
    return;
  }
}

void bookEdit (bookType **thisArray, int tempArrayIndexVal)
{
  int userChoice = 0;
  string editTemp1;
  int editTemp2 = 0;
  double editTemp3 = 0;

  do
  {
    system ("clear");

    int pos = 0;
    int len = 35;

    cout << "************************************************************************************" << endl
         << "*                             SERENDIPITY BOOKSELLERS                              *" << endl
         << "*                                    MAIN MENU                                     *" << endl
         << "*                                                                                  *" << endl
         << "*                 DATABASE SIZE: " << setw (8) << left << DBSIZE << "CURRENT BOOK COUNT: " << setw (8) << bookType::getBookCount () << "             *" << endl
         << "*                                                                                  *" << endl
         << "*                                                   --PENDING VALUES--             *" << endl
         << "*                                                                                  *" << endl
         << "*  <1> Enter Book Title              >  " << setw (43) << left << thisArray [tempArrayIndexVal] -> getTitle ().substr (pos, len) << "*" << endl
         << "*  <2> Enter ISBN                    >  " << setw (43) << thisArray [tempArrayIndexVal] -> getISBN () << "*" << endl
         << "*  <3> Enter Author                  >  " << setw (43) << thisArray [tempArrayIndexVal] -> getAuthor () << "*" << endl
         << "*  <4> Enter Publisher               >  " << setw (43) << thisArray [tempArrayIndexVal] -> getPublisher () << "*" << endl
         << "*  <5> Enter Date Added (MM/DD/YYYY) >  " << setw (43) << thisArray [tempArrayIndexVal] -> getDateAdded () << "*" << endl
         << "*  <6> Enter Quantity on Hand        >  " << setw (43) << thisArray [tempArrayIndexVal] -> getQtyOnHand () << "*" << endl
         << "*  <7> Enter Wholesale Price         >  " << setw (43) << thisArray [tempArrayIndexVal] -> getWholesale () << "*" << endl
         << "*  <8> Enter Retail Price            >  " << setw (43) << thisArray [tempArrayIndexVal] -> getRetail () << "*" << endl
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
        thisArray [tempArrayIndexVal] -> setTitle (editTemp1);
        break;
      case 2:
        cout << "Enter ISBN : > ";
        cin.ignore ();
        getline (cin, editTemp1);
        thisArray [tempArrayIndexVal] -> setISBN (editTemp1);
        break;
      case 3:
        cout << "Enter Author: > ";
        cin.ignore ();
        getline (cin, editTemp1);
        thisArray [tempArrayIndexVal] -> setAuthor (editTemp1);
        break;
      case 4:
        cout << "Enter Publisher: > ";
        cin.ignore ();
        getline (cin, editTemp1);
        thisArray [tempArrayIndexVal] -> setPublisher (editTemp1);
        break;
      case 5:
        cout << "Enter Date Added: > ";
        cin.ignore ();
        getline (cin, editTemp1);
        thisArray [tempArrayIndexVal] -> setDateAdded (editTemp1);
        break;
      case 6:
        cout << "Enter quantity-on-hand: > ";
        cin >> editTemp2;
        thisArray [tempArrayIndexVal] -> setQtyOnHand (editTemp2);
        break;
      case 7:
        cout << "Enter wholesale price: > ";
        cin >> editTemp3;
        thisArray [tempArrayIndexVal] -> setWholesale (editTemp3);
        break;
      case 8:
        cout << "Enter retail price: > ";
        cin >> editTemp3;
        thisArray [tempArrayIndexVal] -> setRetail (editTemp3);
        break;
    }
  }
  while (userChoice != 9);
  {
    return;
  }
}

void bookDelete (bookType **thisArray, int tempArrayIndexVal)
{
  for (int i = tempArrayIndexVal; i < (bookType::getBookCount () - 1); i++)
  {
    thisArray [tempArrayIndexVal] = thisArray [tempArrayIndexVal + 1];
  }

  //delete thisArray [bookType::getBookCount ()]; // DEALLOCATES MEMORY FOR VERY LAST POINTER IN BOOK ARRAY (???) //
  bookType::decBookCount ();
  return;
}

string toLower (string variableStr)
{
  for (int i = 0; i < variableStr.length (); i++)
  {
    if ((variableStr [i] >= 'A') && (variableStr [i] <= 'Z'))
    {
      variableStr [i] = variableStr [i] + 32;
    }
  }

  return variableStr;
}
