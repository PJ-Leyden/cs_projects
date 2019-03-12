// implementation basic hashmap (unordered container)
// Mikhail Nesterenko: adapted from Proc C++
// 4/15/2014

#include <cstddef>
#include <utility>
#include <functional>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::pair;
using std::make_pair;

//////////////////////////////////////////
// hash function implemented as a class
//////////////////////////////////////////

// any Hash Class must provide 
// two methods: hash() and numBuckets().
template <typename T>
class DefaultHash {
public:
	DefaultHash(size_t numBuckets = defaultNumBuckets);
	size_t hash(const T& key) const;
	size_t numBuckets() const { return numBuckets_; }

private:
	// default number of buckets in the hash
	static const size_t defaultNumBuckets = 101; 
	size_t numBuckets_;
};

template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets) : numBuckets_(numBuckets) {}


// uses the division method for hashing.
// treats the key as a sequence of bytes, sums the ASCII
// values of the bytes, and mods the total by the number
// of buckets.
template <typename T>
size_t DefaultHash<T>::hash(const T& key) const {
	size_t res = 0;
	for (size_t i = 0; i < sizeof(key); ++i) {
		const unsigned char b = *(reinterpret_cast<const unsigned char *>(&key) + i);
		res += b;
	}
	return res % numBuckets_;
}


////////////////////////////////////////////////
// container class
////////////////////////////////////////////////

template <typename Key, typename Value, 
		  typename Compare = std::equal_to<Key>,
		  typename Hash = DefaultHash<Key>>
class hashmap{

public:
	typedef pair<const Key, Value> Element;

	// constructor
	// invokes constructors for comparison and hash objects
						 hashmap(const Compare& comp = Compare(), const Hash& hash = Hash());

	Element*             find(const Key& x);    	  // returns pointer to element with key x,
													  // nullptr if not found
	pair<Element*, bool> insert(const Element& x);    // inserts the key/value pair 
	pair<Element*, bool> erase(const Key& x);         // erases element with key x, if exists
	Value&               operator[] (const Key& x);   // returns reference on value of
													  // element with key, inserts if does not exist
	void                 rehash(size_t n);
private:

	// helper function for various searches
	typename list<Element>::iterator findElement(const Key& x, const size_t bucket);

	size_t size_;   // number of elements in the container
	Compare comp_;  // comparison functor, equal_to by default
	Hash hash_;     // hash functor 

	// hash contents: vector of buckets
	// each bucket is a list containing key->value pairs
	vector<list<Element>> elems_;
};


////////////////////////////////////////////////
// container member functions
////////////////////////////////////////////////

// Construct elems_ with the number of buckets.
template <typename Key, typename Value, typename Compare, typename Hash>
	hashmap<Key, Value, Compare, Hash>::hashmap(
	const Compare& comp, const Hash& hash):
	size_(0), comp_(comp), hash_(hash) {
		elems_ = vector<list<Element>>(hash_.numBuckets());
}


//find a specific key in a specific bucket
template <typename Key, typename Value, typename Compare, typename Hash>
	typename list<pair<const Key, Value>>::iterator // return type CAN replace with list<Element>::iterator
	hashmap<Key, Value, Compare, Hash>::findElement(const Key& x, size_t bucket){

	// look for the key in the bucket
	for (auto it =  elems_[bucket].begin(); it != elems_[bucket].end(); ++it)
		if (comp_(it->first, x))
			return it;

   return elems_[bucket].end(); // element not found
}


// returns a pointer to the element with key x
// returns nullptr if no element with this key
template <typename Key, typename Value, typename Compare, typename Hash>
	typename hashmap<Key, Value, Compare, Hash>::Element* // return value type
	hashmap<Key, Value, Compare, Hash>::find(const Key& x) {

	size_t bucket = hash_.hash(x);
	auto it=findElement(x, bucket);    // use the findElement() helper   

	if (it != elems_[bucket].end())
		// found the element. Return a pointer to it.
		return &(*it); // dereference the iterator to list 
					 // then take the address of list element
   
	else // didn't find the element -- return nullptr
		return nullptr;
}


// finds the element with key x, inserts an
// element with that key if none exists yet. Returns a reference to
// the value corresponding to that key.
template <typename Key, typename Value, typename Compare, typename Hash>
pair<typename hashmap<Key, Value, Compare, Hash>::Element*, bool> 
hashmap<Key, Value, Compare, Hash>::insert(const Element& x) {

	size_t bucket = hash_.hash(x.first);   
	auto it = findElement(x.first, bucket);    // try to find the element

	// if not found, insert a new one.
	if (it == elems_[bucket].end()) {

		++size_;
		elems_[bucket].push_back(x);
		it = findElement(x.first, bucket);
		return make_pair(&(*it), true);

	// iff did find
	}else{

		return make_pair(&(*it), false);

	}

}


// removes the Element with key x, if it exists
template <typename Key, typename Value, typename Compare, typename Hash>
pair<typename hashmap<Key, Value, Compare, Hash>::Element*, bool>
hashmap<Key, Value, Compare, Hash>::erase(const Key& x) {

	size_t bucket = hash_.hash(x);
	auto it = findElement(x, bucket);    // try to find the element
	int ret_mode = 0;

	if(it != elems_[bucket].end()){
		--size_;
		if(size_ == 0){
			elems_[bucket].erase(it);
			return make_pair(nullptr, true);	
		}

		if(++it != elems_[bucket].end()){ // return the next element in the bucket.
			it = elems_[bucket].erase(--it);
			return make_pair(&(*it), true);
		}else{ // return the begin of the next non empty bucket
			int b = bucket + 1;
			if(b >= hash_.numBuckets())b = 0;
			while(elems_[b].empty()){
				++b;
			}
			return make_pair(&(*elems_[b].begin()), true);
		}


	}else{
		return make_pair(nullptr, false);
	}

/*

	if (it != elems_[bucket].end()) {    // the element exists, erase it
		--size_;
		if(size == 0)ret_mode = 1;
		if(ret_mode != 1 && it + 1 == elems_[bucket].end() && bucket + 1 < hash_.numBuckets())ret_mode = 2;
		if(ret_mode != 1 && it + 1 == elems_[bucket].end() && bucket + 1 >= hash_.numBuckets())ret_mode = 3;

		elems_[bucket].erase(it);
		
		switch(ret_mode){
			case 1:
				return make_pair(nullptr, true);
			case 2:
				return make_pair(elems_[bucket + 1].begin(), true);
			case 3:
				return make_pair(elems_[0].begin(), true);
		}

	//if element doesn't exist
	}else{
		return make_pair(Element(), false);
	}
*/
}


// returns reference to value of element with key x,
// inserts if does not exist
template <typename Key, typename Value, typename Compare, typename Hash>
Value& hashmap<Key, Value, Compare, Hash>::operator[] (const Key& x) {

	auto p = insert(make_pair(x, Value()));
	return p.first->second;
/*
	Element* found = find(x);
	if (found == nullptr) { // if key not found, create new element with empty value
		insert(make_pair(x, Value())); // calling default constructor on Value
		found = find(x); // inefficient but avoids code duplication
	}
	return found->second;
*/
}

template <typename Key, typename Value, typename Compare, typename Hash>
void hashmap<Key, Value, Compare, Hash>::rehash(size_t n){
	//n is smaller or equal so no action
	if(n <= hash_.numBuckets()) return;


}
