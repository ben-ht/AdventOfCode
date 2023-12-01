#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string content;
    std::string digits = "0123456789";
    unsigned int sum = 0;
    std::ifstream file;
    file.open("input.txt");
    while (getline (file, content)){
        unsigned int firstDigitIndex = content.find_first_of(digits);
        unsigned int lastDigitIndex = content.find_last_of(digits);
        std::string calibrationStr = std::string(1, content[firstDigitIndex]) + content[lastDigitIndex];
        unsigned int calibrationValue = stoi(calibrationStr);
        sum += calibrationValue;
    }
    file.close();

    std::cout << sum;
    return 0;
}
