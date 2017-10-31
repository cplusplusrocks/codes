/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String s1="",s2="",s3,s4="",s5="";
		s3=br.readLine();
		int l1,l2,l3;
		l3=s3.length();
		int i;
		for( i=0;i<l3;i++)
		{
			char ch=s3.charAt(i);
			if(ch==' ')
			break;
			else
			s1=s1+ch;
		}
		s2=s3.substring(++i);
	    int t=Integer.parseInt(br.readLine());
	    	System.out.println(s1+" "+s2);
	    while(t!=0)
	    {
	        t--;
	        s3=br.readLine();
	       l2=s3.length();
		
		for( i=0;i<l2;i++)
		{
			char ch=s3.charAt(i);
			if(ch==' ')
			break;
			else
			s4=s4+ch;
		}
		s5=s3.substring(++i); 
		if(s1.equals(s4))
		{
		    s1=s5;
		    
		}
		else
		{
		    s2=s5;
		}
		System.out.println(s1+" "+s2);
	    }
	}
}