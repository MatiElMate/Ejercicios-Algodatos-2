#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

void pedir_arreglo(int tam, int a[]){
    int k;
    k = 0;

    do{
        printf("El elemento numero %d del arreglo será: ",k);
        scanf("%d",&a[k]);
        k = k + 1;
    } while (tam != k);
}

struct bound_data check_bound(int value, int a[], unsigned int length){
    bool upper;
    bool lower;
    bool exist;
    int i;
    int position;

    position = 0;
    exist = false;
    upper = true;
    lower = true;

        while ( i < length && (lower || upper)){
            if (a[i] > value){
                upper = false;
            }else if (a[i] < value){
                    lower = false;
                }

            if (a[i] == value && !(exist)){
                exist = true;
                position = i;
            }
            i++;

    }

    struct bound_data result = {upper, lower, exist, position};
    
    return result;
    
}

void main(){
    struct bound_data result;  
    int length;
    printf("De cuantos elementos sera el arreglo? ");
    scanf("%d",&length);
    int a[length];
    pedir_arreglo(length,a);
    int value;
    printf("Ingresa un valor: ");
    scanf("%d", &value);

    result = check_bound(value, a, length);

    printf("El valor ingresado es el mas grande de todos: %d \n" , result.is_upperbound);
    printf("El valor ingresado es el mas chico de todos: %d \n" , result.is_lowerbound);
    if (result.exists){
        printf("El valor ingresado es igual a otro: %d \n" , result.exists);
        printf("Ese valor se encuentra en la posición: %d \n" , result.where);
    }else{
        printf("El valor ingresado es igual a otro: %d \n" , result.exists);
    }   
}
    








