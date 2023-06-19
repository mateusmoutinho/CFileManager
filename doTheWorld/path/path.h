
typedef struct DtwPath {
    char *original_path;
    char *dir;
    char *name;
    char *extension;
    bool dir_exists;
    bool name_exists;
    bool extension_exists;
    //Getters
    bool  (*changed)(struct DtwPath *self);
    char *(*get_full_name) (struct DtwPath *self);
    char *(*get_name) (struct DtwPath *self);
    char *(*get_extension) (struct DtwPath *self);

    char *(*get_path) (struct DtwPath *self);
    char *(*get_dir) (struct DtwPath *self);

    
    //Setters
    void (*set_extension) (struct DtwPath *self, const char *extension);
    void (*set_name) (struct DtwPath *self, const char *name);
    void (*set_dir) (struct DtwPath *self, const char *path);
    void (*set_full_name) (struct DtwPath *self, const char *full_name);
    void (*set_path) (struct DtwPath *self, const char *target_path);
    
    void (*add_start_dir)(struct DtwPath *self, const char *start_dir);
    void (*add_end_dir)(struct DtwPath *self, const char *end_dir);

    void (*represent)(struct DtwPath *self);
    void (*free) (struct DtwPath *self);


}DtwPath;
struct DtwPath * newDtwPath(const char *path);
bool  DtwPath_path_changed(struct DtwPath *self);
char *DtwPath_get_full_name(struct DtwPath *self);
char *DtwPath_get_name(struct DtwPath *self);
char *DtwPath_get_extension(struct DtwPath *self);
char *DtwPath_get_path(struct DtwPath *self);
char *DtwPath_get_dir(struct DtwPath *self);

void DtwPath_set_extension(struct DtwPath *self, const char *extension);
void DtwPath_set_name(struct DtwPath * self, const char * name);
void DtwPath_set_dir(struct DtwPath *self, const char *path);

void DtwPath_set_full_name(struct DtwPath * self, const char * full_name);
void DtwPath_set_path(struct DtwPath *self, const char *target_path);

void DtwPath_add_start_dir(struct DtwPath *self, const char *start_dir);
void DtwPath_add_end_dir(struct DtwPath *self, const char *end_dir);

void DtwPath_represent_path(struct DtwPath *self);
void DtwPath_destructor_path(struct DtwPath *self);


