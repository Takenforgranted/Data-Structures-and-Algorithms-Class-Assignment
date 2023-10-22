#ifndef SEQUENLIST_H
#define SEQUENLIST_H

#define maxsize 100

typedef float datatype;
typedef struct
{
    datatype data[maxsize];
    int last;
} sequenlist;

#endif /* SEQUENLIST_H */