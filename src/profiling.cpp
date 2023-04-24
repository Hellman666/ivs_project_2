#include <iostream>
#include <vector>

#include "includes/math.h"

double vypocet_prumeru(std::vector<double> numbers, size_t size) {
    double s = 0;
    for (size_t i = 0; i < size; ++i) s = sum(s, numbers.at(i));
    return div(s, size);
}

double vypocet_smerodatne_odchylky(std::vector<double> numbers, size_t size) {
    double prumer = mul(size, power(vypocet_prumeru(numbers, size), 2));
    double s = 0;
    for (int i = 0; i < size; ++i) s = sum(s, power(numbers.at(i), 2));
    return root(mul(sub(s, prumer), size - 1), 2);
}

int main(int argc, char const *argv[]) {
    std::vector<double> numbers;
    double n;
    if (argc > 1) {
        while (std::cin >> n) {
            numbers.push_back(n);
        }
    } else {
        // pokud není zadán soubor s čísly
        if (numbers.size() == 0) {
            for (size_t i = 0; i < 1000; i++) {
                numbers.push_back(i);
            }
        }
    }
    // double numbers[] = {1, 2, 3, 4, 5};
    double smerodatna_odchylka = vypocet_smerodatne_odchylky(numbers, numbers.size());
    std::cout << "Odchylka: " << smerodatna_odchylka << std::endl;
    return 0;
}
