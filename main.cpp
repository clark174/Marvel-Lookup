//Written by Jimmy Clark (clark1@kenyon.edu)
//Date: 9-25-2020
//Description: This program creates two indexes of Marvel characters and allows the user to search for information about any character either by entering a name or year.
#include "nameIndex.h"
#include "nameMap.h"
#include "yearIndex.h"
using namespace std;

string lowercase(string str);
//Precondition: str is the string that the user entered to search the index for matches.
//Postcondition: returns the string in all lowercase letters.


int main ()
{
  nameMap test1("Marvel.csv");
  nameIndex index1("Marvel.csv");
  yearIndex index2("Marvel.csv");

  char programChoice, indexChoice, inputChoice;

  cout << "Welcome to the Marvel Lookup Program!  To use this program, enter the name of a Marvel character or a year when prompted and the program will display information about that character or if you enter a year, it will list all the characters that were introduced in that year." << endl;

  //This loop encompasses the main part of the program.
  do
  {
    string character = "";

    cout << "Would you like to enter the name of a character or a year? (Enter N for name, Y for year): ";

    cin >> inputChoice;

    //if inputChoice isn't valid, the program forces the user to input it again.
    while(inputChoice != 'N' && inputChoice != 'n' && inputChoice != 'Y' && inputChoice != 'y')
    {
      cout << "\nInvalid input.  Please try again." << endl << "Enter N for name, Y for year: ";
      cin >> inputChoice;
    }

    //The name choice.
    if(inputChoice == 'N' || inputChoice == 'n')
    {
      cout << "\nEnter the name of a Marvel character to look up: ";

      cin.ignore();

      getline(cin, character);//get character name.

      character = lowercase(character);

      vector <int> charChoices = index1.indexSearch(character);//creates a list made up of references to matching characters.

      if (charChoices.size()==0)
      {
        cout << "\nNo matches found. Please try again." << endl;
      }
      else
      do //loop for when the user wants to keep searching with the name they inputted.
      {
        //display the matching characters.
        for (int i = 0; i<charChoices.size(); i++)
        {
         cout << i+1 << ". ";
         test1.displayName(charChoices[i]);
         cout << endl;
        }

        int charOption;

        cout << "Enter the number of the character that you would like to look up: ";

        cin >> charOption;

        cout << "\n";

        //display the info of the character the user chose.
        test1.displayInfo(charChoices[charOption-1]);

        cout << "\nWould you like to look up another character with the name " << character << "? (Enter Y to look up a different index choice, enter any other character to continue the program): ";

        cin >> indexChoice;

        cout << "\n";

      } while (indexChoice == 'Y' || indexChoice == 'y');

    }
    //the year choice.  The procedure is nearly identical to the name choice.
    else
    {
      cout << "\nEnter the year of a Marvel character to look up: ";

      cin.ignore();

      getline(cin, character);

      character = lowercase(character);

      vector <int> charChoices = index2.indexSearch(character);

      if (charChoices.size()==0)
      {
        cout << "\nNo matches found. Please try again." << endl;
      }
      else
       do
        {
          for (int i = 0; i<charChoices.size(); i++)
          {
            cout << i+1 << ". ";
            test1.displayName(charChoices[i]);
            cout << endl;
          }

          int charOption;

          cout << "Enter the number of the character that you would like to look up: ";

          cin >> charOption;

          cout << "\n";

          test1.displayInfo(charChoices[charOption-1]);

          cout << "\nWould you like to look up another character with the year " << character << "? (Enter Y to look up a different index choice, any other character to continue the program): ";

        cin >> indexChoice;

        cout << "\n";

      } while (indexChoice == 'Y' || indexChoice == 'y');
    }

    cout << "Would you like to look up a different name or year? (Enter Y to look up a different name or year, any other character to exit the program): ";

    cin >> programChoice;

    cin.ignore();


  }while (programChoice == 'Y' || programChoice == 'y');
  
  cout << "Thanks for using the program!";
  
  return 0;
}

string lowercase(string str)
{
  for (int i=0; i < str.length();i++)
  {
    str[i] = tolower(str[i]);
  }

  return str;
}
