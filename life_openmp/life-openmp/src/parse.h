#ifndef PARSE_H
#define PARSE_H

int getpattern(char *fname); /* Load pattern as grid */

void writepattern(char *fname); /* Save grid as pattern */

/* maybe? ¯\_(ツ)_/¯ */
void renamepattern(char *fname, char *rname);
void deleTepattern(char *fname);

#endif
