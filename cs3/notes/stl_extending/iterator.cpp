// Sample custom iterator.
// By perfectly.insane (http://www.dreamincode.net/forums/index.php?showuser=76558)
// From: http://www.dreamincode.net/forums/index.php?showtopic=58468

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using std::cout; using std::endl;
using std::vector;

template <typename T>
class fixed_array{
public:

   typedef int size_type;

   class iterator{
   public:
      typedef iterator self_type;
      typedef T value_type;
      typedef T& reference;
      typedef T* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef int difference_type;
      iterator(pointer ptr) : ptr_(ptr) { }
      self_type operator++() { self_type i = *this; ptr_++; return i; }
      self_type operator++(int junk) { ptr_++; return *this; }
      reference operator*() { return *ptr_; }
      pointer operator->() { return ptr_; }
      bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
      bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
   private:
      pointer ptr_;
   };

   class const_iterator{
   public:
      typedef const_iterator self_type;
      typedef T value_type;
      typedef T& reference;
      typedef T* pointer;
      typedef int difference_type;
      typedef std::forward_iterator_tag iterator_category;
      const_iterator(pointer ptr) : ptr_(ptr) { }
      self_type operator++() { self_type i = *this; ptr_++; return i; }
      self_type operator++(int junk) { ptr_++; return *this; }
      const reference operator*() { return *ptr_; }
      const pointer operator->() { return ptr_; }
      bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
      bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
   private:
      pointer ptr_;
   };


   fixed_array(size_type size) : size_(size) { data_ = new T[size_]; }
   size_type size() const { return size_; }
   T& operator[](size_type index){ return data_[index]; }
   const T& operator[](size_type index) const { return data_[index]; }
   iterator begin() { return iterator(data_); }
   iterator end() { return iterator(data_ + size_); }
   const_iterator begin() const { return const_iterator(data_); }
   const_iterator end() const { return const_iterator(data_ + size_); }

private:
   T* data_;
   size_type size_;
};



int main() {
   fixed_array<int> fa(3);
   fa[0] = 1;
   fa[1] = 2;
   fa[2] = 3;

   cout << "array: ";
   for(auto i = fa.begin(); i != fa.end(); i++)
      cout << *i << " ";
   cout << endl;

   vector<int> vec;
   std::copy(fa.begin(), fa.end(), std::back_inserter(vec));

   cout << "copied vector: ";
   for(auto i = vec.begin(); i != vec.end(); i++)
      cout << *i << " ";
   cout << endl;
}
