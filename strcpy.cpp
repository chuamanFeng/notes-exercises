char * strcpy(char * strDest,const char * strSrc)
 {
       if (strDest==NULL||strSrc==NULL)
           return NULL;
           char * strDestCopy=strDest;
          if(strDest<strSrc)
           {
        	   while ((*strDest++=*strSrc++)!='\0')
        	        //cout<<*strDest<<' '<<*strSrc<<endl;
        	   *strDest = '\0';
           }
         else
           {
        	   int len=0;
        	   const char* temp=strSrc;
        	   while(*temp!='\0')
        	   {
        		   temp++;len++;
        		   //cout<<*strDest<<' '<<*strSrc<<endl;
        	   }
                strDest=strDest+len;
                *(strDest--)='\0';

                strSrc=strSrc+len-1;
        	   while (len--)
        	   {*strDest--=*strSrc--;
        	     }
           }
           return strDestCopy;
 }
