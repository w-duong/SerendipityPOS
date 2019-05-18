//
// Created by William Duong on 5/17/2019.
//
#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

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
  int sortCode;
  bool searchFlag;
  int qtyInCart;

  static int bookCount;

public:
  // *** CONSTRUCTORS *** //
  bookType ();
  bookType (string, string, string, string, string, int, double, double, int = 0);
  bookType (bookType*);

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
  void setSortCode (int);
  void setSearchFlag (bool);
  void setQtyInCart (int);

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
  int getSortCode ();
  bool getSearchFlag ();
  int getQtyInCart ();

  // *** MISC *** //s
  void printBookInfo () const;
  bool isEqual (bookType*);
  bool operator == (const bookType&) const;
  bool operator != (const bookType&) const;
  bool operator >= (const bookType&) const;
  friend ostream& operator << (ostream&, const bookType&);
};

#endif //BOOKTYPE_H
