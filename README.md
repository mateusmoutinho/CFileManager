# DoTheWorld
DoTheWorld is a Windows/Linux single file library designed to handle files in C/C++ in a number of ways, providing everything from simple functions for reading/writing files and folders, to complex functions like taking sha256 from files, checking modification dates. And functionalities of atomic writing of folders/files through transaction systems.



## Learning
In These Current Markdown you will see some basic exemples of usage of these library 
but if you want to get an deep knolege see at **exemples** folder, you will find an lot of exemplos of how you can use DoTheWorld

# Installation

The installation of DoTheWorld is made to be as dumb as possible, just  download the file  amalgamation **doTheWorld.h**  and include in your project.
if this compiles then the library will work:
~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){
    
    
    return 0;
}
~~~

## Full Folder
Alternatively you can download the entire **doTheWorld** folder and include the **doTheWorld/doTheWorldMain.h** file

~~~c

#include "doTheWorld/doTheWorldMain.h"

int main(int argc, char *argv[]){

    return 0;
}

~~~
# IO Operations

## Reading strings
if you are sure that the content you are going to read is not binary you can call the function **dtw_load_string_file_content**
~~~c


#include "doTheWorld.h"

int main(int argc, char *argv[]){
  //load a string file content
  const char *path = "exemple_folder/a/test.txt";
  char *content = dtw_load_string_file_content(path);
  if(content == NULL){
    printf("error oppening %s\n",path);
    return 1;
  }
  printf("content: %s\n",content);
  free(content);
  return 0;
}
~~~
## Reading Any
if you are not sure what data type a file is you can call the function **dtw_load_any_content**

~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){
 
  const char *path = "exemple_folder/deer.jpg";
  int size;
  bool is_binary;
  //load any file, is useful if you don't know if the file is binary or not
  unsigned char *content = dtw_load_any_content(path,&size,&is_binary);
  if(content == NULL){
    printf("error oppening %s\n",path);
    return 1;
  }
  printf("size: %d\n",size);
  printf("is_binary: %s\n",is_binary ? "true" : "false");
  printf("content: %s\n",content);
  free(content);
  return 0;
}
~~~


## Writing strings

to write strings in text files is very simple, just call the function **dtw_write_string_file_content**
(Note that the target directory does not need to exist, if it does not exist it will be created automatically)

~~~c
#include "doTheWorld.h"
int main(int argc, char *argv[]){
  // Write a string to a file the path is auto created
  
  bool result = dtw_write_string_file_content("test/a/test.txt","Hello World!");
  printf("result: %s\n",result ? "true" : "false");
  return 0;
}
~~~

## Writing Any

if you want to write anything to a file, it's also very simple, use the **dtw_load_binary_content** function, but note that it will be necessary to pass the writing size

~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){
  //load the beer image
  const char *deer_path = "test/exemple_folder/deer.jpg";
  int deer_size;
  unsigned char *content = dtw_load_binary_content(deer_path,&deer_size);
  //use these functions for binary files
  if(content == NULL){
    printf("error oppening %s\n",deer_path);
    return 1;
  }
  printf("size: %d\n",deer_size);

  bool result = dtw_write_any_content("test/deer.jpg",content,deer_size);
  printf("result: %s\n",result ? "true" : "false");
  return 0;
}
~~~
## Creating Dirs
If you want to create dirs you can call the function **dtw_create_dir_recursively**
passing the folder you want to create,dont wory about if the previews path dont exist 
it will create till reachs the target folder
~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){
 
  dtw_create_dir_recursively("a/b/c/");
  return 0;
}
~~~
##  Copying Things 
With the function **dtw_copy_any** you can copy either files or folders to one position to anoter position 
##### Copying files
~~~c


#include "doTheWorld.h"

int main(int argc, char *argv[]){

  dtw_copy_any("exemple_folder/deer.jpg","deer.jpg",DTW_NOT_MERGE);
  return 0;
}
~~~


## Moving Things

You can move either folders or files with **dtw_move_any** function 

~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){


  dtw_move_any("exemple_folder/deer.jpg","deer.jpg",DTW_NOT_MERGE);

  return 0;
}
~~~

# Monodimension Listage

With the listage functions you can extract all Strings Arrays of elements in an folder 

## Listing files
~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *files = dtw_list_files("exemple_folder", DTW_CONCAT_PATH);
  for(int i = 0; i < files->size; i++){
    printf("%s\n", files->strings[i]);
  }
  files->free(files);
  return 0;
}
~~~
## Listing dirs 
~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *files = dtw_list_dirs("exemple_folder", DTW_CONCAT_PATH);
  files->represent(files);
  files->free(files);
  return 0;
}
~~~
## Listing All 
~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *all = dtw_list_all("exemple_folder",DTW_CONCAT_PATH);
  all->represent(all);
  all->free(all);
  return 0;
}
~~~
# MultiDimension Listage 
The By Using multi dimension listage functions , you can see all itens listed in all sub folders of the "main" folder 

## Listing Files Recursively
~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *files = dtw_list_files_recursively(
    "exemple_folder",
    DTW_CONCAT_PATH
    );
  files->represent(files);
  files->free(files);
  return 0;
}
~~~
## Listing Dirs Recursively

~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *files = dtw_list_dirs_recursively(
    "exemple_folder",
    DTW_CONCAT_PATH
    );
  files->represent(files);
  files->free(files);
  return 0;
}
~~~
## Listing All Recursively

~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){

  struct DtwStringArray *files = dtw_list_all_recursively(
    "exemple_folder",
    DTW_CONCAT_PATH
    );
    
  files->represent(files);
  files->free(files);
  return 0;
}
~~~
# Useful Functions 

## Dealing with base64 
You can easly transform an binary file to an base64 string like these 
~~~c

#include "doTheWorld.h"

int main(int argc, char *argv[]){
   const char *deer_path = "exemple_folder/deer.jpg";
   char *deerb64  = dtw_convert_binary_file_to_base64(deer_path);
   printf("deer: %s", deerb64);
    free(deerb64);
}
~~~
Or you can retransform an base64 file to binary again 
~~~c 
#include "doTheWorld.h"

int main(int argc, char *argv[]){
   //creating the b64 file
   const char *deer_path = "exemple_folder/deer.jpg";
   char *deerb64  = dtw_convert_binary_file_to_base64(deer_path);
   dtw_write_string_file_content("deer.txt", deerb64);
   free(deerb64);

   // loading and reconverting to binary 
    char *string_deer64 = dtw_load_string_file_content("deer.txt");
    int string_deer64_size = strlen(string_deer64);
    size_t out_size = 0;
    unsigned char *deer = dtw_base64_decode(string_deer64, string_deer64_size, &out_size);
    dtw_write_any_content("deer2.jpg", deer, out_size);
}
~~~
## Dealing with Sha 256
Generating Sha from file 
~~~c 

#include "doTheWorld.h"

int main(int argc, char *argv[]){

   char *hash = dtw_generate_sha_from_file("README.md");
   printf("SHA: %s", hash);
   free(hash);
}
~~~
## Getting file last modification 
### Unix 
~~~c 

#include "doTheWorld.h"

int main(int argc, char *argv[]){
   int last_modification_in_unix = dtw_get_file_last_motification_in_unix("README.md");
    printf("Last modification: %d\n", last_modification_in_unix);
}
~~~
### Str
~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){
    char *last_modification = dtw_get_file_last_motification_in_string("README.md");
    printf("Last modification: %s", last_modification);
    free(last_modification);
}
~~~
# Trees, TreeParts And Transactions

with tree concepts, you can manipulate files as trees, and implement IO modifications with atomic concepts 


## Tree Parts 

### Loading An TreePart 
~~~c

#include "doTheWorld.h"



int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "main.c",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    part->represent(part);
    part->free_tree_part(part);
}   
~~~
### Creating an TreePart 
~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_NOT_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    part->set_string_content(part,"Hello World");
    part->hardware_write(part,DTW_SET_AS_ACTION);
    part->hardware_commit(part);
    part->free_tree_part(part);
    
}   
~~~
### Generating Content Modifications

~~~c


#include "doTheWorld.h"


int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    //getting the content
    char *content = part->get_content_string_by_reference(part);
    char new_content[100] ="";
    strcat(new_content,content);
    strcat(new_content," New Mensage");
    part->set_string_content(part,new_content);

    part->hardware_write(part,DTW_SET_AS_ACTION);
    part->hardware_commit(part);
    part->free_tree_part(part);
}   
~~~
### Getting  Path Paramns 
~~~c 

#include "doTheWorld.h"



int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    struct DtwPath *path = part->path;

    char *name = path->get_full_name(path);
    char *extension = path->get_extension(path);
    char *dir = path->get_dir(path);
    char *full_path = path->get_path(path);
    printf("name : %s\n",name);
    printf("extension : %s\n",extension);
    printf("dir : %s\n",dir);
    printf("full_path : %s\n",full_path);


    free(name);
    free(extension);
    free(dir);
    free(full_path);
    part->free_tree_part(part);
}   
~~~
### Changing path atributes 

~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    struct DtwPath *path = part->path;

    path->set_dir(path,"a/b");
    path->set_name(path,"test2");
    path->set_extension(path,"md");
    path->represent(path);
    part->hardware_modify(part,DTW_SET_AS_ACTION);
    part->hardware_commit(part);
    part->free_tree_part(part);

}   
~~~
### Changing path Atributes at once 

~~~c

#include "doTheWorld.h"

int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    struct DtwPath *path = part->path;

    path->set_path(path,"a/test.md");

    part->hardware_modify(part,DTW_SET_AS_ACTION);
    part->hardware_commit(part);
    part->free_tree_part(part);

}   
~~~
## Transactions System 
With the **hardware_modify** , **hardware_write**, **hardware_remove** 
Functions , you can generate modifications, without implement it, in these 
way , you can create massive atomic transactions, and execute all at once 

### hardware_modify
Will Modificate the original content, for exemple, if you change the extension of an file, it will modificate the original content 

~~~c

#include "doTheWorld.h"

int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    struct DtwPath *path = part->path;

    path->set_extension(path,"md");

    part->hardware_modify(part,DTW_EXECUTE_NOW);
    part->hardware_commit(part);
    part->free_tree_part(part);

}    
~~~

### hardware_write 
Will write the file as an "new" file, ignoring the existence of the 
old file 

~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );

    struct DtwPath *path = part->path;

    path->set_extension(path,"md");

    part->hardware_write(part,DTW_EXECUTE_NOW);
    part->hardware_commit(part);
    part->free_tree_part(part);

}   
~~~

### hardware_remove

Will Delete the current Content 
~~~c

#include "doTheWorld.h"



int main(){

    struct DtwTreePart *part = dtw_tree_part_constructor(
            "test.txt",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA
            );


    part->hardware_remove(part,DTW_EXECUTE_NOW);
    part->hardware_commit(part);
    part->free_tree_part(part);

}   
~~~

## Trees
With Trees you can make massive folders and files modifications with 
easy steps 
### Loading Tree From Hardware
~~~c
#include "doTheWorld.h"

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
            );
    tree->represent(tree);
    tree->free(tree);
}   
~~~

### Iterating over Trees
~~~c
#include "doTheWorld.h"

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    for(int i = 0; i<tree->size;i++){
        struct DtwTreePart *current_part = tree->tree_parts[i];
        current_part->represent(current_part);
    }
    tree->free(tree);
}
~~~
### Retriving Tree Parts

#### Finding by Name 

~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
            );

    struct DtwTreePart *deer = tree->find_part_by_name(tree,"deer.jpg");
    if(deer){
        deer->represent(deer);
    }
    tree->free(tree);
}   
~~~
### Finding By Full Path 
~~~c

#include "doTheWorld.h"

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
            );

    struct DtwTreePart *deer = tree->find_part_by_path(
        tree,
        "exemple_folder/deer.jpg"
        );
    if(deer){
        deer->represent(deer);
    }
    tree->free(tree);
}   
~~~
### Finding By Function

~~~c



#include "doTheWorld.h"
bool test_if_deer(struct DtwTreePart*part){

    char *name = part->path->get_full_name(part->path);
    if(!name){
        return false;
    }
    if(strcmp(name,"deer.jpg") == 0){
        free(name);
        return true;
    }
    free(name);
    return false;
};


int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
            );


    struct DtwTreePart *deer = tree->find_part_by_function(
        tree,
        test_if_deer
        );

    if(deer){
        deer->represent(deer);
    }
    tree->free(tree);

}   
~~~
### Map and Filter
Trees suports even Maps or filters, it returns an new tree of the of the current lambda procediment 
#### Filter 
with filter you can filter the contents you want in an tree with an bool lambda
~~~c


#include "doTheWorld.h"

bool filter_txt(struct DtwTreePart *part){
    char *extension = part->path->get_extension(part->path);
    if(!extension){
        return false;
    }
    if(strcmp(extension,"txt") == 0){
        return true;
    }
    return false;
}

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    struct DtwTree *filtered = tree->filter(
            tree,
            filter_txt
            );
    filtered->represent(filtered);
    filtered->free(filtered);
    tree->free(tree);
}
~~~
#### Map
~~~c

#include "doTheWorld.h"

struct DtwTreePart * concat_test(struct DtwTreePart *part){
    if(part->content_exist_in_memory && part->is_binary == false){
        char *content = part->get_content_string_by_reference(part);
        const char *mensage = " test";
        char *new_content = (char*)malloc(strlen(content) + strlen(mensage)+ 2);
        strcpy(new_content,content);
        strcat(new_content,mensage);
        part->set_string_content(part,new_content);
        free(new_content);
    }
    return part;
}

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    struct DtwTree *concated = tree->map(
            tree,
            concat_test
            );

    concated->represent(concated);
    concated->free(concated);
    tree->free(tree);
}
~~~

### Realizing Tree Modifications 
With **hardware_commit_tree** you can commit all modifications at Once 
turning system ultra secury
~~~c


#include "doTheWorld.h"



int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    for(int i=0; i < tree->size;i++){
        struct DtwTreePart *part = tree->tree_parts[i];
        struct DtwPath *path = part->path;
        char *extension = path->get_extension(path);
        if(!extension){
            continue;
        }
        if(strcmp(extension,"txt") == 0){
            path->set_extension(path,"md");
            part->hardware_modify(part,DTW_SET_AS_ACTION);

        }
        free(extension);
    }

    tree->hardware_commit_tree(tree);
    tree->free(tree);
}
~~~
### Transaction Reports 
With transactin Reports , you can see what will be modified

~~~c


#include "doTheWorld.h"

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    for(int i=0; i < tree->size;i++){
        struct DtwTreePart *part = tree->tree_parts[i];
        struct DtwPath *path = part->path;
        char *extension = path->get_extension(path);
        if(!extension){
            continue;
        }
        printf("%s\n",extension);
        if(strcmp(extension,"txt") == 0){
            path->set_extension(path,"md");
            part->hardware_modify(part,DTW_SET_AS_ACTION);

        }
        free(extension);
    }
    struct DtwTransactionReport *report = tree->report(tree);
    report->represent(report);
    report->free_transaction(report);
    tree->free(tree);
}
~~~
### Tree Json Operations 
With Json Trees Operations you can save or load trees, from hardware or strings in an super easy mode 

#### Dumping Tree Json To File 
It will transform the tree in an json document 

~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );
    tree->dumps_json_tree_to_file(
            tree,
            "test.json",
            DTW_NOT_MINIFY,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_ATRIBUTES,
            DTW_PRESERVE_HARDWARE_DATA,
            DTW_LOAD_METADATA_DATA,
            DTW_CONSIDER_IGNORE
    );

    tree->free(tree);
}
~~~

#### Dumping Json Tree to string 

~~~c
#include "doTheWorld.h"
int main(){

    struct DtwTree *tree = newDtwTree();
    tree->add_tree_from_hardware(
            tree,
            "exemple_folder",
            DTW_LOAD_CONTENT,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_START
    );

    char *content = tree->dumps_json_tree(
            tree,
            DTW_NOT_MINIFY,
            DTW_LOAD_METADATA,
            DTW_PRESERVE_PATH_ATRIBUTES,
            DTW_PRESERVE_HARDWARE_DATA,
            DTW_LOAD_METADATA_DATA,
            DTW_CONSIDER_IGNORE
    );
    printf("%s",content);
    tree->free(tree);
}
~~~
#### Loading Json Tree From file 
If you want to recuperate the file you saved in the json file
you can load it 
~~~c

#include "doTheWorld.h"

int main(){

    struct DtwTree *tree = newDtwTree();
    tree->loads_json_tree_from_file(tree,"test.json");
    tree->insecure_hardware_write_tree(tree);
}
~~~

#### Loading Json Tree from string 

~~~c

#include "doTheWorld.h"


int main(){

    struct DtwTree *tree = newDtwTree();
    char *json_tree = dtw_load_string_file_content("test.json");
    tree->loads_json_tree(tree,json_tree);
    tree->insecure_hardware_write_tree(tree);
}
~~~




# Used Dependencies And Atributions
DoTheWorld includes all self dependecies in the single file, so you dont need to care about it, but if you will use one of these librarys, dont include it in your code to avoid circular imports

## CJson<br><br>
**CJson**: from https://github.com/DaveGamble/cJSON <br>
Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## sha-256 <br>
**sha-256**: from https://github.com/amosnier/sha-2 <br>

Zero Clause BSD License
© 2021 Alain Mosnier

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

