
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.typesg.h"
//silver_chain_scope_end

typedef struct DtwJsonTreeErrorModule{

    DtwJsonTreeError * (*validate_json_tree_by_cJSON)(cJSON *json_tree);
    DtwJsonTreeError * (*validate_json_tree_by_content)(const char *content);
    void (*free)(struct DtwJsonTreeError *self);
    void (*represent)(struct DtwJsonTreeError *self);

}DtwJsonTreeErrorModule;
