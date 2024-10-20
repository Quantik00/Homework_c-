#include <iostream>
#include <string>

using namespace std;

class Student 
{
private:
    const string firstName;
    const string lastName;
    int group;
    int grade;
    int XP;
    double money;
    int studentTime;
    int dayTime;

public:
    // Конструктор с вводом оценки
    Student(const string &fName, const string &lName, int group, int gr)
        : firstName(fName), lastName(lName), group(group), grade(gr), XP(100), money(100), studentTime(0), dayTime(24) {}
    
    // Конструктор с оценкой 10 по умолчанию
    Student(const string &fName, const string &lName, int group)
        : firstName(fName), lastName(lName), group(group), grade(10), XP(7), money(10000), studentTime(2), dayTime(24) {}
    
    // Метод еда (*)^(*)
    void eat(int xpUP, double cost)
    {
        if (money >= cost) 
        {
            XP += xpUP;
            money -= cost;
            dayTime -= 1;
        }
        else 
        {
            cout << "Error: недостаточно средств, идите работать! >_<" << endl;
        }
    }

    // Метод учёба...
    void study(int hours, int xpDOWN)
    {
        if (studentTime + hours > 24) // время студента
        {
            XP -= xpDOWN * 3;
        } 
        else {
            XP -= xpDOWN;
        }
        studentTime += hours;
        dayTime -= hours;
    }

    // Метод спат ... zzz
    void sleep(int hours) 
    {
        if (hours > 6) 
        {
            studentTime = 0;
        }
        XP += hours * 10;
        dayTime -= hours;
    }
    // Метод Work work work work work work 
    void work(int hours, double sbereg, int xpDOWN) 
    {
        if (studentTime + hours > 24) 
        {
            XP -= xpDOWN * 3;
        } 
        else
        {
            XP -= xpDOWN;
        }   
        money += sbereg;
        studentTime += hours;
        dayTime -= hours;
    }

    // Метод Невероятный_Кайф 
    void nk(int hours, double cost, int xpUP) {
        if (money >= cost) {
            if (studentTime + hours > 24) {
                XP += xpUP / 3;
            } else {
                XP += xpUP;
            }
            money -= cost;
            studentTime += hours;
            dayTime -= hours;
        } 
        else 
        {
            cout << "Ошибка: недостаточно денег!" << endl;
        }
    }

    int getLife() const 
    {
        return XP;
    }

    double getMoney() const
    {
        return money;
    }

    int getRemainingTime() const
    {
        return dayTime;
    }

    void displayInfo() const 
    {
        cout << "Имя: " << firstName << endl;
        cout << "Фамилия: " << lastName << endl;
        cout << "Группа: " << group << endl;
        cout << "Оценка: " << grade << endl;
        cout << "XP: " << XP << endl;
        cout << "Деньги: " << money << endl;
        cout << "Время студента: " << studentTime << endl;
        cout << "Время " << dayTime << endl;
    }

    void checkLife() const
    {
        if (XP <= 0) 
        {
            cout << "Ушёл в академ \/_\/" << endl;
        }
    }
};

int main() 
{
    Student s1("Макарэн", "Иванов", 305, 9);
    s1.eat(20, 10);
    s1.study(3, 10);
    s1.work(5, 50, 15);
    s1.sleep(7);
    s1.nk(2, 15, 30);

    s1.displayInfo();
    s1.checkLife();

    return 0;
}
