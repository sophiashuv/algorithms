//
// Created by Sophia Shuvar on 15.05.20.
//

#ifndef BITSET_BITSET_H
#define BITSET_BITSET_H

#endif //BITSET_BITSET_H
#pragma once
#include <iostream>
#include <bitset>

using namespace std;

template<size_t N>
class BitSet {
private:
    bool set[N];

public:
    BitSet() {
        for (int i = 0; i < N; i++) set[i] = 0;
    }

    BitSet(const BitSet<N>& other) {
        for (int i = 0; i < N; i++) set[i] = other.set[i];
    }

    BitSet(const string &s) {
        if (s.length() > N) throw "Wrong size exception\n";
        for (size_t i = 0; i < N - s.length(); i++) set[i] = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '0') set[N - s.length() + i] = 0;
            else if (s[i] == '1') set[N - s.length() + i] = 1;
            else throw "Wrong bit line exception";
        }
    }

    BitSet(unsigned long int n) {
        for (auto i = N; i > 0;){
            i--;
            set[i] = bool(n % 2);
            n /= 2;
        }
    }

    //~BitSet() { delete[] set; }

    bool& operator [](size_t n) {
        return set[n];
    }

    size_t size() {
        return N;
    }

    /*
     * Returns the number of bits that are set to true
     */
    int count() {
        int counter = 0;
        for (size_t i = 0; i < N; i++) counter += set[i];
        return counter;
    }

    /*
     * Sets all bits to true
     */
    BitSet& Set() {
        for (size_t i = 0; i < N; i++) set[i] = 1;
        return *this;
    }

    /*
     *  Sets the bit at position pos to the value value
     */
    BitSet& Set(size_t pos, bool value = 1) {
        set[pos] = value;
        return *this;
    }

    /*
     * Sets all bits to false
     */
    BitSet& reset() {
        for (size_t i = 0; i < N; i++) set[i] = 0;
        return *this;
    }

    /*
     *  Sets the bit at position pos to false
     */
    BitSet& reset(size_t pos) {
        set[pos] = 0;
        return *this;
    }

    /*
     * Flips all bits (like operator~, but inplace)
     */
    BitSet& flip() {
        for (size_t i = 0; i < N; i++) set[i] = !set[i];
        return *this;
    }

    /*
     * Flips the bit at the position pos.
     */
    BitSet& flip(size_t pos) {
        set[pos] = !set[pos];
        return *this;
    }

    /*
     *  Checks if all bits are set to true
     */
    bool all() {
        bool checker = 1;
        for (size_t i = 0; i < N; i++) checker *= set[i];
        return checker;
    }

    /*
     * Checks if any bits are set to true
     */
    bool any() {
        bool checker = 0;
        for (size_t i = 0; i < N; i++) checker += set[i];
        return checker;
    }

    /*
     * Checks if none of the bits are set to true
     */
    bool none() {
        bool checker = 1;
        for (size_t i = 0; i < N; i++) checker *= !set[i];
        return checker;
    }

    string to_string() {
        string result;
        for (size_t i = 0; i < N; i++) result += set[i] ? "1" : "0";
        return result;
    }

    /*
     * Converts the contents of the bitset to an unsigned long integer
     */
    unsigned long to_ulong() {
        unsigned long res = 0;
        string s = this->to_string();
        for (size_t i = 0; i < N; i++) {
            res *= 2;
            res += set[i] ? 1 : 0;
        }
        return res;
    }

    friend ostream& operator <<(ostream& out, BitSet& s) {
        for (size_t i = 0; i < N; i++) out << s.set[i];
        return out;
    }

    friend istream& operator >>(istream& in, BitSet& s) {
        for (size_t i = 0; i < N; i++) in << s.set[i];
        return in;
    }

    bool operator==(const BitSet& rhs) const {
        for (size_t i = 0; i < N; i++) if (set[i] != rhs.set[i]) return 0;
        return true;
    }

    bool operator!=(const BitSet& rhs ) {
        return !(*this == rhs);
    }

    BitSet& operator&=(const BitSet& other){
        for (size_t i = 0; i < N; i++) set[i] = set[i] & other.set[i];
        return *this;
    }

    BitSet& operator|=(const BitSet& other) {
        for (size_t i = 0; i < N; i++) set[i] = (set[i] | other.set[i]);
        return *this;
    }

    BitSet& operator^=(const BitSet& other){
        for (size_t i = 0; i < N; i++) set[i] = (set[i] ^ other.set[i]);
        return *this;
    }

    BitSet& operator~() {
        for (size_t i = 0; i < N; i++) set[i] = ~set[i];
        return *this;
    }
};