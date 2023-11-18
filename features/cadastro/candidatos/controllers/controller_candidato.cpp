#include "controller_candidato.h"
#include "vereador.h"
#include "prefeito.h"
#include "iostream"
#include "string"
#include <vector>
#include <typeinfo>
#include "exception_invalid_format.h"

// Classe para controlar todas as operações com os candidatos (vereador ou prefeito)

template <typename T>
ControllerCandidato<T>::ControllerCandidato(State *state, MenuEditarCandidato<T> *menuEditarCandidato, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *controllerDadosCandidato) : _state(state), _menuEditarCandidato(menuEditarCandidato), _controllerDadosEleitor(controllerDadosEleitor), _controllerDadosCandidato(controllerDadosCandidato) {}

template <typename T>
RetornoController ControllerCandidato<T>::listCandidato()
{
  std::vector<Candidato *> listaCandidatos;
  std::cout << "Lista de ";
  if (typeid(T) == typeid(Vereador))
  {
    listaCandidatos = _state->getListaVereador();
    std::cout << "Vereadores" << std::endl;
  }
  else
  {
    listaCandidatos = _state->getListaPrefeito();
    std::cout << "Prefeitos:" << std::endl;
  }
  if (listaCandidatos.size())
  {
    std::cout << listaCandidatos[0]->getNome() << std::endl;
    for (auto candidato : listaCandidatos)
      std::cout << "NÚMERO: " << candidato->getNumTitulo() << " NOME: " << candidato->getNome() << std::endl;
  }
  else
    std::cout << "(Lista vazia)" << std::endl;
  hold();
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::addCandidato()
{
  int numTitulo, numero = 1;
  std::string nome, zona, secao, nomePartido = "PT", cidade = "BH";
  std::cout << "Cadastro de ";
  if (typeid(T) == typeid(Vereador))
    std::cout << "Vereador:" << std::endl;
  else
    std::cout << "Prefeito:" << std::endl;
  std::cout << "Nº Título: ";
  numTitulo = readNumber<int>(
      [&](int numTitulo)
      { return _controllerDadosEleitor->validaNumTitulo(numTitulo, false); });
  std::cout << "Nome: ";
  nome = readLine();
  std::cout << "Zona: ";
  zona = readLine();
  std::cout << "Seção: ";
  secao = readLine();
  std::cout << "Número: ";
  numero = readNumber<int>(
      [&](int numero)
      { return _controllerDadosCandidato->validaNumero(numero, false); });
  std::cout << "Nome do Partido: ";
  nomePartido = readLine();
  std::cout << "Cidade: ";
  cidade = readLine();
  if (typeid(T) == typeid(Vereador))
    _state->addVereador(new Vereador(numTitulo, nome, zona, secao, numero, nomePartido, cidade));
  else
    _state->addPrefeito(new Prefeito(numTitulo, nome, zona, secao, numero, nomePartido, cidade));
  std::cout << "Candidato adicionado!" << std::endl;
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::viewCandidato()
{
  int numero;
  std::cout << "Informe o Número: ";
  numero = readNumber<int>();
  Candidato *candidato;
  if (typeid(T) == typeid(Vereador))
    candidato = _state->buscaVereador(numero);
  else
    candidato = _state->buscaPrefeito(numero);
  if (candidato)
  {
    std::cout << "Dados do Candidato:" << std::endl;
    std::cout << "Nº Titulo: " << candidato->getNumTitulo() << std::endl;
    std::cout << "Nome: " << candidato->getNome() << std::endl;
    std::cout << "Zona: " << candidato->getZona() << std::endl;
    std::cout << "Seção: " << candidato->getSecao() << std::endl;
    std::cout << "Número: " << candidato->getNumero() << std::endl;
    std::cout << "Nome do Partido: " << candidato->getNomePartido() << std::endl;
    std::cout << "Cidade: " << candidato->getCidade() << std::endl;
    hold();
  }
  else
  {
    std::cout << "Candidato não encontrado!" << std::endl;
  }
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::editCandidato()
{
  int numero;
  std::cout << "Informe o Número: ";
  numero = readNumber<int>();
  Candidato *candidato;
  if (typeid(T) == typeid(Vereador))
    candidato = _state->buscaVereador(numero);
  else
    candidato = _state->buscaPrefeito(numero);
  if (candidato)
  {
    _state->setCandidatoEdit(candidato);
    _menuEditarCandidato->executar();
    std::cout << "Edições finalizadas!" << std::endl;
  }
  else
    std::cout << "Candidato não encontrado!" << std::endl;
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::deleteCandidato()
{
  int numero;
  std::cout << "Informe o Número: ";
  numero = readNumber<int>();
  Candidato *candidato;
  if (typeid(T) == typeid(Vereador))
    candidato = _state->buscaVereador(numero);
  else
    candidato = _state->buscaPrefeito(numero);
  if (candidato)
  {
    if (typeid(T) == typeid(Vereador))
      _state->deletaVereador(numero);
    else
      _state->deletaPrefeito(numero);
    std::cout << "Candidato deletado!" << std::endl;
  }
  else
    std::cout << "Candidato não encontrado!" << std::endl;
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::importCandidato()
{
  std::string path;
  std::cout << "Importação de ";
  if (typeid(T) == typeid(Vereador))
    std::cout << "Vereadores:" << std::endl;
  else
    std::cout << "Prefeitos:" << std::endl;
  std::cout << "Bem-vindo à importação de candidatos!" << std::endl;
  std::cout << "Forneça um arquivo com cada linha no seguinte padrão:" << std::endl;
  std::cout << "'numTitulo;nome;zona;secao;numero;nomePartido;cidade'." << std::endl;
  std::cout << ">>> Informe o caminho completo para o arquivo: ";
  path = readLine();
  std::ifstream arquivo(path, std::ios::in);
  std::string line;
  int i = 0;
  Candidato *candidato;
  while (std::getline(arquivo, line))
  {
    i++;
    try
    {
      if (typeid(T) == typeid(Vereador))
        candidato = Vereador::fromString(line);
      else
        candidato = Prefeito::fromString(line);
    }
    catch (std::invalid_argument e)
    {
      std::cout << "Linha " << i << " - Falha: Nº Título deve ser um número!" << std::endl;
      continue;
    }
    catch (ExceptionInvalidFormat e)
    {
      std::cout << "Linha " << i << " - Falha: Formato errado!" << std::endl;
      continue;
    }
    if (_state->checaExisteNumTitulo(candidato->getNumTitulo()))
    {
      std::cout << "Linha " << i << " - Falha: Nº Título já cadastrado!" << std::endl;
      continue;
    }
    if (_state->checaExisteNumero(candidato->getNumero()))
    {
      std::cout << "Linha " << i << " - Falha: Número já cadastrado!" << std::endl;
      continue;
    }
    if (typeid(T) == typeid(Vereador))
      _state->addVereador(dynamic_cast<Vereador *>(candidato));
    else
      _state->addPrefeito(dynamic_cast<Prefeito *>(candidato));
  }
  std::cout << "Importação finalizada!" << std::endl;
  arquivo.close();
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::exportCandidato()
{
  std::string path;
  std::cout << "Exportação de ";
  if (typeid(T) == typeid(Vereador))
    std::cout << "Vereadores:" << std::endl;
  else
    std::cout << "Prefeitos:" << std::endl;
  std::cout << ">>> Informe o caminho completo para o arquivo de saída: ";
  path = readLine();
  std::ofstream arquivo(path, std::ios::out);
  std::vector<Candidato *> listaCandidatos;
  if (typeid(T) == typeid(Vereador))
    listaCandidatos = _state->getListaVereador();
  else
    listaCandidatos = _state->getListaPrefeito();
  for (auto candidato : listaCandidatos)
    arquivo << candidato->getNumTitulo() << ";" << candidato->getNome() << ";" << candidato->getZona() << ";" << candidato->getSecao() << ";" << candidato->getNumero() << ";" << candidato->getNomePartido() << ";" << candidato->getCidade() << std::endl;
  std::cout << "Exportação finalizada!" << std::endl;
  arquivo.close();
  return RetornoController::Completo;
}

template class ControllerCandidato<Vereador>;
template class ControllerCandidato<Prefeito>;