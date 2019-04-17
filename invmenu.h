//
// Created by William Duong on 1/18/2019.
//
#ifndef SERENDIPITY_INVMENU_H
#define SERENDIPITY_INVMENU_H

#include "mainmenu.h"

string toLower (string variableStr);
void inventoryMenu (bookType**);
int lookUpBook (bookType**, int tempArrayIndex []);
void addBook (bookType**);
void bookEdit (bookType**, int tempArrayIndexVal);
void bookDelete (bookType**, int tempArrayIndexVal);

#endif //SERENDIPITY_INVMENU_H
