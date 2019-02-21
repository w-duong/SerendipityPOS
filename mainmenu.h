//
// Created by admin on 1/18/2019.
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

void mainMenu (string bookTitle [], string isbn [], string author [], string publisher [], string dateAdded [], int qtyOnHand [], double wholesale [], double retail [], int& bookCount);

#endif //SERENDIPITY_MAINMENU_H
