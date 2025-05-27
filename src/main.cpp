#include <iostream>

const short sconto = 10;

// Modifica con i nomi desiderati
const std::string amici[] = {
    "Marco",
    "Paolo",
    "Giuseppe",
    "Luca",
    "Mario",
    "Giorgio",
    "Giulia",
    "Giovanni",
    "Giacomo",
    "Denis",
    "Raffaele",
    "Daniel"
};

struct Prodotto {
    std::string nome;
    float prezzo;
};

const Prodotto prodotti[] = {
    { "Coca Cola", 2.50f },
    { "Fanta", 2.00f },
    { "Sprite", 1.75f },
};

int main() {
    std::string nome;
    std::string scelta;

    bool scontato = false;

    std::cout << "Ciao, come ti chiami? ";
    std::cin >> std::ws >> nome;

    for (short i = 0; i < std::size(amici); i++) {
        if (nome == amici[i]) {
            std::cout << "Ciao " << amici[i] << " oggi avrai uno sconto del " << sconto << "%!" << std::endl;
            scontato = true;

            break;
        }

        if (i == std::size(amici) - 1) {
            std::cout << "Benvenuto " << nome << std::endl;
        }
    }

    for (short i = 0; i < std::size(prodotti); i++) {
        if (scontato) {
            std::cout << prodotti[i].nome << ": €" << (prodotti[i].prezzo - ((prodotti[i].prezzo * sconto) / 100)) << std::endl;
        } else {
            std::cout << prodotti[i].nome << ": €" << prodotti[i].prezzo << std::endl;
        }
    }

    std::cout << "Quale scegli? ";
    std::getline(std::cin >> std::ws, scelta);

    for (short i = 0; i < std::size(prodotti); i++) {
        if (scelta == prodotti[i].nome) {
            if (scontato) {
                std::cout << "Mi devi €" << (prodotti[i].prezzo - ((prodotti[i].prezzo * sconto) / 100)) << std::endl;
            } else {
                std::cout << "Mi devi €" << prodotti[i].prezzo << std::endl;
            }

            break;
        }

        if (i == std::size(prodotti) - 1) {
            std::cout << "Non valido!" << std::endl;
        }
    }

    return 0;
}