#include <iostream>
#include <algorithm>
#include <string>

bool canObtainTFromS(const std::string& S, const std::string& T) {
    if (S.length() != T.length()) {
        return false; // S and T have different lengths
    }
    if (S == T) {
        return true; // S and T are already equal
    }
    std::string S1 = S;
    std::reverse(S1.begin(), S1.begin() + S.length() / 2); // perform the first substring reversal
    if (S1 == T) {
        return true; // we can obtain T after one reversal operation
    }
    std::string S2 = S1;
    std::reverse(S2.begin() + S.length() / 2, S2.end()); // perform the second substring reversal
    if (S2 == T) {
        return true; // we can obtain T after two reversal operations
    }
    std::string S3 = S2;
    std::reverse(S3.begin(), S3.begin() + S.length() / 4); // perform the third substring reversal
    std::reverse(S3.begin() + S.length() / 4, S3.begin() + 3 * S.length() / 4);
    std::reverse(S3.begin() + 3 * S.length() / 4, S3.end());
    if (S3 == T) {
        return true; // we can obtain T after three reversal operations
    }
    std::string S4 = S3;
    std::reverse(S4.begin() + S.length() / 4, S4.begin() + 3 * S.length() / 4); // perform the fourth substring reversal
    if (S4 == T) {
        return true; // we can obtain T after four reversal operations
    }
    return false; // we cannot obtain T after four reversal operations
}

int main() {
    std::string S = "abacde";
    std::string T = "beacda";
    if (canObtainTFromS(S, T)) {
        std::cout << "Yes, we can obtain T from S using four substring reversals.\n";
    } else {
        std::cout << "No, we cannot obtain T from S using four substring reversals.\n";
    }
    return 0;
}