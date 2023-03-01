#ifndef CRegressaoLinear_h
#define CRegressaoLinear_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "CSolverRL.h"
#include "CGnuplot.h"


/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CRegressaoLinear
 * @file CRegressaoLinear.h
 * @brief Classe representativa da regressao linear.
 */


class CRegressaoLinear : public CSolverRL { 
protected:
  /// Coeficiente angular da reta obtida.
  double a;   
  
  /// Coeficiente linear da reta obtida.
  double b; 
  
  /// Coeficiente de correlacao.
  double r; 
  
  /// string com a equacao a ser plotada.
  std::string equacao;  
  
  /// Grafico.
  CGnuplot* grafico; 
  
  ///
  /// Arquivo de disco.
  std::ofstream fout;
public:
  /// Metodo que retorna o coeficiente angular.
  /// @return Coeficiente angular.
  double A();  
  
  /// Metodo que retorna o coeficiente linear.
  /// @return Coeficiente linear.
  double B();  	
  
  /// Metodo que retorna uma string com a equacao. 
  /// @return String com a equacao em forma de texto.
  std::string Equacao();
  
  /// Metodo que calcula e mostra na tela o coeficiente de correlacao.
  void Correlacao();    
  
  /// Metodo que mostra na tela a equacao da reta obtida com a regressao.
  void ExibirEquacao();
  
   /// Metodo que plota a reta obtida com a regressao linear com o auxilio do Gnuplot.
  void Plotar(); 
  
  /// Metodo de entrada dos dados e informacoes adicionais.
  void Entrada();
  
  /// Salva resultado em arquivo de disco.
  void Salvar();
};
#endif
