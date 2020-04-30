#pragma once

int ctext_length(const char *ctext);
void ctext_assign(char **ctext, const char *source);
void ctext_malloc(char **ctext,int capcity);
void ctext_free(char **ctext);
int ctext_compare(const char *left,const char *right);
void ctext_concat(char **result,const char *left,const char *right);
void ctext_intercept(char **result,const char *source,int start,int length);
int ctext_match_bruteforce(const char *source,const char *pattern,int start);
void ctext_replace(char **result,const char *source,const char *pattern,const char *replace);
void ctext_insert(char **result,const char *source,const char *insert,int position,int length);
void ctext_remove(char **result,const char *source,int position,int length);
void ctext_reverse(char **result,const char *source);
void ctext_shift(char **result,const char *source,int direction,int step);
