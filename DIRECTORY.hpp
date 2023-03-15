#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <fstream>
#include <algorithm>

using string = std::string;

class Firms {
public:
    Firms() = default;

    Firms(string title, string owner, string phone, string adress, string occupation)
            : title_(std::move(title)), owner_(std::move(owner)), phone_(std::move(phone)), adress_(std::move(adress)),
              occupation_(std::move(occupation)) {};

    Firms(const Firms &firms) :
            Firms(firms.title_, firms.owner_, firms.phone_, firms.adress_, firms.occupation_) {}

    Firms &operator=(const Firms &firms) noexcept {
        Firms firms_copy(firms);
        this->swap(firms_copy);
        return *this;
    }

    ~Firms() = default;

    void swap(Firms &another) noexcept {
        using std::swap;

        swap(another.title_, title_);
        swap(another.owner_, owner_);
        swap(another.phone_, phone_);
        swap(another.adress_, adress_);
        swap(another.occupation_, occupation_);
    }

    void print() {
        std::cout << "1. Company name: " << title_ << std::endl;
        std::cout << "2. Owner: " << owner_ << std::endl;
        std::cout << "3. Phone: " << phone_ << std::endl;
        std::cout << "4. Address: " << adress_ << std::endl;
        std::cout << "5. Type of activity: " << occupation_ << std::endl;
        std::cout << std::endl;
    }

    void save() {
        std::ofstream file("Directory.txt", std::ios::app);
        if (file.is_open()) {
            file << title_ << ":::" << owner_ << ":::" << phone_ << ":::" << adress_ << ":::" << occupation_ << "\n";
        }
        file.close();
    }

    [[nodiscard]] const string &getTitle() const {
        return title_;
    }

    [[nodiscard]] const string &getOwner() const {
        return owner_;
    }

    [[nodiscard]] const string &getPhone() const {
        return phone_;
    }

    [[nodiscard]] const string &getAddress() const {
        return adress_;
    }

    [[nodiscard]] const string &getOccupation() const {
        return occupation_;
    }

private:
    string title_;
    string owner_;
    string phone_;
    string adress_;
    string occupation_;
};

class Directory {


public:
    Directory() = default;

    void add(const Firms &firms) {
        directory_.push_back(firms);
    }

    auto searchTitle(const string &title) {
        return (std::find_if(directory_.begin(), directory_.end(),
                             [title](const Firms &firms) {
                                 return title == firms.getTitle();
                             }));
    }

    auto searchOwner(const string &owner) {
        return (std::find_if(directory_.begin(), directory_.end(),
                             [owner](const Firms &firms) {
                                 return owner == firms.getOwner();
                             }));
    }

    auto searchPhone(const string &phone) {
        return (std::find_if(directory_.begin(), directory_.end(),
                             [phone](const Firms &firms) {
                                 return phone == firms.getPhone();
                             }));
    }

    auto searchAddress(const string &adress) {
        return (std::find_if(directory_.begin(), directory_.end(),
                             [adress](const Firms &firms) {
                                 return adress == firms.getAddress();
                             }));
    }

    auto searchOccupation(const string &occupation) {
        return (std::find_if(directory_.begin(), directory_.end(),
                             [occupation](const Firms &firms) {
                                 return occupation == firms.getOccupation();
                             }));
    }

    void Print() {
        for (auto firms: directory_) {
            firms.print();
        }
    }

    void Save() {
        std::ofstream file("Directory.txt", std::ios::out);
        if (file.is_open()) {
            for (auto firms: directory_) {
                file << firms.getTitle() << ":::" << firms.getOwner() << ":::" << firms.getPhone() << ":::"
                     << firms.getAddress() << ":::" << firms.getOccupation() << "\n";
            }
            file.close();
        }
    }

private:
    std::vector<Firms> directory_;

};

#endif //DIRECTORY_H