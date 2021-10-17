#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsEmptyLine(const string& str){
    if(str  == "")
        return true;
    if(str[0] == ' '){
        for(char s : str){
            if(s != ' ')
                return false;
        }
        return true;
    }
    return false;
}

void FindEmptyLinesInFile(ifstream& inpfile, ofstream& outfile){
    if (!inpfile || !outfile) {
        cerr << "Something goes wrong with files";
        return;
    }
    int line_number = 1, empty_line_number;
    int empty_lines_counter = 0;
    while (inpfile) {
        string line;
        getline(inpfile, line);
        if (IsEmptyLine(line)) {
            empty_lines_counter++;
            if (empty_lines_counter == 1)
                empty_line_number = line_number;
        } else {
            if (empty_lines_counter != 0) {
                outfile << "Line " << empty_line_number << "; Amount " << empty_lines_counter << endl;
                empty_lines_counter = 0;
            }
        }
        line_number++;
    }
}

int main() {
    ifstream inpfile("input.txt");
    ofstream outfile("output.txt");
    FindEmptyLinesInFile(inpfile, outfile);  
    return 0;
}
