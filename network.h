#include <map>
#include <vector>
#include "neurone.h"
using namespace std;


struct Synapse{
	size_t neurone;
	double intensity;
};
	
class Network {

public:
    Network(size_t neurones, double proportionExc, double mean);
    
    size_t size() const;
    
    void createLinks(double mean);


private:
    multimap<size_t,Synapse > synapses;
    vector<Neurone*> neurones;
    size_t NInhibiteurs, NExcitateurs;
};
