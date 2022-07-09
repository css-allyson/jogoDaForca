#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Forca{
public:
//Variáveis
//
//
//
vector<string>palavras;
vector<string>scores;
vector<int>pal_acertadas;
string palavra;
char palavra_temp[50];
char letra;
int letras_acerto{0};
int indice_pal;
int pontos_p;
int pontos_t{0};
int dif_partida;
vector<char> letras_sorteadas;
//Métodos
//
//
//
int acha_letra(char letra);
void jogo_forca();
void inicia_palavra_vazia();
void imprime_palavra();
void imprime_erro(int err);
int verifica_letras_sorteadas();
void dificuldade();
void inicia_jogo();
int checa_caracteres(string pal);
int checa_palavras();
int checa_scores(string scr);
int checa_arquivos();
int checa_palavras_sorteadas(int indice);
void sorteia_palavras();
void finaliza_jogo();
void imprime_scores();
private:
};
//Implementação funções
//
//
/*Método para checar se a palavra sorteada ja foi acertada pelo jogador*/
int Forca::checa_palavras_sorteadas(int indice){
  for(int i=0;i<pal_acertadas.size();i++){
    if(indice==pal_acertadas[i]){
      return 0;
    }
  }
  return 1;
}
/*Método para fazer a inicialização da palavra conforme a dificuldade escolhida pelo jogador:
Fácil: de 1 até tamanho da palavra/5 consoantes exibidas
Médio: 1 vogal exibida
Difícil: nenhuma letra exibida*/
void Forca::dificuldade(){
  if(dif_partida==1){
    char cons[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','x','w','z'};
    int i = palavra.size()/5;
    int tam = max(1,i);
    int cons_count{0};
    while(cons_count<tam){
      srand (time(NULL));
      int ran1 = rand() % 20;
      letra = cons[ran1];
      int teste{0};
      teste = acha_letra(letra);
      if(teste > 0){
        letras_sorteadas.push_back(letra);
        cons_count++;
        letras_acerto += teste;
    }
    }
  }
  if(dif_partida==2){
    char cons[]={'a','e','i','o','u'};
    int cons_count{0};
    while(cons_count<1){
      srand (time(NULL));
      int ran1 = rand() % 5;
      letra = cons[ran1];
      int teste{0};
      teste = acha_letra(letra);
      if(teste > 0){
        letras_sorteadas.push_back(letra);
        cons_count++;
        letras_acerto += teste;
        }
    }
  }
  imprime_palavra();
}
/*Método para procurar letra numa string, retorna quantas vezes foi encontrada a letra*/
int Forca:: acha_letra(char ltr){
  int pts{0};
  for(int j = 0; j<palavra.size(); j++){
    if(palavra[j]==ltr || (palavra[j]==(ltr-32)) ){
      pts++;
      palavra_temp[j] = palavra[j];
    }
    }
  return pts;
}
/*Método para iniciar uma string preenchida por "_" para ser exibida na tela*/
void Forca:: inicia_palavra_vazia(){
  for(int j = 0; j<palavra.size(); j++){
    palavra_temp[j]='_';
  }
}
/*Método para verificar no vetor com as letras sorteadas, se a letra digitada pelo jogador
ja havia sido digitada anteriormente*/
int Forca:: verifica_letras_sorteadas(){
  for(int i = 0; i< letras_sorteadas.size();i++){
    if(letras_sorteadas[i]==letra){
      return 1;
    }
  }
  return 0;
}
/*Método para imprimir a palavra com as letras descobertas pelo jogador até então*/
void Forca::imprime_palavra(){
  for(int j = 0; j<palavra.size(); j++){
    cout<<palavra_temp[j]<<" ";
    }
  cout<<endl<<"Pontos da partida: "<<pontos_p<<endl;
}
/*Método para desenhar em tela o boneco da forca, de acordo com a quantidade de erros do jogador*/
void Forca::imprime_erro(int err){
    if(err == 0){
    cout<<"  ________________"<<endl;
    cout<<" |/               "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 1){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (°ʖ°)    "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 2){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (°ʖ°)    "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 3){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (°ʖ°)    "<<endl;
    cout<<" |       __|      "<<endl;
    cout<<" |      |  |      "<<endl;
    cout<<" |      |  |      "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 4){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (°ʖ°)    "<<endl;
    cout<<" |       __|__    "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |         |      "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 5){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (°ʖ°)    "<<endl;
    cout<<" |       __|__    "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |       __|      "<<endl;
    cout<<" |      |         "<<endl;
    cout<<" |      |         "<<endl;
    cout<<" |     _|         "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
    if(err == 6){
    cout<<"  ________________"<<endl;
    cout<<" |/        |      "<<endl;
    cout<<" |       (ˣʖˣ)    "<<endl;
    cout<<" |       __|__    "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |      |  |  |   "<<endl;
    cout<<" |       __|__    "<<endl;
    cout<<" |      |     |   "<<endl;
    cout<<" |      |     |   "<<endl;
    cout<<" |     _|     |_  "<<endl;
    cout<<" |                "<<endl;
    cout<<"_|_               "<<endl;
  }
}
/*Método responsável pela partida do jogo, faz chamada a outros métodos*/
void Forca::jogo_forca(){
  int erros = 0;
  while(erros<6){
    cout<<"Digite uma letra"<<endl;
    cin>>letra;
    if(verifica_letras_sorteadas()==0){
      letras_sorteadas.push_back(letra);
      int teste = acha_letra(letra);
    if(teste == 0){
      erros++;
      pontos_p--;
    }
    if(teste > 0){
      letras_acerto+=teste;
      pontos_p++;
    }
    imprime_erro(erros);
    imprime_palavra();
    if(letras_acerto == palavra.size()){
      cout<<"Parabéns!!! Você acertou!!!"<<endl;
      pal_acertadas.push_back(indice_pal);
      if(erros==0){
        pontos_t+=pontos_p+3;
      }
      else{
        pontos_t+=pontos_p+2;
      }
      break;
    }
    
    }
    else{
      cout<<"A letra '"<<letra<<"' já foi digitada"<<endl;
    }
  }
  if(erros==6){
    cout<<"Que pena, vc não acertou. A palavra era: "<<palavra<<endl;
    pontos_t+=pontos_p;
  }
}
/*Método para iniciar o jogo, fazendo as configurações iniciais da partida*/
void Forca::inicia_jogo(){
  sorteia_palavras();
  letras_acerto=0;
  pontos_p = 0;
  letras_sorteadas.clear();
  inicia_palavra_vazia();
  dificuldade();
  jogo_forca();
  cout<<"Pontos total do jogador: "<<pontos_t<<endl;
}
/*Método para verificar se os caracteres das palavras do arquivo de palavras está de acordo com o padrão do jogo*/
int Forca::checa_caracteres(string pal){
  for(int i=0;i<pal.size();i++){
    if((pal[i]<97||pal[i]>122) && (pal[i]<65||pal[i]>90)&&(pal[i]!='-')){
      return 0;
    }
  }
  return 1;
  }
/*Método para verificar se os dois arquivos, de palavras e de scores, estão de acordo com o padrão do jogo*/
int Forca::checa_arquivos(){
  for(int i = 0; i< palavras.size();i++){
    if((palavras[i].size()<4)||checa_caracteres(palavras[i])==0){
      return 0;
    }
  }
  for(int v = 0; v< scores.size();v++){
    if((checa_scores(scores[v])==0)){
      return 0;
    }
  }
  return 1;
}
/*Método para verificar se os as linhas dos arquivos de score está de acordo com o padrão do jogo*/
int Forca::checa_scores(string scr){
  int temp1{0},lista_sep[4];
   for(int x=0;x<scr.size();x++){
     if(scr[x]==';'){
      lista_sep[temp1]=x;
      temp1++; 
     }
   }
   lista_sep[3]=scr.size()-1;
   if(temp1<2){
     return 0;
   }
   if(lista_sep[0]==0){
     return 0;
   }
   if((lista_sep[1]-lista_sep[0])<2){
     return 0;
   }
   if(lista_sep[3]-lista_sep[2]<2){
     return 0;
   }
return 1;
}
/*Método que a partir da lista sorteia aleatoriamente uma palavra para a partida. O método não utiliza
palavras que ja foram acertadas anteriormente*/
void Forca::sorteia_palavras(){
  string plvr;
  srand (time(NULL));
  indice_pal = rand() % palavras.size();
  if(pal_acertadas.size()>0){
    while(checa_palavras_sorteadas(indice_pal)==0)
      indice_pal = rand() % palavras.size();
      palavra = palavras[indice_pal];
  }
  else{
    palavra = palavras[indice_pal];
  }
}
/*Método que imprime cada linha do arquivo de scores*/
void Forca::imprime_scores(){
  for(int i = 0; i< scores.size();i++){
    cout << scores[i]<<endl;
  }
  cout <<"--------------------------------------------------------------------"<< endl;
}
/*Método que finaliza o jogo, fazendo a impressão no arquivo de scores do resultado do jogador*/
void Forca::finaliza_jogo(){
  ofstream myfile3 ("scores.txt");
   for(int i = 0; i< scores.size();i++){
    myfile3 <<scores[i]<<endl;
  }
   if(dif_partida ==1){
     myfile3 <<"Fácil;";
   }
  if(dif_partida ==2){
     myfile3 <<"Médio;";
   }
  if(dif_partida ==3){
     myfile3 <<"Difícil;";
   }
  cout<<"Digite seu nome: "<<endl;
  string nome;
  cin>>nome;
  myfile3<<" "<<nome<<";";
  for(int i = 0;i<pal_acertadas.size();i++){
    if(i==pal_acertadas.size()-1){
      myfile3<<" "<<palavras[pal_acertadas[i]]<<";";
    }
    else{
      myfile3<<" "<<palavras[pal_acertadas[i]]<<",";
    }
    
  }
   myfile3<<" "<<pontos_t;
   myfile3.close();
}
#endif