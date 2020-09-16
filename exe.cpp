#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale.h>

using namespace std;

typedef struct NO{
 		string nome;
		int idade;
		int numero_pedido;
		struct NO* proximo;
}*Cliente;

typedef struct NODOIS{
 		int numero;
 		int opcao;
 		int tempo;  //	= 0;
 		int vtotal;
		struct NODOIS* proximo;
}*Pedido;

typedef struct NOTRES{
 		string nome;
 		int tempo;
 		int numero;
		struct NOTRES* proximo;
}*Espera;

 typedef struct NOQUATRO{
 		int nota_p;
 		int nota_r;
 		int nota_m;
 		int nota_b;
 		int nota_o;
}*Votos;

static Cliente head_idoso = NULL;
static Cliente tail_idoso = NULL;
static Cliente aux_idoso = NULL;

static Cliente head_geral = NULL;
static Cliente tail_geral = NULL;
static Cliente aux_geral = NULL;

static Pedido head_ped = NULL;
static Pedido tail_ped = NULL;
static Pedido aux_ped = NULL;
static Pedido prev_ped = NULL;

static Espera head_esp = NULL;
static Espera tail_esp = NULL;
static Espera aux_esp = NULL;
static Espera prev_esp = NULL;

static Votos votos = NULL;

static int aux = 1;

bool vazio_idoso(){
    return head_idoso == NULL;
}
bool vazio_geral(){
    return head_geral == NULL;
}
bool vazio_ped(){
    return head_ped == NULL;
}
bool vazio_esp(){
    return head_esp == NULL;
}
bool vazio_votos(){
    return votos == NULL;
}

void inserir_no_final(string novonome, int novaidade){
    //IDADE ATE 65 ANOS
    if(novaidade<64){
        aux_geral = new NO;
        aux_geral->nome = novonome;
        aux_geral->idade = novaidade;
        aux_geral->proximo = NULL;
        if(vazio_geral()){
            head_geral = aux_geral;
            tail_geral = aux_geral;
        }else{
            tail_geral->proximo = aux_geral;
            tail_geral = aux_geral;
        }
    }else{ //IDADE APOS 65 ANOS
        aux_idoso = new NO;
        aux_idoso->nome = novonome;
        aux_idoso->idade = novaidade;
        aux_idoso->proximo = NULL;
        if(vazio_idoso()){
            head_idoso = aux_idoso;
            tail_idoso = aux_idoso;
        }else{
            tail_idoso->proximo = aux_idoso;
            tail_idoso = aux_idoso;
        }
    }
    system("CLS");

}

void mostrar_filas(){
   if(vazio_idoso()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |       FILA IDOSO VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |          FILA IDOSO           |"<<endl;
    for(aux_idoso = head_idoso; aux_idoso != NULL; aux_idoso=aux_idoso->proximo){
        cout<<" | "<<aux_idoso->nome<<" - "<< aux_idoso->idade <<" Anos\t\t|"<<endl;
        cout<<" |                               |"<<endl;
    }
    	cout<<" |_______________________________|"<<endl;
    }
    cout<<endl;
    cout<<endl;

  if(vazio_geral()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |       FILA GERAL VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |          FILA GERAL           |"<<endl;
    for(aux_geral = head_geral;aux_geral != NULL; aux_geral=aux_geral->proximo){
        cout<<" | "<<aux_geral->nome<<" - "<< aux_geral->idade <<" Anos\t\t\t |"<<endl;
        cout<<" |                               |"<<endl;
    }
        cout<<" |_______________________________|"<<endl;
    }
    cout<<endl;
    cout<<endl;

   if(vazio_esp()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |      FILA ESPERA VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
            cout<<"  _______________________________"<<endl;
            cout<<" |                               |"<<endl;
            cout<<" |         FILA ESPERA           |"<<endl;
        for(aux_esp = head_esp; aux_esp!= NULL; aux_esp=aux_esp->proximo){
            cout<<" | NOME: "<<aux_esp->nome<<"\t|"<<endl;
            cout<<" | NUMERO: "<<aux_esp->numero<<"\t\t|"<<endl;
            cout<<" | TEMPO: "<<aux_esp->tempo<<" Mins\t\t|"<<endl;
            cout<<" |_______________________________|"<<endl;
            cout<<" |                               |"<<endl;
        }
        	cout<<" |_______________________________|"<<endl;
    }
    cout << endl;
    cout << endl;

    system("pause");
    system("CLS");

}

void mostrar_pedidos(){
     if(vazio_ped()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |     FILA PEDIDOS VAZIA!!!     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    } else {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |        FILA PEDIDOS           |"<<endl;
    for(aux_ped = head_ped; aux_ped != NULL; aux_ped=aux_ped->proximo){
        cout<<" | NUMERO: "<<aux_ped->numero<<endl;
        cout<<" | OPÇÃO: "<<aux_ped->opcao<<endl;
        cout<<" | VALOR TOTAL: "<<aux_ped->vtotal<<endl;
        cout<<" | TEMPO: "<<aux_ped->tempo<<" Mins"<<endl;
        cout<<" |_______________________________|"<<endl;
    }}
    cout << endl;
    system("pause");
    system("CLS");

}

void mostrar_votos(){
    cout << endl;
    if(vazio_votos()) {
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |     NENHUM VOTO COMPUTADO     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    }else{
    cout<<"  _______________________________"<<endl;
    cout<<" |                               |"<<endl;
    cout<<" |       VOTOS  COMPUTADOS       |"<<endl;
    cout<<" |     OTIMO............"<<votos->nota_o<<" VOTOS  |"<<endl;
    cout<<" |     BOM.............."<<votos->nota_b<<" VOTOS  |"<<endl;
    cout<<" |     MEDIANO.........."<<votos->nota_m<<" VOTOS  |"<<endl;
    cout<<" |     RUIM............."<<votos->nota_r<<" VOTOS  |"<<endl;
    cout<<" |     PESSIMO.........."<<votos->nota_p<<" VOTOS  |"<<endl;
    cout<<" |_______________________________|"<<endl;
    }
    cout<<endl;
    system("pause");
    system("CLS");
}

void encontrar(string nome){
    cout << endl;
    int i=1, j=1;
    aux_idoso = head_idoso;
    if(aux_idoso!=NULL){
        while (aux_idoso->proximo != NULL && aux_idoso->nome != nome){
            aux_idoso = aux_idoso->proximo;
            i++;
            }
        if(aux_idoso->nome == nome){
            cout<<"  ________________________________________"<<endl;
            cout<<" |                                        |"<<endl;
            cout<<" |ENCONTRADO NA FILA IDOSO NA POSIÇÃO: "<<i<<"  |"<<endl;
            cout<<" |________________________________________|"<<endl;
        }
    }
    aux_geral = head_geral;
    if(aux_geral!=NULL){
        while (aux_geral->proximo != NULL && aux_geral->nome != nome){
            aux_geral = aux_geral->proximo;
            j++;
        }
        if(aux_geral->nome == nome){
            cout<<"  ________________________________________"<<endl;
            cout<<" |                                        |"<<endl;
            cout<<" |ENCONTRADO NA FILA GERAL NA POSIÇÃO: "<<j<<"  |"<<endl;
            cout<<" |________________________________________|"<<endl;
        }else{
            cout<<"  _____________________________________"<<endl;
            cout<<" |                                    |"<<endl;
            cout<<" |         NOME NAO ENCONTRADO        |"<<endl;
            cout<<" |____________________________________|"<<endl;
        }
    }

        if(aux_geral==NULL && aux_idoso==NULL){
            cout<<"  _____________________________________"<<endl;
            cout<<" |                                    |"<<endl;
            cout<<" |        NOME NAO ENCONTRADO         |"<<endl;
            cout<<" |____________________________________|"<<endl;
        }

    system("pause");
    system("CLS");

}

void pedido(int x){
    int numero,opcao,vtotal,tempo;
    numero = aux;
    aux = aux +1;
    cout<<"  _____________________________________"<<endl;
    cout<<" |                                    |"<<endl;
    cout<<" |      ***FAZENDO PEDIDO***          |"<<endl;
    if(x==1){
        cout<<" |            FILA IDOSO              |"<<endl;
        cout<<" |   CLIENTE: "<<head_idoso->nome<<endl;
        cout<<" |   PEDIDO NUMERO: "<< numero<<endl;
     }else{
        cout<<" |            FILA GERAL              |"<<endl;
        cout<<" |   CLIENTE: "<<head_geral->nome<<endl;
        cout<<" |   PEDIDO NUMERO: "<< numero<<endl;
         }
        cout<<" |____________________________________|"<<endl;
        cout<<" |                                    |"<<endl;
        cout<<" | OPÇÕES:                            |"<<endl;
        cout<<" |  1-HAMBURGUER..................$20 |"<<endl;
        cout<<" |  2-SUCO........................$5  |"<<endl;
        cout<<" |  3-SPBREMESA...................$8  |"<<endl;
        cout<<" | COMBOS:                            |"<<endl;
        cout<<" |  4-HAMBURGUER+SUCO.............$24 |"<<endl;
        cout<<" |  5-HAMBURGUER+SOBREMESA........$26 |"<<endl;
        cout<<" |  6-HAMBURGUER+SUCO+SOBREMESA...$30 |"<<endl;
        cout<<" |  7-SUCO+SOBREMESA..............$12 |"<<endl;
        cout<<" |____________________________________|"<<endl;
        cout<<" |_OPÇÂO: ";
        cin>>opcao;
        switch(opcao){
                case 1:{
                    vtotal=20;
                    tempo=6;
                break;
                }
                case 2:{
                    vtotal=5;
                    tempo=3;
                break;
                }
                case 3:{
                    vtotal=8;
                    tempo=3;
                break;
                }
                case 4:{
                    vtotal=24;
                    tempo=7;
                break;
                }
                case 5:{
                    vtotal=26;
                    tempo=7;
                break;
                }
                case 6:{
                    vtotal=30;
                    tempo=8;
                break;
                }
                case 7:{
                    vtotal=12;
                    tempo=7;
                break;
                }
        }
        aux_esp = new NOTRES;
        aux_esp->numero = numero;
        aux_esp->tempo = tempo;
        if(x==1){
            aux_esp->nome = head_idoso->nome;
            head_idoso->numero_pedido = numero;
           //remover(head_idoso->nome, 1);
        }else{
            aux_esp->nome = head_geral->nome;
            head_geral->numero_pedido = numero;
            //remover(head_geral->nome, 2);
        }
       if(vazio_esp()){
            head_esp = aux_esp;
            tail_esp = aux_esp;
        }else{
            tail_esp->proximo = aux_esp;
            tail_esp = aux_esp;
        }
        aux_ped = new NODOIS;
        aux_ped->tempo = tempo;
        aux_ped->numero = numero;
        aux_ped->opcao = opcao;
        aux_ped->vtotal = vtotal;
        aux_ped->proximo = NULL;
        if(vazio_ped()){
            head_ped = aux_ped;
            tail_ped = aux_ped;
        }else{
            tail_ped->proximo = aux_ped;
            tail_ped = aux_ped;
        }
}

void votar(){
    int opc,voto;
    cout<<"  _____________________________________________________________"<<endl;
    cout<<" |                                                             |"<<endl;
    cout<<" |CLIENTE GOSTARIA DE PARTICIPAR DE UMA PESQUISA DE SATISFAÇÂO?|"<<endl;
    cout<<" |                        1-SIM 2-NÃO                          |"<<endl;
    cout<<" |_____________________________________________________________|"<<endl;
    cout<<" |_OPÇÂO: ";
    cin>>opc;
    cout<<endl;
    if(opc==1){
        if(vazio_votos()){
        votos = new NOQUATRO;
        votos->nota_o =0;
        votos->nota_b =0;
        votos->nota_m =0;
        votos->nota_r =0;
        votos->nota_p =0;
        }
    cout<<"  _____________________________________________________________"<<endl;
    cout<<" |                                                             |"<<endl;
    cout<<" |    INDIQUE QUAL SEU NIVEL DE SATISFAÇÃO COM O ATENDIMENTO   |"<<endl;
    cout<<" |            1-PESSIMO 2-RUIM 3-MEDIANO 4-BOM 5-OTIMO         |"<<endl;
    cout<<" |_____________________________________________________________|"<<endl;
    cout<<" |_OPÇÂO: ";
    cin>>voto;
    switch(voto){
        case 1:{
            votos->nota_p=votos->nota_p+1;
            break;
            }
        case 2:{
            votos->nota_r=votos->nota_r+1;
            break;
            }
        case 3:{
            votos->nota_m=votos->nota_m+1;
            break;
            }
        case 4:{
            votos->nota_b=votos->nota_b+1;
            break;
            }
        case 5:{
            votos->nota_o=votos->nota_o+1;
            break;
            }
        }
    }
    system("pause");
    system("CLS");
}

void chamar(int numero_chamado){
     cout << endl;
     int select =0;
    if(vazio_ped()){
        cout<<"  _______________________________"<<endl;
        cout<<" |                               |"<<endl;
        cout<<" |   NENHUM PEDIDO COMPUTADO     |"<< endl;
        cout<<" |_______________________________|"<<endl;
        cout << endl;
    }else{

        aux_ped = head_ped;
         if(aux_ped!=NULL){
            while (aux_ped->proximo != NULL && aux_ped->numero != numero_chamado){
                prev_ped = aux_ped;
                aux_ped = aux_ped->proximo;
                select = select + 1;
            }
        }
         aux_esp = head_esp;
         if(aux_esp!=NULL){
            while (aux_esp->proximo != NULL && aux_esp->numero != numero_chamado){
                prev_esp = aux_esp;
                aux_esp = aux_esp->proximo;
                select = select +1;
            }
         }
            if(aux_ped->numero == numero_chamado){
                cout<<"  _______________________________"<<endl;
                cout<<" |                               |"<<endl;
                cout<<" |   PEDIDO NUMERO: "<<numero_chamado<<endl;
                cout<<" | NOME: "<<aux_esp->nome<<endl;
                cout<<" | OPÇÃO: "<<aux_ped->opcao<<endl;
                cout<<" | VALOR TOTAL: "<<aux_ped->vtotal<<endl;
                cout<<" | TEMPO: "<<aux_ped->tempo<<" Mins"<<endl;
                cout<<" |_______________________________|"<<endl;
            }
//DELETAR DAS FILAS PEDIDOS E ESPERA

              if(select != 0){
                  prev_ped->proximo=aux_ped->proximo;
                  aux_ped->proximo = NULL;
                  prev_esp->proximo=aux_esp->proximo;
                  aux_esp->proximo = NULL;
                  }else{
                   aux_esp = head_esp;
                   head_esp = head_esp->proximo;
                   aux_esp->proximo = NULL;
                   aux_ped = head_ped;
                   head_ped = head_ped->proximo;
                   aux_ped->proximo = NULL;
                  }
              delete aux_ped;
              delete aux_esp;
              select =0 ;
    }
    system("pause");
    system("CLS");
}

void remover(int x){

        if(x ==1){
          aux_idoso = head_idoso;
          head_idoso = head_idoso->proximo;
          aux_idoso->proximo = NULL;
          delete aux_idoso;
        }else{
          aux_geral = head_geral;
          head_geral = head_geral->proximo;
          aux_geral->proximo = NULL;
          delete aux_geral;
        }

}

void limpar_memorias(){

    votos=NULL;
    prev_esp=NULL;
    prev_ped=NULL;

    // cout << "1" << endl;
// --------MMMMMMMM----------------------
    while (head_geral != NULL){
        aux_geral= head_geral;
        head_geral = aux_geral->proximo;
        aux_geral->proximo = NULL;
        delete aux_geral;
    }
    head_geral=NULL;
    tail_geral=NULL;


//  cout << "2" << endl;



    while (head_idoso != NULL) {
        aux_idoso= head_idoso;
        head_idoso = aux_idoso->proximo;
        aux_idoso->proximo = NULL;
        delete aux_idoso;
    }
    tail_idoso=NULL;


// cout << "3" << endl;

    while (head_ped != NULL) {
        aux_ped= head_ped;
        head_ped = aux_ped->proximo;
        aux_ped->proximo = NULL;
        delete aux_ped;
    }
    tail_ped = NULL;

//  cout << "4" << endl;
    while (head_esp != NULL) {
        aux_esp = head_esp;
        head_esp = aux_esp->proximo;
        aux_esp->proximo = NULL;
        delete aux_esp;
    }
    tail_esp = NULL;

//  cout << "5" << endl;
// -------MMMMMMMM-----------------------

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int seletor=-1,idade,numero;
    string nome;

    do{
    cout<<endl;
    cout<<"\tAmo Muito Tudo isso :"<<endl;
    cout<<" ____________________________"<<endl;
    cout<<" |                          |"<<endl;
    cout<<" | 1-\tNOVO CLIENTE\t\t|"<<endl;
    cout<<" | 2-\tBUSCAR NA FILA\t\t|"<<endl;
    cout<<" | 3-\tFAZER PEDIDO\t\t|"<<endl;
    cout<<" | 4-\tCHAMAR PEDIDO\t\t|"<<endl;
    cout<<" | 5-\tMOSTRAR PEDIDOS\t\t|"<<endl;
    cout<<" | 6-\tMOSTRAR VOTOS\t\t|"<<endl;
    cout<<" | 7-\tMOSTRAR FILAS\t\t|"<<endl;
    cout<<" | 0-\tSAIR DO PROGRAMA\t|"<<endl;
    cout<<" |__________________________|"<<endl;
    cout<<" |\tOPÇÂO:\t";
    cin>>seletor;
    system("CLS");
    cout<<endl;
    switch(seletor){
            case 1:{
                cout<<" ____________________________"<<endl;
                cout<<" |                          |"<<endl;
                cout<<" |      *NOVO  CLIENTE*     |"<<endl;
                cout<<" |    NOME: ";
                cin>>nome;
                cout<<" |    IDADE: ";
                cin>>idade;
                cout<<" |__________________________|"<<endl;
                inserir_no_final(nome,idade);
                break;
                }

            case 2:{
                cout<<" ____________________________"<<endl;
                cout<<" |                          |"<<endl;
                cout<<" |    *PESQUISA POR NOME*   |"<<endl;
                cout<<" |  NOME: ";
                cin>>nome;
                cout<<" |__________________________|"<<endl;
                encontrar(nome);
                break;
            }

            case 3:{
                if(vazio_idoso() && vazio_geral()){
                    cout<<" ____________________________"<<endl;
                    cout<<" |                          |"<<endl;
                    cout<<" |       FILAS VAZIAS       |"<<endl;
                    cout<<" |__________________________|"<<endl;
                    cout<<endl;
                    system("pause");
                    system("CLS");

                }else if( head_idoso!= NULL){
                    pedido(1);
                    votar();
                    remover(1);
                }else{
                    pedido(2);
                    votar();
                    remover(2);
                }
                break;
            }
            case 4:{
                cout<<" ____________________________"<<endl;
                cout<<" |                          |"<<endl;
                cout<<" |    *CHAMAR POR NUMERO*   |"<<endl;
                cout<<" | NUMERO: ";
                cin>>numero;
                cout<<" |__________________________|"<<endl;
                chamar(numero);
                break;
                }

            case 5:{
                mostrar_pedidos();
                break;
                }


            case 6:{
                mostrar_votos();
                break;
                }
            case 7:{
                mostrar_filas();
                break;
                }
    }

    }while(seletor!=0);
    system("CLS");
    cout<<"Amo Muito Tudo isso !!!!"<<endl;
    system("pause");
    limpar_memorias();
	return 0;
}