//
// Created by jurandi on 06-07-2023.
//

long DtwObject_get_long(struct DtwObject *self, const char *name,DtwObjectProps *props){
    DtwObjectProps formated_props = DtwObjectProps_create_props(props);
    char *result = self->get_string(self,name,&dtw_no_store);

    if(result){
        long result_converted;
        int test = sscanf(result,"%li",&result_converted);
        free(result);
        if(test == 0){
            self->error = DTW_WRONG_TYPE;
            return 0;
        }
        return result_converted;
    }

    return 0;
}

void DtwObject_set_long(struct DtwObject *self,const char *name, long value,DtwObjectProps *props){
    char result[20] = {0};
    sprintf(result,"%li",value);
    self->set_string(self,name,result,NULL);
}