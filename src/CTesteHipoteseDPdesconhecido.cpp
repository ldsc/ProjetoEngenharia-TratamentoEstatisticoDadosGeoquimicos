#include "CTesteHipoteseDPdesconhecido.h"

double CTesteHipoteseDPdesconhecido::Calcular()
{
  tcalc = ((Media() - h0)*(sqrt(dados.size())))/Desviopadrao();
  return tcalc;
}

void CTesteHipoteseDPdesconhecido::Entrada()
{
  std::cout << "----------------------------------------------\n"
            << "Teste de Hipotese (Desvio Padrao Desconhecido)\n"
            << "----------------------------------------------\n\n";
  CEstatistica::Entrada();
  std::cout << "\n\tMedia Amostral: " << Media() << std::endl;
  std::cout << "\n\tDesvio Padrao da Amostra: " << Desviopadrao() << std::endl;
  std::cout << "\n\tAgora entre com a Hipotese Nula (Ho): ";
  std::cin >> h0; 
  std::cin.get();    
  std::cout << "\nSelecione a Regiao Critica desejada:\n"
	    << "  a) Unilateral ou unicaudal a esquerda..........................................(digite 0 + ENTER): \n"
	    << "  b) Unilateral ou unicaudal a direita...........................................(digite 1 + ENTER): \n"
	    << "  c) Bilateral...................................................................(digite 2 + ENTER): ";	    
  std::cin >> caso; 
  std::cin.get();
  std::cout << "\nSelecione o Nivel de Significancia: \n"
	    << "Para alpha = 0.25.................................................................(digite 1 + ENTER) \n"
	    << "Para alpha = 0.10.................................................................(digite 2 + ENTER) \n"
	    << "Para alpha = 0.05.................................................................(digite 3 + ENTER) \n"
	    << "Para alpha = 0.025................................................................(digite 4 + ENTER) \n"
	    << "Para alpha = 0.01.................................................................(digite 5 + ENTER) \n"
	    << "Para alpha = 0.005................................................................(digite 6 + ENTER) : ";
  std::cin >> alpha; std::cin.get();
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app) ;
}

double CTesteHipoteseDPdesconhecido::Alpha()
{
  double x2[6] = {0.25, 0.10, 0.05, 0.025, 0.01, 0.005};
  return x2[alpha -1]; 
}

void CTesteHipoteseDPdesconhecido::Compara()
{
  double valor = Calcular();
 if (caso == esquerda) {
   std::cout << "\nTeste de Hipotese Unicaudal a Esquerda realizado com sucesso!" << std::endl;
   fout << "\nTeste de Hipotese Unicaudal a Esquerda realizado com sucesso!" << std::endl;
   if (valor < -uniStudent(dados.size()-2, alpha - 1)) {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
   }
   else {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
   }
 }
 else if (caso == direita) {
   std::cout << "\nTeste de Hipotese Unicaudal a Direita realizado com sucesso!" << std::endl;
   fout << "\nTeste de Hipotese Unicaudal a Direita realizado com sucesso!" << std::endl;
   if (valor > uniStudent(dados.size()-2, alpha - 1)) {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
   }
   else {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << uniStudent(dados.size()-2, alpha - 1) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
   }
 }
 else if (caso == bilateral) {
   std::cout << "\nTeste de Hipotese Bicaudal realizado com sucesso!" << std::endl;
   fout << "\nTeste de Hipotese Bicaudal realizado com sucesso!" << std::endl;
   if (valor > biStudent(dados.size()-2, alpha) or valor < -biStudent(dados.size()-2, alpha)) {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << biStudent(dados.size()-2, alpha) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << biStudent(dados.size()-2, alpha) << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << -biStudent(dados.size()-2, alpha) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << -biStudent(dados.size()-2, alpha) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
   }
   else {
     std::cout << "\n\ttcalc = " << valor << std::endl;
     fout << "\n\ttcalc = " << valor << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << biStudent(dados.size()-2, alpha) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << biStudent(dados.size()-2, alpha) << std::endl;
     std::cout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << -biStudent(dados.size()-2, alpha) << std::endl;
     fout << "\n\tValor tabelado de t para phi = " << dados.size() - 1 << " e alpha = " << Alpha() << ": " << -biStudent(dados.size()-2, alpha) << std::endl;
     std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
     fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n"; 
   }
 }
 fout.close();
}
