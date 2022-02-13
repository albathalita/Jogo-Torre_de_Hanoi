#include<iostream>    //biblioteca de entrada e saida
#include<stdlib.h>    //acessar, mover e acessar pastas
#include<locale.h>    //biblioteca para adicionar os acentos

using namespace std;

int main(){
    // Coloca os acentos no português
    setlocale(LC_ALL, "Portuguese");
    // f=3 para o nível fácil, m=5 para o nível médio, d=7 para o nível difícil
    // n1 pra entrada do while, n2 pro jogo ou instruções, v para o usuário colocar o nível do jogo, cont=0 para contar o número de jogadas
    int f=3,m=5,d=7,n1,n2,v, cont=0;
    // para armazenar o nome do usuário
    char nome[50];
    cout<<"            Torre de Hanói"<<endl<<endl<<endl;
    cout<<"Digite seu nome: ";
    // nome com espaço
    cin.getline(nome,50);
    // limpar a tela
    system("cls");

    cout<<"            Torre de Hanói"<<endl<<endl<<endl;
    cout<<nome<<", aperte: "<<endl<<endl<<"1-Para continuar"<<endl<<"2-Para sair"<<endl<<endl<<endl;
    cin>>n1;

    while(n1==1){

        //para limpar a tela
        system("cls");
        cout<<nome<<", aperte: "<<endl<<endl<<"1-Para jogar"<<endl<<"2-Para multiplayer (2 jogadores)"<<endl<<"3-Para as instruções"<<endl<<"4-Para sair"<<endl<<endl<<endl;
        cin>>n2;
        if(n2==4){

            system("cls");
            cout<<nome<<", tem certeza?"<<endl<<endl;
            cout<<"1- Não, quero continuar o jogo"<<endl<<"2- Sim, quero sair"<<endl<<endl;
            cin>>n1;
        }

        if(n2==3){

            system("cls");
            cout<<"O objetivo é : "<<endl<<"Passar todos os discos do pino A para o pino C, usando o pinos B como auxiliar."<<endl<<endl;
            cout<<"Regras: "<<endl<<"* Apenas um disco poderia ser movido por vez"<<endl<<"* Nunca um disco maior deveria ficar por cima de um disco menor."<<endl<<endl;
            cout<<"O número de discos pode variar (nível fácil = 3 ; nível médio = 5 e nível difícil = 7 )."<<endl<<endl<<endl;
            cout<<nome<<", aperte: "<<endl<<"0-Para sair desta aba"<<endl<<"1-Para jogar"<<endl<<"2-Para multiplayer (2 jogadores)"<<endl;
            cin>>n2;
        }
        if(n2==1){

            system("cls");
            cout<<"Os pinos são 1, 2 e 3"<<endl<<endl;
            cout<<"Escolha o nível : [fácil(3), médio(5) e difícil(7)"<<endl<<endl;
            cout<<"Fácil= 3 pinos"<<endl<<"Médio= 5 pinos"<<endl<<"Difícil= 7 pinos"<<endl<<endl;
            cin>>v;
            if(v==f){
            // nível fácil


                system("cls");
                int v1[3],v2[3],v3[3],i,saida,destino;

                for(i=0; i<3; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]!=6 && v3[0]+v3[1]+v3[2]!=6){
                    for(i=0; i<3; i++){
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << cont << endl;
                    cout << nome << ", digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << nome << ", para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1){
                        if(destino==2 && v2[2]==0 && v1[0]!=0){
                            v2[2]=v1[0];
                            v1[0]=0;
                        }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]!=0)
                            {
                                v2[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                                v2[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1])
                            {
                                v2[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2])
                            {
                                v2[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2])
                            {
                                v2[0]=v1[2];
                                v1[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v1[0]!=0)
                        {
                                v3[2]=v1[0];
                                v1[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]!=0)
                            {
                                v3[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                                v3[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1])
                            {
                                v3[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[0]=v1[2];
                                v1[2]=0;
                            } // FIM DA 1
                    }

                    if(saida==2)
                    {
                        if(destino==1 && v1[2]==0 && v2[0]!=0)
                        {
                            v1[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v1[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v1[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1])
                            {
                                v1[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[1]=v2[2];
                                v2[2]=0;
                            }

                            else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[0]=v2[2];
                                v2[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v2[0]!=0)
                        {
                            v3[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v3[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v3[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1])
                            {
                                v3[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[1]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[0]=v2[2];
                                v2[2]=0;
                            } // FIM DA 2
                    }

                    if(saida==3){
                        if(destino==1 && v1[2]==0 && v3[0]!=0)
                        {
                            v1[2]=v3[0];
                            v3[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v1[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v1[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1])
                            {
                                v1[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[0]=v3[2];
                                v3[2]=0;
                            }
                            if(destino==2 && v2[2]==0 && v3[0]!=0)
                            {
                                v2[2]=v3[0];
                                v3[0]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v2[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v2[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1])
                            {
                                v2[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[0]=v3[2];
                                v3[2]=0;
                            }
                        }
                        system("cls");
                        cont++;
                }
                cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<cont<<" jogadas."<<endl;
                cout<<"Para continuar, aperte 1"<<endl;
                cin>>n2;
            }
            if(v==m){
            // nível médio


                system("cls");
                int v1[5],v2[5],v3[5],i,saida,destino,cont=0;

                for(i=0; i<5; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }

                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]!=15 && v3[0]+v3[1]+v3[2]+v3[3]+v3[4]!=15)
                {
                    for(i=0; i<5; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << cont << endl;
                    cout << nome << ", digite a coluna que você quer modificar: ";
                    cin  >> saida;
                    cout << "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[4]==0 && v1[0]!=0)
                        {
                            v2[4]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]!=0)
                        {
                            v2[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0)
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0)
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1])
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2])
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3])
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v1[3]==0 && v1[4]!=0 && v2[4]>v1[4])
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2])
                            {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3])
                            {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[3]>v1[4])
                            {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3])
                            {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[2]>v1[4])
                            {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[1]>v1[4])
                            {
                            v2[0]=v1[4];
                            v1[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v1[0]!=0)
                            {
                                v3[4]=v1[0];
                                v1[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]!=0)
                            {
                            v3[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0)
                            {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0)
                            {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1])
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2])
                            {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3])
                            {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[4]>v1[4])
                            {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2])
                            {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3])
                            {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[3]>v1[4])
                            {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3])
                            {
                            v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[2]>v1[4])
                            {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[1]>v1[4])
                            {
                            v3[0]=v1[4];
                            v1[4]=0;
                        }
                }

                if(saida==2)
                {
                    if(destino==1 && v1[4]==0 && v2[0]!=0)
                        {
                            v1[4]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]!=0)
                        {
                            v1[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0)
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0)
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1])
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2])
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3])
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[4]>v2[4])
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2])
                            {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3])
                            {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[3]>v2[4])
                            {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3])
                            {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[2]>v2[4])
                            {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[1]>v2[4])
                            {
                            v1[0]=v2[4];
                            v2[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v2[0]!=0)
                            {
                                v3[4]=v2[0];
                                v2[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]!=0)
                            {
                            v3[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0)
                            {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0)
                            {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1])
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2])
                            {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3])
                            {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[4]>v2[4])
                            {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2])
                            {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3])
                            {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[3]>v2[4])
                            {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3])
                            {
                            v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[2]>v2[4])
                            {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[1]>v2[4])
                            {
                            v3[0]=v2[4];
                            v2[4]=0;
                        }
                }

                if(saida==3){

                        if(destino==1 && v1[4]==0 && v3[0]!=0)
                        {
                            v1[4]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]!=0)
                        {
                            v1[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0)
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0)
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1])
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2])
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3])
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[4]>v3[4])
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2])
                            {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3])
                            {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[3]>v3[4])
                            {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3])
                            {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[2]>v3[4])
                            {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[1]>v3[4])
                            {
                            v1[0]=v3[4];
                            v3[4]=0;
                        } //FIM

                    if(destino==2 && v2[4]==0 && v3[0]!=0)
                            {
                                v2[4]=v3[0];
                                v3[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]!=0)
                            {
                            v2[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0)
                            {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0)
                            {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1])
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2])
                            {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3])
                            {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[4]>v3[4])
                            {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2])
                            {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3])
                            {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[3]>v3[4])
                            {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3])
                            {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[2]>v3[4])
                            {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[1]>v3[4])
                            {
                            v2[0]=v3[4];
                            v3[4]=0;
                        }


                        }
                       system("cls");
                       cont++;
                }
                cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<cont<<" jogadas."<<endl;
                cout<<"Para continuar, aperte 1"<<endl;
                cin>>n2;


            }
            if(v==d){
            // nível difícil

                system("cls");
                int v1[7],v2[7],v3[7],i,saida,destino,a,r;

                for(i=0; i<7; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]+v2[5]+v2[6]!=28 && v3[0]+v3[1]+v3[2]+v3[4]+v3[5]+v3[6]!=28)
                {
                    for(i=0; i<7; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << cont << endl;
                    cout << "Digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[6]==0 && v1[0]!=0) //OK
                        {
                            v2[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v2[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v2[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v2[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v2[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v2[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v2[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]!=0 && v2[6]>v1[1]) //OK
                            {
                            v2[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[6]>v1[2]) //OK
                        {
                            v2[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[6]>v1[3]) //OK
                        {
                            v2[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[6]>v1[4]) //OK
                        {
                            v2[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v2[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v2[6]>v1[6]) //OK
                        {
                            v2[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[5]>v1[2]) //OK
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[5]>v1[3]) //OK
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[5]>v1[4]) //OK
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[5]>v1[5]) //OK
                        {
                            v2[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[5]>v1[6]) //OK
                        {
                            v2[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1]) //OK
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2]) //OK
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3]) //OK
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[4]>v1[4]) //OK
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[4]>v1[5]) //OK
                        {
                            v2[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v2[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]!=0 && v2[3]>v1[1]) //OK
                            {
                            v2[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2]) //OK
                        {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3]) //OK
                        {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[3]>v1[4]) //OK
                        {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[3]>v1[5]) //OK
                        {
                            v2[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[3]>v1[6]) //OK
                        {
                            v2[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1]) //OK
                            {
                            v2[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2]) //OK
                        {
                            v2[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3]) //OK
                        {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[2]>v1[4]) //OK
                        {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[2]>v1[5]) //OK
                        {
                            v2[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[2]>v1[6]) //OK
                        {
                            v2[1]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v2[1]>v1[6])//OK
                            {
                            v2[0]=v1[6];
                            v1[6]=0;

                        }
                         //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v1[0]!=0) //OK
                        {
                            v3[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v3[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v3[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v3[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v3[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v3[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v3[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]!=0 && v3[6]>v1[1]) //OK
                            {
                            v3[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[6]>v1[2]) //OK
                        {
                            v3[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[6]>v1[3]) //OK
                        {
                            v3[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[6]>v1[4]) //OK
                        {
                            v3[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v3[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v3[6]>v1[6]) //OK
                        {
                            v3[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[5]>v1[2]) //OK
                        {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[5]>v1[3]) //OK
                        {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[5]>v1[4]) //OK
                        {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[5]>v1[5]) //OK
                        {
                            v3[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[5]>v1[6]) //OK
                        {
                            v3[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1]) //OK
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2]) //OK
                        {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3]) //OK
                        {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[4]>v1[4]) //OK
                        {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[4]>v1[5]) //OK
                        {
                            v3[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v3[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]!=0 && v3[3]>v1[1]) //OK
                            {
                            v3[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2]) //OK
                        {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3]) //OK
                        {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[3]>v1[4]) //OK
                        {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[3]>v1[5]) //OK
                        {
                            v3[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[3]>v1[6]) //OK
                        {
                            v3[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1]) //OK
                            {
                            v3[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2]) //OK
                        {
                            v3[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3]) //OK
                        {
                           v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[2]>v1[4]) //OK
                        {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[2]>v1[5]) //OK
                        {
                            v3[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[2]>v1[6]) //OK
                        {
                            v3[1]=v1[6];
                            v1[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v3[1]>v1[6])//OK
                            {
                            v3[0]=v1[6];
                            v1[6]=0;
                 }       } //FIM

if(saida==2)
                {
                    if(destino==1 && v1[6]==0 && v2[0]!=0) //OK
                        {
                            v1[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v1[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v1[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v1[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v1[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v1[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v1[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]!=0 && v1[6]>v2[1]) //OK
                        {
                            v1[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[6]>v2[2]) //OK
                        {
                            v1[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[6]>v2[3]) //OK
                        {
                            v1[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[6]>v2[4]) //OK
                        {
                            v1[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[6]>v2[5]) //OK
                        {
                            v1[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v1[6]>v2[6]) //OK
                        {
                            v1[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[5]>v2[2]) //OK
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[5]>v2[3]) //OK
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[5]>v2[4]) //OK
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[5]>v2[5]) //OK
                        {
                            v1[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[5]>v2[6]) //OK
                        {
                            v1[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1]) //OK
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2]) //OK
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3]) //OK
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[4]>v2[4]) //OK
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[4]>v2[5]) //OK
                        {
                            v1[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v1[4]>v2[6]) //OK
                        {
                            v1[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]!=0 && v1[3]>v2[1]) //OK
                            {
                            v1[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2]) //OK
                        {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3]) //OK
                        {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[3]>v2[4]) //OK
                        {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[3]>v2[5]) //OK
                        {
                            v1[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[3]>v2[6]) //OK
                        {
                            v1[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1]) //OK
                            {
                            v1[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2]) //OK
                        {
                            v1[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3]) //OK
                        {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[2]>v2[4]) //OK
                        {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[2]>v2[5]) //OK
                        {
                            v1[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[2]>v2[6]) //OK
                        {
                            v1[1]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v1[1]>v2[6])//OK
                            {
                            v1[0]=v2[6];
                            v2[6]=0;
                        }
                        //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v2[0]!=0) //OK
                        {
                            v3[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v3[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v3[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v3[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v3[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v3[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v3[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]!=0 && v3[6]>v2[1]) //OK
                            {
                            v3[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[6]>v2[2]) //OK
                        {
                            v3[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[6]>v2[3]) //OK
                        {
                            v3[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[6]>v2[4]) //OK
                        {
                            v3[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[6]>v2[5]) //OK
                        {
                            v3[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v3[6]>v2[6]) //OK
                        {
                            v3[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[5]>v2[2]) //OK
                        {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[5]>v2[3]) //OK
                        {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[5]>v2[4]) //OK
                        {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[5]>v2[5]) //OK
                        {
                            v3[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[5]>v2[6]) //OK
                        {
                            v3[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1]) //OK
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2]) //OK
                        {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3]) //OK
                        {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[4]>v2[4]) //OK
                        {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[4]>v2[5]) //OK
                        {
                            v3[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v3[4]>v2[6]) //OK
                        {
                            v3[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]!=0 && v3[3]>v2[1]) //OK
                            {


                            v2[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2]) //OK
                        {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3]) //OK
                        {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[3]>v2[4]) //OK
                        {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[3]>v2[5]) //OK
                        {
                            v3[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[3]>v2[6]) //OK
                        {
                            v3[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1]) //OK
                            {
                            v3[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2]) //OK
                        {
                            v3[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3]) //OK
                        {
                           v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[2]>v2[4]) //OK
                        {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[2]>v2[5]) //OK
                        {
                            v3[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[2]>v2[6]) //OK
                        {
                            v3[1]=v2[6];
                            v2[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v3[1]>v2[6])//OK
                            {
                            v3[0]=v2[6];
                            v2[6]=0;
                    }    }




if(saida==3)
                {
                    if(destino==1 && v1[6]==0 && v3[0]!=0) //OK
                        {
                            v1[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v1[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v1[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v1[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v1[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v1[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v1[6]=v3[6];
                            v3[6]=0;}



                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]!=0 && v1[6]>v3[1]) //OK
                        {
                            v1[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[6]>v3[2]) //OK
                        {
                            v1[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[6]>v3[3]) //OK
                        {
                            v1[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[6]>v3[4]) //OK
                        {
                            v1[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[6]>v3[5]) //OK
                        {
                            v1[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v1[6]>v3[6]) //OK
                        {
                            v1[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[5]>v3[2]) //OK
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[5]>v3[3]) //OK
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[5]>v3[4]) //OK
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[5]>v3[5]) //OK
                        {
                            v1[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[5]>v3[6]) //OK
                        {
                            v1[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1]) //OK
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2]) //OK
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3]) //OK
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[4]>v3[4]) //OK
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[4]>v3[5]) //OK
                        {
                            v1[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v1[4]>v3[6]) //OK
                        {
                            v1[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]!=0 && v1[3]>v3[1]) //OK
                            {
                            v1[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2]) //OK
                        {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3]) //OK
                        {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[3]>v3[4]) //OK
                        {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[3]>v3[5]) //OK
                        {
                            v1[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[3]>v3[6]) //OK
                        {
                            v1[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1]) //OK
                            {
                            v1[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2]) //OK
                        {
                            v1[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3]) //OK
                        {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[2]>v3[4]) //OK
                        {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[2]>v3[5]) //OK
                        {
                            v1[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[2]>v3[6]) //OK
                        {
                            v1[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v1[1]>v3[6])//OK
                            {
                            v1[0]=v3[6];
                            v3[6]=0;
                        }
                        //FIM



                        if(destino==2 && v2[6]==0 && v3[0]!=0) //OK
                        {
                            v2[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v2[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v2[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v2[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v2[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v2[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v2[6]=v3[6];
                            v3[6]=0;}


                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]!=0 && v2[6]>v3[1]) //OK
                            {
                            v2[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[6]>v3[2]) //OK
                        {
                            v2[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[6]>v3[3]) //OK
                        {
                            v2[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[6]>v3[4]) //OK
                        {
                            v2[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[6]>v3[5]) //OK
                        {
                            v2[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v2[6]>v3[6]) //OK
                        {
                            v2[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[5]>v3[2]) //OK
                        {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[5]>v3[3]) //OK
                        {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[5]>v3[4]) //OK
                        {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[5]>v3[5]) //OK
                        {
                            v2[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[5]>v3[6]) //OK
                        {
                            v2[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1]) //OK
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2]) //OK
                        {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3]) //OK
                        {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[4]>v3[4]) //OK
                        {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[4]>v3[5]) //OK
                        {
                            v2[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v2[4]>v3[6]) //OK
                        {
                            v2[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]!=0 && v2[3]>v3[1]) //OK
                            {
                            v2[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2]) //OK
                        {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3]) //OK
                        {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[3]>v3[4]) //OK
                        {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[3]>v3[5]) //OK
                        {
                            v2[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[3]>v3[6]) //OK
                        {
                            v2[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1]) //OK
                            {
                            v2[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2]) //OK
                        {
                            v2[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3]) //OK
                        {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[2]>v3[4]) //OK
                        {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[2]>v3[5]) //OK
                        {
                            v2[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[2]>v3[6]) //OK
                        {
                            v2[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v2[1]>v3[6])//OK
                            {
                            v2[0]=v3[6];
                            v3[6]=0;
                        }
                        } //FIM
                    system("cls");
                    cont++;
                }

                cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<cont<<" jogadas."<<endl;
                cout<<"Para continuar, aperte 1"<<endl;
                cin>>n2;

            }
        }
        if(n2==2){

            system("cls");
            int play1=0, play2=0, jogo;
            char nome2[50];
            cout<<nome<<", digite o nome do play 2"<<endl;
            cin.ignore();
            cin.getline(nome2,50);

            system("cls");
            cout<<"Os pinos são 1, 2 e 3"<<endl<<endl;
            cout<<"Escolha o nível : [fácil(3), médio(5) e difícil(7)"<<endl<<endl;
            cout<<"Fácil= 3 pinos"<<endl<<"Médio= 5 pinos"<<endl<<"Difícil= 7 pinos"<<endl<<endl;
            cin>>v;
            if(v==f){
            // nível fácil multiplayer

                system("cls");
                cout<<nome<<", primeiro você vai jogar e depois irá jogar "<<nome2<<endl<<endl;
                cout<<"Aperte 1 começar"<<endl;
                cin>>jogo;

                if(jogo==1){
                    system("cls");
                    int v1[3],v2[3],v3[3],i,saida,destino;

                for(i=0; i<3; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]!=6 && v3[0]+v3[1]+v3[2]!=6){
                    for(i=0; i<3; i++){
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play1 << endl;
                    cout << nome << ", digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << nome << ", para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1){
                        if(destino==2 && v2[2]==0 && v1[0]!=0){ //OK
                            v2[2]=v1[0];
                            v1[0]=0;
                        }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]!=0) //OK
                            {
                                v2[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                            {
                                v2[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1]) //OK
                            {
                                v2[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2]) //OK
                            {
                                v2[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2])//OK
                            {
                                v2[0]=v1[2];
                                v1[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v1[0]!=0)
                        {
                                v3[2]=v1[0];
                                v1[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]!=0)
                            {
                                v3[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                                v3[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1])
                            {
                                v3[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[0]=v1[2];
                                v1[2]=0;
                            } // FIM DA 1
                    }

                    if(saida==2)
                    {
                        if(destino==1 && v1[2]==0 && v2[0]!=0)
                        {
                            v1[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v1[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v1[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1])
                            {
                                v1[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[1]=v2[2];
                                v2[2]=0;
                            }

                            else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[0]=v2[2];
                                v2[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v2[0]!=0)
                        {
                            v3[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v3[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v3[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1])
                            {
                                v3[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[1]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[0]=v2[2];
                                v2[2]=0;
                            } // FIM DA 2
                    }

                    if(saida==3){
                        if(destino==1 && v1[2]==0 && v3[0]!=0)
                        {
                            v1[2]=v3[0];
                            v3[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v1[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v1[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1])
                            {
                                v1[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[0]=v3[2];
                                v3[2]=0;
                            }
                            if(destino==2 && v2[2]==0 && v3[0]!=0)
                            {
                                v2[2]=v3[0];
                                v3[0]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v2[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v2[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1])
                            {
                                v2[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[0]=v3[2];
                                v3[2]=0;
                            }
                        }
                        system("cls");
                        play1++;
                }
                cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<play1<<" jogadas."<<endl;
                cout<<"Para continuar, aperte 2"<<endl;
                cin>>jogo;
            }
                if(jogo==2){

                    system("cls");
                    int v1[3],v2[3],v3[3],i,saida,destino;

                for(i=0; i<3; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]!=6 && v3[0]+v3[1]+v3[2]!=6){
                    for(i=0; i<3; i++){
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play2 << endl;
                    cout << nome2 << ", digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << nome2 << ", para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1){
                        if(destino==2 && v2[2]==0 && v1[0]!=0){ //OK
                            v2[2]=v1[0];
                            v1[0]=0;
                        }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]!=0) //OK
                            {
                                v2[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                            {
                                v2[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1]) //OK
                            {
                                v2[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2]) //OK
                            {
                                v2[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2])//OK
                            {
                                v2[0]=v1[2];
                                v1[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v1[0]!=0)
                        {
                                v3[2]=v1[0];
                                v1[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]!=0)
                            {
                                v3[2]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                                v3[2]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1])
                            {
                                v3[1]=v1[1];
                                v1[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[1]=v1[2];
                                v1[2]=0;
                            }

                            else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2])
                            {
                                v3[0]=v1[2];
                                v1[2]=0;
                            } // FIM DA 1
                    }

                    if(saida==2)
                    {
                        if(destino==1 && v1[2]==0 && v2[0]!=0)
                        {
                            v1[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v1[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v1[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1])
                            {
                                v1[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[1]=v2[2];
                                v2[2]=0;
                            }

                            else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2])
                            {
                                v1[0]=v2[2];
                                v2[2]=0;
                            } //FIM

                        if(destino==3 && v3[2]==0 && v2[0]!=0)
                        {
                            v3[2]=v2[0];
                            v2[0]=0;
                        }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]!=0)
                            {
                                v3[2]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                                v3[2]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1])
                            {
                                v3[1]=v2[1];
                                v2[1]=0;
                            }
                            else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[1]=v2[2];
                                v2[2]=0;
                            }
                            else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2])
                            {
                                v3[0]=v2[2];
                                v2[2]=0;
                            } // FIM DA 2
                    }

                    if(saida==3){
                        if(destino==1 && v1[2]==0 && v3[0]!=0)
                        {
                            v1[2]=v3[0];
                            v3[0]=0;
                        }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v1[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v1[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1])
                            {
                                v1[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2])
                            {
                                v1[0]=v3[2];
                                v3[2]=0;
                            }
                            if(destino==2 && v2[2]==0 && v3[0]!=0)
                            {
                                v2[2]=v3[0];
                                v3[0]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]!=0)
                            {
                                v2[2]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                                v2[2]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1])
                            {
                                v2[1]=v3[1];
                                v3[1]=0;
                            }
                            else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[1]=v3[2];
                                v3[2]=0;
                            }
                            else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2])
                            {
                                v2[0]=v3[2];
                                v3[2]=0;
                            }
                        }
                        system("cls");
                        play2++;
                }
                cout << "Fim de jogo, " << nome2 <<endl<< "Houveram "<<play2<<" jogadas."<<endl;
                cout<<"Para ver o resultado, aperte 3"<<endl;
                cin>>jogo;
            }
            if(jogo==3){
                system("cls");
                if(play1<play2){
                    cout<<nome<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                }
                else if(play2<play1){
                    cout<<nome2<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                }
                else{
                    cout<<"Deu empate."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                }
                cout<<"Para voltar ao menu, aperte 1"<<endl;
                cin>>n2;
                }
            }

            if(v==m){
            // nível médio multiplayer

                system("cls");
                cout<<nome<<", primeiro você vai jogar e depois irá jogar "<<nome2<<endl<<endl;
                cout<<"Aperte 1 começar"<<endl;
                cin>>jogo;

                if(jogo==1){


                    system("cls");
                int v1[5],v2[5],v3[5],i,saida,destino,cont=0;

                for(i=0; i<5; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }

                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]!=15 && v3[0]+v3[1]+v3[2]+v3[3]+v3[4]!=15)
                {
                    for(i=0; i<5; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play1 << endl;
                    cout <<"                "<< nome << ", digite a coluna que você quer modificar: ";
                    cin  >> saida;
                    cout <<"                "<< "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[4]==0 && v1[0]!=0) //OK
                        {
                            v2[4]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v2[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1]) //OK
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2]) //OK
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3]) //OK
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v1[3]==0 && v1[4]!=0 && v2[4]>v1[4]) //OK
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2]) //OK
                            {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3]) //OK
                            {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[3]>v1[4]) //OK
                            {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3]) //OK
                            {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[2]>v1[4]) //OK
                            {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[1]>v1[4])//OK
                            {
                            v2[0]=v1[4];
                            v1[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v1[0]!=0)
                            {
                                v3[4]=v1[0];
                                v1[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]!=0)
                            {
                            v3[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0)
                            {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0)
                            {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1])
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2])
                            {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3])
                            {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[4]>v1[4])
                            {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2])
                            {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3])
                            {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[3]>v1[4])
                            {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3]) //OK
                            {
                            v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[2]>v1[4]) //OK
                            {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[1]>v1[4])//OK
                            {
                            v3[0]=v1[4];
                            v1[4]=0;
                        }
                }

                if(saida==2)
                {
                    if(destino==1 && v1[4]==0 && v2[0]!=0) //OK
                        {
                            v1[4]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v1[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1]) //OK
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2]) //OK
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3]) //OK
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[4]>v2[4]) //OK
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2]) //OK
                            {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3]) //OK
                            {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[3]>v2[4]) //OK
                            {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3]) //OK
                            {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[2]>v2[4]) //OK
                            {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[1]>v2[4])//OK
                            {
                            v1[0]=v2[4];
                            v2[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v2[0]!=0)
                            {
                                v3[4]=v2[0];
                                v2[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]!=0)
                            {
                            v3[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0)
                            {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0)
                            {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1])
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2])
                            {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3])
                            {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[4]>v2[4])
                            {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2])
                            {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3])
                            {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[3]>v2[4])
                            {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3]) //OK
                            {
                            v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[2]>v2[4]) //OK
                            {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[1]>v2[4])//OK
                            {
                            v3[0]=v2[4];
                            v2[4]=0;
                        }
                }

                if(saida==3){

                        if(destino==1 && v1[4]==0 && v3[0]!=0) //OK
                        {
                            v1[4]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v1[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1]) //OK
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2]) //OK
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3]) //OK
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[4]>v3[4]) //OK
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2]) //OK
                            {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3]) //OK
                            {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[3]>v3[4]) //OK
                            {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3]) //OK
                            {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[2]>v3[4]) //OK
                            {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[1]>v3[4])//OK
                            {
                            v1[0]=v3[4];
                            v3[4]=0;
                        } //FIM

                    if(destino==2 && v2[4]==0 && v3[0]!=0)
                            {
                                v2[4]=v3[0];
                                v3[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]!=0)
                            {
                            v2[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0)
                            {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0)
                            {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1])
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2])
                            {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3])
                            {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[4]>v3[4])
                            {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2])
                            {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3])
                            {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[3]>v3[4])
                            {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3]) //OK
                            {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[2]>v3[4]) //OK
                            {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[1]>v3[4])//OK
                            {
                            v2[0]=v3[4];
                            v3[4]=0;
                        }


                        }
                       system("cls");
                       play1++;
                }
                cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<play1<<" jogadas."<<endl;
                cout<<"Para continuar, aperte 2"<<endl;
                cin>>jogo;


                }
                if(jogo==2){

                    system("cls");
                    int v1[5],v2[5],v3[5],i,saida,destino,cont=0;

                    for(i=0; i<5; i++){

                        v1[i]=i+1; v2[i]=0; v3[i]=0;
                    }

                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]!=15 && v3[0]+v3[1]+v3[2]+v3[3]+v3[4]!=15)
                {
                    for(i=0; i<5; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play2 << endl;
                    cout <<"                "<< nome2 << ", digite a coluna que você quer modificar: ";
                    cin  >> saida;
                    cout <<"                "<< "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[4]==0 && v1[0]!=0) //OK
                        {
                            v2[4]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v2[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1]) //OK
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2]) //OK
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3]) //OK
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v1[3]==0 && v1[4]!=0 && v2[4]>v1[4]) //OK
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2]) //OK
                            {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3]) //OK
                            {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[3]>v1[4]) //OK
                            {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3]) //OK
                            {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[2]>v1[4]) //OK
                            {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==2 && v2[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v2[1]>v1[4])//OK
                            {
                            v2[0]=v1[4];
                            v1[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v1[0]!=0)
                            {
                                v3[4]=v1[0];
                                v1[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]!=0)
                            {
                            v3[4]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0)
                            {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0)
                            {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0)
                            {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1])
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2])
                            {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3])
                            {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[4]>v1[4])
                            {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2])
                            {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3])
                            {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[3]>v1[4])
                            {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3]) //OK
                            {
                            v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[2]>v1[4]) //OK
                            {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0 && v3[1]>v1[4])//OK
                            {
                            v3[0]=v1[4];
                            v1[4]=0;
                        }
                }

                if(saida==2)
                {
                    if(destino==1 && v1[4]==0 && v2[0]!=0) //OK
                        {
                            v1[4]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v1[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1]) //OK
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2]) //OK
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3]) //OK
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[4]>v2[4]) //OK
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2]) //OK
                            {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3]) //OK
                            {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[3]>v2[4]) //OK
                            {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3]) //OK
                            {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[2]>v2[4]) //OK
                            {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v1[1]>v2[4])//OK
                            {
                            v1[0]=v2[4];
                            v2[4]=0;
                        } //FIM

                    if(destino==3 && v3[4]==0 && v2[0]!=0)
                            {
                                v3[4]=v2[0];
                                v2[0]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]!=0)
                            {
                            v3[4]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0)
                            {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0)
                            {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0)
                            {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1])
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2])
                            {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3])
                            {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[4]>v2[4])
                            {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }

                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2])
                            {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3])
                            {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[3]>v2[4])
                            {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3]) //OK
                            {
                            v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[2]>v2[4]) //OK
                            {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[0]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0 && v3[1]>v2[4])//OK
                            {
                            v3[0]=v2[4];
                            v2[4]=0;
                        }
                }

                if(saida==3){

                        if(destino==1 && v1[4]==0 && v3[0]!=0) //OK
                        {
                            v1[4]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v1[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1]) //OK
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2]) //OK
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3]) //OK
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[4]>v3[4]) //OK
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2]) //OK
                            {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3]) //OK
                            {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[3]>v3[4]) //OK
                            {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3]) //OK
                            {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[2]>v3[4]) //OK
                            {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==1 && v1[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v1[1]>v3[4])//OK
                            {
                            v1[0]=v3[4];
                            v3[4]=0;
                        } //FIM

                    if(destino==2 && v2[4]==0 && v3[0]!=0)
                            {
                                v2[4]=v3[0];
                                v3[0]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]!=0)
                            {
                            v2[4]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0)
                            {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0)
                            {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0)
                            {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1])
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2])
                            {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3])
                            {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[4]>v3[4])
                            {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }

                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2])
                            {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3])
                            {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[3]>v3[4])
                            {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3]) //OK
                            {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[2]>v3[4]) //OK
                            {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[0]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0 && v2[1]>v3[4])//OK
                            {
                            v2[0]=v3[4];
                            v3[4]=0;
                        }


                        }
                       system("cls");
                       play2++;
                }
                cout << "Fim de jogo, " << nome2 <<endl<< "Houveram "<<play2<<" jogadas."<<endl;
                cout<<"Para ver o resultado, aperte 3"<<endl;
                cin>>jogo;

                }
                if(jogo==3){

                    system("cls");
                    if(play1<play2){
                        cout<<nome<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    else if(play2<play1){
                        cout<<nome2<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    else{
                        cout<<"Deu empate."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    cout<<"Para voltar ao menu, aperte 1"<<endl;
                    cin>>n2;

                }
            }
            if(v==d){
            // nível difícil multiplayer

                system("cls");
                cout<<nome<<", primeiro você vai jogar e depois irá jogar "<<nome2<<endl<<endl;
                cout<<"Aperte 1 começar"<<endl;
                cin>>jogo;

                if(jogo==1){
                    system("cls");
                int v1[7],v2[7],v3[7],i,saida,destino,a,r;

                for(i=0; i<7; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]+v2[5]+v2[6]!=28 && v3[0]+v3[1]+v3[2]+v3[4]+v3[5]+v3[6]!=28)
                {
                    for(i=0; i<7; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play1 << endl;
                    cout << nome << ", digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[6]==0 && v1[0]!=0) //OK
                        {
                            v2[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v2[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v2[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v2[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v2[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v2[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v2[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]!=0 && v2[6]>v1[1]) //OK
                            {
                            v2[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[6]>v1[2]) //OK
                        {
                            v2[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[6]>v1[3]) //OK
                        {
                            v2[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[6]>v1[4]) //OK
                        {
                            v2[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v2[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v2[6]>v1[6]) //OK
                        {
                            v2[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[5]>v1[2]) //OK
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[5]>v1[3]) //OK
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[5]>v1[4]) //OK
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[5]>v1[5]) //OK
                        {
                            v2[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[5]>v1[6]) //OK
                        {
                            v2[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1]) //OK
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2]) //OK
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3]) //OK
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[4]>v1[4]) //OK
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[4]>v1[5]) //OK
                        {
                            v2[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v2[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]!=0 && v2[3]>v1[1]) //OK
                            {
                            v2[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2]) //OK
                        {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3]) //OK
                        {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[3]>v1[4]) //OK
                        {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[3]>v1[5]) //OK
                        {
                            v2[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[3]>v1[6]) //OK
                        {
                            v2[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1]) //OK
                            {
                            v2[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2]) //OK
                        {
                            v2[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3]) //OK
                        {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[2]>v1[4]) //OK
                        {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[2]>v1[5]) //OK
                        {
                            v2[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[2]>v1[6]) //OK
                        {
                            v2[1]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v2[1]>v1[6])//OK
                            {
                            v2[0]=v1[6];
                            v1[6]=0;

                        }
                         //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v1[0]!=0) //OK
                        {
                            v3[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v3[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v3[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v3[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v3[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v3[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v3[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]!=0 && v3[6]>v1[1]) //OK
                            {
                            v3[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[6]>v1[2]) //OK
                        {
                            v3[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[6]>v1[3]) //OK
                        {
                            v3[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[6]>v1[4]) //OK
                        {
                            v3[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v3[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v3[6]>v1[6]) //OK
                        {
                            v3[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[5]>v1[2]) //OK
                        {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[5]>v1[3]) //OK
                        {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[5]>v1[4]) //OK
                        {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[5]>v1[5]) //OK
                        {
                            v3[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[5]>v1[6]) //OK
                        {
                            v3[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1]) //OK
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2]) //OK
                        {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3]) //OK
                        {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[4]>v1[4]) //OK
                        {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[4]>v1[5]) //OK
                        {
                            v3[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v3[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]!=0 && v3[3]>v1[1]) //OK
                            {
                            v3[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2]) //OK
                        {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3]) //OK
                        {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[3]>v1[4]) //OK
                        {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[3]>v1[5]) //OK
                        {
                            v3[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[3]>v1[6]) //OK
                        {
                            v3[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1]) //OK
                            {
                            v3[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2]) //OK
                        {
                            v3[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3]) //OK
                        {
                           v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[2]>v1[4]) //OK
                        {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[2]>v1[5]) //OK
                        {
                            v3[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[2]>v1[6]) //OK
                        {
                            v3[1]=v1[6];
                            v1[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v3[1]>v1[6])//OK
                            {
                            v3[0]=v1[6];
                            v1[6]=0;
                 }       } //FIM

if(saida==2)
                {
                    if(destino==1 && v1[6]==0 && v2[0]!=0) //OK
                        {
                            v1[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v1[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v1[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v1[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v1[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v1[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v1[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]!=0 && v1[6]>v2[1]) //OK
                        {
                            v1[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[6]>v2[2]) //OK
                        {
                            v1[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[6]>v2[3]) //OK
                        {
                            v1[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[6]>v2[4]) //OK
                        {
                            v1[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[6]>v2[5]) //OK
                        {
                            v1[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v1[6]>v2[6]) //OK
                        {
                            v1[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[5]>v2[2]) //OK
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[5]>v2[3]) //OK
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[5]>v2[4]) //OK
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[5]>v2[5]) //OK
                        {
                            v1[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[5]>v2[6]) //OK
                        {
                            v1[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1]) //OK
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2]) //OK
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3]) //OK
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[4]>v2[4]) //OK
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[4]>v2[5]) //OK
                        {
                            v1[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v1[4]>v2[6]) //OK
                        {
                            v1[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]!=0 && v1[3]>v2[1]) //OK
                            {
                            v1[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2]) //OK
                        {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3]) //OK
                        {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[3]>v2[4]) //OK
                        {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[3]>v2[5]) //OK
                        {
                            v1[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[3]>v2[6]) //OK
                        {
                            v1[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1]) //OK
                            {
                            v1[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2]) //OK
                        {
                            v1[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3]) //OK
                        {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[2]>v2[4]) //OK
                        {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[2]>v2[5]) //OK
                        {
                            v1[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[2]>v2[6]) //OK
                        {
                            v1[1]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v1[1]>v2[6])//OK
                            {
                            v1[0]=v2[6];
                            v2[6]=0;
                        }
                        //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v2[0]!=0) //OK
                        {
                            v3[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v3[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v3[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v3[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v3[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v3[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v3[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]!=0 && v3[6]>v2[1]) //OK
                            {
                            v3[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[6]>v2[2]) //OK
                        {
                            v3[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[6]>v2[3]) //OK
                        {
                            v3[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[6]>v2[4]) //OK
                        {
                            v3[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[6]>v2[5]) //OK
                        {
                            v3[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v3[6]>v2[6]) //OK
                        {
                            v3[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[5]>v2[2]) //OK
                        {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[5]>v2[3]) //OK
                        {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[5]>v2[4]) //OK
                        {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[5]>v2[5]) //OK
                        {
                            v3[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[5]>v2[6]) //OK
                        {
                            v3[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1]) //OK
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2]) //OK
                        {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3]) //OK
                        {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[4]>v2[4]) //OK
                        {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[4]>v2[5]) //OK
                        {
                            v3[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v3[4]>v2[6]) //OK
                        {
                            v3[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]!=0 && v3[3]>v2[1]) //OK
                            {


                            v2[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2]) //OK
                        {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3]) //OK
                        {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[3]>v2[4]) //OK
                        {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[3]>v2[5]) //OK
                        {
                            v3[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[3]>v2[6]) //OK
                        {
                            v3[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1]) //OK
                            {
                            v3[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2]) //OK
                        {
                            v3[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3]) //OK
                        {
                           v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[2]>v2[4]) //OK
                        {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[2]>v2[5]) //OK
                        {
                            v3[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[2]>v2[6]) //OK
                        {
                            v3[1]=v2[6];
                            v2[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v3[1]>v2[6])//OK
                            {
                            v3[0]=v2[6];
                            v2[6]=0;
                    }    }




if(saida==3)
                {
                    if(destino==1 && v1[6]==0 && v3[0]!=0) //OK
                        {
                            v1[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v1[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v1[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v1[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v1[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v1[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v1[6]=v3[6];
                            v3[6]=0;}



                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]!=0 && v1[6]>v3[1]) //OK
                        {
                            v1[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[6]>v3[2]) //OK
                        {
                            v1[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[6]>v3[3]) //OK
                        {
                            v1[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[6]>v3[4]) //OK
                        {
                            v1[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[6]>v3[5]) //OK
                        {
                            v1[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v1[6]>v3[6]) //OK
                        {
                            v1[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[5]>v3[2]) //OK
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[5]>v3[3]) //OK
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[5]>v3[4]) //OK
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[5]>v3[5]) //OK
                        {
                            v1[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[5]>v3[6]) //OK
                        {
                            v1[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1]) //OK
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2]) //OK
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3]) //OK
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[4]>v3[4]) //OK
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[4]>v3[5]) //OK
                        {
                            v1[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v1[4]>v3[6]) //OK
                        {
                            v1[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]!=0 && v1[3]>v3[1]) //OK
                            {
                            v1[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2]) //OK
                        {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3]) //OK
                        {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[3]>v3[4]) //OK
                        {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[3]>v3[5]) //OK
                        {
                            v1[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[3]>v3[6]) //OK
                        {
                            v1[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1]) //OK
                            {
                            v1[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2]) //OK
                        {
                            v1[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3]) //OK
                        {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[2]>v3[4]) //OK
                        {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[2]>v3[5]) //OK
                        {
                            v1[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[2]>v3[6]) //OK
                        {
                            v1[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v1[1]>v3[6])//OK
                            {
                            v1[0]=v3[6];
                            v3[6]=0;
                        }
                        //FIM



                        if(destino==2 && v2[6]==0 && v3[0]!=0) //OK
                        {
                            v2[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v2[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v2[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v2[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v2[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v2[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v2[6]=v3[6];
                            v3[6]=0;}


                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]!=0 && v2[6]>v3[1]) //OK
                            {
                            v2[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[6]>v3[2]) //OK
                        {
                            v2[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[6]>v3[3]) //OK
                        {
                            v2[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[6]>v3[4]) //OK
                        {
                            v2[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[6]>v3[5]) //OK
                        {
                            v2[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v2[6]>v3[6]) //OK
                        {
                            v2[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[5]>v3[2]) //OK
                        {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[5]>v3[3]) //OK
                        {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[5]>v3[4]) //OK
                        {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[5]>v3[5]) //OK
                        {
                            v2[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[5]>v3[6]) //OK
                        {
                            v2[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1]) //OK
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2]) //OK
                        {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3]) //OK
                        {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[4]>v3[4]) //OK
                        {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[4]>v3[5]) //OK
                        {
                            v2[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v2[4]>v3[6]) //OK
                        {
                            v2[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]!=0 && v2[3]>v3[1]) //OK
                            {
                            v2[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2]) //OK
                        {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3]) //OK
                        {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[3]>v3[4]) //OK
                        {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[3]>v3[5]) //OK
                        {
                            v2[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[3]>v3[6]) //OK
                        {
                            v2[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1]) //OK
                            {
                            v2[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2]) //OK
                        {
                            v2[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3]) //OK
                        {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[2]>v3[4]) //OK
                        {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[2]>v3[5]) //OK
                        {
                            v2[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[2]>v3[6]) //OK
                        {
                            v2[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v2[1]>v3[6])//OK
                            {
                            v2[0]=v3[6];
                            v3[6]=0;
                        }
                        } //FIM
                    system("cls");
                    play1++;
                }

                    cout << "Fim de jogo, " << nome <<endl<< "Houveram "<<play1<<" jogadas."<<endl;
                    cout<<"Para continuar, aperte 2"<<endl;
                    cin>>jogo;
                }
                if(jogo==2){

                    system("cls");
                int v1[7],v2[7],v3[7],i,saida,destino;

                for(i=0; i<7; i++){

                    v1[i]=i+1; v2[i]=0; v3[i]=0;
                }
                while(v2[0]+v2[1]+v2[2]+v2[3]+v2[4]+v2[5]+v2[6]!=28 && v3[0]+v3[1]+v3[2]+v3[4]+v3[5]+v3[6]!=28)
                {
                    for(i=0; i<7; i++)
                    {
                        cout<<"["<<v1[i]<<"]"<<"      "<<"["<<v2[i]<<"]"<<"      "<<"["<<v3[i]<<"]"<<endl;
                    }
                    cout << "----------------------" << endl;
                    cout << " 1        2        3" << endl;
                    cout << endl;
                    cout << "Número de jogadas: " << play2 << endl;
                    cout << nome2 << ", digite a coluna que voce quer modificar: ";
                    cin  >> saida;
                    cout << "Para qual pilar o número será transferido? ";
                    cin  >> destino;

                    if(saida==1)
                    {
                        if(destino==2 && v2[6]==0 && v1[0]!=0) //OK
                        {
                            v2[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v2[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v2[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v2[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v2[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v2[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==2 && v2[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v2[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]!=0 && v2[6]>v1[1]) //OK
                            {
                            v2[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[6]>v1[2]) //OK
                        {
                            v2[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[6]>v1[3]) //OK
                        {
                            v2[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[6]>v1[4]) //OK
                        {
                            v2[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v2[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v2[6]>v1[6]) //OK
                        {
                            v2[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[5]>v1[2]) //OK
                        {
                            v2[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[5]>v1[3]) //OK
                        {
                            v2[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[5]>v1[4]) //OK
                        {
                            v2[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[5]>v1[5]) //OK
                        {
                            v2[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[5]>v1[6]) //OK
                        {
                            v2[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]!=0 && v2[4]>v1[1]) //OK
                            {
                            v2[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[4]>v1[2]) //OK
                        {
                            v2[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[4]>v1[3]) //OK
                        {
                            v2[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[4]>v1[4]) //OK
                        {
                            v2[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[4]>v1[5]) //OK
                        {
                            v2[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v2[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]!=0 && v2[3]>v1[1]) //OK
                            {
                            v2[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[3]>v1[2]) //OK
                        {
                            v2[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[3]>v1[3]) //OK
                        {
                            v2[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[3]>v1[4]) //OK
                        {
                            v2[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[3]>v1[5]) //OK
                        {
                            v2[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[3]>v1[6]) //OK
                        {
                            v2[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]!=0 && v2[2]>v1[1]) //OK
                            {
                            v2[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v2[2]>v1[2]) //OK
                        {
                            v2[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v2[2]>v1[3]) //OK
                        {
                            v2[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v2[2]>v1[4]) //OK
                        {
                            v2[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[2]>v1[5]) //OK
                        {
                            v2[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v2[2]>v1[6]) //OK
                        {
                            v2[1]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v2[1]>v1[6])//OK
                            {
                            v2[0]=v1[6];
                            v1[6]=0;

                        }
                         //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v1[0]!=0) //OK
                        {
                            v3[6]=v1[0];
                            v1[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]!=0) //OK
                        {
                            v3[6]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0) //OK
                        {
                            v3[6]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0) //OK
                        {
                            v3[6]=v1[3];
                            v1[3]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]!=0) //OK
                        {
                            v3[6]=v1[4];
                            v1[4]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]!=0) //OK
                        {
                            v3[6]=v1[5];
                            v1[5]=0;}
                        else if (destino==3 && v3[6]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0) //OK
                        {
                            v3[6]=v1[6];
                            v1[6]=0;}



                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]!=0 && v3[6]>v1[1]) //OK
                            {
                            v3[5]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[6]>v1[2]) //OK
                        {
                            v3[5]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[6]>v1[3]) //OK
                        {
                            v3[5]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[6]>v1[4]) //OK
                        {
                            v3[5]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v2[6]>v1[5]) //OK
                        {
                            v3[5]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  &&  v1[6]!=0 && v3[6]>v1[6]) //OK
                        {
                            v3[5]=v1[6];
                            v1[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[5]>v1[2]) //OK
                        {
                            v3[4]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[5]>v1[3]) //OK
                        {
                            v3[4]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[5]>v1[4]) //OK
                        {
                            v3[4]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[5]>v1[5]) //OK
                        {
                            v3[4]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[5]>v1[6]) //OK
                        {
                            v3[4]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]!=0 && v3[4]>v1[1]) //OK
                            {
                            v3[3]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[4]>v1[2]) //OK
                        {
                            v3[3]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[4]>v1[3]) //OK
                        {
                            v3[3]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[4]>v1[4]) //OK
                        {
                            v3[3]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[4]>v1[5]) //OK
                        {
                            v3[3]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0  && v2[4]>v1[6]) //OK
                        {
                            v3[3]=v1[6];
                            v1[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]!=0 && v3[3]>v1[1]) //OK
                            {
                            v3[2]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[3]>v1[2]) //OK
                        {
                            v3[2]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[3]>v1[3]) //OK
                        {
                            v3[2]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[3]>v1[4]) //OK
                        {
                            v3[2]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[3]>v1[5]) //OK
                        {
                            v3[2]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[3]>v1[6]) //OK
                        {
                            v3[2]=v1[6];
                            v1[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]!=0 && v3[2]>v1[1]) //OK
                            {
                            v3[1]=v1[1];
                            v1[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]!=0 && v3[2]>v1[2]) //OK
                        {
                            v3[1]=v1[2];
                            v1[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]!=0 && v3[2]>v1[3]) //OK
                        {
                           v3[1]=v1[3];
                            v1[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]!=0 && v3[2]>v1[4]) //OK
                        {
                            v3[1]=v1[4];
                            v1[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]!=0  && v3[2]>v1[5]) //OK
                        {
                            v3[1]=v1[5];
                            v1[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v1[0]==0 && v1[1]==0 && v1[2]==0 && v1[3]==0  && v1[4]==0 && v1[5]==0  && v1[6]!=0 && v3[2]>v1[6]) //OK
                        {
                            v3[1]=v1[6];
                            v1[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v1[0]==0 && v1[1]==0 &&  v1[2]==0 && v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]!=0 && v3[1]>v1[6])//OK
                            {
                            v3[0]=v1[6];
                            v1[6]=0;
                 }       } //FIM

if(saida==2)
                {
                    if(destino==1 && v1[6]==0 && v2[0]!=0) //OK
                        {
                            v1[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v1[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v1[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v1[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v1[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v1[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==1 && v1[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v1[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]!=0 && v1[6]>v2[1]) //OK
                        {
                            v1[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[6]>v2[2]) //OK
                        {
                            v1[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[6]>v2[3]) //OK
                        {
                            v1[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[6]>v2[4]) //OK
                        {
                            v1[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[6]>v2[5]) //OK
                        {
                            v1[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v1[6]>v2[6]) //OK
                        {
                            v1[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[5]>v2[2]) //OK
                        {
                            v1[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[5]>v2[3]) //OK
                        {
                            v1[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[5]>v2[4]) //OK
                        {
                            v1[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[5]>v2[5]) //OK
                        {
                            v1[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[5]>v2[6]) //OK
                        {
                            v1[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]!=0 && v1[4]>v2[1]) //OK
                            {
                            v1[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[4]>v2[2]) //OK
                        {
                            v1[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[4]>v2[3]) //OK
                        {
                            v1[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[4]>v2[4]) //OK
                        {
                            v1[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[4]>v2[5]) //OK
                        {
                            v1[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v1[4]>v2[6]) //OK
                        {
                            v1[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]!=0 && v1[3]>v2[1]) //OK
                            {
                            v1[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[3]>v2[2]) //OK
                        {
                            v1[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[3]>v2[3]) //OK
                        {
                            v1[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[3]>v2[4]) //OK
                        {
                            v1[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[3]>v2[5]) //OK
                        {
                            v1[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[3]>v2[6]) //OK
                        {
                            v1[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]!=0 && v1[2]>v2[1]) //OK
                            {
                            v1[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v1[2]>v2[2]) //OK
                        {
                            v1[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v1[2]>v2[3]) //OK
                        {
                            v1[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v1[2]>v2[4]) //OK
                        {
                            v1[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v1[2]>v2[5]) //OK
                        {
                            v1[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v1[2]>v2[6]) //OK
                        {
                            v1[1]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v1[1]>v2[6])//OK
                            {
                            v1[0]=v2[6];
                            v2[6]=0;
                        }
                        //FIM



                        //aqui termina o dois
                        if(destino==3 && v3[6]==0 && v2[0]!=0) //OK
                        {
                            v3[6]=v2[0];
                            v2[0]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]!=0) //OK
                        {
                            v3[6]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0) //OK
                        {
                            v3[6]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0) //OK
                        {
                            v3[6]=v2[3];
                            v2[3]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]!=0) //OK
                        {
                            v3[6]=v2[4];
                            v2[4]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]!=0) //OK
                        {
                            v3[6]=v2[5];
                            v2[5]=0;}
                        else if (destino==3 && v3[6]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0) //OK
                        {
                            v3[6]=v2[6];
                            v2[6]=0;}



                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]!=0 && v3[6]>v2[1]) //OK
                            {
                            v3[5]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[6]>v2[2]) //OK
                        {
                            v3[5]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[6]>v2[3]) //OK
                        {
                            v3[5]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[6]>v2[4]) //OK
                        {
                            v3[5]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[6]>v2[5]) //OK
                        {
                            v3[5]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  &&  v2[6]!=0 && v3[6]>v2[6]) //OK
                        {
                            v3[5]=v2[6];
                            v2[6]=0;
                        }



                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[5]>v2[2]) //OK
                        {
                            v3[4]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[5]>v2[3]) //OK
                        {
                            v3[4]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[5]>v2[4]) //OK
                        {
                            v3[4]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[5]>v2[5]) //OK
                        {
                            v3[4]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[5]>v2[6]) //OK
                        {
                            v3[4]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]!=0 && v3[4]>v2[1]) //OK
                            {
                            v3[3]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[4]>v2[2]) //OK
                        {
                            v3[3]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[4]>v2[3]) //OK
                        {
                            v3[3]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[4]>v2[4]) //OK
                        {
                            v3[3]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[4]>v2[5]) //OK
                        {
                            v3[3]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0  && v3[4]>v2[6]) //OK
                        {
                            v3[3]=v2[6];
                            v2[6]=0;
                        }

                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]!=0 && v3[3]>v2[1]) //OK
                            {


                            v2[2]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[3]>v2[2]) //OK
                        {
                            v3[2]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[3]>v2[3]) //OK
                        {
                            v3[2]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[3]>v2[4]) //OK
                        {
                            v3[2]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[3]>v2[5]) //OK
                        {
                            v3[2]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[3]>v2[6]) //OK
                        {
                            v3[2]=v2[6];
                            v2[6]=0;
                        }
                         else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]!=0 && v3[2]>v2[1]) //OK
                            {
                            v3[1]=v2[1];
                            v2[1]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]!=0 && v3[2]>v2[2]) //OK
                        {
                            v3[1]=v2[2];
                            v2[2]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]!=0 && v3[2]>v2[3]) //OK
                        {
                           v3[1]=v2[3];
                            v2[3]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]!=0 && v3[2]>v2[4]) //OK
                        {
                            v3[1]=v2[4];
                            v2[4]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]!=0  && v3[2]>v2[5]) //OK
                        {
                            v3[1]=v2[5];
                            v2[5]=0;
                        }
                        else if (destino==3 && v3[5]!=0 &&  v3[4]!=0  && v3[3]!=0  && v3[2]!=0 && v3[1]==0 && v2[0]==0 && v2[1]==0 && v2[2]==0 && v2[3]==0  && v2[4]==0 && v2[5]==0  && v2[6]!=0 && v3[2]>v2[6]) //OK
                        {
                            v3[1]=v2[6];
                            v2[6]=0;
                        }
                        else if (destino==3 && v3[6]!=0 && v3[5]!=0 && v3[4]!=0 && v3[3]!=0 && v3[2]!=0 &&  v3[1]!=0 && v3[0]==0 && v2[0]==0 && v2[1]==0 &&  v2[2]==0 && v2[3]==0 && v2[4]==0 && v2[5]==0 && v2[6]!=0 && v3[1]>v2[6])//OK
                            {
                            v3[0]=v2[6];
                            v2[6]=0;
                    }    }




if(saida==3)
                {
                    if(destino==1 && v1[6]==0 && v3[0]!=0) //OK
                        {
                            v1[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v1[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v1[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v1[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v1[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v1[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==1 && v1[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v1[6]=v3[6];
                            v3[6]=0;}



                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]!=0 && v1[6]>v3[1]) //OK
                        {
                            v1[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[6]>v3[2]) //OK
                        {
                            v1[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[6]>v3[3]) //OK
                        {
                            v1[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[6]>v3[4]) //OK
                        {
                            v1[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[6]>v3[5]) //OK
                        {
                            v1[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v1[6]>v3[6]) //OK
                        {
                            v1[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[5]>v3[2]) //OK
                        {
                            v1[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[5]>v3[3]) //OK
                        {
                            v1[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[5]>v3[4]) //OK
                        {
                            v1[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[5]>v3[5]) //OK
                        {
                            v1[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[5]>v3[6]) //OK
                        {
                            v1[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]!=0 && v1[4]>v3[1]) //OK
                            {
                            v1[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[4]>v3[2]) //OK
                        {
                            v1[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[4]>v3[3]) //OK
                        {
                            v1[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[4]>v3[4]) //OK
                        {
                            v1[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[4]>v3[5]) //OK
                        {
                            v1[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v1[4]>v3[6]) //OK
                        {
                            v1[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]!=0 && v1[3]>v3[1]) //OK
                            {
                            v1[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[3]>v3[2]) //OK
                        {
                            v1[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[3]>v3[3]) //OK
                        {
                            v1[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[3]>v3[4]) //OK
                        {
                            v1[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[3]>v3[5]) //OK
                        {
                            v1[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[3]>v3[6]) //OK
                        {
                            v1[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]!=0 && v1[2]>v3[1]) //OK
                            {
                            v1[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v1[2]>v3[2]) //OK
                        {
                            v1[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v1[2]>v3[3]) //OK
                        {
                            v1[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v1[2]>v3[4]) //OK
                        {
                            v1[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v1[2]>v3[5]) //OK
                        {
                            v1[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==1 && v1[5]!=0 &&  v1[4]!=0  && v1[3]!=0  && v1[2]!=0 && v1[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v1[2]>v3[6]) //OK
                        {
                            v1[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==1 && v1[6]!=0 && v1[5]!=0 && v1[4]!=0 && v1[3]!=0 && v1[2]!=0 &&  v1[1]!=0 && v1[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v1[1]>v3[6])//OK
                            {
                            v1[0]=v3[6];
                            v3[6]=0;
                        }
                        //FIM



                        if(destino==2 && v2[6]==0 && v3[0]!=0) //OK
                        {
                            v2[6]=v3[0];
                            v3[0]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]!=0) //OK
                        {
                            v2[6]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0) //OK
                        {
                            v2[6]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0) //OK
                        {
                            v2[6]=v3[3];
                            v3[3]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]!=0) //OK
                        {
                            v2[6]=v3[4];
                            v3[4]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]!=0) //OK
                        {
                            v2[6]=v3[5];
                            v3[5]=0;}
                        else if (destino==2 && v2[6]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0) //OK
                        {
                            v2[6]=v3[6];
                            v3[6]=0;}


                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]!=0 && v2[6]>v3[1]) //OK
                            {
                            v2[5]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[6]>v3[2]) //OK
                        {
                            v2[5]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[6]>v3[3]) //OK
                        {
                            v2[5]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[6]>v3[4]) //OK
                        {
                            v2[5]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[6]>v3[5]) //OK
                        {
                            v2[5]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  &&  v3[6]!=0 && v2[6]>v3[6]) //OK
                        {
                            v2[5]=v3[6];
                            v3[6]=0;
                        }



                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[5]>v3[2]) //OK
                        {
                            v2[4]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[5]>v3[3]) //OK
                        {
                            v2[4]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[5]>v3[4]) //OK
                        {
                            v2[4]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[5]>v3[5]) //OK
                        {
                            v2[4]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[5]>v3[6]) //OK
                        {
                            v2[4]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]!=0 && v2[4]>v3[1]) //OK
                            {
                            v2[3]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[4]>v3[2]) //OK
                        {
                            v2[3]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[4]>v3[3]) //OK
                        {
                            v2[3]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[4]>v3[4]) //OK
                        {
                            v2[3]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[4]>v3[5]) //OK
                        {
                            v2[3]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0  && v2[4]>v3[6]) //OK
                        {
                            v2[3]=v3[6];
                            v3[6]=0;
                        }

                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]!=0 && v2[3]>v3[1]) //OK
                            {
                            v2[2]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[3]>v3[2]) //OK
                        {
                            v2[2]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[3]>v3[3]) //OK
                        {
                            v2[2]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[3]>v3[4]) //OK
                        {
                            v2[2]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[3]>v3[5]) //OK
                        {
                            v2[2]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[3]>v3[6]) //OK
                        {
                            v2[2]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]!=0 && v2[2]>v3[1]) //OK
                            {
                            v2[1]=v3[1];
                            v3[1]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]!=0 && v2[2]>v3[2]) //OK
                        {
                            v2[1]=v3[2];
                            v3[2]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]!=0 && v2[2]>v3[3]) //OK
                        {
                            v2[1]=v3[3];
                            v3[3]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]!=0 && v2[2]>v3[4]) //OK
                        {
                            v2[1]=v3[4];
                            v3[4]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]!=0  && v2[2]>v3[5]) //OK
                        {
                            v2[1]=v3[5];
                            v3[5]=0;
                        }
                        else if (destino==2 && v2[5]!=0 &&  v2[4]!=0  && v2[3]!=0  && v2[2]!=0 && v2[1]==0 && v3[0]==0 && v3[1]==0 && v3[2]==0 && v3[3]==0  && v3[4]==0 && v3[5]==0  && v3[6]!=0 && v2[2]>v3[6]) //OK
                        {
                            v2[1]=v3[6];
                            v3[6]=0;
                        }
                         else if (destino==2 && v2[6]!=0 && v2[5]!=0 && v2[4]!=0 && v2[3]!=0 && v2[2]!=0 &&  v2[1]!=0 && v2[0]==0 && v3[0]==0 && v3[1]==0 &&  v3[2]==0 && v3[3]==0 && v3[4]==0 && v3[5]==0 && v3[6]!=0 && v2[1]>v3[6])//OK
                            {
                            v2[0]=v3[6];
                            v3[6]=0;
                        }
                        } //FIM
                    system("cls");
                    play2++;
                }

                    cout << "Fim de jogo, " << nome2 <<endl<< "Houveram "<<play2<<" jogadas."<<endl;
                    cout<<"Para ver o resultado, aperte 3"<<endl;
                    cin>>jogo;
                }
                if(jogo==3){
                    system("cls");
                    if(play1<play2){
                        cout<<nome<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    else if(play2<play1){
                        cout<<nome2<<" ganhou o jogo."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    else{
                        cout<<"Deu empate."<<endl<<nome<<" = "<<play1<<endl<<nome2<<" = "<<play2<<endl;
                    }
                    cout<<"Para voltar ao menu, aperte 1"<<endl;
                    cin>>n2;
                }

            }
        }
    }
    if(n1==2){

        system("cls");
        cout<<"Obrigado por entrar no programa."<<endl<<endl;
    }
}
