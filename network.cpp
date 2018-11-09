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



