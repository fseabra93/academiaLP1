#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "onibus.hpp" //importa o arquivo de cabeçalho do onibus
#include "perfil.cpp" 
#include "gerente.hpp" //importa o arquivo de cabeçalho do gerente

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
  
  /* Lê o arquivo aluno.txt e carrega os dados no sistema */
  carregarValoresOnibus();
  /* Lê o arquivo instrutor.txt e carrega os dados no sistema */
  carregarValoresGerente();
  
  /* Menu de opções para o perfil Aluno */
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
      
      /* Busca o treino do aluno por sua matricula */
      if(opt == 1){
        cout << "\n####  Ônibus Cadastrados   ####\n";
        // criar função para ler o arquivo onibus cadastrados
      }

      /* Busca o instrutor do aluno com a matricula do aluno */
      else if(opt == 2){
        cout << "\n####  Buscar ônibus por bairro   ####\n";
        cout << "Escolha seu bairro: ";
        // criar um menu com os bairros
        // criar uma função para dizer que ônibus passa nesse bairro
        // criar uma função para dizer que ônibus saem desse bairro
 
      }

      else if(opt == 3){
        cout << "\n####  Ver o itinerário de um ônibus   ####\n";
        cout << "Escolha uma linha de ônibus: ";
        // criar um menu com os números dos ônibus e de onde cada um sai
        // criar uma função para mostrar o itinerário
 
      }

      else if(opt == 4){
        cout << "\n####  Fazer uma reclamação   ####\n";
        cout << "Escreva sua reclamação: (a sua reclamação será anônima)";
        // guardar no arquivo reclamação
       
 
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
          cout << "3 - Buscar um ônibus por seu nome\n";
          cout << "4 - Buscar um ônibus por seu bairro (terminal)\n";
          cout << "5 - Atualizar o bairro (terminal) de um determinado ônibus\n";
          cout << "6 - Atualizar o itinerário de um determinado ônibus\n";
          cout << "7 - Excluir um ônibus (buscando pelo nome)\n";
          cout << "8 - Listar reclamações";
          cout << "9 - Sair\n";

          int opt;
          cin >> opt;
      

            /* Cadastrar um novo aluno */
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
              cadastrarOnibus(num_linha, terminal, itiner); //Chama a função em aluno.cpp
            }

            /* Cadastrar um novo instrutor */
            else if(opt == 2){
              listaOnibus(); //Chama a função em aluno.cpp
            } 

            /* Listar todos os alunos cadastrados */
            else if(opt == 3){
              int linha;
              cout << "Digite o número da linha: ";
              cin >> linha;
              buscaOnibus(linha);
            }
//////////////////////////////////////////////////////////////////////////////////////////////
            /* Listar todos os instrutores cadastrados */
            else if(opt == 4){
              listaInstrutor(); //Chama a função em instrutor.cpp
            }

            /* Apaga um aluno por sua matricula */
            else if(opt == 5){
              cout << "Digite a matricula do aluno: ";
              long long int matricula;
              cin >> matricula;
              apagarAluno(matricula); //Chama a função em aluno.cpp
            }

            /* Apaga um instrutor por sua matricula */
            else if(opt == 6){
              cout << "Digite a matricula do Instrutor: ";
              long long int matricula;
              cin >> matricula;
              apagarInstrutor(matricula); //Chama a função em instrutor.cpp
            }

            /* Sai do while(true) */
            else{
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