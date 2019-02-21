//
// Created by William Duong on 1/18/2019.
//
#ifndef SERENDIPITY_INVMENU_H
#define SERENDIPITY_INVMENU_H

#include "mainmenu.h"

string toLower (string variableStr);
void inventoryMenu (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount);
int lookUpBook (const string bookTitle [], const string isbn [], const string author [], const string publisher [], const string dateAdded [], const int qtyOnHand [], const double wholesale [], const double retail [], const int bookCount, int tempArrayIndex []);
void addBook (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount);
void bookEdit (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int bookCount, int tempArrayIndexVal);
void bookDelete (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount, int tempArrayIndexVal);

//void printBookDB (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount);

#endif //SERENDIPITY_INVMENU_H
