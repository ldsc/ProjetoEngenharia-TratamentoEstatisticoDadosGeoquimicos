#ifndef CTesteDixon_h
#define CTesteDixon_h

#include <algorithm>
#include <utility>

#include "CTeste.h"
///////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteDixon
/// @file CTesteDixon.h
/// @brief Classe representativa do teste de Dixon.
///////////////////////////////////////////////////////////////////////
/// <p>
/// O teste de Dixon atenta para a diferenca entre os valores maximo e minimo e seus valores vizinhos. 
/// E recomendado quando o numero de observacoes esta entre 3 e 25; Os dados sao ordenados de forma crescente e uma estatistica
/// e calculada para o maior ou menor valor, suspeito de ser um outlier. Depois de estabelecido um nivel de significancia, a estatistica
/// calculada e comparada com o valor critico. Se a estatistica calculada for maior que o valor critico, pode-se afirmar que o valor e um outlier, 
/// caso contrario, o valor nao e considerado um outlier.
/// <p>
///////////////////////////////////////////////////////////////////////

enum ETipoTesteDixon {menorDixon, maiorDixon };

class CTesteDixon : public CTeste {
protected:
  /// Serve para a identificacao do nivel de significancia desejado pelo usuario, que assume os valores de 0, 1 ou 2 nessa classe.
  int alpha;            
  
  /// Estatistica calculada caso o suspeito de ser outlier seja o maior numero.
  double z_maior;       
  
  /// Estatistica calculada caso o suspeito de ser outlier seja o menor numero.
  double z_menor;  
  
  /// Comparar a entrada do usuario com a enumeracao e executar o metodo correto.
  int resp;     
  
  /// Matriz com os valores criticos para o teste de Dixon.
  static double vcritico[23][3] ;
  
  /// Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;   
public:
  ///
  /// O metodo Ordenar() ordena os dados inseridos pelo usuario de forma crescente.
  ///
  void Ordenar();        
  ///
  /// O metodo Zmaior() calcula a estatistica do teste quando a suspeita do outlier e o maior numero. O metodo Zmaior() e executado 
  /// de acordo com a escolha do usuario em se testar o maior ou menor elemento no metodo Entrada() ou ao final da execucao do metodo Compara().
  /// @return Representa a estatistica calculada, o valor a ser comparado com o valor critico.
  /// 
  double Zmaior();
  ///
  /// O metodo Zmenor() calcula a estatistica do teste quando a suspeita do outlier e o menor numero. O metodo Zmenor() e executado 
  ///de acordo com a escolha do usuario em se testar o maior ou menor elemento no metodo Entrada() ou ao final da execucao do metodo Compara().
  /// @return Representa a estatistica calculada, o valor a ser comparado com o valor critico.
  ///
  double Zmenor();       
  ///
  /// O metodo ValorCritico() retorna o valor critico especifico para o teste.
  /// @return Representa o valor critico especifico para o teste realizado.
  ///
  double ValorCritico(); 
  ///
  ///O metodo Entrada() pede os dados e as informacoes necessarias para a realizacao do teste.
  ///
  void Entrada(); 
  ///
  /// O metodo Alpha() retorna o valor da significancia requerida pelo usuario.
  /// @return Representa o valor da significancia desejada pelo usuario.
  ///
  double Alpha();        
  ///
  /// o metodo Compara() faz a comparacao entre a estatistica calculada e o valor critico e mostra o resultado ao usuario.
  ///
  void Compara();        
};
#endif
