#include "vereador.h"

Vereador::Vereador(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade) : Candidato(numTitulo, nome, zona, secao, numero, nomePartido, cidade) {}

Vereador *Vereador::fromString(std::string line)
{
  Candidato *candidato = Candidato::fromString(line);
  Vereador *vereador = new Vereador(candidato->getNumTitulo(), candidato->getNome(), candidato->getZona(), candidato->getSecao(), candidato->getNumero(), candidato->getNomePartido(), candidato->getCidade());
  delete candidato;
  return vereador;
}