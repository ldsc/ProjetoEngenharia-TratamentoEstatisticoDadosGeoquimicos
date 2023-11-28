#include <cmath>
#include <algorithm>
#include <numeric>

#include "CEstatistica.h"

void CEstatistica::Entrada()
{
  do {
    std::cout << "Entre com os dados (ctrl + d para encerrar): ";
    double aux; 
    std::cin >> aux; 
    std::cin.get();
    
    if (std::cin.good())
      dados.push_back(aux);
  }
  while (std::cin.good());
  std::cout << std::endl;
  std::cin.clear();
}

double CEstatistica::Amplitudedados()
{
  amplitude = *max_element(dados.begin(), dados.end()) - *min_element(dados.begin(), dados.end());
  return amplitude;
}
  
double CEstatistica::Media()
{
  media = accumulate(dados.begin(), dados.end(), 0.)/dados.size();
  return media;
}

double CEstatistica::Mediana()
{
  std::sort (dados.begin(), dados.end()); 
  int n = dados.size() - 1;
  if (dados.size()%2 == 0) 
  {mediana = (dados[n/2] + dados[(n/2) + 1])/2;}
  else { mediana = dados[(n+1)/2];}
  return mediana;
}

double CEstatistica::Variancia()
{
  double soma = 0;
  for (int i = 0; i < dados.size(); i++) 
  {soma += ((dados[i] - Media())*(dados[i] - Media()));}
  double dsv = sqrt(soma/(dados.size() - 1));
  variancia = dsv*dsv;
  return variancia;
}  
  
double CEstatistica::Desviopadrao()
{
  double soma = 0;
  for (int i = 0; i < dados.size(); i++) 
  {soma += ((dados[i] - Media())*(dados[i] - Media()));}
  desviopadrao = sqrt(soma/(dados.size() - 1));
  return desviopadrao;
}

