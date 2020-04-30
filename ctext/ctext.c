#include "ctext.h"

#include <stdlib.h>

int ctext_length(const char *ctext) {
	int n = 0;
	for (n; ctext[n] != '\0';++n) {}
	return n;
}

void ctext_assign(char **ctext, const char *source) {
	int length = ctext_length(source);
	*ctext = (char *)malloc(sizeof(char)*(length + 1));
	for (int i = 0; i < length; ++i) {
		(*ctext)[i] = source[i];
	}
	(*ctext)[length] = '\0';
}

int ctext_compare(const char *left, const char *right);

void ctext_concat(char **result, const char *left, const char *right) {
	int llen = ctext_length(left);
	int rlen = ctext_length(right);
	int len = llen + rlen;
	if (*result) {
		free(*result);
	}
	*result = (char *)malloc(sizeof(char)*(len + 1));
	for (int i = 0; i < len;++i) {
		if (i < llen) {
			(*result)[i] = left[i];
		}
		else {
			(*result)[i] = right[i - llen];
		}
	}
	(*result)[len] = '\0';
}

void ctext_intercept(char **result, const char *source, int start, int length) {
	if (*result) {
		free(*result);
	}
	*result = (char *)malloc(sizeof(char)*(length + 1));
	for (int i = 0; i < length; ++i) {
		(*result)[i] = source[i + start];
	}
	(*result)[length] = '\0';
}

int ctext_match_bruteforce(const char *source, const char *pattern,int start) {
	int slen = ctext_length(source);
	int plen = ctext_length(pattern);
	int i = start, j = 0;
	while (i < slen&&j<plen) {
		if (source[i]==pattern[j]) {
			++i; ++j;
		}
		else {
			i = i - j + 1; j = 0;
		}
	}
	if (j == plen)
		return i - plen;
	else
		return -1;
}

void ctext_replace(char **result, const char *source, const char *pattern, const char *replace) {
	if (*result) {
		free(*result);
	}
	int slen = ctext_length(source);
	int plen = ctext_length(pattern);
	int rlen = ctext_length(replace);
	int len = slen + rlen - plen;
	*result = (char *)malloc(sizeof(char)*(len + 1));
	int position = ctext_match_bruteforce(source, pattern, 0);
	for (int i = 0; i < len;++i) {
		if (i < position) {
			(*result)[i] = source[i];
		}
		else if (i >= position && i < position + rlen) {
			(*result)[i] = replace[i - position];
		}
		else {
			(*result)[i] = source[i - plen + 1];
		}
	}
	(*result)[len] = '\0';
}

void ctext_insert(char **result, const char *source, const char *insert, int position, int length) {
	if (*result) {
		free(*result);
	}
	int slen = ctext_length(source);
	int rlen = slen + length;
	*result = (char *)malloc(sizeof(char)*(rlen + 1));
	for (int i = 0; i < rlen; ++i) {
		if (i < position) {
			(*result)[i] = source[i];
		}
		else if (i >= position && i < position + length) {
			(*result)[i] = insert[i - position];
		}
		else {
			(*result)[i] = source[i - length];
		}
	}
	(*result)[rlen] = '\0';
}

void ctext_remove(char **result, const char *source, int position, int length) {
	if (*result) {
		free(*result);
	}
	int slen = ctext_length(source);
	int rlen = slen - length;
	*result = (char *)malloc(sizeof(char)*(rlen + 1));
	for (int i = 0; i < rlen;++i) {
		if (i < position) {
			(*result)[i] = source[i];
		}
		else if (i >= position && i < position + length) {
			(*result)[i] = source[i + length];
		}
		else {		}
	}
	(*result)[rlen] = '\0';
}

void ctext_reverse(char **result, const char *source) {
	ctext_assign(result, source);
	int len = ctext_length(source);
	char temp;
	int i = 0, j = len - 1;
	for (i,j; i < j;++i,--j) {
		temp = (*result)[i];
		(*result)[i] = (*result)[j];
		(*result)[j] = temp;
	}
}

void ctext_shift(char **result, const char *source, int direction, int step) {
	ctext_assign(result, source);
	int len = ctext_length(source);
	char temp;
	for (int i = 0; i < step; ++i) {
		if (direction > 0) {
			temp = (*result)[len - 1];
			for (int j = len - 1; j > 0;j--) {
				(*result)[j] = (*result)[j - 1];
			}
			(*result)[0] = temp;
		}
		else {
			temp = (*result)[0];
			for (int j = 0; j < len - 1;++j) {
				(*result)[j] = (*result)[j + 1];
			}
			(*result)[len - 1] = temp;
		}
	}
	(*result)[len] = '\0';
}
