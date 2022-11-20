#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

void Cabecalho ();
float HoraExtra (float heno, float hedi);
int FaltaHoras(int diasFalt);
float SalFamilia();

int main(){
    
    Cabecalho ();
    
    //declaração de variaveis
    int diasFalt;
    float sal, hen = 0, hed = 0, ref = 0, valeMes = 0, descEventuais = 0, descontoTotal;
    double SalLiquido;
    float calcHoraExtra, calcHoraFaltas, SomaHora = 0, calcSalFamilia, calcSalBruto = 0, calcImpostoRenda = 0; 
    char nome[100];
    
    //inicio de dados do funcionário
    printf("Digite o nome do funcionário: \n");
    scanf("%s",&nome[100]);

    printf("Digite o salário do funcionário: \n");
    scanf("%f", &sal);
    
    printf("Digite quantas horas extras diurnas e noturnas trabalhadas: \n");
    scanf("%f%f", &hed, &hen);
    
    SomaHora = hed + hen;
    
    if(SomaHora > 104){

        do
        {
            printf("ERROR! Digite novamente a quantidade de horas extras diurnas e noturnas trabalhadas: \n");
            scanf("%f%f", &hen, &hed);

            SomaHora = hen + hed;

        } while(SomaHora >= 104);

    }
    
    printf("Se houver, digite o valor dos gastos com refeiçoes feitos na empresa:\n");
    scanf("%f", &ref);
    
    printf("Se houver, digite o valor dos vales retirados durante o mes:\n");
    scanf("%f", &valeMes);
    
    printf("Se houver, digite o valor de outros descontos eventuais:\n");
    scanf("%f", &descEventuais);
    
    printf("Digite quantos dias funcionario faltou:\n");
    scanf("%d", &diasFalt);
    
    
    
    //Calculo Salario Familia
    calcSalFamilia = SalFamilia();
    printf("O salario familia: %2.f R$\n", calcSalFamilia);
    
     //Calculo de Hora Extra do funcionario
    calcHoraExtra =  HoraExtra(hed * sal/160, hen * 1.2 * sal/160);
    printf("As horas extras recebida pelo funcionario foi de: %2.f R$\n", calcHoraExtra);
    
    //Calculo de horas de falta do funcionario
    calcHoraFaltas = FaltaHoras(diasFalt * sal/160);
    printf("O desconto no salario por horas faltosas: %2.f R$\n", calcHoraFaltas);
    
    //Calculo do Salario calcSalBruto
    calcSalBruto = sal + calcHoraExtra + calcSalFamilia;
    printf("O salario Bruto do funcionario: %2.f R$\n", calcSalBruto);
    
    //Calculo Imposto de calcImpostoRenda
    calcImpostoRenda = 0.08 * calcSalBruto;
    printf("O imposto de renda do funcionario: %2.f R$\n", calcImpostoRenda);
    
    //Calculo do desconto Total
    descontoTotal = ref + valeMes + descEventuais;
    printf("Descontos do funcionario na empresa durante o mes: %2.f R$\n", descontoTotal);
    
    //Calculo do Salario Liquido
    SalLiquido = calcSalBruto - descontoTotal;
    printf("O salario liquido do funcionario: %2.f R$\n", SalLiquido);
    
    return 0; 
}

void Cabecalho ()
{
  printf ("Felipe Antonio, Luis Fernando e Pedro Gabriel.\n");
  printf ("====== EMISSÃO DA FOLHA DE PAGAMENTO - IFG ======\n");

}


//Calculo da soma de HoraExtra diurnas e HoraExtra noturnas;
float HoraExtra(float heno, float hedi){

    //Declaração de variaveis;
    float SomaHora;

    SomaHora = hedi + heno;

    return SomaHora;
}

//Desconto de faltas do funcionario
int FaltaHoras(int diasFalt){
    int FaltatHor = 0;
    
    FaltatHor = diasFalt;
}

//Calculo Salario Familia
float SalFamilia(){
    float calculo, salMinimoVigente;
    int numDep;
    printf("Digite o salario Minimo vigente:\n");
    scanf("%f", &salMinimoVigente);
    
    printf("Digite o numero de dependentes:\n");
    scanf("%d", &numDep);
    
    calculo = numDep * 0.05 * salMinimoVigente;
    
    return (calculo);
}
