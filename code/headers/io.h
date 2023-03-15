
#ifdef __linux__
#define dtw_create_dir(path) mkdir(path,0777)
#elif _WIN32
#define dtw_create_dir(path) _mkdir(path)
#endif

void dtw_create_dir_recursively(const char *path);

void dtw_remove_any(const char* path);


char *dtw_load_any_content(const char * path,int *size,bool *is_binary);
char *dtw_load_string_file_content(const char * path);


char *dtw_load_binary_content(const char * path,int *size);


bool dtw_write_any_content(const char *path,const char *content,int size);
bool dtw_write_string_file_content(const char *path,char *content);
int dtw_entity_type(const char *path);

#ifdef __cplusplus
    bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge=false);
#else
    bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge);
#endif 

void dtw_move_any(char* src_path, char* dest_path,bool merge) ;