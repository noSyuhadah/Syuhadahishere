import java.util.Scanner;
import java.net.*;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.io.*;

public class Cute{

	public static void main(String [] args) throws 
UnknownHostException, IOException
	{
		String chara, temp;
		Scanner sc= new Scanner(System.in);
		Socket s= new Socket("192.168.136.135",36796);
		Scanner s1= new Scanner(s.getInputStream());
		System.out.println("Enter Hostname");
		chara=sc.next();
		PrintStream p = new PrintStream(s.getOutputStream());
		p.println(chara);
		temp=s1.nextLine();
		System.out.println(temp);
	
		try{
			InetAddress 
host=InetAddress.getByName("192.168.136.135");
			System.out.println(host.getHostName());
		}
		catch(UnknownHostException ex)
		{
			ex.printStackTrace();
		}
	}
}
