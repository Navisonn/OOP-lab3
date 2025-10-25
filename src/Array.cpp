#include "../include/Array.h"

Array::Array() : _data(nullptr), _size(0), _capacity(0) {
    reserve(10);
}
Array::~Array() {
    clear();
    delete[] _data;
}
void Array::reserve(size_t newCapacity) {
    if (newCapacity <= _capacity) return;
    Figure** newData = new Figure*[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
    _capacity = newCapacity;
}
void Array::add(Figure* f) {
    if (_size == _capacity) {
        reserve(_capacity * 2 + 1);
    }
    _data[_size++] = f;
}

void Array::remove(size_t index) {
    if (index >= _size) return;
    delete _data[index];
    for (size_t i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }
    --_size;
}

Figure* Array::operator[](size_t index) {
    return _data[index];
}
const Figure* Array::operator[](size_t index) const {
    return _data[index];
}
size_t Array::size() const {
    return _size;
}
void Array::clear() {
    for (size_t i = 0; i < _size; ++i) {
        delete _data[i];
    }
    _size = 0;
}
