#include "nameMap.h"
using namespace std;

nameMap::nameMap(string filename)
{

    characters characterData;
    fstream infile(filename);//open the file
    string line;
    int position = 0;
    if (infile.good()) {
        while (1) {
            getline(infile, line, '\r');//get the next line of the file.
            characterData.getInfo(line);//fill in the character variables for characterData.
            line = characterData.formatInfo(line);//makes the line neater.
            characterData.info = line;

            if (infile.fail()) break;
            characterList.push_back(characterData);//push the character object onto the end of the list.
        }
        infile.close();
    }
}

void nameMap::displayName(int reference)
{
  cout << characterList[reference].name;
}

//displays all of the character information in a neat order.
void nameMap::displayInfo(int reference)
{
  cout << "Name:" << characterList[reference].name << "\nIdentity:" << characterList[reference].identity << "\nAlliance:" << characterList[reference].alliance << "\nEye Color:" << characterList[reference].eyes << "\nHair Color:" << characterList[reference].hair << "\nGender:" << characterList[reference].gender << "\nAlive or Dead:" << characterList[reference].alive << "\nNumber of Appearances in the Marvel Universe:" << characterList[reference].appearances << "\nDate of First Appearance:" << characterList[reference].firstAppearance << "\nYear of First Appearance:" << characterList[reference].firstYear;
}
