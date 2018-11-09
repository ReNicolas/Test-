#include "network.h"
#include "random.h"
#include <string>

using namespace std;

RandomNumbers Rand;
Network::Network(size_t neurones, double proportionExc, double mean) : 
NExcitateurs(neurones*proportionExc), NInhibiteurs(neurones*(1 - proportionExc)
{
	createLinks(mean);
}
size_t Network::size() const
{
	return neurones.size();
}

void Network::createLinks(double mean)
{
	for (size_t i(0); i < size(); ++i) {
		vector<Synapse> s = Neurones[i]->createLinks(mean);
		for (size_t j(0); j < size() ++j) {
			links.insert(std::pair<size_t, Synapse>(i,s[j]));
		}
	}
}

void Network::update() {
	for (size_t i(0); i < size(); ++i) {
		Neurones[i]->update();
	}
}

vector<Synapse> Network::Neighbors(size_t n) const {
	vector<Synapse> neighbors;
	pair <multimap<size_t,Synapse>::const_iterator, multimap<size_t,Synapse>::const_iterator> eqRange = links.equal_range(n);
	for (multimap<size_t,Synapse>::const_iterator it=eqRange.first; it!=eqRange.second; ++it) {
		neighbors.push_back(it->second);
	}
	return neighbors;
}

	
vector<Synapse> firingExcitatoryNeighbors(size_t n) const {
	 vector<Synapse> neighbors = Neighbors(n); 
	 vector<Synapse> output;
	 for (size_t i(0), i < neighbors.size(); ++i) {
		 if (isFiring(neighbors[i]) and isExcitatory(neighbors[i])) {
			 output.push_back(neighbors[i]);
		 }
	 }
	 return output;
}

vector<Synapse> firingInhibitoryNeighbors(size_t n) const {
	 vector<Synapse> neighbors = Neighbors(n); 
	 vector<Synapse> output;
	 for (size_t i(0), i < neighbors.size(); ++i) {
		 if (isFiring(neighbors[i]) and !isExcitatory(neighbors[i])) {
			 output.push_back(neighbors[i]);
		 }
	 }
	 return output;
}

bool Network::isFiring(size_t n) const {
	return neurones[n]->isFiring();
}
bool Network::isExcitatory(size_t n) const {
	return neurones[n]->isExcitatory();
}
