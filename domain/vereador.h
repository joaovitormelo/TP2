#ifndef INF112_VEREADOR_H
#define INF112_VEREADOR_H
#include "candidato.h"
#include <string>

class Vereador : public Candidato
{
public:
  Vereador(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade, int totalVotos);
};

#endif