/* File handling
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	/* FILE HANDLING
		Three classe:
			ifstream: Stream class to read from files 
			ofstream: Stream class to write on files 
			fstream: Stream class to both read and write from/to files. 
	*/

	// Writing in a file		
	ofstream fout;
	fout.open("sample.txt");		// by default ios::out mode, automatically deletes the content of file
 
    string line;

    while (fout) {
        // Read a Line from standard input
        getline(cin, line);
        // Press -1 to exit
        if (line == "-1")
            break;
        // Write line in file
        fout << line << endl;
	}

    fout.close();

    // Reading from a file
    ifstream fin;
    fin.open("sample.txt");
 
    while (fin) {		// Execute a loop until EOF (End of File)
        getline(fin, line);
        
        cout << line << endl;
    }
 
    fin.close();

    /* Objects can be written to and read from a file through
    	fout.write() and fin.read()
	*/

	return 0;
}