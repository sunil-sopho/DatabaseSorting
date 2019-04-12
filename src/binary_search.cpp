#include<iostream>
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;

int main(int argc, char *argv[]){
	cout << "No. of arguments:: "<<argc << endl;
	if(argc != 3){
		cout << "Argument miss match"<< endl;
		cout << "usage :: ./binary_search <file> <int>\n";
		return 1;
	}

	// cout << argv[2] << endl;
	// File manager constructer
	FileManager fm;

	// Open file from input
	FileHandler fh = fm.OpenFile(argv[1]);

	// No. of pages in file
	cout << fh.LastPage().GetPageNum() <<endl;

	PageHandler ph = fh.FirstPage();

	int pageNum = -1;
	// Lets inspect the data here
	while(true){
		pageNum = ph.GetPageNum();
		cout << "Page Number :: "<< pageNum << endl;
		ph = fh.NextPage(pageNum);
	}


	return 0;
}