import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
 
/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		Scanner sc=new Scanner(System.in);
		int n,i,c1,c2,j,t= sc.nextInt();
		long l;
		String s1="12",s2="8";
		BigInteger f,sum,max,prod,diff,mul;
		long sub[]=new long[500001];
		while((--t)>=0)
		{
		    s2="0";
		    c1=0;
		    c2=0;
		    sum=new BigInteger(s2);
		    diff=sum;
		    n=sc.nextInt();
		    for(i=0;i<n;i++)
		    {
		      l= sc.nextLong(); 
		      if(l>=0)
		      {
		        s1=Long.toString(l); 
		       f=new BigInteger(s1);
		       sum=sum.add(f) ;
		       c1++;
		      }
		      else
		      {
		          sub[c2]=-1*l;
		          s2=Long.toString(sub[c2]);
		          prod=new BigInteger(s2);
		          diff=diff.add(prod);
		          c2++;
		      }
		      
		    }
		    Arrays.sort(sub,0,c2);
		   
		    s2=Integer.toString(c1);
		    prod=new BigInteger(s2);
		    max=sum.multiply(prod);
		    max=max.subtract(diff);
		    for(i=0;i<c2;i++)
		    {
		      s2=Long.toString(sub[i]);
		       prod=new BigInteger(s2);
		       sum=sum.subtract(prod);
		       diff=diff.subtract(prod);
		       c1++;
		       s2=Integer.toString(c1);
		       prod=new BigInteger(s2);
		       mul=sum.multiply(prod);
		       mul=mul.subtract(diff);
		       if(mul.compareTo(max)>0)
		       max=mul;
		       else
		       break;
		       
		       
		      
		    }
    		   
    		System.out.println(max);
		}
	}
} 