

DtwLocker *newDtwLocker(){

    DtwLocker *locker = (DtwLocker*)malloc(sizeof(DtwLocker));

#ifdef windows
    locker->locker = newDtwMultiFileLocker();
#endif
    return locker;
}

int DtwLocker_lock(DtwLocker *self, const  char *element){

#ifdef windows
    return DtwMultiFIleLocker_lock(self->locker,element);
#endif
}

void DtwLocker_unlock(DtwLocker *self, const  char *element){
    #ifdef windows
         DtwMultifileLocker_unlock(self->locker,element);
    #endif
}

void DtwLocker_represemt(DtwLocker *self){
#ifdef windows
     DtwMultiFileLocker_represemt(self->locker);
#endif
}

void DtwLocker_free(DtwLocker *self){
#ifdef windows
     DtwMultiFileLocker_free(self->locker);
#endif
    free(self);
}
