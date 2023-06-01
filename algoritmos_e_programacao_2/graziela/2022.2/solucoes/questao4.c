#include <stdio.h>
int verificaPrimo(int w){
    int i = 0;
    if(w==2){
        return 1;
    }else if(w==1){
        return 0;
    }
    for(i = 2; i < w && w%i!=0; i++)
        ;
    if(i==w)
       return 1;
    else
        return 0;
}
int temPrimo(int v[], int k){
    if(verificaPrimo(v[k-1])){
        return 1;
    }else{
        if(k==0){
            return 0;
        }else{
            return temPrimo(v, k-1);    
        }
    }
}
int main(){

    int n;
    scanf("%d", &n);

    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    if(temPrimo(v, n) == 1)
        printf("Sim\n");
    else
        printf("Nao\n");

    return 0;
}