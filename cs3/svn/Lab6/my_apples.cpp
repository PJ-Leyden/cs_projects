// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// P.J. Leyden
// 10/03/2018


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Apples{
   Apples(){};
   Apples(const Apples &a){color = a.color; weight = a.weight;}
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};



int main(){
   srand(time(nullptr));
   const double minWeight = 8.;
   const double maxWeight = 3.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   cout << "===APPLES CRATE MADE===\n";

   // assign random weight and color to apples in the crate
   // replace with generate()

   

   cout << "===GENERATE APPLES===\n";
   std::generate(crate.begin(), crate.end(), 
    [minWeight, maxWeight](){
		   Apples apple;
		   apple.weight = minWeight + static_cast<double>(rand())/RAND_MAX * (maxWeight - minWeight);
		   apple.color = rand() % 2 == 1 ? "green" : "red";
		   return apple;
    });

 


   cout << "===APPLE WEIGHTS===\n";
   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // count_if()
   int cnt = std::count_if(crate.cbegin(), crate.cend(), [toFind](Apples a){return a.weight > toFind;});

   cout << "===APPLE POSITIONS===\n";
   cout << "There are " << cnt << " apples heavier than " 
	<< toFind << " oz" <<  endl;

   // find_if()
   cout << "at positions \n";
   auto itr = std::find_if(crate.cbegin(), crate.cend(), [toFind](Apples a){return a.weight > toFind;});
   while(itr != crate.cend()){

      itr->print();
      itr = std::find_if(itr + 1, crate.cend(), [toFind](Apples a){return a.weight > toFind;});

   }

   cout << endl;

   cout << "===MAX APPLE===\n";
   // max_element()
   itr = std::max_element(crate.cbegin(), crate.cend(), [](Apples a, Apples b){return a.weight < b.weight;});
   cout << "Heaviest apple weighs: " << itr->weight << " oz" << endl;


   cout << "===TOTAL WEIGHT===\n";
   // for_each() or accumulate()
   double sum = 0;
   std::for_each(crate.begin(), crate.end(), [&sum](Apples a){sum += a.weight;});
   cout << "Total apple weight is: " << sum << " oz" << endl;


   cout << "===APPLE GROWTH===\n";
   // transform();
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;

   std::transform(crate.begin(), crate.end(), crate.begin(), [toGrow](Apples a){Apples res;
                                                                                 res.weight = a.weight + toGrow;
                                                                                 res.color = a.color;
                                                                                 return res;
                                                                               });


   cout << "===APPLE REMOVAL===\n";
   // remove_if()
   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;
   
   crate.erase(std::remove_if(crate.begin(), crate.end(), [minAccept](Apples &a){return a.weight < minAccept;}), crate.end());
	 
   cout << "removed " << size - crate.size() << " elements" << endl;


   cout << "===APPLE SORT===\n";
   // bubble sort, replace with sort()
   std::sort(crate.begin(), crate.end(), [](Apples a, Apples b){return a.weight < b.weight;});

   cout << "APPLES IN CRATE: \n";
   std::for_each(crate.begin(), crate.end(), [](Apples &a){a.print();});

   cout << "\n===APPLE DISTRABUTION===\n";
   // moving all red apples from crate to peck
   // remove_copy_if() with back_inserter()/front_inserter() or equivalents
   deque<Apples> peck(size);
   crate.erase(std::remove_copy_if(crate.begin(), crate.end(), peck.begin(), [](Apples &a){return a.color == "red";}), crate.end());

   // for_each() possibly
   cout << "apples in the crate"<< endl;
   std::for_each(crate.begin(), crate.end(), [](Apples &a){if(a.color != "")a.print();});

   cout << endl;

   // for_each() possibly
   cout << "apples in the peck"<< endl;
   std::for_each(peck.begin(), peck.end(), [](Apples &a){if(a.color != "")a.print();});


   // prints every "space" apple in the peck
   // 
   const int space=3; 
   cout << "\nevery " << space << "\'d apple in the peck"<< endl;

   // replace with advance()/next()/distance()
   // no pointer arithmetic
   int i = 1;
   auto deqitr = peck.begin();
   while(deqitr != peck.end()){
      if(deqitr->color != "" && i%3 == 0)deqitr->print();
      std::advance(deqitr, 1);
      ++i;
   }

   class make_jam{
   private:
     double jamWeight = 0;
   public:
     make_jam(){};
     void operator()(vector<Apples> crt, double max_weight){
       for(auto &itr : crt){
	 if(itr.weight < max_weight){
	   jamWeight += itr.weight;
	 }
       }
     };
     double get_jam_weight(){return jamWeight;};

   };


   // putting all small green apples in a jam
   // use a binder to create a functor with configurable max weight
   // count_if() then remove_if()
   const double weightToJam = 16.0;
   double jamWeight = 0; 

   make_jam jammer;

   auto bound_jammer = std::bind(jammer, crate, std::placeholders::_1);
   

   bound_jammer(weightToJam);

   cout << "Weight of jam is: " << jammer.get_jam_weight() << endl;

}

