#ifndef ARRAY_H
#define ARRAY_H

template<typename Type, size_t Size>
class Array {
  public:
    template<typename...Arguments>
    constexpr Array(const Arguments&...arguments) : mData{arguments...} {

    }

    constexpr Type at(unsigned int index) const {
      return mData[(index <= Size - 1 && index >= 0) ? index : Size - 1];
    } 

    constexpr size_t size() const {
      return Size;
    }

    constexpr Type* begin() const {
      return &mData[0];
    }

    constexpr Type* end() const {
      return &mData[Size - 1];
    }

  private:
    Type mData[Size];
};

#endif