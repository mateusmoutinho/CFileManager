




void DtwResource_rename(DtwResource *self, char *new_name){

    char *old_path = private_DtwResource_get_path(self);
    free(self->name);
    self->name = strdup(new_name);
    char *new_path = private_DtwResource_get_path(self);

    if(self->allow_transaction){
        self->transaction->move_any(self->transaction,old_path,new_path);
    }
    else{
        dtw_move_any(old_path,new_path,DTW_NOT_CONCAT_PATH);
    }
    free(old_path);
    free(new_path);

}


void DtwResource_lock(DtwResource *self){
    if(self->locked){
        return;
    }
    #ifdef __linux__
        self->locker->lock(self->locker,self->path);
    #endif
}
void private_DtwResource_lock_if_auto_lock(DtwResource *self){
    if(self->auto_lock){
        self->lock(self);
    }
}


void DtwResource_destroy(DtwResource *self){

    if(self->allow_transaction){
        self->transaction->delete_any(self->transaction,self->path);
    }
    else{
        dtw_remove_any(self->path);
    }

}






void DtwResource_commit(DtwResource *self){
    self->transaction->commit(self->transaction,NULL);
}


int DtwResource_type(DtwResource *self){
    int type_element =  dtw_complex_entity_type(self->path);
    return type_element;
}

DtwStringArray *DtwResource_list(DtwResource *self){
    return dtw_list_all(self->path,DTW_NOT_CONCAT_PATH);
}

const char * DtwResource_type_in_str(DtwResource *self){
     return dtw_convert_entity(self->type(self));
}

void DtwResource_represent(DtwResource *self){
    printf("path: %s\n", self->path);
    printf("name: %s\n",self->name);
    printf("type: %s\n",self->type_in_str(self));

}

