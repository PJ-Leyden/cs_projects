#ifndef AI_4_DATA
#define AI_4_DATA

struct Data{
		
	int num_data;
	int* d;

	Data(){num_data = 0; d = NULL;};
	Data(int nd){num_data = nd; d = new int[num_data];};

	friend std::ostream& operator<<(std::ostream& out, const Data& data){

		out << "Data: \n";
		for(int i = 0; i < data.num_data; i++){
			out << i << ": " << data.d[i] << '\n';
		}

		out << '\n';

	};

};

#endif