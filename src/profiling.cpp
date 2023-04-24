#include<iostream>
#include "includes/math.h"

double vypocet_prumeru(double arr[], double size) {
    double s = 0;
    for (int i = 0; i < size; ++i) s = sum(s, arr[i]);
    return div(s, size);
}

double vypocet_smerodatne_odchylky(double arr[], double size) {
    double prumer = vypocet_prumeru(arr, size);
    double s = 0;
    for (int i = 0; i < size; ++i) s = sum(s, power(sub(arr[i], prumer), 2));
    return root(div(s, sub(size, 1)), 2);
}

int main() {
    double numbers[] = {1, 2, 3, 4, 5};
    double size = div((double)sizeof(numbers), (double)sizeof(numbers[0]));
    double smerodatna_odchylka = vypocet_smerodatne_odchylky(numbers, size);
    std::cout << "Výběrová směrodatná odchylka: " << smerodatna_odchylka << std::endl;
    return 0;
}
