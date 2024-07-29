#define DTW_ALLOW_CHASH
#include "../unique.definition_requirements.h"

void  *private_dtw_CHashArray_callback(DtwResource *item,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return (void*)formmate_args->callback(item,formmate_args->args);
}

bool private_dtw_CHashArray_filtrage(DtwResource *item,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return formmate_args->filtrage_callback(item,formmate_args->args);
}

int private_dtw_CHashArray_ordenation(DtwResource *item1,DtwResource *item2,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return formmate_args->ordenation_callback(item1,item2,formmate_args->args);
}

void privateDtwResource_add_to_item_to_CHashArray_array(void* array, void *item){
    CHashArray_append_any(array, (CHash *)item);
}

CHashArray *DtwResource_map_CHashArray(DtwResource *self,DtwResourceCHashrrayMapProps props){

    CHashArray *itens = newCHashArrayEmpty();

    DtwResourceMapProps map_props = DtwResource_create_map_props(
        itens,
        privateDtwResource_add_to_item_to_cJSONObject,
        private_dtw_CHashArray_callback
    );

    map_props.args = (void*)&props;
    if(props.filtrage_callback) {
        map_props.filtrage_callback = private_dtw_CHashArray_filtrage;
    }

    if(props.ordenation_callback) {
        map_props.ordenation_callback = private_dtw_CHashArray_ordenation;
    }

    DtwResource_map(self,map_props);

    return itens;
}
