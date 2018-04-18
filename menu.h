#include <iostream>
#include <string>

using namespace std;

#ifndef MENU_H					// avoid repeated expansion
#define MENU_H


void splashScreen();
void subMenuMember();
void subMenuDomestic();
void subMenuInternational();
void mainMenu();
int validate(string input, string checkType);
#endif
