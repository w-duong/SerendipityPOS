//
// Created by William Duong on 1/18/2019.
//
#ifndef SERENDIPITY_INVMENU_H
#define SERENDIPITY_INVMENU_H

#include "mainmenu.h"

string toLower (string variableStr);
void inventoryMenu (unorderedLinkedList <bookType>*);
void lookUpBook (unorderedLinkedList <bookType>*);
void addBook (unorderedLinkedList <bookType>*);
void bookEdit (unorderedLinkedList <bookType>*);
void bookDelete (unorderedLinkedList <bookType>*);

#endif //SERENDIPITY_INVMENU_H
