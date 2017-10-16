#include "Station.h"
#include <fstream>

namespace w2{

	class Stations {
		int count;
		Station* stations;
	public:
		Stations(char* file);
		void update();
		void restock();
		void report();
		~Stations();
	};
}