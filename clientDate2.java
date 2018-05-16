import java.io.*;
import java.net.*;


class clientDate
{
	public static void main(String args[]) throws Exception
	{
		
		Socket soc=new Socket("192.168.136.139", 7777);
		BufferedReader in= new BufferedReader( new 
InputStreamReader( soc.getInputStream()));

		System.out.println(in.readLine());
	}
}

