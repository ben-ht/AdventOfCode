#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::string content;
    std::map<int, std::string> numbers = {
            { 0, "zero" },
            { 1, "one" },
            { 2, "two" },
            { 3, "three" },
            { 4, "four" },
            { 5, "five" },
            { 6, "six" },
            { 7, "seven" },
            { 8, "eight" },
            { 9, "nine" }
    };
    unsigned int sum = 0;
    std::ifstream file;
    file.open("input.txt");
    while (getline (file, content)){
        unsigned int firstIndex = content.length();
        int lastIndex = -1;
        int firstValue = 0;
        int lastValue = 0;
        for (auto const& n : numbers){
            unsigned int rowFirstIndexStr = content.find(n.second);
            unsigned int rowFirstIndexDigit = content.find(std::to_string(n.first));
            unsigned int rowFirstIndex = std::min(rowFirstIndexStr, rowFirstIndexDigit);
            if (rowFirstIndex < firstIndex){
                firstIndex = rowFirstIndex;
                firstValue = n.first;
            }

            int rowLastIndexStr = content.rfind(n.second);
            int rowLastIndexDigit = content.rfind(std::to_string(n.first));
            if (rowLastIndexStr > content.length()) rowLastIndexStr = -1;
            if (rowLastIndexDigit > content.length()) rowLastIndexDigit = -1;
            int rowLastIndex = std::max(rowLastIndexStr, rowLastIndexDigit);
            if (rowLastIndex != -1 && rowLastIndex >= lastIndex){
                lastIndex = rowLastIndex;
                lastValue = n.first;
            }

        }
        std::string rowValue = std::to_string(firstValue) + std::to_string(lastValue);
        sum += stoi(rowValue);
    }
    file.close();

    std::cout << sum;
    return 0;
}
