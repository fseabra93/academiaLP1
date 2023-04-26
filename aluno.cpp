#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "instrutor.hpp"

using namespace std;

//Cria a scruct para armazenar um aluno
struct Aluno{
  string nome;
  string endereco;
  string treino;
  long long int instrutor;
};

//Cria o map para armazenar os alunos Chave (matricula) e valor (struct Aluno)
map<long long int, Aluno> alunos;


//Lê o arquivo assim que o programa é iniciado para salvar no map
void carregarValoresAlunos(){
  fstream arquivoCriar;

  //cria o arquivo alunos.txt caso não exista
  arquivoCriar.open("alunos.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //Abre o arquivo alunos.txt para leitura
  fstream arquivoler;
  arquivoler.open("alunos.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  //Lê todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  arquivoler.close(); //fecha o arquivo lido.
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< vetor.size(); i+=5){
    //stoll converte uma string para um inteiro longo
    long long int matricula = stoll(vetor[i]);
    alunos[matricula].nome = vetor[i+1];
    alunos[matricula].endereco = vetor[i+2];
    alunos[matricula].treino = vetor[i+3];
    alunos[matricula].instrutor = stoll(vetor[i+4]);
  }
}

//Faz o cadastro do aluno com valores recebidos dos parametros
void cadastrarAluno(long long int matricula, string nome, string endereco, string treino, long long int instrutor){
  fstream arquivo;
  arquivo.open("alunos.txt", ios::out | ios::app);
  arquivo << matricula << endl;
  alunos[matricula].nome = nome;
  arquivo << nome << endl;
  alunos[matricula].endereco = endereco;
  arquivo << endereco << endl;
  alunos[matricula].treino = treino;
  arquivo << treino << endl;


  //Verifica se o instrutor existe, se não preenche o campo com zero
  if (existeInstrutor(instrutor)){
    alunos[matricula].instrutor = instrutor;
    arquivo << instrutor << endl;

  }else{
    cout << "Instrutor não localizados" << endl;
    alunos[matricula].instrutor = 0;
    arquivo << 0 << endl;
  }

  arquivo.close(); // Fecha o arquivo

  cout << "Aluno cadastrado!!!\n";
}

//Faz a listagem dos alunos
void listaAluno(){
  cout << "\n####  Lista de Alunos   ####\n\n";
  cout << "*************************\n";
  for(auto i : alunos){
    cout << "Matricula: "<< i.first << endl;
    cout << "Nome: "<< i.second.nome << endl;
    cout << "Treino: "<< i.second.treino << endl;
    cout << "Instrutor: "<< i.second.instrutor << endl;
    cout << "*************************\n";
}
}

//Busca um determinado aluno por sua matricula
void buscaAluno(long long int mat){
  cout << "\n####  Buscando Aluno   ####\n";
  for(auto i : alunos){
    if(i.first == mat){
      cout << "\nAluno encontrado!\n";
    }   
  }
}

//Busca o treino do aluno por sua matricula
void verTreinoAluno(long long int matricula){
  cout << "\n####  Buscando Treino...   ####\n";
  for(auto i : alunos){
    if(i.first == matricula){
      cout << "\n*************************\n";
      cout << "Nome: " << i.second.nome << endl;
      cout << "Treino: " << i.second.treino << endl;
       cout << "*************************\n";
    }   
  }
}

//Busca o instrutor do aluno pela matricula do aluno
void verInstrutorAluno(long long int matricula){
  cout << "\n####  Buscando Instrutor...   ####\n";
  for(auto i : alunos){
    if(i.first == matricula){
      cout << "Nome do aluno: " << i.second.nome << endl;
      buscaInstrutor(i.second.instrutor); //chama a função em instrutor.cpp
    }   
  }
}

//Altera o treino do aluno 
void alterarTreinoAluno(long long int matricula, string novoTreino){
  cout << "\n####  Buscando Aluno   ####\n";
  for(auto i : alunos){
    if(i.first == matricula){
      alunos[matricula].treino = novoTreino;
      cout << "Treino alterado com sucesso" << endl;
    }   
  }
}

//Atualiza o arquivo para excluir a linha apagada
void atualizarArquivoAluno(){
  fstream arquivo;
  arquivo.open("alunos.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : alunos){
    arquivo << i.first << endl;
    arquivo << i.second.nome << endl;
    arquivo << i.second.endereco << endl;
    arquivo << i.second.treino << endl;
    arquivo << i.second.instrutor << endl;
  }
}

//Apaga determinado aluno por sua matricula
void apagarAluno(long long int matricula){
  for(auto i : alunos){
    if(i.first == matricula){
      alunos.erase(matricula);
      atualizarArquivoAluno(); // Chama a função para atualizar o arquivo
      cout << "Aluno excluido com sucesso" << endl;
      return;
    }   
  }
  cout << "Aluno não encontrado!!!" << endl;
}

