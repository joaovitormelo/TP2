#include "controller_candidato.h"

template <typename T>
ControllerCandidato<T>::ControllerCandidato(State *state, MenuEditarEleitor *menuEditarEleitor) : _state(state), _menuEditarEleitor(menuEditarEleitor) {}

template <typename T>
RetornoController ControllerCandidato<T>::listCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::addCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::viewCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::editCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::deleteCandidato()
{
  return RetornoController::Completo;
}

template class ControllerCandidato<Vereador>;
template class ControllerCandidato<Prefeito>;