#include "CSolverRL.h"

using namespace std;

void CSolverRL::Entrada()
{
  double auxiliar1;  ///< Variavel auxiliar para a entrada de dados no vetor vx.
  double auxiliar2;  ///< Variavel auxiliar para a entrada de dados no vetor vy.
  do {
    cout << "Entre com os pares de dados, primeiro a variavel independente:  " ;
    cin >> auxiliar1;
    cin.get();
    
    if(cin.good()) {
      vx.push_back(auxiliar1);
      cout << "Agora entre com o variavel dependente: (ctrl + d encerra a entrada de dados): " ;
      cin >> auxiliar2; 
      cin.get();
      if(cin.good())
	vy.push_back(auxiliar2);
    }
  }
  while (cin.good());
  cin.clear();
  if (vx.size() != vy.size()) {
    cout << "\nO tamanho dos vetores devem ser iguais." << endl;
    cout << "Entre com os dados novamente." << endl;
    vx.clear(); 
    vy.clear();
    this->Entrada();   
  }
  cout << endl;
}

double CSolverRL::Sx()
{
  sx = accumulate (vx.begin(), vx.end(), 0.);
  return sx;
}

double CSolverRL::Sy() 
{
  sy = accumulate (vy.begin(), vy.end(), 0.);
  return sy;
}
  
double CSolverRL::Sxy() 
{
  sxy = 0.0;
  for (int i = 0; i < vx.size(); i++) {
    sxy += vx[i]*vy[i];
  }
  return sxy;
}
  
double CSolverRL::Sx2()
{
  sx2 = 0.0;
  for (int i = 0; i < vx.size(); i++) {
    sx2 += vx[i]*vx[i];
  }
  return sx2;
}
  
double CSolverRL::Sy2()
{
  sy2 = 0.0;
  for (int i = 0; i < vy.size(); i++) {
    sy2 += vy[i]*vy[i];
  }
  return sy2;
}
