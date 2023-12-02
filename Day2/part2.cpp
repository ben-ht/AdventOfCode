#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>

std::vector<std::string>split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while(getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

int main(){
    unsigned sum = 0;
    std::string content;
    std::ifstream file;
    file.open("input.txt");
    while (getline (file, content)){
        unsigned int colonIndex = content.find(':');
        unsigned int spaceIndex = content.find(' ');
        std::map<std::string, int> minColors = {
                { "red", 0 },
                { "green", 0 },
                { "blue", 0 }
        };

        std::string sets = content.substr(colonIndex + 1);
        std::vector<std::string> setsArray = split(sets, ';');
        for (auto const& s : setsArray){
            std::vector<std::string> colorsArray = split(s, ',');
            for (auto c : colorsArray){
                trim(c);
                std::vector<std::string> pair = split(c, ' ');
                if (stoi(pair[0]) > minColors[pair[1]]){
                    minColors[pair[1]] = stoi(pair[0]);
                }
            }
        }
        sum += minColors["red"] * minColors["green"] * minColors["blue"];
    }

    std::cout << sum;
    return 0;
}