#include<bits/stdc++.h> 
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;
int verbose = 0;

int main(int argc, char *argv[]){
	if(verbose)
		cout << "No. of arguments:: "<<argc << endl;
	if(argc != 3){
		if(verbose){
			cout << "Argument miss match"<< endl;
			cout << "usage :: ./binary_search <file> <int>\n";
		}
		return 1;
	}

	// cout << argv[2] << endl;
	// File manager constructer
	FileManager fm;

	// Open file from input
	FileHandler fh = fm.OpenFile(argv[1]);

	//  intialize variables 
	int start =0,end,searchInt;
	searchInt = atoi(argv[2]);

	// No. of pages in file
	end =  fh.LastPage().GetPageNum();

	PageHandler ph ;

	int pageNum = -1,num;
	char* data;
	bool found = false;
	int intPage=-1,intEntryNum=-1;
	// Lets inspect the data here
	while(start <= end && !found){
		ph = fh.PageAt((start+end)/2);
		data = ph.GetData();

		// check for firt number 
		memcpy (&num, &data[0], sizeof(int));
		if(num > searchInt){
			end = (start+end)/2 - 1;
			continue;
		}


		for(int i=0;i<(PAGE_CONTENT_SIZE/(sizeof(int)));i++){
			memcpy (&num, &data[i*4], sizeof(int));
			// cout << num << endl;
			if(num == searchInt){
				found = true;
				intPage = (start+end)/2 +1;
				intEntryNum = i+1;
				break;
			}

			if(num==INT_MIN)
				break;
		}

		if(found)
			break;

		start = (start+end)/2 +1;
	}

	// Close the file
	fm.CloseFile(fh);
	
	cout << "("<<intPage<<","<<intEntryNum<<")"<<endl;

	return 0;
}