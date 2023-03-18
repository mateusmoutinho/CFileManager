
#include "doTheWorld/doTheWorldmain.c"


int main(int argc, char *argv[]){
    
    struct DtwTree *tree = dtw_tree_constructor();
    
    //tree->add_tree_from_hardware(tree,"exemples",DTW_LOAD_CONTENT,DTW_PRESERVE_CONTENT);
    /*
    for(int i = 0; i < tree->size; i++){
        tree->tree_parts[i]->hardware_write(tree->tree_parts[i],DTW_SET_AS_ACTION);
        tree->tree_parts[i]->ignore = true;
    }
    char *json_string = tree->dumps_json_tree(
        tree,
        DTW_PRESERVE_CONTENT,
        DTW_PRESERVE_PATH_ATRIBUTES,
        DTW_PRESERVE_HARDWARE_DATA,
        DTW_PRESERVE_CONTENT_DATA,
        DTW_NOT_MINIFY,
        DTW_CONSIDER_IGNORE
    );

    dtw_write_string_file_content("exemples.json",json_string);
    */
    
    char *json_string = dtw_load_string_file_content("exemples.json");
    struct DtWJsonError *json_error = dtw_validate_json_tree(json_string);
    if(json_error->code != DTW_JSON_ERROR_CODE_OK){
        printf("JSON ERROR: %s on %i",json_error->menssage,json_error->position);
        return 1;
    }
   
    tree->loads_json_tree(tree,json_string);
    tree->represent(tree);
    
    tree->free_tree(tree);
    return 0;
}
