#include <string>
#include "../../inclusion/Reseau.h"

Reseau::Reseau(std::string adresseIpServeur, std::string adresseIpClient)
{
	this->adresseIpServeur = adresseIpServeur;
	this->adresseIpClient = adresseIpClient;
}