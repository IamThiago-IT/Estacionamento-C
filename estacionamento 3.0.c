#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int main(){
	system("color 2");
struct tm *data_hora_atual;     
  time_t segundos; 
  time(&segundos);
char c,cadastro_login[50],cadastro_senha[50],acesso_login[50],acesso_senha[50];
       int a=0,b=1,d=3;// d controlará a quantidade de erros ao logar no sistema
	   	printf("=========================\n");
	    printf("Bem vindo usuario\n");
	   	printf("=========================\n");
	   printf("\n\t\t\tCADASTRO\n\nDigite o login: ");
       fflush(stdin);                     //Limpando o buffer do teclado
       gets(cadastro_login);              
       printf("\nDigite a senha: ");
       do{
           c=getch();
           if(isprint(c)){       //Analisa se o valor da variável c é imprimivel
           cadastro_senha[a]=c;  //Se for, armazena o caractere 
           a++;
           printf("*");          //imprime o * Anterisco
           }
           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           cadastro_senha[a]='\0';
           a--;
           printf("\b \b");       //Apagando o caractere digitado
           } 
       }while(c!=13);             //13 é o valor de ENTER na tabela ASCII
       cadastro_senha[a]='\0';
       system("cls");  
       printf("\n\nCadastro efetuado com sucesso...\n\n");
system("pause");  

	   
int opcao, i, escolha;
int usuariosTotal, vaga[21];
int momentoEntrada[21], momentoSaida[21], momentoUso[21];
int cont = 0;
char placaCarro[usuariosTotal][8];
int horasEntrada[usuariosTotal], horasSaida[usuariosTotal], minutosEntrada[usuariosTotal], minutosSaida[usuariosTotal];
float preco[usuariosTotal];
   

 
for (i = 1; i <= 20;i++){

vaga[i] = 0;

momentoEntrada[i] = 0;
momentoSaida[i] = 0;

momentoUso[i] = 0;

}

usuariosTotal = 0;

do{
	printf (" _________________________________________________________\n");
	printf ("| Estacionamento                                          |\n");
	printf ("| Valores                                                 |\n");
	printf ("| Para uma hora sera cobrado: R$ 9,00                     |\n");
	printf ("| Para cada 30 min. sera cobrado: R$ 5,10                 |\n");
	printf ("| Para cada 01 min. sera cobrado: R$ 0,17                 |\n");
	printf ("|_________________________________________________________|\n");
	printf ("| Menu                                                    |\n");
	printf ("| Selecione a opcao desejada: |                           |\n");
	printf ("| Para estacionar pressione        [1]                    |\n");
	printf ("| Para sair pressione              [2]                    |\n");
	printf ("| Para gerar relatorio pressione   [3]                    |\n");
	printf ("| para gerar o recibo pressione    [4]                    |\n");
	printf ("| Excel                            [5]                    |\n");
	printf ("| contato                          [6]                    |\n");
	printf ("| Final                            [7]                    |\n");
	printf ("| Dono da empresa                  [8]                    |\n");
	printf ("| Para Encerrar programa pressione [0]                    |\n");
	printf ("|_________________________________________________________|\n");


	printf("\t\t Opcao desejada: ");
	scanf("%i",&opcao);

switch(opcao){

case 1:

	printf("|--------------------------XXXXX--------------------------| \n");
	printf("total de vagas 20\n");
	printf("\n\nESCOLHA NUMERO DA VAGA: ");
	scanf("%i",&escolha);
	
	if(escolha<=21){
	if(vaga[escolha] == 0){

// MOMENTO QUE O USUARIO COMPRA O SERVIÇO

	printf("|---------------------VAGA DISPONIVEL---------------------|\n\n");
	
	usuariosTotal=usuariosTotal+1;
	
	printf("PLACA DO CARRO: ");
	scanf("%s", &placaCarro[usuariosTotal]);
	
	printf("|--------------------HORARIO DE ENTRADA-------------------|\n");
	
	printf("HORA [XX]: ");
	scanf("%i", &horasEntrada[usuariosTotal]);
	
	printf("MINUTOS [XX]: ");
	scanf("%i", &minutosEntrada[usuariosTotal]);
	
	
	while(horasEntrada[usuariosTotal] >= 24 || minutosEntrada[usuariosTotal] >= 60){
	
	printf("\n Hora e(ou) minuto invalidos, lembre-se: Horas vao de 0 a 23 e minutos de 0 a 59\n\n");
	
	printf("HORA [XX]:");
	scanf("%i", &horasEntrada[usuariosTotal]);
	
	printf("MINUTOS [XX]:");
	scanf("%i", &minutosEntrada[usuariosTotal]);

}

	vaga[escolha] = 1;
	
	momentoEntrada[escolha] = (horasEntrada[usuariosTotal] * 60) + minutosEntrada[usuariosTotal];

}else{

	printf("\n\nVaga Ocupada, por favor escolha outra vaga \n \n");

}

}else{

	printf("\n\nvaga Nao existente\n\n");


}


	system("pause");
	system("cls");

break;

case 2:
// SAIDA

	printf("\nESCOLHA O NUMERO DA VAGA: ");
	scanf("%i",&escolha);

	if(escolha>0 && escolha<=21 ){
	if(vaga[escolha] != 0){

	printf("|---------------------HORARIO DE SAIDA-------------------|\n");
	printf("HORA [XX]: ");
	scanf("%i",&horasSaida[usuariosTotal]);

	printf("MINUTOS [XX]: ");
	scanf("%i",&minutosSaida[usuariosTotal]);

while(horasSaida[usuariosTotal] >= 24 || minutosSaida[usuariosTotal] >= 60){

	printf("\n Hora e(ou) minuto invalidos, lembre-se: Horas vao de 0 a 23 e minutos de 0 a 59\n\n");
	
	printf("HORA [XX]: ");
	scanf("%i",&horasSaida[usuariosTotal]);
	
	printf("MINUTOS [XX]: ");
	scanf("%i",&minutosSaida[usuariosTotal]);
	
	}
	
	momentoSaida[escolha] = (horasSaida[usuariosTotal] * 60) + minutosSaida[usuariosTotal];

while (momentoEntrada[escolha] > momentoSaida[escolha]){

	printf("Hora de entrada maior que hora de saida, tente novamente!\n");
	
	printf("HORA [XX]:");
	scanf("%i",&horasSaida[usuariosTotal]);
	
	printf("MINUTOS [XX]:");
	scanf("%i",&minutosSaida[usuariosTotal]);

}

	vaga[escolha] = 0;
	
	momentoUso[escolha] = momentoSaida[escolha] - momentoEntrada[escolha];
	
	preco[usuariosTotal] = momentoUso[escolha]*0.17; 
	// CALCULO DE VALOR DO ESTACIONAMENTO
	
	printf("|--------------------------XXXXX--------------------------|\n ");
	printf(" O VALOR A SER PAGO E: %.2f\n",preco[usuariosTotal]); 
	// IMPRESSÃO DO PRECO
	printf("|--------------------------XXXXX--------------------------| \n");

}else{

	printf("\n\nVaga Vazia!\n\n");

}

} else{

	printf("\n\nvaga Nao existente\n\n");

}
	system("pause");
	system("cls");
	break;

case 3:

	// RELATORIO
	printf("|--------------------RELATORIO DIARIO---------------------|\n");
	printf("| Placa | Entrada | Saida | Preco |\n");
for (i = 1; i <= usuariosTotal;i++){

	printf("| %s | %02i:%02i | %02i:%02i | %2.f |\n",placaCarro[i],horasEntrada[i],minutosEntrada[i], horasSaida[i], minutosSaida[i], preco[i]);

}

	printf("|--------------------------XXXXX--------------------------|\n ");
	printf(" TOTAL DE CARROS => %i \n\n",usuariosTotal);
	
	system("pause");
	system("cls");
	
	break;
	default:
case 4:
	// Recibo
       printf("\n\t\t\tCADASTRO\n\nDigite o login: ");
       fflush(stdin);                     //Limpando o buffer do teclado
       gets(cadastro_login);              
       printf("\nDigite a senha: ");
       do{
		   c=getch();
           if(isprint(c)){       //Analisa se o valor da variável c é imprimivel
           cadastro_senha[a]=c;  //Se for, armazena o caractere 
           a++;
           printf("*");          //imprime o * Anterisco
           }
           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           cadastro_senha[a]='\0';
           a--;
           printf("\b \b");       //Apagando o caractere digitado
           } 
       }while(c!=13);             //13 é o valor de ENTER na tabela ASCII
       cadastro_senha[a]='\0';
       system("cls");  
       printf("\n\nCadastro efetuado com sucesso...\n\n");
       
printf("|--------------------RECIBO DO USO DA VAGA---------------------|\n");
printf("| Placa | Entrada | Saida | Preco |\n");
printf("|--------------------------------------------------------------|\n");

for (i = 1; i <= usuariosTotal;i++){

printf("| %s | %02i:%02i | %02i:%02i | %2.f |\n",placaCarro[i],horasEntrada[i],minutosEntrada[i], horasSaida[i], minutosSaida[i], preco[i]);

} 
  data_hora_atual = localtime(&segundos);  
 
	  printf("\nDia..........: %d\n", data_hora_atual->tm_mday);  
	  printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
	  printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
	  
	  printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);  
	  printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);
	    
	
	  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
	  printf("%d:",data_hora_atual->tm_min);//minuto
	  printf("%d\n",data_hora_atual->tm_sec);//segundo 
   	printf("|\nOBRIGADO E TENHA UM BOM DIA\n");
	printf("|--------------------------\\\\\\\--------------------------|\n ");
	printf(" cliente => %i \n\n",usuariosTotal);

	system("pause");
	system("cls");

	break;
case 5:
	system ("");
	
break;
case 6:
	printf("=========================\n");
	printf("Thiago  9-97848601\n");
	printf("Mateus  9-88136910\n");
	printf("Gabriel panheow@gmail.com ");
	printf("=========================\n");
	system("pause");
	break;
case 7:
	printf("=========================\n");
	printf("OBRIGADO PELA ATENCAO\n");
	printf("=========================\n");
	system("pause");
	break;
case 8:
	printf("=========================\n");
	printf("dono do estacionamento:\n");
	printf("Fred\n");
	printf("=========================\n");
	system("pause");
case 0:
	
	if(opcao == 0 ){
	
	printf("Programa encerrado com sucesso.\n");
	break;

}else{

	printf("CODIGO INEXISTENTE\n");

}
}
}
while(opcao!=0);
// COM CARROS LIDOS E NOTAS FISCAIS GERADAS PODEMOS PUXAR A RELAÇÃO COM TODOS OS DADOS DO ESTACIONAMENTO
// printf (" PLACA %c HORARIO ENTRADA %i:%i HORARIO SAIDA %i:%i PERMANENCIA %i (em minutos) PRECO %f\n",placaCarro[contador],horasEntrada[contador],minutosEntrada[contador],horasSaida[contador],minutosSaida[contador],momentoUso[contador],preco[contador]);


return 0;
}
