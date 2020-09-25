#ifndef NAMEMAP_H
#define NAMEMAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "characters.h"

using namespace std;

class nameMap
{
  public:
    nameMap(string filename);//constructor that fills characterList with the characters.
    void displayName(int reference);//displays the name of the character.
    void displayInfo(int reference);//displays the info of the character.

  private:
    vector <characters> characterList;//vector to store the characters.
};

#endif
