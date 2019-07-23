#include "TextHandler.h"

TextHandler::TextHandler(const char* filename) : filename(filename) {
    characters = new std::set<char>();
    charactersStatistics = new std::map<char, int>();
    numbers = new std::set<char>();
    numbersStatistics = new std::map<char, int>();
    specialSymbols = new std::set<char>();
    specialSymbolsStatistics = new std::map<char, int>();
    words = new std::set<std::string>();
    wordsStatistics = new std::map<std::string, int>();
    quantity = 0;
    wordsQuantity = 0;
}

TextHandler::~TextHandler() {
    delete characters;
    delete charactersStatistics;
    delete numbers;
    delete numbersStatistics;
    delete specialSymbols;
    delete specialSymbolsStatistics;
    delete words;
    delete wordsStatistics;
}

const std::set<char>& TextHandler::getCharacters() const {
    return *characters;
}
const std::map<char, int>& TextHandler::getCharactersStatistics() const {
    return *charactersStatistics;
}
const std::set<char>& TextHandler::getNumbers() const {
    return *numbers;
}
const std::map<char, int>& TextHandler::getNumbersStatistics() const {
    return *numbersStatistics;
}
const std::set<char>& TextHandler::getSpecialSymbols() const {
    return *specialSymbols;
}
const std::map<char, int>& TextHandler::getSpecialSymbolsStatistics() const {
    return *specialSymbolsStatistics;
}
const std::set<std::string>& TextHandler::getWords() const {
    return *words;
}
const std::map<std::string, int>& TextHandler::getWordsStatistics() const {
    return *wordsStatistics;
}
long long TextHandler::getQuantity() const {
    return quantity;
}
long long TextHandler::getWordsQuantity() const {
    return wordsQuantity;
}
void TextHandler::insert(char symbol, std::set<char>* lst) {
    lst->insert(symbol);
}

void TextHandler::insert(char symbol, std::map<char, int>* lst) {
    if ( lst->find(symbol) == lst->end() ) {
        lst->insert(std::pair<char, int>(symbol, 0));
    }
    lst->at(symbol) += 1;
}

void TextHandler::insert(std::string str, std::set<std::string>* lst) {
    lst->insert(str);
}
void TextHandler::insert(std::string str, std::map<std::string, int>* lst) {
    if ( lst->find(str) == lst->end() ) {
        lst->insert(std::pair<std::string, int>(str, 0));
    }
    lst->at(str) += 1;
}

bool TextHandler::isLetter(char symbol) {
    return ( symbol >= 'A' && symbol <= 'Z' ) || ( symbol >= 'a' && symbol <= 'z' );
}
bool TextHandler::isNumber(char symbol) {
    return symbol >= '0' && symbol <= '9';
}
bool TextHandler::isSpecial(char symbol) {
    bool special = false;

    if ( ( symbol > ' ' && symbol < '0' ) || ( symbol > '9' && symbol < 'A' ) ) {
        special = true;
    }
    if ( ( symbol > 'Z' && symbol < 'a' ) || ( symbol > 'z' && symbol <= '~' ) ) {
        special = true;
    }
    return special;
}
bool TextHandler::isWord(char symbol) {
    char special[] = {' ', ',', '.' , '!', '?', '\0'};
    
    for ( int i = 0; i < 6; i++ ) {
        if ( symbol == special[i] ) {
            return true;
        }
    }
    return false;
}

void TextHandler::parseText() {
    std::ifstream file(filename);
    int diff = 'a' - 'A';
    char symbol;
    std::string str;
    
    for ( ; file.get(symbol) ; ) {
        if ( isLetter(symbol) ) {
            if ( symbol < 'a' ) {
                symbol += diff;
            }
            insert(symbol, characters);
            insert(symbol, charactersStatistics);
            quantity += 1;
        }
        if ( isNumber(symbol) ) {
            insert(symbol, numbers);
            insert(symbol, numbersStatistics);
            quantity += 1;
        }
        if ( isSpecial(symbol) ) {
            insert(symbol, specialSymbols);
            insert(symbol, specialSymbolsStatistics);
            quantity += 1;
        }
        if ( isLetter(symbol) ) {
            str.push_back(symbol);
        }
        if ( isWord(symbol) ) {
            if ( !str.empty() ) {
                insert(str, words);
                insert(str, wordsStatistics);
                wordsQuantity += 1;
                str.clear();
            }
        }
    }
    
    file.close();
}

std::ostream& operator<<(std::ostream& out, const TextHandler& handler) {
    out << "Symbols found: " << handler.getQuantity() << std::endl;
    out << "Letters statistic:" << std::endl;
    out << "Unique: " << handler.getCharacters() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getCharactersStatistics() << std::endl;

    out << "Numbers statistic:" << std::endl;
    out << "Unique: " << handler.getNumbers() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getNumbersStatistics() << std::endl;

    out << "Special symbols statistic:" << std::endl;
    out << "Unique: " << handler.getSpecialSymbols() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getSpecialSymbolsStatistics() << std::endl;
    
    out << "Words statistic:" << std::endl;
    out << "Words quantity: " << handler.getWordsQuantity()<<std::endl;
    out << "Unique: " << handler.getWords() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getWordsStatistics() ;
    return out;
}
