#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>
#include<algorithm>

using namespace std;

bool isWordsEqual(string word1, string word2, bool was1Deleted = false, bool was2Deleted = false) {
    if (word1 == word2) return true;

    if (abs(int(word1.size() - word2.size())) > 1) return false;

    if (word1[0] == word2[0]) {
        word1.erase(0, 1);
        word2.erase(0, 1);
        return isWordsEqual(word1, word2);
    }
    else if (was1Deleted && was2Deleted) {
        return false;
    }
    else {
        string subWord1 = word1;
        string subWord2 = word2;
        subWord1.erase(0, 1);
        subWord2.erase(0, 1);

        bool checkLeft = was1Deleted ? false : isWordsEqual(subWord1, word2, true, was2Deleted);
        bool checkRight = was2Deleted ? false : isWordsEqual(word1, subWord2, was1Deleted, true);

        return checkLeft || checkRight;
    }
}


int main() {
    int n, k;

    cin >> n >> k;

    string* dict = new string[n];
    string* words = new string[k];

    for (int index = 0; index < n; index++) cin >> dict[index];
    for (int index = 0; index < k; index++) cin >> words[index];

    int* counts = new int[k];
    string* findedWords = new string[k];

    for (int wordIndex = 0; wordIndex < k; wordIndex++) {
        for (int dictIndex = 0; dictIndex < n; dictIndex++) {
            bool isEqual = isWordsEqual(words[wordIndex], dict[dictIndex]);
            counts[wordIndex] += isEqual;

            if (counts[wordIndex] == 1 && isEqual) {
                findedWords[wordIndex] = dict[dictIndex];
            }
            else if (counts[wordIndex] != 1 && isEqual) {
                findedWords[wordIndex] = "";
            }
        }
    }

    for (int index = 0; index < k; index++) {
        cout << words[index] << " " << counts[index] << " " << findedWords[index] << endl;
    }
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
