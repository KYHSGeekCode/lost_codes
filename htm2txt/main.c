/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>




/* Remove all <....> from a file (argv[1]). Save in <file>-ascii */
/* Or read stdin and write on stdout */
/* Skip all leading spaces */
/* Replace each sequence if 5 spaces within line by 1 space */

#define BUFFER_SIZE 4096

static void error (const char *prog, const char *msg)
                  __attribute__((noreturn));
static void error (const char *prog, const char *msg) {
  fprintf (stderr, "ERROR: %s.\n", msg);
  fprintf (stderr, "Usage: %s [ <html_file> ]\n", prog);
  TCHAR errMes[1024];
	TCHAR str[1024];
	int err;
	err=GetLastError();
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,err,	0,errMes,1024,NULL);
	wsprintf(str,"에러코드=%d, 메시지=%s",err,errMes);
	MessageBox(0,str,"에러",MB_OK);
	GetLastError();
  exit(1);
}

const char sstart[] = "Vos Documents au format PDF:";
const char sstop[] = "&nbsp;";


int main (int argc, char *argv[]) {

   FILE *fin, *fout;
   char out_file_name[2048]={0,};
   char buffer[BUFFER_SIZE];
   int len;
   int i, j;
   int skip, sskip;
   int nb_space;
   int leading;
   int nb_empty;
	GetLastError();
    //if (argc > 2) {
	// error (argv[0], "invalid arguments"); 
   //}

   	puts("input file name:");
   	fgets(out_file_name,2048,stdin);
   	puts(out_file_name);
    fin = fopen(out_file_name,"rt");
    
	if (fin == (FILE*) NULL) {
		error (argv[0], "can't open input file");
     }
     //strcpy (out_file_name, argv[1]);
     strcat (out_file_name, "-ascii.txt");
     fout = fopen (out_file_name, "w");
     if (fout == (FILE*) NULL) {
       fclose (fin);
       error (argv[0], "can't create output file");
     }
  

  skip = 0;
  sskip = 0;
  nb_empty = 0;
  for (;;) {
    nb_space = 0;
    leading = 1;
    len = strlen(fgets (buffer, BUFFER_SIZE,fin));
    if (len == 0) {
      break;
    }
    j = 0;
    for (i = 0; i <= len; i++) {
      if (buffer[i] == '<') {
        skip = 1;
      } else if (buffer[i] == '>') {
        skip = 0;
      } else {

        if (!skip) {
          /* We're out of < .. > */
          /* Skip all leading spaces */
          if (buffer[i] == ' ') {
            if (! leading) {
              /* Within line, 5 spaces become 1 space */
              nb_space ++;
              if (nb_space == 5) {
                j -= 4;
                nb_space = 0;
              } 
            }
          } else {
            /* One significant character: within line, no more space */
            leading = 0;
            nb_space = 0;
          }
          if (!leading) {
            if (buffer[i] == (char)0xE9) {
              buffer[j] = 'e';
              j++;
            } else if (buffer[i] < '\0') {
              /* Skip */
              ;
            } else {
              buffer[j] = buffer[i];
              j++;
            }
          }
        }

      }
    }
    /* Now check super start and super stop */
    if ( (sskip == 0) && (strncmp(buffer, sstart, strlen(sstart)) == 0) ) {
      sskip = 1;
    }
    if ( (sskip == 1) && (strncmp(buffer, sstop, strlen(sstop)) == 0) ) {
      sskip = 2;
    }
    if (sskip == 1) {
      /* Only one empty line */
      if (strlen(buffer) == 0) {
        nb_empty ++;
      } else {
        nb_empty = 0;
      }
      if (nb_empty <= 1) {
        fprintf (fout, "%s\n", buffer);
      }
    }
  }

     
  if (argc != 1) {
   fclose (fin);
   fclose (fout);
  }
  exit(0);
}

