#ifndef CTesteHipoteseDPconhecido_h
#define CTesteHipoteseDPconhecido_h

#include <iostream>
#include <cmath>

#include "CTesteHipotese.h"


////////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteHipoteseDPconhecido
/// @file CTesteHipoteseDPconhecido.h
/// @brief Classe representativa do teste de hipoteses com desvio padrao conhecido.
////////////////////////////////////////////////////////////////////////


class CTesteHipoteseDPconhecido : public CTesteHipotese {
protected:
  
  /// Desvio padrao conhecido da populacao.
  double sigma; 
  
  /// Zcalc - estatistica calculada.
  double zcalc;  	
  
  /// Identifica o nivel de significancia.
  double alpha; 
  
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;			
public:
  
  /// Calcula Zcalc.
  /// @return estatistica do teste.  
  double Calcular();
  
  /// Compara Zcalc e Z_alpha ou Z_alpha/2.
  void Compara(); 			
  
  /// Metodo de Entrada. Pede dados e informacoes adicionais.
  void Entrada(); 			

};
#endif
