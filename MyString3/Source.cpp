#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int length;

public:
    MyString()
    {
        length = 0;
        str = new char[length + 1];
        str[0] = '\0';
    }

    MyString(const char* input)
    {
        length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    MyString(const MyString& other) 
    {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    ~MyString()
    {
        delete[] str;
    }

    char& operator[](int index)
    {
        if (index >= 0 && index < length)
        {
            return str[index];
        }
        throw out_of_range("Index out of range");
    }

    void operator()()
    {
        cout << "Enter the line: ";
        char temp[1000];
        cin.getline(temp, 1000);
        int newLength = 0;
        while (temp[newLength] != '\0')
        {
            newLength++;
        }
        delete[] str;
        str = new char[newLength + 1];
        for (int i = 0; i < newLength; i++)
        {
            str[i] = temp[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    MyString operator+(char c) const
    {
        MyString result(length + 1);
        for (int i = 0; i < length; i++)
        {
            result.str[i] = str[i];
        }
        result.str[length] = c;
        result.str[length + 1] = '\0';
        result.length = length + 1;
        return result;
    }

    friend MyString operator+(char c, const MyString& obj)
    {
        MyString result(obj.length + 1);
        result.str[0] = c;

        for (int i = 0; i < obj.length; i++)
        {
            result.str[i + 1] = obj.str[i];
        }
        result.str[obj.length + 1] = '\0';
        result.length = obj.length + 1;
        return result;
    }

    MyString operator+(int n) const
    {
        MyString result(length + n);
        for (int i = 0; i < length; i++)
        {
            result.str[i] = str[i];
        }
        for (int i = 0; i < n; i++)
        {
            result.str[length + i] = '*';
        }

        result.str[length + n] = '\0';
        result.length = length + n;
        return result;
    }

    friend MyString operator+(int n, const MyString& obj)
    {
        MyString result(obj.length + n);

        for (int i = 0; i < n; i++)
        {
            result.str[i] = '*'; 
        }
        for (int i = 0; i < obj.length; i++)
        {
            result.str[n + i] = obj.str[i];
        }

        result.str[obj.length + n] = '\0';
        result.length = obj.length + n;
        return result;
    }

    MyString operator++(int)
    {
        MyString temp = *this;
        *this = *this + '!';
        return temp;
    }

    MyString& operator++()
    {
        *this = '!' + *this;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const MyString& myStr)
    {
        os << myStr.str;
        return os;
    }
};

int main()
{
    MyString s1("Hello");
    cout << "s1: " << s1 << endl;

    cout << "Third symbol: " << s1[2] << endl;

    s1();
    cout << "After entering: " << s1 << endl;

    MyString s2 = s1 + 'A';
    cout << "After adding the symbol at the and: " << s2 << endl;

    MyString s3 = 'B' + s1;
    cout << "After adding the symbol to the beginning: " << s3 << endl;

    MyString s4 = s1 + 10;
    cout << "After adding 10 symbol at the and: " << s4 << endl;

    MyString s5 = 10 + s1;
    cout << "After adding 10 symbol to the beginning: " << s5 << endl;

    MyString s6 = s1++;
    cout << "After postfix increment: " << s1 << endl;

    MyString s6 = ++s1;
    cout << "After prefix increment: " << s1 << endl;

    return 0;
}