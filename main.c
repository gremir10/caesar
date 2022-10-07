#include <stdio.h>
#include <stdlib.h>

int* caesar_cipher(int key, int text[], int size, int encrypt){ //* = returning an address
   int i;                            //allocate size * 4 bytes for array
   int* out_text = (int *) malloc(size * sizeof(int)); //have to cast result of return to malloc
                                                           //as (int *) bc malloc returns void*
                                                        //want to constrain type so cast as int *
           if (encrypt ==0 ) {
               key =- key;
           }
       for(i = 0; i < size; i++) {
       out_text[i] = (text[i] + key + 10) % 10;  //treat out_text as an array
   }
   return out_text;
}

void print_text(int *text, int size) {
    int i;
    for (i = 0; i <size; i++){
        printf("%d, ", text[i]);

    }
    printf("\n");
    return;
}

int main() {

    int plain_txt[] = {1, 2, 9, 0};
    int key = 3;
    int size = 4;

    int *cipher_text;

    cipher_text = caesar_cipher(key, plain_txt, size, 0); //encrypt =1= true, boolean
    print_text(cipher_text, size);

    free(cipher_text); //since not using it after this point
                      //malloc takes up space in the heap so free() removes it

    cipher_text = NULL;    //uppercase = constant, NULL prevents any
                          // other part of program from accessing it in unintended way
                          //whenever a pointer is free()d set it to NULL after
    return 0;

}
