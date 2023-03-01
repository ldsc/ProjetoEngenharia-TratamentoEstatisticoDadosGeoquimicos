#ifndef CSolverRL_h
#define CSolverRL_h

#include <iostream>
#include <vector>
#include <numeric>

/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CSolverRL
 * @file CSolverRL.h
 * @brief Classe representativa das operacoes basicas da regressao linear.
 */

class CSolverRL {
protected:
  /// Vetor que armazena a abcissa dos pontos.
  std::vector<double> vx;
  
  /// Vetor que armazena a ordenada dos pontos.
  std::vector<double> vy;
  
  /// Somatorio das abcissas dos pontos.
  double sx;
  
  /// Somatorio das ordenadas dos pontos.
  double sy;
  
  /// Somatorio da multiplicacao da abcissa por sua respectiva ordenada. Ex: sxy = x1*y1 + x2*y2 + ... + xn*yn
  double sxy;
  
  /// Somatorio do quadrado das abcissas. Ex: sx2 = x1*x1 + x2*x2 + ... + xn*xn 
  double sx2;
  
  /// Somatorio do quadrado das ordenadas. Ex: sy2 = y1*y1 + y2*y2 + ... + yn*yn
  double sy2;
  
public:
  /// Metodo de entrada. Pede  os dados ao usuario.
  void Entrada();
  
  /// Metodo que retorna o somatorio das abcissas dos pontos.
  /// @return somatorio das abcissas dos pontos.
  double Sx();
  
  /// Metodo que retorna o somatorio das ordenadas dos pontos.
  /// @return somatorio das ordenadas dos pontos.
  double Sy();
  
  /// Metodo que retorna o somatorio da multiplicacao da abcissa por sua respectiva ordenada.
  /// @return somatorio da multiplicacao da abcissa por sua respectiva ordenada.
  double Sxy ();
  
  /// Metodo que retorna o somatorio do quadrado das abcissas.
  /// @return somatorio do quadrado das abcissas.
  double Sx2();
  
  /// Metodo que retorna o somatorio do quadrado das ordenadas.
  /// @return somatorio do quadrado das ordenadas.
  double Sy2 ();   
};
#endif

