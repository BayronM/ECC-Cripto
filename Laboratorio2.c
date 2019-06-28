#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>



void doblado(mpz_t *p,mpz_t *result){
  mpz_t aux1,aux2,a,alpha,beta;
  mpz_init(aux1);
  mpz_init(aux2);
  mpz_init(a);
  mpz_init(alpha);
  mpz_init(beta);
/////////////alpha///////////////////////////
  mpz_pow_ui(aux1,p[0],2);
  mpz_mul_ui(aux1,aux1,3);
  mpz_pow_ui(aux2,p[2],4);
  mpz_mul(aux2,a,aux2);
  mpz_add(alpha,aux1,aux2);
///////////////betha///////////////////
  mpz_mul_ui(aux1,p[0],4);
  mpz_pow_ui(aux2,p[1],2);
  mpz_mul(beta,aux1,aux2);
  //////////////Z_3//////////////////
  mpz_mul_ui(aux1,p[1],2);
  mpz_mul(result[2],aux1,p[2]);
  ////////////X_3///////////////////
  mpz_pow_ui(aux1,alpha,2);
  mpz_mul_ui(aux2,beta,2);
  mpz_sub(result[0],aux1,aux2);
  //////////Y_3////////////////////
  mpz_sub(aux1,beta,result[0]);
  mpz_mul(aux1,aux1,alpha);
  mpz_pow_ui(aux2,p[1],4);
  mpz_mul_ui(aux2,aux2,8);
  mpz_sub(result[1],aux1,aux1);
  ////////////////////////////////
}


int main(int argc, char const *argv[]) {

  mpz_t *p1,*p2,*result;

  p1=malloc(3*sizeof(mpz_t));
  p2=malloc(3*sizeof(mpz_t));
  result=malloc(3*sizeof(mpz_t));
  for(int i=0;i<=2;i++){
    mpz_init(p1[i]);
    mpz_init(p2[i]);
    mpz_init(result[i]);
  }
  mpz_set_ui(p1[0],15);
  mpz_set_ui(p1[1],15);
  mpz_set_ui(p1[2],15);

  doblado(p1,result);
  gmp_printf("%Zd\n",result[0]);


  free(result);
  free(p1);
  free(p2);
  return 0;
}
