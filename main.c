
#include "code/doTheWorldSeparated.h"

int main(int argc, char *argv[]){
    dtw_write_string_file_content("teste.aa","") ;
    struct DtwTreePart *tree = dtw_tree_part_constructor("teste.aa",false);
    tree->represent(tree);
    tree->delete(tree);
}
