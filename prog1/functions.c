#include<stdio.h>
#include<stdlib.h>
#include"P1Headers.h"

/* finding the height of the tree recursively */
unsigned int heightT(nodeptr node)//finding the height of tree recursively
{
  if(node == NULL)//base case
    {
    return (0);
    }
  else
    {
      unsigned  int rHeight = heightT(node->rightChild);
      unsigned  int lHeight = heightT(node->leftChild);

      if(rHeight > lHeight) 
	return(1+rHeight);
      else 
	return(1+lHeight);
    }
}
/* finding the number of leaves recursively using right and left child of each node*/
unsigned int countLeaf(nodeptr node)
{
  if(node == NULL)//base case
    {
    return (0);
    }
  else 
    {
      if(node->leftChild  == NULL && node->rightChild == NULL)
	return 1; //if it has no children 
      else
	return(countLeaf(node->leftChild) + countLeaf(node->rightChild));
    }
}
/* finding the total number of strings recursively*/ 
  unsigned int strNum(nodeptr node)
    {
      if(node == NULL)//base case 
	{
	  return (0);
	}
      else 
	{
	  /* if(node->leftChild  == NULL && node->rightChild == NULL)
	     return (1);//if it has no children  */
	  // else
	  return (1+ strNum(node->leftChild) + strNum(node->rightChild));
	}
    }
