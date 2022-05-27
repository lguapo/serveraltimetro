#include <stdio.h>
#include <stdlib.h>

float *pcpr,*pcpi;
float *mcpr, *mcpi;

typedef struct complexo{
float real;
float imaginario;
float esc_real;
float esc_imag;
}tComplexo;

struct complexo cpx;
//soma ok
float SomaComplexos(float a, float b, float c,float d){

cpx.real = a + c;
cpx.imaginario = b + d;

return (a);
}

void MultiplicaPorEscalar(float escalar){

cpx.esc_real = escalar*cpx.real;
cpx.esc_imag = escalar*cpx.imaginario;

}

int main(){
float r1=1.0, im1=1.0, r2=2.0, im2=2.0;
float mux= 2.0;

pcpr = &cpx.real;
pcpi = &cpx.imaginario;
mcpr = &cpx.esc_real;
mcpi = &cpx.esc_imag;

SomaComplexos(r1,im1,r2,im2);
MultiplicaPorEscalar(mux);

printf("resultado soma = %f + j%f\n", *pcpr, *pcpi);
printf("resultado Multi. por Escalar = %f + j%f\n",*mcpr,*mcpi);

system("pause");
return 0;
}