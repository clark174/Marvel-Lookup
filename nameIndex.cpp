#include "nameIndex.h"
using namespace std;

nameIndex::nameIndex(string filename)
{
  string word, line;
  ifstream infile(filename); // open the file
  int position = 0;
  while (!infile.fail()) {
    getline(infile,line,'\r'); // get the next line of code
    line = getName(line); //gets the name of the character.
    line = lowercase(line);//makes it lowercase.
    istringstream lineStream(line); // Create a string stream of the line
    while (lineStream >> word) { // get the next word
        refs[word].push_back(position); // push the word and the line position on the vector for this word.
    }
    position++; // get the position of the next line

    if(position == 16377)
    {
      infile.close();
      break;
    }
}
infile.close();
}

string nameIndex::lowercase(string str)
{
  for (int i=0; i < str.length();i++)
  {
    str[i] = tolower(str[i]);
  }

  return str;
}

vector <int> nameIndex::indexSearch(string word)
{
  map<string, vector<int> >::iterator it;  // iterator for find                                                                
  vector<int> blank; // return for no matches                                                                                  
    /* find the word and get the vector of references */
    /* First use find, so as to NOT create a new entry */
    it = refs.find(word);
    if (it == refs.end()) {
         return(blank);
    } else {
        return (refs[word]);
    }
}

string nameIndex::getName(string str)
{
  string temp = "";
  int position = 0;

  //ignore the characters that are not letters.
  while (str[position] < 'a' || str[position] > 'z')
  {
    position++;
  }
  position--;
  
  //The name is always in between the first and second commas so this loop captures all the info between those two.
  while (str[position] != ',')
  {
    temp+=str[position];
    position++;
  }


  return temp;
}
