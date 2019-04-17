//
// Created by William Duong on 1/18/2019.
//
#ifndef SERENDIPITY_MAINMENU_H
#define SERENDIPITY_MAINMENU_H

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

const int DBSIZE = 20;

class bookType
{
private:
  string bookTitle;
  string isbn;
  string author;
  string publisher;
  string dateAdded;
  int qtyOnHand;
  double wholesale;
  double retail;

  static int bookCount;

public:
  // *** CONSTRUCTORS *** //
  bookType ();
  bookType (string, string, string, string, string, int, double, double);
  //bookType (const bookType*&);

  // *** SETTERS *** //
  void setTitle (string);
  void setISBN (string);
  void setAuthor (string);
  void setPublisher (string);
  void setDateAdded (string);
  void setQtyOnHand (int);
  void setWholesale (double);
  void setRetail (double);
  static void incBookCount ();
  static void decBookCount ();

  // *** GETTERS *** //
  string getTitle () const;
  string getISBN () const;
  string getAuthor () const;
  string getPublisher () const;
  string getDateAdded () const;
  int getQtyOnHand () const;
  double getWholesale () const;
  double getRetail () const;
  static int getBookCount ();

  // *** MISC *** //s
  void printBookInfo () const;
  bool isEqual (bookType*);
};

void mainMenu (bookType**);
void isGoodChoice (int, int, int);
void systemPause ();

#endif //SERENDIPITY_MAINMENU_H
