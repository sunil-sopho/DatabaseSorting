#include<bits/stdc++.h> 
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;
int verbose = 1;

int ceil(int num1 ,int num2){
	if(num1%num2){
		return num1/num2 +1;
	}else{
		return num1/num2;
	}
}

// check for last systems of B-1 not needed so v.size()
int minIndex(vector<int> v){
	int index = 0;
	int val = v[0];

	for(int i=0;i<v.size();i++){

	}
}

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
	int numPages,numRuns;

	// No. of pages in file
	numPages =  fh.LastPage().GetPageNum() + 1;

	// evict last page
	fh.UnpinPage(numPages-1);

	PageHandler ph ;

	numRuns = ceil(numPages,(BUFFER_SIZE-1));
	
	if(verbose){
		cout << "Number of Pages :: " << numPages << endl;
		cout << "Number of Runs :: " << numRuns << endl;
	
	}


// Rethink about this
	if(numRuns >= BUFFER_SIZE){
		if(verbose){
			cout << "Think and code if you can :{" << endl;
		}

		return 1;
	}

	// Creating inital runs
	FileHandler scratch[numRuns];
	for(int i=0;i<numRuns;i++){
		scratch[i] = fm.CreateFile(to_string(i).c_str());
	}

	PageHandler inputPages[BUFFER_SIZE-1];
	int num,count = 0;
	char * data;
	while(true){
		// do inital runs here
		ph = scratch[count].NewPage();
		// now fectching B-1 integer blocks
		// Now lets sort data one by one for all pages
		vector<int> values;
		vector<int> indice;
		for(int i=0;i<BUFFER_SIZE-1;i++){
			inputPages[i] = fh.PageAt(count*(BUFFER_SIZE-1)+i);
			data = inputPages[i].GetData();
			vector<int> v;
			// Iterating over data
			for(int j=0;j<(PAGE_CONTENT_SIZE/(sizeof(int)));j++){
				memcpy (&num, &data[j*4], sizeof(int));
				// cout << num << endl;

				if(num==INT_MIN){
					if(verbose)
						cout << "INT_MIN Encountered at :: "<< v.size() <<"\n";
					break;
				}
				v.push_back(num);
			}
			// sorting vector
			sort(v.begin(),v.end());
			for(int j=0;j < v.size();j++){
				num = v[j];
				memcpy (&data[j*4],&num, sizeof(int));
			}

			// a checker for if everything is cool
			if(verbose==3){
				int val;
				data = inputPages[i].GetData();
				for(int itr=0;itr<v.size();itr++){
					memcpy(&val,&data[itr*4],sizeof(int));
					cout << v[itr] << " :: "<<val<<endl;
				}
			}

			// sorted this Page 
			// Set some parameters
			indice.push_back(0);
			values.push_back(v[0]);

		}

		// Now do a Kway Merge so uncool :(
		if(verbose)
			cout << "Intiating K way merge for Sorted Run :: "<<count+1<<endl;
		for(int i=0;i<BUFFER_SIZE-1;i++){
			cout << indice[i] << " :: " << values[i] <<endl;
		}
		// Till we add B-1 Pages in sorted order to new file
		while(true){
			int pageCount = minIndex(values);


		}


		// ph = fh.PageAt(count);
		// data = ph.GetData();


		// Increment counter and evict page B-1 of input file
		for(int i=0;i<BUFFER_SIZE-1;i++){
			fh.UnpinPage(count*(BUFFER_SIZE-1)+i);		
		}

		// now evict pages of scratch
		scratch[count].UnpinPage(0);

		count++;

		if(count >= numRuns){
			break;
		}
	}


	// Destroying Intial runs
	for(int i=0;i<numRuns;i++){
		fm.DestroyFile(to_string(i).c_str());
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