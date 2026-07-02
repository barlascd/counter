#include <iostream>
#include <map>
#include <string>
#include "counte.h"

int main() {
    std::cout << "Welcome to your digital accountant\n";
    std::map<std::string, int> incomes;
    std::map<std::string, int> outcomes;
    
    bool yes = true;
    
    
    std::cout << "Please give the incomes names and quantities. If you are finished, please write 'yes' when asked.\n";
    while (yes) {
        std::string name;
        int quant;
        std::cout << "Please give the name of income of firm: ";
        std::cin >> name;
        std::cout << "Please give the quantity of income of firm: ";
        std::cin >> quant;
        incomes[name] = quant;
        
        std::string orno;
        std::cout << "Are you finished? Please print yes or no: ";
        std::cin >> orno;
        if (orno == "yes") {
            yes = false;
        }
    }
    
    
    yes = true; 
    std::cout << "Please give the outcomes names and quantities.\n";
    while (yes) {
        std::string name;
        int amount;
        std::cout << "Please give name of outcome except taxes: ";
        std::cin >> name;
        std::cout << "Please give the amount of outcome: ";
        std::cin >> amount;
        outcomes[name] = amount;
        
        std::string orno;
        std::cout << "Are you finished? Please write yes or no: ";
        std::cin >> orno;
        if (orno == "yes") {
            yes = false;
        }
    }
    
    int totalIn = 0; 
    int totalOut = 0; 
    
    for (auto const& pair : incomes) {
        totalIn = sum(totalIn, pair.second);
    }
    for (auto const& pair : outcomes) {
        totalOut = sum(totalOut, pair.second);
    }
    
    int total = dimun(totalIn, totalOut);
    
    std::cout << "Your total incomes are: " << totalIn << std::endl;
    std::cout << "Your total outcomes are: " << totalOut << std::endl;
    std::cout << "Your total (before taxes) is: " << total << std::endl;
    
    
    int taxesAmount = 0;
    std::map<std::string, int> taxes;
    yes = true; 
    
    while (yes) {
        std::string name;
        int percentage;
        std::cout << "Please give the name of taxes: ";
        std::cin >> name;
        std::cout << "Please give the percentage of taxes: ";
        std::cin >> percentage;
        taxes[name] = percentage;
        
        std::string orno;
        std::cout << "Are you finished with taxes? Please write yes or no: ";
        std::cin >> orno;
        if (orno == "yes") {
            yes = false;
        }
    }
    
    for (auto const& pair : taxes) {
       
        taxesAmount = sum(taxesAmount, divide(mult(totalIn, pair.second), 100));
    }
    
    std::cout << "The taxes amount is: " << taxesAmount << std::endl;
    
    
    total = dimun(total, taxesAmount);
    std::cout << "After the outcomes and taxes calculation, the final total of the firm is: " << total << std::endl;
    
    return 0;
}