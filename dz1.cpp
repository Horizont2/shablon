#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class StringManipulator {
public:
    string toUpperCase(T input) {
        string str = toString(input);
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

    string toLowerCase(T input) {
        string str = toString(input);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    string reverse(T input) {
        string str = toString(input);
        std::reverse(str.begin(), str.end());
        return str;
    }

    string concatenate(T input1, T input2) {
        return toString(input1) + toString(input2);
    }

private:
    string toString(T input) {
        if constexpr (is_same<T, string>::value) {
            return input;
        } else {
            return to_string(input);
        }
    }
};

int main() {
    StringManipulator<string> manipulator;
    cout << "UpperCase: " << manipulator.toUpperCase("hello") << endl;
    cout << "LowerCase: " << manipulator.toLowerCase("WORLD") << endl;
    cout << "Reversed: " << manipulator.reverse("C++") << endl;
    cout << "Concatenated: " << manipulator.concatenate("Hello", " World") << endl;

    StringManipulator<int> numManipulator;
    cout << "Reversed number: " << numManipulator.reverse(12345) << endl;

    return 0;
}
