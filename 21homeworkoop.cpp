// 21homeworkoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Базовый класс Base
template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(const T1& v1, const T2& v2) : value1(v1), value2(v2) {}

    void printValues() {
        std::cout << "Base: value1 = " << value1 << ", value2 = " << value2 << std::endl;
    }
};

// Потомок Child
template<typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child(const T1& v1, const T2& v2, const T3& v3, const T4& v4)
        : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    void printValues() {
        Base<T1, T2>::printValues();
        std::cout << "Child: value3 = " << value3 << ", value4 = " << value4 << std::endl;
    }
};

// Потомок Child2
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    Child2(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    void printValues() {
        Child<T1, T2, T3, T4>::printValues();
        std::cout << "Child2: value5 = " << value5 << ", value6 = " << value6 << std::endl;
    }
};

int main() {
    Base<int, float> base(10, 3.14);
    base.printValues();

    Child<int, float, std::string, bool> child(20, 6.28, "Good", true);
    child.printValues();

    Child2<int, float, std::string, bool, double, char> child2(30, 9.42, "day", false, 3.14159, 'A');
    child2.printValues();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
