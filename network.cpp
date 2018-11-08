#include "network.h"
#include "random.h"
#include <string>

using namespace std;

RandomNumbers Rand;

size_t Network:: size() const
{
	return values.size();
}

void Network:: random_connect(const double& lambda)
{
	synapses.clear();
	for ( size_t i(0); i<neurone.size(); i++){
		int newlinks(Rand.poisson(lambda)); // Tire un nombre aleatoire de synapses a creer pour chaque neurone
		vector <int> newlinks (neurone.size());
		vector <bool> valuelinks(newlinks); 
		Rand.uniform_int(newlinks,0,neurone.size()-1); // Tire des nouveaux synapses 
		Rand.uniform_double(valuelinks,0,1); // Tire une valeur aleatoire pour l intensite du lien
		
		
		for ( int j(0); j< newlinks; j++){
			liens.neurone = newlinks[j]; 
			liens.intensity = valuelinks[j]; // Ici j'ai essaye de remplir la structure avec un neurone et une valeur pris aleatoirement juste au dessus 
			synapse.add_link(////) // Ici i faut encore coder une fonction pour ajouter le lien ( ou reutiliser celle de l'exercice  a rendre)
			}
	}
}



