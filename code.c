#include <iostream>
#include <map>
#include <iomanip>
#include <string>

std::map<std::string, double> exchangeRates = {
    {"USD", 1.0},
    {"EUR", 0.85},
    {"GBP", 0.72},
    {"JPY", 110.50}
};

void printSquareBox(const std::string& text, int width = 70) {
    int length = text.length() + 2;
    int padding = (width - length) / 2;

    std::string horizontalLine(width, '-');
    std::string paddingSpace(padding, ' ');

    std::cout << horizontalLine << std::endl;
    std::cout << "|" << paddingSpace << text << paddingSpace << "|" << std::endl;
    std::cout << horizontalLine << std::endl;
    std::cout << std::endl;
}

void displayCurrencies() {
    std::string currencies;
    for (const auto& pair : exchangeRates) {
        currencies += pair.first + " ";
    }
    printSquareBox("Available currencies: " + currencies);
}

double convertCurrency(double amount, const std::string& fromCurrency, const std::string& toCurrency) {
    double fromRate = exchangeRates[fromCurrency];
    double toRate = exchangeRates[toCurrency];
    return (amount / fromRate) * toRate;
}

int main() {
    printSquareBox("\tCURRENCY CONVERTER", 80);

    std::string fromCurrency, toCurrency;
    double amount;

    displayCurrencies();
    
    std::cout << "\t";
    std::cout << "Enter source currency: ";
    std::cin >> fromCurrency;
    std::cout << "\t";
    std::cout << "Enter target currency: ";
    std::cin >> toCurrency;
    std::cout << "\t";
    std::cout << "Enter amount: ";
    std::cin >> amount;

    if (exchangeRates.find(fromCurrency) == exchangeRates.end() ||
        exchangeRates.find(toCurrency) == exchangeRates.end()) {
        printSquareBox("Invalid currency codes.");
        return 1;
    }

    double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);

    printSquareBox("Conversion Result");
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "- " << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << " -" << std::endl;

    return 0;
}

