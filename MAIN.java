import java.math.BigInteger;
public class Main {
	public static void main(String[] args) throws java.lang.Exception {
		java.io.BufferedReader r = new java.io.BufferedReader(new java.io.InputStreamReader (System.in));
		int T = Integer.parseInt(r.readLine());
		BigInteger l = new BigInteger("50");
		BigInteger check = new BigInteger("0");
		BigInteger one = new BigInteger("1");
		int c = 10;
		BigInteger N,result;
		while(T-->0)
		{
			N = new BigInteger(r.readLine());
			if(N.compareTo(l) == 1)
				check = N.subtract(l);
			BigInteger i = N;
			while(i.compareTo(check) == 1)
			{

				if(i.isProbablePrime(c))
				{
					System.out.println(i.toString());
					break;
				}
				result = i.subtract(one);
				i = result;

			}

		}
	}
}
