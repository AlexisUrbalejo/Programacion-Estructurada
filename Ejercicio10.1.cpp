#include<stdio.h>

 int main()
{
    float horas_sem,sal_hora,sal_norm,sal_ext,sal_tot;
    printf("Ingresa cuantas horas trabajaste en la semana ");
    scanf("%f",&horas_sem);
    printf("Ingresa cual es tu salario por hora ");
    scanf("%f",&sal_hora);
    if(horas_sem > 40)
    {
        if(horas_sem > 49)
        {
            sal_norm =  (sal_hora * 40);
            sal_ext = ((sal_hora*2)*9)+((sal_hora*3)*(horas_sem-49));
        }
        else
        {
            sal_norm =  (sal_hora * 40);
            sal_ext = ((sal_hora*2)*(horas_sem-40));
        }
    }
    else
    {
        sal_norm =  (sal_hora * horas_sem);
        sal_ext = 0;
    }
    sal_tot = sal_norm + sal_ext;
    printf("Salario por hora: %.2f $ \n",sal_hora);
    printf("Horas trabajadas: %.2f hrs \n",horas_sem);
    printf("Salario normal: %.2f $ \n",sal_norm);
    printf("Salario extra: %.2f $ \n",sal_ext);
    printf("Salario Total: %.2f $ \n",sal_tot);
    return 0;
}