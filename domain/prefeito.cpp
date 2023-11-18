#include "prefeito.h"

Prefeito::Prefeito(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade) : Candidato(numTitulo, nome, zona, secao, numero, nomePartido, cidade) {}

Prefeito *Prefeito::fromString(std::string line)
{
  Candidato *candidato = Candidato::fromString(line);
  Prefeito *prefeito = new Prefeito(candidato->getNumTitulo(), candidato->getNome(), candidato->getZona(), candidato->getSecao(), candidato->getNumero(), candidato->getNomePartido(), candidato->getCidade());
  delete candidato;
  return prefeito;
}