// hashmap container implementation
// Mikhail Nesterenko, lifted from Pro C++
// 4/20/2014

#include <cstddef>
#include <vector>
#include <list>
#include <stdexcept>
#include <iterator> 
#include <string>
// #include <initializer_list>
#include <algorithm>
using std::vector;
using std::list;
using std::invalid_argument;
using std::string;
using std::pair;
// using std::initializer_list;
using std::for_each;

// Any Hash Class must provide two methods: hash() and numBuckets().
template <typename T>
class DefaultHash{
public:
   // throws invalid_argument if numBuckets is illegal
   DefaultHash(size_t numBuckets = 101) throw (invalid_argument);
   size_t hash(const T& key) const;
   size_t numBuckets() const { return mNumBuckets; }

protected:
   size_t mNumBuckets;
};

// Specialization for strings
template <>
class DefaultHash<string>{
public:
   // throws invalid_argument if numBuckets is illegal
   DefaultHash(size_t numBuckets = 101) throw (invalid_argument);
   size_t hash(const string& key) const;
   size_t numBuckets() const { return mNumBuckets; }

protected:
   size_t mNumBuckets;
};

template <typename Key, typename T, typename Compare, typename Hash>
class hashmap;


// HashIterator class definition
template<typename Key, typename T, typename Compare, typename Hash>
class HashIterator : public std::iterator<std::bidirectional_iterator_tag,
					  pair<const Key, T>>{
   // The hashmap class needs access to protected members of the HashIterator
   friend class hashmap<Key, T, Compare, Hash>;
 public:
   HashIterator(); // bi-directional iterators must supply default c-tor
   HashIterator(size_t bucket,
		typename list<pair<const Key, T>>::iterator listIt,
		const hashmap<Key, T, Compare, Hash>* inHashmap);

   pair<const Key, T>& operator*() const;

   // Return type must be something to which -> can be applied.
   // Return a pointer to a pair<const Key, T>, to which the compiler will
   // apply -> again
   pair<const Key, T>* operator->() const;
   HashIterator<Key, T, Compare, Hash>& operator++();
   const HashIterator<Key, T, Compare, Hash> operator++(int);

   HashIterator<Key, T, Compare, Hash>& operator--();
   const HashIterator<Key, T, Compare, Hash> operator--(int);

   // don't need to define a copy constructor or operator= because the
   // default behavior is what we want.

   // don't need destructor because the default behavior
   // (not deleting mHashmap) is what we want.

   // The following are ok as member functions because we don't support
   // comparisons of different types to this one
   bool operator==(const HashIterator& rhs) const;
   bool operator!=(const HashIterator& rhs) const;

 protected:
   size_t mBucket;
   typename list<pair<const Key, T>>::iterator mIt;
   const hashmap<Key, T, Compare, Hash>* mHashmap;

   // Helper methods for operator++ and operator--
   void increment();
   void decrement();
};

template <typename Key, typename T, typename Compare = std::equal_to<Key>,
	  typename Hash = DefaultHash<Key>>
class hashmap{
public:
   typedef Key key_type;
   typedef T mapped_type;
   typedef pair<const Key, T> value_type;
   typedef Compare key_compare;
   typedef pair<const Key, T>& reference;
   typedef const pair<const Key, T>& const_reference;
   typedef size_t size_type;
   typedef ptrdiff_t difference_type;
   typedef HashIterator<Key, T, Compare, Hash> iterator;
   typedef HashIterator<Key, T, Compare, Hash> const_iterator;

   // Required class definition for associative containers
   class value_compare :
	   public std::binary_function<value_type, value_type, bool> {
		   friend class hashmap<Key, T, Compare, Hash>;
   public:
	   bool operator() (const value_type& x, const value_type& y) const{
		   return comp(x.first, y.first);
	   }
   protected:
	   Compare comp;
   	   value_compare(Compare c) : comp(c) {}
   };

   // The iterator class needs access to protected members of the hashmap
   friend class HashIterator<Key, T, Compare, Hash>;

   // Iterator methods
   iterator begin();
   iterator end();
   const_iterator begin() const;
   const_iterator end() const;
   const_iterator cbegin() const;// For C++11
   const_iterator cend() const;// For C++11


   // Constructors
   // throws invalid_argument if the hash object specifies an illegal
   // number of buckets.   
   hashmap(const Compare& comp = Compare(),
		    const Hash& hash = Hash()) throw(invalid_argument);

   template <class InputIterator>
   hashmap(InputIterator first, InputIterator last,
	   const Compare& comp = Compare(), const Hash& hash = Hash())
      throw(invalid_argument);

   // destructor, copy constructor, move constructor,
   // copy assignment operator and move assignment operator
   ~hashmap();
   hashmap(const hashmap<Key, T, Compare, Hash>& src);
   hashmap(hashmap<Key, T, Compare, Hash>&& src);        // C++11
   hashmap<Key, T, Compare, Hash>& operator=(const hashmap<
					     Key, T, Compare, Hash>& rhs);
   hashmap<Key, T, Compare, Hash>& operator=(hashmap<
						Key, T, Compare, Hash>&& rhs);  // C++11

   /*
     // C++11 initializer list constructor
     hashmap(initializer_list<value_type> il, const Compare& comp = Compare(),
     const Hash& hash = Hash()) throw(invalid_argument);
     // C++11 initializer list assignment operator
     hashmap<Key, T, Compare, Hash>& operator=(initializer_list<value_type> il);
   */

   // Size methods
   bool empty() const;
   size_type size() const;
   size_type max_size() const;

   // element insert methods
   T& operator[] (const key_type& x);
   pair<iterator, bool> insert(const value_type& x);
   iterator insert(iterator position, const value_type& x);
   template <class InputIterator>
   void insert(InputIterator first, InputIterator last);
   // void insert(initializer_list<value_type> il);         // C++11

   // C++11 emplace methods
   pair<iterator, bool> emplace(value_type&& x);
   iterator emplace_hint(iterator hint, value_type&& x);

   // element delete methods
   void erase(iterator position);
   size_type erase(const key_type& x);
   void erase(iterator first, iterator last);


   // other modifying utilities
   void swap(hashmap<Key, T, Compare, Hash>& hashIn);

   void clear();

   // access methods for STL conformity
   key_compare key_comp() const;
   value_compare value_comp() const;

   // Lookup methods
   iterator find(const key_type& x);
   const_iterator find(const key_type& x) const;
   size_type count(const key_type& x) const;

protected:
   typedef list<value_type> ListType;
   typename ListType::iterator
   findElement(const key_type& x, size_t& bucket) const;

   // A pointer to a vector is used so that swap() can
   // be implemented in constant time.
   vector<ListType>* mElems;
   size_type mSize;
   Compare mComp;
   Hash mHash;
};

using std::insert_iterator;
using std::forward;

// Throws invalid_argument if numBuckets is illegal
template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets) throw (invalid_argument){
   if (numBuckets <= 0)
      throw invalid_argument("numBuckets must be > 0");
   mNumBuckets = numBuckets;
}

// Uses the division method for hashing.
// Treats the key as a sequence of bytes, sums the ASCII
// values of the bytes, and mods the total by the number
// of buckets.
template <typename T>
size_t DefaultHash<T>::hash(const T& key) const{
   size_t bytes = sizeof(key);
   size_t res = 0;
   for (size_t i = 0; i < bytes; ++i) {
      unsigned char b = *((unsigned char*)&key + i);
      res += b;
   }
   return (res % mNumBuckets);
}

// Throws invalid_argument if numBuckets is illegal
DefaultHash<string>::DefaultHash(size_t numBuckets) throw (invalid_argument){
   if (numBuckets <= 0) 
      throw invalid_argument("numBuckets must be > 0");
   mNumBuckets = numBuckets;
}

// Uses the division method for hashing after summing the
// ASCII values of all the characters in key.
size_t DefaultHash<string>::hash(const string& key) const{
   size_t sum = 0;
   for (size_t i = 0; i < key.size(); i++) 
      sum += (unsigned char)key[i];
   return sum % mNumBuckets;
}

// Dereferencing or incrementing an iterator constructed with the
// default ctor is undefined, so it doesn't matter what values we give
// here.
template<typename Key, typename T, typename Compare, typename Hash>
HashIterator<Key, T, Compare, Hash>::HashIterator(){
   mBucket = 0;
   mIt = list<pair<const Key, T>>::iterator();
   mHashmap = nullptr;
}

template<typename Key, typename T, typename Compare, typename Hash>
HashIterator<Key, T, Compare, Hash>::HashIterator(size_t bucket,
   typename list<pair<const Key, T>>::iterator listIt,
   const hashmap<Key, T, Compare, Hash>* inHashmap) :
   mBucket(bucket), mIt(listIt), mHashmap(inHashmap){}

// Return the actual element
template<typename Key, typename T, typename Compare, typename Hash>
pair<const Key, T>& HashIterator<Key, T, Compare, Hash>::operator*() const{
   return *mIt;
}

// Return the iterator, so the compiler can apply -> to it to access
// the actual desired field.
template<typename Key, typename T, typename Compare, typename Hash>
pair<const Key, T>*
HashIterator<Key, T, Compare, Hash>::operator->() const{
   return &(*mIt);
}
// Defer the details to the increment() helper
template<typename Key, typename T, typename Compare, typename Hash>
HashIterator<Key, T, Compare, Hash>&
HashIterator<Key, T, Compare, Hash>::operator++(){
   increment();
   return *this;
}

// Defer the details to the increment() helper
template<typename Key, typename T, typename Compare, typename Hash>
const HashIterator<Key, T, Compare, Hash>
HashIterator<Key, T, Compare, Hash>::operator++(int){
   auto oldIt = *this;
   increment();
   return oldIt;
}

// Defer the details to the decrement() helper
template<typename Key, typename T, typename Compare, typename Hash>
HashIterator<Key, T, Compare, Hash>&
HashIterator<Key, T, Compare, Hash>::operator--(){
   decrement();
   return *this;
}

// Defer the details to the decrement() helper
template<typename Key, typename T, typename Compare, typename Hash>
const HashIterator<Key, T, Compare, Hash>
HashIterator<Key, T, Compare, Hash>::operator--(int){
   auto oldIt = *this;
   decrement();
   return oldIt;
}

// Behavior is undefined if mIt already refers to the past-the-end
// element in the table, or is otherwise invalid.

template<typename Key, typename T, typename Compare, typename Hash>
void HashIterator<Key, T, Compare, Hash>::increment() {
   // mIt is an iterator into a single bucket. Increment it.
   ++mIt;

   // If we're at the end of the current bucket,
   // find the next bucket with elements.
   if (mIt == (*mHashmap->mElems)[mBucket].end()) {
      for (size_t i = mBucket + 1; i < (*mHashmap->mElems).size(); i++) 
	 if (!((*mHashmap->mElems)[i].empty())) {
	    // We found a non-empty bucket.
	    // Make mIt refer to the first element in it.
	    mIt = (*mHashmap->mElems)[i].begin();
	    mBucket = i;
	    return;
	 }
      // No more buckets. Assign mIt to refer to the end
      // iterator of the last list.
      mBucket = (*mHashmap->mElems).size() - 1;
      mIt = (*mHashmap->mElems)[mBucket].end();
   }
}

// Behavior is undefined if mIt already refers to the first element
// in the table, or is otherwise invalid.
template<typename Key, typename T, typename Compare, typename Hash>
void HashIterator<Key, T, Compare, Hash>::decrement(){
   // mIt is an iterator into a single bucket.
   // If it's at the beginning of the current bucket, don't decrement it.
   // Instead, try to find a non-empty bucket ahead of the current one.
   if (mIt == (*mHashmap->mElems)[mBucket].begin()) {
      for (size_t i = mBucket - 1; i >= 0; --i) 
	 if (!((*mHashmap->mElems)[i].empty())) {
	    mIt = (*mHashmap->mElems)[i].end();
	    --mIt;
	    mBucket = i;
	    return;
	 }
	 // No more non-empty buckets. This is an invalid decrement.
	 // Assign mIt to refer to one before the start element of the first
	 // list (an invalid position).
	 mIt = (*mHashmap->mElems)[0].begin();
	 --mIt;
	 mBucket = 0;
   } else 
     // We're not at the beginning of the bucket, so just move down.
      --mIt;
}

template<typename Key, typename T, typename Compare, typename Hash>
bool HashIterator<Key, T, Compare, Hash>::operator==(
     const HashIterator& rhs) const{
   // All fields, including the hashmap to which the iterators refer,
   // must be equal.
   return mHashmap == rhs.mHashmap && 
	   mBucket == rhs.mBucket &&
	   mIt == rhs.mIt;
}

template<typename Key, typename T, typename Compare, typename Hash>
bool HashIterator<Key, T, Compare, Hash>::operator!=(
     const HashIterator& rhs) const {
   return !(*this == rhs);
}


// Construct mElems with the number of buckets.
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(
	const Compare& comp, const Hash& hash) throw(invalid_argument) :
mSize(0), mComp(comp), mHash(hash){
	if (mHash.numBuckets() <= 0) 
		throw invalid_argument("Number of buckets must be positive");
	mElems = new vector<ListType>(mHash.numBuckets());
}

// Make a call to insert() to actually insert the elements.
template <typename Key, typename T, typename Compare, typename Hash>
template <class InputIterator>
hashmap<Key, T, Compare, Hash>::hashmap(
	InputIterator first, InputIterator last, const Compare& comp,
	const Hash& hash) throw(invalid_argument) : mSize(0), mComp(comp), mHash(hash) {
   if (mHash.numBuckets() <= 0) 
      throw invalid_argument("Number of buckets must be positive");
   mElems = new vector<ListType>(mHash.numBuckets());
   insert(first, last);
}

// C++11 initializer list constructor
/*
  template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(initializer_list<value_type> il,
const Compare& comp, const Hash& hash) throw(invalid_argument)
: mSize(0), mComp(comp), mHash(hash)
{
if (mHash.numBuckets() <= 0) {
throw invalid_argument("Number of buckets must be positive");
}
mElems = new vector<ListType>(mHash.numBuckets());
insert(il.begin(), il.end());
}
*/

// C++11 initializer list assignment operator
/*
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>& hashmap<Key, T, Compare, Hash>::operator=(
initializer_list<value_type> il)
{
clear();
insert(il.begin(), il.end());
return *this;
}
*/

template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::~hashmap(){
   delete mElems;
   mElems = nullptr;
   mSize = 0;
}

template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(const hashmap<
					Key, T, Compare, Hash>& src) :
   mSize(src.mSize), mComp(src.mComp), mHash(src.mHash){
   // Don't need to bother checking if numBuckets is positive, because
   // we know src checked.

   // Use the vector copy constructor
   mElems = new vector<ListType>(*(src.mElems));
}

// C++11 move constructor
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(hashmap<Key, T, Compare, Hash>&& src){
   // move ownership
   mElems = src.mElems;
   src.mElems = nullptr;
   mSize = src.mSize;
   src.mSize = 0;
   mComp = src.mComp;
   mHash = src.mHash;
}

template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>& hashmap<Key, T, Compare, Hash>::operator=(
        const hashmap<Key, T, Compare, Hash>& rhs) {
   // check for self-assignment
   if (this != &rhs) {
      delete mElems;
      mSize = rhs.mSize;
      mComp = rhs.mComp;
      mHash = rhs.mHash;
      // Don't need to bother checking if numBuckets is positive, because
      // we know rhs checked

      // Use the vector copy constructor
      mElems = new vector<ListType>(*(rhs.mElems));
   }
   return *this;
}

// C++11 move assignment operator
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>& hashmap<Key, T, Compare, Hash>::operator=(
	hashmap<Key, T, Compare, Hash>&& rhs){
   // check for self-assignment
   if (this != &rhs) {
      delete mElems;

      // move ownership
      mElems = rhs.mElems;
      rhs.mElems = nullptr;
      mSize = rhs.mSize;
      rhs.mSize = 0;
      mComp = rhs.mComp;
      mHash = rhs.mHash;
   }
   return *this;
}

template <typename Key, typename T, typename Compare, typename Hash>
typename list<pair<const Key, T> >::iterator
	hashmap<Key, T, Compare, Hash>::findElement(
	const key_type& x, size_t& bucket) const {
		// hash the key to get the bucket
		bucket = mHash.hash(x);

		// Look for the key in the bucket
		for (typename ListType::iterator it = (*mElems)[bucket].begin();
			it != (*mElems)[bucket].end(); ++it) {
				if (mComp(it->first, x)) {
					return it;
				}
		}
		return (*mElems)[bucket].end();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::iterator
hashmap<Key, T, Compare, Hash>::find(const key_type& x) {
   size_t bucket;
   // Use the findElement() helper
   auto it = findElement(x, bucket);
   if (it == (*mElems)[bucket].end()) {
      // we didn't find the element -- return the end iterator
      return end();
   }
   // We found the element -- convert the bucket/iterator to a HashIterator
   return HashIterator<Key, T, Compare, Hash>(bucket, it, this);
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::const_iterator
hashmap<Key, T, Compare, Hash>::find(const key_type& x) const{
   size_t bucket;
   // Use the findElement() helper
   auto it = findElement(x, bucket);
   if (it == (*mElems)[bucket].end()) {
      // we didn't find the element -- return the end iterator
      return end();
   }
   // We found the element -- convert the bucket/iterator to a HashIterator
   return HashIterator<Key, T, Compare, Hash>(bucket, it, this);
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::size_type
hashmap<Key, T, Compare, Hash>::count(const key_type& x) const{
   // There are either 1 or 0 elements matching key x.
   // If we can find a match, return 1, otherwise return 0.
   if (find(x) == end()) {
      return 0;
   } else {
      return 1;
   }
}

template <typename Key, typename T, typename Compare, typename Hash>
T& hashmap<Key, T, Compare, Hash>::operator[] (const key_type& x) {
   // This definition is the same as that used by map, according to
   // the standard.
   // It's a bit cryptic, but it basically attempts to insert
   // a new key/value pair of x and a new value. Regardless of whether
   // the insert succeeds or fails, insert() returns a pair of an
   // iterator/bool. The iterator refers to a key/value pair, the
   // second element of which is the value we want to return.
   return ((insert(make_pair(x, T()))).first)->second;
}

template <typename Key, typename T, typename Compare, typename Hash>
pair<typename hashmap<Key, T, Compare, Hash>::iterator, bool>
hashmap<Key, T, Compare, Hash>::insert(const value_type& x){
   size_t bucket;
   // Try to find the element
   auto it = findElement(x.first, bucket);

   if (it != (*mElems)[bucket].end()) {
      // The element already exists
      // Convert the list iterator into a HashIterator, which
      // also requires the bucket and a pointer to the hashmap.
      HashIterator<Key, T, Compare, Hash> newIt(bucket, it, this);

      // Some compilers don't like make_pair here
      pair<HashIterator<Key, T, Compare, Hash>, bool> p(newIt, false);
      return p;
   } else {
      // We didn't find the element, so insert a new one.
      mSize++;
      auto endIt = (*mElems)[bucket].insert((*mElems)[bucket].end(), x);
      pair<HashIterator<Key, T, Compare, Hash>, bool> p(
	   HashIterator<Key, T, Compare, Hash>(bucket, endIt, this), true);
      return p;
   }
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::iterator
hashmap<Key, T, Compare, Hash>::insert(typename hashmap<Key, T, Compare,
	Hash>::iterator position, const value_type& x) {
   // completely ignore position
   return insert(x).first;
}

template <typename Key, typename T, typename Compare, typename Hash>
template <class InputIterator>
void hashmap<Key, T, Compare, Hash>::insert(InputIterator first,
					    InputIterator last) {
   // Copy each element in the range by using an insert_iterator
   // adapter. Give begin() as a dummy position -- insert ignores it
   // anyway.
   insert_iterator<hashmap<Key, T, Compare, Hash>> inserter(*this, begin());
   copy(first, last, inserter);
}

/*
  template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::insert(initializer_list<value_type> il)
{
insert(il.begin(), il.end());
}
*/

template <typename Key, typename T, typename Compare, typename Hash>
pair<typename hashmap<Key, T, Compare, Hash>::iterator, bool>
	hashmap<Key, T, Compare, Hash>::emplace(value_type&& x) {
	size_t bucket;
	// Try to find the element
	auto it = findElement(x.first, bucket);

	if (it != (*mElems)[bucket].end()) {
		// The element already exists
		// Convert the list iterator into a HashIterator, which
		// also requires the bucket and a pointer to the hashmap.
		HashIterator<Key, T, Compare, Hash> newIt(bucket, it, this);

		// Some compilers don't like make_pair here
		pair<HashIterator<Key, T, Compare, Hash>, bool> p(newIt, false);
		return p;
	} else {
		// We didn't find the element, so emplace a new one.
		mSize++;
		auto endIt = (*mElems)[bucket].emplace((*mElems)[bucket].end(), x);
		pair<HashIterator<Key, T, Compare, Hash>, bool> p(
			HashIterator<Key, T, Compare, Hash>(bucket, endIt, this), true);
		return p;
	}
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::iterator
hashmap<Key, T, Compare, Hash>::emplace_hint(
					     typename hashmap<Key, T, Compare, Hash>::iterator hint, value_type&& x) {
   // completely ignore hint
   return emplace(forward<value_type>(x)).first;
}


template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::size_type
hashmap<Key, T, Compare, Hash>::erase(const key_type& x) {
   size_t bucket;

   // First, try to find the element
   auto it = findElement(x, bucket);

   if (it != (*mElems)[bucket].end()) {
      // The element exists -- erase it
      (*mElems)[bucket].erase(it);
      mSize--;
      return 1;
   } else {
      return 0;
   }
}

template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::erase(
    typename hashmap<Key, T, Compare, Hash>::iterator position) {
   // Erase the element from its bucket
   (*mElems)[position.mBucket].erase(position.mIt);
   mSize--;
} 

template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::erase(
       typename hashmap<Key, T, Compare, Hash>::iterator first, 
       typename hashmap<Key, T, Compare, Hash>::iterator last) {
   typename hashmap<Key, T, Compare, Hash>::iterator cur, next;

   // erase all the elements in the range
   for (next = first; next != last; ) {
      cur = next++;
      erase(cur);
   }
}

template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::clear() {
   // Call clear on each list.
   for_each(mElems->begin(), mElems->end(), [](ListType& e){e.clear();});
   mSize = 0;
}


template <typename Key, typename T, typename Compare, typename Hash>
bool hashmap<Key, T, Compare, Hash>::empty() const {
   return mSize == 0;
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::size_type
hashmap<Key, T, Compare, Hash>::size() const {
   return mSize;
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::size_type
hashmap<Key, T, Compare, Hash>::max_size() const {
   // In the worst case, all the elements hash to the same
   // list, so the max_size is the max_size of a single list.
   // This code assumes that all the lists have the same max_size.
   return (*mElems)[0].max_size();
}

// Just swap the four data members. Use the generic swap template.
template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::swap(hashmap<
					  Key, T, Compare, Hash>& hashIn) {
   // explicitly qualify with std:: so the compiler doesn't think
   // it's a recursive call.
   std::swap(*this, hashIn);
} 

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::iterator
	hashmap<Key, T, Compare, Hash>::begin() {
	if (mSize == 0) 
	   // Special case: there are no elements, so return the end iterator
	   return end();

	// We know there is at least one element. Find the first element
	for (size_t i = 0; i < mElems->size(); ++i) {
	   if (!((*mElems)[i].empty())) {
	      return HashIterator<Key, T, Compare, Hash>(i,
		        (*mElems)[i].begin(), this);
	   }
       }
       // should never reach here, but if we do, return the end iterator
       return end();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::iterator
hashmap<Key, T, Compare, Hash>::end() {
   // The end iterator is just the end iterator of the list in last bucket
   return HashIterator<Key, T, Compare, Hash>(mElems->size() - 1,
	  (*mElems)[mElems->size() - 1].end(), this);
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::const_iterator
	hashmap<Key, T, Compare, Hash>::begin() const {
		if (mSize == 0) {
			// Special case: there are no elements, so return the end iterator
			return end();
		}

		// We know there is at least one element. Find the first element
		for (size_t i = 0; i < mElems->size(); ++i) {
			if (!((*mElems)[i].empty())) {
				return HashIterator<Key, T, Compare, Hash>(i,
					(*mElems)[i].begin(), this);
			}
		}
		// should never reach here, but if we do, return the end iterator
		return end();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::const_iterator
hashmap<Key, T, Compare, Hash>::cbegin() const {
   return const_cast<const hashmap<Key, T, Compare, Hash>*>(this)->begin();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::const_iterator
hashmap<Key, T, Compare, Hash>::end() const {
   // The end iterator is just the end iterator of the list in last bucket
   return HashIterator<Key, T, Compare, Hash>(mElems->size() - 1,
          (*mElems)[mElems->size() - 1].end(), this);
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::const_iterator
hashmap<Key, T, Compare, Hash>::cend() const {
   return const_cast<const hashmap<Key, T, Compare, Hash>*>(this)->end();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::key_compare
hashmap<Key, T, Compare, Hash>::key_comp() const {
   return mComp;
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::value_compare
hashmap<Key, T, Compare, Hash>::value_comp() const {
   return value_compare(mComp);
}
