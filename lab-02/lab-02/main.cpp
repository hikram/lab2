#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    cout << "Hashim Ikram’s Lexer\n";
    ifstream file;
    string line;
    bool single_comment_flag = false, multi_comment_flag = false;
    int x;
    file.open("/Users/Hashim/Documents/School/Semester7/CompilerConstruction/labs/lab2/lab-02/lab-02/input_scanner.txt");
    
    if (file.is_open()) {
        for (; getline(file, line); ) {                        //read a line and store it in string 'line'
            for (int x = 0; x < line.size(); x++) {             //scan each line char by char
                switch (line.at(x)) {
                    case '/':
                        if ((x < line.size() - 1) && line.at(x + 1) == '/')                 //single line comment
                            single_comment_flag = true;
                        break;
                    case '*':
                        if (((x < line.size() - 1) && (x > 0)) && line.at(x - 1) == '/')    //multi-line comment
                            multi_comment_flag = true;
                        
                        else if (multi_comment_flag && ((x < line.size() - 1) && (x > 0)) && line.at(x + 1) == '/')
                            multi_comment_flag = false;
                        break;
                    default:
                        if (single_comment_flag || multi_comment_flag)
                            continue;
                        else
                            cout << line.at(x);
                }
            }
            cout << "\n";
            single_comment_flag = false;
        }
    }
    cin >> x;
    return 0;
}
