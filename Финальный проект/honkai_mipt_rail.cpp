#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Шаблон для сложения трёх элементов одного типа
template <typename T>
T summ(T& first_elem, T& second_elem, T& third_elem) {
    T result = first_elem + second_elem + third_elem;
    return result;
}

// Абстрактный базовый класс для магических существ
class Beastes {
public:
    int health;
    int shield;
    int psi_abilities;
    int stamina;
    string name;

    virtual void info() = 0;  // Абстрактный метод для отображения информации о существе
};

// Абстрактный базовый класс для заклинаний
class MagicSpell {
public:
    string name;
    int protection;
    int damage;
    int psi_effect;
    int stamina_effect;
    int level = 2;         // Уровень заклинания (по умолчанию 2)
    int speed;             // Скорость заклинания

    // Абстрактный метод для применения заклинания
    virtual void ability(Beastes*) = 0;

    void info() {
        cout << name;
    }

    // Друзья:) MagicBook дружит с MagicSpell
    friend class MagicBook;
};

// Заклинание для атаки
class Heart_Afire : public MagicSpell {
public:
    Heart_Afire() {
        name = "Heart_Afire";
        damage = 100;  // Урон
        speed = 5;     // Скорость заклинания
        stamina_effect = -5; // Ослабление заклинания
    }

    void ability(Beastes* x) {
        x->health -= damage;  // Уменьшаем здоровье
    }
};

// Заклинание защиты
class CornerstoneDeluxe : public MagicSpell {
public:
    CornerstoneDeluxe() {
        name = "Cornerstone Deluxe";
        protection = 10;
        speed = 3;  // Скорость заклинания
    }

    void ability(Beastes* x) {
        x->shield += protection;
    }
};

// Заклинание для восстановления пси-способностей
class TALISMANS_TALISMANS_Protection : public MagicSpell {
public:
    TALISMANS_TALISMANS_Protection() {
        name = "TALISMANS_TALISMANS_Protection";
        psi_effect = 5;
        stamina_effect = 50; // Повышение выносливости носителя
        speed = 4;  // Скорость заклинания
    }

    void ability(Beastes* x) {
        x->psi_abilities += psi_effect;
    }
};

// Непростительное заклинание
class Florephemeral_Dreamflux : public MagicSpell {
public:
    Florephemeral_Dreamflux() {
        name = "Florephemeral_Dreamflux";
        damage = 1000;  // Очень сильный урон
        speed = 2;      // Очень медленное заклинание
    }

    void ability(Beastes* x) {
        x->health -= damage;  // Наносим урон цели
    }
};

// Класс для книги заклинаний
class MagicBook {
public:
    string name;              // Название
    int pages;                // Количество страниц
    MagicSpell** m_spells;    // Массив заклинаний
    int array_length;         // Количество заклинаний

    MagicBook(string n, MagicSpell** sp, int s) {
        name = n;
        m_spells = sp;
        array_length = s;
    }

    void info() {
        cout << "Name: " << name << "\n";
        cout << " THE Herta spells: \n";
        for (int i = 0; i < array_length; i++) {
            m_spells[i]->info();
            cout << "\n";
        }
    }
};

// Класс для Ведьмы
class Witch : public Beastes {
public:
    int level;

    Witch(string n, int l, int h, int p, int mh, int s) {
        name = n;
        level = l;
        health = h;
        shield = p;
        psi_abilities = mh;
        stamina = s;
    }

    void info() {
        cout << "Name: " << name << '\n';
        cout << "Health: " << health << '\n';
        cout << "Shield: " << shield << '\n';
        cout << "Psi Abilities: " << psi_abilities << '\n';
        cout << "Stamina: " << stamina << '\n';
    }

    void use(MagicBook* book, int num, Beastes* target) {
        if (book->m_spells[num]->level <= level) {
            book->m_spells[num]->ability(target);
        } else {
            throw runtime_error("Недостаточный уровень для использования заклинания");
        }
    }
};

// Класс для Мага 
class Mage : public Beastes {
public:
    int level;

    Mage(string n, int l, int h, int p, int mh, int s) {
        name = n;
        level = l;
        health = h;
        shield = p;
        psi_abilities = mh;
        stamina = s;
    }

    void info() {
        cout << "Name: " << name << '\n';
        cout << "Health: " << health << '\n';
        cout << "Shield: " << shield << '\n';
        cout << "Psi Abilities: " << psi_abilities << '\n';
        cout << "Stamina: " << stamina << '\n';
    }

    void use(MagicBook* book, int num, Beastes* target) {
        if (book->m_spells[num]->level <= level) {
            book->m_spells[num]->ability(target);
        } else {
            throw runtime_error("Недостаточный уровень для использования заклинания");
        }
    }
};

// Функция для подбрасывания кости
int drop_the_dice() {
    srand(time(0));
    return rand() % 6 + 1;  // Возвращает число от 1 до 6
}

// Считывание заклинаний из файла
vector<string> get_spells_from_file(int dice_roll) {
    string filename = to_string(dice_roll) + ".txt";
    vector<string> spells;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла " << filename << endl;
        return spells;
    }

    string spell;
    while (getline(file, spell)) {
        spells.push_back(spell);
    }

    file.close();
    return spells;
}

// Дуэль между магом и ведьмой
void duel(Beastes* fighter1, Beastes* fighter2, MagicBook* book1, MagicBook* book2) {
    vector<MagicSpell*> spells1(book1->m_spells, book1->m_spells + book1->array_length);
    vector<MagicSpell*> spells2(book2->m_spells, book2->m_spells + book2->array_length);

    // Сортируем заклинания по скорости
    sort(spells1.begin(), spells1.end(), [](MagicSpell* a, MagicSpell* b) {
        return a->speed > b->speed;
    });
    sort(spells2.begin(), spells2.end(), [](MagicSpell* a, MagicSpell* b) {
        return a->speed > b->speed;
    });

    cout << fighter1->name << " vs " << fighter2->name << "\n";

    while (fighter1->health > 0 && fighter2->health > 0) {
        int dice1 = drop_the_dice();  // Подбрасывание кости для первого 
        int dice2 = drop_the_dice();  // Подбрасывание кости для второго

        cout << fighter1->name << " подбрасывает кость и выпадает " << dice1 << "\n";
        vector<string> spells1 = get_spells_from_file(dice1);
        cout << "Доступные заклинания для " << fighter1->name << ":\n";
        for (int i = 0; i < spells1.size(); i++) {
            cout << i+1 << ". " << spells1[i] << "\n";
        }

        int choice1;
        cin >> choice1;
        // Применить выбранное заклинание на противника
        // Здесь необходимо привязать строку с заклинанием к объекту заклинания

        cout << fighter2->name << " подбрасывает кость и выпадает " << dice2 << "\n";
        vector<string> spells2 = get_spells_from_file(dice2);
        cout << "Доступные заклинания для " << fighter2->name << ":\n";
        for (int i = 0; i < spells2.size(); i++) {
            cout << i+1 << ". " << spells2[i] << "\n";
        }

        int choice2;
        cin >> choice2;
        // Применить выбранное заклинание на противника

        // Повторить цикл, пока у одного из бойцов не закончится здоровье
    }

    if (fighter1->health <= 0) {
        cout << fighter2->name << " победил(а)!\n";
    } else {
        cout << fighter1->name << " победил(а)!\n";
    }
}

int main() {
    Mage mage("Валтор", 5, 1000, 50, 200, 100);
    Witch witch("Герта", 5, 900, 30, 150, 80);

    // Создаем заклинания
    MagicSpell* heart = new Heart_Afire();
    MagicSpell* cornerstone = new CornerstoneDeluxe();
    MagicSpell* talismans = new TALISMANS_TALISMANS_Protection();

    MagicSpell* spells[] = {heart, cornerstone, talismans};

    MagicBook* book1 = new MagicBook("Mage's Spellbook", spells, 3);

    // Создаем заклинания для ведьмы
    MagicSpell* florephemeral = new Florephemeral_Dreamflux();
    MagicSpell* spells2[] = {florephemeral};

    MagicBook* book2 = new MagicBook("Witch's Spellbook", spells2, 1);

    // Дуэль между магом и ведьмой
    duel(&mage, &witch, book1, book2);

    return 0;
}
