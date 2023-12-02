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
    std::map<std::string, int> cubes = {
            { "red", 12 },
            { "green", 13 },
            { "blue", 14 }
    };
    unsigned sum = 0;
    std::string content;
    std::ifstream file;
    file.open("input.txt");
    while (getline (file, content)){
        bool isGameValid = true;
        unsigned int colonIndex = content.find(':');
        unsigned int spaceIndex = content.find(' ');
        unsigned int idLength = colonIndex - spaceIndex - 1;
        std::string gameId = content.substr(spaceIndex + 1, idLength);

        std::string sets = content.substr(colonIndex + 1);
        std::vector<std::string> setsArray = split(sets, ';');
        for (auto const& s : setsArray){
            std::vector<std::string> colorsArray = split(s, ',');
            for (auto c : colorsArray){
                trim(c);
                std::vector<std::string> pair = split(c, ' ');
                if (stoi(pair[0]) > cubes[pair[1]]){
                    isGameValid = false;
                }
            }
        }
        if (isGameValid){
            sum+= stoi(gameId);
        }
    }

    std::cout << sum;
    return 0;
}