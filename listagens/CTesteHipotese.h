#ifndef CTesteHipotese_h
#define CTesteHipotese_h

#include <iostream>

#include "CDistTStudent.h"
#include "CDistNormal.h"
#include "CDistChiQuadrado.h"

////////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteHipotese
/// @file CTesteHipotese.h
/// @brief Classe representativa do teste de hipoteses.
////////////////////////////////////////////////////////////////////////

enum ETipoTesteHipotese{esquerda, direita, bilateral};

class CTesteHipotese : public CDistNormal, public CDistTStudent, public CDistChiQuadrado
{  
protected:
  
  /// Hipotese nula
  double h0; 	
  
  /// caso --> unicaudal a esquerda, unicaudal a direita ou bicaudal.
  /// Comparar a entrada do usuario e executar o teste correto.
  int caso; 
  
public: 
  ///
  /// Metodo virual puro.
  virtual void Compara() = 0;
  
  ///
  /// Metodo virtual puro.
  virtual void Entrada() = 0;
  
  ///
  /// Metodo virtual puro.
  virtual double Calcular() = 0;
};
#endif
