#include <string>
#include <iostream>

using namespace std;

void obzac()
{
    cout << "\n\n//============================================================================//\n\n";
}
//task1
class Person
{
private:
    static int count;
protected:
    string n_name;
    int n_age;
    string n_sex;
    int n_wight;
public:
    static int GetCount() { return count; } 
    
    Person(const string& name, const int& age, const string& sex, const int& wight)
        : n_name(name), n_age(age), n_wight(wight), n_sex(sex)
    {
        count++; 
    }

    string GetName() { return n_name; } 
    int GetAge() { return n_age; }
    int GetWighr() { return n_wight; }
    virtual void Print()  
    {
        cout << n_name << ' ' << n_age << ' ' << n_sex << ' ' << n_wight << endl;
    }
};

class Student : public Person 
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& sex, const int wight)
        :Person(name, age, sex, wight), n_year(year) {}

    int GetYear() { return n_year; } 
    void AddYear(int addValue) 
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++; 
    }
    void Print()
    {
        cout << n_year << ' ';
        Person::Print();
    }
};
//task2
class Fruit
{
public:
    string name;
    string color;

    Fruit(string name, string color) : name(name), color(color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};

class Banana : public Fruit
{
public:
    Banana(string name = "Banana", string color = "Yellow") : Fruit(name, color) {}

};

class Apple : public Fruit
{
public:
    Apple(string name = "Apple", string color = "Red") : Fruit(name, color) {}

};

class GrannySmith : public Apple
{
public:
    GrannySmith(string name = "Granny Smith", string color = "Green") : Apple(name, color) {}
};

void Blackjack()
{
    cout << "\nСоздаем классы: Dealer, Player, Hands(Руки), Deck(Колода), Deckpile(Раздача карт).";
    cout << "\nDealer, Player классы базовые, остальные производные.";
}


int Person::count = 0;

int main()
{

    setlocale(LC_ALL, "rus");
    {
        
        obzac();
        auto student1 = new Student(6, "Smith", 24, "male", 60);
        auto student2 = new Student(4, "Oleg", 24, "female", 63);
        auto student3 = new Student(4, "Dmitry", 25, "male", 70);
        auto student4 = new Student(1, "Danya", 15, "female", 56);
        auto student5 = new Student(2, "Volodya", 34, "male", 53);
        student1->Print();
        student2->Print();
        student3->Print();
        student4->Print();
        student5->Print();
        delete student1;
        delete student2;
        delete student3;
        delete student4;
        delete student5;
        
    }

    {
        obzac();
        Apple a("red");
        Banana b;
        GrannySmith c;

        cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    }

    {
       obzac();
       Blackjack();
    }

        return 0;

}