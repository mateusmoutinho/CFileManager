#include "../unique.definition.h"


void DtwResource_foreach(DtwResource *self, bool(*filtrage_callback)(DtwResource *item, void *args_filter), void(*callback)(DtwResource *item, void *args), void *args, int start, int qtd){

    DtwResourceArray *itens = DtwResource_sub_resources(self);

    int total = 0;

    int total_skipded = 0;

    for(int i = 0; i < itens->size; i++){
        DtwResource *current = itens->resources[i];



        if(filtrage_callback){
            bool result = filtrage_callback(current, args);

            if(!result){
                continue;
            }
        }

        total_skipded++;

        if(total_skipded <= start){
            continue;
        }

        total++;

        if(total > qtd && qtd != -1){
            break;
        }

        callback(current, args);
    }
}
