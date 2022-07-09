#include <iostream>
#include <fstream>
#include "classes.h"
using namespace std;

int main(int argc, char *argv[]) {
  vector<string> v1;
  vector<string> v2;
  char p[50];
  string line;
  string line2;
  Forca f1;
  int escolha{25};
  string entr1;
  string entr2; 
  if(argv[1]==NULL){
    entr1 = "palavras.txt";
    entr2 = "scores.txt";
  }
   else{
    entr1 = argv[1];
    entr2 = argv[2];
   }
   ifstream myfile (entr1);
   ifstream myfile2 (entr2);
  if (myfile.is_open())
  {
    while(myfile.getline(p,50)) {
      line = p;
      v1.push_back(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  if (myfile2.is_open())
  {

    while(getline(myfile2, line2,'\n')) {
      v2.push_back(line2);
    }
    myfile2.close();
  }

  else cout << "Unable to open file";
  cout << "Lendo arquivos de palavras [./palavras.txt] e scores [./scores.txt], por favor aguarde."<<endl;
  cout <<"--------------------------------------------------------------------"<< endl;
  f1.palavras = v1;
  f1.scores = v2;
  if(f1.checa_arquivos()==0){
    cout<<"Arquivos não estão no padrão do programa. Verifique o formato dos arquivos de entrada e tente novamente."<<endl;
    return 0;
  }
  cout <<"Arquivos ok!"<< endl;
  cout <<"--------------------------------------------------------------------"<< endl;
  while(escolha!=1){
    cout<<"Bem vindo ao Jogo Forca! Por favor escolha uma das opções"<<endl;
    cout<<"1 - Iniciar Jogo"<<endl;
    cout<<"2 - Ver scores anteriores"<<endl;
    cin>>escolha;
    cout<<"Sua escolha: "<<escolha<<endl;
    cout <<"--------------------------------------------------------------------"<< endl;
    if(escolha==2){
      f1.imprime_scores();
    }
  }

  if(escolha == 1){
    cout<<"Vamos iniciar o jogo! Por favor escolha o nível de dificuldade"<<endl;
    cout<<"1 - Fácil"<<endl;
    cout<<"2 - Médio"<<endl;
    cout<<"3 - Difícil"<<endl;
    cin>>f1.dif_partida;
    cout<<"Sua escolha: "<<f1.dif_partida<<endl;
    cout <<"--------------------------------------------------------------------"<< endl;
  }
  while(escolha>0&&escolha<5){
    if(f1.dif_partida==1){
      cout<<"Iniciando o Jogo no nível Fácil, será que você conhece essa palavra?"<<endl;
    }
    if(f1.dif_partida==2){
      cout<<"Iniciando o Jogo no nível Médio, será que você conhece essa palavra?"<<endl;
    }
    if(f1.dif_partida==3){
      cout<<"Iniciando o Jogo no nível Difícil, será que você conhece essa palavra?"<<endl;
    }
  f1.inicia_jogo();
  cout<<"Deseja jogar novamente?"<<endl;
  cout<<"1 - Sim"<<endl;
  cout<<"5 - Não"<<endl;
  cin>>escolha;
  cout<<"Sua escolha: "<<escolha<<endl;
    cout <<"--------------------------------------------------------------------"<< endl;
  if(escolha==5){
    cout<<"Fim de jogo!"<<endl;
    break;
  }
  cout<<"Iniciando novo jogo!"<<endl;
}
  f1.finaliza_jogo();
}
