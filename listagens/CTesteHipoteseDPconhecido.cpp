#include "CTesteHipoteseDPconhecido.h"

double CTesteHipoteseDPconhecido::Calcular()
{
  zcalc = (Media() - h0)/(sigma/sqrt(dados.size()));
  return zcalc;
}

void CTesteHipoteseDPconhecido::Entrada()
{  
  std::cout << "-------------------------------------------\n"
            << "Teste de Hipotese (Desvio Padrao Conhecido)\n"
            << "-------------------------------------------\n\n";
  CEstatistica::Entrada();
  std::cout << "\n\tMedia Amostral: " << Media() << std::endl;
  std::cout << "\n\tAgora entre com a Hipotese Nula (Ho): ";
  std::cin >> h0; std::cin.get();    
  std::cout << "\nSelecione a Regiao Critica desejada:\n"
	    << "  a) Unilateral ou unicaudal a esquerda.........................................(digite 0 + ENTER): \n"
	    << "  b) Unilateral ou unicaudal a direita..........................................(digite 1 + ENTER): \n"
	    << "  c) Bilateral..................................................................(digite 2 + ENTER): ";	    
  std::cin >> caso; std::cin.get();   
  std::cout << "\nEntre com o Nivel de Significancia: ";
  std::cin >> alpha; std::cin.get();  
  std::cout << "Entre com o Desvio Padrao da Populacao: ";
  std::cin >> sigma; std::cin.get();  
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app) ;
}

void CTesteHipoteseDPconhecido::Compara()
{
  if (caso == esquerda) {
    std::cout << "\nTeste Unicaudal a Esquerda realizado com sucesso!" << std::endl;
    fout << "\nTeste Unicaudal a Esquerda realizado com sucesso!" << std::endl;
    if (Calcular() < InvArea(alpha)) {
      std::cout << "\n\tZcalc = " << Calcular() << std::endl;
      fout << "\n\tZcalc = " << Calcular() << std::endl;
      std::cout << "\n\tValor tabelado de Z para alpha = " << alpha << ": " << InvArea(alpha) << std::endl;
      fout << "\n\tValor tabelado de Z para alpha = " << alpha << ": " << InvArea(alpha) << std::endl;
      std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
      fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n"; 
    }
    else {
      std::cout << "\n\tZcalc = " << Calcular() << std::endl;
      fout << "\n\tZcalc = " << Calcular() << std::endl;
      std::cout << "\n\tValor tabelado de Z para alpha = " << alpha << ": " << InvArea(alpha) << std::endl;
      fout << "\n\tValor tabelado de Z para alpha = " << alpha << ": " << InvArea(alpha) << std::endl;
      std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
      fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n"; 
    }
  }
  else if (caso == direita) {
    std::cout << "\nTeste Unicaudal a Direita realizado com sucesso!" << std::endl;
    fout << "\nTeste Unicaudal a Direita realizado com sucesso!" << std::endl;
    if (Calcular() > InvArea(1 - alpha)) {
      std::cout << "\n\tZcalc = " << Calcular() << std::endl;
      fout << "\n\tZcalc = " << Calcular() << std::endl;
      std::cout << "\n\tValor tabelado de Z para (1 - alpha) = " << 1. - alpha << ": "<< InvArea(1. - alpha) << std::endl;
      fout << "\n\tValor tabelado de Z para (1 - alpha) = " << 1. - alpha << ": "<< InvArea(1. - alpha) << std::endl;
      std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
      fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
    }
      else {
	std::cout << "\n\tZcalc = " << Calcular() << std::endl;
	fout << "\n\tZcalc = " << Calcular() << std::endl;
        std::cout << "\n\tValor tabelado de Z para (1 -alpha) = " << 1. - alpha << ": "<< InvArea(1. - alpha) << std::endl;
	fout << "\n\tValor tabelado de Z para (1 -alpha) = " << 1. - alpha << ": "<< InvArea(1. - alpha) << std::endl;
	std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
	fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
      }
  }
  else if (caso == bilateral) {
    std::cout << "\nTeste Bicaudal Realizado com sucesso!" << std::endl;
    fout << "\nTeste Bicaudal Realizado com sucesso!" << std::endl;
    if (Calcular() > InvArea(1. - (alpha/2.)) or Calcular() < InvArea(alpha/2.)) {
      std::cout << "\n\tZcalc = " << Calcular() << std::endl;
      fout << "\n\tZcalc = " << Calcular() << std::endl;
      std::cout << "\n\tValor tabelado de Z para (1 - alpha/2) = " << 1.-(alpha/2.) << ": " << InvArea(1. - (alpha/2.)) << std::endl;
      fout << "\n\tValor tabelado de Z para (1 - alpha/2) = " << 1.-(alpha/2.) << ": " << InvArea(1. - (alpha/2.)) << std::endl;
      std::cout << "\n\tValor tabelado de Z para alpha/2 = " << alpha/2. << ": " << InvArea(alpha/2.) << std::endl;
      fout << "\n\tValor tabelado de Z para alpha/2 = " << alpha/2. << ": " << InvArea(alpha/2.) << std::endl;
      std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n";
      fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " deve ser rejeitada!\n"; 
    }
      else {
	std::cout << "\n\tZcalc = " << Calcular() << std::endl;
	fout << "\n\tZcalc = " << Calcular() << std::endl;
        std::cout << "\n\tValor tabelado de Z para (1 - alpha/2) = " << 1. - (alpha/2.) << ", e " << InvArea(1. - (alpha/2.)) << std::endl;
	fout << "\n\tValor tabelado de Z para (1 - alpha/2) = " << 1. - (alpha/2.) << ", e " << InvArea(1. - (alpha/2.)) << std::endl;
        std::cout << "\n\tValor tabelado de Z para alpha/2 = " << alpha/2. << ", e "<< InvArea(alpha/2.) << std::endl;
	fout << "\n\tValor tabelado de Z para alpha/2 = " << alpha/2. << ", e "<< InvArea(alpha/2.) << std::endl;
	std::cout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n";
	fout << "\n\tA Hipotese Nula (Ho) mi = " << h0 << " nao deve ser rejeitada!\n"; 
      }
  }
  fout.close();
}
