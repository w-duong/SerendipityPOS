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
#include <ctime>
#include <chrono>
#include "bookType.h"
#include "linkedListType.h"
#include "orderedLinkList.h"
#include "unorderedLinkList.h"

using namespace std;

const int DBSIZE = 20;

void mainMenu (unorderedLinkedList <bookType>*);
void isGoodChoice (int, int, int);
string getDateStr ();
string getTimeStr ();
void writeDataBase (unorderedLinkedList <bookType>*);

#endif //SERENDIPITY_MAINMENU_H
