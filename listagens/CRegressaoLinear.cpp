#include <sstream>
#include <cmath>

#include "CRegressaoLinear.h"
#include "CGnuplot.h"

using namespace std;

std::string CRegressaoLinear::Equacao()
{
  ostringstream nome1;  
  nome1 << A() << "*x + (" << B() << ")";
  equacao = nome1.str();
  return equacao;
}

double CRegressaoLinear::A()
{
  a = 0.0;
  a = (vx.size()*Sxy() - Sx()*Sy())/(vx.size()*Sx2() - Sx()*Sx());
  return a;
}

double CRegressaoLinear::B()
{
  b = 0.0;
  b = (Sx2()*Sy() - Sxy()*Sx())/(vx.size()*Sx2() - Sx()*Sx());
  return b;
}
  
void CRegressaoLinear::Correlacao()
{
  r = 0.0;
  r = (Sxy()*Sxy())/(Sx2()*Sy2());
  cout << "O coeficiente do ajuste da regressao e: " << r << endl;
}
  
void CRegressaoLinear::ExibirEquacao()
{
  cout << "A equacao obtida com a regressao linear e: " << "f(x) = " << Equacao() << endl;
}

void CRegressaoLinear::Plotar() 
{
  grafico = new CGnuplot ("lines");
  grafico->set_xrange(*min_element(vx.begin(), vx.end()) - 1, *max_element(vx.begin(), vx.end()) + 1);
  grafico->set_yrange(*min_element(vy.begin(), vy.end()) - 1, *max_element(vy.begin(), vy.end()) + 1);
  grafico->plot_equation(Equacao(), Equacao()); 
  grafico->set_style("points pt 7 lc 3");
  grafico->plot_xy(vx, vy, "Pontos");
  grafico->set_pointsize(2.2);    
}

void CRegressaoLinear::Entrada()
{
  CSolverRL::Entrada();
  cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  string nome; getline(cin, nome);
  fout.open(nome+".txt", ios::app) ;
}

void CRegressaoLinear::Salvar()
{
  fout << "Pontos" << endl;
  for (int i = 0; i < vx.size(); i++)
  {fout << "(" << vx[i] << ", " << vy[i] << ")" << endl;}
  fout << "O coeficiente do ajuste da regressao e: " << r << endl;
  fout << "A equacao obtida com a regressao linear e: " << "f(x) = " << Equacao() << endl;
  fout.close();
}
