import java.net.ServerSocket;
import java.io.IOException;
import java.util.Scanner;
import java.io.PrintStream;
import java.net.Socket;
import java.net.InetAddress;


public class Servers{

	public static void main(String[] args) throws IOException
	{
		
		String chara, temp;
		String lai = "Hostname";
		ServerSocket s1 = new ServerSocket(36796);
		Socket ss =s1.accept();
		Scanner sc = new Scanner(ss.getInputStream());
		chara = sc.next();

		InetAddress addr= InetAddress.getLocalHost();
		System.out.println("Local HostAddress: 
"+addr.getHostAddress());
		String hostname=addr.getHostName();
		System.out.println("Local host name: "+hostname);

		
		if(chara.equalsIgnoreCase(lai))
		{
			temp="Success";
		}
		else
		temp ="Deny";
		
		PrintStream p = new PrintStream(ss.getOutputStream());
		p.println(temp);
	}
}
