#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "gerente.hpp"

using namespace std;

//Cria a scruct para armazenar um aluno
struct Onibus{
  //int num_linha;
  string terminal;
  string itiner;
};

//Cria o map para armazenar os alunos Chave (matricula) e valor (struct Aluno)
map<int, Onibus> onibus;


//Lê o arquivo assim que o programa é iniciado para salvar no map
void carregarValoresOnibus(){
  fstream arquivoCriar;

  //cria o arquivo alunos.txt caso não exista
  arquivoCriar.open("onibus.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //Abre o arquivo alunos.txt para leitura
  fstream arquivoler;
  arquivoler.open("onibus.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  //Lê todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  arquivoler.close(); //fecha o arquivo lido.
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< vetor.size(); i+=3){
    //stoll converte uma string para um inteiro longo
    int num_linha = stoll(vetor[i]);
    onibus[num_linha].terminal = vetor[i+1];
    onibus[num_linha].itiner = vetor[i+2];
  }
}

//Faz o cadastro do aluno com valores recebidos dos parametros
void cadastrarOnibus(int num_linha, string terminal, string itiner){
  fstream arquivo;
  arquivo.open("onibus.txt", ios::out | ios::app);
  arquivo << num_linha << endl;
  onibus[num_linha].terminal = terminal;
  arquivo << terminal << endl;
  onibus[matricula].itiner = itiner;
  arquivo << itiner << endl;



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
void listaOnibus(){
  cout << "\n####  Lista de Ônibus Cadastrados   ####\n\n";
  cout << "*************************\n";
  for(auto i : onibus){
    cout << "Número da linha: "<< i.first << endl;
    cout << "Terminal: "<< i.second.terminal << endl;
    cout << "Itinerário: "<< i.second.itiner << endl;
    cout << "*************************\n";
}
}

//Busca um determinado aluno por sua matricula
void buscaOnibusLinha(int num_linha){
  cout << "\n####  Buscando Ônibus   ####\n";
  for(auto i : onibus){
    if(i.first == num_linha){
      cout << "\nÔnibus encontrado!\n";
      cout << "\nO terminal desta linha é o " << i.second.terminal << endl;
      cout << "\nO itinerário desta linha é o " << i.second.itiner << endl;

    }   
  }
}

void buscaOnibusLBairro(string bairro){
  cout << "\n####  Buscando Ônibus   ####\n";
  for(auto i : onibus){
    if(i.second.terminal == bairro){
      cout << "\nÔnibus encontrado!\n";
      cout << "\nO número desta linha é o " << i.first << endl;
      cout << "\nO itinerário desta linha é o " << i.second.itiner << endl;

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
void alterarTerminal(int linha, string novo){
  //cout << "\n####  Alterando terminal da linha "<< linha << "   ####\n";
  for(auto i : onibus){
    if(i.first == linha){
      
      onibus[linha].terminal = novo;
      cout << "Terminal da linha "<< linha << " alterado com sucesso" << endl;
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

