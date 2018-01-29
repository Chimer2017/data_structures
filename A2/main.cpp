#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//USER DEFINED struct

struct item {
  string word;
  int count;
};


//************************* STOP WORD FUNCTIONS ************************************************
void getStopWords(char *ignoreWordFileName, string ignoreWords[]) {
  string line;
  int i = 0;
  fstream data;
  data.open(ignoreWordFileName);

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

bool isStopWord(string word, string ignoreWords[]){
  for (int i = 0; i < 50; i++)
  {
    if (word == ignoreWords[i]) {
      return true;
    }
  }
}

//************************* FULL TEXT PARSING FUNCTION ************************************************


void getTextWords(string filename) {
    cout << "Test";

}












int main(int argc, char *argv[]) {
  int numberPrint = stoi(argv[1]);
  string fullTextFile = argv[2];
  string ignoreFilename = argv[3];
  string mainIgnoreWordArray[50];
  int n = 100;
  item *mainWordArray;
  mainWordArray = new item[n];

  getStopWords(argv[3], mainIgnoreWordArray);
  getTextWords("test");



  return 0;
}
