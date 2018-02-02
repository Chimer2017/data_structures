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
  return false;
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

void arraySort(item wordItemList[], int length) {
    item temp;

    for (int i = 0; i < length; i++)
    {
        if (wordItemList[i].count < wordItemList[i + 1].count) {
            temp.word = wordItemList[i].word;
            temp.count = wordItemList[i].count;

            wordItemList[i].word = wordItemList[i+1].word;
            wordItemList[i].count = wordItemList[i+1].count;

            wordItemList[i+1].word = temp.word;
            wordItemList[i+1].count = temp.count;

            i = 0;
        }
    }

}

int getTotalNumberNonStopWords(item wordItemList[], int numberOfUniqueWords) {
  int sum = 0;

  for ( int i = 0; i < numberOfUniqueWords; i++)
  {
    sum = sum + wordItemList[i].count;
  }

  return sum;
}

void printTopN(item wordItemList[], int topN) {

  for (int z = 0; z < topN; z++)
  {
    cout << wordItemList[z].count << " - " << wordItemList[z].word << endl;
  }
}

void getTextWords(string filename, string ignoreWords[], int printX) {

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
    item *temp;



    ifstream ff;
    ff.open(filename);
    if (ff.is_open()) {
      while(!ff.eof())
      {
                getline(ff,line);

                stringstream ss(line);
                while(ss.good())
                {
                                ss>>word;
                                stopCheck = isStopWord(word,ignoreWords);
                                if (stopCheck == true || word == "") {
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
                                        } else {
                                            mainWordArray[j].word = word;
                                            mainWordArray[j].count++;
                                            j++;
                                            wordCount++;
                                        }
                                    }
                                  }


                                  if (wordCount == limit) {
                                    doubleCount++;
                                    temp = new item[2*limit];

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



    }
    ff.close();
  } else {
    ff.close();
  }


    /*for (int i = 0; i < 30; i++)
    {
      cout << mainWordArray[i].word << " " << mainWordArray[i].count << endl;
    }*/
    arraySort(mainWordArray,wordCount);
    printTopN(mainWordArray,printX);
    cout << "#" << endl;
    cout << "Array doubled: " << doubleCount << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << wordCount << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << getTotalNumberNonStopWords(mainWordArray, wordCount) << endl;



    delete [] mainWordArray;
    mainWordArray = nullptr;

}












int main(int argc, char *argv[]) {
  int numberPrint = stoi(argv[1]);
  string fullTextFile = argv[2];
  string ignoreFilename = argv[3];
  string mainIgnoreWordArray[50];


  getStopWords(argv[3], mainIgnoreWordArray);
  getTextWords(fullTextFile, mainIgnoreWordArray, numberPrint);



  return 0;
}
