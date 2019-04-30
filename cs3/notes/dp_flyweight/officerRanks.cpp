// flyweight
// Mikhail Nesterenko
// 4/21/2016

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;

enum class rank {lieutenant, captain, major, general};

// abstract flyweight
class Rank{
public:
   virtual string image() = 0;
};

// concrete flyweights
class Lieutenant: public Rank{
public:
   string image(){ return "*"; }
};


class Captain: public Rank{
   string image() { return "**"; }
};

class Major: public Rank{
public:
   string image() { return "***"; }
};

class General: public Rank{
public:
   string image() { return "****"; }
};


// factory
class Academy{
public:
   static Rank *makeRank(rank r){
     // if officer rank not found
     if(ranks_.find(r) == ranks_.end())
	 switch(r){
	 case rank::lieutenant:
	    ranks_[r] = new Lieutenant; break;
	 case rank::captain:
	    ranks_[r] = new Captain; break;
	 case rank::major:
	    ranks_[r] = new Major; break;
	 case rank::general:
	    ranks_[r] = new General; break;
	 }
      return ranks_[r];
   }
private:
   static std::map<rank, Rank*> ranks_;
}; 

std::map<rank, Rank*> Academy::ranks_;


// client with extrinsic state
class Officer{
public:
   Officer(string name, rank r): name_(name){
      rank_ = Academy::makeRank(r);
   }

   void report() const{
      std::cout << name_ << ' '
		<< rank_ -> image() << std::endl;
   }

private:
   string name_;
   Rank *rank_;
};

int main(){
   std::vector<Officer*> troops = {
      new Officer("David Johnson", rank::lieutenant),
      new Officer("Derek Blake", rank::general),
      new Officer("Nick Allen", rank::lieutenant),
      new Officer("Shirley Parker", rank::major)
   };

   for(const auto e: troops)
      e -> report();
}
