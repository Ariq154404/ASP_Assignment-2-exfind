
/* Sample Input in terminal mac OsX(unix like):
./extfind /Users/ariqrahman/Desktop/folder_tree .c .xyz .abc .rtf .rtf .c


Output:
/Users/ariqrahman/Desktop/folder_tree/test/referece1.rtf 
/Users/ariqrahman/Desktop/folder_tree/test/referece1.rtf 
/Users/ariqrahman/Desktop/folder_tree/test/exfind.c 
/Users/ariqrahman/Desktop/folder_tree/test/exfind.c 
/Users/ariqrahman/Desktop/folder_tree/referece1.rtf 
/Users/ariqrahman/Desktop/folder_tree/referece1.rtf 
/Users/ariqrahman/Desktop/folder_tree/exfind.c 
/Users/ariqrahman/Desktop/folder_tree/exfind.c 
Filextension  .xyz  not found 
Filextension  .abc  not found 


*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
 #include <ftw.h>
char **strarray = NULL;
int cnt=0;
//Flag set with maximum 10 to which extension are refered but not present
int fl[ ]={0,0,0,0,0,0,0,0,0,0};
int func(const char *cr, const struct stat *ptr, int flag, struct FTW *ftw){
        int i=1;
		// printf("Hello");
		for (i=1;i<cnt;i++){
		   int ln=strlen(strarray[i]);
		   int tl=strlen(cr);
		   int j;
		   int fls=1;
		   if (tl>=ln){
		   int x=0;
		   // last n the charecters from file name is checked to see extension present or not
		   for (j=tl-ln;j<tl;j++){
                 if (cr[j]!=strarray[i][x])
				 { fls=0;
				 break;}
				 x+=1;
                 			}

		   
		   }
		   else{
			 fls=0;
		   }
           if (fls==1){
			    fl[i-1]=1;
			    // Condition 1) of assignment to print found extensions
                printf("%s \n",cr);
		

		   } 
		   


		}
		if(cnt<=1){
     //Condition 2) of assignment     // if the extention is not there this condition prints the name of each object
           printf("%s \n",cr);

		}
		return 0;
}
int main(int argc, char *argv[])
{   struct stat sb;
	// Checks for validity of directory
	if (stat(argv[1], &sb) != 0 || S_ISDIR(sb.st_mode)==0)
                        {
                          printf("Not a valid directory\n");
						  return 0;
                         }

	
	for (int y=1;y<argc;y++){
		strarray = (char **)realloc(strarray, (cnt + 1) * sizeof(char *));
		strarray[cnt++] = argv[y];
		
	}
	//Condition 3) of assignment to limit number of extension to 10
	if (cnt>10)
	   {cnt=10;}
   

    int val= nftw(strarray[0],func,10,FTW_DEPTH);
    for(int z=1;z<cnt;z+=1){
	   // ith flag corresponds to directory that is mentioned but not there
       if (fl[z-1]==0){
	   printf("Filextension  %s  not found \n",strarray[z]);}

	}
	return 0;
}
