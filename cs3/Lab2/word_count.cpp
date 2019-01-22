//File: word_count.cpp
//Code by: P.J. Leyden
//Date: Jan 22nd, 2019

#include "word_count.hpp"

WordOccurrence::WordOccurrence(const std::string& word, int num):word_(word), num_(num){}

bool WordOccurrence::matchWord(const std::string& rhs){
	return (word_ == rhs);
	
}

void WordOccurrence::increment(){
	++num_;
}

std::string WordOccurrence::getWord()const{
	return word_;
}

int WordOccurrence::getNum()const{
	return num_;
}

//=====================================
WordList::WordList(const WordList& orig){
	size_ = orig.size_;
	wordArray_ = new WordOccurrence[size_];
	for(int i = 0; i < size_; ++i){
		wordArray_[i] = orig.wordArray_[i];
	}
}

WordList::~WordList(){
	if(wordArray_ != nullptr){
		delete[] wordArray_;
	}
}

WordList& WordList::operator=(const WordList& rhs){
	size_ = rhs.size_;
	if(wordArray_ != nullptr){
		delete[] wordArray_;
	}
	wordArray_ = new WordOccurrence[size_];
	for(int i = 0; i < size_; ++i){
		wordArray_[i] = rhs.wordArray_[i];
	}
	return *this;
}

bool equal(const WordList& wl1, const WordList& wl2){
	bool result = true;
	if(wl1.size_ == wl2.size_){
		for(int i = 0; i < wl1.size_; ++i){
			if(!wl1.wordArray_[i].matchWord(wl2.wordArray_[i].getWord())){
				result = false;
			}
		}
	}else{
		result = false;
	}

	return result;
}

void WordList::addWord(const std::string& w){
	//find if word already in list
	int indx = -1;
	for(int i = 0; i < size_; ++i){
		if(wordArray_[i].getWord() == w){
			indx = i;
			break;
		}
	}

	//if it is increment
	if(indx > -1){
		wordArray_[indx].increment();
	// if it isn't expand
	}else{
		WordOccurrence *tmp = new WordOccurrence[size_ + 1];
		for(int i = 0; i < size_; ++i){
			tmp[i] = wordArray_[i];
		}
		WordOccurrence wo(w, 1);
		tmp[size_] = wo;
		if(wordArray_ != nullptr){
			delete[] wordArray_;
		}
		wordArray_ = tmp;
		++size_;
	}
}

void WordList::print(){
	for(int i = 0; i < size_; ++i){
		std::cout << i << ") ";
		std::cout << wordArray_[i].getWord() << " : " << wordArray_[i].getNum();
		std::cout << std::endl;
	}
}