
#include <stdio.h>
#include <string.h>

int dnt(int *a)
{
    int d ;
    d = *(a + 3*0 + 0) * 
        ( (*(a + 3*1 + 1) * *(a + 3*2 + 2)) - (*(a + 3*1 + 2) * *(a + 3*2 + 1)) )-
        *(a + 3*0 + 1) * 
        ( (*(a + 3*1 + 0) * *(a + 3*2 + 2)) - (*(a + 3*1 + 2) * *(a + 3*2 + 0)) )+
        *(a + 3*0 + 2) * 
        ( (*(a + 3*1 + 0) * *(a + 3*2 + 1)) - (*(a + 3*2 + 0) * *(a + 3*1 + 1)) );
    // printf(" \n %d ", *(a + 3*2 + 2));
    return d;
}

void extuq(int a,int b){
int q,a1,a2,a3,b1,b2,b3;
a1 = 1;
a2 = 0;
a3 = a;
b1 = 0;
b2 = 1;
b3 = b;
while(1){
if(b3 == 0){
return 0;
break;
}
if(b3 == 1){
while(b2 < 0)
b2 = b2 + a;
return b2;
break;
}
q = a3/b3;
t1 = a1 - b1*q;
t2 = a2 - b2*q;
t3 = a3 - b3*q;
a1 = b1;
a2 = b2;
a3 = b3;
b2 = t1; 
b2 = t2; 
b3 = t3;
} }

int main() {
    int p,i,j,l;
    char key[9] = "gybnqkurp";
    int k_int[3][3];
    char plain[] = "act";
    int p_int[3];
    char cip[3] ;
    int c_int[3];
    do{
        // printf("\n ==>  Enter Key text ==> ");
        // scanf("%s",&key);
        // printf("%s",key);
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                k_int[i][j] = key[i*3 + j] - 'a';
                // printf("\t%d",k_int[i][j]);
            }
        }
    }while(dnt(&k_int[0][0]) == 0);
    // printf("%d",dnt(&k_int[0][0]));
    // Encryption
    l = strlen(plain);
    printf("\n test lenth %d",l);
    for(p = 0; p < l; p+=3){
        for(i = 0; i < 3; i++){
            c_int[i] = 0;
            // printf("\n");
            for(j = 0; j < 3; j++){
                p_int[j] = (plain[p+j] - 'a');
                // printf("\t test p_int %d",p_int[j]);
                c_int[i] = c_int[i] + (k_int[i][j] * p_int[j]) ;
            }
            c_int[i] = c_int[i] % 26; 
            cip[p+i] = c_int[i] + 'a' ; 
        }
    }
    for(i = 0; i < 3; i++)
        printf("\t%c",cip[i]);  
    
    // Decryption
    int dk_int[3][3];
    int de_int[3];
    char de[3];
    int dtn_inv,temp;
    int adj[3][3];
    adj[0][0] = k_int[1][1]*k_int[2][2] - k_int[1][2]*k_int[2][1];
    adj[0][1] = k_int[1][2]*k_int[2][0] - k_int[0][1]*k_int[2][2];
    adj[0][2] = k_int[0][1]*k_int[1][2] - k_int[0][2]*k_int[1][1];
    adj[1][0] = k_int[1][2]*k_int[2][0] - k_int[2][2]*k_int[1][0];
    adj[1][1] = k_int[2][2]*k_int[0][0] - k_int[0][2]*k_int[2][0];
    adj[1][2] = k_int[0][2]*k_int[1][0] - k_int[1][2]*k_int[0][0];
    adj[2][0] = k_int[1][0]*k_int[2][1] - k_int[2][0]*k_int[1][1];
    adj[2][1] = k_int[2][0]*k_int[0][1] - k_int[2][1]*k_int[0][0];
    adj[2][2] = k_int[0][0]*k_int[1][1] - k_int[1][0]*k_int[0][1];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(adj[i][j] < 0){
                temp = ((-1)*adj[i][j] ) / 26;
                temp++;
                adj[i][j] = (temp * 26) + adj[i][j]; 
            }
            dk_int[i][j] =  
        }
    }
}
