#ifndef INF112_CANDIDATO_H
#define INF112_CANDIDATO_H
#include "eleitor.h"
#include <string>

class Candidato : public Eleitor
{
private:
  int _numero;
  std::string _nomePartido;
  std::string _cidade;
  int _totalVotos;

public:
  Candidato(int numTitulo, std::string nome, std::string zona, std::string secao, int numero, std::string nomePartido, std::string cidade);
  int getNumero();
  void setNumero(int numero);
  std::string getNomePartido();
  void setNomePartido(std::string nomePartido);
  std::string getCidade();
  void setCidade(std::string cidade);
  int getTotalVotos();
  void setTotalVotos(int totalVotos);
};

#endif