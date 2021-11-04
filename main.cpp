#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

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


 vector<pair<int, int>> FindEmptyLinesInFile(ifstream& inpfile){
    if (!inpfile) {
        cerr << "Something goes wrong with files";
        exit(1);
    }

    vector<pair<int, int>> empty_lines;
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
                empty_lines.push_back({empty_line_number, empty_lines_counter});
                empty_lines_counter = 0;
            }
        }
        line_number++;
    }
    return empty_lines;
}

void WriteInFile(const vector<pair<int, int>>& lines, ofstream& outfile){
    if (!outfile) {
        cerr << "Something goes wrong with files";
        exit(1);
    }

    for(const pair<int, int>& line : lines){
        outfile << "Line " << line.first << "; Amount " << line.second << endl;
    }
}

int main() {
    ifstream inpfile("input.txt");
    ofstream outfile("output.txt");
    vector<pair<int, int>> lines = FindEmptyLinesInFile(inpfile);
    WriteInFile(lines, outfile);
    return 0;
}
