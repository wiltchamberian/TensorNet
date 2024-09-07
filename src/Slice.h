#ifndef __SLICE_H
#define __SLICE_H

#include <iostream>
#include <vector>
#include <cassert>

// Slice class to encapsulate slicing logic
class Slice {
public:
    // Constructor for three parameters
    Slice(int begin, int end, int stride) : begin_(begin), end_(end), stride_(stride) {
        validate();
    }

    // Constructor for two parameters
    Slice(int begin, int end) : begin_(begin), end_(end), stride_(1) {
        validate();
    }

    // Constructor for a single parameter
    Slice(int singleValue) : begin_(singleValue), end_(singleValue + 1), stride_(1) {
        validate();
    }

    // Display slice information
    void display() const {
        std::cout << "Slice(begin=" << begin_ << ", end=" << end_ << ", stride=" << stride_ << ")" << std::endl;
    }

private:
    int begin_;
    int end_;
    int stride_;

    // Validate the slice parameters
    void validate() const {
        assert(stride_ > 0); // Stride must be positive
        assert(begin_ <= end_); // Begin must be less than or equal to end
    }
};


#endif