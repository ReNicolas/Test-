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
    /*! 
     *   @param[out] the number of neurons in the network
     */
    size_t size() const;
     /*! 
      *   Creates the network's links
      *   @param[in] mean number of links a neuron receives
      */
    void createLinks(double mean);
     /*! 
      *   Updates each neuron's potential and relaxation
      */
    void update();
    
    vector<size_t>


private:
    multimap<size_t,Synapse > synapses;
    vector<Neurone*> neurones;
    size_t NInhibiteurs, NExcitateurs;
};
