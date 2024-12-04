#include <iostream>
using namespace std;  

// Шаблон для сложения двух элементов одного типа
template <typename T> T summ(T& first_elem, T& second_elem) {
    T result = first_elem + second_elem;  
    return result;
}

// Абстрактный базовый класс для магических существ 
class Beastes {
public:
    int health;           
    int shield;          
    int psi_abilities;     
    int stamina;           
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

    // Абстрактный метод для применения заклинания 
    virtual void ability(Beastes*) = 0;  

    void info() {
        cout << name;
    }

    // Друзья:)  MagicBook дружит с MagicSpell
    friend class MagicBook;
};

// Заклинание для атаки 
class Heart_Afire : public MagicSpell {
public:
    Heart_Afire() {
        name = "Heart_Afire";
        damage = 100;  // Урон
        stamina = -5; // Ослабление заклинания
    }

    // Реализация способности заклинания
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
    }

    // Реализация щита
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
        stamina = 50; // Повышение выносливости носителя
    }

    // Реализация 
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
        stamina = 0; // полное отсутсвие сил 
    }

    // Реализация способности заклинания: наносит значительный урон цели
    void ability(Beastes* x) {
        x->health -= damage;  // Наносим урон цели
    }
};

// Комбинирование
class UpSpell : public MagicSpell {
    MagicSpell* one;  // Первое заклинание
    MagicSpell* two;  // Второе 
    MagicSpell* three; // третье
public:
    UpSpell(MagicSpell* frst, MagicSpell* sknd, MagicSpell* thrd) {
        one = frst;
        two = sknd;
        three = thrd;
        name = summ(one->name, two->name, three->name);  // Название - объединение двух имен
        damage = summ(one->damage, two->damage, three->damage);  // Суммарный урон
        stamina_effect = summ(one->stamina_effect, two->stamina_effect,three->stamina_effect );  // Суммарный эффект на выносливость
    }

    // Применение объединенного заклинания
    void ability(Beastes* x) {
        one->ability(x);  
        two->ability(x);  
        three->ability(x);         
    }
};

// Класс для книги заклинаний
class MagicBook {
public:
    string name;              // Название 
    int pages;                // Количество страниц 
    MagicSpell** m_spells;    // Массив заклинаний
    int array_length;         // Количество заклинаний 

    // Конструктор для инициализации книги 
    MagicBook(string n, MagicSpell** sp, int s) {
        name = n;
        m_spells = sp;
        array_length = s;
    }

    // Отображение информации о книге 
    void info() {
        cout << "Name: " << name << "\n";
        cout << " THE Herta spells: \n";
        for (int i = 0; i < array_length; i++) {
            m_spells[i]->info();  // Выводим информацию о каждом заклинании
            cout << "\n";
        }
    }

    // Метод для улучшения книги заклинаний путем объединения 
    void upgrade(MagicSpell* one, MagicSpell* two, MagicSpell* three ) {
        m_spells[array_length] = new UpSpell(one, two, three);  // Добавляем объединенное заклинание в конец списка
        array_length += 1;  // Увеличиваем количество заклинаний
    }
};

// Класс для ведьмы, которая может использовать заклинания из книги
class Witch : public Beastes {
public:
    string name;  // Имя
    int level;    // Уровень 

    // Конструктор ведьмы
    Witch(string n, int l, int h, int p, int mh, int s) {
        name = n;
        level = l;
        health = h;
        shield = p;
        psi_abilities = mh;
        stamina = s;
    }

    // Отображение информации о ведьме
    void info() {
        cout << "Name: " << name << '\n';
        cout << "Health: " << health << '\n';
        cout << "Shield: " << shield << '\n';
        cout << "Psi Abilities: " << psi_abilities << '\n';
        cout << "Stamina: " << stamina << '\n';
    }

    // Метод для использования заклинания 
    void use(MagicBook* book, int num, Beastes* target) {
        if (book->m_spells[num]->level <= level) {  // Проверка, если уровень заклинания подходит 
            book->m_spells[num]->ability(target);  // Применяем заклинание к цели
        } else {
            throw(1);  // недостаточный уровень для использования заклинания
        }
    }
};

int main() {
    Witch witch = Witch(" THE Herta", 83, 3500, 1050, 35000, 140); // Создаем ведьму 
    Witch test_object = Witch("Punching bag", 0, 100, 100, 100, 50); // объект для тестирования заклинаний

    cout << "How many THE Herta's secrets do you know? \n";
    int number_of_spells;
    cin >> number_of_spells;

    MagicSpell** list_of_spells = new MagicSpell*[number_of_spells];  
    cout << "Write the capital letters of the spells:";

    string n;  

    try {    // Попытка ввода 
        for (int i = 0; i < number_of_spells; i++) {
            cin >> n;  // Ввод имени заклинания
            if (n == "Its_Magic") {
                list_of_spells[i] = new Heart_Afire();  // Заклинание для атаки
            }
            else if (n == "One_Time_Offer") {
                list_of_spells[i] = new CornerstoneDeluxe();  // Заклинание для защиты
            }
            else if (n == "	It_Can_Still_Be_Optimized") {
                list_of_spells[i] = new TALISMANS_TALISMANS_Protection();  // Заклинание для восстановления пси-способностей
            }
            else {
                throw(2);  // Исключение: нет такого
            }
        }
    }
    catch (int x) {  
        if (x == 1) cout << "You have to be stronger, it can still be optimized";
        if (x == 2) cout << "Ohh... U surtanly do smth wrong, ask νοῦς about this.";
    }

    MagicBook* book_of_magic = new MagicBook("THE Herta", list_of_spells, number_of_spells);  // Книга заклинаний

    book_of_magic->info();  // Вывод информации о заклинаниях в книге

    return 0;
}