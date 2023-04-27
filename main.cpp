#include <iostream>
#include <cstdlib>
#include "aluno.hpp" //importa o arquivo de cabeçalho do instrutor
#include "instrutor.hpp" //importa o arquivo de cabeçalho do instrutor

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
  } cout << endl;
  
  /* Escolhendo o perfil (aluno, instrutor ou admin */
  
  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Usuário (cliente)\n";
  cout << "2 - Gerente\n";
  //cout << "3 - Administrador\n";
  cout << "-> :";
  int perfil; 
  cin >> perfil;
  
  /* Lê o arquivo aluno.txt e carrega os dados no sistema */
  carregarValoresAlunos();
  /* Lê o arquivo instrutor.txt e carrega os dados no sistema */
  carregarValoresInstrutor();
  
  /* Menu de opções para o perfil Aluno */
  if(perfil == 1){
    while(true){
      cout << "\n#####   Usuário (cliente)   #####\n\n";
      cout << "1 - Ver ônibus cadastrados (nome da linha e bairro)\n";
      cout << "2 - Buscar um ônibus por seu bairro (terminal)\n";
      cout << "3 - Ver o itinerário de um ônibus (busque pelo nome da linha)\n";
      cout << "4 - Fazer uma reclamação (a reclamação será anônima)\n";
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
        exit(0);
      } else {
          cout << "1 - Cadastrar alunos\n";
          cout << "2 - Cadastrat instrutor\n";
          cout << "3 - Listar alunos\n";
          cout << "4 - Listar instrutores\n";
          cout << "5 - Excluir alunos\n";
          cout << "6 - Excluir instrutores\n";
          cout << "7 - Sair\n";

          int opt;
          cin >> opt;
      }



 

      /* Cadastrar um novo aluno */
      if(opt == 1){
        string nome, treino, end;
        long long int inst, mat;
        cout << "\n#####   Cadastrar aluno   #####\n";
        cout << "Matricula: ";
        cin >> mat;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Treino: ";
        getline(cin, treino);
        cout << "Endereço: ";
        getline(cin, end);
        cout << "Instrutor: ";
        cin >> inst;
        cadastrarAluno(mat, nome, end, treino, inst); //Chama a função em aluno.cpp
      }

      /* Cadastrar um novo instrutor */
      else if(opt == 2){
        string nome, funcao;
        long long int mat;
        cout << "\n#####   Cadastrar instrutor   #####\n";
        cout << "Matricula: ";
        cin >> mat;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Função: ";
        getline(cin, funcao);
        cadastrarInstrutor(mat, nome, funcao); //Chama a função em instrutor.cpp
      } 

      /* Listar todos os alunos cadastrados */
      else if(opt == 3){
        listaAluno(); //Chama a função em aluno.cpp
      }

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

  /* Caso o perfil não exista */
  else{
      cout << "Perfil não localizado\n"<< endl;
    }
  
  return 0; 
}