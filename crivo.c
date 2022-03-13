#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void teste(int n);
void crivo(int n);
void crivo2(int n);
void crivo3(int n);
void crivo4(int n);
void crivo5(int n);
void crivo6(int n);
void crivo_6(int n);
void crivo7(int n);
int main(void){

//crivo(15485863);


//printf("OK");

//printf("%d", h);
//crivo3(1000000);
crivo7(1000000000);
//crivo_6(1000000000);
return 0;
}

void teste(int n){
int i;
int k = 3;
int prime = 979;
int *eh_primo = malloc(n * sizeof(int));

    for(i = 1; i<=n; i+=k){
      eh_primo[i] = prime;
    }

}
void crivo(int n){
    int *eh_primo = malloc(n * sizeof(int));
    int j;
    int i;

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for(i=1; i<=n; i++){
        eh_primo[i] = 1;
    }

    // Para cada número de 2 até n
    for(i = 2; i <= n; i++){

        // checo se o número atual é indefinido.
        if(eh_primo[i] == 1){

            // e que os múltiplos dele são compostos.
            for(j = i; j <= n; j += i){
                eh_primo[j] = 0;
            }
        }
    }
 for(i = n; eh_primo[i] != 1; i--);
 printf("%d\n", i);
}



void crivo2(int n){
    //int p = (int)n*( log(n) + log(log(n)) );
    int *eh_primo = malloc( n * sizeof(int));
    //int *primo = malloc(n * sizeof(int));
    //int k = 0;
    int it;
    int i;
    //int g;

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for(int i=1; i <= n; i++){
        eh_primo[i] = 1;
    }

    // Para cada número de 2 até p
    for(i = 2; i <= n/i; i++){

        // checo se o número atual é indefinido.
        if(eh_primo[i] == 1){

            // indico que os múltiplos dele são compostos.
           for(it = i + i; it <= n; it += i){
               eh_primo[it] = 0;
           }

        }

}

 for(it = n; eh_primo[it] != 1 ; it--);
    printf("%d\n", it);

}

void crivo3(int n){
    //int p = (int)n*( log(n) + log(log(n)) );
    int *eh_primo = malloc( n * sizeof(int));
    //int *primo = malloc(n * sizeof(int));
    //int k = 0;
    int it;
    int i;
    //int g;

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for(int i=1; i <= n; i++){
        eh_primo[i] = 1;
    }

    // Para cada número de 2 até p
    for(i = 2; i <= n/i; i++){

        // checo se o número atual é indefinido.
        if(eh_primo[i] == 1){

            // indico que os múltiplos dele são compostos.
           for(it = i * i; it <= n; it += i){
               eh_primo[it] = 0;
           }

        }

}

 for(it = n; eh_primo[it] != 1 ; it--);
    printf("%d\n", it);

}

void crivo4(int n){
    //int p = (int)n*( log(n) + log(log(n)) );
    int *eh_primo = malloc( n * sizeof(int));
    //int *primo = malloc(n * sizeof(int));
    int k = 0;
    int it;
    int i;
    //int g;

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
   // for(int i=1; i <= n; i++){
       // eh_primo[i] = 1;
   // }

    // Para cada número de 2 até p
    for(i = 2; i <= n/i; i++){

        // checo se o número atual é indefinido.
        if(eh_primo[i] != -877){ //significa que é primo

           // k = 2*i;
           for(it = i*i; it <= n; it += i){
               eh_primo[it] = -877;
           }

        } // complexidade: p(x)=x ln(ln(x^(0.5)))-((x)/(2 ln(x^(0.5)))) //x = n

}

 for(it = n; eh_primo[it] == -877 ; it--); // enquanto é igual
    printf("%d\n", it);
   // printf("%d", p);
}

void crivo5(int n){
    int *eh_primo = malloc( n * sizeof(int));

    int it;
    int i;
    int d; //dinamico
    //int g;
 for(it =  4; it <= n; it += 2){ // custo: T
      eh_primo[it] = -877;
 }

    // Para cada número de 2 até
    for(i = 3; i <= n/i; i++){

        // checo se o número atual é indefinido.
        if(eh_primo[i] != -877){ //significa que é primo

            d = i*2;
           for(it = i * i; it <= n; it += d){ //custo: 2T
               eh_primo[it] = -877;
           }

        }

    }

 for(it = n; eh_primo[it] == -877 ; it--);
    printf("%d\n", it);
   // printf("%d", p);


}


void crivo6(int n){

    int *eh_primo = malloc( n * sizeof(int));

    int r = 0 - ( rand() % 2);
    int mark = rand()% 93714;
    mark = mark + 2*mark*r;

    int it; // iterador do crivo
    int i; // possível primo
    int di; //intern. dinamic
    int k;
    //int g;
    int de  = 4; //external dinamic 6 - de
    //int g;
for(it =  4; it <= n; it += 2){ // elimina múltiplos de 2
    eh_primo[it] = mark;
}
for(it =  9; it <= n; it += 6){ //elimina apenas múltiplos de 3 que não são múltiplos de 2.
    eh_primo[it] = mark;
}

    for(i = 5; i <= n/i; i+=de){
       de = 6 - de;// 2, 4, 2, 4, 2 ...

        // checo se o primeiro número está marcado como composto.
        if(eh_primo[i] != mark){ //significa que i é primo

           k = 6*i;
           it = i*i;
           di = de*i;

            while(it <= n){
                eh_primo[it] = mark;
                it+=di;
                di = k - di; // evita marcar múltiplos de 3 e de 2.
            }//end while

        }//end if

    }//end for

 for(it = n; eh_primo[it] == mark ; it--);
    printf("%d\n", it);


}

void crivo_6(int n){

    int *eh_primo = malloc( n * sizeof(int));
    srand(time(NULL));
    int r = 0 - ( rand() % 2);
    int mark = rand()% 93714;
    mark = mark + 2*mark*r;
    int it;
    int i;
    int di; //internal dinamic
    int k = 2;
    int g = 2; //prime numbers
    int h = 1; // is not prime
    int de  = 4; //external dinamic
    //int g;



 for(it =  4; it <= n; it += 2){
    eh_primo[it] = mark ; h++;
}

for(it =  9; it <= n; it += 6){
    eh_primo[it] = mark ; h++;
}
    // Para cada número de 2 até
    for(i = 5; i*i <= n; i+=de){
       de = 6 - de;// 5: 2, 7: 4, 2, 4, 2 ...

        // checo se o número atual é indefinido.
        if(eh_primo[i] != mark ){ //significa que i é primo
            //printf("%d\n", rand()%2);
            k = 6*i;
           /* di = (6 - de)*i; // 6 - de necessario por causa de di = k - di
           for(it = i*i; it <= n; it += di){
               eh_primo[it] = -mark;

               //di = 2*i;
               di = k - di;
           }*/
           it = i*i;
           di = de*i;

            while(it <= n){
                if(eh_primo[it] != mark){
                h++; eh_primo[it] = mark;
                }
                it+=di;
                di = k - di;
            }

        }
   // de = 6 - de; // 2
    }
for(it = n; eh_primo[it] == mark  ; it--);

//printf("%d th prime number: %d\n",k, it);
/*k = 1;
 for(int j = 3; j <= n ; j+=2){
    if(eh_primo[j] != mark ){
     k++;
     }

 }*/
    printf("%d th prime number: %d %d\n",n - h, it, eh_primo[33] );
}

void crivo7(int n){

    int *eh_primo = malloc( n * sizeof(int));

    srand(time(NULL));
    int mark = rand()% 93714;
    mark = 0 - mark;
    int prime = rand()% 93714;

    int it; // iterador do crivo
    int i; // possível primo
    int di; //intern. dinamic
    int k;
    //int g;
    int de  = 4; //external dinamic 6 - de

    eh_primo[2] = prime;
    eh_primo[3] = prime;
 /*   //int g;

for(it =  i; it <= n; it += 2){ // elimina múltiplos de 2
    eh_primo[it] = mark;
}
i+=3; // para 10^9
for(it =  i; it <= n; it += 6){ //elimina apenas múltiplos de 3 que não são múltiplos de 2.
    eh_primo[it] = mark;
}

*/
    for(i = 5; i <= n/i; i+=de){
       de = 6 - de;// 2, 4, 2, 4, 2 ... // pula múltiplos de 3 e de 2. não faz nada com eles ( INTERVALO de 5 A i )

        // checo se o primeiro número está marcado como composto.
        if(eh_primo[i] != mark){ //significa que i é primo
           eh_primo[i] = prime;

           k = 6*i;
           it = i*i;
           di = de*i;
            while(it <= n){
                eh_primo[it] = mark;
                it+=di;
                di = k - di; // evita marcar múltiplos de 3 e de 2. (INTERVALO de i*i A n)
            }//end while

        }//end if

    }//end for


 for(; i <= n; i+=de){
    de = 6 - de;
    if(eh_primo[i] != mark)
        eh_primo[i] = prime;
 }

 for(it = n; eh_primo[it] != prime ; it--);
    printf("%d\n", it);

free(eh_primo);
 /*   k = 2;
 for(int j = 5; j <= n ; j+=2){
    if(eh_primo[j] == prime ){
     k++;
     }
}*/
// printf("%d th prime number", k);
}

void crivo7_(int n){

    int *eh_primo = malloc( n * sizeof(int));

    srand(time(NULL));
    int mark = rand()% 93714;
    mark = 0 - mark;
    int prime = rand()% 93714;

    int it; // iterador do crivo
    int i; // possível primo
    int di; //intern. dinamic
    int k;
    int count;
    int de  = 4; //external dinamic 6 - de

    eh_primo[2] = prime;
    eh_primo[3] = prime;
 /*   //int g;

for(it =  i; it <= n; it += 2){ // elimina múltiplos de 2
    eh_primo[it] = mark;
}
i+=3; // para 10^9
for(it =  i; it <= n; it += 6){ //elimina apenas múltiplos de 3 que não são múltiplos de 2.
    eh_primo[it] = mark;
}

*/
    for(i = 5; i <= n/i; i+=de){
       de = 6 - de;// 2, 4, 2, 4, 2 ... // pula múltiplos de 3 e de 2. não faz nada com eles ( INTERVALO de 5 A i )

        // checo se o primeiro número está marcado como composto.
        if(eh_primo[i] != mark){ //significa que i é primo
           eh_primo[i] = prime;

           k = 6*i;
           it = i*i;
           di = de*i;
            while(it <= n){
                eh_primo[it] = mark;
                it+=di;
                di = k - di; // evita marcar múltiplos de 3 e de 2. (INTERVALO de i*i A n)
            }//end while

        }//end if

    }//end for


 for(; i <= n; i+=de){
    de = 6 - de;
    if(eh_primo[i] != mark)
        eh_primo[i] = prime;
 }

 for(it = n; eh_primo[it] != prime ; it--);
    printf("%d\n", it);

free(eh_primo);
 /*   k = 2;
 for(int j = 5; j <= n ; j+=2){
    if(eh_primo[j] == prime ){
     k++;
     }
}*/
// printf("%d th prime number", k);
}
