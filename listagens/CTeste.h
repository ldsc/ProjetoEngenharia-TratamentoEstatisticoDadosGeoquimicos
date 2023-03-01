#ifndef CTeste_h
#define CTeste_h

#include <string>
#include <sstream>
#include <fstream>

#include "CEstatistica.h"

/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CTeste
 * @file CTeste.h
 * @brief Classe de interface para execucao dos testes de identificacao de outliers.
 */

class CTeste : public CEstatistica {
public:
  /// 
  /// Metodo virtual puro. 
  virtual void Entrada() = 0;
  
  ///
  /// Metodo virtual puro.
  virtual void Compara() = 0;
};
#endif
