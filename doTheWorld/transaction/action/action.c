

DtwTransactionAction * newDtwTransactionAction(
        int action,
        const char *source1,
        const char *source2,
        const char *sha256,
        bool is_binary,
        unsigned char *element,
        long size
){

    DtwTransactionAction *self = (DtwTransactionAction*) malloc(sizeof(DtwTransactionAction));
    *self = (DtwTransactionAction){.action = action,.is_binary = is_binary,.size = size};

    if(source1){
        self->source1 = strdup(source1);
    }

    if(source2){
        self->source2 = strdup(source2);
    }

    if(sha256){
        self->sha256 = strdup(sha256);
    }

    if(element){
        self->element = (unsigned  char *) malloc(size + 1);
        memccpy(self->element,element,0,size);
    }
    return self;
}

int DtwTransactionAction_get_transaction_error_code(DtwTransactionAction * self,const char *previews_path){

    char formated_source1[500] = {0};

    if(previews_path){
       sprintf(formated_source1,"%s/%s",self->source1,previews_path);
    }else{
       strcpy(formated_source1,self->source1);
    }
    int entity_type = dtw_entity_type(formated_source1);

    if(self->action ==DTW_CREATE_FILE && entity_type != DTW_NOT_FOUND){
        return DTW_FILE_ALREADY_EXIST_ERROR;
    }


}



void DtwTransactionAction_represent(DtwTransactionAction * self){
    printf("action:%s\n",DtwTransactionAction_convert_action(self));
    printf("source1:%s\n", self->source1 ? self->source1 :"null");
    printf("source2:%s\n", self->source2 ? self->source2: "null");

    if(self->element){
        printf("is binary:%s\n",self->is_binary  ? "true" :"false");
        printf("sha256:%s\n",self->sha256 ? self->sha256 : "null");
        printf("element:%s\n",(char*)self->element);
    }


}


void DtwTransactionAction_free(DtwTransactionAction * self){
    if(self->source1){
        free(self->source1);
    }
    if(self->source2){
        free(self->source2);
    }
    if(self->element){
        free(self->element);
    }
    free(self);
}
