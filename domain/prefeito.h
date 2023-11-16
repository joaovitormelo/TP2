#ifndef INF112_PREFEITO_H
#define INF112_PREFEITO_H
#include "candidato.h"
#include <string>

class Prefeito : public Candidato
{
public:
  Prefeito(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade);
};

#endif