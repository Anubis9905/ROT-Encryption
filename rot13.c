//Encrypt Strings with ROT5,ROT13,ROT18 and ROT47

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROT13 1
#define ROT5 2
#define ROT18 3
#define ROT47 4

char* encROT5(char* in){
    int len= strlen(in);
    char* out=(char*) malloc(len*sizeof(char)+1);
    int i=0;
    for (i=0;i<len;i++){
    if(in[i]>='0' && in[i]<='9'){
        out[i]=(((in[i]-48)+5)%10)+48;
        //printf("%d -> %d\n",in[i],out[i]);
    }
    else{
        out[i]=in[i];
    }
}

    out[i]='\0';
    return out;
}
char* encROT13(char* in){

    int len= strlen(in);
    char* out=(char*) malloc(len*sizeof(char)+1);
//printf("\n",in);
int i=0;
for (i=0;i<len;i++){
    if(in[i]>='A' && in[i]<='Z'){
        out[i]=(((in[i]-65)+13)%26)+65;
        //printf("%d -> %d\n",in[i],out[i]);
    }
    else if(in[i]>='a' && in[i]<='z'){
        out[i]=(((in[i]-97)+13)%26)+97;
        //printf("%d -> %d\n",in[i],out[i]);
    }
    else{
        out[i]=in[i];
    }
}
out[i]='\0';
//printf("%s\n",out);
//printf("Returning\n");
return out;
}

char* encROT47(char* in){
    int len= strlen(in);
    char* out=(char*) malloc(len*sizeof(char)+1);
    int i=0;
    for (i=0;i<len;i++){
    if(in[i]>='!' && in[i]<='~'){
        out[i]=(((in[i]-'!')+47)%94)+'!';
        //printf("%d -> %d\n",in[i],out[i]);
    }
    else{
        out[i]=in[i];
    }
}

    out[i]='\0';
    return out;
}


//ROT 13, 5, 18, 47
char* rot(int type, char* in){
    switch(type){
        case ROT13:
        return encROT13(in);
        case ROT5:
        return encROT5(in);
        case ROT18:
        return encROT13(encROT5(in));
        break;
        case ROT47:
        return encROT47(in);
        default:
            return NULL;

    }
    return NULL;
}

int main(){
    char test[]="Hallo ich bin ein Testsatz";
    char test2[]="1234567890";
    char test3[]="~Hallo:: ich bin ein Testsatz, 1234567890!~";
    char buff[35];
    char buff2[35];


    printf("Ursprung ROT13: %s\n",test);
    strcpy(buff,rot(ROT13,test));
    printf("1:  %s\n",buff);

    strcpy(buff2,rot(ROT13,buff));
    printf("2:  %s\n",buff2);

    printf("Ursprung ROT5: %s\n",test2);
    strcpy(buff,rot(ROT5,test2));
    printf("1:  %s\n",buff);

    strcpy(buff2,rot(ROT5,buff));
    printf("2:  %s\n",buff2);


    printf("Ursprung ROT18: %s\n",test3);
    strcpy(buff,rot(ROT18,test3));
    printf("1:  %s\n",buff);

    strcpy(buff2,rot(ROT18,buff));
    printf("2:  %s\n",buff2);



    printf("Ursprung ROT47: %s\n",test3);//ROT47
    strcpy(buff,rot(ROT47,test3));
    printf("1:  %s\n",buff);

    strcpy(buff2,rot(ROT47,buff));
    printf("2:  %s\n",buff2);
    return EXIT_SUCCESS;
}
