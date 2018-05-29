#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
/*
int main(int argc, char **argv){
    int i;
    for(i = 0 ; i < argc; i++){
    printf("%s ",*(argv+i));
    }
    return 0;
}
*/
/*
int main(int argc, char **argv){
    int flag_a, flag_b, flag_c;
    flag_a = 0;
    flag_b = 0;
    flag_c = 0;
    char * flag_s;
    char c;
    while((c=getopt(argc,argv,"a:b:c:s:"))!=-1){
        switch(c){
            case 'a':
                flag_a = atoi(optarg);
                break;
            case 'b':
                flag_b = atoi(optarg);
                break;
            case 'c':
                flag_c = atoi(optarg);
                break;
            case 's':
                flag_s = optarg;
                break;
            case '?':
                flag_c = 9999;
                break;
            default:
                flag_c = 9988;
                break;
        }
        
    }
    if(flag_a==0||flag_b==0||flag_c==0||flag_c==9999||flag_c==9988||flag_s==NULL){
        printf("%s :/ argument error",argv[0]);
        exit(0);
    }
    printf("a : %d, b : %d, c : %d = total : %d\n", flag_a, flag_b, flag_c, flag_a+flag_b+flag_c);
    printf("%s",flag_s);
    
}
*/

/*int main(){
    int * arr;
    int size;
    int i;
    printf("적으세요 당신의 값");
    scanf("%d",&size);
    arr = (int *) malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        *(arr+i) = i;
    }
    for(i = 0 ; i < size ; i++){
        printf("%d\n",*(arr+i));
    }
    free(arr);
}*/

/*nt main(){
    struct sally{
        int x;
        int y;
    };
    
    struct sally *sam = (struct sally *) malloc(sizeof(struct sally));
    sam->x = 1;
    sam->y = 2;
    printf("%d, %d\n",sam->x,sam->y);
}*/
/*
int main(){
    typedef struct{
        int x;
        int y;
    }john;
    john sam = {1,2};
    john sam2 = {3,4};
    john * sam3;
    sam3 = &sam2;
    printf("%d, %d",sam3->x,sam3->y);
}
*/
