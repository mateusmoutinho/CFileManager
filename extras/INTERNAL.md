{HASHTAG} DoTheWorld
DoTheWorld is a Windows/Linux single file library designed to handle files in C/C++ in a number of ways, providing everything from simple functions for reading/writing files and folders, to complex functions like taking sha256 from files, checking modification dates. And functionalities of atomic writing of folders/files through transaction systems.


{HASHTAG}{HASHTAG} Learning
In These Current Markdown you will see some basic exemples of usage of these library
but if you want to get an deep knolege see at **exemples** folder, you will find an lot of exemplos of how you can use DoTheWorld

{HASHTAG} Installation
The installation of DoTheWorld is made to be as dumb as possible, just  download the
[Amalgamation](https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.001/doTheWorld.h)
file and include into your project.
if you prefer you can download by typing:
```shell
curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.001/doTheWorld.h -o doTheWorld.h
```


~~~c
{HASHTAG}include "doTheWorld.h"

int main(int argc, char *argv[])#{


    return 0;
}#/
~~~

{HASHTAG}{HASHTAG} Full Folder
Alternatively you can download the  [FullFolder](https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.001/doTheWorld.zip) by typing:
```shell
curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v8.001/doTheWorld.zip -o doTheWorld.zip && unzip doTheWorld.zip
```

~~~c

{HASHTAG}include "src/one.c"

int main(int argc, char *argv[])#{

    return 0;
}#/

~~~

{HASHTAG} Bulding the Project

{HASHTAG}  Bulding the Project
if you want to build the project from scracth, you will need  to have [OuiPacker](https://github.com/OUIsolutions/OuiPacker)
on version **0.005** dowloaded,then you can call:

~~~shel
./OuiPacker.out --folder_mode   build/ --install_dependencies  --amalgamate --zip  --silverchain_organize
~~~

These will create all the outputs into the release folder.
If you want to make all the tests and recreate the examples and readme , call:

~~~shell
./OuiPacker.out --folder_mode   build/ --install_dependencies  --amalgamate --zip  --silverchain_organize --test --create_examples --create_readme

~~~


{HASHTAG} IO Operations

{HASHTAG}{HASHTAG} Reading strings
if you are sure that the content you are going to read is not binary you can call the function **dtw_load_string_file_content**
{create_c_example("exemples/io/loading_string.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Reading Any Content

{create_c_example("exemples/io/loading_any.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Reading Double bools and Integers
you also can direclty load all types from an file  with numerical ios

{create_c_example("exemples/numerical_io/loading_data.c")}

to write strings in text files is very simple, just call the function **dtw_write_string_file_content**
(Note that the target directory does not need to exist, if it does not exist it will be created automatically)

{create_c_example("exemples/io/writing_strings.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Writing Any
if you want to write anything to a file, it's also very simple, use the **dtw_write_any_content** function, but note that it will be necessary to pass the writing size


{create_c_example("exemples/io/write_any.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Writing Double , bool and Integers
You also can write any type direclty to an file

{create_c_example("exemples/numerical_io/writing_data.c")}

If you want to create dirs you can call the function **dtw_create_dir_recursively**
passing the folder you want to create,dont wory about if the previews path dont exist
it will create till reachs the target folder

{create_c_example("exemples/io/create_dirs.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Copying Anything
With the function **dtw_copy_any** you can copy either files or folders to one position to anoter position

{create_c_example("exemples/io/copying_files.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Moving Any
You can move either folders or files with **dtw_move_any** function

{create_c_example("exemples/io/move_any.c")}


With the listage functions you can extract all Strings Arrays of elements in an folder

{HASHTAG}{HASHTAG} Listing files

{create_c_example("exemples/monodimension_listage/list_files.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Listing Dirs

{create_c_example("exemples/monodimension_listage/list_dirs.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Listing All

{create_c_example("exemples/monodimension_listage/list_all.c")}

The By Using multi dimension listage functions , you can see all itens listed in all sub folders of the "main" folder

{HASHTAG}{HASHTAG}{HASHTAG} Listing Files Recursively

{create_c_example("exemples/multidimension_listage/list_files_recursively.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Listing Dirs Recursively

{create_c_example("exemples/multidimension_listage/list_dirs_recursively.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Listing All Recursively

{create_c_example("exemples/multidimension_listage/list_all_recursively.c")}

{HASHTAG}{HASHTAG} Dealing with base64
You can easly transform an binary file to an base64 string like these

{create_c_example("exemples/extras/converting_file_to_base64.c")}

You also can reconvert an base64 string to binary

{create_c_example("exemples/extras/converting_b64_to_binary.c")}


{HASHTAG}{HASHTAG} Sha256
Generating Sha from file

{create_c_example("exemples/extras/generating_sha_from_file.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Unix

{create_c_example("exemples/extras/get_entity_last_modification_in_unix.c")}


{create_c_example("exemples/extras/get_entity_last_modification.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Locker
With the locker you can Lock files and ensure that even with multprocessment, they will
be executed in an order

{create_c_example("exemples/locker/locker_test.c")}


{HASHTAG}{HASHTAG} Resources
With Resources you can iterate over all types of values ,and modifie than into an single transaction or one by one
{HASHTAG}{HASHTAG}{HASHTAG} Setting Values

{create_c_example("exemples/resources/setters.c")}




{HASHTAG}{HASHTAG}{HASHTAG} Getting values of Resource
{create_c_example("exemples/resources/getters.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Generating transaction
with transactions you can make all modifications and executed or denny it one time,avoid nod
wanted side effects

{create_c_example("exemples/transaction/transaction_executiong.c")}


You also can dump the transaction to an json file to store it

{create_c_example("exemples/transaction/transaction_dumping_to_json.c")}

{create_c_example("exemples/transaction/transaction_loading_from_json.c")}



{HASHTAG}{HASHTAG}{HASHTAG} Schemas

Schema its a way to handle resources into a serializible way, providing foreing key and primary key concepts

{HASHTAG}{HASHTAG}{HASHTAG} Creating a insertion
in these example we are creating a user using schema concept

{create_c_example("exemples/schema/user_creation.c")}



{HASHTAG}{HASHTAG}{HASHTAG} Removing a insertion
In these example we also can destroy the user , automaticly destroying the index

{create_c_example("exemples/schema/user_remove.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Finding a insertion
With  primary keys you can find values without loop iteration increasing readability and speed,

{create_c_example("exemples/schema/user_find.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Iterating over insertions
you also can iterate over insertions

{create_c_example("exemples/schema/user_iteration.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Iterable Resources

with iterable functional system , you can iterate into Resources easly



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Each
with each, you can pass  also a filtrage callback, a start point (defaults its 0),
and the total elements (defaults its all)
{create_c_example("exemples/resources/Foreach.c")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Schema Each
you also can iterate over schemas with schema each

{create_c_example("exemples/schema/schema_each.c")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Map
with map you can construct, objects lists, with what ever you want
you just need to pass the object, the retriver, and some append function
to be called each generated object

{create_c_example("exemples/resources/map.c")}

of course, it also works with schemas

{create_c_example("exemples/schema/schema_map.c")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} CJson Array Map
you also can directly map a cJSON Array

{create_c_example("exemples/resources/cJSON_ArrayMap.c")}

{HASHTAG}{HASHTAG}{HASHTAG} CJSON Object Map
you also can generate a cJSON object, but you need to
provide a "keey_provider" function ,to determine the key of each
object generation (note that these key can bee released(free) after, you pass the),
free_key prop into the props object

{create_c_example("exemples/resources/cJSON_ArrayObject.c")}

{HASHTAG}{HASHTAG}{HASHTAG} CCHash
you can use [CHash](https://github.com/OUIsolutions/CHashManipulator) objects too
but in these case , you need to use define  DTW_ALLOW_CHASH , and include the lib
into the project since CHashManipulator, its not included into the amalgamation
{create_c_example("exemples/resources/CHashArray_map.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Trees and TreeParts
with tree concepts, you can manipulate files as trees, and implement IO modifications with atomic concepts

{HASHTAG}{HASHTAG}{HASHTAG} Loading An TreePart

{create_c_example("exemples/tree_parts/loading_tree_part.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Creating an empty tree Part

{create_c_example("exemples/trees/creating_tree_part.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Modifying an tree part

{create_c_example("exemples/tree_parts/tree_part_content_modification.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Retriing Paths Paramns

{create_c_example("exemples/path/getting_path_paramns.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Changing path Atributes at once


{create_c_example("exemples/path/change_path_attributes.c")}

With the **hardware_modify** , **hardware_write**, **hardware_remove**
Functions , you can generate modifications, without implement it, in these
way , you can create massive atomic transactions, and execute all at once


{HASHTAG}{HASHTAG}{HASHTAG} hardware_modify
Will Modificate the original content, for exemple, if you change the extension of an file, it will modificate the original content


{create_c_example("exemples/tree_parts/hardware_modify.c")}

Will write the file as an "new" file, ignoring the existence of the
old file

{create_c_example("exemples/tree_parts/hardware_write.c")}


Will Delete the current Content


{create_c_example("exemples/tree_parts/hardware_remove.c")}

With Trees you can make massive folders and files modifications with
easy steps
{HASHTAG}{HASHTAG}{HASHTAG} Loading Tree From Hardware

{create_c_example("exemples/trees/add_tree_from_hardware.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Iterating over An Tree

{create_c_example("exemples/trees/tree_iteration.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Finding An Tree by name

{create_c_example("exemples/trees/find_tree_part_by_name.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Finding An Tree by Path

{create_c_example("exemples/trees/find_tree_part_by_full_path.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Finding An Tree by Function

{create_c_example("exemples/trees/finding_tree_part_by_function.c")}

Trees suports even Maps or filters, it returns an new tree of the of the current lambda procediment
{HASHTAG}{HASHTAG}{HASHTAG} Filter
with filter you can filter the contents you want in an tree with an bool lambda

{create_c_example("exemples/trees/tree_filter.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Map

{create_c_example("exemples/trees/tree_map.c")}

With **hardware_commit_tree** you can commit all modifications at Once
turning system ultra securty


{create_c_example("exemples/trees/tree_commit.c")}


With transactin Reports , you can see what will be modified

{create_c_example("exemples/trees/transaction_report.c")}

With Json Trees Operations you can save or load trees, from hardware or strings in an super easy mode

{HASHTAG}{HASHTAG}{HASHTAG} Dumping Tree Json To File
It will transform the tree in an json document

{create_c_example("exemples/trees/dumps_json_tree_to_file.c")}


{create_c_example("exemples/trees/dumps_json_tree_to_string.c")}

If you want to recuperate the file you saved in the json file
you can load it

{create_c_example("exemples/trees/loads_json_tree_from_file.c")}


{create_c_example("exemples/trees/loads_json_tree_from_string.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Hash

By using hash Object you can digest values,( its very usefull in dynamic programing)
or to avoid recomputation in compilers or bundlers

{HASHTAG}{HASHTAG}{HASHTAG} Simple Hashing

{create_c_example("exemples/hash/simple_digest.c")}

{create_c_example("exemples/hash/file_hashing.c")}

{create_c_example("exemples/hash/file_hashing_by_last_modification.c")}


{HASHTAG}{HASHTAG}{HASHTAG} Randonizer
Randonizer it's a way to generate random values,integers or strings

{HASHTAG}{HASHTAG}{HASHTAG} Numerical Random
{create_c_example("exemples/randonizer/num_randonizer.c")}

{HASHTAG}{HASHTAG}{HASHTAG} Token  Random
{create_c_example("exemples/randonizer/token_randonizer.c")}


{HASHTAG}{HASHTAG} CJson<br><br>
**CJson**: from https://github.com/DaveGamble/cJSON <br>
Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

{HASHTAG}{HASHTAG} sha-256 <br>
**sha-256**: from https://github.com/amosnier/sha-2 <br>

Zero Clause BSD License
© 2021 Alain Mosnier

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
