#ifndef CTesteHipoteseDPdesconhecido_h
#define CTesteHipoteseDPdesconhecido_h
#include <iostream>
#include <cmath>
#include "CTesteHipotese.h"


////////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteHipoteseDPdesconhecido
/// @file CTesteHipoteseDPdesconhecido.h
/// @brief Classe representativa do teste de hipoteses com desvio padrao desconhecido.
////////////////////////////////////////////////////////////////////////

class CTesteHipoteseDPdesconhecido : public CTesteHipotese {
protected:  
  /// Valor para identificar o nivel de significancia
  int alpha; 
  
  /// Estatistica calculada
  double tcalc; 	
 
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;
  
public:  
  
  /// Metodo que calcula a estatistica do teste.
  /// @return estatistica do teste.
  double Calcular();		
  
  /// Metodo que retorna o valor da significancia.
  /// @return valor da significancia.
  double Alpha(); 			
  
  /// Metodo de entrada. Pede od dados e informacoes adicionais.
  void Entrada(); 			
  
  /// Metodo que compara a estatistica do teste e o valor critico e exibe o resultado na tela.
  void Compara(); 			
};
#endif


