#include<bits/stdc++.h> 
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;
int verbose = 1;

int main(int argc, char *argv[]){
	if(verbose)
		cout << "No. of arguments:: "<<argc << endl;
	if(argc != 3){
		if(verbose){
			cout << "Argument miss match"<< endl;
			cout << "usage :: ./merge_sort <input_file> <output_file>\n";
		}
		return 1;
	}

	// File manager constructer
	FileManager fm;

	// Open file from input
	FileHandler fh = fm.OpenFile(argv[1]);

	//  intialize variables 
	int numRuns;

	// No. of pages in file
	numRuns =  fh.LastPage().GetPageNum() + 1;
	PageHandler ph ;
	
	if(verbose)
		cout << "Number of Pages :: " << numRuns << endl;

	if(numRuns >= BUFFER_SIZE){
		if(verbose){
			cout << "Think and code if you can :{" << endl;
		}

		return 1;
	}

	// Close the file
	fm.CloseFile(fh);


	// open output file for writing output
	fh = fm.CreateFile(argv[2]);

	// // Close the file and destory it
	fm.CloseFile (fh);
	fm.DestroyFile (argv[2]);


	// cout << "("<<intPage<<","<<intEntryNum<<")"<<endl;

	return 0;
}