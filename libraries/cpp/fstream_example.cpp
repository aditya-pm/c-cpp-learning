#include <fstream>
#include <iostream>
#include <string>  // required for getline

int main() {
    // EXAMPLE 1
    std::fstream my_file;  // input/output

    // WRITE MODE (overwrite)
    // aditya.txt is created if it does not exist
    // file is opened in write mode (std::ios::out)
    my_file.open("libraries/cpp/aditya.txt", std::ios::out);
    if (my_file.is_open()) {
        my_file << "Hello\n";
        my_file << "This is the second line\n";
        my_file.close();
    }

    // APPEND MODE (add to existing)
    my_file.open("libraries/cpp/aditya.txt", std::ios::app);
    if (my_file.is_open()) {
        my_file << "This sentence is APPENDED\n";
        my_file.close();
    }

    // READ MODE (file must exist)
    my_file.open("libraries/cpp/aditya.txt", std::ios::in);
    if (my_file.is_open()) {
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << std::endl;
        }
        my_file.close();
    }

    // EXAMPLE 2
    std::ifstream input_file;   // input only
    std::ofstream output_file;  // output only

    input_file.open("libraries/cpp/input_nums.txt");
    if (!input_file.is_open()) {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }

    output_file.open("libraries/cpp/output_nums.txt");
    if (!output_file.is_open()) {
        std::cout << "Error opening output file" << std::endl;
        return -1;
    }

    int int_from_input_file = 0;
    while (input_file >> int_from_input_file) {
        output_file << int_from_input_file * 2 << std::endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}
