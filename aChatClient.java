import java.io.*;
import java.net.*;

public class ChatClient
{
	
	public static void main(String[] args)throws Exception
	{
		
	Socket sock=new Socket("192.168.136.135", 3000);
	System.out.println("Start the chitchat");
	BufferedReader keyRead=new BufferedReader(new 
InputStreamReader(System.in));

	OutputStream ostream=sock.getOutputStream();
	PrintWriter pwrite= new PrintWriter(ostream, true);

	InputStream istream=sock.getInputStream();
	BufferedReader receiveRead= new BufferedReader(new 
InputStreamReader(istream));

	

	String receiveMessage, sendMessage;

	while(true)
	{
		sendMessage=keyRead.readLine();
		pwrite.println(sendMessage);
		pwrite.flush();

		if((receiveMessage=receiveRead.readLine())!=null)
		{
			System.out.println(receiveMessage);
		}
		
		
	}
}
}
# Syuhadahishere
