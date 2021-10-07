#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
int myStrStr(char * str, char * sub);


int main()
{
  char str[100]={0};
  char strTocheck[10]={0};
  int i;
  int len = 0;
  
  printf("Enter the first string:\n");
  scanf("%[^\n]s",str);
  len = strlen(str);
  getchar(); 
  for (i=0; i<len; i++){
    if(str[i] >= 48 && str[i] <= 57)
    {
        printf("Invalid character entered\n");
        exit(EXIT_SUCCESS);
    }

  else{

    printf("Enter the second string:\n");
    scanf("%[^\n]s",strTocheck);
    len = strlen(strTocheck);
    for(i=0; i<len; i++)
    {
    if(strTocheck[i] >= 48 && strTocheck[i] <= 57)
    {
        printf("Invalid character entered\n");
        exit(EXIT_SUCCESS);
    }
  }
}
}

    if(myStrStr(str,strTocheck))
    printf("the string \'%s\' is contained in the string \'%s\'\n",strTocheck,str);
  else
    printf("the string \'%s\' is not contained in the string \'%s\'\n",strTocheck,str);
  end:
  return 0;

}

//function definition
int myStrStr(char * str, char * sub)
{
  int flag = 0;
  
  int i=0,len1=0,len2=0;
  
  len1 = strlen(str);
  len2 = strlen(sub);
  
  while(str[i] != '\0')
  {
      if(str[i] == sub[0])
      {
          if((i+len2)>len1)
            break;
            
          if(strncmp(str+i,sub,len2)==0)
          {
            flag = 1;
            break;
          }
      }
      i++;
  }
  
  return flag;
}
