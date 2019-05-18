//
//Created by William Duong on 1/21/2019.
//
#ifndef SERENDIPITY_REPORTS_H
#define SERENDIPITY_REPORTS_H

#include "mainmenu.h"

void reportsMenu (unorderedLinkedList <bookType>*);
void repListing (unorderedLinkedList <bookType>*);
void repWholesale (unorderedLinkedList <bookType>*);
void repRetail (unorderedLinkedList <bookType>*);
void repQty (unorderedLinkedList <bookType>*);
void repCost (unorderedLinkedList <bookType>*);
void repAge (unorderedLinkedList <bookType>*);

orderedLinkedList <bookType> listConverter (unorderedLinkedList <bookType>*, int);

#endif //SERENDIPITY_REPORTS_H
