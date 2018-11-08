#include <map>
#include <vector>
#include "neurone.h"
using namespace std;


struct Synapse{
	size_t neurone;
	double intensity;
} liens;
	
class Network {

public:
    Network() {}
    
    void random_connect(const double&);
    
    size_t size() const;


private:
    multimap<size_t,Synapse > synapses;

};
