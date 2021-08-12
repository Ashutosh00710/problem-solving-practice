#include <bits/stdc++.h>

using namespace std;
/*
buffer: a region of a physical memory storage used to temporarily
store data while it is being moved from one place to another
*/
class String {
    char* Buffer;
    // unsigned is because size of the string cannot be negative
    unsigned int Size;
public:
    String(const char* str) {
        Size = strlen(str);
        Buffer = new char[Size + 1];
        memcpy(Buffer, str, Size + 1);
        Buffer[Size] = 0;
    }

    // copy constructor (declare what to do when someone try to copy the object of this class)
    String(const String& other): Size(other.Size) {
        // allocate a new buffer
        Buffer = new char[Size + 1];
        // copy the other buffer to Buffer
        memcpy(Buffer, other.Buffer, Size + 1);
    }

    char& operator[](unsigned int index) {
        return Buffer[index];
    }

    unsigned int size() {
        return Size;
    }

    ~String() {
        delete[] Buffer;
    }

    friend ostream& operator<< (ostream &stream, const String& string);
    friend String operator+(const String& firstString, const String& secondString);
};

ostream& operator<<(ostream &stream, const String& string) {
    stream << string.Buffer;
    return stream;
}

// Always pass the object by reference to avoid calling copy constructor
// The default copy constructor by C++ just copy the variables as it is.
int main() {
    String s = "Ashu";
    cout << s;
}
