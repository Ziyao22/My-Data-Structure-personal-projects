// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include"heap.h"
#include"binaryTree.h"
using namespace std;
//Ziyao Gao zg8rw 11/10/2020
//huffmandec.cpp
// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    // heap heap1;
    int count=0;
    int count1=0;
    //string letter[1000];
    //string prefix1[000];
    vector<string>letter;
    vector<string>prefix1;
    heap heap1;
    binaryTree* node=new binaryTree();
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
	//heap heap1;
	//binaryTree* node=new binaryTree();
	//int count;
	//huffmanTree1(node,0,prefix,c);
        // do something with the prefix code
	letter.push_back(character);
	prefix1.push_back(prefix);
    while(count<letter.size()){
      //letter.push_back(character);
      //prefix1.push_back(prefix);
      heap1.huffmanTree1(node,0,letter[count],prefix1[count]);
      count++;
    }
		//	heap1.printTree(node,0,character);
	// 	 cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
	//	in+=printTree(node,0,bits);
        sstm << bits;
    }
    string allbits = sstm.str();
    while(count1<allbits.length())
    heap1.printTree(node,count1,allbits);
    cout<<endl;
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    return 0;
}
