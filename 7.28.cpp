#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool testPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    while (start < end && !isalpha(str[start])) {
        start++;
    }
    while (start < end && !isalpha(str[end])) {
        end--;
    }

    char startChar = tolower(str[start]);
    char endChar = tolower(str[end]);

    if (startChar != endChar) {
        return false;
    }

    return testPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const string& str) {
    return testPalindrome(str, 0, str.length() - 1);
}

void printSentence(const string& sentence) {
    cout << sentence << endl;
}

int main() {
    string sentence = "red roses run no risk, sir, on nurses order.";
    printSentence(sentence);

    if (isPalindrome(sentence)) {
        cout << "The sentence is a palindrome." << endl;
    } else {
        cout << "The sentence is not a palindrome." << endl;
    }

    return 0;
}
