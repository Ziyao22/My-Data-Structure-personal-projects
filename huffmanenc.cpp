#include"binaryTree.h"
#include"heap.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//Ziyao Gao zg8rw 11/10/2020
//huffmaenc.cpp
int main(int argc, char** argv) {
  // verify the correct number of parameters                               
  heap heap1;
  binaryTree* node;
  if (argc != 2) {
        cout << "Must supply the input file name as the one and only paramet\
er" << endl;
        exit(1);
    }

    // attempt to open the supplied file                                     
  ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit            
    if (!file) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of\
 the file)                                                                   
    char g;
    int characters=0;
    int convertToInt=0;
    int frequency[1000];
    int count=0;
    while(count<128){
      frequency[count]=0;
      count++;
      }
    while (file.get(g)){
	int convertToInt=(int)g;
	 int count=0;
	if(convertToInt>20&&convertToInt<128){
	  frequency[convertToInt]++;
	characters++;
      }
      // cout << g;
      }
    int counts=0;
    int counts1=0;
    string str=" ";
    for(int i=counts1;i<128;i++){
      if(frequency[i]>0){
	str=to_string(i);
	node=new binaryTree(frequency[i],str);
	heap1.insert(node);
	counts++;
      }
    }
    heap1.huffmanTree();
    vector<string> letter;
    vector<string> encode;
    int abc;
    char abcd[1000];
    heap1.prefix(heap1.findMin(),letter,encode,"");
    for(int i=0;i<counts;i++){
         if(letter[i]=="32")
         letter[i]="space";
       else if(letter[i]=="33")
         letter[i]="!";
      else if(letter[i]=="34")
     letter[i]="\"";
      else if(letter[i]=="35")
         letter[i]="#";
       else if(letter[i]=="36")
         letter[i]="$";
       else if(letter[i]=="37")
         letter[i]="%";
       else if(letter[i]=="38")
         letter[i]="&";
       else if(letter[i]=="39")
	 letter[i]="'";
       else if(letter[i]=="40")
         letter[i]="(";
       else if(letter[i]=="41")
         letter[i]=")";
       else if(letter[i]=="42")
         letter[i]="*";
       else if(letter[i]=="43")
         letter[i]="+";
       else if(letter[i]=="44")
         letter[i]=",";
       else if(letter[i]=="45")
         letter[i]="-";
       else if(letter[i]=="46")
         letter[i]=".";
       else if(letter[i]=="47")
	  letter[i]="/";
       else if(letter[i]=="48")
         letter[i]="0";
       else if(letter[i]=="49")
         letter[i]="1";
       else if(letter[i]=="50")
         letter[i]="2";
       else if(letter[i]=="51")
         letter[i]="3";
       else if(letter[i]=="52")
         letter[i]="4";
       else if(letter[i]=="53")
         letter[i]="5";
       else if(letter[i]=="54")
         letter[i]="6";
       else if(letter[i]=="55")
         letter[i]="7";
       else if(letter[i]=="56")
         letter[i]="8";
       else if(letter[i]=="57")
         letter[i]="9";
       else if(letter[i]=="58")
         letter[i]=":";
       else if(letter[i]=="59")
         letter[i]=";";
       else if(letter[i]=="60")
         letter[i]="<";
       else if(letter[i]=="61")
         letter[i]="=";
       else if(letter[i]=="62")
         letter[i]=">";
       else if(letter[i]=="63")
         letter[i]="?";
        else if(letter[i]=="64")
         letter[i]="@";
	else if(letter[i]=="65")
	letter[i]="A";
       else if(letter[i]=="66")
        letter[i]="B";
      else if(letter[i]=="67")
        letter[i]="C";
       else if(letter[i]=="68")
        letter[i]="D";
      else if(letter[i]=="69")
        letter[i]="E";
      else if(letter[i]=="70")
        letter[i]="F";
      else if(letter[i]=="71")
        letter[i]="G";
       else if(letter[i]=="72")
        letter[i]="H";
      else if(letter[i]=="73")
        letter[i]="I";
      else if(letter[i]=="74")
        letter[i]="J";
      else if(letter[i]=="75")
        letter[i]="K";
       else if(letter[i]=="76")
        letter[i]="L";
      else if(letter[i]=="77")
        letter[i]="M";
      else if(letter[i]=="78")
        letter[i]="N";
      else if(letter[i]=="79")
        letter[i]="O";
       else if(letter[i]=="80")
        letter[i]="P";
      else if(letter[i]=="81")
        letter[i]="Q";
      else if(letter[i]=="82")
        letter[i]="R";
      else if(letter[i]=="83")
        letter[i]="S";
       else if(letter[i]=="84")
        letter[i]="T";
      else if(letter[i]=="85")
        letter[i]="U";
      else if(letter[i]=="86")
        letter[i]="V";
      else if(letter[i]=="87")
	letter[i]="W";
      else if(letter[i]=="88")
	letter[i]="X";
      else if(letter[i]=="89")
        letter[i]="Y";
      else if(letter[i]=="90")
        letter[i]="Z";      
     else if(letter[i]=="97")
	letter[i]="a";
      else if(letter[i]=="98")
	letter[i]="b";
      else if(letter[i]=="99")
	letter[i]="c";
       else if(letter[i]=="100")
        letter[i]="d";
      else if(letter[i]=="101")
        letter[i]="e";
      else if(letter[i]=="102")
        letter[i]="f";
      else if(letter[i]=="103")
        letter[i]="g";
       else if(letter[i]=="104")
        letter[i]="h";
      else if(letter[i]=="105")
        letter[i]="i";
      else if(letter[i]=="106")
        letter[i]="j";
      else if(letter[i]=="107")
        letter[i]="k";
       else if(letter[i]=="108")
        letter[i]="l";
      else if(letter[i]=="109")
        letter[i]="m";
      else if(letter[i]=="110")
        letter[i]="n";
      else if(letter[i]=="111")
        letter[i]="o";
       else if(letter[i]=="112")
        letter[i]="p";
      else if(letter[i]=="113")
        letter[i]="q";
      else if(letter[i]=="114")
        letter[i]="r";
      else if(letter[i]=="115")
        letter[i]="s";
       else if(letter[i]=="116")
        letter[i]="t";
      else if(letter[i]=="117")
        letter[i]="u";
      else if(letter[i]=="118")
        letter[i]="v";
      else if(letter[i]=="119")
        letter[i]="w";
       else if(letter[i]=="120")
        letter[i]="x";
       else if(letter[i]=="121")
	 letter[i]="y";
       else if(letter[i]=="122")
        letter[i]="z";
      else if(letter[i]=="123")
        letter[i]="{";
      else if(letter[i]=="124")
        letter[i]="|";
      else if(letter[i]=="125")
        letter[i]="}";
       else if(letter[i]=="126")
        letter[i]="~";
       else if(letter[i]=="127")
       letter[i]="delete";
      //   abc=stoi(letter[i]);
      // abcd[i]=(char)abc;
      //cout<<abcd[i]<<" "<<encode[i]<<endl;
      cout<<letter[i]<<" "<<encode[i]<<endl;
    }
    cout << "----------------------------------------" << endl;
    file.clear();
    file.seekg(0);
    int number=0;
    int bit=0;
    while(file.get(g)){
      number++;
      string str(1,g);
      if(str==" ")
      str="space";
      for(int i=0;i<counts;i++){
	if(str==letter[i]){
	  bit+=encode[i].length();
	  cout<<encode[i]<<" ";
	}
      }
    }
    cout<<endl;
    cout << "----------------------------------------" << endl;
    cout<<"There are a total of "<<characters<<" symbols that are encoded."
	<<endl;
    cout<<"There are "<<counts<<" distinct symbols used."<<endl;
    cout<<"There were "<<characters*8<<" bits in the original file."<<endl;
    cout<<"There were "<<bit<<" bits in the compressed file"<<endl;
    cout<<"This gives a compression ratio of "<<(double)characters*8/bit<<"."<<endl;
    cout<<"The cost of the Huffman tree is "<<(double)bit/characters<<" bits per character."<<endl;
    file.close();
// a nice pretty separator                                               
    /* cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear t\
hat                                                                          
    // then "seek" to the beginning of the file to start again               
    file->clear(); // Clears the _state_ of the file, not its contents!       
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file->get(g)) {
        cout << g;
    }

    // close the file                                                        
    file->close();*/
    return 0;
}

