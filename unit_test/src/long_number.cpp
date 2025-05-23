#include "long_number.hpp"

using biv::LongNumber;

LongNumber::LongNumber() : length(1), sign(1) {
    numbers = new int[length];
    numbers[0] = 0;
}

LongNumber::LongNumber(const char* const str) {
    int str_length = get_length(str);
    if (str_length == 0) {
        sign = 1;
        length = 1;
        numbers = new int[length];
        numbers[0] = 0;
        return;
    }
    if (str[0] == '-') {
        sign = -1;
        length = str_length - 1;
    } else {
        sign = 1;
        length = str_length;
    }

    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = str[str_length - 1 - i] - '0';
    }
}

LongNumber::LongNumber(const LongNumber& x) {
    length = x.length;
    sign = x.sign;
    numbers = new int[length];
    std::copy(x.numbers, x.numbers + length, numbers);  
}

LongNumber::LongNumber(LongNumber&& x) {
    length = x.length;
    sign = x.sign;
    numbers = x.numbers;

    x.length = 0;
    x.sign = 1;
    x.numbers = nullptr;
}

LongNumber::~LongNumber() {
    delete[] numbers;
}

LongNumber& LongNumber::operator = (const char* const str) {
    LongNumber temp(str);
    std::swap(length, temp.length);
    std::swap(sign, temp.sign);
    std::swap(numbers, temp.numbers);

    return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
    if (this == &x) return *this;

    delete[] numbers;
    length = x.length;
    sign = x.sign;
    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }
    return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
    if (this != &x) {
        delete[] numbers;

        length = x.length;
        sign = x.sign;
        numbers = x.numbers;

        x.length = 0;
        x.sign = 1;
        x.numbers = nullptr;
    }
    return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
    if (length != x.length || sign != x.sign) return false;
    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) return false;
    }
    return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
    if (sign != x.sign) return sign > x.sign;

    if (length != x.length) return length > x.length;

    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) return numbers[i] > x.numbers[i];
    }
    return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
    if (sign != x.sign) return sign < x.sign;

    if (length != x.length) return length < x.length;

    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) return numbers[i] < x.numbers[i];
    }
    return false;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber temp = x;
        temp.sign = -temp.sign;
        return *this - temp;
    }

    int maxLength = std::max(length, x.length) + 1;
    int* result = new int[maxLength]();
    int carry = 0;
    int i = 0;

    for (; i < std::min(length, x.length); i++) {
        int sum = numbers[i] + x.numbers[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    for (; i < length; i++) {
        int sum = numbers[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    for (; i < x.length; i++) {
        int sum = x.numbers[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result[i++] = carry;
    }

    LongNumber res;
    res.sign = sign;
    res.length = i;
    delete[] res.numbers;
    res.numbers = result;

    return res;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber temp = x;
        temp.sign = -temp.sign;
        return *this + temp;
    }

    if (sign == -1) {
        LongNumber temp1 = *this;
        LongNumber temp2 = x;
        temp1.sign = 1;
        temp2.sign = 1;
        return temp2 - temp1;
    }

    if (*this < x) {
        LongNumber result = x - *this;
        result.sign = -1;
        return result;
    }

    int* result = new int[length]();
    int borrow = 0;
    int i = 0;

    for (; i < x.length; i++) {
        int diff = numbers[i] - x.numbers[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }

    for (; i < length; i++) {
        int diff = numbers[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }

    while (i > 1 && result[i - 1] == 0) {
        i--;
    }

    LongNumber res;
    res.sign = 1;
    res.length = i;
    delete[] res.numbers;
    res.numbers = result;

    return res;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
    if ((length == 1 && numbers[0] == 0) || (x.length == 1 && x.numbers[0] == 0)) {
        return LongNumber("0");
    }

    int resultLength = length + x.length;
    int* result = new int[resultLength]();

    for (int i = 0; i < length; i++) {
        int carry = 0;
        for (int j = 0; j < x.length; j++) {
            int product = numbers[i] * x.numbers[j] + result[i + j] + carry;
            result[i + j] = product % 10;
            carry = product / 10;
        }
        if (carry > 0) {
            result[i + x.length] = carry;
        }
    }

    while (resultLength > 1 && result[resultLength - 1] == 0) {
        resultLength--;
    }

    LongNumber res;
    res.sign = sign * x.sign;
    res.length = resultLength;
    delete[] res.numbers;
    res.numbers = result;

    return res;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    if (x == LongNumber("0")) throw std::runtime_error("Division by zero");
    if (*this < x) return LongNumber("0");

    LongNumber dividend = *this;
    LongNumber divisor = x;
    dividend.sign = 1;
    divisor.sign = 1;

    LongNumber quotient("0");
    LongNumber current("0");

    for (int i = dividend.length - 1; i >= 0; i--) {
        current = current * LongNumber("10") + LongNumber(std::to_string(dividend.numbers[i]).c_str());
        int count = 0;
        while (current > divisor || current == divisor) {
            current = current - divisor;
            count++;
        }
        quotient = quotient * LongNumber("10") + LongNumber(std::to_string(count).c_str());
    }

    quotient.sign = (sign == x.sign) ? 1 : -1;
    return quotient;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
    if (x.length == 1 && x.numbers[0] == 0) {
        throw std::runtime_error("Modulo by zero");
    }

    if (length == 1 && numbers[0] == 0) {
        return LongNumber("0");
    }

    LongNumber quotient = *this / x;
    
    LongNumber remainder = *this - (quotient * x);
    
    if (remainder.sign != x.sign && !(remainder.length == 1 && remainder.numbers[0] == 0)) {
        remainder = remainder + x;
    }
    
    return remainder;
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	return numbers[rank - 1];
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
    if (str == nullptr || str[0] == '\0') return 0;
    int str_length = strlen(str);
    return str_length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace biv {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
        if (x.sign == -1) {
            os << "-";
        }
        for (int i = x.length - 1; i >= 0; i--) {
            os << x.numbers[i];
        }
        return os;
	}
}