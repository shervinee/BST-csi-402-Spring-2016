#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "P1Headers.h"


//shervin shahidizandi program 1 
int main(int argc, char* argv[])
{
  FILE *inpf; //the input file 
  FILE *outpf;//the output file
  unsigned int height,leafCount=0,leftHeight, rightHeight, strCount=0, leftStr=0,rightStr=0;//the variables to hold the printed data into outputfile 
  char *strInp;//the input string 
  nodeptr root; //the root of the tree 
  
  if(argc != 3){ //checks the number of command lind arguments
    fprintf(stderr,"Usage ftest file\n");
      exit(1);
  }

  if((inpf = fopen(argv[1], "r+")) == NULL)
    {
      fprintf(stderr,"the input file %s could not be openned\n",argv[1]);
       exit(1);
    }    
	      
      if((outpf =fopen(argv[2], "w")) == NULL)
	{
	  fprintf(stderr,"the output  file %s could not be oppened\n",argv[2]);
	   exit(1);
	}


      strInp = (char*) malloc((MAX_LEN+1)*sizeof(char)); //mallocs the memory for the input string 

      if(strInp == NULL)
    {
      fprintf(stderr,"malloc error");
      exit(1);
    }

      while(fscanf(inpf, "%s" ,strInp) != EOF )
	{
	  if(strlen(strInp) > (MAX_LEN ))//checks if the input is within 15 characters
	      {
		puts("input string is larger than 15 character size limit");
	     exit(1);
               }
	  insert(root,strInp); //builds the tree
	}

      height = heightT(root); 
      leftHeight = heightT(root->leftChild);
      rightHeight = heightT(root->rightChild);
      strCount= strNum(root);
      leftStr = strNum(root->leftChild);
      rightStr = strNum(root->rightChild);

      fprintf(outpf,"The total number of strings in the input file \t = &u \n",strCount);
      fprintf(outpf,"Height of the binary tree \t\t      = &u \n",height);
      fprintf(outpf,"No. of leaves in the binary tree \t\t  = &u \n",countLeaf(root));
      fprintf(outpf,"Height of the left subtree of the root \t   = &u \n",leftHeight);
      fprintf(outpf,"No. of strings in the left subtree of the root \t = &u  \n",leftStr);
      fprintf(outpf,"Height of the right subtree of the root \t   = &u \n",rightHeight);
      fprintf(outpf,"No. of strings in the left subtree of the root \t = &u  \n",rightStr);
      
      /* closing the files */
      if(fclose(inpf) == EOF)
	{
	  fprintf(stderr, "Colud not close the %s file\n", argv[1]);
	}
 if(fclose(outpf) == EOF)
	{
	  fprintf(stderr, "Colud not close the %s file\n", argv[2]);
	}
 free(strInp);//frees the allocated memeory 
 return 0;   
}
