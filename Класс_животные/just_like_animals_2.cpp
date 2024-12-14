#include <iostream>
using namespace std;
#define animal_amount 3 // количество животных

// Абстрактный класс для животных, то есть абстрация
class Animal {
public:
    virtual void emitSound() = 0; // Чистая виртуальная функция для издания звука
};

// Класс кошки
class Cat: public Animal {
private:
    string petName;  
    int petAge;      
    string species;  
    int health;      

public:
    // Переопределение звука для кошки
    void emitSound() { 
        cout << "Moor_Meow!!!" << "\n";      
    }

    // Конструктор для кошки (фабрика)
    Cat(string name, int age, string breed) {
        petName = name;
        petAge = age;
        species = breed;
        health = 90;
    }

    // Конструктор по умолчанию для кошки
    Cat() {
        petName = "Борис";
        petAge = 7;
        species = "той-бобтейл";
        health = 70;
    }

    // Вывод информации о питомце
    void showDetails() {
        cout << "Имя: " << petName << "\n";
        cout << "Возраст: " << petAge << "\n";
        cout << "Порода: " << species << "\n";
        cout << "\n";
    }

    // Вывод здоровья
    void displayHealth() {
        cout << "Здоровье (число жизней): " << health << "\n";
    }

    // Дружеский класс для ветеринара
    friend class Veterinarian;
};

// Класс собаки
class Dog: public Animal {
private:
    string petName; 
    int petAge;     
    string breed;    
    int health;     

public:
    // Переопределение звука для собаки
    void emitSound() { 
        cout << "Woof woof!!!" << "\n";      
    }

    // Конструктор для собаки (фабрика)
    Dog(string name, int age, string breedType) {
        petName = name;
        petAge = age;
        breed = breedType;
        health = 90;
    }

    // Конструктор по умолчанию для собаки
    Dog() {
        petName = "Дендзи";
        petAge = 17;
        breed = "Трудно";
        health = 1;
    }

    // Вывод информации о питомце
    void showDetails() {
        cout << "Имя: " << petName << "\n";
        cout << "Возраст: " << petAge << "\n";
        cout << "Порода: " << breed << "\n";
        cout << "\n";
    }

    // Вывод здоровья
    void displayHealth() {
        cout << "Здоровье: " << health << "\n";
    }

    // Дружеский класс для ветеринара
    friend class Veterinarian;
};

// Структура для хранения имени и фамилии владельца
struct PersonName {
    string firstName = "Geto";  
    string lastName = "Suguru";  
};

// Класс владельца питомцев
class PetOwner {
private:
    PersonName nameDetails;  
    int ownerAge;           
public:
    Cat feline1;  
    Cat feline2;  
    Dog canine;   

    // Конструктор для владельца
    PetOwner(string first, string last, int age, Cat pet1, Cat pet2, Dog pet3) {
        nameDetails = PersonName{first, last};
        ownerAge = age;
        feline1 = pet1;
        feline2 = pet2;
        canine = pet3;            
    }

    // Функция для отображения информации о владельце и питомцах
    void displayOwnerInfo() {
        cout << "Хозяин: " << nameDetails.firstName << " " << nameDetails.lastName << '\n';
        cout << "Возраст: " << ownerAge << "\n";
        cout << "Количество питомцев: " << animal_amount << "\n";
        cout << "\n";
        cout << "Первый питомец (кошка): \n";
        feline1.showDetails();
        cout << "Второй питомец (кошка): \n";
        feline2.showDetails();
        cout << "Третий питомец (собака): \n";
        canine.showDetails();
    }

    // Дружеский класс для ветеринара, (это паттерн)
    friend class Veterinarian;
};

// Класс для ветеринара
class Veterinarian {
private:
    PersonName nameDetails;  
public:
    // Конструктор для ветеринара
    Veterinarian(string first, string last) {
        nameDetails = PersonName{first, last};
    }

    // Лечение кошек
    void treat(Cat* pet) {
        pet->health += 70; 
    }

    // Лечение собак
    void treat(Dog* pet) {
        pet->health += 15;  
    }

    // Коммуникация с владельцем
    void talk(PetOwner& owner) {
        cout << "Здравствуй, " << owner.nameDetails.firstName << " " << owner.nameDetails.lastName 
             << "! Я вылечил твоих питомцев!" << "\n";
    }
};

// Основная функция
int main() {
    // Ввод данных владельца
    cout << "Введите имя владельца, фамилию и возраст: \n";
    string firstName, lastName;
    int age;
    cin >> firstName >> lastName >> age;
    cout << "\n";

    // Ввод данных питомцев
    cout << "Введите данные для первого питомца (имя, возраст, порода): \n";
    string pet1Name, pet1Breed;
    int pet1Age;
    cin >> pet1Name >> pet1Age >> pet1Breed;
    cout << "\n";

    cout << "Введите данные для второго питомца (имя, возраст, порода): \n";
    string pet2Name, pet2Breed;
    int pet2Age;
    cin >> pet2Name >> pet2Age >> pet2Breed;
    cout << "\n";

    cout << "Введите данные для третьего питомца (имя, возраст, порода): \n";
    string pet3Name, pet3Breed;
    int pet3Age;
    cin >> pet3Name >> pet3Age >> pet3Breed;
    cout << "\n";

    // Создание объектов питомцев и владельца
    Cat firstCat(pet1Name, pet1Age, pet1Breed);
    Cat secondCat;
    Dog thirdDog(pet3Name, pet3Age, pet3Breed);

    PetOwner
    // Создание объекта владельца
    PetOwner owner(firstName, lastName, age, firstCat, secondCat, thirdDog);

    // Создание объекта ветеринара
    Veterinarian vet("Иван", "Иванов");

    // Вывод информации о владельце и его питомцах
    owner.displayOwnerInfo();

    // Лечение питомцев
    vet.treat(&firstCat); //(команда?)
    vet.treat(&secondCat);
    vet.treat(&thirdDog);

    // После лечения, вывод информации о питомцах
    cout << "\nПосле лечения:\n";
    owner.feline1.displayHealth();
    owner.feline2.displayHealth();
    owner.canine.displayHealth();

    // Общение с владельцем
    vet.talk(owner);

    return 0;
}