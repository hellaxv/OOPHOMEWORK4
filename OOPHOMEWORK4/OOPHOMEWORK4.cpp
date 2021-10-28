#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert> // для assert()
#include "blackjack.h"

using namespace std;

void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
    cout << "\n\n//======================================END======================================//\n\n";
}
void obzac2()
{
    cout << "\n\n//-------------------------------------------------------------------------------//\n\n";
}

/*HOMEWORK1
Добавить в контейнерный класс, который был написан в этом уроке, методы:
для удаления последнего элемента массива (аналог функции pop_back() в векторах)
для удаления первого элемента массива (аналог pop_front() в векторах)
для сортировки массива
для вывода на экран элементов.
*/
/*
class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() :  m_length(0), m_data(nullptr){}
    

    ArrayInt(int length) :  m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
        // Здесь нам не нужно присваивать значение null для m_data или выполнять m_length = 0, так как объект и так будет уничтожен
    }


    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void reallocate(int newLength)
    {
        // Удаляем все существующие элементы внутри массива
        erase();

        // Если наш массив должен быть пустым, то выполняем возврат здесь
        if (newLength <= 0)
            return;

        // Дальше нам нужно выделить новые элементы
        m_data = new int[newLength];
        m_length = newLength;
    }

    // Функция resize() изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int* data = new int[m_length + 1];

        // Копируем все элементы аж до index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем наш новый элемент в наш новый массив
        data[index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый массив
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        // Проверка на корректность передаваемого индекса
        assert(index >= 0 && index < m_length);

        // Если это последний элемент массива, то делаем массив пустым и выполняем return
        if (m_length == 1)
        {
            erase();
            return;
        }

        // Cоздаем новый массив на один элемент меньше нашего старого массива
        int* data = new int[m_length - 1];

        // Копируем все элементы аж до index
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Копируем все значения после удаляемого элемента
        for (int after = index + 1; after < m_length; ++after)
            data[after - 1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый массив
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    
    void deleteIndex(int index)
    {
        assert(index >= 0 && index <= m_length);

        int* newData = new int[m_length - 1];
        int j = 0;

        for (int i = 0; i < m_length; i++)
        {
            if (i == index)
            {
                //no copying m_data[i], skip to m_data[i + 1]
            }
            else
            {
                newData[j] = m_data[i];
                j++;
            }

        }

        delete[] m_data;
        m_data = newData;
        --m_length;

    }

    void pop_back()
    {
        deleteIndex(m_length - 1);
    }

    void print()
    {
        std::cout << "\n";
        for (int i = 0; i < m_length; i++)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << "\n";
    }
};*/
class ArrayInt
{
private:
    int* data;
    int length;
public:
    ArrayInt() : length(0), data(nullptr) {};

    ArrayInt(int inLength) : length(inLength) 
    {
        assert(length >= 0);
        if (length > 0)
        {
            data = new int[length];
        }
        else
            data = nullptr;
    }

    void erase()
    {
        if (length > 0)
        {
            delete[] data;
            data = nullptr;
            length = 0;
        }
    }

    int getLength() const {
        return length;
    }

    int& operator[](int index)
    {
        return data[index];
    }

    void deleteLast() 
    {

        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    void deleteFirst()
    {
        assert(length != 0);

        if (length == 1)
        {
            erase();
        }
        else
        {
            int* new_data = new int[length - 1];

            for (int i = 0; i < length - 1; i++) {
                new_data[i] = data[i + 1];
            }

            delete[] data;
            data = new_data;
            length--;
        }
    }

    //сортировка пузырьком
    void sort() 
    {
        assert(length != 0);

        int tempIndex = 0;
        int lastIndex = length - 1;
        int temp;

        while (lastIndex > 0)
        {
            if (data[tempIndex] > data[tempIndex + 1])
            {
                temp = data[tempIndex];
                data[tempIndex] = data[tempIndex + 1];
                data[tempIndex + 1] = temp;
            }

            if (tempIndex == lastIndex - 1)
            {
                tempIndex = 0;
                lastIndex--;
            }
            else
            {
                tempIndex++;
            }
        }
    }

    void print() const {
        assert(length != 0);

        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "length: " << length << endl;
    }

    ~ArrayInt() {
        delete[] data;
    }
};




/*HOMEWORK2
Дан вектор чисел, требуется выяснить, сколько среди них различных. 
Постараться использовать максимально быстрый алгоритм.
*/
void printVector(vector<int>& input)
{
    cout << "\n";
    for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        cout << *it << " ";
}
int countUniqueNumbers(vector<int> input)
{
    sort(input.begin(), input.end());
    vector<int>::iterator it;
    it = unique(input.begin(), input.end());
    input.resize(distance(input.begin(), it));
    //printVector(input); - test
    return input.size();
}

int main()
{
    setlocale(LC_ALL, "rus");
    /*
    //vector <int> v; // <int> тип элементов, которые хранятся в этом векторе. в данном случае целые числа int и v-объект.
    //vector <vector <int>> v; пример 2ву мерного массива. (вектор векторов).
    vector <int> v{ 4, -3, -6, 6, 5, 1, 9, 10 }; //инициализация вектора.
    cout << v.size() << endl; //запрос размера вектора, чтобы узнать колл-во элементов в нашем векторе. (одномерный динамический массив).
    //cout << v[3] << endl; //указатель на конкретный массив.
    //cout << v.at(3) << endl; //указатель на конкретный массив. 2рой способ.
    //v.push_back(6); //добавление нового элемента в конец вектора.
    //v.pop_back(); //удаляет последний элемент из вектора.
    //v.insert(); //аналог который удаляет или вставляет элемент в массив.
    //v.erase(); //для удаления произвольной области.
    //int eight v.back(); //eight удаляем 8мое число, можно удалить конкретное, two например и тп.
    
    //int x = v.front(); //возвращает нулевой элемент вектора. v.front(); возвращает элемент х.
    //v[0] //возвращает нулевой элемент вектора. v.front(); возвращает элемент х. 2рой способ.

    for(int i = 0; i<v.size(); i++) //выводим все элементы на экран.
        cout << v[i] << " ";
    */

    {
        /*2РОЙ ВАРИАНТ РЕШЕНИЕ, НО ЧЕРЕЗ REMOVE!.
        obzac();
        ArrayInt array(15); //объявили массив.
        for (int i = 0; i < 15; i++) //заполнили массив.
            array[i] = i + 1;
        array.remove(1);
        array.pop_back();
        array.print();
        obzac2();
        */
    }
    
    {
        obzac();
        ArrayInt array(6);
        array[0] = 1;
        array[1] = 2;
        array[2] = 3;
        array[3] = 4;
        array[4] = 5;
        array[5] = 6;
        array.deleteFirst();
        array.deleteLast();
        array.print();
        obzac2();
    }


    {  
        obzac();
        vector<int> array = { 1, 1, 1, 2, 4, 6, 6, 295, 23, 5, 5, 6, 7, 10 };
        cout << "\nНачальный массивчик: ";
        printVector(array);
        int count = countUniqueNumbers(array);
        cout << "\nУникальные числа: " << count;
        obzac2();
    }

    {
        obzac();
        Card aceClubs(ACE, CLUBS);
        Card aceHearts(ACE, HEARTS);
        Card kingClubs(KING, CLUBS);

        Hand playerHand;
        playerHand.Add(&aceClubs);
        playerHand.Add(&aceHearts);
        playerHand.Add(&kingClubs);

        int sum = playerHand.GetValue();
        std::cout << "\n\nPlayer's hand value is: " << sum;
        playerHand.Clear();
        sum = playerHand.GetValue();
        std::cout << "\nHand cleared! New value is: " << sum;
        obzac2();
    }
}
