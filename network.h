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
     /*! 
	  * @param[in] the index of the neuron
	  * @param[out] a vector containing the indexes of all
					neurons connected to neuron, and the intensity of each link.
	*/
    vector<size_t> Neighbors(size_t n) const;
    /*! 
		@param[in] the index of the neuron
		@param[out] a vector containing the indexes of all excitatory 
					neurons connected to neuron n and firing, and the intensity of each link.
	*/
	
    vector<size_t> firingExcitatoryNeighbors(size_t n) const;
     /*! 
	  * @param[in] the index of the neuron
	  * @param[out] a vector containing the indexes of all inhibitory
					neurons connected to neuron n and firing, and the intensity of each link.
	*/
    vector<size_t> firingInhibitoryNeighbors(size_t n) const; 
     
    /*!
     * 	@param[in] the index of the neuron
     * @param[out] true if the neuron is firing
     */
    bool isFiring(size_t n) const;
    /*!
     * 	@param[in] the index of the neuron
     * @param[out] true if the neuron is excitatory
     */
    bool isExcitatory(size_t n) const;


private:
    multimap<size_t,Synapse > synapses;
    vector<Neurone*> neurones;
    size_t NInhibiteurs, NExcitateurs;
};
