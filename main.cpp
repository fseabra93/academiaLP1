#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "onibus.hpp" //importa o arquivo de cabeçalho do onibus



using namespace std;

int main(int argc, char *argv[]){

  //imprimir o título

  string titulo = "### Sistema Gerenciador de Transportes Coletivos ###";
  int tam_titulo = titulo.length();

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl;
  
  cout << "### Sistema Gerenciador de transportes coletivos ###\n";

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl << endl;
  
  /* Escolhendo o perfil (cliente, gerente) */
  int perfil = perf();
  
  /* Lê os arquivos onibus.txt e reclamacoes.txt e carrega os dados no sistema */
  carregarValores();
  
  /* Menu de opções para o perfil cliente */
  if(perfil == 1){
    while(true){
      cout << "\n#####   Usuário (cliente)   #####\n\n";
      cout << "1 - Ver ônibus cadastrados (nome da linha e bairro)\n";
      cout << "2 - Buscar um ônibus por seu bairro (terminal)\n";
      cout << "3 - Ver o itinerário de um ônibus (busque pelo nome da linha)\n";
      cout << "4 - Fazer uma reclamação (a reclamação será anônima)\n";
      cout << "5 - Para sair\n";
      int opt;
      cin >> opt;
      
      /* Lista ônibus cadastrados */
      if(opt == 1){
        cout << "\n####  Ônibus Cadastrados   ####\n";
        listaOnibus();
      }

      /* Busca ônibus por bairro */
      else if(opt == 2){
        cout << "\n####  Buscar ônibus por bairro   ####\n";
        string bairro;
        cout << "Digite o bairro (terminal): ";
        getline(cin, bairro);
        buscaOnibusBairro(bairro);
 
      }
        /* Busca ônibus por linha e mostra o itinerário */
      else if(opt == 3){
        cout << "\n####  Ver o itinerário de um ônibus   ####\n";
        cout << "Escolha uma linha de ônibus: ";
        int linha;
        cin >> linha;
        buscaOnibusLinha(linha);
 
      }

      /*Cadastra uma reclamação anônima*/
      else if(opt == 4){
        cout << "\n####  Fazer uma reclamação   ####\n";
        cout << "Escreva sua reclamação: (a sua reclamação será anônima)";
        cadastrarReclamacao();       
 
      }


      else if(opt == 5){
        cout << "\n##  Obrigado por utilizar o Sistema Gerenciador de Transportes Coletivos   ##\n";
        sleep(2);
        exit(0);
 
      }
      
      /* Sai do while(true) */
      else{
        break;

      }
    } 
  }


  /* Menu de opções para o perfil admin */
  else if(perfil == 2){
    while(true){

      cout << "\nPara entrar no perfil GERENTE necessário autenticar seu perfil. \nDigite sua senha de ADMINISTRADOR:\n";
      string admin = "admin";
      string senha;
      cin >> senha;

      if (senha != admin){
        cout << "Você não tem acesso ao perfil ADMINISTRADOR\n";
        char tecla;
        cout << "Digite qualquer tecla para fechar o programa.\n";
        cin >> tecla;
        exit(0);
      } else {
          cout << "1 - Cadastrar linhas e ônibus\n";
          cout << "2 - Listar todos os ônibus cadastrados\n";
          cout << "3 - Buscar um ônibus por seu nome(número da linha)\n";
          cout << "4 - Buscar um ônibus por seu bairro (terminal)\n";
          cout << "5 - Atualizar o bairro (terminal) de um determinado ônibus\n";
          cout << "6 - Atualizar o itinerário de um determinado ônibus\n";
          cout << "7 - Excluir um ônibus (buscando pelo número da linha)\n";
          cout << "8 - Listar reclamações";
          cout << "9 - Sair\n";

          int opt;
          cin >> opt;
      

            /* Cadastrar linhas de onibus */
            if(opt == 1){
              string terminal, itiner;
              int num_linha;
              cout << "\n#####   Cadastrar linhas e ônibus   #####\n";
              cout << "Número da linha: ";
              cin >> num_linha;
              cout << "Terminal: ";
              cin.ignore();
              getline(cin, terminal);
              cout << "Itinerário: ";
              getline(cin, itiner);
              cadastrarOnibus(num_linha, terminal, itiner); //Chama a função em onibus.cpp
            }

            /* Lista as linhas, terminais e itinerários */
            else if(opt == 2){
              listaOnibus(); //Chama a função em onibus.cpp
            } 

            /* Busca ônibus pela linha*/
            else if(opt == 3){
              int linha;
              cout << "Digite o número da linha: ";
              cin >> linha;
              buscaOnibusLinha(linha);
            }

            /* Busca ônibus pelo terminal*/
            else if(opt == 4){
              string bairro;
              cout << "Digite o bairro (terminal): ";
              getline(cin, bairro);
              buscaOnibusBairro(bairro);
            }

            /* Atualizar o bairro (terminal) de um determinado ônibus */
            else if(opt == 5){
              cout << "Digite o número da linha que deseja atualizar o terminal: ";
              int num_linha;
              cin >> num_linha;
              cout << "Digite o novo Terminal para a linha " << num_linha <<": ";
              string novo_terminal;
              getline(cin, novo_terminal);
              alterarTerminal(num_linha, novo_terminal); 
              atualizarArquivo_onibus();
            }

            /* Atualizar o itinerário de um determinado ônibus */
            else if(opt == 6){
              cout << "Digite a número da linha que deseja atualizar o itinerário: ";
              int num_linha;
              cin >> num_linha;
              cout << "Digite o novo Itinerário para a linha " << num_linha <<": ";
              string novo_itiner;
              getline(cin, novo_itiner);
              alterarTerminal(num_linha, novo_itiner); 
              atualizarArquivo_onibus();
            }
            /*Excluir um ônibus (buscando pelo número da linha)*/
            else if(opt == 7){
              cout << "Digite a número da linha que deseja excluir: ";
              int num_linha;
              cin >> num_linha;
              apagarOnibus(num_linha); 
              
            }

            /*Listar reclamações*/
            else if(opt == 8){
              listaReclamacoes();
            }

            /* Sai do while(true) */
            else{
              cout << "\n##  Obrigado por utilizar o Sistema Gerenciador de Transportes Coletivos   ##\n";
              sleep(2);
              exit(0);

              break;
            }

        }
    }
  }

  /* Caso o perfil não exista */
  else{
      cout << "Perfil não localizado\n"<< endl;
    }
  
  return 0; 
}