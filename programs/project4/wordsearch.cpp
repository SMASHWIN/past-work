#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <string.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include "bag.h"

using namespace std;

void to_lower(std::string& s) {
   for (std::string::iterator p = s.begin();
        p != s.end(); ++p) {
      *p = tolower(*p);
   }
}


// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  sort(files.begin(), files.end());
  return 0;
}

int main(int argc, char* argv[])
{
  string dir; 
  vector<string> files = vector<string>();

  Bag container; // Bag object where you will store the words.
  

  // This part of the program checks if a directory containing the files has been
  // specified. If There is no directory specified, the program terminates.
  // Otherwise, it opens the sub-directory containg the data files using the function
  // getdir().
  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  
  // This part of the program opens every data file one by one and prints out the
  // words contained in it.

  string slash("/");
  for (unsigned int i = 0; i < files.size(); i++) {
    if(files[i][0]=='.') continue; //skip hidden files
    cout << "OPEN " << files[i] << endl;
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file..
    string word;
    while(true){
      fin>>word;
      if(fin.eof()) {cout << "EOF " << files[i] << endl; break;}
      to_lower(word);
      container.add(word, files[i]);
    // add code here to insert the word to the bag object "container" along with the filename

    }
    fin.close();
  }

  // the code below reads in user input and do searching and displaying of results
  while(true){
    cout<<"Enter word: ";
    std::string input;
    getline(cin, input, '\n');
    to_lower(input);

    if(strcmp(".",input.c_str()) == 0)
      break;
    if (!container.contains(input)) cout << "Word not found in database" << endl;
    else{
	Word w = container.findWord(input);
	cout << "Total count: " << w.getCount() << endl;
	for(int i = 0; i < w.getSize(); i++){
		cout << w.getFile(i)->getName() << "::" << w.getFile(i)->getCount() << endl;
	}
    }
    // add code here to search the bag object "container" and display the search results

    
    
  }
  
  return 0;
}






