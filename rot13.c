#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

char* encodeROT13(char *in,int len){
char out[MAX];
char *ptr=out;
printf("%s\n",in);
int i=0;
for (i=0;i<len;i++){
    if(in[i]>=65 && in[i]<=90){
        out[i]=(((in[i]-65)+13)%26)+65;
        printf("%d -> %d\n",in[i],out[i]);
    }
    else if(in[i]>=97 && in[i]<=122){
        out[i]=(((in[i]-97)+13)%26)+97;
        printf("%d -> %d\n",in[i],out[i]);
    }
    else{
        out[i]=in[i];
    }
}
out[len]='\0';
//printf("%s\n",out);
//printf("Returning\n");
return ptr;
}

char* decodeROT13(char *in,int len){
char out[MAX];
char *ptr=out;
//printf("%s\n",in);
int i=0;
for (i=0;i<len;i++){
    if(in[i]>=65 && in[i]<=90){
        out[i]=(((in[i]-65)+13)%26)+65;
        //printf("%d - %d\n",out[i],in[i]);
    }
    else if(in[i]>=97 && in[i]<=122){
        out[i]=(((in[i]-97)+13)%26)+97;
        //printf("%d - %d\n",out[i],in[i]);
    }
    else{
        out[i]=in[i];
    }
}
out[len]='\0';
//printf("%s\n",out);
return ptr;
}

int main(){
   char input[]="Hallo ich bin ein TAstsatz";
    char output[MAX];
    
    printf("Encode folgendes: %s\n",input);
    strcpy(output,encodeROT13(input,30));
    printf("Encoded: %s\n",output);

    strcpy(input,decodeROT13(output,30));
    printf("Decoded: %s\n",input);


    return EXIT_SUCCESS;
}
