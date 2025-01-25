int func(char* str){
    int sigen = 1;
    
    if(*str == '-'){
        sigen = -1;
        str++;
    }
    int res = *str;
    str++;

    while(*str){
        res*=10;
        res+= *str;
        str++;
    }

    return res*sigen;
}