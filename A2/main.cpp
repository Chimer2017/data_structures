#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//USER DEFINED struct

struct item {
  string word;
  int count = 0;
};

void doNothing() {

}

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

int isUniqueWord(string word, item array[], int length) {
  int index;
  int status;
  for (int i = 0; i < length; i++)
  {
    if (word == array[i].word) {
      // not unique, return index and increment
      index = i;
      status = 1;
      break;
    }
  }
  if (status == 1) {
    return index;
  } else {
    return -1;
  }


}


void getTextWords(string filename, string ignoreWords[]) {

//strings necessary for PARSING
    string line;
    string word;
//int necessary for doubling arrays
    int doubleCount = 0;
    int wordCount = 0;
    int j = 0;
    int n = 100;
    int limit = 100;
//bools necessary for checking unqiueness of the WORD
    bool stopCheck;
    int uniqueCheck;
    item *mainWordArray;
    mainWordArray = new item[n];


    ifstream ff;
    ff.open(filename);
    if (ff.is_open()) {
      while(!ff.eof())
      {
                getline(ff,line);

                stringstream ss(line);
                while(ss>>word)
                {
                                stopCheck = isStopWord(word,ignoreWords);
                                if (stopCheck == true) {
                                    doNothing();
                                } else {
                                    if (wordCount == 0) {
                                        mainWordArray[j].word = word;
                                        mainWordArray[j].count = 1;
                                        j++;
                                        wordCount++;
                                    } else {
                                        uniqueCheck = isUniqueWord(word,mainWordArray,wordCount);
                                        if (uniqueCheck != -1) {
                                            mainWordArray[uniqueCheck].count++;
                                        }
                                        if (uniqueCheck == -1) {
                                            mainWordArray[j].word = word;
                                            mainWordArray[j].count++;
                                            j++;
                                            wordCount++;
                                        }

                                    }
                                  }



                  }
                  if (wordCount == limit) {
                    doubleCount++;
                    item *temp;
                    temp = new item[2*n];

                    for (int z = 0; z < limit; z++)
                    {
                      temp[z].word = mainWordArray[z].word;
                      temp[z].count = mainWordArray[z].count;
                    }
                    delete [] mainWordArray;
                    mainWordArray = temp;
                    temp = nullptr;
                    limit = 2 * wordCount;

                  }


    }
    ff.close();
  } else {
    ff.close();
  }
    cout << wordCount << endl;
    cout << doubleCount << endl;
/*
    for (int i = 0; i < wordCount; i++)
    {
      cout << mainWordArray[i].word << " " << mainWordArray[i].count << endl;
    }*/

}












int main(int argc, char *argv[]) {
  int numberPrint = stoi(argv[1]);
  string fullTextFile = argv[2];
  string ignoreFilename = argv[3];
  string mainIgnoreWordArray[50];


  getStopWords(argv[3], mainIgnoreWordArray);
  getTextWords(fullTextFile, mainIgnoreWordArray);



  return 0;
}
