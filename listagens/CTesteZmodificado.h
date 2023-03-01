#ifndef CTesteZmodificado_h
#define CTesteZmodificado_h
#include "CTeste.h"
#include <vector>

class CTesteZmodificado : public CTeste {
public: 
  
  /// Vetor desvio absoluto |Xi - Xm|.
  std::vector<double> desvioAbsoluto; 
  
  /// Vetor desvio (Xi - Xm).
  std::vector<double> desvio;
  
  /// Mediana de |Xi - Xm|
  double mad; 		
  
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;			
  
  /// Vetor que armazena Zmod
  std::vector<double> zmod;
  
  /// Retorna a mediana de |Xi - Xm| --> mad
  /// @return mediana dos desvios absolutos.
  double Mad(); 
  
  /// Compara a estatistica calculada.
  void Compara(); 			
  
  /// Metodo que calcula o vetor de Zmod.
  void Z(); 		
  
  /// Metodo que calcula e preenche os vetores desvioAbsoluto e desvio.
  void DesvioAbs(); 	
  
  /// Metodo de entrada. Pede os dados e informacoes adicionais.
  void Entrada(); 			
  
};
#endif