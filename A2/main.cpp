#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void getStopWords(char *ignoreWordFileName, string ignoreWords[]) {
  string line;
  int i = 0;
  fstream data;
  data.open(*ignoreWordFileName);

  if (data.is_open()) {
    while (getline(data,line))
    {
        ignoreWords[i] = line;
        i++;
    }
    data.close();
  } else {
    data.close();
  }

}

int main(int argc, char const *argv[]) {
  int numberPrint = stoi(argv[1]);
  string fullTextFile = argv[2];
  string ignoreFilename = argv[3];
  string *ignoreFilenameRef;
  string mainIgnoreWordArray[50];

  ignoreFilenameRef = &ignoreFilename;

  getStopWords(ignoreFilenameRef, mainIgnoreWordArray);

  return 0;
}
