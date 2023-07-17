
enum {
    DTW_ABLE_TO_LOCK,
    DTW_ALREADY_LOCKED_BY_SELF,
    PRIVATE_DTW_LOCKED_BY_OTHER_PROCESS
};
typedef struct DtwLocker{
   char *separator;
   char *path;
   double reverifcation_delay;
   double min_interval_delay;
   double max_interval_delay;
   int process;
   int max_lock_time;
   DtwStringArray *locked_elements;

   int (*status)(struct DtwLocker *self, const  char *element);
   bool (*lock)(struct DtwLocker *self, const  char *element,double timeout);
   void (*unlock)(struct DtwLocker *self,const  char *element);
   void (*free)(struct DtwLocker *self);

}DtwLocker;


DtwLocker *newDtwLocker(char *path);

void private_DtwLocker_format_element(char *result,struct DtwLocker *self,const  char *element);

int DtwLocker_element_status(struct DtwLocker *self, const  char *element);


bool DtwLocker_lock(struct DtwLocker *self, const  char *element,double timeout);

void DtwLocker_unlock(struct DtwLocker *self,const  char *element);

void DtwLocker_free(struct DtwLocker *self);

