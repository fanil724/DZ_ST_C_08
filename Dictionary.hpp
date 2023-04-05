#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <map>
#include <fstream>

using string = std::string;

class Dictionary {
public:
    Dictionary() = default;

    ~Dictionary() = default;

    void add(const string S) {
        if (dictionary_.empty()) {
            dictionary_.insert(std::pair<string, int>(S, 1));
        } else if (dictionary_.contains(S)) {
            dictionary_[S] += 1;
        } else {
            dictionary_.insert(std::pair<string, int>(S, 1));
        }
    }

    void Erase(string &s) {
        for (int i = 0; i < s.length(); i++) {
            for (char j: simbols) {
                if (s[i] == j) {
                    s.erase(i, 1);
                    i--;
                }
            }
        }
    }

    void print() {
        for (const auto &i: dictionary_) {
            std::cout << i.first << " - " << i.second << "\n";
        }
        std::cout << std::endl;
    }

    void save() {
        std::ofstream file("Save_Dictionary.txt", std::ios::app);
        if (file.is_open()) {
            for (const auto &i: dictionary_) {
                file << i.first << ":::" << i.second << "\n";
            }
        }
        file.close();
    }

    void printWord() {
        auto pr = std::max_element(dictionary_.begin(), dictionary_.end(), [](const auto &x, const auto &y) {
            return x.second < y.second;
        });
        std::cout << pr->first << " - " << pr->second << std::endl;
    }

    void read() {
        string s, slovo;
        std::fstream file("Dictionary.txt", std::ios::in);
        if (file.is_open()) {
            while (getline(file, s)) {
                do {
                    slovo = s.substr(0, s.find(' '));
                    Erase(slovo);
                    if (s.find(' ', 0) == -1) {
                        s.clear();
                    } else {
                        s.erase(0, s.find(' ', 0) + 1);
                    }
                    add(slovo);
                } while (!s.empty());
            }
        }
        file.close();
    }

private:
    std::map<string, int> dictionary_;
    const string simbols = ",.?!|{}[];'<>@#$^&*()";
};

#endif //DICTIONARY_H