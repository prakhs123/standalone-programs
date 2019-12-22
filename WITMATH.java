import java.math.BigInteger;
public class Main {
public static void main(String[] args) throws java.lang.Exception {

int certainty = 10;
BigInteger limit=new BigInteger("230");
java.io.BufferedReader r = new java.io.BufferedReader(new java.io.InputStreamReader (System.in));
int T=Integer.parseInt(r.readLine());
BigInteger check=new BigInteger("0");
BigInteger one=new BigInteger("1");

BigInteger N,result;
while(T-->0)
{

N = new BigInteger(r.readLine());

if(N.compareTo(limit)==1)
check=N.subtract(limit);
BigInteger i=N;
while(i.compareTo(check)==1)
{

if(i.isProbablePrime(certainty))
{
System.out.println(i.toString());
break;
}
result=i.subtract(one);
i=result;

}

}
}
}
