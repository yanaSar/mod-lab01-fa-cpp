// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

unsigned int faStr1(const char *str) {
    if (str == nullptr) return 0;

    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (const char *p = str; *p != '\0'; ++p) {
        if (!std::isspace(static_cast<unsigned char>(*p))) {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
            if (std::isdigit(static_cast<unsigned char>(*p))) {
                hasDigit = true;
            }
        } else {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        }
    }
    if (inWord && !hasDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    if (str == nullptr) return 0;

    unsigned int count = 0;
    bool inWord = false;
    bool validWord = true;
    bool firstChar = true;

    for (const char *p = str; *p != '\0'; ++p) {
        if (isLetter(*p)) {
            if (!inWord) {
                inWord = true;
                firstChar = true;
                validWord = true;
            }
            if (firstChar) {
                if (!std::isupper(static_cast<unsigned char>(*p)))
                    validWord = false;
                firstChar = false;
            } else {
                if (!std::islower(static_cast<unsigned char>(*p)))
                    validWord = false;
            }
        } else if (*p == ' ') {
            if (inWord && validWord) count++;
            inWord = false;
        } else {
            if (inWord) validWord = false;
        }
    }
    if (inWord && validWord) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    if (str == nullptr) return 0;

    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;
    unsigned int currentLength = 0;

    for (const char *p = str; *p != '\0'; ++p) {
        if (isLetter(*p)) {
            if (!inWord) {
                inWord = true;
                currentLength = 1;
            } else {
                currentLength++;
            }
        } else {
            if (inWord) {
                totalLength += currentLength;
                wordCount++;
                inWord = false;
            }
        }
    }
    if (inWord) {
        totalLength += currentLength;
        wordCount++;
    }
    if (wordCount == 0) return 0;

    double avg = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(std::round(avg));
}
