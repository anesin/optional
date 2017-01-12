#ifndef __OPTIONAL_H__
#define __OPTIONAL_H__

#include <cassert>


template<typename T>
class optional
{
 private:
  bool init_;
  T value_;

 public:
  typedef T         value_type;
  typedef T const & reference_const_type;
  typedef T &       reference_type;
  typedef T const & argument_type;

  optional() : init_(false) {}
  optional(argument_type val) : init_(true), value_(val) {}

  bool initialized() const {
    return init_;
  }

  bool operator!() const {
    return !initialized();
  }

  optional & operator=(const optional &rhs) {
    if (initialized()) {
      if (rhs.initialized())
        value_ = rhs.get();
      else
        init_ = false;
    }
    else {
      if (rhs.initialized())
        assign(rhs.get());
    }
    return *this;
  }

  optional & operator=(argument_type val) {
    assign(val);
    return *this;
  }

  reference_const_type get() const {
    assert(initialized());
    return value_;
  }

  reference_type get() {
    assert(initialized());
    return value_;
  }

  reference_const_type get_value_or(reference_const_type val) const {
    return initialized()? value_: val;
  }

  reference_type get_value_or(reference_type val) {
    return initialized()? value_: val;
  }

  reference_const_type operator*() const {
    return get();
  }

  reference_type operator*() {
    return get();
  }

 private:
  void assign(argument_type value) {
    init_ = true;
    value_ = value;
  }
};


// operator== for optional<T>
template<typename T>
inline bool operator==(const optional<T> &lhs, const optional<T> &rhs) {
  return (!lhs) != (!rhs)? false: (!lhs? true: *lhs == *rhs);
}

template<typename T>
inline bool operator==(const optional<T> &lhs, const T &rhs) {
  return !lhs? false: *lhs == rhs;
}

template<typename T>
inline bool operator==(const T &lhs, const optional<T> &rhs) {
  return !rhs? false: lhs == *rhs;
}


// operator!= for optional<T>
template<typename T>
inline bool operator!=(const optional<T> &lhs, const optional<T> &rhs) {
  return !(lhs == rhs);
}

template<typename T>
inline bool operator!=(const optional<T> &lhs, const T &rhs) {
  return !(lhs == rhs);
}

template<typename T>
inline bool operator!=(const T &lhs, const optional<T> &rhs) {
  return !(lhs == rhs);
}


// operator< for optional<T>
template<typename T>
inline bool operator<(const optional<T> &lhs, const optional<T> &rhs) {
  return !rhs? false: (!lhs? true: *lhs < *rhs);
}

template<typename T>
inline bool operator<(const optional<T> &lhs, const T &rhs) {
  return !lhs? true: *lhs < rhs;
}

template<typename T>
inline bool operator<(const T &lhs, const optional<T> &rhs) {
  return !rhs? false: lhs < *rhs;
}


// operator> for optional<T>
template<typename T>
inline bool operator>(const optional<T> &lhs, const optional<T> &rhs) {
  return rhs < lhs;
}

template<typename T>
inline bool operator>(const optional<T> &lhs, const T &rhs) {
  return rhs < lhs;
}

template<typename T>
inline bool operator>(const T &lhs, const optional<T> &rhs) {
  return rhs < lhs;
}


// operator<= for optional<T>
template<typename T>
inline bool operator<=(const optional<T> &lhs, const optional<T> &rhs) {
  return !(rhs < lhs);
}

template<typename T>
inline bool operator<=(const optional<T> &lhs, const T &rhs) {
  return !(rhs < lhs);
}

template<typename T>
inline bool operator<=(const T &lhs, const optional<T> &rhs) {
  return !(rhs < lhs);
}


// operator>= for optional<T>
template<typename T>
inline bool operator>=(const optional<T> &lhs, const optional<T> &rhs) {
  return !(lhs < rhs);
}

template<typename T>
inline bool operator>=(const optional<T> &lhs, const T &rhs) {
  return !(lhs < rhs);
}

template<typename T>
inline bool operator>=(const T &lhs, const optional<T> &rhs) {
  return !(lhs < rhs);
}


typedef optional<bool>            op_bool;
typedef optional<char>            op_char;
typedef optional<unsigned char>   op_uchar;
typedef optional<short>           op_short;
typedef optional<unsigned short>  op_ushort;
typedef optional<int>             op_int;
typedef optional<unsigned int>    op_uint;
typedef optional<long>            op_long;
typedef optional<unsigned long>   op_ulong;


#endif  // __OPTIONAL_H__
