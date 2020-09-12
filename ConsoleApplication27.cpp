// ConsoleApplication27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;


struct node {
    string name;
    int rate;
    node* next;
};
class result {
private:

public:
    node* head;
    result() {
        head = NULL;
    }

    void add(string name, int rate) {
        node* _new = new node;
        _new->name = name;
        _new->rate = rate;
        _new->next = head;
        head = _new;
    }


    void add(int n, string names[], int rates[]) {
        for (int i = 0; i < n; i++)add(names[i], rates[i]);
    }


    void show() {
        cout << "ZNO's result:" << endl;
        node* cur = head;
        while (cur != NULL) {
            cout << "Last name: " << cur->name << "Marks:" << cur->rate << endl;
            cur = cur->next;
        }
    }

    vector<string> count_2(int* k) {
        vector<string>names;
        node* cur = head;
        while (cur != NULL) {
            if (cur->rate == 2)names.push_back(cur->name);
            cur = cur->next;
        }
        *k = names.size();
        return names;
    }



    void del(string name) {
        if (head == NULL)cout << "Empty list";
        else {
            if (head->name == name)head = head->next;
            else {
                node* cur = head;
                node* prev = NULL;
                while (cur != NULL) {
                    if (cur->name == name) {
                        prev->next = cur->next;
                    }
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
    }


    void del(vector<string>names) {
        for (int i = 0; i < names.size(); i++)del(names[i]);
    }
};


int main() {


    cout << "How More Classes:" << endl;
    int n;
    cin >> n;
    char ch;
    result* j = new result[n];
    for (int i = 0; i < n; i++) {
        cout << "Marks " << i + 1 << "-n classes:" << endl;
        do {
            cout << "\n Last name :";
            string s;
            cin >> s;
            cout << "\n Mark:";
            int rate;
            cin >> rate;
            j[i].add(s, rate);
            cout << "\n The end of list y/n " << endl;;
            ch = _getch();
        } while (ch != 'y');
    }

    vector<string>names;
    int count, max = 0;
    for (int i = 0; i < n; i++) {
        j[i].show();
        int k = 0;
        j[i].count_2(&k);
        if (max <= k) {
            names = j[i].count_2(&k);
            max = k;
            count = i;
        }
    }
    cout << endl << "Changes:" << endl;
    node* cur = j[count].head;
    while (cur != NULL) {
        cout << "Name: " << cur->name << "  Mark: " << cur->rate << endl;
        cout << "\n Delete? y/n " << endl;;
        ch = _getch();
        if (ch == 'y') {
            j[count].del(cur->name);
        }
        cur = cur->next;
    }
    cout << "Changed" << endl;
    j[count].show();

    system("PAUSE");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
