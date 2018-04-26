#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE] = {};
    bool isEndOfWord;
    int counter = 0;
};


class Trie {
    public:
        Trie();
        ~Trie();
        void insert(string);
        int search(string);
        TrieNode* root;
};


Trie::Trie() {

root = new TrieNode;

}

Trie::~Trie() {}

TrieNode *getNode()
{
    TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void Trie::insert(string word) {
  //cout << word[0] - 'a' << endl;
    /* Start from the root  */
    TrieNode* pt = root;
    //cout << "a" << endl;

    /* Iterate over all letters in the word  */
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] <= 'a' || word[i] >= 'z')
          continue;
        /*
         * YOUR CODE HERE
         */    //cout << "z" << endl;

         int index = word[i] - 'a';
         //cout << "j" << endl;

         if (!pt->children[index])
         {
            pt->children[index] = getNode();
          }

      //cout << "x" << endl;

        pt = pt->children[index];
    }

    /* Once we finish iterating over the word,
        we can mark the node of the last letter
        as "end of the word".
      */
    pt->isEndOfWord = true;
    pt->counter++;

}

int Trie::search(string word) {
    struct TrieNode* pt = root;

    /*
    Starting from the root,
    we iterate over all the letters of this word.
    */
    for (int i = 0; i < word.length(); i++)
    {
        /*
         * YOUR CODE HERE
         */
        int index = word[i] - 'a';
        if (!pt->children[index])
            return -1;

        pt = pt->children[index];

    }

    /*
    At this point, we finish iterating the word.
    Does that mean we've found this word?
    What additional condition should we check?
    */
     bool stat = (pt != NULL && pt->isEndOfWord);
     if (pt->counter > 0)
      return pt->counter;
    else
      return -1;

}


void array_insert(string word, vector<string>& vocabulary, vector<int>& counter) {

    for (int i = 0; i < vocabulary.size(); ++i) {
        if (word == vocabulary[i]) {
            counter[i] += 1;
            return;
        }
    }

    vocabulary.push_back(word);
    counter.push_back(1);
    return;
}


int array_search(string word, vector<string>& vocabulary, vector<int>& counter) {

    for (int i = 0; i < vocabulary.size(); ++i) {
        if (word == vocabulary[i]) {
            return counter[i];
        }
    }

    return -1;
}

int main() {
  //cout << "a" << endl;


    /* Create a trie  */
    Trie the_trie;
    //cout << "a" << endl;


    //cout << "a" << endl;
    /* Read in file  */
    ifstream handle;
    handle.open("test.txt");
    string line;
    string word;
    //cout << "b" << endl;

    while(getline(handle, line, '\n')) {

        stringstream sp(line);
        while (getline(handle, word, ' ')) {
          //cout << "c" << endl;

            the_trie.insert(word);
        }
    }

    handle.close();

    clock_t t1, t2;
    t1 = clock();
    cout << "      the: " << the_trie.search("the");
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    cout << "    there: " << the_trie.search("there");
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    cout << "therefore: " << the_trie.search("therefore");
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;


    /* Array implementation  */

    handle.open("test.txt");
    vector<string> vocab;
    vector<int> counter;

    while(getline(handle, line, '\n')) {

        stringstream sp(line);
        while (getline(handle, word, ' ')) {
            if (word[0] == '\n') word = word.substr(1);
            array_insert(word, vocab, counter);
        }
    }

    handle.close();

    t1 = clock();
    cout << "      the: " << array_search("the", vocab, counter);
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    cout << "    there: " << array_search("there", vocab, counter);
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    cout << "therefore: " << array_search("therefore", vocab, counter);
    t2 = clock();
    cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;


    return 0;
}
