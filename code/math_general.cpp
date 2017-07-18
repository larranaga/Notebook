 long square(long n){ return n*n;}

 int fastPow(long x, long n){
     if(n == 0)
        return 1;

     if(n % 2 == 0)
        return square(fastPow(x, n/2));

     return x * (fastPow(x, n - 1));
 }

/* LCM */
int LCM(int m, n){return (m*n)/__gcd(m, n); }


int main(){

    /* n es impar?*/
    odd = ((n & 1)? true : false);

    /*como saber si un numero es una potencia de 2*/
    power_of_2 = ((v & (v-1)) == 0);

    /*contar trailing 0's de una mascara */
    __builtin_ctz(n);

    /*contar 1's de una mascara*/
    __builtin_popcount(n);

    /*quitar el elemento j de la máscara*/

    mask &= ~(1<<j);

    /*revisar si el elemento j del arreglo esta en la máscara ( si es 0 el resultado es porque no está)*/
    int t = mask & (1<<j);

    /*Obtener el bit menos significativo*/
     t = mask & -mask

    /*encender todos los n primeros bits de la máscara*/

    mask = (1<<n) - 1;

    /*iterar sobre cada uno de los subsets de un subset y*/
    for(int x = y; x>0; x = (y & (x-1)) )
}





