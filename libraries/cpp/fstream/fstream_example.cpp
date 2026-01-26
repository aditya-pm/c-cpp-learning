#include <fstream>
#include <iomanip>  // for formatting examples
#include <iostream>
#include <string>  // required for getline

/*
 * Related files:
 *  - libraries/cpp/aditya.txt
 *  - libraries/cpp/input_nums.txt
 *  - libraries/cpp/output_nums.txt
 */

int main() {
    // ------------------------------------------------------------------------
    // PART 1: Using std::fstream with explicit open() and close()
    // ------------------------------------------------------------------------

    // EXAMPLE 1
    std::fstream my_file;  // input/output stream

    // WRITE MODE (overwrite)
    // aditya.txt is created if it does not exist
    my_file.open("libraries/cpp/fstream/aditya.txt", std::ios::out);
    if (my_file.is_open()) {
        my_file << "Hello\n";
        my_file << "This is the second line\n";
        my_file.close();
    }

    // APPEND MODE (add to existing content)
    my_file.open("libraries/cpp/fstream/aditya.txt", std::ios::app);
    if (my_file.is_open()) {
        my_file << "This sentence is APPENDED\n";
        my_file.close();
    }

    // READ MODE (file must exist)
    my_file.open("libraries/cpp/fstream/aditya.txt", std::ios::in);
    if (my_file.is_open()) {
        std::string line;
        while (std::getline(my_file, line)) {  // unformatted input
            std::cout << line << std::endl;
        }
        my_file.close();
    }

    // EXAMPLE 2
    // using formatted input/output with >> and <<

    std::ifstream input_file;   // input only
    std::ofstream output_file;  // output only

    input_file.open("libraries/cpp/fstream/input_nums.txt");
    if (!input_file.is_open()) {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    output_file.open("libraries/cpp/fstream/output_nums.txt");
    if (!output_file.is_open()) {
        std::cout << "Error opening output file" << std::endl;
        return -1;
    }

    int int_from_input_file = 0;
    while (input_file >> int_from_input_file) {               // formatted input
        output_file << int_from_input_file * 2 << std::endl;  // formatted output
    }

    input_file.close();
    output_file.close();

    // ------------------------------------------------------------------------
    // PART 2: using constructors instead of open()
    // (preferred in modern C++)
    // ------------------------------------------------------------------------

    // constructor-based opening combines creation + opening
    // into a single step and reduces the chance of misuse

    std::ofstream out_file("libraries/cpp/fstream/aditya.txt", std::ios::app);
    if (out_file.is_open()) {
        out_file << "Written using constructor-based opening\n";
        out_file.close();  // still allowed, but often unnecessary
    }

    std::ifstream in_file("libraries/cpp/fstream/aditya.txt");
    if (in_file.is_open()) {
        std::string line;
        while (std::getline(in_file, line)) {
            std::cout << line << std::endl;
        }
        in_file.close();
    }

    // ------------------------------------------------------------------------
    // PART 3: Using scopes and RAII (automatic file closing)
    // ------------------------------------------------------------------------

    // streams automatically close themselves when they go out of scope
    // this is known as RAII (Resource Acquisition Is Initialization)

    {
        // File is opened when the object is created
        std::ofstream scoped_out("libraries/cpp/fstream/output_nums.txt", std::ios::app);

        if (scoped_out) {
            scoped_out << std::fixed << std::setprecision(2);
            scoped_out << 3.14159 << std::endl;  // formatted output
            scoped_out << 42 << std::endl;
        }

    }  // scoped_out goes out of scope here -> file is closed automatically

    {
        std::ifstream scoped_in("libraries/cpp/fstream/output_nums.txt");

        if (scoped_in) {
            std::string line;
            while (std::getline(scoped_in, line)) {
                std::cout << line << std::endl;
            }
        }

    }  // scoped_in goes out of scope here -> file is closed automatically

    return 0;
}
