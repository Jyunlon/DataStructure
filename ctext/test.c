#include "ctext.h"

#include <stdio.h>

void ctext_length_test(){
  printf("%d\n",ctext_length("Hello,Wolrd!"));
  printf("%d\n",ctext_length("ABC"));
}
void ctext_assign_test(){
  char *ctext;
  ctext_assign(&ctext,"Hello,Wolrd!");
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_concat_test(){
  char *ctext;
  ctext_concat(&ctext,"Hello,","Wolrd!");
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_intercept_test(){
  char *ctext;
  ctext_intercept(&ctext,"Hello,Wolrd!",2,5);
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_match_bruteforce_test(){
  printf("%d\n",ctext_macth_bruteforce("Hello,World!","llo",0));
  printf("%d\n",ctext_macth_bruteforce("Hello,Wolrd!","olr",0));
  printf("%d\n",ctext_match_bruteforce("Hello,Wolrd!","abc",0));
}
void ctext_replace_test(){
  char *ctext;
  ctext_replace(&ctext,"Hello,World!","o,W","#####");
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_insert_test(){
  char *ctext;
  ctext_insert(&ctext,"Hello,World!","#####",2,3);
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_remove_test(){
  char *ctext;
  ctext_remove(&ctext,"Hello,World!",2,5);
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_reverse_test(){
  char *ctext;
  ctext_reverse(&ctext,"Hello,Wolrd!");
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
void ctext_shift_test(){
  char *ctext;
  ctext_shift(&ctext,"Hello,Wolrd!",1,3);
  printf("%s\n",ctext);
  ctext_clear(&ctext);
}
