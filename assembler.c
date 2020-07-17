#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char BYTE;

int main(void)
{

FILE * fpw, *fpr;
char instruc [10], filename [15], fileout[15];
int line = 0;

printf("enter input file: (specify type e.g. .txt \n");
scanf("%s",filename);
fpr= fopen(filename, "r");
for(int j = 0; filename[j]!='.';j++)
{
	fileout[j]=filename[j];
}
fpw= fopen(strcat(fileout,"_out"), "w");
fprintf(fpw,"v2.0 raw\n0\n" );

while((fscanf(fpr,"%s",instruc))!=EOF){

	int addr =0;
	int iaddr =0;
	char ass_instruc [10]="";
        for (int x=0; instruc[x]!='\0'; x++ ) {

            if ((instruc[x]>='a' && instruc[x]<='z') || (instruc[x]>='A' && instruc[x]<='Z') ){

                ass_instruc [iaddr] = instruc[x];
                iaddr++;

            }

            else if(instruc[x]>='0' && instruc[x]<='9') {

				addr =(addr * 10) + (instruc[x]-48);
            }

        }


    if (strcmp(ass_instruc, "LDA") == 0){
        fprintf(fpw,"1%x \n",addr);
    }
    else if (strcmp(ass_instruc, "ADD") == 0){
        fprintf(fpw,"2%x \n",addr);
    }
    else if (strcmp(ass_instruc, "J") == 0){
        fprintf(fpw,"3%x \n",addr);
    }
    else if (strcmp(ass_instruc, "STA") == 0){
        fprintf(fpw,"4%x \n",addr);
    }
    else if (strcmp(ass_instruc, "LDI") == 0){
        fprintf(fpw,"5%x \n",addr);
    }
    else if (strcmp(ass_instruc, "SUB") == 0){
        fprintf(fpw,"6%x \n",addr);
    }
    else if (strcmp(ass_instruc, "OUT") == 0){
        fprintf(fpw,"e%x \n",0);
    }
    else if (strcmp(ass_instruc, "HLT") == 0){
        fprintf(fpw,"f%x \n",0);
    }
    else if (strcmp(ass_instruc, "JC") == 0){
        fprintf(fpw,"a%x \n",addr);
    }
    else if (strcmp(ass_instruc, "JZ") == 0){
        fprintf(fpw,"9%x \n",addr);
    }
    else if (strcmp(ass_instruc, "JCZ") == 0){
        fprintf(fpw,"8%x \n",addr);
    }
    else if (strcmp(ass_instruc, "I") == 0){
    fprintf(fpw,"8%x \n",addr);
    }
    else {
        printf("\n ERROR: Invalid instruction at %d \n", line );
    }


    if(ass_instruc=="J"){
        if (addr=="1"){
            (strcmp(ass_instruc, "LDA") == 0);
        }
        else if(addr="2"){
            (strcmp(ass_instruc, "ADD") == 0);
        }
        else if(addr="4"){
            (strcmp(ass_instruc, "STA") == 0);
        }
        else if(addr="5"){
            (strcmp(ass_instruc, "LDI") == 0);
        }
        else if(addr="6"){
            (strcmp(ass_instruc, "SUB") == 0);
        }
        else if(addr="e"){
            (strcmp(ass_instruc, "OUT") == 0);
        }
        else if(addr="f"){
            (strcmp(ass_instruc, "HLT") == 0);
        }
        else if(addr="a"){
            (strcmp(ass_instruc, "JC") == 0);
        }
        else if(addr="9"){
            (strcmp(ass_instruc, "JZ") == 0);
        }
        else if(addr="8"){
            (strcmp(ass_instruc, "JCZ") == 0);
        }

r
    }

    line++;
}



fclose(fpr);
fclose(fpw);
}
