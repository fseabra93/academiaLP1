#ifndef INSTRUTOR_HPP
#define INSTRUTOR_HPP

void cadastrarInstrutor(long long int matricula, std::string nome, std::string funcao);
void listaInstrutor();
void buscaInstrutor(long long int mat);
void carregarValoresInstrutor();
bool existeInstrutor(long long int mat);
void apagarInstrutor(long long int matricula);
void atualizarArquivoInstrutor();


#endif