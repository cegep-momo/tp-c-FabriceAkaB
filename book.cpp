#include "book.h"

#include <sstream>
#include <string>

using namespace std;

// ===== Constructors =====
Book::Book()
    : title(""),
      author(""),
      isbn(""),
      isAvailable(true),
      borrowerName("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title),
      author(author),
      isbn(isbn),
      isAvailable(true),
      borrowerName("") {}

// ===== Getters =====
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerName() const { return borrowerName; }

// ===== Setters =====
void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }
void Book::setISBN(const string& i) { isbn = i; }
void Book::setAvailability(bool available) { isAvailable = available; }
void Book::setBorrowerName(const string& name) { borrowerName = name; }

// ===== Methods =====
void Book::checkOut(const string& borrower) {
    // Ne fait l'emprunt que si disponible et nom non vide
    if (isAvailable && !borrower.empty()) {
        isAvailable = false;
        borrowerName = borrower;
    }
}

void Book::returnBook() {
    // Rendre = dispo et effacer l'emprunteur
    isAvailable = true;
    borrowerName.clear();
}

string Book::toString() const {
    // Texte lisible par l'utilisateur (utilisé dans main.cpp lors des recherches/affichages)
    ostringstream oss;
    oss << "Titre : " << title << "\n"
        << "Auteur : " << author << "\n"
        << "ISBN : " << isbn << "\n"
        << "Statut : " << (isAvailable ? "Disponible" : "Emprunté");
    if (!isAvailable && !borrowerName.empty()) {
        oss << "\nEmprunté par : " << borrowerName;
    }
    return oss.str();
}

string Book::toFileFormat() const {
    // Format fichier conforme à books.txt :
    // Disponible :  Title|Author|ISBN|1|
    // Emprunté   :  Title|Author|ISBN|0|Borrower
    ostringstream oss;
    oss << title << '|'
        << author << '|'
        << isbn << '|'
        << (isAvailable ? '1' : '0') << '|';
    if (!isAvailable && !borrowerName.empty()) {
        oss << borrowerName;
    }
    return oss.str();
}

void Book::fromFileFormat(const string& line) {
    // Parse d'une ligne Title|Author|ISBN|<0/1>|[Borrower]
    // Le champ emprunteur est optionnel si disponible=1
    string t, a, i, availStr, borrower;

    // On lit champ par champ avec '|' comme délimiteur
    // Remarque : si la ligne se termine par '|' (cas disponible=1), le dernier getline renverra ""
    stringstream ss(line);
    getline(ss, t, '|');
    getline(ss, a, '|');
    getline(ss, i, '|');
    getline(ss, availStr, '|');
    getline(ss, borrower); // peut être vide

    // Affectation avec valeurs par défaut prudentes
    title = t;
    author = a;
    isbn = i;

    // Disponibilité : "1" => true ; sinon false
    isAvailable = (availStr == "1");

    if (isAvailable) {
        borrowerName.clear();
    } else {
        borrowerName = borrower; // peut être vide si données incomplètes
    }
}
